#include <atlbase.h>
#include "FACE.h"
#include "FACElib.h"
#include "FACElib_i.c"


	// Private  内部保持Interface
	IFACE *iFACE;

CFACE::CFACE(){

	CoInitialize( NULL );
    CoCreateInstance( CLSID_FACE, NULL, CLSCTX_ALL,
		IID_IFACE, (LPVOID *)&(iFACE) );

	if ( iFACE == NULL ){
		MessageBox( NULL ,
			"エラー CoCreateInstanceがNULLを返しました。\nFACElib Unregistered\n\n対処法 コマンドラインで regsvr32 FACElib_100.dll" ,
			"FACE Create Failed"  , 0 );
		return;
	}
}
CFACE::~CFACE(){
	iFACE->Release( );
	CoUninitialize();
}
void CFACE::wDefault( LPSTR ProgramName ){
	USES_CONVERSION;

	iFACE->wDefault( A2OLE( ProgramName ) );
}
LONG CFACE::GetFACEVer( ){
	LONG Ret ; iFACE->GetFACEVer( &Ret ); return Ret;
}
void CFACE::Logging(){
	iFACE->Logging();
}
#define Method_Sub(x) void CFACE::x( ){iFACE->x( );}
#define Method_Get(x,y) y CFACE::x( ){ y Ret;iFACE->x(&Ret);return Ret;}
#define Method_Get2(x,y,c) y CFACE::x( ){ y Ret;iFACE->x((c*)&Ret);return Ret;}
#define Method_Prop(x,putms,getms) \
	BOOL x::operator=( BOOL Flagment ){ \
		iFACE->putms( Flagment) ; return Flagment; }\
	x::operator BOOL(){ BOOL ret;iFACE->getms(&ret);return ret;}
#define Method_WNDPROC(x,putms,getms) \
	WNDPROC x::operator=( WNDPROC Flagment ){ \
		iFACE->putms( (LONG)Flagment) ; return Flagment; }\
	x::operator WNDPROC(){ LONG ret;iFACE->getms(&ret);return (WNDPROC)ret;}
#define Method_Event(x,putms,getms) \
	SUBPROC x::operator=( SUBPROC Flagment ){ \
		iFACE->putms( (LONG)Flagment) ; return Flagment; }\
	x::operator SUBPROC(){ LONG ret;iFACE->getms(&ret);return (SUBPROC)ret;}

Method_Sub( TickReset );
Method_Get( GetTick , LONG );
Method_Get( DoEvents , BOOL );
Method_Sub( Run );
void CFACE::wMoveBy	(LONG cx , LONG cy ){iFACE->wMoveBy(cx,cy);}
void CFACE::wMoveTo	(LONG x  , LONG y ){iFACE->wMoveTo(x,y);}
void CFACE::wResizeBy	(LONG cw , LONG ch ){iFACE->wResizeBy( cw ,ch );}
void CFACE::wResizeTo	(LONG w  , LONG h ){iFACE->wResizeTo(w,h);}
Method_Sub( wDestroy );
void CFACE::wRunTimer	(LONG interval , SUBPROC TimerEvent ){
	iFACE->wRunTimer( interval , (LONG)TimerEvent ); }
BOOL CFACE::wYesNoMessage( LPSTR Message , LPSTR Caption ){USES_CONVERSION;
	BOOL Ret;iFACE->wYesNoMessage( A2OLE(Message),A2OLE(Caption),&Ret);return Ret;}
void CFACE::wShowMessage( LPSTR Message , LPSTR Caption ){USES_CONVERSION;
	iFACE->wShowMessage( A2OLE(Message),A2OLE(Caption));}
Method_Get2( wGetHandle, HWND , LONG );

Method_WNDPROC( wPROCEDURE , put_wProcedure , get_wProcedure );
	LPSTR wCAPTION::operator=( LPSTR Flagment ){ USES_CONVERSION;
		iFACE->put_wCaption( A2OLE(Flagment) ) ; return Flagment; }
