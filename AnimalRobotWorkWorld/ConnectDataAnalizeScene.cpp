#define _CRT_SECURE_NO_WARNINGS
#include "ConnectDataAnalizeScene.h"

void ConnectDataAnalizeScene::Initialize() {
	playerInformationDialog = PlayerInformationDialog();
	playerInformationDialog.baseX = 400;
	playerInformationDialog.baseY = 400;
	playerInformationDialog.backDialogGraphH = LoadGraph("AnimalRobotDebugMessageBackGround.png");
	IsEncrypt = false;
	IsDecrypt = false;
	EncryptAnimCount = 0;
	DecryptAnimCount = 0;
}


/// <summary>
/// ���݂̉�͂���󋵂��킩��
/// </summary>
void ConnectDataAnalizeScene::DrawNowScene() {

	SetFontSize(24);

	char DebugTitle[50];
	sprintf(DebugTitle, (char*)"�ǂ��Ԃ� ���Ă��� �����ɂ�Z���^�[");
	DrawFormatString(400, 100, GetColor(255, 200, 200), DebugTitle, TRUE);

	if (IsEncrypt) {
		char CryptStartTitle[50];

		sprintf(CryptStartTitle, (char*)"�閧�̂��Ă��݂ɂ����[");
		DrawFormatString(510, 185, GetColor(255, 200, 200), CryptStartTitle, TRUE);

		char TargetDescriptionMessage[100];

		if (EncryptAnimCount > 30) {

			sprintf(TargetDescriptionMessage, (char*)"���̂��莆��閧�̕����ɂ����");
			DrawFormatString(510, 230, GetColor(255, 200, 200), TargetDescriptionMessage, TRUE);
		}

		if (EncryptAnimCount > 60) {
			sprintf(TargetDescriptionMessage, (char*)"�������݂͂�߂Ȃ��悤�ɂ����");
			DrawFormatString(510, 280, GetColor(255, 200, 200), TargetDescriptionMessage, TRUE);
		}

		if (EncryptAnimCount > 90) {
			DrawFormatString(510, 320, GetColor(255, 200, 200), "�ǂ��ԂA���ɂ��炭�ł���񂾂�", TRUE);
		}
		SetFontSize(15);
		if (EncryptAnimCount > 120) {
			DrawFormatString(510, 345, GetColor(255, 200, 200), "���̂��莆�����炭������e����", TRUE);
			DrawFormatString(510, 370, GetColor(255, 200, 200), (char*)pszBaseString, TRUE);

		}

		if (EncryptAnimCount > 150) {
			char convertMessage[100];
			sprintf(convertMessage, "�Ђ݂̂��Ă��݂͂��m�点�ɂ����肪�����B");
			DrawFormatString(500, 560, GetColor(255, 200, 200), convertMessage, TRUE);

			sprintf(convertMessage, "���񂩂���%d�����ɕ����āA������ˁB", encodeResultNum);
			DrawFormatString(500, 580, GetColor(255, 200, 200), convertMessage, TRUE);
			for (int i = 0; i < encodeResultNum; i++) {
				DrawFormatString(500, 600+i*45, GetColor(255, 200, 200), (char*)encodeResult[i], TRUE);
			}

		}

	}

	if (IsDecrypt) {
		char CryptStartTitle[50];

		sprintf(CryptStartTitle, (char*)"���������J�n�����[");
		DrawFormatString(500, 185, GetColor(255, 200, 200), CryptStartTitle, TRUE);
		SetFontSize(15);
		if (DecryptAnimCount > 30) {
			char TargetDescriptionMessage[100];

			sprintf(TargetDescriptionMessage, (char*)"���̂��莆����߂�悤�ɂ���ˁ[");
			DrawFormatString(500, 210, GetColor(255, 200, 200), TargetDescriptionMessage, TRUE);
		}


		if (DecryptAnimCount > 30) {
			char convertMessage[100];
			sprintf(convertMessage, "�Ђ݂̂��Ă��݂͂��m�点�ɂ����肪�����B");
			DrawFormatString(500, 260, GetColor(255, 200, 200), convertMessage, TRUE);

			sprintf(convertMessage, "���񂩂���%d�����Ńn�g���񂩂���炭������", encodeResultNum);
			DrawFormatString(500, 280, GetColor(255, 200, 200), convertMessage, TRUE);
			for (int i = 0; i < encodeResultNum; i++) {
				DrawFormatString(500, 300 + i * 45, GetColor(255, 200, 200), (char*)encodeResult[i], TRUE);
			}

		}

		if (DecryptAnimCount > 90) {
			SetFontSize(23);
			DrawFormatString(510, 450, GetColor(255, 200, 200), "���ꂶ�Ⴀ�A���̂��莆����͂����", TRUE);
		}

		if (DecryptAnimCount > 90 && DecryptAnimCount < 180) {
			SetFontSize(20);
			DrawFormatString(510, 480, GetColor(255, 200, 200), "���莆��͒�����....", TRUE);
		}

		if ( DecryptAnimCount > 190) {
			DrawFormatString(510, 480, GetColor(255, 200, 200), "���Ă��݂͖l��������Ă����\�͂�������", TRUE);
		}

		if (DecryptAnimCount > 230) {
			char convertResultMessage[100];

			sprintf(convertResultMessage, "�����̂͂₳ %d �܂ł�����", animalRobot.getSpeed());
			DrawFormatString(510, 520, GetColor(255, 200, 200), convertResultMessage, TRUE);
			sprintf(convertResultMessage, "�����������Z�ł̂�����傭 %d �܂ł�����", animalRobot.getHp());
			DrawFormatString(510, 550, GetColor(255, 200, 200), convertResultMessage, TRUE);
			sprintf(convertResultMessage, "�����݂� %d �܂ł�����", animalRobot.getSpeed());
			DrawFormatString(510, 580, GetColor(255, 200, 200), convertResultMessage, TRUE);

		}

	}

}

void ConnectDataAnalizeScene::DrawDialog() {


}


/// <summary>
/// �Z�[�u�f�[�^��͎��̑�����
/// </summary>
void ConnectDataAnalizeScene::UpdateNowScene() {

	// �Í����������ʂ̕`��J�n
	if (CheckHitKey(KEY_INPUT_1) != false) {
		IsEncrypt = true;
		IsDecrypt = false;
		EncryptAnimCount = 0;
	}

	// �������������ʂ̕`��J�n
	if (CheckHitKey(KEY_INPUT_2) != false) {
		IsEncrypt = false;
		IsDecrypt = true;
		DecryptAnimCount = 0;
	}

	if (IsEncrypt) {
		EncryptAnimCount++;
	}


	if (IsDecrypt) {
		DecryptAnimCount++;
	}

}