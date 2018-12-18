/***************************************************************************** sys.c sys_cfg.h sys_info.inc sys_private.h sys_public.h Copyright (C) 2016 ShenZhen Yeedon Media co.,LTD. All rights reserved. * sys.c sys_cfg.h sys_info.inc sys_private.h sys_public.h File Name : sys_private.h sys.c sys_cfg.h sys_info.inc sys_private.h sys_public.h Description :the private datas of the sys module. sys.c sys_cfg.h sys_info.inc sys_private.h sys_public.h Author: Jianjun.He sys.c sys_cfg.h sys_info.inc sys_private.h sys_public.h Date: 2016-12-09 ******************************************************************************/  /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr check of multiple include */ #ifndef _SYS_PRIVATE_H_  #define _SYS_PRIVATE_H_ #include "yd_typedefs.h" #include "public.h" #include "s_dsm_api.h" #include "s_tpm.h" #include "s_fm_app.h"  /*private Macro defines */ #define SYS_DELAYTIME_5S 5000 #define TASK_PROCESS_PERIOD 100 #define TASK_PROCESS_5MS 5 #define TASK_PROCESS_10MS 10 #define TASK_PROCESS_20MS 20 #define TASK_PROCESS_50MS 50 #define TASK_PROCESS_100MS 100 #define TASK_PROCESS_200MS 200 #define TASK_PROCESS_1000MS 1000  #define BASETIME_15MS 15 /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr 时间偏移基准*/ #define BASETIME_25MS 25 #define BASETIME_35MS 35 #define TASK5MS_MAX 9 /*5ms的任务数*/ #define TASK10MS_MAX 7 /*10ms的任务数*/ #define TASK20MS_MAX 2 /*20ms的任务数*/ #define TASK25MS_MAX 4 /*25ms的任务数*/ #define TASK50MS_MAX 6 /*50ms的任务数*/ #define TASK100MS_MAX 3 /*100ms的任务数*/   /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Private data structures defines */ typedef void(*InitType)(void); /*定义初始化类型的函数指针*/ typedef void(*Proc5msType)(void); /*定义5ms process的函数指针类型*/ typedef void(*Proc10msType)(void); /*定义10ms process的函数指针类型*/ typedef void(*Proc20msType)(void); /*定义20ms process的函数指针类型*/ typedef void(*Proc50msType)(void); /*定义50ms process的函数指针类型*/ typedef void(*Proc100msType)(void); /*定义100ms process的函数指针类型*/ typedef void(*Proc200msType)(void); /*定义100ms process的函数指针类型*/ typedef void(*Proc1000msType)(void); /*定义1000ms process的函数指针类型*/  extern void hmi_gfx_loop(float dt); typedef enum SysGetWrkMode_Tag { STATUS_SYS_RUN = (0u), /*正常工作模式*/ STATUS_SYS_STANDBY, /*虚拟模式*/ STATUS_SYS_DEEPSTOP, /*睡眠模式*/ STATUS_SYS_ALL }SysGetWrkMode_ENUM;     typedef enum SysInitProcess_Tag { INDEX_NZM_INIT = (0u), INDEX_OSTM_INIT, INDEX_ADCE_INIT, /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr INDEX_GPD_INIT, */ INDEX_PWM_INIT, INDEX_TAUB_INIT, /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr INDEX_DMA_INIT */ INDEX_RSTC_INIT, INDEX_ISM_INIT, INDEX_EED_INIT, INDEX_ADM_INIT, INDEX_IOM_INIT, INDEX_LRM_INIT, INDEX_MOM_INIT, INDEX_BPM_INIT, INDEX_PWMM_INIT, /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr INDEX_NWD_INIT, */ INDEX_COM_INIT, INDEX_NVM_INIT, INDEX_DIAG_INIT, /*NEW ADD*/ INDEX_TPMS_INIT, /*NEW ADD*/ INDEX_SLF_INIT, /*NEW ADD*/ INDEX_BAT_INIT, INDEX_PWR_INIT, INDEX_NWD_INIT, /*NEW ADD*/ INDEX_ASS_INIT, INDEX_SSB_INIT, INDEX_HSD_INIT, INDEX_ILLU_INIT, INDEX_TIP_INIT, INDEX_ST_INIT, /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr INDEX_RANG_INIT, */ INDEX_ACC_INIT, INDEX_CRUS_INIT, /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr INDEX_FL1_INIT,*/ //INDEX_TRIP_INIT, INDEX_WFM_INIT, /*NEW ADD*/ INDEX_EVT_INIT, /*NEW ADD*/ INDEX_STSMG_INIT, /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr INDEX_FL_INIT,*/ INDEX_CHM_INIT, /*NEW ADD*/ INDEX_LED_INIT, /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr INDEX_GCM_INIT, */ // INDEX_WARN_INIT, INDEX_MSG_INIT, /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr INDEX_FNVM_INIT,*/ INDEX_RTC_INIT, INDEX_RST_INIT, INDEX_SCS_INIT, /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr INDEX_FL2_INIT,*/ INDEX_ODO_INIT, INDEX_FL_INIT, /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr FL */ INDEX_FC_INIT, /*FC*/ INDEX_RANG_INIT, /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr RANG */ INDEX_FTR_INIT, /*NEW ADD*/ INDEX_DM_INIT, /*NEW ADD*/ INDEX_IDLE_INIT, /*NEW ADD*/ INDEX_SYSINIT_ALL }SysInitProcess_ENUM;   static const InitType SysInit_Tabl[INDEX_SYSINIT_ALL] = { NZM_Init, OSTM_Init, ADCE_Init, /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr GPD_Init */ PWM_Init, TAUB_Init, /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr DMA_Init, */ RSTC_Init, ISM_Init, EED_Init, /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr DSPI FNVM_Init, GCM_Init, 应用层和中间层的初始化*/ ADM_Init, /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr NWD_Init, */ IOM_Init, LRM_Init, MOM_Init, BPM_Init, /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr DIO*/ PWMM_Init, /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr PWM*/ COM_Init, // NZM_Init, NVM_Init, DIAG_Init, /*nvm adm*/ TPMS_Init, /*DIAG COM*/ SLF_Init, /*adm*/ BAT_Init, PWR_Init, NWD_Init, /*bat pwr com*/ ASS_Init, /*IOM NVM */ SSB_Init, /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr ADM NVM */ HSD_Init, /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr IOM*/ ILLU_Init, /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr IOM NVM PWMM*/ TIP_Init, /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr ADM IOM */ ST_Init, /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr NVM */ ACC_Init, /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr ADM IOM NVM */ CRUS_Init, /*ADM IOM NVM */ //TRIP_Init, /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr ADM*/ WFM_Init, /*FL DIAG NWD COM*/ EVT_Init, /**/ STSMG_Init, CHM_Init, /*STSMG DIAG*/ LED_Init, /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr NVM IOM LRM*/ //WARN_Init, /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr BPM*/ MSG_Init, RTC_Init, /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr NVM RTCA*/ RST_Init, /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr RSTC */ SCS_Init, ODO_Init, /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr NVM*/ FuelLevelAlgorithm_V2_initialize, /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr FL */ avgFuelCsump_V2_initialize, /*FC*/ RangeToEmptyAlgorithm_V2_initialize, /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr RANG */ FTR_Init, /*FTR*/ DM_Init, /*DM*/ IDLE_Init };   /*所有5 ms 任务的index 索引号*/ typedef enum Sys5MSProcess_Tag {  INDEX_ADM_PROCESS= ( 0U ), INDEX_MOM_PROCESS, INDEX_COM_PROCESS,  INDEX_NWD_PROCESS, INDEX_BAT_PROCESS,  INDEX_CHM_PROCESS, INDEX_IDLE_PROCESS, INDEX_MSG_PROCESS, INDEX_SYS5MSPROCESS_ALL }Sys5MSProcess_ENUM;  /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr 5ms Process 函数排序*/ static const Proc5msType SysProc5ms_Tabl[INDEX_SYS5MSPROCESS_ALL] = {  ADM_Process_5ms,  MOM_Process_5ms, COM_Process_5ms, NWD_Process_5ms, BAT_Process_5ms, MSG_Process_5ms, CHM_Process_5ms, IDLE_Process_5ms, };      /*所有20 ms 任务的index 索引号*/ typedef enum Sys20MSProcess_Tag { INDEX_SSB_PROCESS = ( 0U ),  INDEX_TPM_PROCCESS, INDEX_DSM_PROCESS,   INDEX_PWR_PROCESS,  INDEX_CRUS_PROCESS,  INDEX_TIP_PROCESS,  INDEX_SLF_PROCESS, INDEX_WFM_PROCESS, INDEX_TRIP_PROCESS,   INDEX_STSMG_PROCESS,  INDEX_SYS20MSPROCESS_ALL }Sys20MSProcess_ENUM;  /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr 20ms Process 函数排序*/ static const Proc20msType SysProc20ms_Tabl[INDEX_SYS20MSPROCESS_ALL] = { SSB_Process_20ms, s_tpm_task, s_dsm_task, PWR_Process_20ms,  CRUS_Process_20ms, TIP_Process_20ms,  SLF_Process_20ms, WFM_Process_20ms,  TRIP_Process_20ms, STSMG_Process_20ms  };  /*所有50 ms 任务的index 索引号*/ typedef enum Sys50MSProcess_Tag { INDEX_NVM_PROCESS = (0u), INDEX_SCS_PROCESS,  INDEX_TPMS_PROCESS,  INDEX_FM_PROCESS,  INDEX_ST_PROCESS, INDEX_FTR_PROCESS, INDEX_NZM_PROCESS, INDEX_DM_PROCESS, INDEX_HMI_PROCESS,  INDEX_LED_PROCESS, INDEX_SYS50MSPROCESS_ALL }Sys50MSProcess_ENUM;  /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr 50ms Process 函数排序*/ static const Proc50msType SysProc50ms_Tabl[INDEX_SYS50MSPROCESS_ALL] = { NVM_Process_50ms, /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr GCM_Process_50ms */ SCS_Process_50ms, TPMS_Process_50ms, f_fm_task,  ST_Process_50ms, FTR_Process_50ms, NZM_Update_50ms, DM_Process_50ms, hmi_gfx_loop, LED_Process_50ms  };  /*所有100 ms 任务的index 索引号*/ typedef enum Sys100MSProcess_Tag {  INDEX_IOM_PROCESS = (0u),  INDEX_LRM_PROCESS,  INDEX_PWMM_PROCESS, INDEX_PWRCHK_PROCESS,  INDEX_ACC_PROCESS,  //INDEX_STSMG_PROCESS, INDEX_ODO_PROCESS,  INDEX_RTC_PROCESS, INDEX_ILLU_PROCESS, INDEX_ASS_PROCESS, INDEX_HSD_PROCESS, INDEX_BCMBAT_PROCESS,  INDEX_SYS100MSPROCESS_ALL }Sys100MSProcess_ENUM;  /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr 100ms Process 函数排序*/ static const Proc100msType SysProc100ms_Tabl[INDEX_SYS100MSPROCESS_ALL] = {  PWMM_Process_100ms, IOM_Process_100ms, LRM_Process_100ms,  PWR_Process_100ms, ACC_Process_100ms, //STSMG_Process_100ms,  ODO_Process_100ms, RTC_Process_100ms, ILLU_Process_100ms, ASS_Process_100ms, HSD_Process_100ms, BAT_BcmBat_Process_100ms,  };  typedef enum Sys200MSProcess_Tag {  INDEX_AVGFUELCSUMP_PROCESS = (0u),  INDEX_SYS200MSPROCESS_ALL }Sys200MSProcess_ENUM;  /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr 200ms Process 函数排序*/ static const Proc200msType SysProc200ms_Tabl[INDEX_SYS200MSPROCESS_ALL] =  { avgFuelCsump_V2_step };   /*所有1000 ms 任务的index 索引号*/ typedef enum Sys1000MSProcess_Tag { INDEX_FUELLEVELALGORITHM_PROCESS = (0u),  // INDEX_AVGFUELCSUMP_PROCESS, INDEX_RANGETOEMPTYALGORITHM_PROCESS, //INDEX_WAKEUPFRAME_PROCESS, INDEX_SYS1000MSPROCESS_ALL }Sys1000MSProcess_ENUM;  /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr 1000ms Process 函数排序*/ static const Proc1000msType SysProc1000ms_Tabl[INDEX_SYS1000MSPROCESS_ALL] =  { FuelLevelAlgorithm_V2_step, // avgFuelCsump_V2_step, RangeToEmptyAlgorithm_V2_step  }; /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Private static functions declare */ static void sys_InitProcess(void); static void sys_Process_BeforeDeepSleep(void); #endif /*_SYS_PRIVATE_H_*/  /*----------------end of file------------------------*/  /*=========================================================================== sys.c sys_cfg.h sys_info.inc sys_private.h sys_public.h File Revision History(bottom to top:first revision to last revision) *============================================================================ sys.c sys_cfg.h sys_info.inc sys_private.h sys_public.h $Log:$ * sys.c sys_cfg.h sys_info.inc sys_private.h sys_public.h Rev: Userid: Date: Description *-------- ---------- --------- ------------------------------ * sys.c sys_cfg.h sys_info.inc sys_private.h sys_public.h V1.0 Jianjun.He 2016-12-09 Initial sys.c sys_cfg.h sys_info.inc sys_private.h sys_public.h V2.0 Liuyingying 2017-6-30 modify *===========================================================================*/
