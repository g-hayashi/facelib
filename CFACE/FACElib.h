/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Fri May 21 23:42:02 2004
 */
/* Compiler settings for D:\My Programming\FACE Library\FACElib\FACElib.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __FACElib_h__
#define __FACElib_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IFACE_FWD_DEFINED__
#define __IFACE_FWD_DEFINED__
typedef interface IFACE IFACE;
#endif 	/* __IFACE_FWD_DEFINED__ */


#ifndef __FACE_FWD_DEFINED__
#define __FACE_FWD_DEFINED__

#ifdef __cplusplus
typedef class FACE FACE;
#else
typedef struct FACE FACE;
#endif /* __cplusplus */

#endif 	/* __FACE_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __IFACE_INTERFACE_DEFINED__
#define __IFACE_INTERFACE_DEFINED__

/* interface IFACE */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IFACE;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8F67CBF4-A0A3-4144-9985-AEF9623FD317")
    IFACE : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE wDefault( 
            /* [in] */ BSTR ProgramName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Run( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DoEvents( 
            /* [retval][out] */ BOOL __RPC_FAR *StillRunning) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE wGetHandle( 
            /* [retval][out] */ LONG __RPC_FAR *HandleToWindow) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE wResizeTo( 
            /* [in] */ LONG w,
            /* [in] */ LONG h) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE wResizeBy( 
            /* [in] */ LONG rw,
            /* [in] */ LONG rh) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE wMoveTo( 
            /* [in] */ LONG x,
            /* [in] */ LONG y) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE wMoveBy( 
            /* [in] */ LONG rx,
            /* [in] */ LONG ry) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE wShowMessage( 
            /* [in] */ BSTR Message,
            /* [in] */ BSTR Caption) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE wYesNoMessage( 
            /* [in] */ BSTR Message,
            /* [in] */ BSTR Caption,
            /* [retval][out] */ BOOL __RPC_FAR *YesNo) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_wCaption( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_wVisible( 
            /* [retval][out] */ BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_wVisible( 
            /* [in] */ BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_wEnable( 
            /* [retval][out] */ BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_wEnable( 
            /* [in] */ BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_wHasMaxBtn( 
            /* [retval][out] */ BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_wHasMaxBtn( 
            /* [in] */ BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_wHasMinBtn( 
            /* [retval][out] */ BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_wHasMinBtn( 
            /* [in] */ BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_wHasCloseBtn( 
            /* [retval][out] */ BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_wHasCloseBtn( 
            /* [in] */ BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_wHasTitleBar( 
            /* [retval][out] */ BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_wHasTitleBar( 
            /* [in] */ BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_wResizeable( 
            /* [retval][out] */ BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_wResizeable( 
            /* [in] */ BOOL newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE wRunTimer( 
            /* [in] */ LONG Interval,
            /* [in] */ LONG Event) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetTick( 
            /* [retval][out] */ LONG __RPC_FAR *Tick) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OnActive( 
            /* [retval][out] */ LONG __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_OnActive( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OnDeActive( 
            /* [retval][out] */ LONG __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_OnDeActive( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OnKeyDown( 
            /* [retval][out] */ LONG __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_OnKeyDown( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OnKeyUp( 
            /* [retval][out] */ LONG __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_OnKeyUp( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OnCommand( 
            /* [retval][out] */ LONG __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_OnCommand( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OnMouseDown( 
            /* [retval][out] */ LONG __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_OnMouseDown( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OnMouseUp( 
            /* [retval][out] */ LONG __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_OnMouseUp( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OnMouseWheel( 
            /* [retval][out] */ LONG __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_OnMouseWheel( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OnMove( 
            /* [retval][out] */ LONG __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_OnMove( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OnMoving( 
            /* [retval][out] */ LONG __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_OnMoving( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OnSize( 
            /* [retval][out] */ LONG __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_OnSize( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OnSizing( 
            /* [retval][out] */ LONG __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_OnSizing( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_wProcedure( 
            /* [retval][out] */ LONG __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_wProcedure( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE wDestroy( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_wHasBorder( 
            /* [retval][out] */ BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_wHasBorder( 
            /* [in] */ BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_wToolWin( 
            /* [retval][out] */ BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_wToolWin( 
            /* [in] */ BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_wTopMost( 
            /* [retval][out] */ BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_wTopMost( 
            /* [in] */ BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SoftwareFPS( 
            /* [retval][out] */ LONG __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SoftwareFPS( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_KeepFPS( 
            /* [retval][out] */ BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Blt( 
            /* [in] */ LONG FromID,
            /* [in] */ LONG FromX,
            /* [in] */ LONG FromY,
            /* [in] */ LONG w,
            /* [in] */ LONG h,
            /* [in] */ LONG ToID,
            /* [in] */ LONG ToX,
            /* [in] */ LONG ToY) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE BltStretch( 
            /* [in] */ LONG FromID,
            /* [in] */ LONG FromX,
            /* [in] */ LONG FromY,
            /* [in] */ LONG FromW,
            /* [in] */ LONG FromH,
            /* [in] */ LONG ToID,
            /* [in] */ LONG ToX,
            /* [in] */ LONG ToY,
            /* [in] */ LONG ToW,
            /* [in] */ LONG ToH) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE BltAlphaBlend( 
            /* [in] */ LONG FromID,
            /* [in] */ LONG FromX,
            /* [in] */ LONG FromY,
            /* [in] */ LONG w,
            /* [in] */ LONG h,
            /* [in] */ LONG ToID,
            /* [in] */ LONG ToX,
            /* [in] */ LONG ToY,
            /* [in] */ LONG lAlphaBlend) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DrawBox( 
            /* [in] */ LONG x,
            /* [in] */ LONG y,
            /* [in] */ LONG w,
            /* [in] */ LONG h,
            /* [in] */ LONG Color,
            /* [in] */ BOOL Fills,
            /* [defaultvalue][in] */ LONG SpriteID = 0) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DrawPolygon( 
            /* [in] */ LONG x,
            /* [in] */ LONG y,
            /* [in] */ LONG wr,
            /* [in] */ LONG hr,
            /* [in] */ LONG Polygon,
            /* [in] */ LONG Rotate,
            /* [in] */ LONG Color,
            /* [in] */ BOOL Fills,
            /* [defaultvalue][in] */ LONG SpriteID = 0) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DrawLine( 
            /* [in] */ LONG x1,
            /* [in] */ LONG y1,
            /* [in] */ LONG x2,
            /* [in] */ LONG y2,
            /* [in] */ LONG Color,
            /* [defaultvalue][in] */ LONG SpriteID = 0) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DrawLineFromLP( 
            /* [in] */ LONG x,
            /* [in] */ LONG y,
            /* [in] */ LONG Color,
            /* [defaultvalue][in] */ LONG SpriteID = 0) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DSetLP( 
            /* [in] */ LONG x,
            /* [in] */ LONG y,
            /* [defaultvalue][in] */ LONG SpriteID = 0) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DrawPixel( 
            /* [in] */ LONG x,
            /* [in] */ LONG y,
            /* [in] */ LONG Color,
            /* [defaultvalue][in] */ LONG SpriteID = 0) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DGetPixel( 
            /* [in] */ LONG x,
            /* [in] */ LONG y,
            /* [defaultvalue][in] */ LONG SpriteID,
            /* [retval][out] */ LONG __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DrawRoundBox( 
            /* [in] */ LONG x,
            /* [in] */ LONG y,
            /* [in] */ LONG w,
            /* [in] */ LONG h,
            /* [in] */ LONG Round,
            /* [in] */ LONG Color,
            /* [in] */ BOOL Fills,
            /* [defaultvalue][in] */ LONG SpriteID = 0) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DrawCircle( 
            /* [in] */ LONG x,
            /* [in] */ LONG y,
            /* [in] */ LONG Radius,
            /* [in] */ LONG StartR,
            /* [in] */ LONG EndR,
            /* [in] */ LONG Color,
            /* [in] */ BOOL Fills,
            /* [defaultvalue][in] */ LONG SpriteID = 0) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DrawEllipse( 
            /* [in] */ LONG x,
            /* [in] */ LONG y,
            /* [in] */ LONG wr,
            /* [in] */ LONG hr,
            /* [in] */ LONG StartR,
            /* [in] */ LONG EndR,
            /* [in] */ LONG Color,
            /* [in] */ BOOL Close,
            /* [defaultvalue][in] */ LONG SpriteID = 0) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DrawFill( 
            /* [in] */ LONG x,
            /* [in] */ LONG y,
            /* [in] */ LONG Color,
            /* [defaultvalue][in] */ LONG SpriteID = 0) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DrawString( 
            /* [in] */ LONG x,
            /* [in] */ LONG y,
            /* [in] */ BSTR Text,
            /* [defaultvalue][in] */ LONG Align,
            /* [in] */ LONG Color,
            /* [defaultvalue][in] */ LONG SpriteID = 0) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DSetTextFont( 
            /* [defaultvalue][in] */ LONG Size = 0xff,
            /* [defaultvalue][in] */ BOOL Bold = 0xff,
            /* [defaultvalue][in] */ BOOL Italic = 0xff,
            /* [defaultvalue][in] */ BOOL UnderLine = 0xff,
            /* [defaultvalue][in] */ BOOL Strike = 0xff,
            /* [defaultvalue][in] */ BSTR FontName = L"default",
            /* [defaultvalue][in] */ LONG SpriteID = 0) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DSetTextSpace( 
            /* [in] */ LONG lSpace,
            /* [defaultvalue][in] */ LONG SpriteID = 0) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Refresh( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SpriteState( 
            /* [in] */ LONG SpriteID,
            /* [in] */ BOOL IsEnable) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SpriteResize( 
            /* [in] */ LONG SpriteID,
            /* [in] */ LONG cx,
            /* [in] */ LONG cy) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SpriteLoadFromFile( 
            /* [in] */ LONG SpriteID,
            BSTR FPath) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SpriteCopy( 
            /* [in] */ LONG FromID,
            /* [in] */ LONG ToID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SpritePaste( 
            /* [in] */ LONG FromID,
            /* [in] */ LONG ToID,
            /* [in] */ LONG x,
            /* [in] */ LONG y) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SpriteView( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MouseX( 
            /* [retval][out] */ LONG __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MouseX( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MouseY( 
            /* [retval][out] */ LONG __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MouseY( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE InCheck( 
            /* [in] */ short KeyCode,
            /* [retval][out] */ BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE InCheckPrev( 
            /* [in] */ short KeyCode,
            /* [retval][out] */ BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE fClear( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE fWriteString( 
            /* [in] */ BSTR Category,
            /* [in] */ BSTR KeyName,
            /* [in] */ BSTR Data) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE fWriteInteger( 
            /* [in] */ BSTR Category,
            /* [in] */ BSTR KeyName,
            /* [in] */ LONG Data) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE fReadString( 
            /* [in] */ BSTR Categoly,
            /* [in] */ BSTR KeyName,
            /* [in] */ BSTR Default,
            /* [out][in] */ BSTR lpBuffer) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE fReadInteger( 
            /* [in] */ BSTR Category,
            /* [in] */ BSTR KeyName,
            /* [in] */ LONG Defaults,
            /* [out][in] */ LONG __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE fOpen( 
            /* [in] */ BSTR FName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DSetFillStyle( 
            /* [in] */ LONG newVal,
            /* [defaultvalue][in] */ LONG SpriteID = 0) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DSetLineStyle( 
            /* [in] */ LONG newVal,
            /* [defaultvalue][in] */ LONG SpriteID = 0) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Graphics( 
            /* [in] */ LONG Switch) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OnMCIFailure( 
            /* [retval][out] */ LONG __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_OnMCIFailure( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OnMCISuccess( 
            /* [retval][out] */ LONG __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_OnMCISuccess( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OnSurfaceLost( 
            /* [retval][out] */ LONG __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_OnSurfaceLost( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DSetColorKey( 
            /* [in] */ LONG Color,
            /* [in] */ LONG Non_Zero_SpriteID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DSetRasterOP( 
            /* [in] */ LONG lRasterOP,
            /* [defaultvalue][in] */ LONG SpriteID = 0) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DSetMapMode( 
            /* [in] */ LONG lMapMode,
            /* [defaultvalue][in] */ LONG SpriteID = 0) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DSetOrigin( 
            /* [in] */ LONG X,
            /* [in] */ LONG Y,
            /* [defaultvalue][in] */ LONG SpriteID = 0) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Sound( 
            /* [in] */ LONG SNDMode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Snd_Open( 
            /* [in] */ LONG BufferID,
            /* [in] */ BSTR FileName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Snd_Play( 
            /* [in] */ LONG BufferID,
            /* [defaultvalue][in] */ LONG ShowDialog = 0) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Snd_LoopPlay( 
            /* [in] */ LONG BufferID,
            /* [defaultvalue][in] */ LONG ShowDialog = 0) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Snd_Stop( 
            /* [in] */ LONG BufferID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Download( 
            /* [in] */ BSTR URL,
            /* [in] */ BSTR DownloadFile) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Logging( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Snd_Pause( 
            /* [in] */ BOOL Play,
            /* [in] */ LONG BufferID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Snd_GetData( 
            /* [in] */ LONG BufferID,
            /* [retval][out] */ LONG __RPC_FAR *Data) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE TickReset( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetFACEVer( 
            /* [retval][out] */ LONG __RPC_FAR *Ret) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE mci( 
            /* [in] */ BSTR CMDStr,
            /* [in] */ BSTR FName,
            /* [in] */ BSTR Optional) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFACEVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IFACE __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IFACE __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IFACE __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IFACE __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IFACE __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IFACE __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IFACE __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *wDefault )( 
            IFACE __RPC_FAR * This,
            /* [in] */ BSTR ProgramName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Run )( 
            IFACE __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DoEvents )( 
            IFACE __RPC_FAR * This,
            /* [retval][out] */ BOOL __RPC_FAR *StillRunning);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *wGetHandle )( 
            IFACE __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *HandleToWindow);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *wResizeTo )( 
            IFACE __RPC_FAR * This,
            /* [in] */ LONG w,
            /* [in] */ LONG h);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *wResizeBy )( 
            IFACE __RPC_FAR * This,
            /* [in] */ LONG rw,
            /* [in] */ LONG rh);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *wMoveTo )( 
            IFACE __RPC_FAR * This,
            /* [in] */ LONG x,
            /* [in] */ LONG y);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *wMoveBy )( 
            IFACE __RPC_FAR * This,
            /* [in] */ LONG rx,
            /* [in] */ LONG ry);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *wShowMessage )( 
            IFACE __RPC_FAR * This,
            /* [in] */ BSTR Message,
            /* [in] */ BSTR Caption);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *wYesNoMessage )( 
            IFACE __RPC_FAR * This,
            /* [in] */ BSTR Message,
            /* [in] */ BSTR Caption,
            /* [retval][out] */ BOOL __RPC_FAR *YesNo);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_wCaption )( 
            IFACE __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_wVisible )( 
            IFACE __RPC_FAR * This,
            /* [retval][out] */ BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_wVisible )( 
            IFACE __RPC_FAR * This,
            /* [in] */ BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_wEnable )( 
            IFACE __RPC_FAR * This,
            /* [retval][out] */ BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_wEnable )( 
            IFACE __RPC_FAR * This,
            /* [in] */ BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_wHasMaxBtn )( 
            IFACE __RPC_FAR * This,
            /* [retval][out] */ BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_wHasMaxBtn )( 
            IFACE __RPC_FAR * This,
            /* [in] */ BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_wHasMinBtn )( 
            IFACE __RPC_FAR * This,
            /* [retval][out] */ BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_wHasMinBtn )( 
            IFACE __RPC_FAR * This,
            /* [in] */ BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_wHasCloseBtn )( 
            IFACE __RPC_FAR * This,
            /* [retval][out] */ BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_wHasCloseBtn )( 
            IFACE __RPC_FAR * This,
            /* [in] */ BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_wHasTitleBar )( 
            IFACE __RPC_FAR * This,
            /* [retval][out] */ BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_wHasTitleBar )( 
            IFACE __RPC_FAR * This,
            /* [in] */ BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_wResizeable )( 
            IFACE __RPC_FAR * This,
            /* [retval][out] */ BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_wResizeable )( 
            IFACE __RPC_FAR * This,
            /* [in] */ BOOL newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *wRunTimer )( 
            IFACE __RPC_FAR * This,
            /* [in] */ LONG Interval,
            /* [in] */ LONG Event);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTick )( 
            IFACE __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *Tick);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_OnActive )( 
            IFACE __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_OnActive )( 
            IFACE __RPC_FAR * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_OnDeActive )( 
            IFACE __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_OnDeActive )( 
            IFACE __RPC_FAR * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_OnKeyDown )( 
            IFACE __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_OnKeyDown )( 
            IFACE __RPC_FAR * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_OnKeyUp )( 
            IFACE __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_OnKeyUp )( 
            IFACE __RPC_FAR * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_OnCommand )( 
            IFACE __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_OnCommand )( 
            IFACE __RPC_FAR * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_OnMouseDown )( 
            IFACE __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_OnMouseDown )( 
            IFACE __RPC_FAR * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_OnMouseUp )( 
            IFACE __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_OnMouseUp )( 
            IFACE __RPC_FAR * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_OnMouseWheel )( 
            IFACE __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_OnMouseWheel )( 
            IFACE __RPC_FAR * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_OnMove )( 
            IFACE __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_OnMove )( 
            IFACE __RPC_FAR * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_OnMoving )( 
            IFACE __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_OnMoving )( 
            IFACE __RPC_FAR * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_OnSize )( 
            IFACE __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_OnSize )( 
            IFACE __RPC_FAR * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_OnSizing )( 
            IFACE __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_OnSizing )( 
            IFACE __RPC_FAR * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_wProcedure )( 
            IFACE __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_wProcedure )( 
            IFACE __RPC_FAR * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *wDestroy )( 
            IFACE __RPC_FAR * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_wHasBorder )( 
            IFACE __RPC_FAR * This,
            /* [retval][out] */ BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_wHasBorder )( 
            IFACE __RPC_FAR * This,
            /* [in] */ BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_wToolWin )( 
            IFACE __RPC_FAR * This,
            /* [retval][out] */ BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_wToolWin )( 
            IFACE __RPC_FAR * This,
            /* [in] */ BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_wTopMost )( 
            IFACE __RPC_FAR * This,
            /* [retval][out] */ BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_wTopMost )( 
            IFACE __RPC_FAR * This,
            /* [in] */ BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SoftwareFPS )( 
            IFACE __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_SoftwareFPS )( 
            IFACE __RPC_FAR * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_KeepFPS )( 
            IFACE __RPC_FAR * This,
            /* [retval][out] */ BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Blt )( 
            IFACE __RPC_FAR * This,
            /* [in] */ LONG FromID,
            /* [in] */ LONG FromX,
            /* [in] */ LONG FromY,
            /* [in] */ LONG w,
            /* [in] */ LONG h,
            /* [in] */ LONG ToID,
            /* [in] */ LONG ToX,
            /* [in] */ LONG ToY);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *BltStretch )( 
            IFACE __RPC_FAR * This,
            /* [in] */ LONG FromID,
            /* [in] */ LONG FromX,
            /* [in] */ LONG FromY,
            /* [in] */ LONG FromW,
            /* [in] */ LONG FromH,
            /* [in] */ LONG ToID,
            /* [in] */ LONG ToX,
            /* [in] */ LONG ToY,
            /* [in] */ LONG ToW,
            /* [in] */ LONG ToH);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *BltAlphaBlend )( 
            IFACE __RPC_FAR * This,
            /* [in] */ LONG FromID,
            /* [in] */ LONG FromX,
            /* [in] */ LONG FromY,
            /* [in] */ LONG w,
            /* [in] */ LONG h,
            /* [in] */ LONG ToID,
            /* [in] */ LONG ToX,
            /* [in] */ LONG ToY,
            /* [in] */ LONG lAlphaBlend);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DrawBox )( 
            IFACE __RPC_FAR * This,
            /* [in] */ LONG x,
            /* [in] */ LONG y,
            /* [in] */ LONG w,
            /* [in] */ LONG h,
            /* [in] */ LONG Color,
            /* [in] */ BOOL Fills,
            /* [defaultvalue][in] */ LONG SpriteID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DrawPolygon )( 
            IFACE __RPC_FAR * This,
            /* [in] */ LONG x,
            /* [in] */ LONG y,
            /* [in] */ LONG wr,
            /* [in] */ LONG hr,
            /* [in] */ LONG Polygon,
            /* [in] */ LONG Rotate,
            /* [in] */ LONG Color,
            /* [in] */ BOOL Fills,
            /* [defaultvalue][in] */ LONG SpriteID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DrawLine )( 
            IFACE __RPC_FAR * This,
            /* [in] */ LONG x1,
            /* [in] */ LONG y1,
            /* [in] */ LONG x2,
            /* [in] */ LONG y2,
            /* [in] */ LONG Color,
            /* [defaultvalue][in] */ LONG SpriteID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DrawLineFromLP )( 
            IFACE __RPC_FAR * This,
            /* [in] */ LONG x,
            /* [in] */ LONG y,
            /* [in] */ LONG Color,
            /* [defaultvalue][in] */ LONG SpriteID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DSetLP )( 
            IFACE __RPC_FAR * This,
            /* [in] */ LONG x,
            /* [in] */ LONG y,
            /* [defaultvalue][in] */ LONG SpriteID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DrawPixel )( 
            IFACE __RPC_FAR * This,
            /* [in] */ LONG x,
            /* [in] */ LONG y,
            /* [in] */ LONG Color,
            /* [defaultvalue][in] */ LONG SpriteID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DGetPixel )( 
            IFACE __RPC_FAR * This,
            /* [in] */ LONG x,
            /* [in] */ LONG y,
            /* [defaultvalue][in] */ LONG SpriteID,
            /* [retval][out] */ LONG __RPC_FAR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DrawRoundBox )( 
            IFACE __RPC_FAR * This,
            /* [in] */ LONG x,
            /* [in] */ LONG y,
            /* [in] */ LONG w,
            /* [in] */ LONG h,
            /* [in] */ LONG Round,
            /* [in] */ LONG Color,
            /* [in] */ BOOL Fills,
            /* [defaultvalue][in] */ LONG SpriteID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DrawCircle )( 
            IFACE __RPC_FAR * This,
            /* [in] */ LONG x,
            /* [in] */ LONG y,
            /* [in] */ LONG Radius,
            /* [in] */ LONG StartR,
            /* [in] */ LONG EndR,
            /* [in] */ LONG Color,
            /* [in] */ BOOL Fills,
            /* [defaultvalue][in] */ LONG SpriteID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DrawEllipse )( 
            IFACE __RPC_FAR * This,
            /* [in] */ LONG x,
            /* [in] */ LONG y,
            /* [in] */ LONG wr,
            /* [in] */ LONG hr,
            /* [in] */ LONG StartR,
            /* [in] */ LONG EndR,
            /* [in] */ LONG Color,
            /* [in] */ BOOL Close,
            /* [defaultvalue][in] */ LONG SpriteID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DrawFill )( 
            IFACE __RPC_FAR * This,
            /* [in] */ LONG x,
            /* [in] */ LONG y,
            /* [in] */ LONG Color,
            /* [defaultvalue][in] */ LONG SpriteID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DrawString )( 
            IFACE __RPC_FAR * This,
            /* [in] */ LONG x,
            /* [in] */ LONG y,
            /* [in] */ BSTR Text,
            /* [defaultvalue][in] */ LONG Align,
            /* [in] */ LONG Color,
            /* [defaultvalue][in] */ LONG SpriteID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DSetTextFont )( 
            IFACE __RPC_FAR * This,
            /* [defaultvalue][in] */ LONG Size,
            /* [defaultvalue][in] */ BOOL Bold,
            /* [defaultvalue][in] */ BOOL Italic,
            /* [defaultvalue][in] */ BOOL UnderLine,
            /* [defaultvalue][in] */ BOOL Strike,
            /* [defaultvalue][in] */ BSTR FontName,
            /* [defaultvalue][in] */ LONG SpriteID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DSetTextSpace )( 
            IFACE __RPC_FAR * This,
            /* [in] */ LONG lSpace,
            /* [defaultvalue][in] */ LONG SpriteID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Refresh )( 
            IFACE __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SpriteState )( 
            IFACE __RPC_FAR * This,
            /* [in] */ LONG SpriteID,
            /* [in] */ BOOL IsEnable);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SpriteResize )( 
            IFACE __RPC_FAR * This,
            /* [in] */ LONG SpriteID,
            /* [in] */ LONG cx,
            /* [in] */ LONG cy);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SpriteLoadFromFile )( 
            IFACE __RPC_FAR * This,
            /* [in] */ LONG SpriteID,
            BSTR FPath);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SpriteCopy )( 
            IFACE __RPC_FAR * This,
            /* [in] */ LONG FromID,
            /* [in] */ LONG ToID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SpritePaste )( 
            IFACE __RPC_FAR * This,
            /* [in] */ LONG FromID,
            /* [in] */ LONG ToID,
            /* [in] */ LONG x,
            /* [in] */ LONG y);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SpriteView )( 
            IFACE __RPC_FAR * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_MouseX )( 
            IFACE __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_MouseX )( 
            IFACE __RPC_FAR * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_MouseY )( 
            IFACE __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_MouseY )( 
            IFACE __RPC_FAR * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InCheck )( 
            IFACE __RPC_FAR * This,
            /* [in] */ short KeyCode,
            /* [retval][out] */ BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InCheckPrev )( 
            IFACE __RPC_FAR * This,
            /* [in] */ short KeyCode,
            /* [retval][out] */ BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *fClear )( 
            IFACE __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *fWriteString )( 
            IFACE __RPC_FAR * This,
            /* [in] */ BSTR Category,
            /* [in] */ BSTR KeyName,
            /* [in] */ BSTR Data);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *fWriteInteger )( 
            IFACE __RPC_FAR * This,
            /* [in] */ BSTR Category,
            /* [in] */ BSTR KeyName,
            /* [in] */ LONG Data);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *fReadString )( 
            IFACE __RPC_FAR * This,
            /* [in] */ BSTR Categoly,
            /* [in] */ BSTR KeyName,
            /* [in] */ BSTR Default,
            /* [out][in] */ BSTR lpBuffer);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *fReadInteger )( 
            IFACE __RPC_FAR * This,
            /* [in] */ BSTR Category,
            /* [in] */ BSTR KeyName,
            /* [in] */ LONG Defaults,
            /* [out][in] */ LONG __RPC_FAR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *fOpen )( 
            IFACE __RPC_FAR * This,
            /* [in] */ BSTR FName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DSetFillStyle )( 
            IFACE __RPC_FAR * This,
            /* [in] */ LONG newVal,
            /* [defaultvalue][in] */ LONG SpriteID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DSetLineStyle )( 
            IFACE __RPC_FAR * This,
            /* [in] */ LONG newVal,
            /* [defaultvalue][in] */ LONG SpriteID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Graphics )( 
            IFACE __RPC_FAR * This,
            /* [in] */ LONG Switch);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_OnMCIFailure )( 
            IFACE __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_OnMCIFailure )( 
            IFACE __RPC_FAR * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_OnMCISuccess )( 
            IFACE __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_OnMCISuccess )( 
            IFACE __RPC_FAR * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_OnSurfaceLost )( 
            IFACE __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_OnSurfaceLost )( 
            IFACE __RPC_FAR * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DSetColorKey )( 
            IFACE __RPC_FAR * This,
            /* [in] */ LONG Color,
            /* [in] */ LONG Non_Zero_SpriteID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DSetRasterOP )( 
            IFACE __RPC_FAR * This,
            /* [in] */ LONG lRasterOP,
            /* [defaultvalue][in] */ LONG SpriteID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DSetMapMode )( 
            IFACE __RPC_FAR * This,
            /* [in] */ LONG lMapMode,
            /* [defaultvalue][in] */ LONG SpriteID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DSetOrigin )( 
            IFACE __RPC_FAR * This,
            /* [in] */ LONG X,
            /* [in] */ LONG Y,
            /* [defaultvalue][in] */ LONG SpriteID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Sound )( 
            IFACE __RPC_FAR * This,
            /* [in] */ LONG SNDMode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Snd_Open )( 
            IFACE __RPC_FAR * This,
            /* [in] */ LONG BufferID,
            /* [in] */ BSTR FileName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Snd_Play )( 
            IFACE __RPC_FAR * This,
            /* [in] */ LONG BufferID,
            /* [defaultvalue][in] */ LONG ShowDialog);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Snd_LoopPlay )( 
            IFACE __RPC_FAR * This,
            /* [in] */ LONG BufferID,
            /* [defaultvalue][in] */ LONG ShowDialog);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Snd_Stop )( 
            IFACE __RPC_FAR * This,
            /* [in] */ LONG BufferID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Download )( 
            IFACE __RPC_FAR * This,
            /* [in] */ BSTR URL,
            /* [in] */ BSTR DownloadFile);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Logging )( 
            IFACE __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Snd_Pause )( 
            IFACE __RPC_FAR * This,
            /* [in] */ BOOL Play,
            /* [in] */ LONG BufferID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Snd_GetData )( 
            IFACE __RPC_FAR * This,
            /* [in] */ LONG BufferID,
            /* [retval][out] */ LONG __RPC_FAR *Data);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *TickReset )( 
            IFACE __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFACEVer )( 
            IFACE __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *Ret);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *mci )( 
            IFACE __RPC_FAR * This,
            /* [in] */ BSTR CMDStr,
            /* [in] */ BSTR FName,
            /* [in] */ BSTR Optional);
        
        END_INTERFACE
    } IFACEVtbl;

    interface IFACE
    {
        CONST_VTBL struct IFACEVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFACE_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFACE_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFACE_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFACE_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IFACE_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IFACE_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IFACE_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IFACE_wDefault(This,ProgramName)	\
    (This)->lpVtbl -> wDefault(This,ProgramName)

#define IFACE_Run(This)	\
    (This)->lpVtbl -> Run(This)

#define IFACE_DoEvents(This,StillRunning)	\
    (This)->lpVtbl -> DoEvents(This,StillRunning)

#define IFACE_wGetHandle(This,HandleToWindow)	\
    (This)->lpVtbl -> wGetHandle(This,HandleToWindow)

#define IFACE_wResizeTo(This,w,h)	\
    (This)->lpVtbl -> wResizeTo(This,w,h)

#define IFACE_wResizeBy(This,rw,rh)	\
    (This)->lpVtbl -> wResizeBy(This,rw,rh)

#define IFACE_wMoveTo(This,x,y)	\
    (This)->lpVtbl -> wMoveTo(This,x,y)

#define IFACE_wMoveBy(This,rx,ry)	\
    (This)->lpVtbl -> wMoveBy(This,rx,ry)

#define IFACE_wShowMessage(This,Message,Caption)	\
    (This)->lpVtbl -> wShowMessage(This,Message,Caption)

#define IFACE_wYesNoMessage(This,Message,Caption,YesNo)	\
    (This)->lpVtbl -> wYesNoMessage(This,Message,Caption,YesNo)

#define IFACE_put_wCaption(This,newVal)	\
    (This)->lpVtbl -> put_wCaption(This,newVal)

#define IFACE_get_wVisible(This,pVal)	\
    (This)->lpVtbl -> get_wVisible(This,pVal)

#define IFACE_put_wVisible(This,newVal)	\
    (This)->lpVtbl -> put_wVisible(This,newVal)

#define IFACE_get_wEnable(This,pVal)	\
    (This)->lpVtbl -> get_wEnable(This,pVal)

#define IFACE_put_wEnable(This,newVal)	\
    (This)->lpVtbl -> put_wEnable(This,newVal)

#define IFACE_get_wHasMaxBtn(This,pVal)	\
    (This)->lpVtbl -> get_wHasMaxBtn(This,pVal)

#define IFACE_put_wHasMaxBtn(This,newVal)	\
    (This)->lpVtbl -> put_wHasMaxBtn(This,newVal)

#define IFACE_get_wHasMinBtn(This,pVal)	\
    (This)->lpVtbl -> get_wHasMinBtn(This,pVal)

#define IFACE_put_wHasMinBtn(This,newVal)	\
    (This)->lpVtbl -> put_wHasMinBtn(This,newVal)

#define IFACE_get_wHasCloseBtn(This,pVal)	\
    (This)->lpVtbl -> get_wHasCloseBtn(This,pVal)

#define IFACE_put_wHasCloseBtn(This,newVal)	\
    (This)->lpVtbl -> put_wHasCloseBtn(This,newVal)

#define IFACE_get_wHasTitleBar(This,pVal)	\
    (This)->lpVtbl -> get_wHasTitleBar(This,pVal)

#define IFACE_put_wHasTitleBar(This,newVal)	\
    (This)->lpVtbl -> put_wHasTitleBar(This,newVal)

#define IFACE_get_wResizeable(This,pVal)	\
    (This)->lpVtbl -> get_wResizeable(This,pVal)

#define IFACE_put_wResizeable(This,newVal)	\
    (This)->lpVtbl -> put_wResizeable(This,newVal)

#define IFACE_wRunTimer(This,Interval,Event)	\
    (This)->lpVtbl -> wRunTimer(This,Interval,Event)

#define IFACE_GetTick(This,Tick)	\
    (This)->lpVtbl -> GetTick(This,Tick)

#define IFACE_get_OnActive(This,pVal)	\
    (This)->lpVtbl -> get_OnActive(This,pVal)

#define IFACE_put_OnActive(This,newVal)	\
    (This)->lpVtbl -> put_OnActive(This,newVal)

#define IFACE_get_OnDeActive(This,pVal)	\
    (This)->lpVtbl -> get_OnDeActive(This,pVal)

#define IFACE_put_OnDeActive(This,newVal)	\
    (This)->lpVtbl -> put_OnDeActive(This,newVal)

#define IFACE_get_OnKeyDown(This,pVal)	\
    (This)->lpVtbl -> get_OnKeyDown(This,pVal)

#define IFACE_put_OnKeyDown(This,newVal)	\
    (This)->lpVtbl -> put_OnKeyDown(This,newVal)

#define IFACE_get_OnKeyUp(This,pVal)	\
    (This)->lpVtbl -> get_OnKeyUp(This,pVal)

#define IFACE_put_OnKeyUp(This,newVal)	\
    (This)->lpVtbl -> put_OnKeyUp(This,newVal)

#define IFACE_get_OnCommand(This,pVal)	\
    (This)->lpVtbl -> get_OnCommand(This,pVal)

#define IFACE_put_OnCommand(This,newVal)	\
    (This)->lpVtbl -> put_OnCommand(This,newVal)

#define IFACE_get_OnMouseDown(This,pVal)	\
    (This)->lpVtbl -> get_OnMouseDown(This,pVal)

#define IFACE_put_OnMouseDown(This,newVal)	\
    (This)->lpVtbl -> put_OnMouseDown(This,newVal)

#define IFACE_get_OnMouseUp(This,pVal)	\
    (This)->lpVtbl -> get_OnMouseUp(This,pVal)

#define IFACE_put_OnMouseUp(This,newVal)	\
    (This)->lpVtbl -> put_OnMouseUp(This,newVal)

#define IFACE_get_OnMouseWheel(This,pVal)	\
    (This)->lpVtbl -> get_OnMouseWheel(This,pVal)

#define IFACE_put_OnMouseWheel(This,newVal)	\
    (This)->lpVtbl -> put_OnMouseWheel(This,newVal)

#define IFACE_get_OnMove(This,pVal)	\
    (This)->lpVtbl -> get_OnMove(This,pVal)

#define IFACE_put_OnMove(This,newVal)	\
    (This)->lpVtbl -> put_OnMove(This,newVal)

#define IFACE_get_OnMoving(This,pVal)	\
    (This)->lpVtbl -> get_OnMoving(This,pVal)

#define IFACE_put_OnMoving(This,newVal)	\
    (This)->lpVtbl -> put_OnMoving(This,newVal)

#define IFACE_get_OnSize(This,pVal)	\
    (This)->lpVtbl -> get_OnSize(This,pVal)

#define IFACE_put_OnSize(This,newVal)	\
    (This)->lpVtbl -> put_OnSize(This,newVal)

#define IFACE_get_OnSizing(This,pVal)	\
    (This)->lpVtbl -> get_OnSizing(This,pVal)

#define IFACE_put_OnSizing(This,newVal)	\
    (This)->lpVtbl -> put_OnSizing(This,newVal)

#define IFACE_get_wProcedure(This,pVal)	\
    (This)->lpVtbl -> get_wProcedure(This,pVal)

#define IFACE_put_wProcedure(This,newVal)	\
    (This)->lpVtbl -> put_wProcedure(This,newVal)

#define IFACE_wDestroy(This)	\
    (This)->lpVtbl -> wDestroy(This)

#define IFACE_get_wHasBorder(This,pVal)	\
    (This)->lpVtbl -> get_wHasBorder(This,pVal)

#define IFACE_put_wHasBorder(This,newVal)	\
    (This)->lpVtbl -> put_wHasBorder(This,newVal)

#define IFACE_get_wToolWin(This,pVal)	\
    (This)->lpVtbl -> get_wToolWin(This,pVal)

#define IFACE_put_wToolWin(This,newVal)	\
    (This)->lpVtbl -> put_wToolWin(This,newVal)

#define IFACE_get_wTopMost(This,pVal)	\
    (This)->lpVtbl -> get_wTopMost(This,pVal)

#define IFACE_put_wTopMost(This,newVal)	\
    (This)->lpVtbl -> put_wTopMost(This,newVal)

#define IFACE_get_SoftwareFPS(This,pVal)	\
    (This)->lpVtbl -> get_SoftwareFPS(This,pVal)

#define IFACE_put_SoftwareFPS(This,newVal)	\
    (This)->lpVtbl -> put_SoftwareFPS(This,newVal)

#define IFACE_get_KeepFPS(This,pVal)	\
    (This)->lpVtbl -> get_KeepFPS(This,pVal)

#define IFACE_Blt(This,FromID,FromX,FromY,w,h,ToID,ToX,ToY)	\
    (This)->lpVtbl -> Blt(This,FromID,FromX,FromY,w,h,ToID,ToX,ToY)

#define IFACE_BltStretch(This,FromID,FromX,FromY,FromW,FromH,ToID,ToX,ToY,ToW,ToH)	\
    (This)->lpVtbl -> BltStretch(This,FromID,FromX,FromY,FromW,FromH,ToID,ToX,ToY,ToW,ToH)

#define IFACE_BltAlphaBlend(This,FromID,FromX,FromY,w,h,ToID,ToX,ToY,lAlphaBlend)	\
    (This)->lpVtbl -> BltAlphaBlend(This,FromID,FromX,FromY,w,h,ToID,ToX,ToY,lAlphaBlend)

#define IFACE_DrawBox(This,x,y,w,h,Color,Fills,SpriteID)	\
    (This)->lpVtbl -> DrawBox(This,x,y,w,h,Color,Fills,SpriteID)

#define IFACE_DrawPolygon(This,x,y,wr,hr,Polygon,Rotate,Color,Fills,SpriteID)	\
    (This)->lpVtbl -> DrawPolygon(This,x,y,wr,hr,Polygon,Rotate,Color,Fills,SpriteID)

#define IFACE_DrawLine(This,x1,y1,x2,y2,Color,SpriteID)	\
    (This)->lpVtbl -> DrawLine(This,x1,y1,x2,y2,Color,SpriteID)

#define IFACE_DrawLineFromLP(This,x,y,Color,SpriteID)	\
    (This)->lpVtbl -> DrawLineFromLP(This,x,y,Color,SpriteID)

#define IFACE_DSetLP(This,x,y,SpriteID)	\
    (This)->lpVtbl -> DSetLP(This,x,y,SpriteID)

#define IFACE_DrawPixel(This,x,y,Color,SpriteID)	\
    (This)->lpVtbl -> DrawPixel(This,x,y,Color,SpriteID)

#define IFACE_DGetPixel(This,x,y,SpriteID,pVal)	\
    (This)->lpVtbl -> DGetPixel(This,x,y,SpriteID,pVal)

#define IFACE_DrawRoundBox(This,x,y,w,h,Round,Color,Fills,SpriteID)	\
    (This)->lpVtbl -> DrawRoundBox(This,x,y,w,h,Round,Color,Fills,SpriteID)

#define IFACE_DrawCircle(This,x,y,Radius,StartR,EndR,Color,Fills,SpriteID)	\
    (This)->lpVtbl -> DrawCircle(This,x,y,Radius,StartR,EndR,Color,Fills,SpriteID)

#define IFACE_DrawEllipse(This,x,y,wr,hr,StartR,EndR,Color,Close,SpriteID)	\
    (This)->lpVtbl -> DrawEllipse(This,x,y,wr,hr,StartR,EndR,Color,Close,SpriteID)

#define IFACE_DrawFill(This,x,y,Color,SpriteID)	\
    (This)->lpVtbl -> DrawFill(This,x,y,Color,SpriteID)

#define IFACE_DrawString(This,x,y,Text,Align,Color,SpriteID)	\
    (This)->lpVtbl -> DrawString(This,x,y,Text,Align,Color,SpriteID)

#define IFACE_DSetTextFont(This,Size,Bold,Italic,UnderLine,Strike,FontName,SpriteID)	\
    (This)->lpVtbl -> DSetTextFont(This,Size,Bold,Italic,UnderLine,Strike,FontName,SpriteID)

#define IFACE_DSetTextSpace(This,lSpace,SpriteID)	\
    (This)->lpVtbl -> DSetTextSpace(This,lSpace,SpriteID)

#define IFACE_Refresh(This)	\
    (This)->lpVtbl -> Refresh(This)

#define IFACE_SpriteState(This,SpriteID,IsEnable)	\
    (This)->lpVtbl -> SpriteState(This,SpriteID,IsEnable)

#define IFACE_SpriteResize(This,SpriteID,cx,cy)	\
    (This)->lpVtbl -> SpriteResize(This,SpriteID,cx,cy)

#define IFACE_SpriteLoadFromFile(This,SpriteID,FPath)	\
    (This)->lpVtbl -> SpriteLoadFromFile(This,SpriteID,FPath)

#define IFACE_SpriteCopy(This,FromID,ToID)	\
    (This)->lpVtbl -> SpriteCopy(This,FromID,ToID)

#define IFACE_SpritePaste(This,FromID,ToID,x,y)	\
    (This)->lpVtbl -> SpritePaste(This,FromID,ToID,x,y)

#define IFACE_SpriteView(This)	\
    (This)->lpVtbl -> SpriteView(This)

#define IFACE_get_MouseX(This,pVal)	\
    (This)->lpVtbl -> get_MouseX(This,pVal)

#define IFACE_put_MouseX(This,newVal)	\
    (This)->lpVtbl -> put_MouseX(This,newVal)

#define IFACE_get_MouseY(This,pVal)	\
    (This)->lpVtbl -> get_MouseY(This,pVal)

#define IFACE_put_MouseY(This,newVal)	\
    (This)->lpVtbl -> put_MouseY(This,newVal)

#define IFACE_InCheck(This,KeyCode,pVal)	\
    (This)->lpVtbl -> InCheck(This,KeyCode,pVal)

#define IFACE_InCheckPrev(This,KeyCode,pVal)	\
    (This)->lpVtbl -> InCheckPrev(This,KeyCode,pVal)

#define IFACE_fClear(This)	\
    (This)->lpVtbl -> fClear(This)

#define IFACE_fWriteString(This,Category,KeyName,Data)	\
    (This)->lpVtbl -> fWriteString(This,Category,KeyName,Data)

#define IFACE_fWriteInteger(This,Category,KeyName,Data)	\
    (This)->lpVtbl -> fWriteInteger(This,Category,KeyName,Data)

#define IFACE_fReadString(This,Categoly,KeyName,Default,lpBuffer)	\
    (This)->lpVtbl -> fReadString(This,Categoly,KeyName,Default,lpBuffer)

#define IFACE_fReadInteger(This,Category,KeyName,Defaults,pVal)	\
    (This)->lpVtbl -> fReadInteger(This,Category,KeyName,Defaults,pVal)

#define IFACE_fOpen(This,FName)	\
    (This)->lpVtbl -> fOpen(This,FName)

#define IFACE_DSetFillStyle(This,newVal,SpriteID)	\
    (This)->lpVtbl -> DSetFillStyle(This,newVal,SpriteID)

#define IFACE_DSetLineStyle(This,newVal,SpriteID)	\
    (This)->lpVtbl -> DSetLineStyle(This,newVal,SpriteID)

#define IFACE_Graphics(This,Switch)	\
    (This)->lpVtbl -> Graphics(This,Switch)

#define IFACE_get_OnMCIFailure(This,pVal)	\
    (This)->lpVtbl -> get_OnMCIFailure(This,pVal)

#define IFACE_put_OnMCIFailure(This,newVal)	\
    (This)->lpVtbl -> put_OnMCIFailure(This,newVal)

#define IFACE_get_OnMCISuccess(This,pVal)	\
    (This)->lpVtbl -> get_OnMCISuccess(This,pVal)

#define IFACE_put_OnMCISuccess(This,newVal)	\
    (This)->lpVtbl -> put_OnMCISuccess(This,newVal)

#define IFACE_get_OnSurfaceLost(This,pVal)	\
    (This)->lpVtbl -> get_OnSurfaceLost(This,pVal)

#define IFACE_put_OnSurfaceLost(This,newVal)	\
    (This)->lpVtbl -> put_OnSurfaceLost(This,newVal)

#define IFACE_DSetColorKey(This,Color,Non_Zero_SpriteID)	\
    (This)->lpVtbl -> DSetColorKey(This,Color,Non_Zero_SpriteID)

#define IFACE_DSetRasterOP(This,lRasterOP,SpriteID)	\
    (This)->lpVtbl -> DSetRasterOP(This,lRasterOP,SpriteID)

#define IFACE_DSetMapMode(This,lMapMode,SpriteID)	\
    (This)->lpVtbl -> DSetMapMode(This,lMapMode,SpriteID)

#define IFACE_DSetOrigin(This,X,Y,SpriteID)	\
    (This)->lpVtbl -> DSetOrigin(This,X,Y,SpriteID)

#define IFACE_Sound(This,SNDMode)	\
    (This)->lpVtbl -> Sound(This,SNDMode)

#define IFACE_Snd_Open(This,BufferID,FileName)	\
    (This)->lpVtbl -> Snd_Open(This,BufferID,FileName)

#define IFACE_Snd_Play(This,BufferID,ShowDialog)	\
    (This)->lpVtbl -> Snd_Play(This,BufferID,ShowDialog)

#define IFACE_Snd_LoopPlay(This,BufferID,ShowDialog)	\
    (This)->lpVtbl -> Snd_LoopPlay(This,BufferID,ShowDialog)

#define IFACE_Snd_Stop(This,BufferID)	\
    (This)->lpVtbl -> Snd_Stop(This,BufferID)

#define IFACE_Download(This,URL,DownloadFile)	\
    (This)->lpVtbl -> Download(This,URL,DownloadFile)

#define IFACE_Logging(This)	\
    (This)->lpVtbl -> Logging(This)

#define IFACE_Snd_Pause(This,Play,BufferID)	\
    (This)->lpVtbl -> Snd_Pause(This,Play,BufferID)

#define IFACE_Snd_GetData(This,BufferID,Data)	\
    (This)->lpVtbl -> Snd_GetData(This,BufferID,Data)

#define IFACE_TickReset(This)	\
    (This)->lpVtbl -> TickReset(This)

#define IFACE_GetFACEVer(This,Ret)	\
    (This)->lpVtbl -> GetFACEVer(This,Ret)

#define IFACE_mci(This,CMDStr,FName,Optional)	\
    (This)->lpVtbl -> mci(This,CMDStr,FName,Optional)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFACE_wDefault_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ BSTR ProgramName);


void __RPC_STUB IFACE_wDefault_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFACE_Run_Proxy( 
    IFACE __RPC_FAR * This);


void __RPC_STUB IFACE_Run_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFACE_DoEvents_Proxy( 
    IFACE __RPC_FAR * This,
    /* [retval][out] */ BOOL __RPC_FAR *StillRunning);


void __RPC_STUB IFACE_DoEvents_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFACE_wGetHandle_Proxy( 
    IFACE __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *HandleToWindow);


void __RPC_STUB IFACE_wGetHandle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFACE_wResizeTo_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ LONG w,
    /* [in] */ LONG h);


void __RPC_STUB IFACE_wResizeTo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFACE_wResizeBy_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ LONG rw,
    /* [in] */ LONG rh);


void __RPC_STUB IFACE_wResizeBy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFACE_wMoveTo_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ LONG x,
    /* [in] */ LONG y);


void __RPC_STUB IFACE_wMoveTo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFACE_wMoveBy_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ LONG rx,
    /* [in] */ LONG ry);


void __RPC_STUB IFACE_wMoveBy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFACE_wShowMessage_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ BSTR Message,
    /* [in] */ BSTR Caption);


void __RPC_STUB IFACE_wShowMessage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFACE_wYesNoMessage_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ BSTR Message,
    /* [in] */ BSTR Caption,
    /* [retval][out] */ BOOL __RPC_FAR *YesNo);


void __RPC_STUB IFACE_wYesNoMessage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFACE_put_wCaption_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IFACE_put_wCaption_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFACE_get_wVisible_Proxy( 
    IFACE __RPC_FAR * This,
    /* [retval][out] */ BOOL __RPC_FAR *pVal);


void __RPC_STUB IFACE_get_wVisible_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFACE_put_wVisible_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ BOOL newVal);


void __RPC_STUB IFACE_put_wVisible_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFACE_get_wEnable_Proxy( 
    IFACE __RPC_FAR * This,
    /* [retval][out] */ BOOL __RPC_FAR *pVal);


void __RPC_STUB IFACE_get_wEnable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFACE_put_wEnable_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ BOOL newVal);


void __RPC_STUB IFACE_put_wEnable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFACE_get_wHasMaxBtn_Proxy( 
    IFACE __RPC_FAR * This,
    /* [retval][out] */ BOOL __RPC_FAR *pVal);


void __RPC_STUB IFACE_get_wHasMaxBtn_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFACE_put_wHasMaxBtn_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ BOOL newVal);


void __RPC_STUB IFACE_put_wHasMaxBtn_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFACE_get_wHasMinBtn_Proxy( 
    IFACE __RPC_FAR * This,
    /* [retval][out] */ BOOL __RPC_FAR *pVal);


void __RPC_STUB IFACE_get_wHasMinBtn_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFACE_put_wHasMinBtn_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ BOOL newVal);


void __RPC_STUB IFACE_put_wHasMinBtn_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFACE_get_wHasCloseBtn_Proxy( 
    IFACE __RPC_FAR * This,
    /* [retval][out] */ BOOL __RPC_FAR *pVal);


void __RPC_STUB IFACE_get_wHasCloseBtn_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFACE_put_wHasCloseBtn_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ BOOL newVal);


void __RPC_STUB IFACE_put_wHasCloseBtn_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFACE_get_wHasTitleBar_Proxy( 
    IFACE __RPC_FAR * This,
    /* [retval][out] */ BOOL __RPC_FAR *pVal);


void __RPC_STUB IFACE_get_wHasTitleBar_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFACE_put_wHasTitleBar_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ BOOL newVal);


void __RPC_STUB IFACE_put_wHasTitleBar_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFACE_get_wResizeable_Proxy( 
    IFACE __RPC_FAR * This,
    /* [retval][out] */ BOOL __RPC_FAR *pVal);


void __RPC_STUB IFACE_get_wResizeable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFACE_put_wResizeable_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ BOOL newVal);


void __RPC_STUB IFACE_put_wResizeable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFACE_wRunTimer_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ LONG Interval,
    /* [in] */ LONG Event);


void __RPC_STUB IFACE_wRunTimer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFACE_GetTick_Proxy( 
    IFACE __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *Tick);


void __RPC_STUB IFACE_GetTick_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFACE_get_OnActive_Proxy( 
    IFACE __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *pVal);


void __RPC_STUB IFACE_get_OnActive_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFACE_put_OnActive_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ LONG newVal);


void __RPC_STUB IFACE_put_OnActive_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFACE_get_OnDeActive_Proxy( 
    IFACE __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *pVal);


void __RPC_STUB IFACE_get_OnDeActive_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFACE_put_OnDeActive_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ LONG newVal);


void __RPC_STUB IFACE_put_OnDeActive_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFACE_get_OnKeyDown_Proxy( 
    IFACE __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *pVal);


void __RPC_STUB IFACE_get_OnKeyDown_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFACE_put_OnKeyDown_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ LONG newVal);


void __RPC_STUB IFACE_put_OnKeyDown_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFACE_get_OnKeyUp_Proxy( 
    IFACE __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *pVal);


void __RPC_STUB IFACE_get_OnKeyUp_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFACE_put_OnKeyUp_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ LONG newVal);


void __RPC_STUB IFACE_put_OnKeyUp_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFACE_get_OnCommand_Proxy( 
    IFACE __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *pVal);


void __RPC_STUB IFACE_get_OnCommand_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFACE_put_OnCommand_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ LONG newVal);


void __RPC_STUB IFACE_put_OnCommand_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFACE_get_OnMouseDown_Proxy( 
    IFACE __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *pVal);


void __RPC_STUB IFACE_get_OnMouseDown_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFACE_put_OnMouseDown_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ LONG newVal);


void __RPC_STUB IFACE_put_OnMouseDown_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFACE_get_OnMouseUp_Proxy( 
    IFACE __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *pVal);


void __RPC_STUB IFACE_get_OnMouseUp_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFACE_put_OnMouseUp_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ LONG newVal);


void __RPC_STUB IFACE_put_OnMouseUp_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFACE_get_OnMouseWheel_Proxy( 
    IFACE __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *pVal);


void __RPC_STUB IFACE_get_OnMouseWheel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFACE_put_OnMouseWheel_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ LONG newVal);


void __RPC_STUB IFACE_put_OnMouseWheel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFACE_get_OnMove_Proxy( 
    IFACE __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *pVal);


void __RPC_STUB IFACE_get_OnMove_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFACE_put_OnMove_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ LONG newVal);


void __RPC_STUB IFACE_put_OnMove_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFACE_get_OnMoving_Proxy( 
    IFACE __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *pVal);


void __RPC_STUB IFACE_get_OnMoving_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFACE_put_OnMoving_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ LONG newVal);


void __RPC_STUB IFACE_put_OnMoving_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFACE_get_OnSize_Proxy( 
    IFACE __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *pVal);


void __RPC_STUB IFACE_get_OnSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFACE_put_OnSize_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ LONG newVal);


void __RPC_STUB IFACE_put_OnSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFACE_get_OnSizing_Proxy( 
    IFACE __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *pVal);


void __RPC_STUB IFACE_get_OnSizing_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFACE_put_OnSizing_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ LONG newVal);


void __RPC_STUB IFACE_put_OnSizing_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFACE_get_wProcedure_Proxy( 
    IFACE __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *pVal);


void __RPC_STUB IFACE_get_wProcedure_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFACE_put_wProcedure_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ LONG newVal);


void __RPC_STUB IFACE_put_wProcedure_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFACE_wDestroy_Proxy( 
    IFACE __RPC_FAR * This);


void __RPC_STUB IFACE_wDestroy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFACE_get_wHasBorder_Proxy( 
    IFACE __RPC_FAR * This,
    /* [retval][out] */ BOOL __RPC_FAR *pVal);


void __RPC_STUB IFACE_get_wHasBorder_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFACE_put_wHasBorder_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ BOOL newVal);


void __RPC_STUB IFACE_put_wHasBorder_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFACE_get_wToolWin_Proxy( 
    IFACE __RPC_FAR * This,
    /* [retval][out] */ BOOL __RPC_FAR *pVal);


void __RPC_STUB IFACE_get_wToolWin_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFACE_put_wToolWin_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ BOOL newVal);


void __RPC_STUB IFACE_put_wToolWin_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFACE_get_wTopMost_Proxy( 
    IFACE __RPC_FAR * This,
    /* [retval][out] */ BOOL __RPC_FAR *pVal);


void __RPC_STUB IFACE_get_wTopMost_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFACE_put_wTopMost_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ BOOL newVal);


void __RPC_STUB IFACE_put_wTopMost_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFACE_get_SoftwareFPS_Proxy( 
    IFACE __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *pVal);


void __RPC_STUB IFACE_get_SoftwareFPS_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFACE_put_SoftwareFPS_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ LONG newVal);


void __RPC_STUB IFACE_put_SoftwareFPS_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFACE_get_KeepFPS_Proxy( 
    IFACE __RPC_FAR * This,
    /* [retval][out] */ BOOL __RPC_FAR *pVal);


void __RPC_STUB IFACE_get_KeepFPS_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFACE_Blt_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ LONG FromID,
    /* [in] */ LONG FromX,
    /* [in] */ LONG FromY,
    /* [in] */ LONG w,
    /* [in] */ LONG h,
    /* [in] */ LONG ToID,
    /* [in] */ LONG ToX,
    /* [in] */ LONG ToY);


void __RPC_STUB IFACE_Blt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFACE_BltStretch_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ LONG FromID,
    /* [in] */ LONG FromX,
    /* [in] */ LONG FromY,
    /* [in] */ LONG FromW,
    /* [in] */ LONG FromH,
    /* [in] */ LONG ToID,
    /* [in] */ LONG ToX,
    /* [in] */ LONG ToY,
    /* [in] */ LONG ToW,
    /* [in] */ LONG ToH);


void __RPC_STUB IFACE_BltStretch_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFACE_BltAlphaBlend_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ LONG FromID,
    /* [in] */ LONG FromX,
    /* [in] */ LONG FromY,
    /* [in] */ LONG w,
    /* [in] */ LONG h,
    /* [in] */ LONG ToID,
    /* [in] */ LONG ToX,
    /* [in] */ LONG ToY,
    /* [in] */ LONG lAlphaBlend);


void __RPC_STUB IFACE_BltAlphaBlend_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFACE_DrawBox_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ LONG x,
    /* [in] */ LONG y,
    /* [in] */ LONG w,
    /* [in] */ LONG h,
    /* [in] */ LONG Color,
    /* [in] */ BOOL Fills,
    /* [defaultvalue][in] */ LONG SpriteID);


void __RPC_STUB IFACE_DrawBox_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFACE_DrawPolygon_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ LONG x,
    /* [in] */ LONG y,
    /* [in] */ LONG wr,
    /* [in] */ LONG hr,
    /* [in] */ LONG Polygon,
    /* [in] */ LONG Rotate,
    /* [in] */ LONG Color,
    /* [in] */ BOOL Fills,
    /* [defaultvalue][in] */ LONG SpriteID);


void __RPC_STUB IFACE_DrawPolygon_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFACE_DrawLine_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ LONG x1,
    /* [in] */ LONG y1,
    /* [in] */ LONG x2,
    /* [in] */ LONG y2,
    /* [in] */ LONG Color,
    /* [defaultvalue][in] */ LONG SpriteID);


void __RPC_STUB IFACE_DrawLine_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFACE_DrawLineFromLP_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ LONG x,
    /* [in] */ LONG y,
    /* [in] */ LONG Color,
    /* [defaultvalue][in] */ LONG SpriteID);


void __RPC_STUB IFACE_DrawLineFromLP_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFACE_DSetLP_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ LONG x,
    /* [in] */ LONG y,
    /* [defaultvalue][in] */ LONG SpriteID);


void __RPC_STUB IFACE_DSetLP_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFACE_DrawPixel_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ LONG x,
    /* [in] */ LONG y,
    /* [in] */ LONG Color,
    /* [defaultvalue][in] */ LONG SpriteID);


void __RPC_STUB IFACE_DrawPixel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFACE_DGetPixel_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ LONG x,
    /* [in] */ LONG y,
    /* [defaultvalue][in] */ LONG SpriteID,
    /* [retval][out] */ LONG __RPC_FAR *pVal);


void __RPC_STUB IFACE_DGetPixel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFACE_DrawRoundBox_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ LONG x,
    /* [in] */ LONG y,
    /* [in] */ LONG w,
    /* [in] */ LONG h,
    /* [in] */ LONG Round,
    /* [in] */ LONG Color,
    /* [in] */ BOOL Fills,
    /* [defaultvalue][in] */ LONG SpriteID);


void __RPC_STUB IFACE_DrawRoundBox_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFACE_DrawCircle_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ LONG x,
    /* [in] */ LONG y,
    /* [in] */ LONG Radius,
    /* [in] */ LONG StartR,
    /* [in] */ LONG EndR,
    /* [in] */ LONG Color,
    /* [in] */ BOOL Fills,
    /* [defaultvalue][in] */ LONG SpriteID);


void __RPC_STUB IFACE_DrawCircle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFACE_DrawEllipse_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ LONG x,
    /* [in] */ LONG y,
    /* [in] */ LONG wr,
    /* [in] */ LONG hr,
    /* [in] */ LONG StartR,
    /* [in] */ LONG EndR,
    /* [in] */ LONG Color,
    /* [in] */ BOOL Close,
    /* [defaultvalue][in] */ LONG SpriteID);


void __RPC_STUB IFACE_DrawEllipse_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFACE_DrawFill_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ LONG x,
    /* [in] */ LONG y,
    /* [in] */ LONG Color,
    /* [defaultvalue][in] */ LONG SpriteID);


void __RPC_STUB IFACE_DrawFill_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFACE_DrawString_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ LONG x,
    /* [in] */ LONG y,
    /* [in] */ BSTR Text,
    /* [defaultvalue][in] */ LONG Align,
    /* [in] */ LONG Color,
    /* [defaultvalue][in] */ LONG SpriteID);


void __RPC_STUB IFACE_DrawString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFACE_DSetTextFont_Proxy( 
    IFACE __RPC_FAR * This,
    /* [defaultvalue][in] */ LONG Size,
    /* [defaultvalue][in] */ BOOL Bold,
    /* [defaultvalue][in] */ BOOL Italic,
    /* [defaultvalue][in] */ BOOL UnderLine,
    /* [defaultvalue][in] */ BOOL Strike,
    /* [defaultvalue][in] */ BSTR FontName,
    /* [defaultvalue][in] */ LONG SpriteID);


void __RPC_STUB IFACE_DSetTextFont_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFACE_DSetTextSpace_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ LONG lSpace,
    /* [defaultvalue][in] */ LONG SpriteID);


void __RPC_STUB IFACE_DSetTextSpace_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFACE_Refresh_Proxy( 
    IFACE __RPC_FAR * This);


void __RPC_STUB IFACE_Refresh_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFACE_SpriteState_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ LONG SpriteID,
    /* [in] */ BOOL IsEnable);


void __RPC_STUB IFACE_SpriteState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFACE_SpriteResize_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ LONG SpriteID,
    /* [in] */ LONG cx,
    /* [in] */ LONG cy);


void __RPC_STUB IFACE_SpriteResize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFACE_SpriteLoadFromFile_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ LONG SpriteID,
    BSTR FPath);


void __RPC_STUB IFACE_SpriteLoadFromFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFACE_SpriteCopy_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ LONG FromID,
    /* [in] */ LONG ToID);


