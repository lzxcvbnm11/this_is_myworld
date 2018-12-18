/bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr app_drw2dcpu app_menu app_tripcomp app_tutorial application.c application.h error.c error.h font.h font_data.h fonts fs_data.h hmi_manager.c hmi_manager.h img.c img.h img_data.h img_drw2d.c img_drw2d.h img_format.h main.c main.h mem_init.c mem_init.h sfma.c wm.c wm.h write.c write.h PROJECT : GRAPE_APP FILE : $Id: img.c 25427 2013-06-14 07:55:45Z nan.wang $ ============================================================================ DESCRIPTION Image Module ============================================================================ C O P Y R I G H T ============================================================================ Copyright (c) 2014 by Renesas Electronics (Europe) GmbH. Arcadiastrasse 10 D-40472 Duesseldorf Germany All rights reserved. ============================================================================ Purpose: only for testing, not for mass production DISCLAIMER LICENSEE has read, understood and accepted the terms and conditions defined in the license agreement, especially the usage rights. In any case, it is LICENSEE's responsibility to make sure that any user of the software complies with the terms and conditions of the signed license agreement. SAMPLE CODE is not part of the licensed software, as such it must not be used in mass-production applications. It can only be used for evaluation and demonstration purposes at customer�s premises listed in the signed license agreement. app_drw2dcpu app_menu app_tripcomp app_tutorial application.c application.h error.c error.h font.h font_data.h fonts fs_data.h hmi_manager.c hmi_manager.h img.c img.h img_data.h img_drw2d.c img_drw2d.h img_format.h main.c main.h mem_init.c mem_init.h sfma.c wm.c wm.h write.c write.h app_drw2dcpu/ app_menu/ app_tripcomp/ app_tutorial/ fonts/ /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Title: Image Module The module provides functions to setup textures in the GPU memory or to release the memory used by a texture. app_drw2dcpu/ app_menu/ app_tripcomp/ app_tutorial/ fonts/ /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Section: Includes app_drw2dcpu/ app_menu/ app_tripcomp/ app_tutorial/ fonts/ #include "r_typedefs.h" /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Renesas basic types, e.g. uint32_t app_drw2dcpu/ app_menu/ app_tripcomp/ app_tutorial/ fonts/ #include "img_format.h" #include "r_cdi_api.h" #include "fw_fsal_api.h" #include "error.h" #include "r_cdi_api.h" #include <string.h> #include "img.h" extern r_cdi_Heap_t loc_VRAM_heap; /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Section: Local Functions app_drw2dcpu/ app_menu/ app_tripcomp/ app_tutorial/ fonts/ /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Function: locDecompressRLE Unpack RLE data to destination address. Parameters: Dst - video memory destination address Src - Pointer to source data Size - Size of compressed data Bpp - Number of bytes per pixel Returns: void app_drw2dcpu/ app_menu/ app_tripcomp/ app_tutorial/ fonts/ static void locDecompressRLE(uint32_t Dst, uint8_t *Src, uint32_t Size, uint8_t Bpp) { uint8_t pixelcounter; uint8_t nextpixelrle; uint8_t tmp; uint8_t* rlestart; while (Size > 0) { tmp = *Src; pixelcounter = (tmp & 0x7F) + 1; nextpixelrle = (tmp >> 7); Src++; Size -= 1; if (Size == 0) { break; } rlestart = Src; while (pixelcounter > 0) { if (nextpixelrle != 0) { /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr if rle package repeat same pixel app_drw2dcpu/ app_menu/ app_tripcomp/ app_tutorial/ fonts/ Src = rlestart; } memcpy((uint8_t*) Dst, Src, Bpp); Dst += Bpp; Src += Bpp; pixelcounter -= 1; if ((nextpixelrle == 0) || ((nextpixelrle != 0) && (pixelcounter == 1))) { if (Size >= Bpp) { Size -= Bpp; } else { Size = 0; } } } } } /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Section: Global Functions Description see: <img.h> app_drw2dcpu/ app_menu/ app_tripcomp/ app_tutorial/ fonts/ /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Function: Init2DImg app_drw2dcpu/ app_menu/ app_tripcomp/ app_tutorial/ fonts/ void *Init2DImg(Img_t *Img) { void *data; void *old; uint32_t size; uint8_t bpp; void *fp; uint32_t mm_data_addr; if (!Img) { return 0; } if (Img->Attributes & IMG_ATTRIBUTE_USE_FROM_PERSISTENT_MEMORY) { /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr don't copy image to video memory, directly use it from persistent memory (Flash) app_drw2dcpu/ app_menu/ app_tripcomp/ app_tutorial/ fonts/ if ((Img->Attributes & IMG_ATTRIBUTE_RLE_DECOMPRESS) != 0) { /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Cannot decompress RLE image without using RAM app_drw2dcpu/ app_menu/ app_tripcomp/ app_tutorial/ fonts/ return 0; } if (*Img->Data == 0) { /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr check, if ROMFS is to be used app_drw2dcpu/ app_menu/ app_tripcomp/ app_tutorial/ fonts/ /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr use ROMFS app_drw2dcpu/ app_menu/ app_tripcomp/ app_tutorial/ fonts/ fp = FW_FSAL_FOpen((const int8_t*)Img->Name, "rb"); if (!fp) { return 0; } mm_data_addr = (uint32_t)FW_FSAL_MMap(0, 0, 0, 0, fp, 0); if (!mm_data_addr) { return 0; } FW_FSAL_MUnmap((void*)mm_data_addr, 0); FW_FSAL_FClose(fp); /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr simply return image data address (read from ROMFS) app_drw2dcpu/ app_menu/ app_tripcomp/ app_tutorial/ fonts/ old = *Img->Data; *Img->Data = (void*)mm_data_addr; } else { /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr simply return image data address app_drw2dcpu/ app_menu/ app_tripcomp/ app_tutorial/ fonts/ old = *Img->Data; } } else { /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr copy image data to video memory app_drw2dcpu/ app_menu/ app_tripcomp/ app_tutorial/ fonts/ /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr check colourformat and calc bpp app_drw2dcpu/ app_menu/ app_tripcomp/ app_tutorial/ fonts/ switch (Img->Colorformat) { case IMG_ARGB8888: case IMG_RGBA8888: bpp = 4; break; case IMG_RGBX8888: /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr RGB888 is a 4 byte aligned app_drw2dcpu/ app_menu/ app_tripcomp/ app_tutorial/ fonts/ bpp = 4; break; case IMG_ARGB6666: case IMG_RGBA6666: case IMG_RGB888: /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr RGB888 is a 3 byte format w/o 4byte alignment when RLE compressed app_drw2dcpu/ app_menu/ app_tripcomp/ app_tutorial/ fonts/ bpp = 3; break; case IMG_ARGB1555: case IMG_RGBA5551: case IMG_ARGB4444: case IMG_RGBA4444: case IMG_RGB565: bpp = 2; break; case IMG_ALPHA8: bpp = 1; break; default: Error(ERR_TEXTURE_SETUP_FAILED); return *Img->Data; } /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr calc image size (decompressed) app_drw2dcpu/ app_menu/ app_tripcomp/ app_tutorial/ fonts/ size = (Img->Height app_drw2dcpu app_menu app_tripcomp app_tutorial application.c application.h error.c error.h font.h font_data.h fonts fs_data.h hmi_manager.c hmi_manager.h img.c img.h img_data.h img_drw2d.c img_drw2d.h img_format.h main.c main.h mem_init.c mem_init.h sfma.c wm.c wm.h write.c write.h Img->Width app_drw2dcpu app_menu app_tripcomp app_tutorial application.c application.h error.c error.h font.h font_data.h fonts fs_data.h hmi_manager.c hmi_manager.h img.c img.h img_data.h img_drw2d.c img_drw2d.h img_format.h main.c main.h mem_init.c mem_init.h sfma.c wm.c wm.h write.c write.h bpp); data = (void*)R_CDI_Alloc(&loc_VRAM_heap, size); if (!data) { Error(ERR_TEXTURE_SETUP_FAILED); return *Img->Data; } if ((Img->Attributes & IMG_ATTRIBUTE_RLE_DECOMPRESS) != 0) { /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr rle decompress image by CPU, only if image is of rle format and IMG_MODE_RLE flag is not set (means the image should not be decompressed by the Drawing engine during runtime app_drw2dcpu/ app_menu/ app_tripcomp/ app_tutorial/ fonts/ if (*Img->Data == 0) { /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr check, if ROMFS is to be used app_drw2dcpu/ app_menu/ app_tripcomp/ app_tutorial/ fonts/ /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr use ROMFS app_drw2dcpu/ app_menu/ app_tripcomp/ app_tutorial/ fonts/ fp = FW_FSAL_FOpen((const int8_t*)Img->Name, "rb"); if (!fp) { R_CDI_Free((uint32_t)data, &loc_VRAM_heap); return 0; } mm_data_addr = (uint32_t)FW_FSAL_MMap(0, 0, 0, 0, fp, 0); if (!mm_data_addr) { R_CDI_Free((uint32_t)data, &loc_VRAM_heap); return 0; } locDecompressRLE((uint32_t)data, (uint8_t*)mm_data_addr, Img->DataLength, bpp); FW_FSAL_MUnmap((void*)mm_data_addr, 0); FW_FSAL_FClose(fp); } else { locDecompressRLE((uint32_t)data, *Img->Data, Img->DataLength, bpp); } } else { if (*Img->Data == 0) { /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr check, if ROMFS is to be used app_drw2dcpu/ app_menu/ app_tripcomp/ app_tutorial/ fonts/ /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr use ROMFS app_drw2dcpu/ app_menu/ app_tripcomp/ app_tutorial/ fonts/ fp = FW_FSAL_FOpen((const int8_t*)Img->Name, "rb"); if (!fp) { R_CDI_Free((uint32_t)data, &loc_VRAM_heap); return 0; } mm_data_addr = (uint32_t)FW_FSAL_MMap(0, 0, 0, 0, fp, 0); if (!mm_data_addr) { R_CDI_Free((uint32_t)data, &loc_VRAM_heap); return 0; } /*PF_D2DSendToVidMemSync(Dev, data, (void*)mm_data_addr, Img->DataLength);*/ memcpy(data, (void*)mm_data_addr, Img->DataLength); FW_FSAL_MUnmap((void*)mm_data_addr, 0); FW_FSAL_FClose(fp); } else { /*PF_D2DSendToVidMemSync(Dev, data, (void*)*Img->Data, Img->DataLength);*/ memcpy(data, (void*)*Img->Data, Img->DataLength); } } old = *Img->Data; *Img->Data = data; } return old; } /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Function: Deinit2DImg app_drw2dcpu/ app_menu/ app_tripcomp/ app_tutorial/ fonts/ void Deinit2DImg(Img_t *Img, void *Original) { uint32_t err; if (!Img) { return; } if (Img->Attributes & IMG_ATTRIBUTE_USE_FROM_PERSISTENT_MEMORY) { /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr don't copy image to video memory, directly use it from persistent memory (Flash) app_drw2dcpu/ app_menu/ app_tripcomp/ app_tutorial/ fonts/ /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr -> nothing to free app_drw2dcpu/ app_menu/ app_tripcomp/ app_tutorial/ fonts/ } else { /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr copy image to video memory app_drw2dcpu/ app_menu/ app_tripcomp/ app_tutorial/ fonts/ /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr -> video memory can be freed now app_drw2dcpu/ app_menu/ app_tripcomp/ app_tutorial/ fonts/ err = R_CDI_Free((uint32_t)*Img->Data, &loc_VRAM_heap); if (err) { Error(err); } } *Img->Data = Original; }