#include "FACE_Draw_Assist.h"

STDMETHODIMP CFACE::SpriteState( LONG SpriteID , BOOL IsEnable ){
	CHECK_MODE( dwDrawMode );
	CHECK_RANGE_STR( SpriteID , 0 , dwSpriteNum , "Draw系関数(DSetColorKey)->Sprite ID" );
		
	if ( !IsEnable )
		Sprites[ SpriteID ].Clear( );
	else
		Sprites[ SpriteID ].Make( Screen.cx, Screen.cy );

	return S_OK;
 }
STDMETHODIMP CFACE::SpriteResize( LONG SpriteID , LONG cx , LONG cy ){
	//モードチェックと範囲チェック
	CHECK_MODE( dwDrawMode );
	CHECK_RANGE_STR( SpriteID , 0 , dwSpriteNum , "Draw系関数(DSetColorKey)->Sprite ID" );
	CHECK_EMPTY_STR( Sprites, SpriteID , "Draw系関数(DSetColorKey)->Sprite" );
	/* スプライトへのアクセスポインタ -- */
	SPRITE *lpSprite = &Sprites[ SpriteID ];

	/* -- サイズ比較 -- */
	if ( lpSprite->Size.cx == cx && lpSprite->Size.cy == cy ) {
		return S_OK;
	}
	/* 互換性のある空のサーフェスを作成 */
	HDC		CompatibleDC	= CreateCompatibleDC( 0 );
	HBITMAP CompatibleBMP	= CreateCompatibleBitmap( CompatibleDC , cx , cy * 2 ); 
	LONG	MemCLRKey		= lpSprite->CLRKey;
		// 関連づけを行う
		SelectObject( CompatibleDC , CompatibleBMP );
	// 一時ＤＣに転送
	HDC SpriteDC = lpSprite->GetSprDC( );
	BitBlt( CompatibleDC , 0 , 0 ,  
		min( cx , lpSprite->Size.cx ) , min( cy , lpSprite->Size.cy ) ,
		SpriteDC , 0 , 0 , SRCCOPY );
	BitBlt( CompatibleDC , 0 , cy ,  
		min( cx , lpSprite->Size.cx ) , min( cy , lpSprite->Size.cy ) ,
		SpriteDC , 0 , cy , SRCCOPY );
	lpSprite->EndSprDC( SpriteDC );
	// リサイズ
	lpSprite->Clear();
	lpSprite->Make( cx , cy );
	// 復元
	SpriteDC = lpSprite->GetSprDC( );
	BitBlt( SpriteDC , 0 , 0 ,  
		cx , cy  ,
		CompatibleDC , 0 , 0 , SRCCOPY );
	BitBlt( SpriteDC , 0 , cy ,  
		cx ,cy ,
		CompatibleDC , 0 , 0 , SRCCOPY );
	lpSprite->EndSprDC( SpriteDC );
	DeleteObject( CompatibleBMP );
	DeleteDC( CompatibleDC );

	return S_OK;
}

