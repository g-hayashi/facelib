#include "stdafx.h"
#include "FACElib.h"
#include "FACE.h"

/* DirectSoundHeader */
#include <DSound.h>
#pragma comment (lib,"Dsound.lib" )
/* C++ Header */
#include <process.h>	// MultiThread�n
#include <commctrl.h>	// ProgressBar�֘A(SoundLoader)
#pragma once

#include <vorbis/codec.h>
#include <vorbis/vorbisfile.h>

#define dwBufferNum 7
#define AllBuffers(i) ( i = 0 ; i <= dwBufferNum ; i++ )

#define BufferSec 5
/* SoundMode��` */

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
	CHECK_RANGE_STR( BufferID , 0 , dwBufferNum , "Sound�n���\�b�h->BufferID" ); \
	CHECK_EMPTY_STR( Buffers,BufferID , "Sound�n���\�b�h->Buffer" ); 

class BUFFERS;

typedef HRESULT (*READFUNCTION)( BUFFERS *fp , LONG nSizeToRead, 
								char* pbData , LONG *Ret );

class BUFFERS{
public:
	// �S�ĉ������֐�
	BUFFERS( );
	void Clear( );
	// �쐬
	void Make( BOOL StreamType );
	// ���邩�H
	BOOL IsEmpty( );
	// �v�`�u�t�@�C������Ȃ��ꍇ�Ɏg�����ʂȊ֐�
		// General
	FILE *SndPts; BOOL IsLoopPlay;
		// Uses in OGG
	OggVorbis_File ovFile;
	// �t�H�[�}�b�g���
    WAVEFORMATEX WaveFormat;
	DWORD BufferSize;
	// �֐��A�N�Z�X�i�������S�ē����Ȃ̂œ���Ăяo�����\)
	READFUNCTION ReadFunc;
	
	void Stop() ;
	void Buffer_Fill( BOOL IsStream = 0 );
	long Buffer_Keep();
	// �_�C���N�g�T�E���h�o�b�t�@
	IDirectSoundBuffer *SecBuf;	
};
// DirectSound
extern IDirectSound			*ObjDS;
extern IDirectSoundNotify	*Notify;
extern BUFFERS				Buffers[ dwBufferNum + 1 ]; // Buffers Class
extern HANDLE				hEvent[ 3 ];  // Event Handle
extern BYTE					dwSndMode;
extern HWND EncodeDlg;
