/***************************************************************************** pwmm.c pwmm_cfg.h pwmm_info.inc pwmm_private.h pwmm_public.h Copyright (C) 2016 ShenZhen Yeedon Media co.,LTD. All rights reserved. * pwmm.c pwmm_cfg.h pwmm_info.inc pwmm_private.h pwmm_public.h File Name : pwmm_private.h pwmm.c pwmm_cfg.h pwmm_info.inc pwmm_private.h pwmm_public.h Description :the private datas of the pwmm module. pwmm.c pwmm_cfg.h pwmm_info.inc pwmm_private.h pwmm_public.h Author: Xueping.Chen pwmm.c pwmm_cfg.h pwmm_info.inc pwmm_private.h pwmm_public.h Date: 2016-11-29 ******************************************************************************/  /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr check of multiple include */ #ifndef _PWMM_PRIVATE_H_  #define _PWMM_PRIVATE_H_  #include "pwmm_public.h" #include "yd_typedefs.h"  /*private Macro defines */ #define PWMM_CYCLE 4 /*the cycle of the pwmm*/  /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Private static functions declare */ static U8 pwmm_GetCycleDuty(PwmmCh_ENUM Channel, PwmmLevel_ENUM Level, PU8 Cycle, PU8 Duty);   #endif /*_PWMM_PRIVATE_H_*/  /*----------------end of file------------------------*/  /*=========================================================================== pwmm.c pwmm_cfg.h pwmm_info.inc pwmm_private.h pwmm_public.h File Revision History(bottom to top:first revision to last revision) *============================================================================ pwmm.c pwmm_cfg.h pwmm_info.inc pwmm_private.h pwmm_public.h $Log:$ * pwmm.c pwmm_cfg.h pwmm_info.inc pwmm_private.h pwmm_public.h Rev: Userid: Date: Description *-------- ---------- --------- ------------------------------ * pwmm.c pwmm_cfg.h pwmm_info.inc pwmm_private.h pwmm_public.h V1.0 Xueping.Chen 2016-11-29 Initial * *===========================================================================*/
