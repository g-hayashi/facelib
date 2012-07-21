/* -----------------------------------------

		ＦＡＣＥ　ウインドウ機能

  --------------------------------------- */
#include "FACE_Window_Assist.h"

/* -------------
	ウインドウ作成関数
	--------------*/
STDMETHODIMP CFACE::wDefault( BSTR ProgramName ){
	// 文字列変換マクロ使用
	USES_CONVERSION;
	// Release多重コール＝無視
	if ( hWnd != NULL ) 
		LogPut( FATAL , IDS_ERR_MULTI );
	// ウインドウ作成開始
	LogBegin( "Windows Maker" );

	/* -- Class Regist -- */
	WNDCLASSEX wcex;
	wcex.cbSize			= sizeof( WNDCLASSEX );
	wcex.style			= DEF_WCLASSSTYLE;
	wcex.lpfnWndProc	= DefWndProc;
	wcex.cbClsExtra		= wcex.cbWndExtra = 0;
	wcex.hInstance		= hInst;
	wcex.hIcon			= wcex.hIconSm = LoadIcon( NULL , IDI_APPLICATION );
	wcex.hCursor		= LoadCursor( NULL, IDC_ARROW );
	wcex.hbrBackground	= ( HBRUSH )( COLOR_BTNFACE + 1 );
	wcex.lpszMenuName	= NULL;
	wcex.lpszClassName	= OLE2T( ProgramName );
	RegisterClassEx( &wcex );
	/* -- ウインドウ精製時のサイズを計算 -- */
	RECT Rect; SetRect( &Rect, 0 , 0 , DEF_WSIZE_W , DEF_WSIZE_H );
	AdjustWindowRect( &Rect ,  DEF_WSTYLE , FALSE );
	/* -- ウインドウを作成 -- */
	if ( ( hWnd = CreateWindowEx( 0 , 
			OLE2T( ProgramName ) ,
			OLE2T( ProgramName ) ,	/* タイトル */
			DEF_WSTYLE,
			CW_USEDEFAULT  , CW_USEDEFAULT  ,	/* Position (x,y) is Default */
			Rect.right - Rect.left , Rect.bottom  - Rect.top ,
			NULL  , NULL ,	/* 親ウインドウのハンドル（なし)、メニューID */
			hInst , NULL	/* WS_CREATE SendWith */
		) ) == NULL )
			LogPut( FATAL , IDS_ERR_HWND );
	// 表示と画面更新
	ShowWindow( hWnd , SW_SHOWNORMAL ); UpdateWindow( hWnd );
	Screen.cx=DEF_WSIZE_W;Screen.cy=DEF_WSIZE_H;
	LogQuit( );
	
	return S_OK;
}
/* -------------
	メッセージ処理ルーチン
	--------------*/
STDMETHODIMP CFACE::Run( ){
	MSG msg; 
	while ( GetMessage( &msg , NULL , 0 , 0 ) > 0 ){
		// メッセージをディスパッチ
		TranslateMessage( &msg );
		DispatchMessage( &msg );
		if ( EndFlag )break;
	}

	return S_OK;
}
/* -------------
	メッセージ処理ルーチン
	--------------*/
STDMETHODIMP CFACE::DoEvents( BOOL *pVal ){
	MSG msg;

	while ( PeekMessage( &msg , NULL , 0 , 0 , PM_REMOVE ) ){
		// メッセージをディスパッチ
		TranslateMessage( &msg );
		DispatchMessage( &msg );
	}
	*pVal = EndFlag;

	return S_OK;
}
/* -------------
	FACEを終了させる
	--------------*/
STDMETHODIMP CFACE::wDestroy( ){
	// ウインドウを除去
	PostQuitMessage( 0 );
	EndFlag = 1;

	return S_OK;
}
/* -------------
	FACEの起動時間を取得
	--------------*/
STDMETHODIMP CFACE::GetTick(LONG *pVal){
	*pVal =  timeGetTime() - StartTick;

	return S_OK;
}
/* -----------------
	Tickリセット
	--------------*/
STDMETHODIMP CFACE::TickReset(){
	StartTick = timeGetTime( );
	return S_OK;
}
/* -------------
	FACEのハンドル
	--------------*/
STDMETHODIMP CFACE::wGetHandle(LONG *pVal){
	*pVal = (LONG)hWnd;
	return S_OK;
}
/* ------------------ 
	表示属性 
	---------------------*/
