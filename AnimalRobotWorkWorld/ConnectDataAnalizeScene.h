#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include "DxLib.h"
#include "AnimalRobot.h"
#include "Dialog.h"
#include <map>

/// <summary>
/// セーブシーン解析
/// </summary>
class ConnectDataAnalizeScene {

public:


	/// <summary>
	/// デバッグ実行ダイアログ
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
	/// 解析結果を取得するよ
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
	/// お手紙の原文だよ
	/// </summary>
	BYTE* pszBaseString;

	/// <summary>
	/// 秘密のお手紙にしたものだよ
	/// </summary>
	LPSTR encodeResult[3];

	/// <summary>
	/// 秘密のお手紙の分割回数
	/// </summary>
	int encodeResultNum;


	/// <summary>
	/// お手紙の解析結果
	/// </summary>
	AnimalRobot animalRobot;

	/// <summary>
	/// 暗号化モードのメッセージカウント
	/// </summary>
	int EncryptAnimCount;

	/// <summary>
	/// 複合化モードのメッセージカウント
	/// </summary>
	int DecryptAnimCount;

	///
	/// 暗号化モードフラグ
	///
	bool IsEncrypt;
	
	/// 
	/// 複合化モードフラグ
	/// 
	bool IsDecrypt;

};

