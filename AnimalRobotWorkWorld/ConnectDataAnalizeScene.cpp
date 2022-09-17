#define _CRT_SECURE_NO_WARNINGS
#include "ConnectDataAnalizeScene.h"

void ConnectDataAnalizeScene::Initialize() {
	playerInformationDialog = PlayerInformationDialog();
	playerInformationDialog.baseX = 400;
	playerInformationDialog.baseY = 400;
	playerInformationDialog.backDialogGraphH = LoadGraph("AnimalRobotDebugMessageBackGround.png");
	IsEncrypt = false;
	IsDecrypt = false;
	EncryptAnimCount = 0;
	DecryptAnimCount = 0;
}


/// <summary>
/// 現在の解析くん状況がわかる
/// </summary>
void ConnectDataAnalizeScene::DrawNowScene() {

	SetFontSize(24);

	char DebugTitle[50];
	sprintf(DebugTitle, (char*)"どうぶつ おてがみ かくにんセンター");
	DrawFormatString(400, 100, GetColor(255, 200, 200), DebugTitle, TRUE);

	if (IsEncrypt) {
		char CryptStartTitle[50];

		sprintf(CryptStartTitle, (char*)"秘密のおてがみにするよー");
		DrawFormatString(510, 185, GetColor(255, 200, 200), CryptStartTitle, TRUE);

		char TargetDescriptionMessage[100];

		if (EncryptAnimCount > 30) {

			sprintf(TargetDescriptionMessage, (char*)"このお手紙を秘密の文字にするよ");
			DrawFormatString(510, 230, GetColor(255, 200, 200), TargetDescriptionMessage, TRUE);
		}

		if (EncryptAnimCount > 60) {
			sprintf(TargetDescriptionMessage, (char*)"あかぐみはよめないようにするね");
			DrawFormatString(510, 280, GetColor(255, 200, 200), TargetDescriptionMessage, TRUE);
		}

		if (EncryptAnimCount > 90) {
			DrawFormatString(510, 320, GetColor(255, 200, 200), "どうぶつ連合にれんらくできるんだよ", TRUE);
		}
		SetFontSize(15);
		if (EncryptAnimCount > 120) {
			DrawFormatString(510, 345, GetColor(255, 200, 200), "このお手紙がれんらくする内容だよ", TRUE);
			DrawFormatString(510, 370, GetColor(255, 200, 200), (char*)pszBaseString, TRUE);

		}

		if (EncryptAnimCount > 150) {
			char convertMessage[100];
			sprintf(convertMessage, "ひみつのおてがみはお知らせにかぎりがあるよ。");
			DrawFormatString(500, 560, GetColor(255, 200, 200), convertMessage, TRUE);

			sprintf(convertMessage, "こんかいは%dかいに分けて、おくるね。", encodeResultNum);
			DrawFormatString(500, 580, GetColor(255, 200, 200), convertMessage, TRUE);
			for (int i = 0; i < encodeResultNum; i++) {
				DrawFormatString(500, 600+i*45, GetColor(255, 200, 200), (char*)encodeResult[i], TRUE);
			}

		}

	}

	if (IsDecrypt) {
		char CryptStartTitle[50];

		sprintf(CryptStartTitle, (char*)"かいせき開始するよー");
		DrawFormatString(500, 185, GetColor(255, 200, 200), CryptStartTitle, TRUE);
		SetFontSize(15);
		if (DecryptAnimCount > 30) {
			char TargetDescriptionMessage[100];

			sprintf(TargetDescriptionMessage, (char*)"このお手紙をよめるようにするねー");
			DrawFormatString(500, 210, GetColor(255, 200, 200), TargetDescriptionMessage, TRUE);
		}


		if (DecryptAnimCount > 30) {
			char convertMessage[100];
			sprintf(convertMessage, "ひみつのおてがみはお知らせにかぎりがあるよ。");
			DrawFormatString(500, 260, GetColor(255, 200, 200), convertMessage, TRUE);

			sprintf(convertMessage, "こんかいは%dかいでハトさんかられんらく来たよ", encodeResultNum);
			DrawFormatString(500, 280, GetColor(255, 200, 200), convertMessage, TRUE);
			for (int i = 0; i < encodeResultNum; i++) {
				DrawFormatString(500, 300 + i * 45, GetColor(255, 200, 200), (char*)encodeResult[i], TRUE);
			}

		}

		if (DecryptAnimCount > 90) {
			SetFontSize(23);
			DrawFormatString(510, 450, GetColor(255, 200, 200), "それじゃあ、このお手紙を解析するね", TRUE);
		}

		if (DecryptAnimCount > 90 && DecryptAnimCount < 180) {
			SetFontSize(20);
			DrawFormatString(510, 480, GetColor(255, 200, 200), "お手紙解析中だよ....", TRUE);
		}

		if ( DecryptAnimCount > 190) {
			DrawFormatString(510, 480, GetColor(255, 200, 200), "おてがみは僕が解放していい能力だったよ", TRUE);
		}

		if (DecryptAnimCount > 230) {
			char convertResultMessage[100];

			sprintf(convertResultMessage, "あしのはやさ %d までいいよ", animalRobot.getSpeed());
			DrawFormatString(510, 520, GetColor(255, 200, 200), convertResultMessage, TRUE);
			sprintf(convertResultMessage, "たたかう競技でのたいりょく %d までいいよ", animalRobot.getHp());
			DrawFormatString(510, 550, GetColor(255, 200, 200), convertResultMessage, TRUE);
			sprintf(convertResultMessage, "すたみな %d までいいよ", animalRobot.getSpeed());
			DrawFormatString(510, 580, GetColor(255, 200, 200), convertResultMessage, TRUE);

		}

	}

}

void ConnectDataAnalizeScene::DrawDialog() {


}


/// <summary>
/// セーブデータ解析室の操作作業
/// </summary>
void ConnectDataAnalizeScene::UpdateNowScene() {

	// 暗号化した結果の描画開始
	if (CheckHitKey(KEY_INPUT_1) != false) {
		IsEncrypt = true;
		IsDecrypt = false;
		EncryptAnimCount = 0;
	}

	// 複合化した結果の描画開始
	if (CheckHitKey(KEY_INPUT_2) != false) {
		IsEncrypt = false;
		IsDecrypt = true;
		DecryptAnimCount = 0;
	}

	if (IsEncrypt) {
		EncryptAnimCount++;
	}


	if (IsDecrypt) {
		DecryptAnimCount++;
	}

}