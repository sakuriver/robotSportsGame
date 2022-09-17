

#define _CRT_SECURE_NO_WARNINGS
#include "SceneManager.h"
#include <stdio.h>

using namespace std;

void SceneManager::DrawNowScene()
{
}

void SceneManager::SetSceneType(int sceneType)
{

}

void SceneManager::UpdateNowScene()
{
}

enum ProfileMode {
	PlayerBasicInformation = 1,
	BeforeStartSelect = 2,
	AnimalRobotStart = 3,
	AnimalInGame = 4
};

/// <summary>
/// �v���t�B�[�����
/// </summary>
void ProfileScene::Draw()
{
	switch (playerDrawType)
	{
	case ProfileMode::PlayerBasicInformation:
		DrawBasicInformation();
		break;
	case ProfileMode::BeforeStartSelect:
		DrawRobotList();
		break;
	case ProfileMode::AnimalRobotStart:
		DrawAnimalRobotStart();
		break;
	}

}

/// <summary>
/// �v���C���[�̊�{���\��
/// </summary>
void ProfileScene::DrawBasicInformation()
{
	this->playerInformationDialog.baseX = 400;
	this->playerInformationDialog.baseY = 150;

	this->playerInformationDialog.Draw();
	char expInfoFormat[50];
	char agpInfoFormat[50];
	// �������{�b�g�ꗗ
	SetFontSize(42);
	int drawBaseX = this->playerInformationDialog.baseX;
	int drawBaseY = this->playerInformationDialog.baseY + 30;
	DrawGraph(100, drawBaseY - 120, profileBackDialogGraphH, TRUE);

	DrawFormatString(drawBaseX + 120, drawBaseY - 100, GetColor(255, 255, 255), "�v���t�B�[��");

	SetFontSize(25);

	DrawFormatString(drawBaseX + 100, drawBaseY, GetColor(255, 255, 255), "��{���");
	// �v���C���[���Ƃ̃Z�[�u����`��


	// ���̃��x���܂ł̌o���l...�v������
	float nextExp = 100.0f;

	// �o���l�Q�[�W�̌v�Z
	int expGaugeWidth = ((float)this->playerInformation.expInfo.nowExp / nextExp) * 400;

	sprintf(expInfoFormat, "���x�� : %d ", this->playerInformation.expInfo.nowLevel);
	DrawFormatString(drawBaseX + 100, drawBaseY + 70, GetColor(255, 255, 255), expInfoFormat);
	sprintf(expInfoFormat, "�o���l : %d ", this->playerInformation.expInfo.nowExp);
	DrawFormatString(drawBaseX + 100, drawBaseY + 100, GetColor(255, 255, 255), expInfoFormat);

	DrawBox(drawBaseX + 100, drawBaseY + 170, drawBaseX + 400, drawBaseY + 190, GetColor(0, 0, 0), TRUE);

	DrawBox(drawBaseX + 100, drawBaseY + 170, drawBaseX + expGaugeWidth, drawBaseY + 190, GetColor(0, 180, 0), TRUE);

	sprintf(agpInfoFormat, "�����|�C���g : %d ", this->playerInformation.agpInfo.nowAgp);

	DrawFormatString(drawBaseX + 100, drawBaseY + 220, GetColor(255, 255, 255), agpInfoFormat);

	DrawFormatString(drawBaseX + 100, drawBaseY + 300, GetColor(255, 255, 255), "�`�P�b�g���");

	sprintf(agpInfoFormat, "�����^����`�P�b�g : %d ", this->playerInformation.liveTicketInfo.nowTicket);
	DrawFormatString(drawBaseX + 100, drawBaseY + 350, GetColor(255, 255, 255), agpInfoFormat);

	DrawFormatString(drawBaseX + 100, drawBaseY + 450, GetColor(255, 255, 255), "Enter�łƂ������������");

}

