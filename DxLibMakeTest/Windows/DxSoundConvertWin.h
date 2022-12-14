// -------------------------------------------------------------------------------
// 
// 		cwCu		WindowsOSpTEhf[^Ο·vOwb_t@C
// 
// 				Ver 3.22f
// 
// -------------------------------------------------------------------------------

#ifndef DX_SOUNDCONVERTWIN_H
#define DX_SOUNDCONVERTWIN_H

#include "../DxCompileConfig.h"

// CN[h ------------------------------------------------------------------
#include "../DxLib.h"
#include "../DxThread.h"

#include "DxUseCStrmBaseFilter.h"

#ifndef DX_NON_ACM
	#if defined( DX_GCC_COMPILE ) || defined( DX_GCC_COMPILE_4_9_2 ) || defined( DX_GCC_COMPILE_5_3_0 )
		#include <mmreg.h>
	#endif // defined( DX_GCC_COMPILE ) || defined( DX_GCC_COMPILE_4_9_2 ) || defined( DX_GCC_COMPILE_5_3_0 )
	#include <msacm.h>
#endif // DX_NON_ACM

#ifndef DX_NON_NAMESPACE

namespace DxLib
{

#endif // DX_NON_NAMESPACE

// }Nθ` --------------------------------------------------------------------

#define SOUND_METHODTYPE_ACM				(SOUND_METHODTYPE_DEFAULT_NUM + 0)		// `blπgp
#define SOUND_METHODTYPE_DSMP3				(SOUND_METHODTYPE_DEFAULT_NUM + 1)		// crπgp΅½loRΔΆ
#define SOUND_METHODTYPE_MF					(SOUND_METHODTYPE_DEFAULT_NUM + 2)		// l@eπgp

// \’Μθ` --------------------------------------------------------------------

#ifndef DX_NON_ACM

// #ifdef DX_GCC_COMPILE
struct D_HACMSTREAM__
{
	int unused ;
} ;

typedef struct D_HACMSTREAM__ *D_HACMSTREAM ;
typedef        D_HACMSTREAM   *D_LPHACMSTREAM ;

struct D_HACMOBJ__
{
	int unused ;
} ;
typedef struct D_HACMOBJ__     *D_HACMOBJ ;

typedef struct D_wavefilter_tag
{
	DWORD   cbStruct;           /* Size of the filter in bytes */
	DWORD   dwFilterTag;        /* filter type */
	DWORD   fdwFilter;          /* Flags for the filter (Universal Dfns) */
	DWORD   dwReserved[5];      /* Reserved for system use */
} D_WAVEFILTER;
typedef D_WAVEFILTER FAR  *D_LPWAVEFILTER;

#define D_MPEGLAYER3_WFX_EXTRA_BYTES			12
#define D_WAVE_FORMAT_MPEGLAYER3				0x0055 /* ISO/MPEG Layer3 Format Tag */

#define D_MPEGLAYER3_ID_UNKNOWN					0
#define D_MPEGLAYER3_ID_MPEG					1
#define D_MPEGLAYER3_ID_CONSTANTFRAMESIZE		2

typedef struct D_mpeglayer3waveformat_tag
{
	WAVEFORMATEX  wfx;
	WORD          wID;
	DWORD         fdwFlags;
	WORD          nBlockSize;
	WORD          nFramesPerBlock;
	WORD          nCodecDelay;
} D_MPEGLAYER3WAVEFORMAT ;

#define D_ACM_STREAMSIZEF_SOURCE				0x00000000L
#define D_ACM_STREAMSIZEF_DESTINATION			0x00000001L
#define D_ACM_STREAMSIZEF_QUERYMASK				0x0000000FL

#define D_ACM_METRIC_MAX_SIZE_FORMAT			50

#define D_ACM_STREAMCONVERTF_BLOCKALIGN			0x00000004
#define D_ACM_STREAMCONVERTF_START				0x00000010
#define D_ACM_STREAMCONVERTF_END				0x00000020

#ifdef  _WIN64
#define D__DRVRESERVED    15
#else
#define D__DRVRESERVED    10
#endif  // _WIN64

typedef struct D_tACMSTREAMHEADER
{
    DWORD           cbStruct;               // sizeof(D_ACMSTREAMHEADER)
    DWORD           fdwStatus;              // ACMSTREAMHEADER_STATUSF_*
    DWORD_PTR       dwUser;                 // user instance data for hdr
    LPBYTE          pbSrc;
    DWORD           cbSrcLength;
    DWORD           cbSrcLengthUsed;
    DWORD_PTR       dwSrcUser;              // user instance data for src
    LPBYTE          pbDst;
    DWORD           cbDstLength;
    DWORD           cbDstLengthUsed;
    DWORD_PTR       dwDstUser;              // user instance data for dst
    DWORD           dwReservedDriver[D__DRVRESERVED];   // driver reserved work space

} D_ACMSTREAMHEADER, *D_PACMSTREAMHEADER, FAR *D_LPACMSTREAMHEADER;
// #endif

// `blf[^Ο·p\’Μ
struct SOUNDCONV_ACM
{
	WAVEFORMATEX				*Format ;				// Ο·³ΜtH[}bg
	D_HACMSTREAM				AcmStreamHandle[2]	;	// ³k³κ½f[^π΅€ΫΙg€`blΜnh

