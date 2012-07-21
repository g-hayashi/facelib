#include "oggread.h"
#include "wavread.h"

 IDirectSound		*ObjDS;
 IDirectSoundNotify	*Notify;
 BUFFERS			Buffers[ dwBufferNum + 1]; // Buffers Class
 HANDLE				hEvent[ 3 ];  // Event Handle
 BYTE				dwSndMode;
 HWND				EncodeDlg;

 void CFACE::SoundRelease( ){
	if ( dwSndMode == SOUNDDISABLE )return;
	// �C�x���g�n���h�����J��
	for ( int i = 0 ; i < 3 ; i++ ){
		CloseHandle( hEvent[ i ] ); hEvent[ i ] = NULL; }
	int j ; for AllBuffers( j ) Buffers[ j ].Clear( );

	// DirectSound�̊J��
	SAFE_RELEASE( Notify );
	SAFE_RELEASE( ObjDS );
	dwSndMode = SOUNDDISABLE;
	LogBegin( _T( "Sounds Destraction" ) );
	LogQuit( );
}
	void CFACE::SoundClear( ){
		dwSndMode	= SOUNDDISABLE;
		ObjDS		= NULL;
		Notify		= NULL;
		ZeroMemory( hEvent , sizeof( hEvent ) );
	}

/*------------------------
	�C�j�V�����C�Y
  -------------------------*/
STDMETHODIMP CFACE::Sound( LONG DSMODE ){ if ( DSMODE == dwSndMode ) return S_OK;
	// ���O�ɋL�q
		LogBegin( "Sounds Initializer" );
		LogPut( CONTINUE , IDS_LOG_MODEOUT , DSMODE ); 

	// �n���h���`�F�b�N
		CHECK_HWND;
	// �O���t�B�b�N�萔�͈̓`�F�b�N
		CHECK_RANGE( DSMODE , 0 , 1 );

	// �g�p���Ȃ����[�h
	if ( DSMODE == SOUNDDISABLE ) SoundRelease( ); 
	else{
		SoundRelease( );	// �S���
		// DirectSound ���쐬����B
		if ( FAILED( DirectSoundCreate( NULL , &ObjDS , NULL ) ) )
			DSoundInitFailed;
		// �������x����ݒ肷��
		if ( FAILED( ObjDS->SetCooperativeLevel( hWnd , DSSCL_NORMAL ) ) )
			DSoundInitFailed;
		// �C�x���g�̍쐬
		// at Half, at EndPos , FinallyHandler at Half
		for ( int i = 0 ; i < 3 ; i++ ) 
			hEvent[ i ] = CreateEvent( NULL , FALSE , FALSE , NULL );
	}
	dwSndMode = (BYTE)DSMODE;
	LogQuit( );
	return S_OK;
}
/* -------------------------------
	�X�g���[���Đ��̃X���b�h
  --------------------------------*/
