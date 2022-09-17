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
/// ���ݑI�����Ă���f�o�b�O���[�h�̏�Ԃ��I�������
/// </summary>
void DebugScene::DrawNowScene() {

	SetFontSize(40);

	char DebugTitle[50];
	sprintf(DebugTitle, (char*)"�ǂ��Ԃ���ǂ��� ��������߂ɂ�[");
	DrawFormatString(200, 100, GetColor(255, 200, 200), DebugTitle, TRUE);

	// ���j���[�w�i�摜�`��
	DrawGraph(100, 150, leftMenuHandle, TRUE);
	DrawGraph(700, 150, rightMenuHandle, TRUE);


	SetFontSize(30);

	DrawBox(105, 100+((selectCategory+1)*100), 350, 100 + ((selectCategory + 1) * 100)+50, GetColor(170, 0, 0), FALSE );

	// ���j���[�̊e���ڕ\��
	sprintf(DebugTitle, (char*)"��ׂ��ς����");
	DrawFormatString(110, 200, GetColor(255, 255, 255), DebugTitle, TRUE);


	sprintf(DebugTitle, (char*)"�ǂ��Ԃɂ��炭");
	DrawFormatString(110, 300, GetColor(255, 255, 255), DebugTitle, TRUE);


	sprintf(DebugTitle, (char*)"�������Ƃ̂Ă͂�");
	DrawFormatString(110, 400, GetColor(255, 255, 255), DebugTitle, TRUE);

	// ���j���[�̏ڍ׏���I��
	switch (selectCategory)
	{

	case 0:
		sprintf(DebugTitle, (char*)"��ׂ�`�[�g");
		DrawFormatString(710, 200, GetColor(255, 255, 255), DebugTitle, TRUE);

		sprintf(DebugTitle, (char*)"1.�ő僌�x���ɂ���");
		DrawFormatString(710, 240, GetColor(255, 255, 255), DebugTitle, TRUE);

		sprintf(DebugTitle, (char*)"2.�ŏ����x���ɂ���");
		DrawFormatString(710, 280, GetColor(255, 255, 255), DebugTitle, TRUE);


		break;

	case 1:
		sprintf(DebugTitle, (char*)"�ǂ��Ԃ`�[�g");
		DrawFormatString(710, 200, GetColor(255, 255, 255), DebugTitle, TRUE);

		sprintf(DebugTitle, (char*)"1.���ׂĂ̓����𒇊Ԃɂ���");
		DrawFormatString(710, 240, GetColor(255, 255, 255), DebugTitle, TRUE);

		sprintf(DebugTitle, (char*)"2.���ׂĂ̂ǂ��Ԃ��������傤�ɂ���");
		DrawFormatString(710, 280, GetColor(255, 255, 255), DebugTitle, TRUE);


		break;
	case 2:
		sprintf(DebugTitle, (char*)"�`�P�b�g�`�[�g");
		DrawFormatString(710, 200, GetColor(255, 255, 255), DebugTitle, TRUE);

		sprintf(DebugTitle, (char*)"2.�`�P�b�g��100�����炤");
		DrawFormatString(710, 240, GetColor(255, 255, 255), DebugTitle, TRUE);

		break;

	default:
		break;
	}

	DrawDialog();

}

void DebugScene::DrawDialog() {
	/// <summary>
	/// �f�o�b�O�R�}���h�����s����Ă�����`�悷��
	/// </summary>
	if (isDebugCommanded == true) {
		DrawGraph(playerInformationDialog.baseX, playerInformationDialog.baseY, playerInformationDialog.backDialogGraphH, TRUE);
		DrawFormatString(playerInformationDialog.baseX + 75, playerInformationDialog.baseY + 80, GetColor(255, 255, 255), debugResultMessage);
		DrawBox(playerInformationDialog.baseX + 145, playerInformationDialog.baseY + 190, playerInformationDialog.baseX + 280, playerInformationDialog.baseX + 240, GetColor(125, 255, 255), TRUE);

		DrawFormatString(playerInformationDialog.baseX + 180, playerInformationDialog.baseY + 200, GetColor(255, 255, 255), "OK");

	}
}


/// <summary>
/// �f�o�b�O�V�[�����ł̑���
/// </summary>
void DebugScene::UpdateNowScene() {

	if (changeMenu <= 3) {
		changeMenu++;
	}

	/// <summary>
	/// �J�e�S���[���Ƃ̃f�o�b�O�@�\����
	/// </summary>
	switch (selectCategory) {
	case 0:
		if (CheckHitKey(KEY_INPUT_1)!= 0) {
			sprintf(debugResultMessage, (char*)"�ő僌�x���ɂ�����");
			playerInformation->expInfo.nowLevel = 100;
			playerInformation->expInfo.nowExp = 100;
			isDebugCommanded = true;
		}
		if (CheckHitKey(KEY_INPUT_2) != 0) {
			sprintf(debugResultMessage, (char*)"�������x���ɂ��ǂ�����");
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