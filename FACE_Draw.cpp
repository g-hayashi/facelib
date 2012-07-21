/* -----------------------------------------
		ＦＡＣＥ　描画機能(Main)
  --------------------------------------- */
#include "FACE_Draw_Assist.h"

	DIRECTDRAW				*ObjDD;
	DIRECTDRAWSURFACE		*PriSurf;
	IDirectDrawClipper		*lpClipper;
	SPRITE					Sprites[ dwSpriteNum + 1 ];
	SIZE					Screen;
	LONG					dwDrawMode;
static LONG	FPS_wt;
static BOOL FPS_Keep;

/*------------------------
	DrawingSystem 終了
  -------------------------*/
void CFACE::DrawRelease( ){
	if ( dwDrawMode == DRAWDISABLE )return;
	
	LogBegin( _T( "Graphics Destraction" ) );

	for (int i =0;i < dwSpriteNum ; i++ )
		Sprites[ i ].Clear( );
	// DirectDraw開放メソッド
	SAFE_RELEASE( PriSurf );
	SAFE_RELEASE( lpClipper );
	SAFE_RELEASE( ObjDD );
	dwDrawMode = DRAWDISABLE;
	LogQuit( );
}
void CFACE::DrawClear( ){
	dwDrawMode	= DRAWDISABLE;
	FPS_wt		= 1000 / 60;
	FPS_Keep	= TRUE;
	ObjDD		= NULL; 
	PriSurf		= NULL; 
	lpClipper	= NULL;
}
/*------------------------
	イニシャライズ
  -------------------------*/
