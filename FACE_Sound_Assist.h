#include "stdafx.h"
#include "FACElib.h"
#include "FACE.h"

/* DirectSoundHeader */
#include <DSound.h>
#pragma comment (lib,"Dsound.lib" )
/* C++ Header */
#include <process.h>	// MultiThread系
#include <commctrl.h>	// ProgressBar関連(SoundLoader)
#pragma once

#include <vorbis/codec.h>
#include <vorbis/vorbisfile.h>

#define dwBufferNum 7
#define AllBuffers(i) ( i = 0 ; i <= dwBufferNum ; i++ )

#define BufferSec 5
/* SoundMode定義 */

#define SOUNDDISABLE 0
#define DSOUND 1

#define DSoundInitFailed { \
	LogPut( CONTINUE , IDS_LOG_DSOUNDFAILED ); \
	LogQuit( );\
	SoundRelease();\
	return S_OK;\
	}

#define SoundBegin { \
	CHECK_MODE( dwSndMode ); \
	CHECK_RANGE_STR( BufferID , 0 , dwBufferNum , "Sound系メソッド->BufferID" ); \
	CHECK_EMPTY_STR( Buffers,BufferID , "Sound系メソッド->Buffer" ); 

class BUFFERS;

typedef HRESULT (*READFUNCTION)( BUFFERS *fp , LONG nSizeToRead, 
								char* pbData , LONG *Ret );

class BUFFERS{
public:
	// 全て解放する関数
	BUFFERS( );
	void Clear( );
	// 作成
	void Make( BOOL StreamType );
	// あるか？
	BOOL IsEmpty( );
	// ＷＡＶファイルじゃない場合に使う特別な関数
		// General
	FILE *SndPts; BOOL IsLoopPlay;
		// Uses in OGG
	OggVorbis_File ovFile;
	// フォーマット情報
    WAVEFORMATEX WaveFormat;
	DWORD BufferSize;
	// 関数アクセス（引数が全て同じなので同一呼び出しが可能)
	READFUNCTION ReadFunc;
	
	void Stop() ;
	void Buffer_Fill( BOOL IsStream = 0 );
	long Buffer_Keep();
	// ダイレクトサウンドバッファ
	IDirectSoundBuffer *SecBuf;	
};
// DirectSound
extern IDirectSound			*ObjDS;
extern IDirectSoundNotify	*Notify;
extern BUFFERS				Buffers[ dwBufferNum + 1 ]; // Buffers Class
extern HANDLE				hEvent[ 3 ];  // Event Handle
extern BYTE					dwSndMode;
extern HWND EncodeDlg;
