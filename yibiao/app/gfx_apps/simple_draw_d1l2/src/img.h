/bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr back_rle_256.c back_rle_2561.c black_king.c config.h font.h font_data.h fonts hmi_manager.c hmi_manager.h img.c img.h img_data.h img_drw2d.c img_drw2d.h img_format.h main.c main.h mem_init.c mem_init.h QD_HMI sfma.c wm.c wm.h PROJECT : GRAPE_APP FILE : $Id: img.h 25427 2013-06-14 07:55:45Z nan.wang $ ============================================================================ DESCRIPTION Header for Texture Module ============================================================================ C O P Y R I G H T ============================================================================ Copyright (c) 2014 by Renesas Electronics (Europe) GmbH. Arcadiastrasse 10 D-40472 Duesseldorf Germany All rights reserved. ============================================================================ Purpose: only for testing, not for mass production DISCLAIMER LICENSEE has read, understood and accepted the terms and conditions defined in the license agreement, especially the usage rights. In any case, it is LICENSEE's responsibility to make sure that any user of the software complies with the terms and conditions of the signed license agreement. SAMPLE CODE is not part of the licensed software, as such it must not be used in mass-production applications. It can only be used for evaluation and demonstration purposes at customerís premises listed in the signed license agreement. back_rle_256.c back_rle_2561.c black_king.c config.h font.h font_data.h fonts hmi_manager.c hmi_manager.h img.c img.h img_data.h img_drw2d.c img_drw2d.h img_format.h main.c main.h mem_init.c mem_init.h QD_HMI sfma.c wm.c wm.h fonts/ QD_HMI/ #ifndef _TEXTURE_H_ #define _TEXTURE_H_ #ifdef __cplusplus extern "C" { #endif /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Title: Image Module Interface An application can use these functions to setup textures in the GPU memory or release the memory used by a texture. fonts/ QD_HMI/ /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Section: Global Functions fonts/ QD_HMI/ /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Function: InitImg Prepare an image for drawing engine usage. If an image is located in the CPU memory, copy it to the video memory. After the copy operation or if the image is already in the GPU memory (e.g. flash), adjust the pointer in the image structure. Parameters: Img - Image structure Returns: Original image data pointer fonts/ QD_HMI/ void *Init2DImg(Img_t *Img); /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Function: Deinit2DImg Remove an image from the GPU memory. If an image is located in the GPU memory, the GPU memory will be released. Parameters: Img - Image structure Original - Pointer to the original image data (e.g. CPU flash) Returns: void fonts/ QD_HMI/ void Deinit2DImg(Img_t *Img, void *Original); #ifdef __cplusplus } #endif #endif /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr _TEXTURE_H_ fonts/ QD_HMI/