void __RPC_STUB IFACE_SpriteCopy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFACE_SpritePaste_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ LONG FromID,
    /* [in] */ LONG ToID,
    /* [in] */ LONG x,
    /* [in] */ LONG y);


void __RPC_STUB IFACE_SpritePaste_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFACE_SpriteView_Proxy( 
    IFACE __RPC_FAR * This);


void __RPC_STUB IFACE_SpriteView_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFACE_get_MouseX_Proxy( 
    IFACE __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *pVal);


void __RPC_STUB IFACE_get_MouseX_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFACE_put_MouseX_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ LONG newVal);


void __RPC_STUB IFACE_put_MouseX_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFACE_get_MouseY_Proxy( 
    IFACE __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *pVal);


void __RPC_STUB IFACE_get_MouseY_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFACE_put_MouseY_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ LONG newVal);


void __RPC_STUB IFACE_put_MouseY_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFACE_InCheck_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ short KeyCode,
    /* [retval][out] */ BOOL __RPC_FAR *pVal);


void __RPC_STUB IFACE_InCheck_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFACE_InCheckPrev_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ short KeyCode,
    /* [retval][out] */ BOOL __RPC_FAR *pVal);


void __RPC_STUB IFACE_InCheckPrev_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFACE_fClear_Proxy( 
    IFACE __RPC_FAR * This);