STDMETHODIMP CFACE::Graphics( LONG lParam ){ if ( lParam == dwDrawMode ) return S_OK;

	// ログに記述
		LogBegin( "Graphics Initializer" );
		LogPut( CONTINUE , IDS_LOG_MODEOUT , lParam ); 
	// ハンドルチェック
		CHECK_HWND;
	// グラフィック定数範囲チェック
		CHECK_RANGE( lParam , 0 , 3 );

	// 使用しないモード
	if ( lParam == DRAWDISABLE ) DrawRelease( ); 
	else{
		/* DirectDrawは全て開放されるので、サーフェスをバックアップ */
		if ( ( dwDrawMode == DDRAW || dwDrawMode == DDRAW_FULL ) ){
			for ( int i = 0 ; i < dwSpriteNum ; i++ )
				Sprites[ i ].DDSurfToGDISurf( );
			// DirectDraw開放メソッド
			SAFE_RELEASE( PriSurf );
			SAFE_RELEASE( lpClipper );
			SAFE_RELEASE( ObjDD );
		}
		// フルスクリーン用
		if ( lParam == DDRAW_FULL ){
			put_wHasTitleBar( 0 );
			wResizeTo( 640 , 480 );
		}else 
			put_wHasTitleBar( 1 );
		/* -- ダイレクトドロー始動 -- */
		if ( lParam != WINGDI ){
#ifdef DX7
			if ( DD_OK != DirectDrawCreateEx( NULL, (VOID**)&ObjDD , IID_IDirectDraw7 , NULL )){
#else
			if ( DD_OK != DirectDrawCreate( NULL, &ObjDD ,  NULL )){
#endif
				DDrawInitFailed;
			}else{
				if ( lParam == DDRAW ){
					/* -- 協調レベルセット -- */
					if ( DD_OK != ObjDD->SetCooperativeLevel( hWnd ,DDSCL_NORMAL ) )
						DDrawInitFailed;
					/* -- クリッパーを取得し、関連づけ -- */
					if ( DD_OK != ObjDD->CreateClipper( 0 , &lpClipper , NULL ) )
						DDrawInitFailed;
					lpClipper->SetHWnd( 0 , hWnd );
					MessageBox( hWnd , "","",0);
					// make Primary
					DXObjInit( SURFACEDESC ddsd , ddsd );
						ddsd.dwFlags = DDSD_CAPS; 
							ddsd.ddsCaps.dwCaps = DDSCAPS_PRIMARYSURFACE;
					// Primary
					if ( DD_OK != ObjDD->CreateSurface( &ddsd , &PriSurf , NULL ) )
						DDrawInitFailed;
					PriSurf->SetClipper( lpClipper );
				}else{
					/* -- 協調レベルセット -- */
					if ( DD_OK != ObjDD->SetCooperativeLevel( hWnd , 
							DDSCL_EXCLUSIVE | DDSCL_FULLSCREEN ) )
						DDrawInitFailed;
					/* -- ディスプレーモード設定 -- */
					if ( DD_OK != SETDISPLAYMODE )
						DDrawInitFailed;
				} // End Full or NormalDraw if
			} // end Block if
		}
		/* -- セカンダリサーフェースを復帰 -- */
		if ( lParam == DDRAW || lParam == DDRAW_FULL ){
			for (int i=0;i<dwSpriteNum;i++)
				Sprites[ i ].GDISurfToDDSurf( );
		}
		/* -- セカンダリサーフェースを作成 -- */
		Sprites[ 0 ].Make( Screen.cx , Screen.cy , lParam );
		// 背景塗りつぶし
		DrawBox( 0 , 0 , Screen.cx , Screen.cy , 0 , TRUE , 0 );
	}
	LogQuit( );
	dwDrawMode = (BYTE)lParam;
	return S_OK;
}
/*-----------------
  Flip(WindowModeではセカンダリからプライマリへ転送)
	---------------- */
STDMETHODIMP CFACE::Refresh( ){
	switch ( dwDrawMode ){
	case DRAWDISABLE:
		break;
	case WINGDI:
		/* -- フロントからバックへ転送するため -- */
		{
			HDC hDC = GetDC( hWnd );
			BitBlt( hDC , 0 , 0 , Screen.cx, Screen.cy , 
				Sprites[ 0 ].GetSprDC( ) , 0 , 0 , SRCCOPY );
			// 開放
			ReleaseDC( hWnd ,  hDC );
		}
		break;
	case DDRAW:
		{
			// 通常 ビルてぃんぐ
			RECT DestRect; POINT Pos = { 0 , 0 };
			// 座標計算
			ClientToScreen( hWnd , &Pos );			
			SetRect( &DestRect , Pos.x , Pos.y , 
				Pos.x + Screen.cx,Pos.y + Screen.cy );
			// ブリッティング
			PriSurf->Blt( &DestRect , Sprites[ 0 ].GetSurf( ) , 
				NULL , DDBLT_DONOTWAIT , NULL );
		} // EndBlock
		break;
	case DDRAW_FULL:
		PriSurf->Blt( NULL , Sprites[ 0 ].GetSurf( ) , 
			NULL , DDBLT_DONOTWAIT , NULL );
		break;
	}
	/* -- ウェイトをかける -- */
	static	DWORD	InnerTick = timeGetTime( ) - 1;
			LONG	w = FPS_wt - ( timeGetTime() - InnerTick ) ;

	if ( ( FPS_Keep = ( w > 0) ) ) Sleep( w );
 	InnerTick = timeGetTime( );

	return S_OK;
}
/*-------------------------
	通常画像転送メソッド
	----------------------- */
STDMETHODIMP CFACE::Blt( LONG FromID , LONG FromX , LONG FromY , LONG w , LONG h , 
						LONG ToID , LONG ToX , LONG ToY ){
	CHECK_MODE( dwDrawMode );
	CHECK_RANGE_STR( FromID , 0 , dwSpriteNum , "Draw系関数(Blt)->FromSprite ID" );
	CHECK_EMPTY_STR( Sprites, FromID , "Draw系関数(Blt)->FromSprite" );
	CHECK_RANGE_STR(   ToID , 0 , dwSpriteNum , "Draw系関数(Blt)->ToSprite ID" );
	CHECK_EMPTY_STR( Sprites,  ToID , "Draw系関数(Blt)->ToSprite" );
	
	if ( dwDrawMode == WINGDI ){
		if ( Sprites[ FromID ].ClrKeying( ) ){
			// マスク画像を貼り付け
			BitBlt( Sprites[ ToID ].GetSprDC( ) , ToX , ToY ,  w , h , 
				Sprites[ FromID ].GetSprDC( ) , 
				FromX , FromY + Sprites[ FromID ].Size.cy , SRCAND );
		}
		// 転送画像を貼り付け
		BitBlt( Sprites[ ToID ].GetSprDC( ) , ToX , ToY ,  w , h , 
			Sprites[ FromID ].GetSprDC( ) , FromX , FromY , 
			( !Sprites[ FromID ].ClrKeying( ) ? SRCCOPY : SRCPAINT ) );
	}else{
		RECT SrcRect , DestRect ;
		// れくと情報セット
		SetRect( &SrcRect , FromX , FromY , FromX + w , FromY + h );
		SetRect( &DestRect , ToX , ToY , ToX + w , ToY + h );
		
		Sprites[ ToID ].GetSurf( )->Blt( &DestRect , Sprites[ FromID ].GetSurf( ) , &SrcRect ,  
			( Sprites[ FromID ].ClrKeying( ) ? DDBLT_KEYSRC  : 0 )|DDBLT_DONOTWAIT  , NULL );
	}

	return S_OK;
}
/*---------------------------
	伸縮可能画像転送メソッド
	------------------------*/
STDMETHODIMP CFACE::BltStretch( LONG FromID , LONG FromX , LONG FromY , LONG FromW , LONG FromH , 
						LONG ToID , LONG ToX , LONG ToY , LONG ToW , LONG ToH  ){
	CHECK_MODE( dwDrawMode );
	CHECK_RANGE_STR( FromID , 0 , dwSpriteNum , "Draw系関数(BltStretch)->FromSprite ID" );
	CHECK_EMPTY_STR( Sprites, FromID ,, "Draw系関数(BltStretch)->FromSprite" );
	CHECK_RANGE_STR(   ToID , 0 , dwSpriteNum , "Draw系関数(BltStretch)->ToSprite ID" );
	CHECK_EMPTY_STR( Sprites,   ToID , , "Draw系関数(BltStretch)->ToSprite" );
	
	if ( dwDrawMode == WINGDI ){
		if ( Sprites[ FromID ].ClrKeying( ) ){
			// マスク画像を貼り付け
			StretchBlt( Sprites[ ToID ].GetSprDC( ) , ToX , ToY ,  ToW , ToH , 
				Sprites[ FromID ].GetSprDC( ) , FromX , FromY + Sprites[ FromID ].Size.cy , 
				FromW , FromH , SRCAND );
		}
		// 転送画像を貼り付け
		StretchBlt( Sprites[ ToID ].GetSprDC( ) , ToX , ToY ,  ToW , ToH , 
			Sprites[FromID].GetSprDC( ) , FromX , FromY , FromW , FromH , 
			( !Sprites[ FromID ].ClrKeying( ) ? SRCCOPY : SRCPAINT ) );
	}else{
		RECT SrcRect , DestRect ;
		// れくと情報セット
		SetRect( &SrcRect , FromX , FromY , FromX + FromW , FromY + FromH );
		SetRect( &DestRect , ToX , ToY , ToX + ToW , ToY + ToH );
		
		Sprites[ ToID ].GetSurf( )->Blt( &DestRect , Sprites[FromID].GetSurf( ) , &SrcRect ,  
			( !Sprites[ FromID ].ClrKeying( ) ? DDBLT_KEYSRC  : 0 )|DDBLT_DONOTWAIT , NULL );
	}

	return S_OK;
}
/*-------------------------
	αブレンドサポート画像転送メソッド
	---------------------- */
STDMETHODIMP CFACE::BltAlphaBlend( LONG FromID , LONG FromX , LONG FromY , LONG w , LONG h , 
							 LONG ToID , LONG ToX , LONG ToY , LONG AlphaValue){
	int i,j;
	int r1,g1,b1,r2,g2,b2,r3,g3,b3;
	COLORREF cl , cl2 ; 

	CHECK_MODE( dwDrawMode );
	CHECK_RANGE_STR( FromID , 0 , dwSpriteNum , "Draw系関数(BltAlphaBlend)->FromSprite ID" );
	CHECK_EMPTY_STR( Sprites, FromID ,, "Draw系関数(BltAlphaBlend)->FromSprite" );
	CHECK_RANGE_STR(   ToID , 0 , dwSpriteNum , "Draw系関数(BltAlphaBlend)->ToSprite ID" );
	CHECK_EMPTY_STR( Sprites,   ToID , , "Draw系関数(BltAlphaBlend)->ToSprite" );
	
	HDC hDC = Sprites[ FromID ].GetSprDC( );
	HDC hDC2 = Sprites[ ToID ].GetSprDC( );
	
	for ( i = 0 ; i < w ; i++ ){
		for ( j = 0 ; j < h ; j++ ){
			cl = GetPixel( hDC , FromX + i , FromY + j );
			cl2 = GetPixel( hDC2 , ToX + i , ToY + j );
			r1 = (cl & 0xff);
			r2 = (cl2 & 0xff);
			g1 = (cl >> 8) & 0xff;
			g2 = (cl2 >> 8) & 0xff;
			b1 = (cl >> 16) & 0xff;
			b2 = (cl2 >> 16) & 0xff;
			r3 = ((r1 - r2) * AlphaValue >> 8) + r2;
			g3 = ((g1 - g2) * AlphaValue >> 8) + g2;
			b3 = ((b1 - b2) * AlphaValue >> 8) + b2;

			SetPixelV( hDC2 , ToX + i , ToY + j , RGB(r3 , g3 , b3));
		}
	}

	return S_OK;
}

STDMETHODIMP CFACE::DSetFillStyle(LONG newVal , LONG SpriteID) DrawBegin;
	Sprites[ SpriteID ].dwFillStyle = newVal; 
DrawEnd
STDMETHODIMP CFACE::DSetLineStyle(LONG newVal , LONG SpriteID) DrawBegin;
	Sprites[ SpriteID ].dwLineStyle = newVal; 
DrawEnd
STDMETHODIMP CFACE::DSetRasterOP(LONG newVal, LONG SpriteID) DrawBegin;
	SetROP2( hDC , newVal );
DrawEnd
STDMETHODIMP CFACE::DSetMapMode(LONG newVal, LONG SpriteID)DrawBegin;
	SetMapMode( hDC , newVal ); 
DrawEnd
STDMETHODIMP CFACE::DSetOrigin(LONG X, LONG Y, LONG SpriteID)DrawBegin;
	SetWindowOrgEx( hDC , X , Y , NULL );
DrawEnd
/* --------------------- 
   四角形を描画する
	--------------------*/
STDMETHODIMP CFACE::DrawBox( LONG x , LONG y , LONG w , LONG h , 
					LONG Color , BOOL Fills , LONG SpriteID ) DrawBegin;
	ObjectSet;
	RECT RT; SetRect( &RT , x , y , x + w , y + h );
	/* -- 塗りつぶし？それとも・・・ */
	if ( Fills )	FillRect	( hDC , &RT , FillColor );
	else			FrameRect	( hDC , &RT , FillColor );

	ObjectRelease;

DrawEnd


const double Pai = 3.14159265;
const double Rad = Pai / 180;
/*------------------------
	多角形を描画（オリジナル関数)
--------------------------*/
STDMETHODIMP CFACE::DrawPolygon( LONG x , LONG  y ,LONG wr , LONG hr ,
									LONG Polygon , LONG Rotate ,
									LONG Color , BOOL Fills , LONG SpriteID ) DrawBegin;
	ObjectSet;

	if ( Rotate == 0 )Rotate= 360;
	double	Rot = 2 * Pai / Polygon , 
			Base = Rad * Rotate, 
			th ;
	LONG dx , dy ;
	
	/* -- 線の数だけループ -- */
	for ( LONG i = 0 ; i <= Polygon ; i++ ){
		th = Rot * i + Base;
		
		dx = (LONG)(x + wr * cos( th ) ) ; dy = (LONG)(y + hr * sin( th ));
		if ( i > 0 )
			LineTo( hDC , dx , dy );
		else
			MoveToEx( hDC , dx , dy , NULL );
	}

	if ( Fills )ExtFloodFill( hDC , x , y , Color , FLOODFILLBORDER );

	ObjectRelease;

DrawEnd

/* ---------------------

   角丸四角形を描画する

	--------------------*/
STDMETHODIMP CFACE::DrawRoundBox( LONG x , LONG y , LONG w , LONG h , LONG Round , 
					LONG Color , BOOL Fills , LONG SpriteID  ) DrawBegin;
			
	HBRUSH	OldBrush	,FillColor = NULL ;
	if ( Fills ){
		if ( Sprites[ SpriteID ].dwFillStyle == -1 ) 
			FillColor = CreateSolidBrush( Color ); 
		else 
			FillColor = CreateHatchBrush( Sprites[ SpriteID ].dwFillStyle , Color );
		OldBrush	=	(HBRUSH)SelectObject( hDC , FillColor ); 
	}
	HPEN	OldPen		, ForeColor	= CreatePen( Sprites[ SpriteID ].dwLineStyle, 0 , Color ) ; 
	OldPen		=	(HPEN)SelectObject( hDC , ForeColor );

	RoundRect( hDC , x , y , x + w , y + h , Round , Round );

	if ( Fills ){
		SelectObject( hDC , OldBrush );
		DeleteObject( FillColor );
	}
	SelectObject( hDC , OldPen );
	DeleteObject( ForeColor );
DrawEnd
/* ---------------------

   線を描画する

	--------------------*/
STDMETHODIMP CFACE::DrawLine( LONG x1, LONG y1 , LONG x2, LONG y2 , 
				LONG Color , LONG SpriteID ) DrawBegin;
	ObjectSet;
	MoveToEx( hDC , x1 , y1 , NULL );
	LineTo( hDC , x2 , y2 );
	ObjectRelease;
DrawEnd
/* ---------------------

   線を描画する

	--------------------*/
STDMETHODIMP CFACE::DrawLineFromLP( LONG x, LONG y , 
				LONG Color , LONG SpriteID ) DrawBegin;
	ObjectSet;
	LineTo( hDC , x , y );
	ObjectRelease;
DrawEnd
/*-------------------

	ＬＰセット

--------------------*/
STDMETHODIMP CFACE::DSetLP( LONG x, LONG y , LONG SpriteID ) DrawBegin;
	MoveToEx( hDC , x , y , NULL );
DrawEnd
/* ---------------------

   点を描画する

	--------------------*/
STDMETHODIMP CFACE::DrawPixel( LONG x, LONG  y , LONG Color , LONG SpriteID ) DrawBegin;
	SetPixelV( hDC , x , y , Color );
DrawEnd
/* ---------------------

   点を取得する

	--------------------*/
STDMETHODIMP CFACE::DGetPixel( LONG x, LONG  y , LONG SpriteID , LONG *retVal ) DrawBegin;
	*retVal = GetPixel( hDC , x , y );
DrawEnd
/* ---------------------

   塗りつぶし

	--------------------*/
STDMETHODIMP CFACE::DrawFill( LONG x , LONG y , LONG Color , LONG SpriteID ) DrawBegin;
	ObjectSet;
	ExtFloodFill( hDC , x ,y , GetPixel( hDC , x , y ) , FLOODFILLSURFACE );
	ObjectRelease;
DrawEnd
/* -----------------------

  円を描画する
	
	----------------------*/
STDMETHODIMP CFACE::DrawCircle( LONG x, LONG y , LONG Radius , 
				LONG StartR , LONG EndR , 
				LONG Color , BOOL Fills , LONG SpriteID ) DrawBegin;

	ObjectSet;
    
	if ( StartR == EndR ){
		/* -- 描かない -- */
	}else if ( abs( EndR - StartR ) % 360 == 0 ){
		/* -- 円周が360度 -- */
		if ( Fills )
			Ellipse( hDC , x - Radius , y - Radius , 
							x + Radius , y + Radius );
		else
			Arc( hDC ,  x - Radius , y - Radius , 
							x + Radius , y + Radius ,
							0 , 0 , 0 , 0 );
	}else{
		LONG StartX , StartY , EndX , EndY ;
		StartX	= (LONG)( cos( Rad * StartR ) * Radius) + x;
		StartY	= (LONG)( -sin( Rad * StartR ) * Radius) + y;
		EndX	= (LONG)( cos( Rad * EndR ) * Radius) + x;
		EndY	= (LONG)( -sin( Rad * EndR ) * Radius) + y;

		if ( Fills )
			Pie( hDC , x - Radius , y - Radius , 
							x + Radius , y + Radius , 
							StartX , StartY , EndX , EndY );
		else
			Arc( hDC , x - Radius , y - Radius , 
							x + Radius , y + Radius ,
							StartX , StartY , EndX , EndY );
	}

	ObjectRelease;

DrawEnd
/* ----------------------------
	楕円の描画（オリジナル)
	--------------------------*/
STDMETHODIMP CFACE::DrawEllipse(  LONG x, LONG y , LONG wr , LONG hr , 
				LONG StartR , LONG EndR , 
				LONG Color , BOOL Close , LONG SpriteID ) DrawBegin;
	ObjectSet;

	LONG dx , dy;
	
	for ( LONG i = StartR ; i <= EndR ; i++ ){
		double th = Rad * i;

		dx = (LONG)( x + wr * cos( th ) );
		dy = (LONG)( y - hr * sin( th ) );
		
		if ( i > StartR ){
			if ( ( i == EndR ) && Close ) {
				MoveToEx( hDC , dx , dy , NULL );
				LineTo( hDC , x , y );
			}
			LineTo( hDC , dx , dy );
		}else{
			if ( Close ){
				MoveToEx( hDC , dx , dy , NULL );
				LineTo( hDC , x , y );
			}
			MoveToEx( hDC , dx , dy , NULL );
		}
	}
	
	ObjectRelease;

DrawEnd

STDMETHODIMP CFACE::DrawString( LONG x, LONG y , BSTR Text, 
							   LONG TextAlign ,LONG Color , LONG SpriteID ) 
DrawBegin;
	
	USES_CONVERSION;
	HFONT OldFont , hFont ; RECT RT; LONG Opt = 0 ;
	
	TextMaskCheck( TextAlign );

	hFont = CreateFontIndirect( &Sprites[ SpriteID ].FontSet );
	SetTextColor( hDC , Color );		/* 文字の色		*/
	SetBkMode( hDC , TRANSPARENT );		/* 背景は透明	*/
	OldFont = (HFONT)SelectObject( hDC , hFont );

	TextMaskCheck( TextAlign );

	DrawText( hDC , OLE2T( Text ) , -1 , 
		&RT , DT_EXPANDTABS | DT_NOPREFIX | DT_NOCLIP | Opt );

	SelectObject( hDC , OldFont );
	DeleteObject( hFont );
DrawEnd
/* -------------------------
	文字間隔の設定 
	----------------------*/
STDMETHODIMP CFACE::DSetTextSpace( LONG lSpace , LONG SpriteID ) DrawBegin;
	SetTextCharacterExtra( hDC , lSpace );
DrawEnd

STDMETHODIMP CFACE::DSetTextFont( LONG Size , BOOL Bold , BOOL Italic , BOOL UnderLine , 
								 BOOL Strike , BSTR FontName , LONG SpriteID ) DrawBegin;

	USES_CONVERSION;
	
	if ( Size != 0xFF )		Sprites[ SpriteID ].FontSet.lfHeight = Size;
	if ( Bold != 0xFF )		Sprites[ SpriteID ].FontSet.lfWeight = Bold* 800;
	if ( Italic != 0xFF	)	Sprites[ SpriteID ].FontSet.lfItalic = (BYTE)Italic;
	if ( UnderLine !=0xFF )	Sprites[ SpriteID ].FontSet.lfUnderline  = (BYTE)UnderLine;
	if ( Strike != 0xFF )	Sprites[ SpriteID ].FontSet.lfStrikeOut = (BYTE)Strike;
	
	if ( lstrcmp( OLE2T(FontName) , _T( "default" ) ) != 0 ){
		ZeroMemory( 
			Sprites[ SpriteID ].FontSet.lfFaceName , 
			sizeof( Sprites[ SpriteID ].FontSet.lfFaceName ) );
		lstrcpy( Sprites[ SpriteID ].FontSet.lfFaceName ,  OLE2T(FontName) );
	}

DrawEnd 

void CFACE::Receive( LONG w , LONG h ){
	lpFACE->SpriteResize( 0 , w , h );
	Screen.cx = w ; Screen.cy = h;
}
STDMETHODIMP CFACE::get_SoftwareFPS(LONG *pVal){ 
	*pVal = 1000 / FPS_wt; return S_OK;
}
STDMETHODIMP CFACE::put_SoftwareFPS(LONG newVal){
	if ( newVal == -1 )
		FPS_wt = 0;
	else
		FPS_wt = 1000 / newVal; return S_OK;
}
STDMETHODIMP CFACE::get_KeepFPS(BOOL *pVal){*pVal = FPS_Keep; return S_OK; }
/* -- カラーキー設定 -- */
STDMETHODIMP CFACE::DSetColorKey(LONG Color, LONG SpriteID){
	CHECK_MODE( dwDrawMode );
	CHECK_RANGE_STR( SpriteID , 0 , dwSpriteNum , "Draw系関数(DSetColorKey)->Sprite ID" );
	CHECK_EMPTY_STR( Sprites, SpriteID , "Draw系関数(DSetColorKey)->Sprite" );

	Sprites[ SpriteID ].SetColorKey( Color );
	
	return S_OK;
}