Method_Prop( wTOOLWIN , put_wToolWin , get_wToolWin );
Method_Prop( wHASBORDER , put_wHasBorder , get_wHasBorder );
Method_Prop( wTOPMOST , put_wTopMost , get_wTopMost );
Method_Prop( wRESIZEABLE , put_wResizeable, get_wResizeable );
Method_Prop( wHASTITLEBAR, put_wHasTitleBar , get_wHasTitleBar );
Method_Prop( wHASCLOSEBTN , put_wHasCloseBtn , get_wHasCloseBtn );
Method_Prop( wHASMAXBTN , put_wHasMaxBtn , get_wHasMaxBtn );
Method_Prop( wHASMINBTN , put_wHasMinBtn , get_wHasMinBtn );
Method_Prop( wENABLE, put_wEnable , get_wEnable );
Method_Prop( wVISIBLE , put_wVisible , get_wVisible );

Method_Event( OnSIZING , put_OnSizing, get_OnSizing );
Method_Event( OnSIZE , put_OnSize, get_OnSize );
Method_Event( OnMOVING , put_OnMoving, get_OnMoving );
Method_Event( OnMOVE , put_OnMove, get_OnMove );
Method_Event( OnMOUSEWHEEL , put_OnMouseWheel, get_OnMouseWheel );
Method_Event( OnMOUSEUP , put_OnMouseUp, get_OnMouseUp );
Method_Event( OnMOUSEDOWN , put_OnMouseDown, get_OnMouseDown );
Method_Event( OnCOMMAND , put_OnCommand, get_OnCommand );
Method_Event( OnKEYUP , put_OnKeyUp ,get_OnKeyUp );
Method_Event( OnKEYDOWN , put_OnKeyDown, get_OnKeyDown );
Method_Event( OnDEACTIVE , put_OnDeActive, get_OnDeActive );
Method_Event( OnACTIVE , put_OnActive, get_OnActive );
Method_Event( OnSURFACELOST , put_OnActive, get_OnActive );
Method_Event( OnMCIFAILURE , put_OnMCIFailure, get_OnMCIFailure );
Method_Event( OnMCISUCCESS , put_OnMCISuccess, get_OnMCISuccess );

void CFACE::Graphics	(LONG GraphicsMode ){iFACE->Graphics(GraphicsMode);}
Method_Sub( Refresh );
	// 描画周り

void CFACE::DrawBox( LONG x , LONG y , LONG w , LONG h , 
					LONG Color ,BOOL Fills , LONG SpriteID  ){
	iFACE->DrawBox( x,y,w,h,Color,Fills,SpriteID );
}
void CFACE::DrawCircle( LONG x , LONG  y , LONG Radius , 
		LONG StartAngle , LONG EndAngle , LONG Color , 
		BOOL Fills, LONG SpriteID  ){
	iFACE->DrawCircle( x,y,Radius,StartAngle,EndAngle,Color,Fills,SpriteID);
}
void CFACE::DrawEllipse( LONG x , LONG  y ,LONG wr , LONG hr , 
		LONG StartAngle , LONG EndAngle , LONG Color , 
		BOOL Close , LONG SpriteID ){
	iFACE->DrawEllipse( x,y,wr,hr,StartAngle,EndAngle,Color,Close,SpriteID);
}
void CFACE::DrawFill( LONG x , LONG y , LONG Color , LONG SpriteID ){
	iFACE->DrawFill(x,y,Color,SpriteID);
}
void CFACE::DrawLine( LONG x1 , LONG  y1 , LONG x2 , LONG y2 , 
					 LONG Color , LONG SpriteID  ){
	iFACE->DrawLine(x1,y1,x2,y2,Color,SpriteID);
}
void CFACE::DrawLineFromLP( LONG x , LONG  y ,
						   LONG Color ,  LONG SpriteID ){
	iFACE->DrawLineFromLP(x,y,Color,SpriteID);
}
void CFACE::DrawPixel( LONG x , LONG y , LONG Color , LONG SpriteID  ){
	iFACE->DrawPixel(x,y,Color,SpriteID);
}
void CFACE::DrawPolygon( LONG x , LONG  y ,LONG wr , LONG hr , 
		LONG Polygon ,LONG Rotate ,
		LONG Color , BOOL Fills ,LONG SpriteID ){
	iFACE->DrawPolygon( x,y,wr,hr,Polygon,Rotate,Color,Fills,SpriteID);
}
void CFACE::DrawRoundBox( LONG x , LONG  y , LONG w , LONG h , LONG Round , 
				  LONG Color , BOOL Fills, LONG SpriteID ){
	iFACE->DrawRoundBox(x,y,w,h,Round,Color,Fills,SpriteID);
}
void CFACE::DrawString( LONG x, LONG y , LPSTR Text , 
				LONG AlignData , LONG Color , LONG SpriteID ){USES_CONVERSION;
	iFACE->DrawString(x,y,A2OLE(Text),AlignData,Color,SpriteID);
}
	/* 設定関数群 */
