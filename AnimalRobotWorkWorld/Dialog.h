#include "DxLib.h"
#pragma once
#include "AnimalRobot.h"

/// <summary>
/// �v���C���[���_�C�A���O
/// </summary>
class PlayerInformationDialog {
public:
	/// <summary>
	/// �_�C�A���O�̍�����W�̐ݒ���
	/// </summary>
	int baseX;
	int baseY;

	/// <summary>
	/// �_�C�A���O�̔w�i�摜�n���h��
	/// </summary>
	int backDialogGraphH;


	void Draw() {
		DrawGraph(baseX, baseY, backDialogGraphH, TRUE);
	};
	void Update();


};
