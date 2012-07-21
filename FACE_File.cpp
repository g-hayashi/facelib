#include "stdafx.h"
#include "FACElib.h"
#include "FACE.h"
#pragma comment(lib,"wininet.lib")
#include <wininet.h>

TCHAR  WritingPath[ MAX_PATH ];

STDMETHODIMP CFACE::fOpen( BSTR FName ){
	USES_CONVERSION;
	//　書き込みファイル名生成
	wsprintf( WritingPath , _T( "%s\\%s.FACEDat" ) , FACEDir , OLE2T( FName ) );
	LogBegin( "fOpenMethod" );
	LogPut( CONTINUE , IDS_LOG_FILEIO , WritingPath );
	// オープン
	HANDLE hFile;
	if ( NULL == ( hFile = CreateFile( WritingPath , GENERIC_WRITE , 0 , NULL , OPEN_ALWAYS , 
		FILE_ATTRIBUTE_NORMAL , NULL ) ) )
			LogPut( FATAL , IDS_ERR_INVALIDFILE );
	CloseHandle( hFile );

	return S_OK;
}



STDMETHODIMP CFACE::fClear( ){
	LogBegin( "fClearMethod" );
	LogPut( CONTINUE , IDS_LOG_FILEIO , WritingPath );
	HANDLE hFile;
	if ( NULL == ( hFile = CreateFile( WritingPath , GENERIC_WRITE , 0 , NULL , CREATE_ALWAYS, 
		FILE_ATTRIBUTE_NORMAL , NULL ) )) 
		LogPut( FATAL , IDS_ERR_INVALIDFILE );
	CloseHandle( hFile );

	return S_OK;
}

/* ---------------------------- FILE IO ----------------------------------*/
STDMETHODIMP CFACE::fReadInteger( BSTR Category, BSTR KeyName, LONG Defaults , LONG *pVal){
	USES_CONVERSION;

	*pVal = GetPrivateProfileInt( OLE2T( Category ) , OLE2T( KeyName ) , Defaults , WritingPath );

	return S_OK;
}

STDMETHODIMP CFACE::fReadString( BSTR Category, BSTR KeyName, BSTR Default, BSTR lpBuffer ){
	USES_CONVERSION;

	GetPrivateProfileString( OLE2T( Category ) , OLE2T( KeyName ) , OLE2T( Default ) , 
		OLE2T( lpBuffer ) , 256 , WritingPath );

	return S_OK;
}

STDMETHODIMP CFACE::fWriteInteger( BSTR Category, BSTR KeyName, LONG Data){	
	USES_CONVERSION;

	TCHAR DataString[ 256 ] ; ZeroMemory( DataString , sizeof(DataString) );
	wsprintf( DataString , _T( "%l" ) , Data );
	
	if ( !WritePrivateProfileString( OLE2T( Category ), OLE2T( KeyName ) , DataString , WritingPath ) )
		LogPut( FATAL , IDS_ERR_INVALIDFILE );

	return S_OK;
}
STDMETHODIMP CFACE::fWriteString( BSTR Category, BSTR KeyName, BSTR Data){
	USES_CONVERSION;

	if ( !WritePrivateProfileString( OLE2T( Category ), OLE2T( KeyName ) , OLE2T( Data ) , WritingPath ) )
		LogPut( FATAL , IDS_ERR_INVALIDFILE );

	return S_OK;
}