LONG CFACE::DGetPixel(		LONG x,LONG y , LONG SpriteID ){
	LONG Ret;iFACE->DGetPixel(x,y,SpriteID,&Ret);return Ret;
}
void CFACE::DSetColorKey ( LONG Color    , LONG Non_Zero_SpriteID ){
	iFACE->DSetColorKey(Color,Non_Zero_SpriteID);
}
void CFACE::DSetFillStyle( LONG Style    , LONG SpriteID){
	iFACE->DSetFillStyle(Style,SpriteID);
}	
void CFACE::DSetLineStyle( LONG Style    , LONG SpriteID ){
	iFACE->DSetLineStyle(Style,SpriteID);
}
void CFACE::DSetLP(		LONG x,LONG y , LONG SpriteID ){
	iFACE->DSetLP(x,y,SpriteID);
}
void CFACE::DSetMapMode  ( LONG MapMode  , LONG SpriteID ){
	iFACE->DSetMapMode(MapMode,SpriteID);
}
void CFACE::DSetOrigin   ( LONG x,LONG y , LONG SpriteID ){
	iFACE->DSetOrigin(x,y,SpriteID);
}
void CFACE::DSetRasterOP ( LONG RasterOP , LONG SpriteID ){
	iFACE->DSetRasterOP(RasterOP,SpriteID);
}
void CFACE::DSetTextSpace( LONG lSpace   , LONG SpriteID ){
	iFACE->DSetTextSpace(lSpace,SpriteID);
}
void CFACE::DSetTextFont( LONG Size , BOOL IsBold , BOOL IsItalic , BOOL IsUnderline , BOOL IsStrike , LPSTR FontName , LONG SpriteID ){USES_CONVERSION;
	iFACE->DSetTextFont(Size,IsBold,IsItalic,IsUnderline,IsStrike,A2OLE( FontName),SpriteID);
}
		// 転送メソッド
		void CFACE::Blt		(	LONG FromID , LONG FromX , LONG FromY , LONG w , LONG h, 
			LONG ToID , LONG ToX , LONG ToY ){
				iFACE->Blt( FromID,FromX,FromY,w,h,ToID,ToX,ToY);
		}
		void CFACE::BltAlphaBlend( LONG FromID , LONG FromX , LONG FromY , LONG w , LONG h, 
							LONG ToID , LONG ToX , LONG ToY , 
							LONG AlphaBlend){
			iFACE->BltAlphaBlend(FromID,FromX,FromY,w,h,ToID,ToX,ToY,AlphaBlend);
		}
		void CFACE::BltStretch(	LONG FromID , LONG FromX , LONG FromY , LONG FromW , LONG FromH, 
			LONG ToID , LONG ToX , LONG ToY , LONG ToW ,LONG ToH ){
			iFACE->BltStretch(FromID,FromX,FromY,FromW,FromH,ToID,ToX,ToY,ToW,ToH);
		}
		// Sprite管理
		void CFACE::SpriteCopy ( LONG FromID , LONG ToID ){
			iFACE->SpriteCopy(FromID,ToID);
		}
		void CFACE::SpritePaste( LONG FromID , LONG ToID , LONG x , LONG y ){
			iFACE->SpritePaste(FromID,ToID,x,y);
		}
		void CFACE::SpriteLoadFromFile( LONG SpriteID , LPSTR FName ){USES_CONVERSION;
			iFACE->SpriteLoadFromFile(SpriteID,A2OLE(FName));
		}
		void CFACE::SpriteResize( LONG SpriteID  , LONG cx , LONG cy )
		{
			iFACE->SpriteResize(SpriteID,cx,cy);
		}
		void CFACE::SpriteState(  LONG SpriteID  , BOOL IsEnable ){
			iFACE->SpriteState(SpriteID,IsEnable);
		}
		void SpriteView( ){
			iFACE->SpriteView();
		}

		LONG SOFTWAREFPS::operator=( LONG Flagment ){ \
			iFACE->put_SoftwareFPS( Flagment) ; return Flagment; }\
		SOFTWAREFPS::operator LONG(){ LONG ret;iFACE->get_SoftwareFPS(&ret);return ret;}
		BOOL KEEPFPS::operator=( BOOL Flagment ){ 
			return 0; }
		KEEPFPS::operator BOOL(){BOOL Ret ;iFACE->get_KeepFPS( &Ret);return Ret;}
	
	// サウンド周り
		void CFACE::Sound( LONG dwSndMode ){iFACE->Sound(dwSndMode);}
		void CFACE::Snd_Open( LONG BufferID,LPSTR FName ){USES_CONVERSION;
			iFACE->Snd_Open( BufferID,A2OLE(FName) );
		}
		void CFACE::Snd_Play( LONG BufferID , LONG ShowDlg ){
			iFACE->Snd_Play(ShowDlg);
		}
		void CFACE::Snd_LoopPlay( LONG BufferID , LONG ShowDlg ){
			iFACE->Snd_LoopPlay(BufferID);
		}
		void CFACE::Snd_Pause( BOOL bPlay , LONG BufferID ){
			iFACE->Snd_Pause(bPlay,BufferID);
		}
		void CFACE::Snd_Stop( LONG BufferID ){
			iFACE->Snd_Stop(BufferID);
		}
		LONG CFACE::Snd_GetData( LONG BufferID ){
			LONG Ret;
			iFACE->Snd_GetData( BufferID , &Ret );return Ret;
		}
		// MCI直接命令
		void CFACE::mci( LPSTR CMDStr , LPSTR FName , LPSTR Optional ){ USES_CONVERSION;
			iFACE->mci( A2OLE(CMDStr),A2OLE(FName),A2OLE(Optional) );
		}
	
	// FACE ファイル入出力
		void CFACE::fClear( ){
			iFACE->fClear();
		}