void __RPC_STUB IFACE_fClear_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFACE_fWriteString_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ BSTR Category,
    /* [in] */ BSTR KeyName,
    /* [in] */ BSTR Data);


void __RPC_STUB IFACE_fWriteString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFACE_fWriteInteger_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ BSTR Category,
    /* [in] */ BSTR KeyName,
    /* [in] */ LONG Data);


void __RPC_STUB IFACE_fWriteInteger_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFACE_fReadString_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ BSTR Categoly,
    /* [in] */ BSTR KeyName,
    /* [in] */ BSTR Default,
    /* [out][in] */ BSTR lpBuffer);


void __RPC_STUB IFACE_fReadString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFACE_fReadInteger_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ BSTR Category,
    /* [in] */ BSTR KeyName,
    /* [in] */ LONG Defaults,
    /* [out][in] */ LONG __RPC_FAR *pVal);


void __RPC_STUB IFACE_fReadInteger_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFACE_fOpen_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ BSTR FName);


void __RPC_STUB IFACE_fOpen_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFACE_DSetFillStyle_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ LONG newVal,
    /* [defaultvalue][in] */ LONG SpriteID);


void __RPC_STUB IFACE_DSetFillStyle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFACE_DSetLineStyle_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ LONG newVal,
    /* [defaultvalue][in] */ LONG SpriteID);


