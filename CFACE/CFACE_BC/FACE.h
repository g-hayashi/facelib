#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdio.h>		/* StandardLibrary */
#include <stdlib.h>		/* ライブラリ */
#include <math.h>
#include <time.h>

/* -- FACEライブラリ -- */
#pragma comment(lib,"CFACE.lib")
	/* -- クラス構築マクロ -- */
	#define PropSheet( CLSNAME , ValType ) \
		class CLSNAME{\
		public: \
			ValType operator=(ValType); \
			operator ValType( ); \
		};
	#define FACEProp class
	#define FACEEvent class

// イベントはこの型に準拠する必要があります
typedef VOID (*SUBPROC)( LONG c );

PropSheet( MOUSEX , LONG );
PropSheet( MOUSEY , LONG );
PropSheet( wRESIZEABLE , BOOL );
PropSheet( wHASTITLEBAR , BOOL );
PropSheet( wHASCLOSEBTN , BOOL );
PropSheet( wHASMAXBTN , BOOL );
PropSheet( wHASMINBTN , BOOL );
PropSheet( wENABLE , BOOL );
PropSheet( wTOOLWIN , BOOL );
PropSheet( wHASBORDER , BOOL );
PropSheet( wTOPMOST , BOOL );
PropSheet( KEEPFPS , BOOL );
PropSheet( SOFTWAREFPS , LONG );
PropSheet( wPROCEDURE , WNDPROC );
PropSheet( wCAPTION , LPSTR );
PropSheet( wVISIBLE , BOOL );
PropSheet( OnSURFACELOST , SUBPROC );
PropSheet( OnMCIFAILURE , SUBPROC );
PropSheet( OnMCISUCCESS , SUBPROC );
PropSheet( OnSIZING, SUBPROC );
PropSheet( OnSIZE , SUBPROC );
PropSheet( OnMOVING , SUBPROC );
PropSheet( OnMOVE , SUBPROC );
PropSheet( OnMOUSEWHEEL , SUBPROC );
PropSheet( OnMOUSEUP , SUBPROC );
PropSheet( OnMOUSEDOWN , SUBPROC );
PropSheet( OnCOMMAND , SUBPROC );
PropSheet( OnKEYUP , SUBPROC );
PropSheet( OnKEYDOWN , SUBPROC );
PropSheet( OnDEACTIVE , SUBPROC );
PropSheet( OnACTIVE , SUBPROC );
	
class CFACE{
public:
	// コンストラクタ（起動処理
	CFACE();
	~CFACE();
	// FACE システム周り
	LONG GetFACEVer( );
	void Logging();

	void TickReset( );
	LONG GetTick( );
	// Window系関数
	void wDefault( LPSTR ProgramName );
	BOOL DoEvents( );
	void Run( );

	void wMoveBy	(LONG cx , LONG cy );
	void wMoveTo	(LONG x  , LONG y );
	void wResizeBy	(LONG cw , LONG ch );
	void wResizeTo	(LONG w  , LONG h );
	void wDestroy	();
	void wRunTimer	(LONG interval , SUBPROC TimerFACEEvent );
	BOOL wYesNoMessage( LPSTR Message , LPSTR Caption );
	void wShowMessage( LPSTR Message , LPSTR Caption );
	HWND wGetHandle( );

	FACEProp wPROCEDURE wProcedure;
	FACEProp wCAPTION wCaption;
	FACEProp wTOOLWIN wToolWin;
	FACEProp wHASBORDER wHasBorder;
	FACEProp wTOPMOST wTopMost;
	FACEProp wRESIZEABLE wResizeable;
	FACEProp wHASTITLEBAR wHasTitleBar;
	FACEProp wHASCLOSEBTN wHasCloseBtn;
	FACEProp wHASMAXBTN wHasMaxBtn;
	FACEProp wHASMINBTN wHasMinBtn;
	FACEProp wENABLE wEnable;
	FACEProp wVISIBLE wVisible;