/// <summary>
/// 
/// </summary>
void ProfileScene::DrawRobotList()
{



	// �������{�b�g�ꗗ
	SetFontSize(42);

	DrawGraph(100, 50, profileBackDialogGraphH, TRUE);

	DrawFormatString(410, 70, GetColor(255, 255, 255), "�Ƃ������������");

	SetFontSize(22);

	DrawFormatString(330, 150, GetColor(255, 255, 255), "���Ƃ�������I��ł�������");

	// �e����`��


	DrawGraph(100, 180, profileUnitPartsLeftBackH, TRUE);

	this->unitParamDialog.baseX = 640;
	this->unitParamDialog.baseY = 180;


	int selectUnitId = playerInformation.robotList[selectUnitIndex].getId();


	DrawFormatString(this->unitParamDialog.baseX + 10, this->unitParamDialog.baseY + 3, GetColor(255, 255, 255), roboNamemap[selectUnitId]);


	for (int i = 1; i <= roboRegistMax; i++) {
		DrawGraph( i * 110, 200, roboIconGraphmap[playerInformation.robotList[i].getId()], TRUE);
	}

	DrawGraph(1050, 300, roboFullGraphmap[selectUnitId], TRUE);

	this->unitParamDialog.Draw();

	char paramHpName[50];
	char paramPowerName[50];
	char paramSpeedName[50];

	sprintf(paramHpName, "������傭    %d", 100);
	DrawFormatString(this->unitParamDialog.baseX + 10, this->unitParamDialog.baseY + 30, GetColor(255, 255, 255), paramHpName);

	DrawBox(this->unitParamDialog.baseX + 210, this->unitParamDialog.baseY + 30, this->unitParamDialog.baseX + 390, this->unitParamDialog.baseY + 50, GetColor(0, 0, 0), TRUE);
	DrawBox(this->unitParamDialog.baseX + 210, this->unitParamDialog.baseY + 30, this->unitParamDialog.baseX + 310, this->unitParamDialog.baseY + 50, GetColor(0, 180, 0), TRUE);



	sprintf(paramPowerName, "������    %d", 30);
	DrawFormatString(this->unitParamDialog.baseX + 10, this->unitParamDialog.baseY + 60, GetColor(255, 255, 255), paramPowerName);

	DrawBox(this->unitParamDialog.baseX + 210, this->unitParamDialog.baseY + 60, this->unitParamDialog.baseX + 390, this->unitParamDialog.baseY + 80, GetColor(0, 0, 0), TRUE);
	DrawBox(this->unitParamDialog.baseX + 210, this->unitParamDialog.baseY + 60, this->unitParamDialog.baseX + 240, this->unitParamDialog.baseY + 80, GetColor(0, 180, 0), TRUE);



	sprintf(paramSpeedName, "�͂₳    %d", 100);
	DrawFormatString(this->unitParamDialog.baseX + 10, this->unitParamDialog.baseY + 90, GetColor(255, 255, 255), paramSpeedName);


	DrawBox(this->unitParamDialog.baseX + 210, this->unitParamDialog.baseY + 90, this->unitParamDialog.baseX + 390, this->unitParamDialog.baseY + 110, GetColor(0, 0, 0), TRUE);
	DrawBox(this->unitParamDialog.baseX + 210, this->unitParamDialog.baseY + 90, this->unitParamDialog.baseX + 270, this->unitParamDialog.baseY + 110, GetColor(0, 180, 0), TRUE);

	DrawFormatString(630, 750, GetColor(255, 255, 255), "Enter�ł���ǂ������ɂ�����ς�");


}


/// <summary>
/// �ǂ��Ԃ��{�b�g����ǂ������o��
/// </summary>
void ProfileScene::DrawAnimalRobotStart()
{

	if (TellMovieToGraphToFrame(unitStartMovieH) != GetMovieTotalFrameToGraph(unitStartMovieH)) {
		DrawExtendGraph(0, 0, 1400, 1000, unitStartMovieH, FALSE);
	}


}

/// <summary>
/// �v���C���[��ʓ��ł̑���؂�ւ�
/// </summary>
void ProfileScene::Update()
{
	switch (playerDrawType)
	{
	case 1:
		if (CheckHitKey(KEY_INPUT_RETURN)!=0) {
			playerDrawType = ProfileMode::BeforeStartSelect;
		}
		break;
	case ProfileMode::BeforeStartSelect:
		if (CheckHitKey(KEY_INPUT_O)!=0) {
			playerDrawType = ProfileMode::PlayerBasicInformation;
		}

		if (CheckHitKey(KEY_INPUT_P) != 0) {
			SeekMovieToGraph(unitStartMovieH, 0);
			PlayMovieToGraph(unitStartMovieH);
			playerDrawType = ProfileMode::AnimalRobotStart;
		}
		break;
	case ProfileMode::AnimalRobotStart:
		if (TellMovieToGraph(unitStartMovieH) > 6000) {
			playerDrawType = ProfileMode::AnimalInGame;
		}
		break;
	}
}

int ProfileScene::ChangeScene()
{

	if (playerDrawType == ProfileMode::AnimalInGame && CheckHitKey(KEY_INPUT_RETURN) != 0) {
		return playerDrawType;
	}
	return 0;
}