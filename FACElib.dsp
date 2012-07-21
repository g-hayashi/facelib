# Microsoft Developer Studio Project File - Name="FACElib" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** 編集しないでください **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=FACElib - Win32 More
!MESSAGE これは有効なﾒｲｸﾌｧｲﾙではありません。 このﾌﾟﾛｼﾞｪｸﾄをﾋﾞﾙﾄﾞするためには NMAKE を使用してください。
!MESSAGE [ﾒｲｸﾌｧｲﾙのｴｸｽﾎﾟｰﾄ] ｺﾏﾝﾄﾞを使用して実行してください
!MESSAGE 
!MESSAGE NMAKE /f "FACElib.mak".
!MESSAGE 
!MESSAGE NMAKE の実行時に構成を指定できます
!MESSAGE ｺﾏﾝﾄﾞ ﾗｲﾝ上でﾏｸﾛの設定を定義します。例:
!MESSAGE 
!MESSAGE NMAKE /f "FACElib.mak" CFG="FACElib - Win32 More"
!MESSAGE 
!MESSAGE 選択可能なﾋﾞﾙﾄﾞ ﾓｰﾄﾞ:
!MESSAGE 
!MESSAGE "FACElib - Win32 Debug" ("Win32 (x86) Dynamic-Link Library" 用)
!MESSAGE "FACElib - Win32 Release MinDependency" ("Win32 (x86) Dynamic-Link Library" 用)
!MESSAGE "FACElib - Win32 More" ("Win32 (x86) Dynamic-Link Library" 用)
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "FACElib - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /WX /GX /Zi /Od /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /FD /GZ /c
# SUBTRACT CPP /Fr /YX /Yc /Yu
# ADD BASE RSC /l 0x411 /d "_DEBUG"
# ADD RSC /l 0x411 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 MSVCRTD.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /pdb:none /machine:I386 /nodefaultlib:"LIBCMTD" /nodefaultlib:"LIBCD"
# SUBTRACT LINK32 /debug
# Begin Custom Build - 登録を行っています
OutDir=.\Debug
TargetPath=.\Debug\FACElib.dll
InputPath=.\Debug\FACElib.dll
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "FACElib - Win32 Release MinDependency"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ReleaseMinDependency"
# PROP BASE Intermediate_Dir "ReleaseMinDependency"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ReleaseMinDependency"
# PROP Intermediate_Dir "ReleaseMinDependency"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "_ATL_STATIC_REGISTRY" /D "_ATL_MIN_CRT" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "_ATL_STATIC_REGISTRY" /D "_ATL_MIN_CRT" /FD /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE RSC /l 0x411 /d "NDEBUG"
# ADD RSC /l 0x411 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386 /nodefaultlib:"LIBCMTD" /nodefaultlib:"LIBCD" /nodefaultlib:"LIBCMT" /nodefaultlib:"LIBC"
# Begin Custom Build - 登録を行っています
OutDir=.\ReleaseMinDependency
TargetPath=.\ReleaseMinDependency\FACElib.dll
InputPath=.\ReleaseMinDependency\FACElib.dll
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "FACElib - Win32 More"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "FACElib___Win32_More"
# PROP BASE Intermediate_Dir "FACElib___Win32_More"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "FACElib___Win32"
# PROP Intermediate_Dir "FACElib___Win32"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /WX /GX /Od /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /FD /GZ /c
# SUBTRACT BASE CPP /Fr /YX /Yc /Yu
# ADD CPP /nologo /MDd /W3 /WX /GX /Zi /Od /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /FD /GZ /c
# SUBTRACT CPP /Fr /YX /Yc /Yu
# ADD BASE RSC /l 0x411 /d "NDEBUG"
# ADD RSC /l 0x411 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /pdb:none /machine:I386 /nodefaultlib:"LIBCMTD" /nodefaultlib:"LIBCD"
# SUBTRACT BASE LINK32 /debug
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /debug /debugtype:both /machine:I386 /nodefaultlib:"LIBCMTD" /nodefaultlib:"LIBCD"
# SUBTRACT LINK32 /pdb:none /map
# Begin Custom Build - 登録を行っています
OutDir=.\FACElib___Win32
TargetPath=.\FACElib___Win32\FACElib.dll
InputPath=.\FACElib___Win32\FACElib.dll
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	
# End Custom Build

!ENDIF 

# Begin Target

# Name "FACElib - Win32 Debug"
# Name "FACElib - Win32 Release MinDependency"
# Name "FACElib - Win32 More"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Group "FACEライブラリソース"

# PROP Default_Filter ""
# Begin Group "FACE Input周り"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\FACE_Input.cpp
# End Source File
# End Group
# Begin Group "FACE Sound周り"

# PROP Default_Filter ""
# Begin Group "外部サウンドローダー"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\oggread.cpp
# End Source File
# Begin Source File

SOURCE=.\oggread.h
# End Source File
# Begin Source File

SOURCE=.\wavread.cpp
# End Source File
# Begin Source File

SOURCE=.\wavread.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\FACE_Sound.cpp
# End Source File
# Begin Source File

SOURCE=.\FACE_Sound_Assist.cpp
# End Source File
# Begin Source File

SOURCE=.\FACE_Sound_Assist.h
# End Source File
# End Group
# Begin Group "FACE Window周り"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\FACE_Window.cpp
# End Source File
# Begin Source File

SOURCE=.\FACE_Window_Assist.h
# End Source File
# End Group
# Begin Group "FACE Draw周り"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\FACE_Draw.cpp
# End Source File
# Begin Source File

SOURCE=.\FACE_Draw_Assist.cpp
# End Source File
# Begin Source File

SOURCE=.\FACE_Draw_Assist.h
# End Source File
# Begin Source File

SOURCE=.\FACE_Draw_Sprite.cpp
# End Source File
# End Group
# Begin Group "FACE Out周り"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\FACE_File.cpp
# End Source File
# End Group
# Begin Source File

SOURCE=.\FACE.cpp
# End Source File
# Begin Source File

SOURCE=.\FACE.h
# End Source File
# End Group
# Begin Group "FACE COM/ATLソース"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\FACElib.cpp
# End Source File
# Begin Source File

SOURCE=.\FACElib.def
# End Source File
# Begin Source File

SOURCE=.\FACElib.idl
# ADD MTL /tlb ".\FACElib.tlb" /h "FACElib.h" /iid "FACElib_i.c" /Oicf
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\FACE.rgs
# End Source File
# Begin Source File

SOURCE=.\FACElib.rc
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# End Group
# End Target
# End Project
