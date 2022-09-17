// -------------------------------------------------------------------------------
// 
// 		�c�w���C�u����		�W���b���C�u�����g�p�v���O�����w�b�_�t�@�C��
// 
// 				Ver 3.22f
// 
// -------------------------------------------------------------------------------

#ifndef DX_USECLIB_H
#define DX_USECLIB_H

// �C���N���[�h ------------------------------------------------------------------
#include "DxCompileConfig.h"

#ifndef DX_NON_OGGTHEORA
#include "DxMovie.h"
#endif

#if !defined( DX_NON_OPUS ) || !defined( DX_NON_OGGVORBIS ) || !defined( DX_NON_MOVIE )
#include "DxSoundConvert.h"
#endif

#include "DxFile.h"
#include "DxBaseFunc.h"

//namespace DxLib
//{

// �}�N����` --------------------------------------------------------------------

// �\���̒�` --------------------------------------------------------------------

#ifndef DX_NON_MERSENNE_TWISTER

#define MT_N 624

typedef struct tagMERSENNE_TWISTER_DATA
{
	int mti ;                       /* index number */
	unsigned int mt[ MT_N + 1 ] ;   /* the array for the state vector */
	unsigned int mtr[ MT_N ] ;      /* the array for the random number */
} MERSENNE_TWISTER_DATA ;

#endif // DX_NON_MERSENNE_TWISTER

// �e�[�u��-----------------------------------------------------------------------

// �������ϐ��錾 --------------------------------------------------------------

// �֐��v���g�^�C�v�錾-----------------------------------------------------------










#ifndef DX_NON_MERSENNE_TWISTER

// Copyright SYN--------------------------------------
extern unsigned int		CheckMMX(void) ;
extern void				srandMT(unsigned int seed) ;
extern void				generateMT(void) ;
extern unsigned int		randMT(void) ;
// ---------------------------------------------------

extern void				initMTData( MERSENNE_TWISTER_DATA *MTData, unsigned int seed ) ;
extern unsigned int		randMTData( MERSENNE_TWISTER_DATA *MTData ) ;

#endif // DX_NON_MERSENNE_TWISTER






#ifndef DX_NON_TIFFREAD
extern	int		LoadTiffImage( STREAMDATA *Src, BASEIMAGE *BaseImage, int GetFormatOnly ) ;						// �s�h�e�e�摜�̓ǂ݂���
#endif
#ifndef DX_NON_PNGREAD
extern	int		LoadPngImage(     STREAMDATA *Src, BASEIMAGE *BaseImage, int GetFormatOnly ) ;					// �o�m�f�摜�̓ǂ݂���
#ifndef DX_NON_SAVEFUNCTION
extern	int		SaveBaseImageToPngBase( const char *FilePathW, const char *FilePathA, BASEIMAGE *BaseImage, int CompressionLevel ) ;																					// ��{�摜�f�[�^���o�m�f�摜�Ƃ��ĕۑ�����
#endif
#endif
#ifndef DX_NON_JPEGREAD
extern	int		LoadJpegImageBase( STREAMDATA *Src, BASEIMAGE *BaseImage, int GetFormatOnly, int GetExifOnly, void *ExifBuffer, size_t ExifBufferSize ) ;	// �i�o�d�f�摜�̓ǂ݂��� (���̂� DxUseCLib.cpp �̒�)
extern	int		LoadJpegImage( STREAMDATA *Src, BASEIMAGE *BaseImage, int GetFormatOnly ) ;						// �i�o�d�f�摜�̓ǂ݂��� (���̂� DxUseCLib.cpp �̒�)
#ifndef DX_NON_SAVEFUNCTION
extern	int		SaveBaseImageToJpegBase( const char *FilePathW, const char *FilePathA, BASEIMAGE *BaseImage, int Quality, int Sample2x1 ) ;																			// ��{�摜�f�[�^���i�o�d�f�摜�Ƃ��ĕۑ�����
#endif
#endif




extern	int			INT64DIV(  const BYTE *Int64,  int   DivNum ) ;
extern	DWORD		UINT64DIV( const BYTE *UInt64, DWORD DivNum ) ;
extern	int			INT64MOD(  const BYTE *Int64,  int   ModNum ) ;
extern	DWORD		UINT64MOD( const BYTE *UInt64, DWORD ModNum ) ;





extern	int			MQOZ_ZIP_uncompress( void *dest, size_t destLen, const void *source, size_t sourceLen ) ;		// MQOZ�`������ ZIP ���k���ꂽ�f�[�^���𓀂���





#ifndef DX_NON_MOVIE
#ifndef DX_NON_DSHOW_MOVIE
#ifndef DX_NON_DSHOW_MP3
extern	int SetupSoundConvert_DSMP3(            SOUNDCONV *SoundConv ) ;							// DirectShow���g����MP3�t�@�C�����R���o�[�g����Z�b�g�A�b�v�������s��( [��] -1:�G���[ )
#endif
#endif
#endif




