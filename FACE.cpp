// FACE.cpp : CFACE �̃C���v�������e�[�V����
#include "stdafx.h"
#include "FACElib.h"
#include "FACE.h"

/* -------------
	�R���X�g���N�^
  --------------*/
class	CFACE *lpFACE;
TCHAR	FACEDir[ MAX_PATH ] , FACELogFile[ MAX_PATH ] ;

CFACE::CFACE( ){
	// ������`�`�F�b�N
	if ( lpFACE ){
		ExitProcess(0);
	}
	// FACE�ϐ����������s��
	hWnd = NULL ; StartTick = 0 ; EndFlag = FALSE ;
	// DirectX Objects
	DrawClear( );
	SoundClear( );
	// �N���A�B�I�u�W�F�N�g
	/* -- �ϐ��ݒ� -- */
		// FACE�A�h���X���Z�b�g	
		lpFACE = this;
		// �J�E���^�[��������
		StartTick = timeGetTime( );
			wProcedure  = OnSurfaceLost = NULL;
	/* Get FACEDir */
	DWORD	ptSize = MAX_PATH;
	ZeroMemory( FACEDir , MAX_PATH );
	HKEY hKey; // Registry�A�N�Z�X
	RegOpenKeyEx( HKEY_CURRENT_USER , 
		"Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Shell Folders" , 
		0 , KEY_READ , &hKey );
	RegQueryValueEx( hKey , "Local AppData" , 0 , NULL , (BYTE*)FACELogFile , &ptSize );
	RegCloseKey( hKey );
	// �t�F�[�X���[�U�[�t�H���_���쐬���A����
	wsprintf( FACEDir , _T("%s\\%s") , FACELogFile ,_T( "FACEDir" ) );
	CreateDirectory( FACEDir , NULL );
	wsprintf( FACELogFile , "%s\\FACE.log" , FACEDir );
	DeleteFile( FACELogFile );
}
/* -------------
	�f�X�g���N�^
  --------------*/
CFACE::~CFACE( ){ Release( ); }
ULONG CFACE::Release( ){
	if ( !lpFACE )return 0;
	// ���O�A�E�g
	LogBegin( "FACE FinallyCall" );
 
	mciSendString( _T( "close all" ) , NULL , 0 , NULL );
	// �^�C�}�[�����i�����Ă����
	KillTimer( hWnd , 4 );
	// �I�u�W�F�N�g�������
	DrawRelease( ); SoundRelease( );
	
	// FACE���N���A
	lpFACE = NULL; 
	
	LogQuit( );
	return 0;
}
/* ------------------
	���O�A�E�g
	-----------------*/
void CFACE::LogBegin( TCHAR * lpStr ){
	// �G���[�A�E�g�p�o�b�t�@
	TCHAR lpBuf[ 1024 ];
	// �������X�g����printf���s��
	wsprintf( lpBuf , _T( "%s" ) , lpStr );
	// �t�@�C�����J���i�ǋL���[�h
	FILE *fp = fopen( FACELogFile , "a" );
	// �t�@�C���Ƀ��M���O(+���s)
	fwrite( lpBuf , sizeof( char ) , lstrlen( lpBuf ) , fp ); 
	// �C���q
	fwrite( "\n" , 1 , 1 , fp );
	// �t�@�C�������
	fclose( fp );
}
void CFACE::LogPut( BOOL Fatal , LONG uID ,  ... ){
	// �G���[�A�E�g�p�o�b�t�@
	TCHAR lpBuf[ 1024 ] , lpFormat[ 256 ];
	// Format�擾
	LoadString( (HINSTANCE)GetWindowLong( lpFACE->hWnd , GWL_HINSTANCE ), uID , 
		lpFormat , 255 );
	// �������X�g����printf���s��
	va_list va; va_start( va , uID );	
	vsprintf( lpBuf , lpFormat , va );
	// �t�@�C�����J���i�ǋL���[�h
	FILE *fp = fopen( FACELogFile , "a" );
	// �t�@�C���Ƀ��M���O(+���s)
	fwrite( lpBuf , sizeof( char ) , lstrlen( lpBuf ) , fp ); 
	// �C���q
	fwrite( "\n" , 1 , 1 , fp );
	// �t�@�C�������
	fclose( fp );
	if ( Fatal == FATAL ){
		MessageBox( hWnd , "�v���I�G���[", "FATAL END" , 0 );
		Release( ); \
		ExitProcess( 0 );
	}
}
void CFACE::LogQuit( ){
	// �t�@�C�����J���i�ǋL���[�h
	FILE *fp = fopen( FACELogFile , "a" );
	// �C���q
	fwrite( "\n" , 1 , 1 , fp );
	// �t�@�C�������
	fclose( fp );
}
BOOL CFACE::GetFilePath( TCHAR *FileName , TCHAR *lpPath ){
	TCHAR PathBuffer[ MAX_PATH ];
	lstrcpy( PathBuffer , FileName );
	// �܂��̓��[�J������T��
	FILE *fp = fopen( PathBuffer , _T( "rb" ) );
	if ( fp == NULL ){
		// FACE���[�U�[�f�B���N�g������
		wsprintf( PathBuffer , _T( "%s\\%s" ) , FACEDir , FileName );
		fp = fopen( PathBuffer , _T( "rb" ) );
		if ( fp == NULL )
			return FALSE;
	}
	fclose( fp );
	lstrcpy( lpPath , PathBuffer );

	return TRUE;
}
STDMETHODIMP CFACE::GetFACEVer( LONG *Ret ){
	*Ret = MAKELONG( 1 , MAKEWORD( 0 , 1 ) );
	
	return S_OK;
}
STDMETHODIMP CFACE::InterfaceSupportsErrorInfo(REFIID riid){
	static const IID* arr[] = { &IID_IFACE };
	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}
