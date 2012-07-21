#include "oggread.h"
#include <math.h>

HRESULT ogg_Open( BUFFERS *fp ){
	if ( ov_open( fp->SndPts , &fp->ovFile , NULL , 0 ) == 0 ){
		// OGGVorbis ファイルだー！
		vorbis_info *vi;
		/* 詳細収得 */
		vi = ov_info( &fp->ovFile , -1 );
		if ( vi == NULL ) {
			ov_clear( &fp->ovFile );
			return E_FAIL;
		}
		fp->WaveFormat.cbSize          = sizeof(WAVEFORMATEX);
		fp->WaveFormat.wFormatTag      = WAVE_FORMAT_PCM;
		fp->WaveFormat.nChannels       = (WORD)vi->channels;
		fp->WaveFormat.nSamplesPerSec  = (WORD)vi->rate;
		fp->WaveFormat.nAvgBytesPerSec = (WORD)vi->rate * vi->channels * 2;
		fp->WaveFormat.nBlockAlign     = (WORD)vi->channels * 2;
		fp->WaveFormat.wBitsPerSample  = 2 * 8;
		fp->BufferSize = (long)ceil(
			vi->channels * vi->rate * ov_time_total(&fp->ovFile,-1) * 2);
		fp->ReadFunc = ogg_Read;

		return S_OK;
	}else
		return E_FAIL;
}
int current_section;
HRESULT ogg_Read( BUFFERS *fp , long nSizeToRead, char* pbData , long *ret ){
	long Readen , nSizeFrom = nSizeToRead;
	// プログレスの最大設定
	if ( EncodeDlg )
		SendMessage( GetDlgItem( EncodeDlg , IDC_DownProgress ) , 
			PBM_SETRANGE , 0 , MAKELONG( 0 , nSizeToRead /1000 ) );
	// バッファを埋める
	do{
		Readen = ov_read( &fp->ovFile , pbData , nSizeToRead , 0, 2, 1, &current_section);
		if ( Readen == 0 )
			return S_OK;
		nSizeToRead -= Readen; pbData += Readen;
		if ( EncodeDlg ){
			BOOL END; TCHAR BUF[256];
			wsprintf( BUF , _T( "  %d %% ( Remain %li / Total %li)" ) ,
				(long)((double)(nSizeFrom-nSizeToRead) / nSizeFrom * 100) , 
				nSizeToRead , nSizeFrom );
			SetWindowText( GetDlgItem( EncodeDlg , IDC_Prog ) , BUF );
			//進行状況表示
			SendMessage( GetDlgItem( EncodeDlg , IDC_DownProgress ) , 
				PBM_SETPOS , (nSizeFrom-nSizeToRead)  /1000, 0 );
			lpFACE->DoEvents( &END );
		}
	}while ( nSizeToRead > 0 );

	if ( ret != NULL ) *ret= nSizeFrom - nSizeToRead;
	return !( nSizeFrom == nSizeToRead );

}
