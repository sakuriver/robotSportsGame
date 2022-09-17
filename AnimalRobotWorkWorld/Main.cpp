
#include "DxLib.h"
#include "AnimalRobot.h"
#include "SceneManager.h"
#include "DebugScene.h"
#include "InGameAnimationScene.h"
#include "AnimalFieldScene.h"
#include "ConnectDataAnalizeScene.h"
#include <cereal/cereal.hpp>
#include <atlstr.h>
#include <wincrypt.h>
#include <cereal/archives/json.hpp>
#include <iostream>
#include <regex>
#pragma comment (lib, "Crypt32.lib")
#define ARRAY_SIZE(dArray) (sizeof(dArray)/sizeof(dArray[0]))

std::stringstream ss;
int TitleDraw(int titleGraphHandle, int debugGraphHandle, int gameMode, bool isDebugMode, DebugScene debugScene) {

    DrawGraph(0, 0, titleGraphHandle, true);
    DrawFormatString(30, 100, GetColor(255, 255, 255), "モード入力画面です");
    DrawFormatString(30, 120, GetColor(255, 255, 255), "1.メニューシーン移動");
    DrawFormatString(30, 180, GetColor(255, 255, 255), "Enterキーを押してね");

    if (CheckHitKey(KEY_INPUT_RETURN) != 0) {
        gameMode = 1;
        DrawFormatString(30, 100, GetColor(255, 255, 255), "チャレンジコーナーへ移動中です");
        Sleep(1500);
        DrawFormatString(30, 100, GetColor(255, 255, 255), "移動完了しました");
        Sleep(1000);
    }
    if (isDebugMode == true) {
        DrawGraph(0, 0, debugGraphHandle, TRUE);
        debugScene.DrawNowScene();
        debugScene.UpdateNowScene();
    }
    return gameMode;

}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

    BYTE * pszString = NULL;
    DWORD cchString = 0;

    DWORD dwDst = 0;
    BYTE* pbDist[3];
    
    // ウィンドウモードに設定
    ChangeWindowMode(TRUE);

    // 画面モードの変更
    SetGraphMode(1400, 1000, 32);
    SetWindowText("どうぶつローカル うんどうかい");

    // DXライブラリ初期化処理
    if (DxLib_Init() < 0) {
        //エラーなら終了する
        return -1;
    }

    //描画先を裏画面にする
    SetDrawScreen(DX_SCREEN_BACK);

    int gameMode = 0;

    int characterCount = 0;
    AnimalRobot pokemon;
    pokemon.setHp(1000);

    {
        cereal::JSONOutputArchive o_archive(ss);
        o_archive(pokemon);
    }
    std::string result = ss.str();
    pszString = (byte *)result.c_str();
    //pszString = (byte *)"crypt encode decode test";
    cchString = strlen((char *)pszString);
    std::stringstream sst;
    LPSTR encodeResult[3]{};
    DWORD *encodeResultIndex[3]{0, 0, 0};

    DWORD valueData = 0;

    DWORD dwStringLen = 0;
    DWORD maxNum = 100;
    DWORD setIndexNum = 0;
    // 一度にコンバートできる文字数に制限があるので区切ってデータを取得する
    int dataIndex = 0;

    // タイトル画像
    int titleGraphHandle;
    titleGraphHandle = LoadGraph("AniRobot_Title.png");


    while (true) {

        if (CryptBinaryToString(&pszString[0], cchString, CRYPT_STRING_ANY, NULL, &dwStringLen))
        {
            // エンコード処理
            if (maxNum < dwStringLen) {
               
                    // 指定した文字数以下の場合は、一括変換をする
                    BYTE setData[100+1];
                    int startValue = 0;
                    for (int j = dataIndex * maxNum; j < maxNum * (dataIndex + 1); j++) {
                        setData[startValue] = pszString[j];
                        startValue++;
                    }
                    if (CryptBinaryToString(&setData[0], sizeof(setData), CRYPT_STRING_ANY, NULL, &setIndexNum))
                    {
                        encodeResult[dataIndex] = new TCHAR[setIndexNum];
                        if (CryptBinaryToString(&setData[0], sizeof(setData), CRYPT_STRING_ANY, encodeResult[dataIndex], &setIndexNum))
                        {
                        }
                    }

            }
            else {

                // 指定した文字数以下の場合は、一括変換をする
                encodeResult[0] = new TCHAR[dwStringLen + 1];
                if (CryptBinaryToString(&pszString[0], cchString, CRYPT_STRING_ANY, encodeResult[0], &dwStringLen))
                {
                }
                dataIndex++;
                break;
            }

        }
        dataIndex++;

        if (dataIndex > 2) {
            break;
        }

    }
    BYTE* decodeResult = NULL;
    for (int i = 0; i < dataIndex; i++) {
        // デコード処理
        DWORD size = strlen(encodeResult[i]) + 1;
        CString stringData = CString(encodeResult[i]);
        if (CryptStringToBinary(stringData, size, CRYPT_STRING_ANY, NULL, &valueData, NULL, NULL)) {
            const int calcResult = valueData + 1;
            BYTE* decodeResult = new BYTE[calcResult]{};
            if (CryptStringToBinary(stringData, size, CRYPT_STRING_ANY, &decodeResult[0], &valueData, NULL, NULL)) {
                //pbDist:バイト列
                sst << decodeResult;
            }
        }
    }


    std::string binaryEncorder = sst.str();
    binaryEncorder = regex_replace(binaryEncorder, regex("ﾌ"), "");
    AnimalRobot pokemon_i;
    std::stringstream sstd;
    sstd << binaryEncorder.c_str();
    cereal::JSONInputArchive i_archive(sstd);

    i_archive(pokemon_i);
    char key[23] = "1101001101011000111";
    std::string convertResult = "";
    int j = 0;
    for (int i = 0; i < result.length(); i++) {
        if (j >= ARRAY_SIZE(key)) {
            j = 0;
        }
         convertResult += result[i]+key[j];
        
         j++;
    }

    ProfileScene profileScene = ProfileScene();
    profileScene.Initialize();

    AnimalFieldScene animalFieldScene = AnimalFieldScene();
    animalFieldScene.Initialize();

    IngameAnimationScene ingameAnimationScene = IngameAnimationScene();
    ingameAnimationScene.Initialize();

    int backGroundHandle = LoadGraph("AnimalBackGround.png");
    int saveManagerGroundHandle = LoadGraph("AnimalDataCheckBackGround.PNG.png");

    bool isDebugMode = false;
    ChangeFontType(DX_FONTTYPE_ANTIALIASING_8X8);
    int debugGraphHandle = LoadGraph("AnimalRobotDebugSceneBackGround.png");
    DebugScene debugScene = DebugScene();
    debugScene.Initialize();
    debugScene.SetPlayerInformation(profileScene.GetPlayerInformation());

    // セーブデータ解析シーン関連の用意
    ConnectDataAnalizeScene connectDataAnalizeScene = ConnectDataAnalizeScene();
    connectDataAnalizeScene.Initialize();
    connectDataAnalizeScene.SetPszString(pszString);
    connectDataAnalizeScene.SetEncodeResult(encodeResult, dataIndex);
    connectDataAnalizeScene.SetAnimalRobot(pokemon_i);

    int changeScene = 0;
    // while(裏画面を表画面に反映, メッセージ処理, 画面クリア)
    while (ProcessMessage() == 0) {

        switch (gameMode)
        {
        case 0:
            gameMode = TitleDraw(titleGraphHandle, debugGraphHandle, gameMode, isDebugMode, debugScene);
            break;
        case 1:
            DrawFormatString(30, 100, GetColor(255, 255, 255), "1.あそぶ");
            DrawFormatString(30, 150, GetColor(255, 255, 255), "2.セーブデータ解析画面");
            DrawFormatString(30, 200, GetColor(255, 255, 255), "3.プロフィール画面");
            DrawFormatString(30, 250, GetColor(255, 255, 255), "データ読み込み完了 100 byte です");
            if (CheckHitKey(KEY_INPUT_1) != 0) {
                gameMode = 2;
            }
            if (CheckHitKey(KEY_INPUT_2) != 0) {
                gameMode = 3;
            }
            if (isDebugMode == true) {
                DrawGraph(0, 0, debugGraphHandle, TRUE);
                debugScene.DrawNowScene();
                debugScene.UpdateNowScene();
            }
            if (CheckHitKey(KEY_INPUT_3) != 0) {
                gameMode = 5;
            }
            break;
        case 2:
            DrawGraph(0, 0, backGroundHandle, TRUE);

            animalFieldScene.Draw();
            animalFieldScene.Update();
            changeScene = profileScene.ChangeScene();
            if (changeScene != 0) {
                gameMode = changeScene;
            }
            if (isDebugMode == true) {
                DrawGraph(0, 0, debugGraphHandle, TRUE);
                debugScene.DrawNowScene();
                debugScene.UpdateNowScene();
            }
            break;

        case 3:
            DrawGraph(0, 0, saveManagerGroundHandle, TRUE);
            //
            SetFontSize(40);
            DrawFormatString(630, 50, GetColor(255, 255, 255), "ほぞんのしょ 解析くん");
            SetFontSize(35);
            DrawFormatString(30, 200, GetColor(255, 255, 255), "1.ほぞんのしょ 暗号化かいし");
            DrawFormatString(30, 250, GetColor(255, 255, 255), "2.ほぞんのしょ 解析かいし");
            DrawBox(500, 150, 1000, 800, GetColor(0, 0, 0), TRUE);
            SetFontSize(30);
            DrawFormatString(630, 200, GetColor(255, 255, 255), "");
            connectDataAnalizeScene.DrawNowScene();
            connectDataAnalizeScene.UpdateNowScene();
            break;
        case 4:
            ingameAnimationScene.Draw();
            ingameAnimationScene.Update();
            break;
        case 5:
            DrawGraph(0, 0, backGroundHandle, TRUE);

            profileScene.Draw();
            profileScene.Update();
            changeScene = profileScene.ChangeScene();
            if (changeScene != 0) {
                gameMode = changeScene;
            }
            if (isDebugMode == true) {
                DrawGraph(0, 0, debugGraphHandle, TRUE);
                debugScene.DrawNowScene();
                debugScene.UpdateNowScene();
            }
            break;
        default:
            break;
        }



        DrawFormatString(30, 950, GetColor(255, 255, 255), "ESCキーで終了します");


        // 各モード関係なしのデバッグ機構
        if ((CheckHitKey(KEY_INPUT_N) != 0)) {
            isDebugMode = !isDebugMode;
        }
        if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) {
            DrawFormatString(30, 350, GetColor(0, 255, 0), "またきてねー☆");
            Sleep(5000);
            break;
        }
        ScreenFlip();

        ClearDrawScreen();
        clsDx();

    
    }

    DxLib_End();    // DXライブラリ終了処理
    return 0;
}