INT_PTR CALLBACK DownLoadProc( HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM ){
	return FALSE;

}
STDMETHODIMP CFACE::Download( BSTR URL, BSTR DownloadFile ){
	
	USES_CONVERSION;

	HANDLE hFile; TCHAR DownloadTo[ MAX_PATH ] , TXT[ 256 ] ;
	HWND hDialog;

	LogBegin( "File Download Method" );
	LogPut( CONTINUE , IDS_LOG_DOWNLOAD , URL );
	// ユーザーフォルダ名を取得
	// ダイアログの作成
	hDialog = CreateDialog( hInst ,MAKEINTRESOURCE( IDD_DownLoading ) , 
		hWnd , (DLGPROC)DownLoadProc );
	wsprintf( TXT , _T( "%s \nDown To : %s " ) , OLE2T( URL ) , OLE2T( DownloadFile ) );
	SetWindowText( GetDlgItem( hDialog , IDC_Down ) ,TXT );
	// そこに、ファイル名を追加することで、ダウンロード先の完成
	wsprintf( DownloadTo , _T( "%s\\%s" ) , FACEDir , OLE2T( DownloadFile ) );
	
    // ダウンロードを行う関数をロード
	DWORD dwBytesWrite , dwBytesRead , dwBytesAvailable , dwTotalRead = 0; 
	BYTE *Buffer;
	
	// ＤＬＬ関数初期化
	HANDLE hInternet = InternetOpen( 
				_T( "FACE Download Method" ) , 
				INTERNET_OPEN_TYPE_PRECONFIG , NULL , NULL , 0 ) , 
			hInternetFile = InternetOpenUrl( hInternet , OLE2T( URL ) , NULL , 0 ,0 , 0 );
	LogPut( CONTINUE , IDS_LOG_DOWNLOAD , OLE2T( URL ) );

	if ( hInternet == NULL || hInternetFile == NULL )
		LogPut( FATAL , IDS_ERR_CANTDOWNLOAD );

	// 最適サイズ取得
	InternetQueryDataAvailable( hInternetFile , &dwBytesAvailable, 0, 0 );
	Buffer = (BYTE*)malloc( dwBytesAvailable + 1 );
	// タイムアウト設定
	DWORD TimeOut;
	TimeOut = 30 * 1000;  // ここでは30秒に指定しています。
	InternetSetOption( hInternetFile, INTERNET_OPTION_RECEIVE_TIMEOUT,  &TimeOut, sizeof(TimeOut) );

	// インターネットファイルの更新日時をクエリー
	SYSTEMTIME LastModified;
	dwBytesRead = sizeof(LastModified);
	HttpQueryInfo( hInternetFile , HTTP_QUERY_LAST_MODIFIED  | HTTP_QUERY_FLAG_SYSTEMTIME 
		, &LastModified , &dwBytesRead , 0 );
	// ファイルがすでにある場合は更新日時をチェック
	if ( ( hFile = CreateFile( DownloadTo , GENERIC_WRITE , 0 , NULL , 
		OPEN_EXISTING , FILE_ATTRIBUTE_NORMAL , NULL  ) ) != INVALID_HANDLE_VALUE ){
			// 更新日時の比較
		FILETIME ft2,ft1;
		SystemTimeToFileTime( &LastModified , &ft2 );
		FileTimeToLocalFileTime( &ft2 , &ft1 );
		GetFileTime( hFile , NULL , NULL , &ft2 );
		CloseHandle( hFile );
	}
	
	hFile = CreateFile( DownloadTo , GENERIC_WRITE , 0 , NULL , 
		CREATE_ALWAYS , FILE_ATTRIBUTE_NORMAL , NULL  );

	LONG x = -40 , ax = 1; // Progressing

	do{
		ZeroMemory( Buffer , sizeof(Buffer) );
		// ダウンロード
		InternetReadFile( hInternetFile , Buffer , dwBytesAvailable , &dwBytesRead );
		sprintf( TXT , _T( 
			" 最適レート / 実ダウン : %d / %d Bytes" ) , 
			dwBytesAvailable , dwBytesRead );
		SetWindowText( GetDlgItem( hDialog , IDC_Down3 ) , TXT );

		/* -- ダウンロード総容量の表示 -- */
		dwTotalRead += dwBytesRead;
		if ( dwTotalRead < 1000000 )
			sprintf( TXT , _T( 
			" ダウンロード済みサイズ : %.3g KBytes" ) , 
				(double)dwTotalRead / 1024 );
		else
			sprintf( TXT , _T( 
			" ダウンロード済みサイズ : %.3g MBytes " ) , 
				(double)dwTotalRead / 1024 / 1024 );
		SetWindowText( GetDlgItem( hDialog , IDC_Down2 ) , TXT );

		// ダウンロード進行を示す プログレス
		x += ax; 
		HDC hDC = GetDC( GetDlgItem( hDialog , IDC_PROGRESS1 ) );
		RECT RT ;
		GetClientRect( GetDlgItem( hDialog , IDC_PROGRESS1 ) ,  &RT );
		if ( x < RT.left- 40 || x > RT.right + 30 ) ax *= -1;
		FillRect( hDC , &RT , (HBRUSH)( COLOR_BTNFACE + 1 ) );
		
		SetRect( &RT, x , 0 , x + 30 , 10 );
		FillRect( hDC , &RT , (HBRUSH)( COLOR_ACTIVECAPTION + 1 ) );
		ReleaseDC(  GetDlgItem( hDialog , IDC_PROGRESS1 ) , hDC );

		Buffer [ dwBytesRead ] = 0;
		WriteFile( hFile , Buffer , dwBytesRead , &dwBytesWrite , NULL );

		BOOL END; DoEvents( &END );if (END)break;
	}while ( dwBytesRead > 0 );

	InternetCloseHandle( hInternetFile );
	InternetCloseHandle( hInternet );
	
	CloseHandle( hFile );
	DestroyWindow( hDialog );

	LogQuit( );

	return S_OK;
}
