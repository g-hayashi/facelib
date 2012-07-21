#include "FACE_Sound_Assist.h"

#pragma comment(lib,"vorbis_static_d.lib")
#pragma comment(lib,"ogg_static_d.lib")
#pragma comment(lib,"vorbisfile_static_d.lib")

HRESULT ogg_Open( BUFFERS *fp );
HRESULT ogg_Read( BUFFERS *fp , long nSizeToRead, char* pbData , long *Ret  );

