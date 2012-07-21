#include "FACE_Sound_Assist.h"

BOOL BUFFERS::IsEmpty( ){
	return ( !SecBuf );
}
BUFFERS::BUFFERS( ){
	// SND_OPEN
	SndPts = NULL ;
	ZeroMemory( &ovFile , sizeof( ovFile ) );
	ZeroMemory( &WaveFormat, sizeof( WaveFormat) );
	BufferSize = 0;
	ReadFunc = NULL;
	SecBuf =NULL;
	IsLoopPlay = FALSE;
}
void BUFFERS::Make( BOOL IsStream ){
	DXObjInit( DSBUFFERDESC DSSD , DSSD );
	if ( IsStream ){
		// ストリーム再生用バッファ
		DSSD.dwFlags = DSBCAPS_GETCURRENTPOSITION2
						| DSBCAPS_GLOBALFOCUS
						| DSBCAPS_CTRLPOSITIONNOTIFY;
		DSSD.dwBufferBytes = WaveFormat.nAvgBytesPerSec * BufferSec ;
		lpFACE->LogPut( CONTINUE , IDS_LOG_BUFFER_STREAM , DSSD.dwBufferBytes );
	}else{
		DSSD.dwFlags = DSBCAPS_STATIC
						| DSBCAPS_GLOBALFOCUS;
		// スターてぃっくばっふぁ
		DSSD.dwBufferBytes = BufferSize;
		lpFACE->LogPut( CONTINUE , IDS_LOG_BUFFER_STATIC , DSSD.dwBufferBytes );
	}
	DSSD.lpwfxFormat = &WaveFormat;	
	ObjDS->CreateSoundBuffer( &DSSD , &SecBuf , NULL );
}
void BUFFERS::Stop( ){
	SecBuf->Stop();
	// 再生カーソルを戻す
	if ( SndPts == NULL )
		ov_time_seek( &ovFile , 0 );
	else
		fseek( SndPts , 0 , SEEK_SET );
	SecBuf->SetCurrentPosition( 0 );

	IsLoopPlay = FALSE;
}
void BUFFERS::Clear( ){
	if ( IsEmpty() )return;
	// バッファ開放
	SAFE_RELEASE( SecBuf );
	// ファイルの開放
	if ( SndPts == NULL ) ov_clear( &ovFile );
	lpFACE->LogBegin( _T( "BufferClear" ) );
	lpFACE->LogPut( CONTINUE , IDS_LOG_CREATE , this - &Buffers[ 0 ] );
	lpFACE->LogQuit( );
}
void BUFFERS::Buffer_Fill( BOOL IsStream ){
	LPSTR lpBlock1 , lpBlock2; DWORD BlockSize1 , BlockSize2 , CanWrite;
	LONG Ret; 
	LPSTR DsBuffer;

	if ( IsStream ){
		// ストリームなので初期化
		BufferSize = WaveFormat.nAvgBytesPerSec * BufferSec ;
		DsBuffer = (char*)
			HeapAlloc( GetProcessHeap( ) , HEAP_ZERO_MEMORY , 
			BufferSize + 1 );
	}else
		DsBuffer = (char*)
			HeapAlloc( GetProcessHeap( ) , HEAP_ZERO_MEMORY , BufferSize + 1 );
	ReadFunc( this , BufferSize , DsBuffer , &Ret );

	// LOCK
	SecBuf->Lock( 0 , BufferSize , 
		(LPVOID*)&lpBlock1 , &BlockSize1 , (LPVOID*)&lpBlock2 , &BlockSize2 , 0 );
	// DirectSoundBufferを初期化
	CanWrite = min( BufferSize , BlockSize1 );
	memcpy( lpBlock1 , DsBuffer , CanWrite );
	// リングの後端
	if ( lpBlock2 )	
		memcpy( lpBlock2 , DsBuffer + CanWrite , BufferSize - CanWrite );
	// 開放
	SecBuf->Unlock( lpBlock1  , BlockSize1 , lpBlock2 , BlockSize2 );
	SAFE_FREE( DsBuffer );
	if ( IsStream ) BufferSize /= 2;

	if ( Ret ) return ;
	// 読み切った
	if ( IsLoopPlay ){
		// ファイルポインタを戻す
		if ( SndPts == NULL )
			ov_time_seek( &ovFile , 0 );
		else
			fseek( SndPts , 0 , SEEK_SET );
	}else
		// 単純再生へ移行
		SecBuf->Play( 0 , 0 ,0 );
	return;
}}


long BUFFERS::Buffer_Keep(){
	LONG Ret ;
	LPSTR lpBlock1 , lpBlock2; 
	DWORD BlockSize1 , BlockSize2 , CanWrite;
	LPSTR DsBuffer;
	
	DsBuffer = (char*)
		HeapAlloc( GetProcessHeap( ) , HEAP_ZERO_MEMORY , BufferSize + 1 );
	ReadFunc( this , BufferSize , DsBuffer , &Ret );

	// LOCK
	SecBuf->Lock( BufferSize , BufferSize ,
		(LPVOID*)&lpBlock1 , &BlockSize1 , (LPVOID*)&lpBlock2 , &BlockSize2 , 0  );

	CanWrite = min( BufferSize , BlockSize1 );
	memcpy( lpBlock1 , DsBuffer + BufferSize, CanWrite );
	// バッファの終端越え
	if ( lpBlock2 )
		memcpy( lpBlock1 , DsBuffer + CanWrite+ BufferSize  , BufferSize - CanWrite );
	// バッファUNロック
	SecBuf->Unlock( lpBlock1  , BlockSize1 , lpBlock2 , BlockSize2 );
	SAFE_FREE( DsBuffer );

	if ( Ret == 0 ){
		// 読み切った
		if ( IsLoopPlay ){
			// ファイルポインタを戻す
			if ( SndPts == NULL )
				ov_time_seek( &ovFile , 0 );
			else
				fseek( SndPts , 0 , SEEK_SET );
		}else
			// 単純再生へ移行
			SecBuf->Play( 0 , 0 ,0 );
	}
	
	return Ret;
}
}