	void						*SrcData ;				// Ο·³Μf[^πκIΙΫΆ΅Δ¨­Μζ
	int							SrcDataSize ;			// Ο·³Μf[^πκIΙΫΆ΅Δ¨­ΜζΜTCY
//	int							SrcDataValidSize ;		// Ο·³Μf[^ΜLψΘTCY
	LONGLONG					SrcDataPosition ;		// Ο·³Μf[^ΜΟ·ͺ?Ή΅½TCY
	LONGLONG					DestDataSampleNum ;		// Ο·γΜf[^ΜTv( -1:ΘOΜκΜέLψ )

	LONGLONG					BeginSeekCompSrcSize ;	// V[N\θΚuάΕTuACMnhΕΟ·΅Δ¨­ΕAωΙΟ·ͺ?Ή΅Δ’ι³kf[^ΜTCY
	LONGLONG					BeginSeekPosition ;		// V[N\θΚuάΕTuACMnhΕΟ·΅Δ¨­ΕAωΙΟ·ͺ?Ή΅Δ’ιWJγf[^ΜTCY(V[N\θΚuΝ SOUNDCONV ΦΜ SeekLockPosition o[)
	void						*BeginSeekBuffer ;		// V[N\θΚuάΕTuACMnhΕΟ·΅Δ¨­Εgp·ιobt@
} ;

#endif // DX_NON_ACM

#ifndef DX_NON_MOVIE
#ifndef DX_NON_DSHOW_MOVIE

// crπgΑ½loRf[^Ο·Εgp·ιobt@NX
class SOUNDCONV_DSMP3_BUF : public D_ISampleGrabberCB
{
public :
	struct SOUNDCONV			*SoundConvData ;		// ΉΊf[^Ο·p\’ΜΦΜ|C^

	ULONG __stdcall				AddRef() ;
	ULONG __stdcall				Release() ;