void CFACE::PlayThread( LPVOID param ){
	BUFFERS *lpBuffer = (BUFFERS*)param;
	// �f�[�^�������݃��[�v
	while ( TRUE ){
		// �C�x���g�R�[�h�̎擾
		int i = WaitForMultipleObjects( 3 , hEvent , FALSE , INFINITE );

		if ( lpFACE->EndFlag ) break;
		// �C�x���g��������C���ꂩ��Đ������u���b�N�̎��̃u���b�N�ɏ�������
		if ( i  == WAIT_OBJECT_0 )
			lpBuffer->Buffer_Keep(  );
		else if ( i  == WAIT_OBJECT_0 + 1 )
			lpBuffer->Buffer_Fill( 1 );
		else if ( i ==  WAIT_OBJECT_0 + 2 ){
			lpBuffer->Stop( ); break; }
	}
	return ;
}
INT_PTR CALLBACK EncodeProc( HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM ){ return FALSE; }
STDMETHODIMP CFACE::Snd_Open( LONG BufferID , BSTR FileName ){
	USES_CONVERSION;
	// �J�n
	LogBegin( _T( "Snd_Open" ) );
	//���[�h�`�F�b�N�Ɣ͈̓`�F�b�N
	CHECK_MODE( dwSndMode );
	CHECK_RANGE_STR( BufferID , 0 , dwBufferNum , "Sound�n�֐�(Snd_Open)->BufferID" );
	/* �X�v���C�g�ւ̃A�N�Z�X�|�C���^ -- */
	BUFFERS *lpBuffer = &Buffers[ BufferID ];
	lpBuffer->Clear( );
	/* �t�@�C���ւ̃p�X���擾���� */
	// ���O�A�E�g
	LogPut( CONTINUE , IDS_LOG_LOADFROMFILE , OLE2T( FileName ) , BufferID );
	TCHAR FilePath[ MAX_PATH ] , lpFormatStr[ 64 ];
	if ( !GetFilePath( OLE2T( FileName ) , FilePath ) )
		LogPut( FATAL , IDS_ERR_FILENOTFOUND );
	lpBuffer->SndPts = fopen( FilePath , _T( "rb" ) );
	
	// Check OGG Vorbis File?
	if ( ogg_Open( lpBuffer ) != S_OK ){
		// Check WAV File?
		if ( wav_Open( lpBuffer ) != S_OK )
			LogPut( FATAL , IDS_ERR_INVALIDFILE );
		else
			lstrcpy( lpFormatStr ,  _T( " ** WavFile **" ) );
	}else
		lstrcpy( lpFormatStr , _T(" ** OGGVorbisFile ** " ) );

	// SoundBuffer�\�z�\���̂�������
	lpBuffer->Make( BufferID == 0 );
	/* Notify��` */
	if ( BufferID == 0 ){
		SAFE_RELEASE( Notify );
		// DirectSoundNotify�̍쐬
		lpBuffer->SecBuf->QueryInterface( IID_IDirectSoundNotify ,(LPVOID*)&Notify );

		DSBPOSITIONNOTIFY pn[3];
			pn[0].dwOffset = lpBuffer->WaveFormat.nAvgBytesPerSec * BufferSec - 1;
			pn[0].hEventNotify = hEvent[ 0 ];
			pn[1].dwOffset = lpBuffer->WaveFormat.nAvgBytesPerSec * BufferSec / 2;
			pn[1].hEventNotify = hEvent[ 1 ];
			pn[2].dwOffset = DSBPN_OFFSETSTOP;	// �Đ���~
			pn[2].hEventNotify = hEvent[ 2 ];
		Notify->SetNotificationPositions( 3 , pn );		
	}
	// ���O�A�E�g
	LogPut( CONTINUE , IDS_LOG_SOUNDINFO , lpFormatStr );
	LogQuit( );
	return S_OK;
}
BOOL CFACE::Inner_Snd_Play( LONG BufferID , LONG ShowDlg , BOOL Loop ){
	EncodeDlg = ShowDlg ?
			CreateDialog( hInst ,MAKEINTRESOURCE( IDD_Encoding ) , 
			hWnd , (DLGPROC)EncodeProc ) : NULL ;

	Buffers[ BufferID ].Buffer_Fill( BufferID == 0 );
	Buffers[ BufferID ].IsLoopPlay = Loop;
	
	if ( BufferID == 0 ){
		// DirectPlay�Đ�
		Buffers[ BufferID ].SecBuf->Play( 0 , 0, DSBPLAY_LOOPING );
		// �Đ��p�X���b�h�����
		_beginthread( PlayThread , 0 , &Buffers[ BufferID ] );
	}else
		Buffers[ BufferID ].SecBuf->Play( 0 , 0, ( Loop ? DSBPLAY_LOOPING : 0 ) );
	
	if ( EncodeDlg ) DestroyWindow( EncodeDlg );
	
	return 0;
}
STDMETHODIMP CFACE::Snd_Play( LONG BufferID ,LONG ShowDlg ){
	CHECK_MODE( dwSndMode ); 
	CHECK_RANGE_STR( BufferID , 0 , dwBufferNum , "Sound�n���\�b�h->BufferID" ); 
	CHECK_EMPTY_STR( Buffers,BufferID , "Sound�n���\�b�h->Buffer" ); 
	Inner_Snd_Play( BufferID , ShowDlg , FALSE ); 

	return S_OK;
}
STDMETHODIMP CFACE::Snd_LoopPlay( LONG BufferID , LONG ShowDlg ){
	CHECK_MODE( dwSndMode ); 
	CHECK_RANGE_STR( BufferID , 0 , dwBufferNum , "Sound�n���\�b�h->BufferID" ); 
	CHECK_EMPTY_STR( Buffers,BufferID , "Sound�n���\�b�h->Buffer" ); 
	Inner_Snd_Play( BufferID , ShowDlg , TRUE ); 
	
	return S_OK;
}
STDMETHODIMP CFACE::Snd_Stop(LONG BufferID)
SoundBegin
	// ����
	Buffers[ BufferID ].Stop( );
	return S_OK;
}
STDMETHODIMP CFACE::Snd_Pause(BOOL bPlay, LONG BufferID)
SoundBegin
	// ����
	if ( bPlay ) 
		// DirectPlay�Đ�
		Buffers[ BufferID ].SecBuf->Play( 
			0 , 0, ( Buffers[ BufferID ].IsLoopPlay ? DSBPLAY_LOOPING : 0 ) );
	else
		Buffers[ BufferID ].SecBuf->Stop( );
	return S_OK;
}

STDMETHODIMP CFACE::mci( BSTR CMDStr, BSTR FName, BSTR Optional){
	TCHAR MCICommandStr[ 1024 ];
	USES_CONVERSION;
	// Make Command Strings
	wsprintf( MCICommandStr , _T( "%s \"%s\" %s" ) , 
		OLE2T( CMDStr ) , OLE2T( FName ) , OLE2T( Optional ) );
	// Log
	LogBegin( "MCI" );
	LogPut( CONTINUE , IDS_LOG_MCISTRING , MCICommandStr );
	MCIERROR mciErr = mciSendString( MCICommandStr , NULL , 
		0 , hWnd );
	mciGetErrorString( mciErr , MCICommandStr , 1024 );
	LogPut( CONTINUE , IDS_LOG_MCIERROR , MCICommandStr );
	LogQuit( );

	return S_OK;
}