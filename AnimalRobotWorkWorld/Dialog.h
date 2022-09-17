#include "DxLib.h"
#pragma once
#include "AnimalRobot.h"

/// <summary>
/// プレイヤー情報ダイアログ
/// </summary>
class PlayerInformationDialog {
public:
	/// <summary>
	/// ダイアログの左上座標の設定情報
	/// </summary>
	int baseX;
	int baseY;

	/// <summary>
	/// ダイアログの背景画像ハンドル
	/// </summary>
	int backDialogGraphH;


	void Draw() {
		DrawGraph(baseX, baseY, backDialogGraphH, TRUE);
	};
	void Update();


};