	HRESULT __stdcall			QueryInterface( REFIID riid, void ** ppv ) ;
	HRESULT __stdcall			SampleCB( double SampleTime, D_IMediaSample *pSample ) ;
	HRESULT __stdcall			BufferCB( double SampleTime, BYTE *pBuffer, long BufferLen ) ;
} ;

// crπgΑ½loRf[^Ο·p\’Μ
struct SOUNDCONV_DSMP3
{
	void						*PCMBuffer ;			// oblΙΟ·³κ½f[^πi[·ιΜζ
	DWORD						PCMBufferSize ;			// oblobt@ΜTCY
	DWORD						PCMValidDataSize ;		// LψΘoblΜTCY
	DWORD						PCMDestCopySize ;		// {obt@ΦΜRs[ͺ?Ή΅½TCY
} ;

#endif  // DX_NON_DSHOW_MOVIE
#endif	// DX_NON_MOVIE

// TEhΟ·SΜΕgp·ιf[^\’ΜΕ Windows ΙΛΆ΅Δ’ιξρΜ\’Μ
struct SOUNDCONVERTDATA_WIN
{
	int							Dummy ;
#ifndef DX_NON_ACM
	HMODULE						msacm32DLL ;					// msacm32DLL
	MMRESULT					( WINAPI *acmStreamOpenFunc            )( D_LPHACMSTREAM phas, HACMDRIVER had, LPWAVEFORMATEX pwfxSrc, LPWAVEFORMATEX pwfxDst, D_LPWAVEFILTER pwfltr, DWORD dwCallback, DWORD dwInstance, DWORD fdwOpen );
	MMRESULT					( WINAPI *acmFormatSuggestFunc         )( HACMDRIVER had, LPWAVEFORMATEX pwfxSrc, LPWAVEFORMATEX pwfxDst, DWORD cbwfxDst, DWORD fdwSuggest );
	MMRESULT					( WINAPI *acmStreamCloseFunc           )( D_HACMSTREAM has, DWORD fdwClose );
	MMRESULT					( WINAPI *acmMetricsFunc               )( D_HACMOBJ hao, UINT uMetric, LPVOID pMetric );
	MMRESULT					( WINAPI *acmStreamPrepareHeaderFunc   )( D_HACMSTREAM has, D_LPACMSTREAMHEADER pash, DWORD fdwPrepare );
	MMRESULT					( WINAPI *acmStreamConvertFunc         )( D_HACMSTREAM has, D_LPACMSTREAMHEADER pash, DWORD fdwConvert );
	MMRESULT					( WINAPI *acmStreamUnprepareHeaderFunc )( D_HACMSTREAM has, D_LPACMSTREAMHEADER pash, DWORD fdwUnprepare );
	MMRESULT					( WINAPI *acmStreamSizeFunc            )( D_HACMSTREAM has, DWORD cbInput, LPDWORD pdwOutputBytes, DWORD fdwSize );
#endif
} ;

// ΰεζΟιΎ --------------------------------------------------------------

// Φvg^CvιΎ-----------------------------------------------------------

#ifndef DX_NON_ACM
extern	int      SetupSoundConvert_ACM(            struct SOUNDCONV *SoundConv ) ;								// `blπgp΅½t@CΜZbgAbvπs€( [ί] -1:G[ )
extern	int      SetupSoundConvert_MP3(            struct SOUNDCONV *SoundConv ) ;								// loRt@CΜZbgAbvπs€( [ί] -1:G[ )
extern	int      TerminateSoundConvert_ACM(        struct SOUNDCONV *SoundConv ) ;								// `blπgp΅½t@CΜγnπs€
extern	int      ConvertProcessSoundConvert_ACM(   struct SOUNDCONV *SoundConv ) ;								// Ο·γΜobt@Ιf[^πβ[·ι
//extern int     SetTimeSoundConvert_ACM(          struct SOUNDCONV *SoundConv, int Time ) ;					// Ο·πΚuπΟX·ι( ~bPΚ )
extern	int      SetSampleTimeSoundConvert_ACM(    struct SOUNDCONV *SoundConv, LONGLONG SampleTime ) ;			// Ο·ΜΚuπΟX·ι( TvPΚ )
extern	LONGLONG GetSoundConvertDestSize_Fast_ACM( struct SOUNDCONV *SoundConv ) ;								// Ο·γΜε}Μf[^TCYπΎι
#endif

#ifndef DX_NON_MOVIE
#ifndef DX_NON_DSHOW_MOVIE
#ifndef DX_NON_DSHOW_MP3
extern	int      TerminateSoundConvert_DSMP3(        struct SOUNDCONV *SoundConv ) ;							// MP3πgp΅½t@CΜγnπs€
extern	int      ConvertProcessSoundConvert_DSMP3(   struct SOUNDCONV *SoundConv ) ;							// Ο·γΜobt@Ιf[^πβ[·ι
//extern int     SetTimeSoundConvert_DSMP3(          struct SOUNDCONV *SoundConv, int Time ) ;					// Ο·πΚuπΟX·ι( ~bPΚ )
extern	int      SetSampleTimeSoundConvert_DSMP3(    struct SOUNDCONV *SoundConv, LONGLONG SampleTime ) ;		// Ο·ΜΚuπΟX·ι( TvPΚ )
extern	LONGLONG GetSoundConvertDestSize_Fast_DSMP3( struct SOUNDCONV *SoundConv ) ;							// Ο·γΜε}Μf[^TCYπΎι
#endif
#endif
#endif

#ifndef DX_NON_MEDIA_FOUNDATION
extern	int      SetupSoundConvert_MF(            SOUNDCONV *SoundConv ) ;										// Media Foundation πgp΅½t@CΜZbgAbvπs€( [ί] -1:G[ )
extern	int      TerminateSoundConvert_MF(        SOUNDCONV *SoundConv ) ;										// Media Foundation πgp΅½t@CΜγnπs€
extern	int      ConvertProcessSoundConvert_MF(   SOUNDCONV *SoundConv ) ;										// Ο·γΜobt@Ιf[^πβ[·ι
//extern int     SetTimeSoundConvert_MF(          SOUNDCONV *SoundConv, int Time ) ;							// Ο·πΚuπΟX·ι( ~bPΚ )
extern	int      SetSampleTimeSoundConvert_MF(    SOUNDCONV *SoundConv, LONGLONG SampleTime ) ;					// Ο·ΜΚuπΟX·ι( TvPΚ )
extern	LONGLONG GetSoundConvertDestSize_Fast_MF( SOUNDCONV *SoundConv ) ;										// Ο·γΜε}Μf[^TCYπΎι
#endif // DX_NON_MEDIA_FOUNDATION

#ifndef DX_NON_NAMESPACE

}

#endif // DX_NON_NAMESPACE

#endif // DX_SOUNDCONVERTWIN_H
