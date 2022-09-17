#define _CRT_SECURE_NO_WARNINGS
#include "DxLib.h"
#pragma once
#include "AnimalRobot.h"
#include "Dialog.h"
#include <map>

/// <summary>
/// どうぶつえんゲームシーン
/// </summary>
class AnimalFieldScene {
public:

	// 店員用UI画像

	int storeLeftDialogH;


	// プレイヤー情報

	int InGamePlayerModelH;

	int InGameBackModelH;

	// アイテム交換所キャラクター
	int StoreNpcModelH;

	bool isStoreOpen;

	// ダイアログ描画用インスタンス
	PlayerInformationDialog playerInformationDialog = PlayerInformationDialog();

	PlayerInformationDialog unitParamDialog = PlayerInformationDialog();


	// プレイヤー情報
	PlayerInformation playerInformation;

	// 実際に競技に参加するどうぶつロボ
	AnimalRobot animalRobot;

	// 左右補正
	float leftPos;
	float zPos;

	// 武器購入用パラメータ
	int price[3];

	int priceNumber = 1;

	bool isStoreMessageOpen;



	/// <summary>
	/// インゲーム内の初期化処理でゲーム開始前に設定される
	/// </summary>
	void Initialize() {
		// 2Dゲーム画像処理

		playerInformationDialog.backDialogGraphH = LoadGraph("AnimalRobotStoreMessageBackGround.png");
		storeLeftDialogH = LoadGraph("StoreLeftDialogBackGround.png");
		unitParamDialog.backDialogGraphH = LoadGraph("ProfileUnitDialogBackGround.png");
		isStoreMessageOpen = false;
		unitParamDialog.backDialogGraphH = LoadGraph("ProfileUnitDialogBackGround.png");
		// ゲーム内のモデルデータ
		InGamePlayerModelH = MV1LoadModel("InGame_Model_1.X");
		InGameBackModelH = MV1LoadModel("InGame_BackModel_1.X");
		// カメラの設定
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