/* -----------------------------------------
		ＦＡＣＥ　描画機能(Main)
  --------------------------------------- */
#include "stdafx.h"
#include "FACElib.h"
#include "FACE.h"

// DirectDraw関連
#include <DDraw.h>
#pragma comment( lib,"DDraw.lib" )
#pragma comment( lib,"DxGuid.lib")
// 計算ライブラリ
#include <math.h>
// SliderBar関連(SpriteViewer)
#include <commctrl.h>
// モード定義
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

// スプライトマクロ
#define EXPAND_SIZE(x) x.cx , x.cy

// DirectDraw初期化失敗
#define DDrawInitFailed { \
	LogPut( CONTINUE , IDS_LOG_DDRAWFAILED ); \
	LogQuit( );\
	return Graphics( 1 );\
	}
#define DrawBegin { \
	CHECK_MODE( dwDrawMode ); \
	CHECK_RANGE_STR( SpriteID , 0 , dwSpriteNum , "Draw系メソッド->SpriteID" ); \
	CHECK_EMPTY_STR(  Sprites,SpriteID , "Draw系メソッド->Sprite" ); \
	HDC hDC = Sprites[ SpriteID ].GetSprDC( )
#define DrawEnd \
	Sprites[ SpriteID ].EndSprDC( hDC );\
	return S_OK; }

/* -- 描画入出力プラグイン -- */
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
		// 全て解放する関数
		SPRITE( );
		void Clear( LONG dwMode = DEFAULT );
		// 作成
		void Make( LONG cx , LONG cy, LONG dwMode = DEFAULT );
		// あるか？
		BOOL IsEmpty( LONG dwMode = DEFAULT );
		// デバイスコンテキスト解放と取得
		HDC		GetSprDC( );
		void	EndSprDC( HDC );
		DIRECTDRAWSURFACE* GetSurf();
		// カラーキー設定
		BOOL SetColorKey( LONG Color = CLR_INVALID );
		BOOL ClrKeying( );
		// 別モード移行、バックアップ機能
		BOOL GDISurfToDDSurf( );
		BOOL DDSurfToGDISurf( );
			// サイズ情報
			SIZE		Size;
			// カラーキー情報
			LONG		CLRKey;
			// GDI オプション設定
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
