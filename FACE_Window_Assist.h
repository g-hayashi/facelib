#include "stdafx.h"
#include "FACElib.h"
#include "FACE.h"

/* -- Default -- */
#define DEF_WSTYLE	WS_VISIBLE | WS_CAPTION | WS_SYSMENU | WS_CLIPCHILDREN | WS_OVERLAPPED 
#define DEF_WCLASSSTYLE CS_DBLCLKS | CS_HREDRAW | CS_VREDRAW | CS_CLASSDC
#define DEF_WCAPTION	"FACE Library" 
#define DEF_WSIZE_W	640
#define DEF_WSIZE_H	480

typedef VOID (*SUBPROC)( int c );

#define WM_SURFACELOST ( WM_USER + 1 )
	// wParam : ����ꂽ�T�[�t�F�X�h�c

	#define RunEvent( x , Param  ) {\
		if ( lpFACE->x != NULL ) \
			( (SUBPROC)lpFACE->x )( Param );\
	}

	#define MakeEventFunc(x,y,z) \
		STDMETHODIMP CFACE::x(LONG *pVal){ *pVal = lpFACE->z; return S_OK; }\
		STDMETHODIMP CFACE::y(LONG newVal){ lpFACE->z = newVal ;return S_OK;}

#define BitMasked( API , UnAPI , Target , tfFlagment , QueryValue )\
	RECT Rect; LONG ExStyle , DefStyle , dwNum = API( hWnd , Target );\
	/* -- �X�^�C���̉��Z -- */ \
	if ( tfFlagment )	dwNum |= QueryValue; \
	else				dwNum -= ( dwNum & QueryValue ); \
	/* -- �ݒ蔽�f -- */ \
	UnAPI ( hWnd , Target , dwNum ); \
	\
	ZeroMemory( &Rect , sizeof(RECT) ); \
	GetClientRect( hWnd , &Rect );  \
	/* -- �X�^�C���擾�i�Čv�Z�p ) -- */\
	DefStyle = GetWindowLong( hWnd , GWL_STYLE );\
	ExStyle = GetWindowLong( hWnd , GWL_EXSTYLE );\
	AdjustWindowRectEx( &Rect , DefStyle , FALSE  , ExStyle ); \
	/* -- ���ۂ̕ύX -- */ \
	SetWindowPos( hWnd , NULL , 0 , 0 , \
		( Rect.right - Rect.left ) , (Rect.bottom-Rect.top) ,  \
		( ( DefStyle & WS_VISIBLE ) ? SWP_SHOWWINDOW : 0 ) | SWP_NOMOVE | SWP_FRAMECHANGED ); \
	UpdateWindow( hWnd )

#define BitCheck( API , Target , QueryValue ) \
	 ( ( API( hWnd , Target ) & QueryValue ) > 0 );

#define UnBitCheck( API , Target , QueryValue ) \
	!( ( API( hWnd , Target ) & QueryValue ) > 0 );

#define MakeStyleFunc(x,y,z)\
	STDMETHODIMP CFACE::x(BOOL *pVal){ *pVal = BitCheck( GetWindowLong , GWL_STYLE , z ); return S_OK; } \
	STDMETHODIMP CFACE::y(BOOL newVal){\
		BitMasked( GetWindowLong , SetWindowLong , GWL_STYLE , newVal , z ); \
	BOOL Reserved ;DoEvents( &Reserved );return S_OK; }

#define MakeStyleExFunc(x,y,z)\
	STDMETHODIMP CFACE::x(BOOL *pVal){ *pVal = BitCheck( GetWindowLong , GWL_EXSTYLE , z ); return S_OK; } \
	STDMETHODIMP CFACE::y(BOOL newVal){\
			BitMasked( GetWindowLong , SetWindowLong , GWL_EXSTYLE , newVal , z ); \
		BOOL Reserved;DoEvents( &Reserved );return S_OK; }


