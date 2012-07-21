#include "FACE_Draw_Assist.h"

STDMETHODIMP CFACE::SpriteState( LONG SpriteID , BOOL IsEnable ){
	CHECK_MODE( dwDrawMode );
	CHECK_RANGE_STR( SpriteID , 0 , dwSpriteNum , "Draw�n�֐�(DSetColorKey)->Sprite ID" );
		
	if ( !IsEnable )
		Sprites[ SpriteID ].Clear( );
	else
		Sprites[ SpriteID ].Make( Screen.cx, Screen.cy );

	return S_OK;
 }
STDMETHODIMP CFACE::SpriteResize( LONG SpriteID , LONG cx , LONG cy ){
	//���[�h�`�F�b�N�Ɣ͈̓`�F�b�N
	CHECK_MODE( dwDrawMode );
	CHECK_RANGE_STR( SpriteID , 0 , dwSpriteNum , "Draw�n�֐�(DSetColorKey)->Sprite ID" );
	CHECK_EMPTY_STR( Sprites, SpriteID , "Draw�n�֐�(DSetColorKey)->Sprite" );
	/* �X�v���C�g�ւ̃A�N�Z�X�|�C���^ -- */
	SPRITE *lpSprite = &Sprites[ SpriteID ];

	/* -- �T�C�Y��r -- */
	if ( lpSprite->Size.cx == cx && lpSprite->Size.cy == cy ) {
		return S_OK;
	}
	/* �݊����̂����̃T�[�t�F�X���쐬 */
	HDC		CompatibleDC	= CreateCompatibleDC( 0 );
	HBITMAP CompatibleBMP	= CreateCompatibleBitmap( CompatibleDC , cx , cy * 2 ); 
	LONG	MemCLRKey		= lpSprite->CLRKey;
		// �֘A�Â����s��
		SelectObject( CompatibleDC , CompatibleBMP );
	// �ꎞ�c�b�ɓ]��
	HDC SpriteDC = lpSprite->GetSprDC( );
	BitBlt( CompatibleDC , 0 , 0 ,  
		min( cx , lpSprite->Size.cx ) , min( cy , lpSprite->Size.cy ) ,
		SpriteDC , 0 , 0 , SRCCOPY );
	BitBlt( CompatibleDC , 0 , cy ,  
		min( cx , lpSprite->Size.cx ) , min( cy , lpSprite->Size.cy ) ,
		SpriteDC , 0 , cy , SRCCOPY );
	lpSprite->EndSprDC( SpriteDC );
	// ���T�C�Y
	lpSprite->Clear();
	lpSprite->Make( cx , cy );
	// ����
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
	// �J�n
	LogBegin( _T( "SpriteLoadFromFile" ) );
	//���[�h�`�F�b�N�Ɣ͈̓`�F�b�N
	CHECK_MODE( dwDrawMode );
	CHECK_RANGE_STR( SpriteID , 0 , dwSpriteNum , "Draw�n�֐�(DSetColorKey)->Sprite ID" );
	// ���O�A�E�g
	LogPut( CONTINUE , IDS_LOG_LOADFROMFILE , OLE2T( FileName ) , SpriteID );
	/* �X�v���C�g�ւ̃A�N�Z�X�|�C���^ -- */
	SPRITE *lpSprite = &Sprites[ SpriteID ];
	lpSprite->Clear( );
	/* �t�@�C���ւ̃p�X���擾���� */
	TCHAR FilePath[ MAX_PATH ];
	if ( !GetFilePath( OLE2T( FileName ) , FilePath ) )
		LogPut( FATAL , IDS_ERR_FILENOTFOUND );
	/* �O�����C�u�����̃��[�h */
	HINSTANCE	jpg , png; 
	ISSUPPORTED	jpgIsSupported	,	pngIsSupported;
	GETPICTURE	jpgGetPicture	,	pngGetPicture ;
	HBITMAP		hBitmap ;
	GETPICTURE		GetFunc = NULL;	// �ǂݍ��ݐ�
	// JPGLib�̎�荞��
		if ( jpg = LoadLibrary( _T( "jpegloader." ) ) ){
			// �֐����[�h
			jpgIsSupported	= (ISSUPPORTED)GetProcAddress( jpg , "IsSupported" );
			jpgGetPicture	= (GETPICTURE) GetProcAddress( jpg , "GetPicture" );
			if (!( jpgIsSupported && jpgGetPicture ) ){
				FreeLibrary( jpg ); jpg = NULL;
			}
		}
	// PNGLib�̎�荞��
		if ( png = LoadLibrary( _T( "pngloader." ) ) ){
			// �֐����[�h
			pngIsSupported	= (ISSUPPORTED)GetProcAddress( png , "IsSupported" );
			pngGetPicture	= (GETPICTURE) GetProcAddress( png , "GetPicture" );
			if ( !( pngIsSupported && pngGetPicture ) ){
				FreeLibrary( png ); png = NULL;
			}
		}
	// �Ή��𒲂ׂ�
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
	SIZE Size ;	// ���ƍ������		
	if ( GetFunc ){
		CloseHandle( hFile );
		// ���C�u�������烍�[�h���邱�Ƃ��ł���
		HDC				DestDC;
		HANDLE			hBitmapInfo , hBitmapBitData;
		LPBYTE			m_pImage;
		LPBITMAPINFO	m_pHDR;
	
		GetFunc( FilePath , 0 , 0 , 
			&hBitmapInfo , &hBitmapBitData , ProgressCallback , 0 );
		m_pImage	= (LPBYTE)LocalLock(hBitmapBitData);
		m_pHDR		= (LPBITMAPINFO)LocalLock(hBitmapInfo);
		// ���擾
		Size.cx = m_pHDR->bmiHeader.biWidth;
		Size.cy = m_pHDR->bmiHeader.biHeight;
		// �X�v���C�g�쐬
		lpSprite->Make( Size.cx , Size.cy );
		//GDI�֐��Ńu���b�N�]��
		DestDC = lpSprite->GetSprDC( );
		StretchDIBits( DestDC , 0 , 0 , Size.cx , Size.cy , 0 , 0 , 
					Size.cx , Size.cy , m_pImage , m_pHDR , 
					DIB_RGB_COLORS , SRCCOPY );
		lpSprite->EndSprDC( DestDC );

		/* -- �ǂݍ��݂Ɏg�p�����I�u�W�F�N�g�̊J�� -- */
		LocalUnlock( hBitmapInfo );
		LocalUnlock( hBitmapBitData );
		LocalFree( m_pHDR );
		LocalFree( m_pImage );
		if ( png )FreeLibrary( png );
		if ( jpg )FreeLibrary( jpg );
	}else{
		HDC			SrcDC , DestDC;
		BITMAP		bmp;
		//�r�b�g�}�b�v�w�b�_����T�C�Y���擾
		GetObject( hBitmap , sizeof( BITMAP ) , ( LPSTR )&bmp );
		Size.cx = bmp.bmWidth; Size.cy = bmp.bmHeight;
		// ���CompatibleDC���쐬��a�l�o�Ɗ֘A�Â���
		SrcDC	= CreateCompatibleDC( NULL );
		SelectObject( SrcDC , hBitmap );
		// �X�v���C�g�쐬
		lpSprite->Make( Size.cx, Size.cy );
		//GDI�֐��Ńu���b�N�]��
		DestDC = lpSprite->GetSprDC( );
		BitBlt( DestDC , 0 , 0 , Size.cx , Size.cy , SrcDC , 0 , 0 , SRCCOPY );
		lpSprite->EndSprDC( DestDC );
		//�@���
		DeleteObject( hBitmap );
		DeleteDC( SrcDC );
	}
	// ���ƍ����̏����o��
	LogPut( CONTINUE , IDS_LOG_IMAGEINFO , lpFormatStr, EXPAND_SIZE( Size ) );
	LogQuit( );
	// �J���[�L�[�K��
	DSetColorKey( lpSprite->CLRKey , SpriteID ); 
	
	return S_OK;
}
STDMETHODIMP CFACE::SpriteCopy( LONG FromID , LONG ToID ){

	CHECK_MODE( dwDrawMode );
	CHECK_RANGE_STR( FromID , 0 , dwSpriteNum , "Draw�n�֐�(SpriteCopy)->Sprite ID" );
	CHECK_RANGE_STR( ToID , 0 , dwSpriteNum , "Draw�n�֐�(SpriteCopy)->Sprite ID" );
	CHECK_EMPTY_STR( Sprites, FromID , "Draw�n�֐�(SpriteCopy)->Sprite" );

	/* -- �u���b�e�B���O�i�R�s�[ ) -- */
	Blt( FromID , 0 , 0 ,  EXPAND_SIZE( Sprites[ FromID ].Size ) , ToID , 0 , 0 );
	
	return S_OK;
}
STDMETHODIMP CFACE::SpritePaste( LONG FromID , LONG ToID , LONG x , LONG y ){

	CHECK_MODE( dwDrawMode );
	CHECK_RANGE_STR( FromID , 0 , dwSpriteNum , "Draw�n�֐�(SpritePaste)->Sprite ID" );
	CHECK_RANGE_STR( ToID , 0 , dwSpriteNum , "Draw�n�֐�(SpritePaste)->Sprite ID" );
	CHECK_EMPTY_STR( Sprites, FromID , "Draw�n�֐�(SpritePaste)->Sprite" );

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
		// �`�悷�ׂ��h�c���擾
		Viewer = SendMessage( GetDlgItem( hwndDlg , IDC_SLIDER ) , TBM_GETPOS, 0 , 0 );
			
		RECT Rect;
		// -- �E�C���h�E�T�C�Y��ݒ�-- 
		SetRect( &Rect, 0 , 0 , 
			( Sprites[ Viewer ].Size.cx < 320 ? 320 : Sprites[ Viewer ].Size.cx ) , 
			Sprites[ Viewer ].Size.cy + 25  );
		AdjustWindowRect( &Rect ,  GetWindowLong( hwndDlg , GWL_STYLE ) , FALSE );
		
		// �E�C���h�E�T�C�Y�ύX
		SetWindowPos( hwndDlg , HWND_TOP , 0 , 0 , Rect.right - Rect.left , Rect.bottom - Rect.top , 
			SWP_NOMOVE | SWP_SHOWWINDOW ); 
		// �e�L�X�g������
		TCHAR Text[ 256 ];
		wsprintf( Text , _T("ID : %d") , Viewer ); 
		if ( Sprites[ Viewer ].IsEmpty( ) )	lstrcat( Text , _T("\r\n���g�p�ł�") );
		else
			wsprintf( Text , _T("%s\r\n %d*%d") , Text , EXPAND_SIZE( Sprites[ Viewer ].Size ) );
		// �E�C���h�E�e�L�X�g�ݒ�
		SetWindowText( GetDlgItem( hwndDlg , IDC_LABEL ) , Text );
		// �}�X�N���`�F�b�N�\���H
		EnableWindow( GetDlgItem( hwndDlg , IDC_MASKCHECK ) , 
			Sprites[ Viewer ].ClrKeying( ) && 
			dwDrawMode == WINGDI) ;
		// �`�F�b�N������
		SendMessage( GetDlgItem(hwndDlg,IDC_MASKCHECK) , BM_SETCHECK , 
			( Sprites[ Viewer ].ClrKeying( )  && 
			dwDrawMode == WINGDI ? BST_CHECKED : BST_UNCHECKED ) , 0 ); 
		// �ĕ`���v��
		RedrawWindow( hwndDlg , NULL , NULL , RDW_INVALIDATE | RDW_ERASE | RDW_UPDATENOW );

		return TRUE;
	case WM_PAINT:
		if ( !Sprites[ Viewer ].IsEmpty( ) ){
			PAINTSTRUCT ps; BeginPaint( hwndDlg , &ps );

			BOOL Masking = SendMessage( GetDlgItem( hwndDlg ,IDC_MASKCHECK ) , BM_GETCHECK , 0 , 0 );
			/*-- �]����Ɠ]��������� -- */
			HDC DestDC = Sprites[ Viewer ].GetSprDC( );
			
			if ( Masking == BST_CHECKED )
				// �}�X�N�摜��\��t��
				BitBlt( ps.hdc , 0 , 25 , 
					EXPAND_SIZE( Sprites[ Viewer ].Size ),
					DestDC , 0 , 0 + Sprites[ Viewer ].Size.cy , SRCAND );
			// �]���摜��\��t��
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
