#define _CRT_SECURE_NO_WARNINGS
#include "DxLib.h"
#pragma once
#include "AnimalRobot.h"
#include "Dialog.h"
#include <map>

/// <summary>
/// �ǂ��Ԃ���A�j���[�V����&�V�F�[�_�[�e�X�g
/// </summary>
class IngameAnimationScene {
public:

	// �����\��
	int VertexShaderHandle;
	int PixelShaderHandle;

	int InGamePlayerModelH;

	int InGameBackModelH;

	/// <summary>
	/// �p�[�c�ݒ��ʂ̃��j�b�g�I�𕔕��̔w�i
	/// </summary>
	int profileUnitPartsLeftBackH;

	int unitStartMovieH;

	// �_�C�A���O�`��p�C���X�^���X
	PlayerInformationDialog playerInformationDialog = PlayerInformationDialog();

	PlayerInformationDialog unitParamDialog = PlayerInformationDialog();


	// �v���C���[���
	PlayerInformation playerInformation;

	// ���ۂɋ��Z�ɎQ������ǂԂ��{
	AnimalRobot animalRobot;

	// �S�[���֌������ẴJ�E���g�{�^��
	float dushCount;

	int ComboCount = 0;

	/// <summary>
	/// �Q�[���R���{
	/// ���莞�ԓ��Ɍ��ݎw��̃{�^����������Ƒ�����
	/// </summary>
	int comboCount = 0;

	/// <summary>
	/// �����Ɠ����{�^���������Ă���ꍇ�́A�R���{���r�؂��
	/// </summary>

	int beforeCount = 0;


	/// <summary>
	/// �{�^�����ݏ���������
	/// </summary>
	bool beforeJButton = true;
	bool beforeKButton = false;

	/// <summary>
	/// �C���Q�[�����̏����������ŃQ�[���J�n�O�ɐݒ肳���
	/// </summary>
	void Initialize() {
		// 2D�Q�[���摜����
		playerInformationDialog.backDialogGraphH = LoadGraph("ProfileDialogBackGround.png");
		unitParamDialog.backDialogGraphH = LoadGraph("ProfileUnitDialogBackGround.png");
		profileUnitPartsLeftBackH = LoadGraph("AnimalRobotlProfileLeftBackGround.png");
		// �Q�[�����̃��f���f�[�^
		InGamePlayerModelH = MV1LoadModel("InGame_Model_1.X");
		InGameBackModelH = MV1LoadModel("InGame_BackModel_1.X");
		// �J�����̐ݒ�
		ExpInfo expInfo = ExpInfo(45, 30);
		AgpInfo agpInfo= AgpInfo(30);
		AnimalRobotLiveTicketInfo ticketInfo = AnimalRobotLiveTicketInfo(500);
		std::vector<AnimalRobot> animalRobotList;
		playerInformation = PlayerInformation();
		playerInformation.SetProfile(expInfo, agpInfo, ticketInfo, animalRobotList);
		unitStartMovieH = LoadGraph("UnitStart1.GIF");
		// ���_�V�F�[�_�[��ǂݍ���
		VertexShaderHandle = LoadVertexShader("NormalMesh_NoLight_FogVS.vso");

		// �s�N�Z���V�F�[�_�[��ǂݍ���
		PixelShaderHandle = LoadPixelShader("NormalMesh_NoLight_FogPS.pso");


		dushCount = 0.0f;
		ComboCount = 0;
		beforeJButton = true;
		beforeKButton = false;

		// ���f���̕`��ɃI���W�i���V�F�[�_�[���g�p����ݒ���n�m�ɂ���
	//	MV1SetUseOrigShader(TRUE);

		// �g�p���钸�_�V�F�[�_�[���Z�b�g
		SetUseVertexShader(VertexShaderHandle);

		// �g�p����s�N�Z���V�F�[�_�[���Z�b�g
		SetUsePixelShader(PixelShaderHandle);


	}

	PlayerInformation* GetPlayerInformation() { return &this->playerInformation; };
	void Update();
	void Draw();
	int  ChangeScene();
};