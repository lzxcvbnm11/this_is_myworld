/***************************************************************************** ass.c ass_cfg.h ass_info.inc ass_private.h ass_public.h Copyright (C) 2016 ShenZhen Yeedon Media co.,LTD. All rights reserved. * ass.c ass_cfg.h ass_info.inc ass_private.h ass_public.h File Name :ass_public.h ass.c ass_cfg.h ass_info.inc ass_private.h ass_public.h Description : public data of the Ass ass.c ass_cfg.h ass_info.inc ass_private.h ass_public.h Author: Hejianjun ass.c ass_cfg.h ass_info.inc ass_private.h ass_public.h Date: 2016-12-03 ******************************************************************************/  /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr check of multiple include */ #ifndef _ASS_PUBLIC_H_  #define _ASS_PUBLIC_H_  #include "yd_typedefs.h"  /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Public Macros defines */  /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Public data structures defines */  /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Public extern functions declare */ extern void ASS_Init(void); extern void ASS_Process_100ms(void); extern U8 ASS_GetInitStatus(void); extern void ASS_SendNetSignal_5ms(void); #endif /*_ASS_PUBLIC_H_*/  /*----------------end of file------------------------*/  /*=========================================================================== ass.c ass_cfg.h ass_info.inc ass_private.h ass_public.h File Revision History(bottom to top:first revision to last revision) *============================================================================ ass.c ass_cfg.h ass_info.inc ass_private.h ass_public.h $Log:$ * ass.c ass_cfg.h ass_info.inc ass_private.h ass_public.h Rev: Userid: Date: Description *-------- ---------- --------- ------------------------------ * ass.c ass_cfg.h ass_info.inc ass_private.h ass_public.h V1.1 Hejianjun 2016-12-03 Initial ass.c ass_cfg.h ass_info.inc ass_private.h ass_public.h V2.0 zhangxx 2017-06-23 modify * *===========================================================================*/
