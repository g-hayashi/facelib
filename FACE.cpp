// FACE.cpp : CFACE のインプリメンテーション
#include "stdafx.h"
#include "FACElib.h"
#include "FACE.h"

/* -------------
	コンストラクタ
  --------------*/
class	CFACE *lpFACE;
TCHAR	FACEDir[ MAX_PATH ] , FACELogFile[ MAX_PATH ] ;

CFACE::CFACE( ){
	// 複数定義チェック
	if ( lpFACE ){
		ExitProcess(0);
	}
	// FACE変数初期化を行う
	hWnd = NULL ; StartTick = 0 ; EndFlag = FALSE ;
	// DirectX Objects
	DrawClear( );
	SoundClear( );
	// クリア。オブジェクト
	/* -- 変数設定 -- */
		// FACEアドレスをセット	
		lpFACE = this;
		// カウンターを初期化
		StartTick = timeGetTime( );
			wProcedure  = OnSurfaceLost = NULL;
	/* Get FACEDir */
	DWORD	ptSize = MAX_PATH;
	ZeroMemory( FACEDir , MAX_PATH );
	HKEY hKey; // Registryアクセス
	RegOpenKeyEx( HKEY_CURRENT_USER , 
		"Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Shell Folders" , 
		0 , KEY_READ , &hKey );
	RegQueryValueEx( hKey , "Local AppData" , 0 , NULL , (BYTE*)FACELogFile , &ptSize );
	RegCloseKey( hKey );
	// フェースユーザーフォルダを作成し、完了
	wsprintf( FACEDir , _T("%s\\%s") , FACELogFile ,_T( "FACEDir" ) );
	CreateDirectory( FACEDir , NULL );
	wsprintf( FACELogFile , "%s\\FACE.log" , FACEDir );
	DeleteFile( FACELogFile );
}
/* -------------
	デストラクタ
  --------------*/
CFACE::~CFACE( ){ Release( ); }
ULONG CFACE::Release( ){
	if ( !lpFACE )return 0;
	// ログアウト
	LogBegin( "FACE FinallyCall" );
 
	mciSendString( _T( "close all" ) , NULL , 0 , NULL );
	// タイマー消去（動いていれば
	KillTimer( hWnd , 4 );
	// オブジェクト解放処理
	DrawRelease( ); SoundRelease( );
	
	// FACEをクリア
	lpFACE = NULL; 
	
	LogQuit( );
	return 0;
}
/* ------------------
	ログアウト
	-----------------*/
void CFACE::LogBegin( TCHAR * lpStr ){
	// エラーアウト用バッファ
	TCHAR lpBuf[ 1024 ];
	// 引数リストからprintfを行う
	wsprintf( lpBuf , _T( "%s" ) , lpStr );
	// ファイルを開く（追記モード
	FILE *fp = fopen( FACELogFile , "a" );
	// ファイルにロギング(+改行)
	fwrite( lpBuf , sizeof( char ) , lstrlen( lpBuf ) , fp ); 
	// 修飾子
	fwrite( "\n" , 1 , 1 , fp );
	// ファイルを閉じる
	fclose( fp );
}
void CFACE::LogPut( BOOL Fatal , LONG uID ,  ... ){
	// エラーアウト用バッファ
	TCHAR lpBuf[ 1024 ] , lpFormat[ 256 ];
	// Format取得
	LoadString( (HINSTANCE)GetWindowLong( lpFACE->hWnd , GWL_HINSTANCE ), uID , 
		lpFormat , 255 );
	// 引数リストからprintfを行う
	va_list va; va_start( va , uID );	
	vsprintf( lpBuf , lpFormat , va );
	// ファイルを開く（追記モード
	FILE *fp = fopen( FACELogFile , "a" );
	// ファイルにロギング(+改行)
	fwrite( lpBuf , sizeof( char ) , lstrlen( lpBuf ) , fp ); 
	// 修飾子
	fwrite( "\n" , 1 , 1 , fp );
	// ファイルを閉じる
	fclose( fp );
	if ( Fatal == FATAL ){
		MessageBox( hWnd , "致命的エラー", "FATAL END" , 0 );
		Release( ); \
		ExitProcess( 0 );
	}
}
void CFACE::LogQuit( ){
	// ファイルを開く（追記モード
	FILE *fp = fopen( FACELogFile , "a" );
	// 修飾子
	fwrite( "\n" , 1 , 1 , fp );
	// ファイルを閉じる
	fclose( fp );
}
BOOL CFACE::GetFilePath( TCHAR *FileName , TCHAR *lpPath ){
	TCHAR PathBuffer[ MAX_PATH ];
	lstrcpy( PathBuffer , FileName );
	// まずはローカルから探す
	FILE *fp = fopen( PathBuffer , _T( "rb" ) );
	if ( fp == NULL ){
		// FACEユーザーディレクトリから
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