	FACEEvent OnSIZING OnSizing;
	FACEEvent OnSIZE OnSize;
	FACEEvent OnMOVING OnMoving;
	FACEEvent OnMOVE OnMove;
	FACEEvent OnMOUSEWHEEL OnMouseWheel;
	FACEEvent OnMOUSEUP OnMouseUp;
	FACEEvent OnMOUSEDOWN OnMouseDown;
	FACEEvent OnCOMMAND OnCommand;
	FACEEvent OnKEYUP OnKeyUp;
	FACEEvent OnKEYDOWN OnKeyDown;
	FACEEvent OnDEACTIVE OnDeActive;
	FACEEvent OnACTIVE OnActive;
	FACEEvent OnSURFACELOST OnSurfaceLost;
	FACEEvent OnMCIFAILURE OnMCIFailure;
	FACEEvent OnMCISUCCESS OnMCISuccess;

	// 描画周り
	void Graphics( LONG lGraphMode );
	void Refresh( );

	void DrawBox( LONG x , LONG y , LONG w , LONG h , 
		LONG Color ,BOOL Fills , LONG SpriteID  = 0 );
	void DrawCircle( LONG x , LONG  y , LONG Radius , 
		LONG StartAngle , LONG EndAngle , LONG Color , 
		BOOL Fills, LONG SpriteID = 0 );
	void DrawEllipse( LONG x , LONG  y ,LONG wr , LONG hr , 
		LONG StartAngle , LONG EndAngle , LONG Color , 
		BOOL Close , LONG SpriteID = 0 );
	void DrawFill( LONG x , LONG y , LONG Color , LONG SpriteID = 0 );
	void DrawLine( LONG x1 , LONG  y1 , LONG x2 , LONG y2 , 
		LONG Color , LONG SpriteID = 0 );
	void DrawLineFromLP( LONG x , LONG  y , 
		LONG Color ,  LONG SpriteID = 0 );
	void DrawPixel( LONG x , LONG y , LONG Color , LONG SpriteID = 0 );
	void DrawPolygon( LONG x , LONG  y ,LONG wr , LONG hr , 
		LONG Polygon ,LONG Rotate ,
		LONG Color , BOOL Fills ,LONG SpriteID = 0 );
	void DrawRoundBox( LONG x , LONG  y , LONG w , LONG h , LONG Round , 
		LONG Color , BOOL Fills, LONG SpriteID = 0 );
	void DrawString( LONG x, LONG y , LPSTR Text , 
		LONG AlignData , LONG Color , LONG SpriteID = 0 );
	/* 設定関数群 */
	LONG DGetPixel(		LONG x,LONG y , LONG SpriteID = 0 );
	void DSetColorKey ( LONG Color    , LONG Non_Zero_SpriteID );
	void DSetFillStyle( LONG Style    , LONG SpriteID = 0 );
	void DSetLineStyle( LONG Style    , LONG SpriteID = 0 );
	void DSetLP(		LONG x,LONG y , LONG SpriteID = 0 );
	void DSetMapMode  ( LONG lMapMode , LONG SpriteID = 0 );
	void DSetOrigin   ( LONG x,LONG y , LONG SpriteID = 0 );
	void DSetRasterOP ( LONG lRasterOP, LONG SpriteID = 0 );
	void DSetTextSpace( LONG lSpace   , LONG SpriteID = 0 );
	void DSetTextFont( LONG Size , BOOL IsBold =0xFF, BOOL IsItalic =0xFF, BOOL IsUnderline =0xFF, BOOL IsStrike =0xFF, LPSTR FontName = "" , LONG SpriteID = 0 );
		// 転送メソッド
		void Blt		(	LONG FromID , LONG FromX , LONG FromY , LONG w , LONG h, 
							LONG ToID , LONG ToX , LONG ToY );
		void BltAlphaBlend( LONG FromID , LONG FromX , LONG FromY , LONG w , LONG h, 
							LONG ToID , LONG ToX , LONG ToY , 
							LONG lAlphaBlend);
		void BltStretch(	LONG FromID , LONG FromX , LONG FromY , LONG FromW , LONG FromH, 
							LONG ToID , LONG ToX , LONG ToY , LONG ToW ,LONG ToH );
		// Sprite管理
		void SpriteCopy ( LONG FromID , LONG ToID );
		void SpritePaste( LONG FromID , LONG ToID , LONG x , LONG y );
		void SpriteLoadFromFile( LONG SpriteID , LPSTR FileName );
		void SpriteResize( LONG SpriteID  , LONG cx , LONG cy );
		void SpriteState(  LONG SpriteID  , BOOL IsEnable );
		void SpriteView( );

	FACEProp SOFTWAREFPS SoftwareFPS;
	FACEProp KEEPFPS KeepFPS;
	
