/bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr back_rle_256.c back_rle_2561.c black_king.c config.h font.h font_data.h fonts hmi_manager.c hmi_manager.h img.c img.h img_data.h img_drw2d.c img_drw2d.h img_format.h main.c main.h mem_init.c mem_init.h QD_HMI sfma.c wm.c wm.h PROJECT : GRAPE_APP FILE : $Id: font.h 25427 2013-06-14 07:55:45Z nan.wang $ ============================================================================ DESCRIPTION Sample program for demonstration of the D1X GFX features ============================================================================ C O P Y R I G H T ============================================================================ Copyright (c) 2014 by Renesas Electronics (Europe) GmbH. Arcadiastrasse 10 D-40472 Duesseldorf Germany All rights reserved. ============================================================================ Purpose: only for testing, not for mass production DISCLAIMER LICENSEE has read, understood and accepted the terms and conditions defined in the license agreement, especially the usage rights. In any case, it is LICENSEE's responsibility to make sure that any user of the software complies with the terms and conditions of the signed license agreement. SAMPLE CODE is not part of the licensed software, as such it must not be used in mass-production applications. It can only be used for evaluation and demonstration purposes at customer�s premises listed in the signed license agreement. back_rle_256.c back_rle_2561.c black_king.c config.h font.h font_data.h fonts hmi_manager.c hmi_manager.h img.c img.h img_data.h img_drw2d.c img_drw2d.h img_format.h main.c main.h mem_init.c mem_init.h QD_HMI sfma.c wm.c wm.h fonts/ QD_HMI/ #ifndef _FONT_H_ #define _FONT_H_ #ifdef __cplusplus extern "C" { #endif /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Title: Font Interface This header describes the structure of a bitmap font, which can be used by the framework. fonts/ QD_HMI/ /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Section: Global Types fonts/ QD_HMI/ /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Type: FontPos_t Character position and width information. The type is used to specify the position of a character inside a font texture. Members: Offset - Pixel position in the texture Width - Pixel width in the texture fonts/ QD_HMI/ typedef struct { int Offset; int Width; } FontPos_t; /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Type: Font_t Font data type. This structure contains the data of a font. Members: Texture - Pointer to the font's image structure Pos - Array of character information Height - Pixel height of the font fonts/ QD_HMI/ typedef struct { Img_t *Texture; const FontPos_t *Pos; int Height; } Font_t; #ifdef __cplusplus } #endif #endif /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr _FONT_H_ fonts/ QD_HMI/