#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include "DxLib.h"
#include "AnimalRobot.h"
#include "Dialog.h"
#include <map>

/// <summary>
/// �f�o�b�O���[�h�Ǘ�
/// </summary>
class DebugScene {

public:

	/// <summary>
	/// �f�o�b�O���j���[�̑�J�e�S���[�̉摜�n���h��
	/// </summary>
	int leftMenuHandle;

	/// <summary>
	/// �f�o�b�O���j���[�̕ύX���鍀�ڂ̉摜�n���h��
	/// </summary>
	int rightMenuHandle;

	///
	/// �I�𒆂̃f�o�b�O��J�e�S���[
	/// 
	int selectCategory;

	/// <summary>
	/// �`���^�����O�Ή�
	/// </summary>
	int changeMenu;


	char debugResultMessage[50];


	/// <summary>
	/// �R�}���h�����s����
	/// </summary>
	bool isDebugCommanded;

	/// <summary>
	/// �v���C���[���
	/// �v���C���̃`�[�g�@�\�́A�����ŏC�����Ĕ��f������
	/// </summary>
	PlayerInformation* playerInformation;

	/// <summary>
	/// �f�o�b�O���s�_�C�A���O
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

