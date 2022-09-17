

#define _CRT_SECURE_NO_WARNINGS
#include "InGameAnimationScene.h"
#include <stdio.h>

using namespace std;



/// <summary>
/// �v���t�B�[�����
/// </summary>
void IngameAnimationScene::Draw()
{
	int drawBaseX = this->playerInformationDialog.baseX;
	int drawBaseY = this->playerInformationDialog.baseY + 30;

	// �t�H�O��L���ɂ���
	SetFogEnable(false);

	// �t�H�O�̐F�𐅂ɂ���
	SetFogColor(0, 255, 180);

	// �t�H�O�̊J�n�������O�A�I���������P�T�O�O�ɂ���
	SetFogStartEnd(-2000.0f, 3000.0f);

	SetFontSize(25);

	DrawFormatString(drawBaseX + 100, drawBaseY, GetColor(255, 255, 255), "�ǂ��Ԃ]��������");

	// ��ʂɉf��ʒu�ɂR�c���f�����ړ�
	MV1SetRotationXYZ(InGamePlayerModelH, VGet(0.0f, 180.0f * DX_PI_F / 180.0f, 0.0f));
	MV1SetPosition(InGameBackModelH, VGet(620.0f, 500.0f, -600.0f));

	// �����v�Z�� �J�n�ʒu + (�{�^���i�s�J�E���g + (�R���{�W�� * 2)) 
	MV1SetPosition(InGamePlayerModelH, VGet(620.0f, 500.0f, -600.0f + dushCount ));
	SetFontSize(45);


	// ���f���̕`��
	MV1DrawModel(InGameBackModelH);

	MV1DrawModel(InGamePlayerModelH);


	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	DrawFormatString(700, 30, GetColor(255, 255, 255), "TIME 200");

	// �A����������A��p�������o��
	if (comboCount > 3) {
		char paramCombo[50];
		SetFontSize(45 + comboCount);
		sprintf(paramCombo, "�R���{    %d", comboCount);

		DrawFormatString(700, 430, GetColor(255, 255, 0), paramCombo);

	}


}



/// <summary>
/// �v���C���[��ʓ��ł̑���؂�ւ�
/// </summary>
void IngameAnimationScene::Update()
{
	if (CheckHitKey(KEY_INPUT_K) != 0) {
			dushCount += 0.1f;
			if (beforeJButton && beforeCount <= 60) {
				comboCount++;
				beforeJButton = false;
				beforeKButton = true;
			}
	}


	if (CheckHitKey(KEY_INPUT_J) != 0) {
		dushCount += 0.1f;
		if (beforeKButton && beforeCount <= 60) {
			comboCount++;
			beforeJButton = true;
			beforeKButton = false;
		}
	}


	if (beforeCount > 60) {
		comboCount = 0;
		beforeCount = 0;
	}

	beforeCount++;

	dushCount += (comboCount * 2);
}