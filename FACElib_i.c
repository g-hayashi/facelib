/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Tue Jun 12 00:15:10 2007
 */
/* Compiler settings for D:\MyProgramming_n\FACE_SRC\FACElib\FACElib.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )
#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

const IID IID_IFACE = {0x8F67CBF4,0xA0A3,0x4144,{0x99,0x85,0xAE,0xF9,0x62,0x3F,0xD3,0x17}};


const IID LIBID_FACELIB = {0x9873C60F,0xB912,0x4D2A,{0xBD,0x23,0x23,0xCA,0x1A,0xC2,0x26,0x3B}};


const CLSID CLSID_FACE = {0xD07551AA,0xAB43,0x4C28,{0xA0,0x8A,0xB9,0xE3,0xB7,0x4E,0x93,0xDF}};


#ifdef __cplusplus
}
#endif

