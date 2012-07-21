#include "FACE_Draw_Assist.h"

/* コンストラクタ */
SPRITE::SPRITE( ){
	// 変数初期化
	FillsNil( Size );
	FillsNil( FontSet );
		// 初期情報
		FontSet.lfCharSet= 128; FontSet .lfHeight = 18;
		lstrcpy( FontSet.lfFaceName , _T( "ＭＳ Ｐゴシック" ) );
	DDrawSurf		=	NULL;
	CompatibleDC	=	NULL;
	CompatibleBMP	=	NULL;
	CLRKey			=	CLR_INVALID;
	dwFillStyle		=	-1 ;
	dwLineStyle		=	PS_SOLID;
}
/* -----------------
	スプライトの作成
	---------------*/
void SPRITE::Make( LONG cx, LONG cy , LONG dwMode ){ 
	if ( !IsEmpty( dwMode ) ) return;
	if ( dwMode == DEFAULT ) dwMode = dwDrawMode;

	lpFACE->LogBegin( _T( "SpriteMake" ) );
	lpFACE->LogPut( CONTINUE , IDS_LOG_CREATE , this - &Sprites[ 0 ] );
	if ( dwMode == WINGDI ){
		// 互換性のあるＤＣとＢＭＰを作成 
		CompatibleDC	= CreateCompatibleDC( NULL );
		CompatibleBMP	= CreateCompatibleBitmap( CompatibleDC , cx , cy * 2 ); 
		// 関連づけを行う
		SelectObject( CompatibleDC , CompatibleBMP );
	}else if ( dwMode == DDRAW ){
		// サーフェス情報格納構造体
		DXObjInit( SURFACEDESC ddsd , ddsd );
		ddsd.dwFlags = DDSD_CAPS  | DDSD_WIDTH | DDSD_HEIGHT;
		ddsd.dwWidth	= cx;
		ddsd.dwHeight	= cy;
		ddsd.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN | DDSCAPS_SYSTEMMEMORY ;
		
		ObjDD->CreateSurface( &ddsd , &DDrawSurf , NULL );
	}
	lpFACE->LogPut( CONTINUE , IDS_LOG_SURFACEDESC , cx , cy  );
	// 変数セット
	CLRKey = CLR_INVALID;
	Size.cx = cx ; Size.cy = cy;
	lpFACE->LogQuit( );
}
/* -----------------
	スプライトの削除
	---------------*/
