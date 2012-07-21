#include "wavread.h"

HRESULT wav_Open( BUFFERS *fp ){
	fseek( fp->SndPts , 0 , SEEK_SET );
	
	char Chunk[ 5 ] = ""; DWORD DataSize;
	
	// RIFFチャンクのリードとスキップ
	fread( Chunk, sizeof(char), 4 , fp->SndPts );
	if ( strcmp( "RIFF", Chunk ) != 0 ) 
		return E_FAIL;
	fread( &DataSize, sizeof(DataSize), 1, fp->SndPts );
	
	// WAVEの文字列を探す
	fread( Chunk , sizeof( char ) , 4 , fp->SndPts );
	if ( strcmp( "WAVE" , Chunk ) != 0 ) 
		return  E_FAIL;

	// Formatチャンクのリード
	fread( Chunk , sizeof( char ) , 4 , fp->SndPts );
	if ( strcmp( "fmt ", Chunk ) != 0)
		return E_FAIL;
	fread( &DataSize , sizeof( DataSize ) , 1 , fp->SndPts );

	// フォーマット取得
	fread( &fp->WaveFormat  , sizeof( WAVEFORMATEX ) - sizeof( WORD ) , 1 , fp->SndPts );
	
	// フォーマット情報の次へシーク
	fseek( fp->SndPts , DataSize - ( sizeof(WAVEFORMATEX) - sizeof(WORD) ) , SEEK_CUR );

	//  HRESULT wav_Reset( FILE *fp );
	
	// DATAチャンクの検索
	while ( 1 ){
		fread( Chunk , sizeof( char ) , 4 , fp->SndPts );
		if ( feof( fp->SndPts ) ) return E_FAIL;

		if ( strcmp( "data" ,Chunk ) == 0 ) break;
		else{
			// 違うらしい
			fread( &DataSize, sizeof(DWORD), 1, fp->SndPts );
			fseek( fp->SndPts ,  DataSize , SEEK_CUR );
		}
	}
	fread( &DataSize, sizeof(DWORD), 1, fp->SndPts );
	// 情報を格納する
	fp->BufferSize = DataSize;
	fp->BufferSize = DataSize;
	fp->ReadFunc = wav_Read;
    return S_OK;
}
LONG wav_Read( BUFFERS *fp , long nSizeToRead, char* pbData , long *Ret ){
	LONG i = fread( pbData ,  sizeof( char ) , nSizeToRead , fp->SndPts );
	if ( Ret != NULL ) *Ret = i;

	return S_OK;
}
