#define _CRT_SECURE_NO_WARNINGS
#include "DxLib.h"
#pragma once
#include "AnimalRobot.h"
#include "Dialog.h"
#include <map>

/// <summary>
/// どうぶつえんアニメーション&シェーダーテスト
/// </summary>
class IngameAnimationScene {
public:

	// 水中表現
	int VertexShaderHandle;
	int PixelShaderHandle;

	int InGamePlayerModelH;

	int InGameBackModelH;

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

	// 実際に競技に参加するどぶつロボ
	AnimalRobot animalRobot;

	// ゴールへ向かってのカウントボタン
	float dushCount;

	int ComboCount = 0;

	/// <summary>
	/// ゲームコンボ
	/// 特定時間内に交互指定のボタンを押せると増える
	/// </summary>
	int comboCount = 0;

	/// <summary>
	/// ずっと同じボタンを押している場合は、コンボが途切れる
	/// </summary>

	int beforeCount = 0;


	/// <summary>
	/// ボタン交互処理を実装
	/// </summary>
	bool beforeJButton = true;
	bool beforeKButton = false;

	/// <summary>
	/// インゲーム内の初期化処理でゲーム開始前に設定される
	/// </summary>
	void Initialize() {
		// 2Dゲーム画像処理
		playerInformationDialog.backDialogGraphH = LoadGraph("ProfileDialogBackGround.png");
		unitParamDialog.backDialogGraphH = LoadGraph("ProfileUnitDialogBackGround.png");
		profileUnitPartsLeftBackH = LoadGraph("AnimalRobotlProfileLeftBackGround.png");
		// ゲーム内のモデルデータ
		InGamePlayerModelH = MV1LoadModel("InGame_Model_1.X");
		InGameBackModelH = MV1LoadModel("InGame_BackModel_1.X");
		// カメラの設定
		ExpInfo expInfo = ExpInfo(45, 30);
		AgpInfo agpInfo= AgpInfo(30);
		AnimalRobotLiveTicketInfo ticketInfo = AnimalRobotLiveTicketInfo(500);
		std::vector<AnimalRobot> animalRobotList;
		playerInformation = PlayerInformation();
		playerInformation.SetProfile(expInfo, agpInfo, ticketInfo, animalRobotList);
		unitStartMovieH = LoadGraph("UnitStart1.GIF");
		// 頂点シェーダーを読み込む
		VertexShaderHandle = LoadVertexShader("NormalMesh_NoLight_FogVS.vso");

		// ピクセルシェーダーを読み込む
		PixelShaderHandle = LoadPixelShader("NormalMesh_NoLight_FogPS.pso");


		dushCount = 0.0f;
		ComboCount = 0;
		beforeJButton = true;
		beforeKButton = false;

		// モデルの描画にオリジナルシェーダーを使用する設定をＯＮにする
	//	MV1SetUseOrigShader(TRUE);

		// 使用する頂点シェーダーをセット
		SetUseVertexShader(VertexShaderHandle);

		// 使用するピクセルシェーダーをセット
		SetUsePixelShader(PixelShaderHandle);


	}

	PlayerInformation* GetPlayerInformation() { return &this->playerInformation; };
	void Update();
	void Draw();
	int  ChangeScene();
};