int PASCAL ProgressCallback(int , int , LONG ){return 0;}
STDMETHODIMP CFACE::SpriteLoadFromFile( LONG SpriteID , BSTR FileName ){
	USES_CONVERSION;
	// 開始
	LogBegin( _T( "SpriteLoadFromFile" ) );
	//モードチェックと範囲チェック
	CHECK_MODE( dwDrawMode );
	CHECK_RANGE_STR( SpriteID , 0 , dwSpriteNum , "Draw系関数(DSetColorKey)->Sprite ID" );
	// ログアウト
	LogPut( CONTINUE , IDS_LOG_LOADFROMFILE , OLE2T( FileName ) , SpriteID );
	/* スプライトへのアクセスポインタ -- */
	SPRITE *lpSprite = &Sprites[ SpriteID ];
	lpSprite->Clear( );
	/* ファイルへのパスを取得する */
	TCHAR FilePath[ MAX_PATH ];
	if ( !GetFilePath( OLE2T( FileName ) , FilePath ) )
		LogPut( FATAL , IDS_ERR_FILENOTFOUND );
	/* 外部ライブラリのロード */
	HINSTANCE	jpg , png; 
	ISSUPPORTED	jpgIsSupported	,	pngIsSupported;
	GETPICTURE	jpgGetPicture	,	pngGetPicture ;
	HBITMAP		hBitmap ;
	GETPICTURE		GetFunc = NULL;	// 読み込み先
	// JPGLibの取り込み
		if ( jpg = LoadLibrary( _T( "jpegloader." ) ) ){
			// 関数ロード
			jpgIsSupported	= (ISSUPPORTED)GetProcAddress( jpg , "IsSupported" );
			jpgGetPicture	= (GETPICTURE) GetProcAddress( jpg , "GetPicture" );
			if (!( jpgIsSupported && jpgGetPicture ) ){
				FreeLibrary( jpg ); jpg = NULL;
			}
		}
	// PNGLibの取り込み
		if ( png = LoadLibrary( _T( "pngloader." ) ) ){
			// 関数ロード
			pngIsSupported	= (ISSUPPORTED)GetProcAddress( png , "IsSupported" );
			pngGetPicture	= (GETPICTURE) GetProcAddress( png , "GetPicture" );
			if ( !( pngIsSupported && pngGetPicture ) ){
				FreeLibrary( png ); png = NULL;
			}
		}
	// 対応を調べる
		TCHAR lpFormatStr[ 64 ];
		HANDLE hFile = CreateFile( FilePath  , GENERIC_READ , FILE_SHARE_READ , NULL , 
			OPEN_EXISTING , FILE_ATTRIBUTE_NORMAL , NULL );
		// Chk JPG
		if ( jpg && jpgIsSupported( FilePath , (DWORD)hFile ) ){
			GetFunc = jpgGetPicture;
			lstrcpy( lpFormatStr, _T("Joint Photographic Exports Group(JPEG) Image file") );
		}else{
			CloseHandle( hFile );
			hFile = CreateFile( FilePath  , GENERIC_READ , FILE_SHARE_READ , NULL , 
				OPEN_EXISTING , FILE_ATTRIBUTE_NORMAL , NULL );
			// Chk PNG
			if ( png && pngIsSupported( FilePath , (DWORD)hFile ) ){
				GetFunc = pngGetPicture; 
				lstrcpy( lpFormatStr, _T( "Portable Network Graphics(PNG) Image file" ) );
			}else{
				CloseHandle( hFile );
				// Chk BMP
				if ( hBitmap = ( HBITMAP )LoadImage( NULL , FilePath , IMAGE_BITMAP , 
					0 , 0 , LR_LOADFROMFILE | LR_CREATEDIBSECTION ) ) 
						lstrcpy( lpFormatStr, _T( "BITMAP Image file **" ) );
				else{
					LogPut( FATAL , IDS_ERR_INVALIDFILE );
				}
			}
		}
	SIZE Size ;	// 幅と高さ情報		
	if ( GetFunc ){
		CloseHandle( hFile );
		// ライブラリからロードすることができる
		HDC				DestDC;
		HANDLE			hBitmapInfo , hBitmapBitData;
		LPBYTE			m_pImage;
		LPBITMAPINFO	m_pHDR;
	
		GetFunc( FilePath , 0 , 0 , 
			&hBitmapInfo , &hBitmapBitData , ProgressCallback , 0 );
		m_pImage	= (LPBYTE)LocalLock(hBitmapBitData);
		m_pHDR		= (LPBITMAPINFO)LocalLock(hBitmapInfo);
		// 情報取得
		Size.cx = m_pHDR->bmiHeader.biWidth;
		Size.cy = m_pHDR->bmiHeader.biHeight;
		// スプライト作成
		lpSprite->Make( Size.cx , Size.cy );
		//GDI関数でブロック転送
		DestDC = lpSprite->GetSprDC( );
		StretchDIBits( DestDC , 0 , 0 , Size.cx , Size.cy , 0 , 0 , 
					Size.cx , Size.cy , m_pImage , m_pHDR , 
					DIB_RGB_COLORS , SRCCOPY );
		lpSprite->EndSprDC( DestDC );

		/* -- 読み込みに使用したオブジェクトの開放 -- */
		LocalUnlock( hBitmapInfo );
		LocalUnlock( hBitmapBitData );
		LocalFree( m_pHDR );
		LocalFree( m_pImage );
		if ( png )FreeLibrary( png );
		if ( jpg )FreeLibrary( jpg );
	}else{
		HDC			SrcDC , DestDC;
		BITMAP		bmp;
		//ビットマップヘッダからサイズを取得
		GetObject( hBitmap , sizeof( BITMAP ) , ( LPSTR )&bmp );
		Size.cx = bmp.bmWidth; Size.cy = bmp.bmHeight;
		// 空のCompatibleDCを作成後ＢＭＰと関連づける
		SrcDC	= CreateCompatibleDC( NULL );
		SelectObject( SrcDC , hBitmap );
		// スプライト作成
		lpSprite->Make( Size.cx, Size.cy );
		//GDI関数でブロック転送
		DestDC = lpSprite->GetSprDC( );
		BitBlt( DestDC , 0 , 0 , Size.cx , Size.cy , SrcDC , 0 , 0 , SRCCOPY );
		lpSprite->EndSprDC( DestDC );
		//　解放
		DeleteObject( hBitmap );
		DeleteDC( SrcDC );
	}
	// 幅と高さの書き出し
	LogPut( CONTINUE , IDS_LOG_IMAGEINFO , lpFormatStr, EXPAND_SIZE( Size ) );
	LogQuit( );
	// カラーキー適応
	DSetColorKey( lpSprite->CLRKey , SpriteID ); 
	
	return S_OK;
}
STDMETHODIMP CFACE::SpriteCopy( LONG FromID , LONG ToID ){

	CHECK_MODE( dwDrawMode );
	CHECK_RANGE_STR( FromID , 0 , dwSpriteNum , "Draw系関数(SpriteCopy)->Sprite ID" );
	CHECK_RANGE_STR( ToID , 0 , dwSpriteNum , "Draw系関数(SpriteCopy)->Sprite ID" );
	CHECK_EMPTY_STR( Sprites, FromID , "Draw系関数(SpriteCopy)->Sprite" );

	/* -- ブリッティング（コピー ) -- */
	Blt( FromID , 0 , 0 ,  EXPAND_SIZE( Sprites[ FromID ].Size ) , ToID , 0 , 0 );
	
	return S_OK;
}
STDMETHODIMP CFACE::SpritePaste( LONG FromID , LONG ToID , LONG x , LONG y ){

	CHECK_MODE( dwDrawMode );
	CHECK_RANGE_STR( FromID , 0 , dwSpriteNum , "Draw系関数(SpritePaste)->Sprite ID" );
	CHECK_RANGE_STR( ToID , 0 , dwSpriteNum , "Draw系関数(SpritePaste)->Sprite ID" );
	CHECK_EMPTY_STR( Sprites, FromID , "Draw系関数(SpritePaste)->Sprite" );

	Blt( FromID , 0 , 0 , EXPAND_SIZE( Sprites[ FromID ].Size ) ,  ToID , x , y );
	
	return S_OK;
}
INT_PTR CALLBACK ViewerDlgProc( HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM ){
	static UINT Viewer = 0;

	switch ( uMsg ){
	case WM_INITDIALOG:
		SendMessage( GetDlgItem( hwndDlg , IDC_SLIDER ) , TBM_SETRANGE, 
			(WPARAM) TRUE, (LPARAM) MAKELONG( 0 , dwSpriteNum ) );  // min. & max. positions 
		SendMessage( GetDlgItem( hwndDlg , IDC_SLIDER ) , TBM_SETPOS, 
	        (WPARAM) TRUE, (LPARAM) 0 );
		SendMessage( hwndDlg , WM_HSCROLL,TB_ENDTRACK , 0 );
	case WM_HSCROLL:
		if ( LOWORD( wParam ) != TB_ENDTRACK) break;
		// 描画すべきＩＤを取得
		Viewer = SendMessage( GetDlgItem( hwndDlg , IDC_SLIDER ) , TBM_GETPOS, 0 , 0 );
			
		RECT Rect;
		// -- ウインドウサイズを設定-- 
		SetRect( &Rect, 0 , 0 , 
			( Sprites[ Viewer ].Size.cx < 320 ? 320 : Sprites[ Viewer ].Size.cx ) , 
			Sprites[ Viewer ].Size.cy + 25  );
		AdjustWindowRect( &Rect ,  GetWindowLong( hwndDlg , GWL_STYLE ) , FALSE );
		
		// ウインドウサイズ変更
		SetWindowPos( hwndDlg , HWND_TOP , 0 , 0 , Rect.right - Rect.left , Rect.bottom - Rect.top , 
			SWP_NOMOVE | SWP_SHOWWINDOW ); 
		// テキストを準備
		TCHAR Text[ 256 ];
		wsprintf( Text , _T("ID : %d") , Viewer ); 
		if ( Sprites[ Viewer ].IsEmpty( ) )	lstrcat( Text , _T("\r\n未使用です") );
		else
			wsprintf( Text , _T("%s\r\n %d*%d") , Text , EXPAND_SIZE( Sprites[ Viewer ].Size ) );
		// ウインドウテキスト設定
		SetWindowText( GetDlgItem( hwndDlg , IDC_LABEL ) , Text );
		// マスクがチェック可能か？
		EnableWindow( GetDlgItem( hwndDlg , IDC_MASKCHECK ) , 
			Sprites[ Viewer ].ClrKeying( ) && 
			dwDrawMode == WINGDI) ;
		// チェックを入れる
		SendMessage( GetDlgItem(hwndDlg,IDC_MASKCHECK) , BM_SETCHECK , 
			( Sprites[ Viewer ].ClrKeying( )  && 
			dwDrawMode == WINGDI ? BST_CHECKED : BST_UNCHECKED ) , 0 ); 
		// 再描画を要求
		RedrawWindow( hwndDlg , NULL , NULL , RDW_INVALIDATE | RDW_ERASE | RDW_UPDATENOW );

		return TRUE;
	case WM_PAINT:
		if ( !Sprites[ Viewer ].IsEmpty( ) ){
			PAINTSTRUCT ps; BeginPaint( hwndDlg , &ps );

			BOOL Masking = SendMessage( GetDlgItem( hwndDlg ,IDC_MASKCHECK ) , BM_GETCHECK , 0 , 0 );
			/*-- 転送先と転送元を区別 -- */
			HDC DestDC = Sprites[ Viewer ].GetSprDC( );
			
			if ( Masking == BST_CHECKED )
				// マスク画像を貼り付け
				BitBlt( ps.hdc , 0 , 25 , 
					EXPAND_SIZE( Sprites[ Viewer ].Size ),
					DestDC , 0 , 0 + Sprites[ Viewer ].Size.cy , SRCAND );
			// 転送画像を貼り付け
			BitBlt( ps.hdc , 0 , 25 , 
				EXPAND_SIZE( Sprites[ Viewer ].Size ) * 2  ,
				DestDC , 0 , 0 , 
				( Masking == BST_CHECKED ? SRCPAINT : SRCCOPY  ) );

			Sprites[ Viewer ].EndSprDC( DestDC );

			EndPaint( hwndDlg , &ps );
		}
		return FALSE;
	case WM_COMMAND:
		switch ( LOWORD( wParam ) ){
		case IDC_MASKCHECK:
			RedrawWindow( hwndDlg , NULL , NULL , RDW_INVALIDATE | RDW_ERASE | RDW_UPDATENOW  );
			break;
		case IDOK:
			EndDialog( hwndDlg , 0 );
			return TRUE;
		case IDCANCEL:
			EndDialog( hwndDlg , 0 );
			return TRUE;
		}
	}
	return FALSE;
}

STDMETHODIMP CFACE::SpriteView( ){
	DialogBox( hInst ,MAKEINTRESOURCE( IDD_SPRITEVIEWER ) , 
		hWnd , (DLGPROC)ViewerDlgProc );

	return S_OK;
}