#ifndef DX_NON_OGGVORBIS
extern	int      SetupSoundConvert_OGG(            SOUNDCONV *SoundConv ) ;								// �n�f�f�t�@�C���̃Z�b�g�A�b�v�������s��( [��] -1:�G���[ )
extern	int      TerminateSoundConvert_OGG(        SOUNDCONV *SoundConv ) ;								// �n�f�f�t�@�C���̌�n���������s��
extern	int      ConvertProcessSoundConvert_OGG(   SOUNDCONV *SoundConv ) ;								// �ϊ���̃o�b�t�@�Ƀf�[�^���[����
//extern int     SetTimeSoundConvert_OGG(          SOUNDCONV *SoundConv, int Time ) ;					// �ϊ��������ʒu��ύX����( �~���b�P�� )
extern	int      SetSampleTimeSoundConvert_OGG(    SOUNDCONV *SoundConv, LONGLONG SampleTime ) ;		// �ϊ������̈ʒu��ύX����( �T���v���P�� )
extern	LONGLONG GetSoundConvertDestSize_Fast_OGG( SOUNDCONV *SoundConv ) ;								// �ϊ���̑�}�̃f�[�^�T�C�Y�𓾂�
extern	int      GetSoundConvertLoopAreaInfo_OGG(  SOUNDCONV *SoundConv, LONGLONG *LoopStartPos, LONGLONG *LoopEndPos ) ;	// ���[�v�����擾( [��] -1:�G���[ )
#endif






#ifndef DX_NON_OPUS
extern	int      SetupSoundConvert_OPUS(            SOUNDCONV *SoundConv ) ;							// Opus�t�@�C���̃Z�b�g�A�b�v�������s��( [��] -1:�G���[ )
extern	int      TerminateSoundConvert_OPUS(        SOUNDCONV *SoundConv ) ;							// Opus�t�@�C���̌�n���������s��
extern	int      ConvertProcessSoundConvert_OPUS(   SOUNDCONV *SoundConv ) ;							// �ϊ���̃o�b�t�@�Ƀf�[�^���[����
extern	int      SetSampleTimeSoundConvert_OPUS(    SOUNDCONV *SoundConv, LONGLONG SampleTime ) ;		// �ϊ������̈ʒu��ύX����( �T���v���P�� )
extern	LONGLONG GetSoundConvertDestSize_Fast_OPUS( SOUNDCONV *SoundConv ) ;							// �ϊ���̑�}�̃f�[�^�T�C�Y�𓾂�
#endif






#ifndef DX_NON_OGGTHEORA

extern int	TheoraDecode_GrobalInitialize( void ) ;																					// �\�t�g�I�Ɉ�x�����ĂԂׂ��������֐�

// Ogg Theora �ǂݍ��ݏ����̏������s��( �߂�l  0:���s  1�ȏ�:���������� )
extern DWORD_PTR  TheoraDecode_InitializeStream(
	STREAMDATASHRED *	StreamShred,
	DWORD_PTR			StreamData,
	int					StockFrameNum /* = 10 */,
	int					NotUseYUVFormatSurface /* = FALSE */,
	int					NotUseYUVGrHandle /* = TRUE */,
	int					ASyncTrhead /* = FALSE */
) ;
extern int	TheoraDecode_Terminate( DWORD_PTR Handle ) ;																			// Ogg Theora �ǂݍ��ݏ����̌�n�����s��
extern int	TheoraDecode_SurfaceTerminate( DWORD_PTR Handle ) ;																		// Ogg Theora �Ŏg�p���Ă���T�[�t�F�X���������

extern int	TheoraDecode_GetInfo( DWORD_PTR Handle, THEORADECODE_INFO *Info ) ;														// ����̏����擾����
extern int	TheoraDecode_GetCurrentFrame( DWORD_PTR Handle ) ;																		// �J�����g�t���[�����擾����
	
extern int	TheoraDecode_IncToFrame( DWORD_PTR Handle, int AddNum = 1 ) ;															// �J�����g�t���[�����P�t���[�����i�߂�( �߂�l  0:�L�[�t���[������Ȃ�����  1:�L�[�t���[��  -1:�G���[ )
extern int	TheoraDecode_SeekToFrame( DWORD_PTR Handle, int Frame ) ;																// �J�����g�t���[�����w��̃t���[���Ɉړ�����
extern int	TheoraDecode_SeekToTime( DWORD_PTR Handle, LONGLONG Time ) ;															// �J�����g�t���[�����w��̍Đ����ԂɈړ�����( �P�ʂ̓}�C�N���b )

extern int	TheoraDecode_SetupImage( DWORD_PTR Handle, int BaseImage = 0, int YUVGrHandle = 0, int YUVImage = 0, int ASyncThread = FALSE ) ;				// �J�����g�t���[����RGB�摜���쐬����( �߂�l  1:�쐬���ꂽ  0:����Ȃ����� )
extern const BASEIMAGE *	TheoraDecode_GetBaseImage( DWORD_PTR Handle ) ;															// �ꎞ�o�b�t�@�̃A�h���X���擾����
extern const void *			TheoraDecode_GetYUVImage( DWORD_PTR Handle ) ;															// �ꎞ�o�b�t�@�� YUV �t�H�[�}�b�g�̃T�[�t�F�X�𓾂�
extern int	TheoraDecode_GetYGrHandle( DWORD_PTR Handle ) ;																			// YUV�J���[�� Y�����̃O���t�B�b�N�n���h�����擾����
extern int	TheoraDecode_GetUVGrHandle( DWORD_PTR Handle ) ;																		// YUV�J���[�� UV�����̃O���t�B�b�N�n���h�����擾����

extern int	TheoraDecode_IsIdle( DWORD_PTR Handle ) ;																				// �f�R�[�h�X���b�h���A�C�h����Ԃ��ǂ����𒲂ׂ�( �߂�l  1:�A�C�h�����  0:�ғ��� )

#endif






//}

#endif // DX_USECLIB_H