#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include "DxLib.h"
#include "AnimalRobot.h"
#include "Dialog.h"
#include <map>

/// <summary>
/// �Z�[�u�V�[�����
/// </summary>
class ConnectDataAnalizeScene {

public:


	/// <summary>
	/// �f�o�b�O���s�_�C�A���O
	/// </summary>
	PlayerInformationDialog playerInformationDialog;

	void SetPlayerInformation(PlayerInformation* playerInformation) {
	}

	void SetPszString(BYTE* pszString)
	{
		pszBaseString = pszString;
	}

	/// <summary>
	/// 
	/// </summary>
	/// <param name="decodeResultTmp"></param>
	/// <param name="decodeResultTmpNum"></param>
	void SetEncodeResult(LPSTR decodeResultTmp[], int decodeResultTmpNum)
	{
		encodeResult[0] = decodeResultTmp[0];
		encodeResult[1] = decodeResultTmp[1];
		encodeResult[2] = decodeResultTmp[2];
		encodeResultNum = decodeResultTmpNum;
	}

	/// <summary>
	/// ��͌��ʂ��擾�����
	/// </summary>
	/// <param name="animalRobotTmp"></param>
	void SetAnimalRobot(AnimalRobot animalRobotTmp)
	{
		animalRobot = animalRobotTmp;
	}

	void DrawNowScene();
	void UpdateNowScene();
	void Initialize();

private:
	void DrawDialog();


	/// <summary>
	/// ���莆�̌�������
	/// </summary>
	BYTE* pszBaseString;

	/// <summary>
	/// �閧�̂��莆�ɂ������̂���
	/// </summary>
	LPSTR encodeResult[3];

	/// <summary>
	/// �閧�̂��莆�̕�����
	/// </summary>
	int encodeResultNum;


	/// <summary>
	/// ���莆�̉�͌���
	/// </summary>
	AnimalRobot animalRobot;

	/// <summary>
	/// �Í������[�h�̃��b�Z�[�W�J�E���g
	/// </summary>
	int EncryptAnimCount;

	/// <summary>
	/// ���������[�h�̃��b�Z�[�W�J�E���g
	/// </summary>
	int DecryptAnimCount;

	///
	/// �Í������[�h�t���O
	///
	bool IsEncrypt;
	
	/// 
	/// ���������[�h�t���O
	/// 
	bool IsDecrypt;

};

