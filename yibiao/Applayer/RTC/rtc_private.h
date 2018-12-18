/***************************************************************************** rtc.c rtc_cfg.h rtc_info.inc rtc_private.h rtc_public.h Copyright (C) 2016 ShenZhen Yeedon Media co.,LTD. All rights reserved. * rtc.c rtc_cfg.h rtc_info.inc rtc_private.h rtc_public.h File Name : rtc_private.h rtc.c rtc_cfg.h rtc_info.inc rtc_private.h rtc_public.h Description : the private datas of the Rtc rtc.c rtc_cfg.h rtc_info.inc rtc_private.h rtc_public.h Author: Hejianjun rtc.c rtc_cfg.h rtc_info.inc rtc_private.h rtc_public.h Date: 2016-12-05 ******************************************************************************/  /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr check of multiple include */ #ifndef _RTC_PRIVATE_H_  #define _RTC_PRIVATE_H_   /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Macro defines */ #define RTC_YEAR_OFFSET 2000 #define RTC_DEFT_YEAR 17 #define RTC_DEFT_MONTH 1 #define RTC_DEFT_DAY 1  #define RTC_DEFT_HOUR 0 #define RTC_DEFT_MINUTE 0 #define RTC_DEFT_SECOND 0 #define RTC_DRIVINGTIME_MAX 5999 /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr 99: 59 对应分钟数*/  #define RTC_DRIVINGTIME_MAX_SEC 359940 /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr 99: 59 对应分钟数*/  #define RTC_DISPLY12_MODE 0 #define RTC_DISPLY24_MODE 1  #define RTC_PROCESS_PERIOD 100 /*RTC PROCESS 执行周期*/ #define RTC_FUNCTION_PERIOD 1000 /*内部函数执行周期*/ #define RTC_PROCESS_CNT (RTC_FUNCTION_PERIOD/RTC_PROCESS_PERIOD) #define RTC_VEHSPDTHRESHOLD 5 /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr 5km/h 的速度阈值*/    #define ENRUNA_ACTIVE_TIME 1000 #define ENRUNA_ACTIVE_CNT (ENRUNA_ACTIVE_TIME/RTC_PROCESS_PERIOD)  /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Private data structures defines */    /*constant define*/   /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Private static functions declare */ static void rtc_SysTimeProcess_100ms(void); static void rtc_DrivenTimeProcess_1000ms(U8 index); static BOOL rtc_DriveTimeBeginProcess_1000ms(U32 DriveTime,BOOL* pStartFlg); static rtc_EnRunA_Active_Process_100ms(void); static void rtc_clean_driventime_100ms(void); #endif /*_RTC_PRIVATE_H_*/  /*------------------end of file----------------------------*/  /*=========================================================================== rtc.c rtc_cfg.h rtc_info.inc rtc_private.h rtc_public.h File Revision History(bottom to top:first revision to last revision) *============================================================================ rtc.c rtc_cfg.h rtc_info.inc rtc_private.h rtc_public.h $Log:$ * rtc.c rtc_cfg.h rtc_info.inc rtc_private.h rtc_public.h Rev: Userid: Date: Description *-------- ---------- --------- ------------------------------ * rtc.c rtc_cfg.h rtc_info.inc rtc_private.h rtc_public.h V1.0 Hejianjun 2016-12-05 Initial rtc.c rtc_cfg.h rtc_info.inc rtc_private.h rtc_public.h V2.0 zxx 2017-06-28 modify rtc.c rtc_cfg.h rtc_info.inc rtc_private.h rtc_public.h add RTC_YEAR_OFFSET define *===========================================================================*/