void __RPC_STUB IFACE_DSetLineStyle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFACE_Graphics_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ LONG Switch);


void __RPC_STUB IFACE_Graphics_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFACE_get_OnMCIFailure_Proxy( 
    IFACE __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *pVal);


void __RPC_STUB IFACE_get_OnMCIFailure_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFACE_put_OnMCIFailure_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ LONG newVal);


void __RPC_STUB IFACE_put_OnMCIFailure_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFACE_get_OnMCISuccess_Proxy( 
    IFACE __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *pVal);


void __RPC_STUB IFACE_get_OnMCISuccess_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFACE_put_OnMCISuccess_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ LONG newVal);


void __RPC_STUB IFACE_put_OnMCISuccess_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFACE_get_OnSurfaceLost_Proxy( 
    IFACE __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *pVal);


void __RPC_STUB IFACE_get_OnSurfaceLost_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFACE_put_OnSurfaceLost_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ LONG newVal);


void __RPC_STUB IFACE_put_OnSurfaceLost_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFACE_DSetColorKey_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ LONG Color,
    /* [in] */ LONG Non_Zero_SpriteID);


void __RPC_STUB IFACE_DSetColorKey_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFACE_DSetRasterOP_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ LONG lRasterOP,
    /* [defaultvalue][in] */ LONG SpriteID);


