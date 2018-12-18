/***************************************************************************** idle.c idle_cfg.h idle_info.inc idle_private.h idle_public.h Copyright (C) 2016 ShenZhen Yeedon Media co.,LTD. All rights reserved. * idle.c idle_cfg.h idle_info.inc idle_private.h idle_public.h File Name : idle.c idle.c idle_cfg.h idle_info.inc idle_private.h idle_public.h Description : IDLE module middleware idle.c idle_cfg.h idle_info.inc idle_private.h idle_public.h Author: Xuenian.Feng idle.c idle_cfg.h idle_info.inc idle_private.h idle_public.h Date: 2016-12-8 ******************************************************************************/  /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Files for including */ #include "idle_info.inc"  static U8 idle_InitSts = FALSE;  /*************************************************** idle.c idle_cfg.h idle_info.inc idle_private.h idle_public.h Function: IDLE_Init idle.c idle_cfg.h idle_info.inc idle_private.h idle_public.h Description: IDLE module initialized idle.c idle_cfg.h idle_info.inc idle_private.h idle_public.h Parameters: none idle.c idle_cfg.h idle_info.inc idle_private.h idle_public.h Returns: none idle.c idle_cfg.h idle_info.inc idle_private.h idle_public.h $Create & Verlog:$ idle.c idle_cfg.h idle_info.inc idle_private.h idle_public.h Author:Xuenian.Feng Date:2016-12-8 Version:V1.0 ****************************************************/ void IDLE_Init(void) { idle_InitSts = TRUE; }  /*************************************************** idle.c idle_cfg.h idle_info.inc idle_private.h idle_public.h Function: IDLE_Process_5ms idle.c idle_cfg.h idle_info.inc idle_private.h idle_public.h Description: the process of Idle idle.c idle_cfg.h idle_info.inc idle_private.h idle_public.h Parameters: none idle.c idle_cfg.h idle_info.inc idle_private.h idle_public.h Returns: none idle.c idle_cfg.h idle_info.inc idle_private.h idle_public.h $Create & Verlog:$ idle.c idle_cfg.h idle_info.inc idle_private.h idle_public.h Author:Xuenian.Feng Date:2016-12-8 Version:V1.0 ****************************************************/ void IDLE_Process_5ms(void) {  if (TRUE == idle_InitSts) { WDT_Feed(); } else { /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr do nothing */ }  }  /*----------------end of file------------------------*/  /*=========================================================================== idle.c idle_cfg.h idle_info.inc idle_private.h idle_public.h File Revision History(bottom to top:first revision to last revision) *============================================================================ idle.c idle_cfg.h idle_info.inc idle_private.h idle_public.h $Log:$ * idle.c idle_cfg.h idle_info.inc idle_private.h idle_public.h Rev: Userid: Date: Description *-------- ---------- --------- ------------------------------ * idle.c idle_cfg.h idle_info.inc idle_private.h idle_public.h V1.0 Xuenian.Feng 2016-12-8 Initial * *===========================================================================*/