	// サウンド周り
	void Sound( LONG lSoundMode );
	void Snd_Open( LONG BufferID , LPSTR FileName  );
	void Snd_Play( LONG BufferID , LONG ShowDlg = 0 );
	void Snd_LoopPlay( LONG BufferID , LONG ShowDlg = 0 );
	void Snd_Pause( BOOL bPlay , LONG BufferID );
	void Snd_Stop( LONG BufferID );
	LONG Snd_GetData( LONG BufferID );
		// MCI直接命令
		void mci( LPSTR CMDStr , LPSTR FileName , LPSTR Optional );
	
	// FACE ファイル入出力
	void fClear( );
	void fOpen ( LPSTR FileName );
	void fReadInteger(  LPSTR Category , LPSTR KeyName , LONG  Default , LONG *RESULT );
	void fReadString(   LPSTR Category , LPSTR KeyName , LPSTR Default , LPSTR RESULT );
	void fWriteInteger( LPSTR Category , LPSTR KeyName , LONG  Dat );
	void fWriteString(  LPSTR Category , LPSTR KeyName , LPSTR Dat );
		// インターネットコネクション
		void Download( LPSTR URL , LPSTR FileName );

	// 入力管理
	BOOL InCheckPrev( short KeyCode );
	BOOL InCheck( short KeyCode );
	FACEProp MOUSEX MouseX;
	FACEProp MOUSEY MouseY;
};
const double Pai = 3.14159265;
const double Rad = Pai / 180;
const Left = 0 ;
const Right = 1 ;
const Center = 2 ;

/* メインマクロ */
#define FMain int APIENTRY WinMain( HINSTANCE , HINSTANCE , LPSTR, int )
#define FMAIN int APIENTRY WinMain( HINSTANCE , HINSTANCE , LPSTR, int )

/* -- その他マクロ -- */
#define iif(x,y,z) (x)?(y):(z)
#define niif(x,y) (x)?(y):(0)
#define sgn(x) iif( x > 0 , 1 , iif( x < 0 , -1 , 0 ) )
#define rnd(x) rand()%(x)
#define range(x,y,z) ( ( x > y ) && ( x < z ) ) 
#define rangeequ(x,y,z) ( ( x >= y ) && ( x <= z ) )
#define Randomize srand( (unsigned)time(NULL) )