void __RPC_STUB IFACE_DSetRasterOP_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFACE_DSetMapMode_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ LONG lMapMode,
    /* [defaultvalue][in] */ LONG SpriteID);


void __RPC_STUB IFACE_DSetMapMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFACE_DSetOrigin_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ LONG X,
    /* [in] */ LONG Y,
    /* [defaultvalue][in] */ LONG SpriteID);


void __RPC_STUB IFACE_DSetOrigin_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFACE_Sound_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ LONG SNDMode);


void __RPC_STUB IFACE_Sound_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFACE_Snd_Open_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ LONG BufferID,
    /* [in] */ BSTR FileName);


void __RPC_STUB IFACE_Snd_Open_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFACE_Snd_Play_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ LONG BufferID,
    /* [defaultvalue][in] */ LONG ShowDialog);


void __RPC_STUB IFACE_Snd_Play_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFACE_Snd_LoopPlay_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ LONG BufferID,
    /* [defaultvalue][in] */ LONG ShowDialog);


void __RPC_STUB IFACE_Snd_LoopPlay_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFACE_Snd_Stop_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ LONG BufferID);


void __RPC_STUB IFACE_Snd_Stop_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFACE_Download_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ BSTR URL,
    /* [in] */ BSTR DownloadFile);


void __RPC_STUB IFACE_Download_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFACE_Logging_Proxy( 
    IFACE __RPC_FAR * This);


