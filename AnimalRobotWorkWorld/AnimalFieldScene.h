#define _CRT_SECURE_NO_WARNINGS
#include "DxLib.h"
#pragma once
#include "AnimalRobot.h"
#include "Dialog.h"
#include <map>

/// <summary>
/// �ǂ��Ԃ���Q�[���V�[��
/// </summary>
class AnimalFieldScene {
public:

	// �X���pUI�摜

	int storeLeftDialogH;


	// �v���C���[���

	int InGamePlayerModelH;

	int InGameBackModelH;

	// �A�C�e���������L�����N�^�[
	int StoreNpcModelH;

	bool isStoreOpen;

	// �_�C�A���O�`��p�C���X�^���X
	PlayerInformationDialog playerInformationDialog = PlayerInformationDialog();

	PlayerInformationDialog unitParamDialog = PlayerInformationDialog();


	// �v���C���[���
	PlayerInformation playerInformation;

	// ���ۂɋ��Z�ɎQ������ǂ��Ԃ��{
	AnimalRobot animalRobot;

	// ���E�␳
	float leftPos;
	float zPos;

	// ����w���p�p�����[�^
	int price[3];

	int priceNumber = 1;

	bool isStoreMessageOpen;



	/// <summary>
	/// �C���Q�[�����̏����������ŃQ�[���J�n�O�ɐݒ肳���
	/// </summary>
	void Initialize() {
		// 2D�Q�[���摜����

		playerInformationDialog.backDialogGraphH = LoadGraph("AnimalRobotStoreMessageBackGround.png");
		storeLeftDialogH = LoadGraph("StoreLeftDialogBackGround.png");
		unitParamDialog.backDialogGraphH = LoadGraph("ProfileUnitDialogBackGround.png");
		isStoreMessageOpen = false;
		unitParamDialog.backDialogGraphH = LoadGraph("ProfileUnitDialogBackGround.png");
		// �Q�[�����̃��f���f�[�^
		InGamePlayerModelH = MV1LoadModel("InGame_Model_1.X");
		InGameBackModelH = MV1LoadModel("InGame_BackModel_1.X");
		// �J�����̐ݒ�
		ExpInfo expInfo = ExpInfo(45, 30);
		AgpInfo agpInfo = AgpInfo(20000);
		AnimalRobotLiveTicketInfo ticketInfo = AnimalRobotLiveTicketInfo(500);
		std::vector<AnimalRobot> animalRobotList;
		playerInformation = PlayerInformation();
		playerInformation.SetProfile(expInfo, agpInfo, ticketInfo, animalRobotList);
		StoreNpcModelH = MV1LoadModel("Field_NpcStore.X");
		isStoreOpen = false;
		leftPos = 0.0f;
		zPos = 0.0f;
		priceNumber = 1;

		price[0] = 800;
		price[1] = 1200;
		price[2] = 4500;


	}

	PlayerInformation* GetPlayerInformation() { return &this->playerInformation; };
	void Update();
	void Draw();
	int  ChangeScene();
};