STDMETHODIMP CFACE::get_wVisible(BOOL *pVal){
	*pVal = UnBitCheck( GetWindowLong , GWL_STYLE , WS_VISIBLE );
	return S_OK;
}
STDMETHODIMP CFACE::put_wVisible(BOOL newVal){
	ShowWindow( hWnd , newVal ? SW_SHOW : SW_HIDE );
	BitMasked( GetWindowLong , SetWindowLong , GWL_STYLE , 
		newVal , WS_VISIBLE );
	return S_OK;
}
/* -----------------
		 有効属性
---------------------------*/
STDMETHODIMP CFACE::get_wEnable(BOOL *pVal){
	*pVal = UnBitCheck( GetWindowLong , GWL_STYLE , WS_DISABLED );

	return S_OK;
}
STDMETHODIMP CFACE::put_wEnable(BOOL newVal){
	BitMasked( GetWindowLong , SetWindowLong , GWL_STYLE , 
		!newVal , WS_DISABLED );

	return S_OK;
}
/* -----------ボタン表示属性属性---------------------------*/
STDMETHODIMP CFACE::get_wHasCloseBtn(BOOL *pVal){
	*pVal = BitCheck( GetClassLong , CS_NOCLOSE , CS_NOCLOSE );

	return S_OK;
}
STDMETHODIMP CFACE::put_wHasCloseBtn(BOOL newVal){
	BitMasked( GetClassLong , SetClassLong , GCL_STYLE , 
		newVal , CS_NOCLOSE );

	return S_OK;
}
/* -----------ボタン表示属性属性---------------------------*/
MakeStyleFunc( get_wHasMaxBtn , put_wHasMaxBtn , WS_MAXIMIZEBOX )
MakeStyleFunc( get_wHasMinBtn , put_wHasMinBtn , WS_MINIMIZEBOX )
MakeStyleFunc( get_wHasTitleBar , put_wHasTitleBar , WS_CAPTION )
MakeStyleFunc( get_wHasBorder , put_wHasBorder, WS_BORDER )
MakeStyleFunc( get_wResizeable , put_wResizeable , WS_SIZEBOX )
MakeStyleExFunc( get_wTopMost , put_wTopMost , WS_EX_TOPMOST )

STDMETHODIMP CFACE::put_wCaption( BSTR newVal){
	USES_CONVERSION;

	SetWindowText( hWnd , OLE2T(newVal) );
	return S_OK;
}
/* -------------移動 ----------------------*/
STDMETHODIMP CFACE::wMoveTo(LONG x, LONG y){
	SetWindowPos( hWnd , NULL , x , y , 0 , 0 , SWP_SHOWWINDOW | SWP_NOSIZE );

	return S_OK;
}

STDMETHODIMP CFACE::wMoveBy(LONG x, LONG y){
		/* 相対のため、今の基点を取得 */
	RECT Rect ; ZeroMemory( &Rect , sizeof(Rect) );
	GetWindowRect( hWnd , &Rect );
	SetWindowPos( hWnd , NULL , Rect.left + x , Rect.top + y , 
		0 , 0 , SWP_SHOWWINDOW | SWP_NOSIZE );

	return S_OK;
}
/* --------- サイズ変更 ( Toは、絶対指定 Byは、相対指定)---------- */
STDMETHODIMP CFACE::wResizeTo( LONG w, LONG h ){
	RECT Rect;  SetRect( &Rect , 0  , 0 , w , h );

	SetWindowPos( hWnd , NULL , 0 , 0 ,
		(Rect.right-Rect.left) , (Rect.bottom-Rect.top) ,
		SWP_SHOWWINDOW | SWP_NOMOVE | SWP_FRAMECHANGED );

	return S_OK;
}
STDMETHODIMP CFACE::wResizeBy( LONG w, LONG h){
		/* 相対のため、今の基点を取得 */
	RECT Rect;ZeroMemory( &Rect , sizeof(Rect) );
	GetWindowRect( hWnd, &Rect );
	SetWindowPos( hWnd , NULL , 0 , 0 ,
		Rect.right - Rect.left + w , Rect.bottom - Rect.top  + h,
		SWP_SHOWWINDOW | SWP_NOMOVE );
	GetClientRect( hWnd , &Rect );

	return S_OK;
}

/* ------------- メッセージボックス -----------*/
STDMETHODIMP CFACE::wShowMessage( BSTR Prompt , BSTR Caption ){
	USES_CONVERSION;

	MessageBox( hWnd , OLE2T( Prompt ) , OLE2T( Caption ) , MB_ICONQUESTION );

	return S_OK;
}
/* ------------- メッセージボックス -----------*/
STDMETHODIMP CFACE::wYesNoMessage( BSTR Prompt, BSTR Caption, BOOL *Result){
	USES_CONVERSION;

	*Result =  MessageBox( hWnd , OLE2T( Prompt ) , OLE2T( Caption ) , 
		MB_YESNO | MB_ICONINFORMATION ) == IDYES;

	return S_OK;
}
LONG wProcedure ,OnSurfaceLost;
/* -- タイマー -- */
STDMETHODIMP CFACE::wRunTimer( LONG longerval ){
	// 今あるタイマーを除去
	KillTimer( hWnd , 4 );
	// 新たにセット
	SetTimer( hWnd , 4 , longerval , NULL );
	return S_OK;
}
MakeEventFunc( get_wProcedure,put_wProcedure,wProcedure )
MakeEventFunc( get_OnSurfaceLost , put_OnSurfaceLost , OnSurfaceLost )

LRESULT CALLBACK CFACE::DefWndProc( HWND wnd , UINT Message , WPARAM wParam, LPARAM lParam) {
	LRESULT  Ret = 0;
	
	if ( lpFACE->wProcedure ){
		Ret = ((WNDPROC)lpFACE->wProcedure)( wnd , Message, wParam, lParam  );
		return Ret;
	}
	switch (Message){
		case WM_SIZE:
			Receive( LOWORD( lParam ) , HIWORD( wParam ) );
			break;
		case WM_DESTROY:
			lpFACE->EndFlag = 1;
			break;
		case WM_SURFACELOST:
			RunEvent( OnSurfaceLost , wParam);
			break;
		default:
			return DefWindowProc( wnd , Message , wParam , lParam );
	}
	return DefWindowProc( wnd , Message , wParam , lParam );
}