void __RPC_STUB IFACE_Logging_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFACE_Snd_Pause_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ BOOL Play,
    /* [in] */ LONG BufferID);


void __RPC_STUB IFACE_Snd_Pause_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFACE_Snd_GetData_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ LONG BufferID,
    /* [retval][out] */ LONG __RPC_FAR *Data);


void __RPC_STUB IFACE_Snd_GetData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFACE_TickReset_Proxy( 
    IFACE __RPC_FAR * This);


void __RPC_STUB IFACE_TickReset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFACE_GetFACEVer_Proxy( 
    IFACE __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *Ret);


void __RPC_STUB IFACE_GetFACEVer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFACE_mci_Proxy( 
    IFACE __RPC_FAR * This,
    /* [in] */ BSTR CMDStr,
    /* [in] */ BSTR FName,
    /* [in] */ BSTR Optional);


void __RPC_STUB IFACE_mci_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IFACE_INTERFACE_DEFINED__ */



#ifndef __FACELIB_LIBRARY_DEFINED__
#define __FACELIB_LIBRARY_DEFINED__

/* library FACELIB */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_FACELIB;

EXTERN_C const CLSID CLSID_FACE;

#ifdef __cplusplus

class DECLSPEC_UUID("D07551AA-AB43-4C28-A08A-B9E3B74E93DF")
FACE;
#endif
#endif /* __FACELIB_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long __RPC_FAR *, unsigned long            , BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long __RPC_FAR *, BSTR __RPC_FAR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
