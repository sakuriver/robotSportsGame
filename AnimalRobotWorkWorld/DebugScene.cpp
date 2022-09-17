#define _CRT_SECURE_NO_WARNINGS
#include "DebugScene.h"

void DebugScene::Initialize() {
	leftMenuHandle = LoadGraph("DebugMenuLeftPanelBackGround.png");
	rightMenuHandle = LoadGraph("DebugMenuRightPanelBackGround.png");
	selectCategory = 0;
	playerInformationDialog =  PlayerInformationDialog();
	isDebugCommanded = false;
	playerInformationDialog.baseX = 400;
	playerInformationDialog.baseY = 400;
	playerInformationDialog.backDialogGraphH = LoadGraph("AnimalRobotDebugMessageBackGround.png");
	sprintf(debugResultMessage, (char*)"");

}


/// <summary>
/// 現在選択しているデバッグモードの状態が選択される
/// </summary>
void DebugScene::DrawNowScene() {

	SetFontSize(40);

	char DebugTitle[50];
	sprintf(DebugTitle, (char*)"どうぶつうんどう会 ずるっこめにゅー");
	DrawFormatString(200, 100, GetColor(255, 200, 200), DebugTitle, TRUE);

	// メニュー背景画像描画
	DrawGraph(100, 150, leftMenuHandle, TRUE);
	DrawGraph(700, 150, rightMenuHandle, TRUE);


	SetFontSize(30);

	DrawBox(105, 100+((selectCategory+1)*100), 350, 100 + ((selectCategory + 1) * 100)+50, GetColor(170, 0, 0), FALSE );

	// メニューの各項目表示
	sprintf(DebugTitle, (char*)"れべるを変えるよ");
	DrawFormatString(110, 200, GetColor(255, 255, 255), DebugTitle, TRUE);


	sprintf(DebugTitle, (char*)"どうぶつにれんらく");
	DrawFormatString(110, 300, GetColor(255, 255, 255), DebugTitle, TRUE);


	sprintf(DebugTitle, (char*)"ちけっとのてはい");
	DrawFormatString(110, 400, GetColor(255, 255, 255), DebugTitle, TRUE);

	// メニューの詳細情報を選択
	switch (selectCategory)
	{

	case 0:
		sprintf(DebugTitle, (char*)"れべるチート");
		DrawFormatString(710, 200, GetColor(255, 255, 255), DebugTitle, TRUE);

		sprintf(DebugTitle, (char*)"1.最大レベルにする");
		DrawFormatString(710, 240, GetColor(255, 255, 255), DebugTitle, TRUE);

		sprintf(DebugTitle, (char*)"2.最小レベルにする");
		DrawFormatString(710, 280, GetColor(255, 255, 255), DebugTitle, TRUE);


		break;

	case 1:
		sprintf(DebugTitle, (char*)"どうぶつチート");
		DrawFormatString(710, 200, GetColor(255, 255, 255), DebugTitle, TRUE);

		sprintf(DebugTitle, (char*)"1.すべての動物を仲間にする");
		DrawFormatString(710, 240, GetColor(255, 255, 255), DebugTitle, TRUE);

		sprintf(DebugTitle, (char*)"2.すべてのどうぶつをさいきょうにする");
		DrawFormatString(710, 280, GetColor(255, 255, 255), DebugTitle, TRUE);


		break;
	case 2:
		sprintf(DebugTitle, (char*)"チケットチート");
		DrawFormatString(710, 200, GetColor(255, 255, 255), DebugTitle, TRUE);

		sprintf(DebugTitle, (char*)"2.チケットを100枚もらう");
		DrawFormatString(710, 240, GetColor(255, 255, 255), DebugTitle, TRUE);

		break;

	default:
		break;
	}

	DrawDialog();

}

void DebugScene::DrawDialog() {
	/// <summary>
	/// デバッグコマンドが実行されていたら描画する
	/// </summary>
	if (isDebugCommanded == true) {
		DrawGraph(playerInformationDialog.baseX, playerInformationDialog.baseY, playerInformationDialog.backDialogGraphH, TRUE);
		DrawFormatString(playerInformationDialog.baseX + 75, playerInformationDialog.baseY + 80, GetColor(255, 255, 255), debugResultMessage);
		DrawBox(playerInformationDialog.baseX + 145, playerInformationDialog.baseY + 190, playerInformationDialog.baseX + 280, playerInformationDialog.baseX + 240, GetColor(125, 255, 255), TRUE);

		DrawFormatString(playerInformationDialog.baseX + 180, playerInformationDialog.baseY + 200, GetColor(255, 255, 255), "OK");

	}
}


/// <summary>
/// デバッグシーン内での操作
/// </summary>
void DebugScene::UpdateNowScene() {

	if (changeMenu <= 3) {
		changeMenu++;
	}

	/// <summary>
	/// カテゴリーごとのデバッグ機能発動
	/// </summary>
	switch (selectCategory) {
	case 0:
		if (CheckHitKey(KEY_INPUT_1)!= 0) {
			sprintf(debugResultMessage, (char*)"最大レベルにしたよ");
			playerInformation->expInfo.nowLevel = 100;
			playerInformation->expInfo.nowExp = 100;
			isDebugCommanded = true;
		}
		if (CheckHitKey(KEY_INPUT_2) != 0) {
			sprintf(debugResultMessage, (char*)"初期レベルにもどしたよ");
			playerInformation->expInfo.nowLevel = 1;
			playerInformation->expInfo.nowExp = 0;
			isDebugCommanded = true;
		}
		break;
	case 1:
		if (CheckHitKey(KEY_INPUT_1)!= 0) {
			isDebugCommanded = true;
		}
		break;
	case 2:
		if (CheckHitKey(KEY_INPUT_1) != 0) {
			isDebugCommanded = true;
		}
		break;
	}

	if (changeMenu >= 3 && selectCategory >= 1 && CheckHitKey(KEY_INPUT_UP)) {
		selectCategory--;
		changeMenu = 0;
	}

	if (changeMenu >= 3  && selectCategory < 2 && CheckHitKey(KEY_INPUT_DOWN)) {
		selectCategory++;
		changeMenu = 0;

	}

}