void SPRITE::Clear( LONG dwMode ){ 
	if ( IsEmpty( dwMode ) ) return;
	if ( dwMode == DEFAULT ) dwMode = dwDrawMode;
	
	if ( dwMode == WINGDI ){
		// GDIモード
		DeleteObject( CompatibleBMP );	CompatibleBMP = NULL;
		DeleteDC( CompatibleDC );		CompatibleDC = NULL;
	}else if ( dwMode == DDRAW ){
		// DirectDraw モード
		SAFE_RELEASE( DDrawSurf );
	}
	lpFACE->LogBegin( _T( "SpriteClear" ) );
	lpFACE->LogPut( CONTINUE , IDS_LOG_CREATE , this - &Sprites[ 0 ] );
	lpFACE->LogQuit( );
}
// 空っぽか取得
BOOL SPRITE::IsEmpty( LONG dwMode ) {
	if ( dwMode == DEFAULT ) dwMode = dwDrawMode;
	
	return ( ( dwMode == WINGDI ? !CompatibleDC : !DDrawSurf ) );
}
// デバイスコンテキスト取得
HDC SPRITE::GetSprDC( ){
	HDC hDC;
	if ( CompatibleDC )
		// GDI モード
		hDC = CompatibleDC;
	else if ( DDrawSurf )
		// DirectDraw モード
		DDrawSurf->GetDC( &hDC );
	return hDC;
}
// デバイスコンテキスト開放
void SPRITE::EndSprDC( HDC hDC ){
	if ( DDrawSurf ) DDrawSurf->ReleaseDC( hDC );
}
DIRECTDRAWSURFACE * SPRITE::GetSurf(){return DDrawSurf;}
/* -- DirectDrawSurfaceからHDCへコピー -- */
BOOL SPRITE::DDSurfToGDISurf( ){
	// DirectDrawサーフェスが無ければリターン
	if ( IsEmpty( DDRAW ) ) return FALSE;

	/* 互換性のある空のサーフェスをWINGDIで作成 */
	Make( Size.cx , Size.cy , WINGDI );
	
	// そっくりそのままコピーする
	HDC hDC;
	DDrawSurf->GetDC( &hDC );
	BitBlt( CompatibleDC , 0 , 0 , Size.cx, Size.cy , hDC , 0 , 0 , SRCCOPY );
	DDrawSurf->ReleaseDC( hDC );

	// DirectDrawサーフェス開放
	Clear( DDRAW );

	return TRUE;
}
/* -- GDIのコンパチブルＤＣからDirectDrawサーフェスを作成する -- */
BOOL SPRITE::GDISurfToDDSurf( ){
	if ( IsEmpty( WINGDI ) ) return FALSE;
	
	// 復元の必要がある
	Make( Size.cx , Size.cy  , DDRAW );

	// そっくりそのままコピーする
	HDC hDC;
	DDrawSurf->GetDC( &hDC );
	BitBlt( hDC , 0 , 0 , Size.cx , Size.cy  , CompatibleDC , 0 , 0 ,SRCCOPY );
	DDrawSurf->ReleaseDC( hDC );

	// WINGDIを開放
	Clear( WINGDI );
	// カラーキー適応
	SetColorKey( CLRKey );
	
	return TRUE;
}
BOOL SPRITE::SetColorKey( LONG Colors ){
	if ( Colors == CLR_INVALID )return TRUE;

	// マスクを不可視領域に作成
	// DirectDrawは、カラーキーセッティング
	if ( CompatibleDC ){
		for ( int j = 0 ; j < Size.cy ; j++ ){
			for ( int i = 0 ; i < Size.cx ; i++ ){
				LONG src = GetPixel( CompatibleDC , i , j );

				// 画面上半分は元画像（カラーキーにしたい色は黒へ、それ以外はcontinue)
				if ( src == Colors )
					SetPixelV( CompatibleDC , i , j , 0x0 );
				// 画面下半分はマスク分の画像
				SetPixelV( CompatibleDC , i , Size.cy + j , 
					( src == Colors ? 0xFFFFFF : 0x0 ) );
			}
		}
	}else if ( DDrawSurf ){
		HDC hDC ;SURFACEDESC ddsd; COLORREF PrevClr ; DWORD PhysicalClr;
		
		// GDIで、まずは点を打つ
		DDrawSurf->GetDC( &hDC );
		PrevClr = GetPixel( hDC , 0 , 0 );
		SetPixelV( hDC , 0 , 0 , Colors );
		DDrawSurf->ReleaseDC( hDC );

		// Lockを行い、直接アクセス。物理色の取得
		ZeroMemory( &ddsd , sizeof(ddsd) );ddsd.dwSize = sizeof( ddsd );
		while ( DDrawSurf->Lock( NULL, &ddsd, 0, NULL)  == DDERR_WASSTILLDRAWING );
		PhysicalClr = *( DWORD * )ddsd.lpSurface;	// 取得
		// Mask
		if ( ddsd.ddpfPixelFormat.dwRGBBitCount < 32 ) 
			PhysicalClr &= (1 << ddsd.ddpfPixelFormat.dwRGBBitCount) - 1;
		DDrawSurf->Unlock( NULL );

		// 元の色をリストア
		DDrawSurf->GetDC( &hDC );
		SetPixelV( hDC , 0 , 0 , PrevClr );
		DDrawSurf->ReleaseDC ( hDC );

		DDCOLORKEY ddck = { PhysicalClr , PhysicalClr };

		DDrawSurf->SetColorKey( DDCKEY_SRCBLT , &ddck );
	}
	CLRKey = Colors;

	return TRUE;
}
BOOL SPRITE::ClrKeying( ){
	return CLRKey != CLR_INVALID;
}
