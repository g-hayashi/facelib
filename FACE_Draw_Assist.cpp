#include "FACE_Draw_Assist.h"

/* �R���X�g���N�^ */
SPRITE::SPRITE( ){
	// �ϐ�������
	FillsNil( Size );
	FillsNil( FontSet );
		// �������
		FontSet.lfCharSet= 128; FontSet .lfHeight = 18;
		lstrcpy( FontSet.lfFaceName , _T( "�l�r �o�S�V�b�N" ) );
	DDrawSurf		=	NULL;
	CompatibleDC	=	NULL;
	CompatibleBMP	=	NULL;
	CLRKey			=	CLR_INVALID;
	dwFillStyle		=	-1 ;
	dwLineStyle		=	PS_SOLID;
}
/* -----------------
	�X�v���C�g�̍쐬
	---------------*/
void SPRITE::Make( LONG cx, LONG cy , LONG dwMode ){ 
	if ( !IsEmpty( dwMode ) ) return;
	if ( dwMode == DEFAULT ) dwMode = dwDrawMode;

	lpFACE->LogBegin( _T( "SpriteMake" ) );
	lpFACE->LogPut( CONTINUE , IDS_LOG_CREATE , this - &Sprites[ 0 ] );
	if ( dwMode == WINGDI ){
		// �݊����̂���c�b�Ƃa�l�o���쐬 
		CompatibleDC	= CreateCompatibleDC( NULL );
		CompatibleBMP	= CreateCompatibleBitmap( CompatibleDC , cx , cy * 2 ); 
		// �֘A�Â����s��
		SelectObject( CompatibleDC , CompatibleBMP );
	}else if ( dwMode == DDRAW ){
		// �T�[�t�F�X���i�[�\����
		DXObjInit( SURFACEDESC ddsd , ddsd );
		ddsd.dwFlags = DDSD_CAPS  | DDSD_WIDTH | DDSD_HEIGHT;
		ddsd.dwWidth	= cx;
		ddsd.dwHeight	= cy;
		ddsd.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN | DDSCAPS_SYSTEMMEMORY ;
		
		ObjDD->CreateSurface( &ddsd , &DDrawSurf , NULL );
	}
	lpFACE->LogPut( CONTINUE , IDS_LOG_SURFACEDESC , cx , cy  );
	// �ϐ��Z�b�g
	CLRKey = CLR_INVALID;
	Size.cx = cx ; Size.cy = cy;
	lpFACE->LogQuit( );
}
/* -----------------
	�X�v���C�g�̍폜
	---------------*/
