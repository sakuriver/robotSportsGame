

#define _CRT_SECURE_NO_WARNINGS
#include "AnimalFieldScene.h"
#include <stdio.h>

using namespace std;

/// <summary>
/// ����ǂ�������t���
/// </summary>
void AnimalFieldScene::Draw()
{
	int drawBaseX = this->playerInformationDialog.baseX;
	int drawBaseY = this->playerInformationDialog.baseY + 30;


	SetFontSize(25);


	// ��ʂɉf��ʒu�ɂR�c���f�����ړ�
	MV1SetRotationXYZ(InGamePlayerModelH, VGet(0.0f, 180.0f * DX_PI_F / 180.0f, 0.0f));

	MV1SetPosition(InGameBackModelH, VGet(620.0f, 500.0f, -600.0f));

	VECTOR calcAnimalPosition = VGet(620.0f + leftPos, 500.0f, -500.0f + zPos);
	MV1SetPosition(InGamePlayerModelH, calcAnimalPosition);
	MV1SetPosition(StoreNpcModelH, VGet(320.0f, 500.0f, 4000.0f));


	// �J�����̒����_��ݒ�
	SetCameraPositionAndTarget_UpVecY(VGet(620.0f + leftPos, 500.0f, -600.0f + zPos - 50.0f), VGet(620.0f + leftPos, 500.0f, -600.0f + zPos - 10));


	SetFontSize(45);


	// ���f���̕`��
	MV1DrawModel(InGameBackModelH);

	MV1DrawModel(InGamePlayerModelH);


	MV1DrawModel(StoreNpcModelH);


	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);

	// �ǂ��Ԃp�[�c�w���\���
	if (!isStoreOpen && calcAnimalPosition.z >= 2800 && calcAnimalPosition.z <= 3600) {
		DrawFormatString(drawBaseX + 200, 300, GetColor(255, 255, 255), "Z : �X���ɐ���������");

	}

	if (isStoreOpen) {
		COLORDATA colorData = COLORDATA();
		SetFontSize(28);



		DrawGraph(100, drawBaseY + 120, storeLeftDialogH, TRUE);

		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 122);

		DrawBox(100, drawBaseY + 50, 700, drawBaseY + 120, GetColor3(&colorData, 10, 10, 10, 120), TRUE);

		DrawBox(900, drawBaseY, 1300, drawBaseY + 70, GetColor3(&colorData, 10, 10, 10, 120), TRUE);

		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);

		DrawFormatString(120, drawBaseY + 70, GetColor(255, 255, 255), "�ρ[������");
		char agpInfoFormat[80];
		int nowAgp = this->playerInformation.agpInfo.nowAgp;
		sprintf(agpInfoFormat, "�ǂ��Ԃ|�C���g : %d ", nowAgp);

		DrawFormatString(900, drawBaseY + 30, GetColor(255, 255, 0), agpInfoFormat);

		char priceInfoFormat[3][80];

		char productName[3][80];
		sprintf(productName[0], "�J�o�̂Ђ��肤��");
		sprintf(productName[1], "�`�[�^�[�̑�");
		sprintf(productName[2], "�h���S���݂̂�����");


		int weaponFormatIndex = 3;

		for (int i = 0; i < weaponFormatIndex; i++) {

			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);

			DrawBox(120, drawBaseY + 160 + (i * 50), 500, drawBaseY + 205 + (i * 50), GetColor3(&colorData, 10, 10, 180, 120), TRUE);

			sprintf(priceInfoFormat[i], "%s : %d ", productName[i], price[i]);


			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);

			DrawFormatString(120, drawBaseY + 160 + (i * 50), GetColor(255, 255, 255), priceInfoFormat[i]);


		}

		if (isStoreMessageOpen) {

			int dialogBaseX = drawBaseX + 200;
			int dialogBaseY  = drawBaseY + 300;
			DrawGraph(drawBaseX + 180, dialogBaseY + 30, playerInformationDialog.backDialogGraphH, TRUE);
			char storeMessage[3][50];
			sprintf(storeMessage[0], "%s���w���ł�����? ", productName[priceNumber]);
			sprintf(storeMessage[1], "�ǂ��Ԃ|�C���g");
			sprintf(storeMessage[2], "% d ��% d �ł���", nowAgp, nowAgp - price[priceNumber]);
			int MessageColor = GetColor(255, 255, 255);

			DrawFormatString(dialogBaseX + 60, dialogBaseY + 80, MessageColor, storeMessage[0]);
			DrawFormatString(dialogBaseX + 60, dialogBaseY + 130, MessageColor, storeMessage[1]);
			DrawFormatString(dialogBaseX + 60, dialogBaseY + 180, GetColor(255, 0, 0), storeMessage[2]);

			DrawBox(dialogBaseX + 145, dialogBaseY + 230, dialogBaseX + 200, dialogBaseY + 270, GetColor(125, 255, 255), TRUE);

			DrawFormatString(dialogBaseX + 160, dialogBaseY + 240, GetColor(255, 255, 255), "OK");

			DrawBox(dialogBaseX + 230, dialogBaseY + 230, dialogBaseX + 350, dialogBaseY + 270, GetColor(125, 255, 255), TRUE);

			DrawFormatString(dialogBaseX + 250, dialogBaseY + 240, GetColor(255, 255, 255), "CANCEL");

		}


		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);


		SetFontSize(25);

		DrawFormatString(drawBaseX + 850, 800, GetColor(255, 255, 255), "X : �X�𗣂��");





	}

}



/// <summary>
/// �v���C���[��ʓ��ł̑���؂�ւ�
/// </summary>
void AnimalFieldScene::Update()
{
	float moveSpeed = 8.0f;

	if (isStoreOpen == false) {
		if (CheckHitKey(KEY_INPUT_UP) != 0) {
			zPos += moveSpeed;
		}


		if (CheckHitKey(KEY_INPUT_DOWN) != 0) {
			zPos -= moveSpeed;
		}

		if (CheckHitKey(KEY_INPUT_LEFT) != 0) {
			leftPos -= moveSpeed;
		}

		if (CheckHitKey(KEY_INPUT_RIGHT) != 0) {
			leftPos += moveSpeed;
		}

	}
	else {
		if (CheckHitKey(KEY_INPUT_RETURN) != 0) {
			isStoreMessageOpen = true;
		}
	}

	if (CheckHitKey(KEY_INPUT_Z) != 0) {
		isStoreOpen = true;
		isStoreMessageOpen = false;
	}


	if (CheckHitKey(KEY_INPUT_X) != 0) {
		isStoreOpen = false;
		isStoreMessageOpen = false;
	}



}