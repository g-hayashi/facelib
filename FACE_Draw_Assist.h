/* -----------------------------------------
		�e�`�b�d�@�`��@�\(Main)
  --------------------------------------- */
#include "stdafx.h"
#include "FACElib.h"
#include "FACE.h"

// DirectDraw�֘A
#include <DDraw.h>
#pragma comment( lib,"DDraw.lib" )
#pragma comment( lib,"DxGuid.lib")
// �v�Z���C�u����
#include <math.h>
// SliderBar�֘A(SpriteViewer)
#include <commctrl.h>
// ���[�h��`
#define DRAWDISABLE 0
#define WINGDI 1
#define DDRAW 2
#define DDRAW_FULL 3

#define dwSpriteNum 8

#ifdef DX7
#define DIRECTDRAW IDirectDraw7
#define DIRECTDRAWSURFACE IDirectDrawSurface7
#define SURFACEDESC DDSURFACEDESC2 
#define SETDISPLAYMODE ObjDD->SetDisplayMode( 640 , 480 , 16 , 0 , 0  )
#else
#define DIRECTDRAW IDirectDraw
#define DIRECTDRAWSURFACE IDirectDrawSurface
#define SURFACEDESC DDSURFACEDESC 
#define SETDISPLAYMODE ObjDD->SetDisplayMode( 640 , 480 , 16  )
#define DDBLT_DONOTWAIT 0
#endif

// �X�v���C�g�}�N��
#define EXPAND_SIZE(x) x.cx , x.cy

// DirectDraw���������s
#define DDrawInitFailed { \
	LogPut( CONTINUE , IDS_LOG_DDRAWFAILED ); \
	LogQuit( );\
	return Graphics( 1 );\
	}
#define DrawBegin { \
	CHECK_MODE( dwDrawMode ); \
	CHECK_RANGE_STR( SpriteID , 0 , dwSpriteNum , "Draw�n���\�b�h->SpriteID" ); \
	CHECK_EMPTY_STR(  Sprites,SpriteID , "Draw�n���\�b�h->Sprite" ); \
	HDC hDC = Sprites[ SpriteID ].GetSprDC( )
#define DrawEnd \
	Sprites[ SpriteID ].EndSprDC( hDC );\
	return S_OK; }

/* -- �`����o�̓v���O�C�� -- */
typedef int (PASCAL *PROGRESSCALLBACK)
	(int nNum, int nDenom, LONG lData);
typedef int (PASCAL *GETPICTURE)
	(LPSTR buf, LONG len, unsigned int flag, HANDLE *pHBInfo, HANDLE *pHBm, PROGRESSCALLBACK lpPrgressCallback, LONG lData);
typedef int (PASCAL *ISSUPPORTED )
	(LPSTR filename, DWORD dw);
 
	class SPRITE{
	private:
		DIRECTDRAWSURFACE *DDrawSurf;
		HDC			CompatibleDC;
		HBITMAP		CompatibleBMP;
	public:
		// �S�ĉ������֐�
		SPRITE( );
		void Clear( LONG dwMode = DEFAULT );
		// �쐬
		void Make( LONG cx , LONG cy, LONG dwMode = DEFAULT );
		// ���邩�H
		BOOL IsEmpty( LONG dwMode = DEFAULT );
		// �f�o�C�X�R���e�L�X�g����Ǝ擾
		HDC		GetSprDC( );
		void	EndSprDC( HDC );
		DIRECTDRAWSURFACE* GetSurf();
		// �J���[�L�[�ݒ�
		BOOL SetColorKey( LONG Color = CLR_INVALID );
		BOOL ClrKeying( );
		// �ʃ��[�h�ڍs�A�o�b�N�A�b�v�@�\
		BOOL GDISurfToDDSurf( );
		BOOL DDSurfToGDISurf( );
			// �T�C�Y���
			SIZE		Size;
			// �J���[�L�[���
			LONG		CLRKey;
			// GDI �I�v�V�����ݒ�
			LOGFONT		FontSet;
			LONG		dwFillStyle , dwLineStyle;
	};

#define ObjectSet {\
	HBRUSH	OldBrush , FillColor ;\
	if ( Sprites[ SpriteID ].dwFillStyle == -1 ) \
		FillColor = CreateSolidBrush( Color ); \
	else \
		FillColor = CreateHatchBrush( Sprites[ SpriteID ].dwFillStyle , Color ); \
	HPEN	OldPen	, ForeColor	= CreatePen( Sprites[ SpriteID ].dwLineStyle, 0 , Color ) ; \
	OldBrush	=	(HBRUSH)SelectObject( hDC , FillColor ); \
	OldPen		=	(HPEN)SelectObject( hDC , ForeColor )
#define ObjectRelease \
	SelectObject( hDC , OldPen );\
	DeleteObject( ForeColor );\
	SelectObject( hDC , OldBrush );\
	DeleteObject( FillColor );}
	
#define TextMaskCheck(tts) \
		if ( ( ( tts ) < ( 0 ) ) || ( ( tts ) > ( 2 ) ) ) { \
			LogBegin( _T( "DrawString TextAlign" ) );\
			LogPut( FATAL , IDS_ERR_PARAM , ( tts ) );\
		} \
	if ( tts == 0 ) { \
		Opt = DT_LEFT; \
		SetRect( &RT , x , y , 0 , 0 ); \
	}else if ( tts == 1 ){ \
		Opt = DT_RIGHT; \
		SetRect( &RT , 0 , y , x , 0 ); \
	}else if ( tts == 2 ){ \
		Opt = DT_CENTER; \
		SetRect( &RT , x - Screen.cx  , y , x + Screen.cx , Screen.cy ); \
	}
		// DirectDraw
	// Are DirectX7 Libraries Avaliable?
	extern DIRECTDRAW			*ObjDD;
	extern DIRECTDRAWSURFACE	*PriSurf;
	extern IDirectDrawClipper	*lpClipper;
	extern SPRITE				Sprites[ dwSpriteNum + 1 ];
