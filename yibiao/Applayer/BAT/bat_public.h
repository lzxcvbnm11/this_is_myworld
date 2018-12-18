/***************************************************************************** bat.c bat_cfg.h bat_info.inc bat_private.h bat_public.h ZS12_BAT_ADC_TAB.xlsx Copyright (C) 2016 ShenZhen Yeedon Media co.,LTD. All rights reserved. * bat.c bat_cfg.h bat_info.inc bat_private.h bat_public.h ZS12_BAT_ADC_TAB.xlsx File Name :bat_public.h bat.c bat_cfg.h bat_info.inc bat_private.h bat_public.h ZS12_BAT_ADC_TAB.xlsx Description : public data of the Bat bat.c bat_cfg.h bat_info.inc bat_private.h bat_public.h ZS12_BAT_ADC_TAB.xlsx Author: ZXX bat.c bat_cfg.h bat_info.inc bat_private.h bat_public.h ZS12_BAT_ADC_TAB.xlsx Date: 2017-6-28 ******************************************************************************/ /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr check of multiple include */ #ifndef _BAT_PUBLIC_H_  #define _BAT_PUBLIC_H_  #include "yd_typedefs.h"  /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Public Macros defines */ typedef enum BatFlt_Tag { FLT_BAT_NO = (0u), /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr battery normal */ FLT_BAT_VOL_HIGH, /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr battery high */ FLT_BAT_VOL_LOW, /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr battery low */ FLT_BAT_ALL }BatFlt_ENUM;  typedef enum BatLevel_Tag { LEVEL_BAT_NORMAL = (0u), /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr battery normal */ LEVEL_BAT_HIGH, /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr battery high */ LEVEL_BAT_LOW, /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr battery low */ LEVEL_BAT_ALL }BATLevel_ENUM;  typedef enum BatDect_Type_tag { TYPE_BATDET_TD = (0u), /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Trouble Diagnostic */ TYPE_BATDET_CLASSA, /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr class a */ TYPE_BATDET_LIN,/* lin */ TYPE_BATDET_CAN,/* can */ TYPE_BATDET_ALL }BatDect_Type_ENUM;  /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Public data structures defines */   /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Public extern functions declare */ extern void BAT_Init(void); extern U8 BAT_GetInitSts(void); extern void BAT_Process_5ms(void); extern U8 BAT_GetBatValue(PU16 Value); extern U8 BAT_GetBatFltSts(BatDect_Type_ENUM Type,PU8 sts); extern U8 BAT_GetBCMBatValue(PU16 pValue); extern void BAT_BcmBat_Process_100ms(void); #endif /*_BAT_PUBLIC_H_*/  /*----------------end of file------------------------*/  /*=========================================================================== bat.c bat_cfg.h bat_info.inc bat_private.h bat_public.h ZS12_BAT_ADC_TAB.xlsx File Revision History(bottom to top:first revision to last revision) *============================================================================ bat.c bat_cfg.h bat_info.inc bat_private.h bat_public.h ZS12_BAT_ADC_TAB.xlsx $Log:$ * bat.c bat_cfg.h bat_info.inc bat_private.h bat_public.h ZS12_BAT_ADC_TAB.xlsx Rev: Userid: Date: Description *-------- ---------- --------- ------------------------------ * bat.c bat_cfg.h bat_info.inc bat_private.h bat_public.h ZS12_BAT_ADC_TAB.xlsx V1.0 Hejianjun 2016-11-30 Initial bat.c bat_cfg.h bat_info.inc bat_private.h bat_public.h ZS12_BAT_ADC_TAB.xlsx V2.0 ZXX 2017-6-28 MODIFY *===========================================================================*/