#define CONVERS { USES_CONVERSION;
	void CFACE::fOpen ( LPSTR FName ) CONVERS
		iFACE->fOpen( A2OLE(FName) );
	}
	void CFACE::fReadInteger(  LPSTR Category , LPSTR KeyName , LONG  Default , LONG *RESULT ) CONVERS
		iFACE->fReadInteger(A2OLE(Category ), A2OLE(KeyName),Default,RESULT);
	}
	void CFACE::fReadString(   LPSTR Category , LPSTR KeyName , LPSTR Default , LPSTR RESULT ) CONVERS
		iFACE->fReadString( A2OLE(Category), A2OLE(KeyName),A2OLE(Default),A2OLE(RESULT));
	}
	void CFACE::fWriteInteger( LPSTR Category , LPSTR KeyName , LONG  Dat ) CONVERS
		iFACE->fWriteInteger(A2OLE(Category ), A2OLE(KeyName),Dat);
	}
	void CFACE::fWriteString(  LPSTR Category , LPSTR KeyName , LPSTR Dat ) CONVERS
		iFACE->fWriteString(A2OLE(Category ), A2OLE(KeyName),A2OLE(Dat));
	}
		// インターネットコネクション
		void CFACE::Download( LPSTR URL , LPSTR FName ) CONVERS
			iFACE->Download( A2OLE(URL),A2OLE(FName));
		}

	// 入力管理
	BOOL CFACE::InCheckPrev( short KeyCode ){BOOL Ret;iFACE->InCheckPrev(KeyCode,&Ret);return Ret;}
	BOOL CFACE::InCheck( short KeyCode ){BOOL Ret;iFACE->InCheck(KeyCode,&Ret);return Ret;}
		LONG MOUSEX::operator=( LONG Flagment ){ \
			iFACE->put_MouseX( Flagment) ; return Flagment; }\
		MOUSEX::operator LONG(){ LONG ret;iFACE->get_MouseX(&ret);return ret;}
		LONG MOUSEY::operator=( LONG Flagment ){ \
			iFACE->put_MouseY( Flagment) ; return Flagment; }\
		MOUSEY::operator LONG(){ LONG ret;iFACE->get_MouseY(&ret);return ret;}




