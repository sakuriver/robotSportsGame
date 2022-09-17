#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include "DxLib.h"
#include "AnimalRobot.h"
#include "Dialog.h"
#include <map>

/// <summary>
/// デバッグモード管理
/// </summary>
class DebugScene {

public:

	/// <summary>
	/// デバッグメニューの大カテゴリーの画像ハンドル
	/// </summary>
	int leftMenuHandle;

	/// <summary>
	/// デバッグメニューの変更する項目の画像ハンドル
	/// </summary>
	int rightMenuHandle;

	///
	/// 選択中のデバッグ大カテゴリー
	/// 
	int selectCategory;

	/// <summary>
	/// チャタリング対応
	/// </summary>
	int changeMenu;


	char debugResultMessage[50];


	/// <summary>
	/// コマンドを実行した
	/// </summary>
	bool isDebugCommanded;

	/// <summary>
	/// プレイヤー情報
	/// プレイ中のチート機能は、ここで修正して反映をする
	/// </summary>
	PlayerInformation* playerInformation;

	/// <summary>
	/// デバッグ実行ダイアログ
	/// </summary>
	PlayerInformationDialog playerInformationDialog;

	void SetPlayerInformation(PlayerInformation* playerInformation) {
		this->playerInformation = playerInformation;
	}

	void DrawNowScene();
	void UpdateNowScene();
	void Initialize();

private:
	void DrawDialog();

};

