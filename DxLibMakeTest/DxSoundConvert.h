// -------------------------------------------------------------------------------
// 
// 		�c�w���C�u����		�T�E���h�f�[�^�ϊ��v���O�����w�b�_�t�@�C��
// 
// 				Ver 3.22f
// 
// -------------------------------------------------------------------------------

#ifndef DX_SOUNDCONVERT_H
#define DX_SOUNDCONVERT_H

#include "DxCompileConfig.h"

#ifndef DX_NON_SOUND

// �C���N���[�h ------------------------------------------------------------------

#include "DxLib.h"

#ifdef WINDOWS_DESKTOP_OS
	#include "Windows/DxSoundConvertWin.h"
#endif // WINDOWS_DESKTOP_OS

#ifdef __ANDROID__
	#include "Android/DxSoundConvertAndroid.h"
#endif // __ANDROID__

#ifdef __APPLE__
    #include "TargetConditionals.h"
    #if TARGET_OS_IPHONE
		#include "iOS/DxSoundConvertiOS.h"
    #endif // TARGET_OS_IPHONE
#endif // __APPLE__




#ifndef DX_NON_NAMESPACE

namespace DxLib
{

#endif // DX_NON_NAMESPACE

// �}�N����` --------------------------------------------------------------------

// �����^�C�v
#define SOUND_METHODTYPE_NORMAL				(0)		// �ʏ�̏���(���ʂȏ����͋��܂Ȃ�)
#define SOUND_METHODTYPE_OGG				(1)		// �n�f�f���g�p
#define SOUND_METHODTYPE_OPUS				(2)		// Opus���g�p
#define SOUND_METHODTYPE_DEFAULT_NUM		(3)		// ���Ɉˑ����Ȃ������^�C�v�̐�

// �`�����N�h�c�Z�b�g�}�N��
#define RIFFCHUNKID( C1 , C2 , C3 , C4 )	( DWORD )( ((( DWORD )C4)<<24) | ((( DWORD )C3)<<16) | ((( DWORD )C2)<<8) | (C1) ) 

#ifndef WAVE_FORMAT_IEEE_FLOAT
#define WAVE_FORMAT_IEEE_FLOAT		0x0003
#endif

#ifndef WAVE_FORMAT_PCM
#define WAVE_FORMAT_PCM				0x0001
#endif

// �\���̒�` --------------------------------------------------------------------

// RIFF�`�����N�f�[�^
struct ___RIFFCHUNK
{
	DWORD						fcc ;
	DWORD						 cb ;
} ;

// �v�`�u�d�f�[�^�ϊ��p�\����
struct SOUNDCONV_WAVE
{
	BYTE						*SrcBuffer ;		// �ϊ����̃f�[�^
	ULONGLONG					SrcBufferSize ;		// �ϊ����o�b�t�@�̃f�[�^�T�C�Y
	ULONGLONG					SrcSampleNum ;		// �ϊ����o�b�t�@�̃T���v����
	LONGLONG					LoopStart, LoopEnd ;	// ���[�v���
	WAVEFORMATEX				SrcFormat ;			// �ϊ����o�b�t�@�̃t�H�[�}�b�g
} ;

// �����f�[�^�ϊ������p�\����
struct SOUNDCONV
{
	int							InitializeFlag ;		// ����������Ă���ꍇ�ɗ��t���O
	int							EndFlag ;				// �ϊ����I�������痧�t���O
	
	int 						MethodType ;			// �����^�C�v( SOUND_METHODTYPE_NORMAL �� )
	STREAMDATA 					Stream ;				// �f�[�^�ǂݍ��ݗp�X�g���[���f�[�^

	LONGLONG					HeaderPos ;				// �w�b�_�̂���ʒu
	LONGLONG					HeaderSize ;			// �w�b�_�̃T�C�Y
	LONGLONG					DataPos ;				// ���f�[�^�̂���ʒu
	LONGLONG					DataSize ;				// ���f�[�^�̃T�C�Y

	WAVEFORMATEX				OutFormat ;				// �ϊ���̃t�H�[�}�b�g

	char						ConvFunctionBuffer[ 1024 ] ;	// MethodType �ʃf�[�^�ۑ��p�o�b�t�@�̈�

	void						*DestData ;				// �ϊ���̃f�[�^���ꎞ�I�ɕۑ����郁�����̈�
	LONGLONG					DestDataSize ;			// �ϊ���̃f�[�^���ꎞ�I�ɕۑ����郁�����̈�̃T�C�Y
	LONGLONG					DestDataValidSize ;		// �ϊ���̃f�[�^�̗L���ȃT�C�Y
	LONGLONG					DestDataCompSize ;		// �ϊ���̃f�[�^���ꎞ�I�ɕۑ����郁�����̈撆�̓]���ς݂̃T�C�Y
	LONGLONG					DestDataCompSizeAll ;	// �ϊ��J�n���猻�݂Ɏ���܂łɓ]�������f�[�^�̃T�C�Y