void SPRITE::Clear( LONG dwMode ){ 
	if ( IsEmpty( dwMode ) ) return;
	if ( dwMode == DEFAULT ) dwMode = dwDrawMode;
	
	if ( dwMode == WINGDI ){
		// GDI���[�h
		DeleteObject( CompatibleBMP );	CompatibleBMP = NULL;
		DeleteDC( CompatibleDC );		CompatibleDC = NULL;
	}else if ( dwMode == DDRAW ){
		// DirectDraw ���[�h
		SAFE_RELEASE( DDrawSurf );
	}
	lpFACE->LogBegin( _T( "SpriteClear" ) );
	lpFACE->LogPut( CONTINUE , IDS_LOG_CREATE , this - &Sprites[ 0 ] );
	lpFACE->LogQuit( );
}
// ����ۂ��擾
BOOL SPRITE::IsEmpty( LONG dwMode ) {
	if ( dwMode == DEFAULT ) dwMode = dwDrawMode;
	
	return ( ( dwMode == WINGDI ? !CompatibleDC : !DDrawSurf ) );
}
// �f�o�C�X�R���e�L�X�g�擾
HDC SPRITE::GetSprDC( ){
	HDC hDC;
	if ( CompatibleDC )
		// GDI ���[�h
		hDC = CompatibleDC;
	else if ( DDrawSurf )
		// DirectDraw ���[�h
		DDrawSurf->GetDC( &hDC );
	return hDC;
}
// �f�o�C�X�R���e�L�X�g�J��
void SPRITE::EndSprDC( HDC hDC ){
	if ( DDrawSurf ) DDrawSurf->ReleaseDC( hDC );
}
DIRECTDRAWSURFACE * SPRITE::GetSurf(){return DDrawSurf;}
/* -- DirectDrawSurface����HDC�փR�s�[ -- */
BOOL SPRITE::DDSurfToGDISurf( ){
	// DirectDraw�T�[�t�F�X��������΃��^�[��
	if ( IsEmpty( DDRAW ) ) return FALSE;

	/* �݊����̂����̃T�[�t�F�X��WINGDI�ō쐬 */
	Make( Size.cx , Size.cy , WINGDI );
	
	// �������肻�̂܂܃R�s�[����
	HDC hDC;
	DDrawSurf->GetDC( &hDC );
	BitBlt( CompatibleDC , 0 , 0 , Size.cx, Size.cy , hDC , 0 , 0 , SRCCOPY );
	DDrawSurf->ReleaseDC( hDC );

	// DirectDraw�T�[�t�F�X�J��
	Clear( DDRAW );

	return TRUE;
}
/* -- GDI�̃R���p�`�u���c�b����DirectDraw�T�[�t�F�X���쐬���� -- */
BOOL SPRITE::GDISurfToDDSurf( ){
	if ( IsEmpty( WINGDI ) ) return FALSE;
	
	// �����̕K�v������
	Make( Size.cx , Size.cy  , DDRAW );

	// �������肻�̂܂܃R�s�[����
	HDC hDC;
	DDrawSurf->GetDC( &hDC );
	BitBlt( hDC , 0 , 0 , Size.cx , Size.cy  , CompatibleDC , 0 , 0 ,SRCCOPY );
	DDrawSurf->ReleaseDC( hDC );

	// WINGDI���J��
	Clear( WINGDI );
	// �J���[�L�[�K��
	SetColorKey( CLRKey );
	
	return TRUE;
}
BOOL SPRITE::SetColorKey( LONG Colors ){
	if ( Colors == CLR_INVALID )return TRUE;

	// �}�X�N��s���̈�ɍ쐬
	// DirectDraw�́A�J���[�L�[�Z�b�e�B���O
	if ( CompatibleDC ){
		for ( int j = 0 ; j < Size.cy ; j++ ){
			for ( int i = 0 ; i < Size.cx ; i++ ){
				LONG src = GetPixel( CompatibleDC , i , j );

				// ��ʏ㔼���͌��摜�i�J���[�L�[�ɂ������F�͍��ցA����ȊO��continue)
				if ( src == Colors )
					SetPixelV( CompatibleDC , i , j , 0x0 );
				// ��ʉ������̓}�X�N���̉摜
				SetPixelV( CompatibleDC , i , Size.cy + j , 
					( src == Colors ? 0xFFFFFF : 0x0 ) );
			}
		}
	}else if ( DDrawSurf ){
		HDC hDC ;SURFACEDESC ddsd; COLORREF PrevClr ; DWORD PhysicalClr;
		
		// GDI�ŁA�܂��͓_��ł�
		DDrawSurf->GetDC( &hDC );
		PrevClr = GetPixel( hDC , 0 , 0 );
		SetPixelV( hDC , 0 , 0 , Colors );
		DDrawSurf->ReleaseDC( hDC );

		// Lock���s���A���ڃA�N�Z�X�B�����F�̎擾
		ZeroMemory( &ddsd , sizeof(ddsd) );ddsd.dwSize = sizeof( ddsd );
		while ( DDrawSurf->Lock( NULL, &ddsd, 0, NULL)  == DDERR_WASSTILLDRAWING );
		PhysicalClr = *( DWORD * )ddsd.lpSurface;	// �擾
		// Mask
		if ( ddsd.ddpfPixelFormat.dwRGBBitCount < 32 ) 
			PhysicalClr &= (1 << ddsd.ddpfPixelFormat.dwRGBBitCount) - 1;
		DDrawSurf->Unlock( NULL );

		// ���̐F�����X�g�A
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
