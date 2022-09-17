#define _CRT_SECURE_NO_WARNINGS
#include "DxLib.h"
#pragma once
#include "AnimalRobot.h"
#include "Dialog.h"
#include <map>
/// <summary>
/// �V�[���Ǘ��N���X
/// </summary>
class SceneManager {


	int sceneType;

	void SetSceneType(int sceneType);

	void DrawNowScene();
	void UpdateNowScene();

	
};

class ProfileScene {
public:
	/// <summary>
	/// �v���t�B�[����ʏ�̃O���t�B�b�N�n���h��
	/// </summary>
	int profileBackDialogGraphH;



	/// <summary>
	/// �p�[�c�ݒ��ʂ̃��j�b�g�I�𕔕��̔w�i
	/// </summary>
	int profileUnitPartsLeftBackH;

	int unitStartMovieH;

	// �_�C�A���O�`��p�C���X�^���X
	PlayerInformationDialog playerInformationDialog = PlayerInformationDialog();

	PlayerInformationDialog unitParamDialog = PlayerInformationDialog();


	// �v���C���[���
	PlayerInformation playerInformation;

	/// <summary>
	/// �������{�A�C�R���ꗗ
	/// </summary>
	std::map<int, int> roboIconGraphmap;

	/// <summary>
	/// �I�𓮕����{�A�C�R���ꗗ
	/// </summary>
	std::map<int, int> roboFullGraphmap;

	/// <summary>
	/// �I�𓮕����{���ꗗ
	/// </summary>
	std::map<int, char*> roboNamemap;

	/// <summary>
	/// �ő働�{�o�^��
	/// </summary>
	int roboRegistMax = 3;

	/// <summary>
	/// �v���C���[�{�����ł̃V�[���^�C�v
	/// </summary>
	int playerDrawType;

	/// <summary>
	/// ���ݑI�𒆂̔ԍ�
	/// </summary>
	int selectUnitIndex = 1;

	void Initialize() {
		selectUnitIndex = 1;
		playerInformationDialog.backDialogGraphH = LoadGraph("ProfileDialogBackGround.png");
		profileBackDialogGraphH = LoadGraph("ProfileTitleBackGround.png");
		unitParamDialog.backDialogGraphH = LoadGraph("ProfileUnitDialogBackGround.png");
		profileUnitPartsLeftBackH = LoadGraph("AnimalRobotlProfileLeftBackGround.png");
		for (int i = 1; i <= roboRegistMax; i++) {
			char roboIconName[50];
			sprintf_s(roboIconName, "AnimalRobotIcon/Unit%d_icon.PNG", i);
			roboIconGraphmap[i] = LoadGraph(roboIconName);
			char roboFullName[50];
			sprintf_s(roboFullName, "AnimalRobotFull/Unit_%d.PNG", i);
			roboFullGraphmap[i] = LoadGraph(roboFullName);
			roboNamemap[i] = (char*)"���t�E�T��y";
		}
		playerDrawType = 1;
		ExpInfo expInfo = ExpInfo(45, 30);
		AgpInfo agpInfo = AgpInfo(30);
		AnimalRobotLiveTicketInfo ticketInfo = AnimalRobotLiveTicketInfo(500);
		std::vector<AnimalRobot> animalRobotList;
		for (int i = 0; i <= roboRegistMax; i++) {
			AnimalRobot animalRobot = AnimalRobot();
			animalRobot.setId(1);
			animalRobot.setHp(100);
			animalRobot.setPower(200);
			animalRobotList.push_back(animalRobot);
		}
		playerInformation = PlayerInformation();
		playerInformation.SetProfile(expInfo, agpInfo, ticketInfo, animalRobotList);
		unitStartMovieH = LoadGraph("UnitStart1.GIF");
	}

	PlayerInformation* GetPlayerInformation() { return &this->playerInformation; };
	 void Update();
	 void Draw();
	 void DrawBasicInformation();
	 void DrawRobotList();
	 void DrawAnimalRobotStart();
	 int  ChangeScene();
};

class AnimalRobotFieldTestScene {

};

class PlayBeforeScene {
};

class AnimalRobotPlayScene {

};

class AnimalRobotPlayResultScene {

};