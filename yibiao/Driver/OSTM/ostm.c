/***************************************************************************** ostm.c ostm_cfg.h ostm_info.inc ostm_private.h ostm_public.h Copyright (C) 2016 ShenZhen Yeedon Media co.,LTD. All rights reserved. * ostm.c ostm_cfg.h ostm_info.inc ostm_private.h ostm_public.h File Name : ostm.c ostm.c ostm_cfg.h ostm_info.inc ostm_private.h ostm_public.h Description : Driver source file of OSTM. ostm.c ostm_cfg.h ostm_info.inc ostm_private.h ostm_public.h Author: Xiaojie.Zheng ostm.c ostm_cfg.h ostm_info.inc ostm_private.h ostm_public.h Date: 2016-12-12 ******************************************************************************/  /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Files for including */ #include "ostm_info.inc"  static BOOL ostm_InitStatus; U32 ostm_TickTime;  static U8 ostm_Task5MS_Count = 0; static U8 ostm_Task20MS_Count = 0; static U8 ostm_Task50MS_Count = 0; static U8 ostm_Task100MS_Count = 0; static U8 ostm_Task200MS_Count = 0; static U16 ostm_Task1000MS_Count = 0; static U8 ostm_5MS_Flag; static U8 ostm_20MS_Flag; static U8 ostm_50MS_Flag; static U8 ostm_100MS_Flag; static U8 ostm_200MS_Flag; static U8 ostm_1000MS_Flag;  /************************************************/ static U8 ostm1_10ms_counter = 0; static U8 ostm1_20ms_counter = 0; static U8 ostm1_50ms_counter = 0; static U8 ostm1_100ms_counter = 0; static U8 ostm1_1000ms_counter = 0; #if (1 == OSTM_EVT_EN) extern STSMG_EventDataAll_ST Stsmg_EventVar; #endif  extern evt_TickTockType_ST evt_TickType; /*************************************************** ostm.c ostm_cfg.h ostm_info.inc ostm_private.h ostm_public.h Function: OSTM_Init ostm.c ostm_cfg.h ostm_info.inc ostm_private.h ostm_public.h Description: OSTM drive initialization ostm.c ostm_cfg.h ostm_info.inc ostm_private.h ostm_public.h Parameters: none ostm.c ostm_cfg.h ostm_info.inc ostm_private.h ostm_public.h Returns: none ostm.c ostm_cfg.h ostm_info.inc ostm_private.h ostm_public.h $Create & Verlog:$ ostm.c ostm_cfg.h ostm_info.inc ostm_private.h ostm_public.h Author: Xiaojie.Zheng Date:2016-12-12 Version:V1.0 ****************************************************/ void OSTM_Init(void) /*默认为系统定时器0*/ { /*C_ISO_OSTM source clock selection register bit32:0 reserved bit1:0 Source clock selection for C_ISO_OSTM 00B: Disabled 01B: CLKJIT 10B: C_ISO_CPUCLK /4 11B: MainOsc fX */ protected_write(SYSPROTCMDD1, SYSPROTSD1, SYSCKSC_IOSTMS_CTL, 0x03); while(SYSCKSC_IOSTMS_ACT == 0x0) {/* Waiting for SYSCKSC_IOSTMS_ACT to set. */}; /*OSTMnCMP — OSTMn Compare Register In interval timer mode: start value of the down-counter In free-run compare mode: compare value */  OSTM1CMP = 0x09c40; /*1/8000000*8000 = 5ms*/   /*OSTMnCTL — OSTMn Control Register 1 OSTMnMD1 Specifies the operating mode for the counter: 0: Interval timer mode 1: Free-run compare mode ---set 0 OSTMnMD0 Controls the generation of OSTMTINT interrupt requests at the start of counting: 0: Interrupts when counting starts are disabled. ---set 1: Interrupts when counting starts are enabled. */  OSTM1CTL = 0x00; /*向上计数Free-run compare mode*/ PBGFSGD0BPROT0 = 0x07FFFFFFUL;   INTC2EIC126 = 0x47; ostm_TickTime = 0;  ostm_Task5MS_Count = 0; ostm_Task20MS_Count = 0; ostm_Task50MS_Count = 0; ostm_Task100MS_Count = 0; ostm_Task1000MS_Count = 0;  ostm_5MS_Flag = FALSE; ostm_20MS_Flag = FALSE; ostm_50MS_Flag = FALSE; ostm_100MS_Flag = FALSE; ostm_1000MS_Flag = FALSE;  ostm1_10ms_counter = 0; ostm1_20ms_counter = 0; ostm1_50ms_counter = 0; ostm1_100ms_counter = 0; ostm1_1000ms_counter = 0;  ostm_InitStatus = TRUE; }  void OSTM_Start(void) { OSTM1TS = 0x01; }  /*************************************************** ostm.c ostm_cfg.h ostm_info.inc ostm_private.h ostm_public.h Function: OSTM_GetInitStatus ostm.c ostm_cfg.h ostm_info.inc ostm_private.h ostm_public.h Description: get the OSTM module initialized status ostm.c ostm_cfg.h ostm_info.inc ostm_private.h ostm_public.h Parameters: none ostm.c ostm_cfg.h ostm_info.inc ostm_private.h ostm_public.h Returns: ostm_InitStatus ostm.c ostm_cfg.h ostm_info.inc ostm_private.h ostm_public.h $Create & Verlog:$ ostm.c ostm_cfg.h ostm_info.inc ostm_private.h ostm_public.h Author: Xiaojie.Zheng Date:2016-12-12 Version:V1.0 ****************************************************/ U8 OSTM_GetInitStatus(void) { return ostm_InitStatus; }  /*************************************************** ostm.c ostm_cfg.h ostm_info.inc ostm_private.h ostm_public.h Function: OSTM_GetTickTime ostm.c ostm_cfg.h ostm_info.inc ostm_private.h ostm_public.h Description: ostm.c ostm_cfg.h ostm_info.inc ostm_private.h ostm_public.h Parameters: none ostm.c ostm_cfg.h ostm_info.inc ostm_private.h ostm_public.h Returns: none ostm.c ostm_cfg.h ostm_info.inc ostm_private.h ostm_public.h $Create & Verlog:$ ostm.c ostm_cfg.h ostm_info.inc ostm_private.h ostm_public.h Author:Jianjun.He Date:2016-12-09 Version:V1.0 ****************************************************/ U8 OSTM_GetTickTime(PU32 time) { U8 res =RET_OK; if (FALSE == ostm_InitStatus) { res = RET_FAIL; } else if (NULL_PTR == time) { res = RET_INVALID; } else { *time = ostm_TickTime; /*sys_ticktime 在1ms 定时中断服务中自增*/ } return res; } /*************************************************** ostm.c ostm_cfg.h ostm_info.inc ostm_private.h ostm_public.h Function: OSTM_GetSysTaskFlag ostm.c ostm_cfg.h ostm_info.inc ostm_private.h ostm_public.h Description: ostm.c ostm_cfg.h ostm_info.inc ostm_private.h ostm_public.h Parameters: none ostm.c ostm_cfg.h ostm_info.inc ostm_private.h ostm_public.h Returns: none ostm.c ostm_cfg.h ostm_info.inc ostm_private.h ostm_public.h $Create & Verlog:$ ostm.c ostm_cfg.h ostm_info.inc ostm_private.h ostm_public.h Author:Jianjun.He Date:2016-12-09 Version:V1.0 ****************************************************/ U8 OSTM_GetSysTaskFlag(OSTMTaskType_ENUM ostmtask, PU8 flag) { U8 res =RET_OK; if (FALSE == ostm_InitStatus) { res = RET_FAIL; } else if ((NULL_PTR == flag) || (INDEX_OSTM_ALL <= ostmtask)) { res = RET_INVALID; } else { switch (ostmtask) {  case INDEX_OSTM_5MS: *flag = ostm_5MS_Flag; break; case INDEX_OSTM_20MS: *flag = ostm_20MS_Flag; break; case INDEX_OSTM_50MS: *flag = ostm_50MS_Flag; break; case INDEX_OSTM_100MS: *flag = ostm_100MS_Flag; break;  case INDEX_OSTM_200MS: *flag = ostm_200MS_Flag; break; case INDEX_OSTM_1000MS: *flag = ostm_1000MS_Flag; break; default: res = RET_INVALID; break; } } return res; } /*************************************************** ostm.c ostm_cfg.h ostm_info.inc ostm_private.h ostm_public.h Function: OSTM_ClearSysTaskFlag ostm.c ostm_cfg.h ostm_info.inc ostm_private.h ostm_public.h Description: ostm.c ostm_cfg.h ostm_info.inc ostm_private.h ostm_public.h Parameters: none ostm.c ostm_cfg.h ostm_info.inc ostm_private.h ostm_public.h Returns: none ostm.c ostm_cfg.h ostm_info.inc ostm_private.h ostm_public.h $Create & Verlog:$ ostm.c ostm_cfg.h ostm_info.inc ostm_private.h ostm_public.h Author:Jianjun.He Date:2016-12-09 Version:V1.0 ****************************************************/ U8 OSTM_ClrSysTaskFlag(OSTMTaskType_ENUM ostmtask) { U8 res =RET_OK; if (FALSE == ostm_InitStatus) { res = RET_FAIL; } else if (INDEX_OSTM_ALL <= ostmtask) { res = RET_INVALID; } else { switch (ostmtask) { case INDEX_OSTM_5MS: ostm_5MS_Flag = FALSE; break; case INDEX_OSTM_20MS: ostm_20MS_Flag = FALSE; break; case INDEX_OSTM_50MS: ostm_50MS_Flag = FALSE; break; case INDEX_OSTM_100MS: ostm_100MS_Flag = FALSE; break; case INDEX_OSTM_1000MS: ostm_1000MS_Flag = FALSE; break; default: res = RET_INVALID; break; } } return res; }   /*************************************************** ostm.c ostm_cfg.h ostm_info.inc ostm_private.h ostm_public.h Function: OSTM_IsrHandler ostm.c ostm_cfg.h ostm_info.inc ostm_private.h ostm_public.h Description: ostm.c ostm_cfg.h ostm_info.inc ostm_private.h ostm_public.h Parameters: none ostm.c ostm_cfg.h ostm_info.inc ostm_private.h ostm_public.h Returns: none ostm.c ostm_cfg.h ostm_info.inc ostm_private.h ostm_public.h $Create & Verlog:$ ostm.c ostm_cfg.h ostm_info.inc ostm_private.h ostm_public.h Author:Jianjun.He Date:2016-12-09 Version:V1.0 ****************************************************/ void OSTM0_IsrHandler(void) {  ostm_TickTime++;  ostm_Task5MS_Count++; ostm_Task20MS_Count++; ostm_Task50MS_Count++; ostm_Task100MS_Count++; ostm_Task200MS_Count++; ostm_Task1000MS_Count++;  if (evt_TickType.cnt !=0)  evt_TickType.cnt --;   if (TASK_5MS_CNT <= ostm_Task5MS_Count) { ostm_Task5MS_Count = 0; ostm_5MS_Flag = TRUE; CHM_SignalOutPutProcess_5ms(); } else { }  if (TASK_20MS_CNT <= ostm_Task20MS_Count) { ostm_Task20MS_Count = 0; ostm_20MS_Flag = TRUE; } else { }  if (TASK_50MS_CNT <= ostm_Task50MS_Count) { ostm_Task50MS_Count = 0; ostm_50MS_Flag = TRUE; } if (TASK_100MS_CNT <= ostm_Task100MS_Count) { ostm_Task100MS_Count = 0; ostm_100MS_Flag = TRUE; } else { } if (TASK_200MS_CNT <= ostm_Task200MS_Count) { ostm_Task200MS_Count = 0; ostm_200MS_Flag = TRUE; } else { }   if (TASK_1000MS_CNT/*TASK_1000MS_CNT*/ <= ostm_Task1000MS_Count) { ostm_Task1000MS_Count = 0; ostm_1000MS_Flag = TRUE; } else { }   }     /*************************************************** ostm.c ostm_cfg.h ostm_info.inc ostm_private.h ostm_public.h Function: OSTM_IsrHandler ostm.c ostm_cfg.h ostm_info.inc ostm_private.h ostm_public.h Description: 5ms Timer Interupt Task ostm.c ostm_cfg.h ostm_info.inc ostm_private.h ostm_public.h Parameters: none ostm.c ostm_cfg.h ostm_info.inc ostm_private.h ostm_public.h Returns: none ostm.c ostm_cfg.h ostm_info.inc ostm_private.h ostm_public.h $Create & Verlog:$ ostm.c ostm_cfg.h ostm_info.inc ostm_private.h ostm_public.h Author:Jianjun.He Date:2016-12-09 Version:V1.0 ****************************************************/ void OSTM1_IsrHandler(void) { U8 cansts = 0; U8 linsts = 0; U8 res = RET_OK;  res = BAT_GetBatFltSts(TYPE_BATDET_CAN,&cansts); res = BAT_GetBatFltSts(TYPE_BATDET_LIN,&linsts); /*CAN RX*/ if(LEVEL_BAT_NORMAL == cansts) { v_input(v_config_handle); } else { }  /*5ms process start*************/ /*LIN2CAN转发*/ COM_Lin2CAN(); /*LIN TX*/  ASS_SendNetSignal_5ms(); SSB_SendNetSignal_5ms(); CHM_SendNetSignal_5ms(); HSD_SendNetSignal_5ms(); /*5ms process end***************/  /*10ms process start************/ ostm1_10ms_counter ++; if(OSTM1_10MS_MAXCNT <= ostm1_10ms_counter) { ostm1_10ms_counter = 0; PWR_SendNetSignal_10ms(); CRUS_SendNetSignal_10ms(); TIP_SendNetSignal_10ms(); } else { }  /*10ms process end***************/ ostm1_20ms_counter ++; if(OSTM1_20MS_MAXCNT <= ostm1_20ms_counter) {  ostm1_20ms_counter = 0; #if (1 == OSTM_EVT_EN) EVT_JudgeLeftDirLamp(); EVT_JudgeRightDirLamp(); #endif }  /*50ms process start*************/ ostm1_50ms_counter ++; if(OSTM1_50MS_MAXCNT <= ostm1_50ms_counter) { ostm1_50ms_counter = 0;   WFM_SendNetSignal_50ms(); TPMS_SendUnitSignal_50ms(); ST_SendNetSignal_50ms(); } else { } /*50ms process end***************/  /*100ms process start************/ ostm1_100ms_counter ++; if(OSTM1_100MS_MAXCNT <= ostm1_100ms_counter) { ostm1_100ms_counter = 0; SCS_SendNetSignal_100ms(); TPMS_SendNetSignal_100ms(); ACC_SendNetSignal_100ms();  ODO_SendNetSignal_100ms(); RTC_SendNetSignal_100ms(); } else { } /*100ms process end************/  /*1000ms process start*********/ ostm1_1000ms_counter ++; if(OSTM1_1000MS_MAXCNT <= ostm1_1000ms_counter) { ostm1_1000ms_counter = 0; FC_NetSignal_OutPut(); FL_NetSignal_OutPut(); RANG_NetSignal_OutPut(); } else { } /*1000ms process end*********/    /*CAN TX*/ if(LEVEL_BAT_NORMAL == cansts) { v_output(v_config_handle);  } else { }  /*LIN TX*/ COM_CAN2Lin(); if(LEVEL_BAT_NORMAL == linsts) { v_sb_tick(IPK_LIN3_handle); } else { }  }  /*=========================================================================== ostm.c ostm_cfg.h ostm_info.inc ostm_private.h ostm_public.h File Revision History(bottom to top:first revision to last revision) *============================================================================ ostm.c ostm_cfg.h ostm_info.inc ostm_private.h ostm_public.h $Log:$ * ostm.c ostm_cfg.h ostm_info.inc ostm_private.h ostm_public.h Rev: Userid: Date: Description *-------- ---------- --------- ------------------------------ * ostm.c ostm_cfg.h ostm_info.inc ostm_private.h ostm_public.h V1.0 Xiaojie.Zheng 2016-12-12 Initial * *===========================================================================*/