#define ALICEBLUE 0xFFF0F8
#define ANTIQUEWHITE 0xD7FAEB
#define AQUA 0xFFFF00
#define AQUAMARINE 0xD47FFF
#define AZURE 0xFFFFF0
#define BEIGE 0xDCF5F5
#define BISQUE 0xC4E4FF
#define BLACK 0x000000
#define BLANCHEDALMOND 0xCDEBFF
#define BLUE 0xFF0000
#define BLUEVIOLET 0xE22B8A
#define BROWN 0x2A2AA5
#define BURLYWOOD 0x87B8DE
#define CADETBLUE 0xA09E5F
#define CHARTREUSE 0x00FF7F
#define CHOCOLATE 0x1E69D2
#define CORAL 0x507FFF
#define CORNFLOWER 0xED9564
#define CORNSILK 0xDCF8FF
#define CRIMSON 0x3C14DC
#define CYAN 0xFFFF00
#define DARKBLUE 0x8B0000
#define DARKCYAN 0x8B8B00
#define DARKGOLDENROD 0x0B86B8
#define DARKGRAY 0xA9A9A9
#define DARKGREEN 0x006400
#define DARKKHAKI 0x6BB7BD
#define DARKMAGENTA 0x8B008B
#define DARKOLIVEGREEN 0x2F6B55
#define DARKORANGE 0x008CFF
#define DARKORCHID 0xCC3299
#define DARKRED 0x00008B
#define DARKSALMON 0x7A96E9
#define DARKSEAGREEN 0x8BBC8F
#define DARKSLATEBLUE 0x8B3D48
#define DARKSLATEGRAY 0x4F4F2F
#define DARKTURQUOISE 0xD1CE00
#define DARKVIOLET 0xD30094
#define DEEPPINK 0x9314FF
#define DEEPSKYBLUE 0xFFBF00
#define DIMGRAY 0x696969
#define DODGERBLUE 0xFF901E
#define FIREBRICK 0x2222B2
#define FLORALWHITE 0xF0FAFF
#define FORESTGREEN 0x228B22
#define FUCHIA 0xFF00FF
#define GAINSBORO 0xDCDCDC
#define GHOSTWHITE 0xFFF8F8
#define GOLD 0x00D7FF
#define GOLDENROD 0x20A5DA
#define GRAY 0x808080
#define GREEN 0x008000
#define GREENYELLOW 0x2FFFAD
#define HONEYDEW 0xF0FFF0
#define HOTPINK 0xB469FF
#define INDIANRED 0x5C5CCD
#define INDIGO 0x82004B
#define IVORY 0xF0FFFF
#define KHAKI 0x8CE6F0
#define LAVENDER 0xFAE6E6
#define LAVENDERBLUSH 0xF5F0FF
#define LAWNGREEN 0x00FC7C
#define LEMONCHIFFON 0xCDFAFF
#define LIGHTBLUE 0xE6D8AD
#define LIGHTCORAL 0x8080F0
#define LIGHTCYAN 0xFFFFFE0
#define LIGHTGOLDENRODYELLOW 0xD2FAFA
#define LIGHTGREEN 0x90EE90
#define LIGHTGREY 0xD3D3D3
#define LIGHTPINK 0xC1B6FF
#define LIGHTSALMON 0x7AA0FF
#define LIGHTSEAGREEN 0xAAB220
#define LIGHTSKYBLUE 0xFACE87
#define LIGHTSLATEGRAY 0x998877
#define LIGHTSTEELBLUE 0xDEC4B0
#define LIGHTYELLOW 0xE0FFFF
#define LIME 0x00FF00
#define LIMEGREEN 0x32CD32
#define LINEN 0xE6F0FA
#define MAGENTA 0xFF00FF
#define MAROON 0x000080
#define MEDIUMAQUAMARINE 0xAACD66
#define MEDIUMBLUE 0xCD0000
#define MEDIUMORCHID 0xD355BA
#define MEDIUMPURPLE 0xDB7097
#define MEDIUMSEAGREEN 0x71B33C
#define MEDIUMSLATEBLUE 0xEE687B
#define MEDIUMSPRINGGREEN 0x9AFA00
#define MEDIUMTURQUOISE 0xCCD148
#define MEDIUMVIOLETRED 0x8515C7
#define MIDNIGHTBLUE 0x701919
#define MINTCREAM 0xFAFFF5
#define MISTYROSE 0xE1E4FF
#define MOCCASIN 0xB5E4FF
#define NAVAJOWHITE 0xADDEFF
#define NAVY 0x800000
#define OLDLACE 0xE6F5FD
#define OLIVE 0x008080
#define OLIVEDRAB 0x238E6B
#define ORANGE 0x00A5FF
#define ORANGERED 0x0045FF
#define ORCHID 0xD670DA
#define ALEGOLDENROD 0xAAE8EE
#define PALEGREEN 0x98FB98
#define PALETURQUOISE 0xEEEEAF
#define PALEVIOLETRED 0x9370DB
#define PAPAYAWHIP 0xD5EFFF
#define PEACHPUFF 0xB9DAFF
#define PERU 0x3F85CD
#define PINK 0xCBC0FF
#define PLUM 0xDDA0DD
#define POWDERBLUE 0xE6E0B0
#define PURPLE 0x800080
#define RED 0x0000FF
#define ROSYBROWN 0x8F8FBC
#define ROYALBLUE 0xE16941
#define SADDLEBROWN 0x13458B
#define SALMON 0x7280FA
#define SANDYBROWN 0x60A4F4
#define SEAGREEN 0x578B2E
#define SEASHELL 0xEEF5FF
#define SIENNA 0x2D52A0
#define SILVER 0xC0C0C0
#define SKYBLUE 0xEBCE87
#define SLATEBLUE 0xCD5A6A
#define SLATEGRAY 0x908070
#define SNOW 0xFAFAFF
#define SPRINGGREEN 0x7FFF00
#define STEELBLUE 0xB48246
#define TAN 0x8CB4D2
#define TEAL 0x808000
#define THISTLE 0xD8BFD8
#define TOMATO 0x4763FF
#define TURQUOISE 0xD0E040
#define VIOLET 0xEE82EE
#define WHEAT 0xB3DEF5
#define WHITE 0xFFFFFF
#define WHITESMOKE 0xF5F5F5
#define YELLOW 0x00FFFF
#define YELLOWGREEN 0x32CD9A

