#define _CRT_SECURE_NO_WARNINGS
#include "DxLib.h"
#pragma once
#include "AnimalRobot.h"
#include "Dialog.h"
#include <map>
/// <summary>
/// シーン管理クラス
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
	/// プロフィール画面上のグラフィックハンドル
	/// </summary>
	int profileBackDialogGraphH;



	/// <summary>
	/// パーツ設定画面のユニット選択部分の背景
	/// </summary>
	int profileUnitPartsLeftBackH;

	int unitStartMovieH;

	// ダイアログ描画用インスタンス
	PlayerInformationDialog playerInformationDialog = PlayerInformationDialog();

	PlayerInformationDialog unitParamDialog = PlayerInformationDialog();


	// プレイヤー情報
	PlayerInformation playerInformation;

	/// <summary>
	/// 動物ロボアイコン一覧
	/// </summary>
	std::map<int, int> roboIconGraphmap;

	/// <summary>
	/// 選択動物ロボアイコン一覧
	/// </summary>
	std::map<int, int> roboFullGraphmap;

	/// <summary>
	/// 選択動物ロボ名一覧
	/// </summary>
	std::map<int, char*> roboNamemap;

	/// <summary>
	/// 最大ロボ登録数
	/// </summary>
	int roboRegistMax = 3;

	/// <summary>
	/// プレイヤー閲覧情報でのシーンタイプ
	/// </summary>
	int playerDrawType;

	/// <summary>
	/// 現在選択中の番号
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
			roboNamemap[i] = (char*)"モフウサ先輩";
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