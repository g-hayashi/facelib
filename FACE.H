// FACE.h : IFACE �̐錾
#ifndef __FACE_H_
#define __FACE_H_

/* -- Changes Compile mode -- */
#define MBCS
#define OLE2ANSI
//#define UNICODE
//#define _UNICODE


__declspec(dllexport) class IFACE{
	BOOL GetFACEVer)(LONG*);
	BOOL TickReset)();
	BOOL Snd_Pause)( BOOL Play , LONG BufferID );
	BOOL Download)(BSTR URL , BSTR FName );
	BOOL Snd_Stop)(LONG BufferID);
	BOOL Snd_LoopPlay)(LONG BufferID,LONG ShowDlg );
	BOOL Snd_Play)(LONG BufferID ,LONG ShowDlg );
	BOOL Snd_Open)( LONG BufferID, BSTR FilePath);
	BOOL Sound)( LONG dwSndMode );
	BOOL DSetOrigin)(LONG X,LONG Y , /*[in,defautvalue(0)]*/LONG SpriteID) ;
	BOOL DSetMapMode)( LONG newVal,/*[in,defaultvalue(0)]*/LONG SpriteID);
	BOOL DSetRasterOP)( LONG newVal,/*[in,defaultvalue(0)]*/LONG SpriteID);
	BOOL DSetColorKey)(LONG Color ,LONG SpriteID);
	BOOL get_OnSurfaceLost)(/*[out, retval]*/ LONG *pVal);
	BOOL put_OnSurfaceLost)( LONG newVal);
	BOOL Graphics)( LONG GraphicsMode );
	BOOL DSetLineStyle)( LONG newVal,LONG SpriteID);
	BOOL DSetFillStyle)(  LONG newVal,LONG SpriteID);
	BOOL fOpen)( BSTR FName );
	BOOL fReadInteger)(BSTR Category , BSTR KeyName , LONG Defaults,/*[in,out]*/LONG *pVal);
	BOOL fReadString)(BSTR Categoly , BSTR KeyName ,  BSTR Default , /*[in,out]*/ BSTR lpBuffer);
	BOOL fWriteInteger)(BSTR Category ,BSTR KeyName , LONG Data);
	BOOL fWriteString)( BSTR Category,BSTR KeyName,BSTR Data);
	BOOL fClear)();
	BOOL InCheckPrev)(short KeyCode, /*[out, retval]*/ BOOL *pVal);
	BOOL InCheck)(short KeyCode, /*[out, retval]*/ BOOL *pVal);
	BOOL get_MouseY)(/*[out, retval]*/ LONG *pVal);
	BOOL put_MouseY)( LONG newVal);
	BOOL get_MouseX)(/*[out, retval]*/ LONG *pVal);
	BOOL put_MouseX)( LONG newVal);
	BOOL SpriteView)();
	BOOL SpritePaste)(LONG FromID , LONG ToID , LONG x , LONG y);
	BOOL SpriteCopy)(LONG FromID , LONG ToID);
	BOOL SpriteLoadFromFile)(LONG SpriteID , BSTR FPath);
	BOOL SpriteResize)(LONG SpriteID , LONG cx , LONG cy);
	BOOL SpriteState)(LONG SpriteID , BOOL IsEnable);
	BOOL Refresh)();
	BOOL DSetTextSpace)(LONG lSpace , LONG SpriteID );
	BOOL DSetTextFont)(LONG Size , BOOL Bold , BOOL Italic , BOOL UnderLine , BOOL Strike , BSTR FontName , LONG SpriteID);
	BOOL DrawString)(LONG x, LONG y , BSTR Text,LONG Align ,LONG Color , LONG SpriteID);
	BOOL DrawFill)(LONG x , LONG y , LONG Color , LONG SpriteID);
	BOOL DrawEllipse)(LONG x, LONG y , LONG wr , LONG hr , LONG StartR , LONG EndR , LONG Color , BOOL Close , LONG SpriteID );
	BOOL DrawCircle)(LONG x, LONG y , LONG Radius , LONG StartR , LONG EndR , LONG Color , BOOL Fills , LONG SpriteID );
	BOOL DrawRoundBox)(LONG x , LONG y , LONG w , LONG h , LONG Round , LONG Color , BOOL Fills , LONG SpriteID);
	BOOL DGetPixel)(LONG x, LONG  y , LONG SpriteID, /*[out, retval]*/ LONG *pVal);
	BOOL DrawPixel)(LONG x, LONG  y , LONG Color , LONG SpriteID);
	BOOL DSetLP)( LONG x, LONG y , LONG SpriteID);
	BOOL DrawLineFromLP)( LONG x, LONG y , LONG Color , LONG SpriteID);
	BOOL DrawLine)(LONG x1, LONG y1 , LONG x2, LONG y2 , LONG Color , LONG SpriteID);
	BOOL DrawPolygon)(LONG x , LONG  y ,LONG wr , LONG hr ,LONG Polygon , LONG Rotate ,LONG Color , BOOL Fills , LONG SpriteID);
	BOOL DrawBox)(LONG x , LONG y , LONG w , LONG h , LONG Color , BOOL Fills , LONG SpriteID);
	BOOL BltAlphaBlend)(LONG FromID , LONG FromX , LONG FromY , LONG w , LONG h, LONG ToID , LONG ToX , LONG ToY , LONG AlphaBlend);
	BOOL BltStretch)(LONG FromID , LONG FromX , LONG FromY , LONG FromW , LONG FromH, LONG ToID , LONG ToX , LONG ToY , LONG ToW ,LONG ToH );
	BOOL Blt)(LONG FromID , LONG FromX , LONG FromY , LONG w , LONG h, LONG ToID , LONG ToX , LONG ToY );
	BOOL get_KeepFPS)(/*[out, retval]*/ BOOL *pVal);
	BOOL get_SoftwareFPS)(/*[out, retval]*/ LONG *pVal);
	BOOL put_SoftwareFPS)( LONG newVal);
	BOOL get_wTopMost)(/*[out, retval]*/ BOOL *pVal);
	BOOL put_wTopMost)( BOOL newVal);
	BOOL get_wHasBorder)(/*[out, retval]*/ BOOL *pVal);
	BOOL put_wHasBorder)( BOOL newVal);
	BOOL wDestroy)();
	BOOL get_wProcedure)(/*[out, retval]*/ LONG *pVal);
	BOOL put_wProcedure)( LONG newVal);
	BOOL GetTick)(/*[out,retval]*/LONG *Tick);
	BOOL wRunTimer)(LONG Interval);
	BOOL get_wResizeable)(/*[out, retval]*/ BOOL *pVal);
	BOOL put_wResizeable)( BOOL newVal);
	BOOL get_wHasTitleBar)(/*[out, retval]*/ BOOL *pVal);
	BOOL put_wHasTitleBar)( BOOL newVal);
	BOOL get_wHasCloseBtn)(/*[out, retval]*/ BOOL *pVal);
	BOOL put_wHasCloseBtn)( BOOL newVal);
	BOOL get_wHasMinBtn)(/*[out, retval]*/ BOOL *pVal);
	BOOL put_wHasMinBtn)( BOOL newVal);
	BOOL get_wHasMaxBtn)(/*[out, retval]*/ BOOL *pVal);
	BOOL put_wHasMaxBtn)( BOOL newVal);
	BOOL get_wEnable)(/*[out, retval]*/ BOOL *pVal);
	BOOL put_wEnable)( BOOL newVal);
	BOOL get_wVisible)(/*[out, retval]*/ BOOL *pVal);
	BOOL put_wVisible)( BOOL newVal);
	BOOL put_wCaption)( BSTR newVal);
	BOOL wYesNoMessage)(BSTR Message,BSTR Caption,/*[out,retval]*/BOOL *YesNo);
	BOOL wShowMessage)(BSTR Message,BSTR Caption);
	BOOL wMoveBy)(LONG x , LONG y);
	BOOL wMoveTo)(LONG x,LONG y);
	BOOL wResizeBy)(LONG w, LONG h);
	BOOL wResizeTo)(LONG w, LONG h);
	BOOL wGetHandle)(/*[out,retval]*/ LONG *HandleToWindow);
	BOOL DoEvents)(/*[out,retval]*/ BOOL *StillRunning );
	BOOL Run)( );
	BOOL wDefault)(  BSTR ProgramName );
};
#endif //__FACE_H_


extern CFACE *lpFACE;
extern TCHAR FACEDir[ MAX_PATH ];
extern HINSTANCE hInst;
extern SIZE		Screen;
extern LONG		dwDrawMode;