	LONGLONG					SeekLockPosition ;		// �\��V�[�N�ʒu(�`�b�l�^�C�v�Ń��[�v����ꍇ�ׂ̈̃f�[�^)
#ifndef DX_NON_OGGVORBIS
	int							OggVorbisBitDepth ;			// �n�����u�����������g�p���̃r�b�g�[�x(1:8bit 2:16bit)
	int							OggVorbisFromTheoraFile ;	// Ogg Theora �t�@�C������ Vorbis �f�[�^���Q�Ƃ��邩�ǂ����̃t���O( TRUE:Theora �t�@�C������ Vorbis �f�[�^���Q�Ƃ��� )
#endif
} ;

// �T�E���h�ϊ������S�̂Ŏg�p����f�[�^�\����
struct SOUNDCONVERTDATA
{
	int							InitializeFlag ;				// �������t���O
} ;

// �������ϐ��錾 --------------------------------------------------------------

extern SOUNDCONVERTDATA GSoundConvertData ;

// �֐��v���g�^�C�v�錾-----------------------------------------------------------

// �������E�I���֐�
extern	int InitializeSoundConvert( void ) ;														// �T�E���h�f�[�^�ϊ������̏��������s��
extern	int TerminateSoundConvert( void ) ;															// �T�E���h�f�[�^�ϊ������̏I���������s��

// �t�H�[�}�b�g�ϊ��p
extern	int      SetupSoundConvert( SOUNDCONV *SoundConv, STREAMDATA *Stream, int DisableReadSoundFunctionMask = 0, int OggVorbisBitDepth = 2, int OggVorbisFromTheoraFile = FALSE ) ;	// �ϊ������̃Z�b�g�A�b�v( [��] -1:�G���[ )
//extern int     SetTimeSoundConvert(          SOUNDCONV *SoundConv, int Time ) ;							// �ϊ������̈ʒu��ύX����( �~���b�P�� )
extern	int      SetSampleTimeSoundConvert(    SOUNDCONV *SoundConv, LONGLONG SampleTime ) ;				// �ϊ������̈ʒu��ύX����( �T���v���P�� )
extern	int      SetupSeekPosSoundConvert(     SOUNDCONV *SoundConv, LONGLONG SeekPos ) ;					// �V�[�N�\��̈ʒu���Z�b�g���Ă���(�`�b�l�ׂ̈�)
extern	size_t   RunSoundConvert(              SOUNDCONV *SoundConv, void *DestBuffer, size_t DestSize ) ;	// �w��̃T�C�Y��������������( [��] -1:�G���[  0�ȏ�:�ϊ������T�C�Y )
extern	int      TerminateSoundConvert(        SOUNDCONV *SoundConv ) ;										// �ϊ������̌�n�����s��
extern	int      GetOutSoundFormatInfo(        SOUNDCONV *SoundConv, WAVEFORMATEX *OutWaveFormat ) ;		// �ϊ���̉����`�����擾( [��] -1:�G���[  0�ȏ�:�ϊ���̃T�C�Y )
extern	int      GetSoundConvertLoopAreaInfo(  SOUNDCONV *SoundConv, LONGLONG *LoopStartPos, LONGLONG *LoopEndPos ) ;	// ���[�v�����擾( [��] -1:�G���[ )
extern	int      GetSoundConvertEndState(      SOUNDCONV *SoundConv ) ;										// �ϊ��������I�����Ă��邩�ǂ������擾����( [��] TRUE:�I������  FALSE:�܂��I�����Ă��Ȃ� )
extern	LONGLONG GetSoundConvertDestSize_Fast( SOUNDCONV *SoundConv ) ;										// �ϊ���̑�}�̃f�[�^�T�C�Y�𓾂�
extern	int      SoundConvertFast(             SOUNDCONV *SoundConv, WAVEFORMATEX *FormatP, void **DestBufferP, size_t *DestSizeP ) ;	// �����Ȉꊇ�ϊ�


// ���ˑ��������E�I���֐�
extern	int      InitializeSoundConvert_PF( void ) ;														// �T�E���h�f�[�^�ϊ������̊��ˑ��̏��������s��
extern	int      TerminateSoundConvert_PF( void ) ;															// �T�E���h�f�[�^�ϊ������̊��ˑ��̏I���������s��

extern	int      SetupSoundConvert_PF( SOUNDCONV *SoundConv, STREAMDATA *Stream, int DisableReadSoundFunctionMask ) ;	// (���ˑ�����)�ϊ������̃Z�b�g�A�b�v( [��] -1:�G���[ )
extern	int      SetSampleTimeSoundConvert_PF(    SOUNDCONV *SoundConv, LONGLONG SampleTime ) ;				// (���ˑ�����)�ϊ������̈ʒu��ύX����( �T���v���P�� )
extern	int      ConvertProcessSoundConvert_PF(   SOUNDCONV *SoundConv ) ;									// (���ˑ�����)�ϊ���̃o�b�t�@�Ƀf�[�^���[����
extern	int      TerminateSoundConvert_PF(        SOUNDCONV *SoundConv ) ;									// (���ˑ�����)�ϊ������̌�n�����s��
extern	LONGLONG GetSoundConvertDestSize_Fast_PF( SOUNDCONV *SoundConv ) ;									// (���ˑ�����)�ϊ���̑�}�̃f�[�^�T�C�Y�𓾂�

#ifndef DX_NON_NAMESPACE

}

#endif // DX_NON_NAMESPACE

#endif // DX_NON_SOUND

#endif // DX_SOUNDCONVERT_H