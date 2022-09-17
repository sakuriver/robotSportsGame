

#define _CRT_SECURE_NO_WARNINGS
#include "InGameAnimationScene.h"
#include <stdio.h>

using namespace std;



/// <summary>
/// プロフィール情報
/// </summary>
void IngameAnimationScene::Draw()
{
	int drawBaseX = this->playerInformationDialog.baseX;
	int drawBaseY = this->playerInformationDialog.baseY + 30;

	// フォグを有効にする
	SetFogEnable(false);

	// フォグの色を水にする
	SetFogColor(0, 255, 180);

	// フォグの開始距離を０、終了距離を１５００にする
	SetFogStartEnd(-2000.0f, 3000.0f);

	SetFontSize(25);

	DrawFormatString(drawBaseX + 100, drawBaseY, GetColor(255, 255, 255), "どうぶつ転生試験中");

	// 画面に映る位置に３Ｄモデルを移動
	MV1SetRotationXYZ(InGamePlayerModelH, VGet(0.0f, 180.0f * DX_PI_F / 180.0f, 0.0f));
	MV1SetPosition(InGameBackModelH, VGet(620.0f, 500.0f, -600.0f));

	// 加速計算式 開始位置 + (ボタン進行カウント + (コンボ係数 * 2)) 
	MV1SetPosition(InGamePlayerModelH, VGet(620.0f, 500.0f, -600.0f + dushCount ));
	SetFontSize(45);


	// モデルの描画
	MV1DrawModel(InGameBackModelH);

	MV1DrawModel(InGamePlayerModelH);


	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	DrawFormatString(700, 30, GetColor(255, 255, 255), "TIME 200");

	// 連鎖をしたら、専用文字が出る
	if (comboCount > 3) {
		char paramCombo[50];
		SetFontSize(45 + comboCount);
		sprintf(paramCombo, "コンボ    %d", comboCount);

		DrawFormatString(700, 430, GetColor(255, 255, 0), paramCombo);

	}


}



/// <summary>
/// プレイヤー画面内での操作切り替え
/// </summary>
void IngameAnimationScene::Update()
{
	if (CheckHitKey(KEY_INPUT_K) != 0) {
			dushCount += 0.1f;
			if (beforeJButton && beforeCount <= 60) {
				comboCount++;
				beforeJButton = false;
				beforeKButton = true;
			}
	}


	if (CheckHitKey(KEY_INPUT_J) != 0) {
		dushCount += 0.1f;
		if (beforeKButton && beforeCount <= 60) {
			comboCount++;
			beforeJButton = true;
			beforeKButton = false;
		}
	}


	if (beforeCount > 60) {
		comboCount = 0;
		beforeCount = 0;
	}

	beforeCount++;

	dushCount += (comboCount * 2);
}