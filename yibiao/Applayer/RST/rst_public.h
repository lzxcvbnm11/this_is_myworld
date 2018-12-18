/***************************************************************************** rst.c rst_cfg.h rst_info.inc rst_private.h rst_public.h Copyright (C) 2016 ShenZhen Yeedon Media co.,LTD. All rights reserved. * rst.c rst_cfg.h rst_info.inc rst_private.h rst_public.h File Name :rst_public.h rst.c rst_cfg.h rst_info.inc rst_private.h rst_public.h Description : public data of the Rst rst.c rst_cfg.h rst_info.inc rst_private.h rst_public.h Author: Hejianjun rst.c rst_cfg.h rst_info.inc rst_private.h rst_public.h Date: 2016-12-05 ******************************************************************************/  /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr check of multiple include */ #ifndef _RST_PUBLIC_H_  #define _RST_PUBLIC_H_   #include "yd_typedefs.h"  /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Public Macros defines */   /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Public data structures defines */ typedef enum RstRes_Tag { RST_RES_FAIL = (0u), /*结果失败*/ RST_RES_OK, /*结果成功*/ RST_RES_INVALID, /*结果不可用*/ RST_RES_ALL  }RstRes_ENUM;  typedef enum RSTType_Tag { TYPE_RST_EXTERNAL = (0u), /*External reset signal RESET*/ TYPE_RST_POC0RES, /*Power-On-Clear 0*/ TYPE_RST_PWRGD, /*External power-good indicator signal*/ TYPE_RST_WDTA0RES, /*Overflow of the Watchdog Timers*/  TYPE_RST_WDTA1RES, /*Overflow of the Watchdog Timers*/ TYPE_RST_CLMA0RES, /*Clock Monitor 0 reset*/ TYPE_RST_ECMRES, /*Error Control Module reset output*/ TYPE_RST_SWRES, /*Software reset*/ //OK TYPE_RST_DBRES, /*Debugger reset*/ TYPE_RST_ISORES, /*DEEPSTOP mode*/ TYPE_RST_ISOPWRES,  TYPE_RST_NULL, TYPE_RST_ALL  }RSTType_ENUM;   /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Public extern functions declare */ extern void RST_Init(void); extern U8 RST_GetRstSource(PU8 source);    #endif /*_RST_PUBLIC_H_*/  /*----------------end of file------------------------*/  /*=========================================================================== rst.c rst_cfg.h rst_info.inc rst_private.h rst_public.h File Revision History(bottom to top:first revision to last revision) *============================================================================ rst.c rst_cfg.h rst_info.inc rst_private.h rst_public.h $Log:$ * rst.c rst_cfg.h rst_info.inc rst_private.h rst_public.h Rev: Userid: Date: Description *-------- ---------- --------- ------------------------------ * rst.c rst_cfg.h rst_info.inc rst_private.h rst_public.h V1.0 Hejianjun 2016-11-30 Initial * *===========================================================================*/
