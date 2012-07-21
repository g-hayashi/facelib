/* -----------------------------------------

		‚e‚`‚b‚d@“ü—Í‹@”\

  --------------------------------------- */
#include "stdafx.h"
#include "FACElib.h"
#include "FACE.h"

/* ------------------ ƒ}ƒEƒX‚w@-------------------- */
STDMETHODIMP CFACE::get_MouseX(LONG *pVal){
	POINT pt; 
	GetCursorPos( &pt ) ; ScreenToClient( hWnd, &pt );

	*pVal = pt.x;

	return S_OK;
}
STDMETHODIMP CFACE::put_MouseX(LONG newVal){
	POINT pt = { newVal , 0 } , yP; 
	GetCursorPos( &yP ) ; ScreenToClient(  hWnd , &yP );
	ClientToScreen( hWnd , &pt );

	SetCursorPos( pt.x , yP.y );

	return S_OK;
}
/* ------------------ ƒ}ƒEƒX‚x@-------------------- */
STDMETHODIMP CFACE::get_MouseY(LONG *pVal){
	POINT pt; 
	GetCursorPos( &pt ) ; ScreenToClient(  hWnd ,  &pt );

	*pVal = pt.y;

	return S_OK;
}
STDMETHODIMP CFACE::put_MouseY(LONG newVal){
	POINT pt = { 0 , newVal } , xP; 
	ClientToScreen( hWnd , &pt );
	GetCursorPos( &xP ) ; ScreenToClient(  hWnd ,&xP );

	SetCursorPos( xP.x  , pt.y );

	return S_OK;
}
STDMETHODIMP CFACE::InCheck( short KeyCode , BOOL *pval ){
	*pval = HIBYTE( GetAsyncKeyState( KeyCode ) ) > 0;

	return S_OK;
}
STDMETHODIMP CFACE::InCheckPrev( short KeyCode , BOOL *pval ){
	*pval = LOBYTE( GetAsyncKeyState( KeyCode ) ) > 0;

	return S_OK;
}
