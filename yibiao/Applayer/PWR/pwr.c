/***************************************************************************** pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Copyright (C) 2016 ShenZhen Yeedon Media co.,LTD. All rights reserved. * pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h File Name : pwr.C pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Description :the private datas of the pwr module. pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Author: Xueping.Chen pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Date: 2016-12-09 ******************************************************************************/ /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Files for including */ #include "pwr_info.inc"  static U8 pwr_CntSSBlongPressPRO = 0; /*用于计数到SSBLongPressDetect*/ static U8 pwr_CntCheckPRO = 0; /*用于计数到自检process*/ static U16 pwr_Cnt2Second = 0; /*用于判断ssb按键长按的计数*/ static U16 pwr_Cnt5Second = 0; /*用于判断自检5s的计数*/ static U16 pwr_CntLostNet = 0; /*用于判断网络节点丢失后由ACC->OFF的时间计数*/  static U8 pwr_NetBCMPwrMdHwdSta = 0; /*用于存储从CAN 获取BCMPwrMdHwdSta*/ static U8 pwr_NetBCMPwrMdHwdStaV = 0; /*用于存储从CAN 获取BCMPwrMdHwdStaV*/ static BOOL pwr_NetBCMEmgcSp = FALSE; /*用于存储从CAN 获取BCMEmgcSp*/ static BOOL pwr_NetEnRunA = FALSE; /*用于存储从CAN 获取EnRunA*/ static PWR_SelfChk_ENUM pwr_CheckStatus = STATUS_SLFCHK_NOT_READY; /*判断自检的标志*/ static U8 pwr_LostIcm = FALSE; /*节点丢失的标志*/ static BOOL pwr_SsbLongPressedFlag = FALSE; /*判断长按的标志*/ static BOOL pwr_VStpFlag = FALSE; /*判断车停的标志*/ static BOOL pwr_NetSysBPMEnbd = FALSE; /*用于存储从CAN 获取SysBPMEnbd*/ static PWRMODEType_ENUM pwr_CPwrMode = PWR_OFF; static PWRMODEType_ENUM pwr_NetSysBPM = PWR_OFF; static U16 pwr_SSBlongPreCnt = 0; /*判断长按时间的计数*/ static U16 pwr_SSBShortPrsCnt = 0; /*判断长按时间的计数*/ static BOOL pwr_ThreeWheelStop = FALSE; /*判断三个轮子停止的标志*/ static U8 pwr_InitSts = FALSE; /*初始化*/ /*配置字*/ static U8 pmACCToOFFDelayprm = PMACCTOOFFDELAYPRM_DEF_VALUE; static U8 insLampCheckTimePrm = INSLAMPCHECKTIMEPRM_DEF_VALUE; static U8 gloVehMovingThresholdPrm = GLOVEHMOVINGTHRESHOLDPRM_DEF_VALUE; static U8 gloVehStoppedThresholdPrm = GLOVEHSTOPPEDTHRESHOLDPRM_DEF_VALUE; static U8 pmOperationalMode = PMOPERATIONALMODE_DEF_VALUE; static BOOL pmMultiPressEnPRm = PMMULTIPRESSENPRM_DEF_VALUE; /*SSB按钮配置为长按功能*/ static U16 pmSSBPressTimeToTurnOffprm;// = PMSSBPRESSTIMETOTURNOFFPRM_DEF_VALUE; static U16 PmSSBActivePressTimePrm;// = PMSSBACTIVEPRESSTIMEPRM_DEF_VALUE; static U16 pmManuSSBPressTimeToTurnOFFPrm = PMMANUSSBPRESSTIMETOTURNOFFPRM_DEF_VALUE; /*网络信号*/ static U16 pwr_NetWhlGNDVelLDvn = 0; /*用于存储从CAN 获取WhlGNDVelLDvn*/ static U8 pwr_NetWhlGNDVelLDvnv = INVALID; /*用于存储从CAN 获取WhlGNDVelLDvnv*/ static U16 pwr_NetWhlGNDVelLnonDvn = 0; /*用于存储从CAN 获取WhlGNDVelLnonDvn*/ static U8 pwr_NetWhlGNDVelLnonDvnv = INVALID; /*用于存储从CAN 获取WhlGNDVelLnonDvnv */ static U16 pwr_NetWhlGNDVelRDvn = 0; /*用于存储从CAN 获取WhlGNDVelRDvn*/ static U8 pwr_NetWhlGNDVelRDvnv = INVALID; /*用于存储从CAN 获取WhlGNDVelRDvnv*/ static U16 pwr_NetWhlGNDVelRnonDvn = 0; /*用于存储从CAN 获取WhlGNDVelRnonDvn*/ static U8 pwr_NetWhlGNDVelLRnonDvnv = INVALID;/*用于存储从CAN 获取WhlGNDVelLRnonDvnv*/ static U16 pwr_NetVehSpdAvgDrvn = 0; /*用于存储从CAN 获取VehSpdAvgDrvn*/ static U8 pwr_NetVehSpdAvgDrvnV = INVALID; /*用于存储从CAN 获取VehSpdAvgDrvnV*/ static BOOL pwr_busoff = FALSE; /*BUSOFF 丢失的标志*/ static U8 pwr_lostSCS = FALSE; /*SCS 丢失的标志*/ static U8 pwr_lostECM = FALSE;  static DID_D001_UN pwr_D001;  /*************************************************** pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Function: PWR_Init pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Description: the initialized of the mom module pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Parameters: none pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Returns: none pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h $Create & Verlog:$ pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Author:Xueping.Chen Date:2016-12-09 Version:V1.0 ****************************************************/ void PWR_Init(void) { U8 res = RET_FAIL;  pwr_InitSts = FALSE; pwr_CntSSBlongPressPRO = 0; pwr_CntCheckPRO = 0; pwr_Cnt2Second = 0; pwr_Cnt5Second = 0; pwr_CntLostNet = 0;  pwr_NetBCMPwrMdHwdSta = PWR_UNKNOWN; pwr_NetBCMPwrMdHwdStaV = VALID; pwr_NetBCMEmgcSp = FALSE; pwr_NetEnRunA = FALSE; pwr_CheckStatus = STATUS_SLFCHK_NOT_READY; pwr_LostIcm = FALSE;  pwr_VStpFlag = FALSE; pwr_NetSysBPMEnbd = FALSE; pwr_CPwrMode = PWR_OFF; pwr_NetSysBPM = PWR_OFF; pwr_SSBlongPreCnt = 0; /*用于判断ssb按键长按的计数变量*/ pwr_ThreeWheelStop = FALSE;  insLampCheckTimePrm = DIAG_GetLampCheckTime(); gloVehMovingThresholdPrm = DIAG_GetVehMovingThreshold(); gloVehStoppedThresholdPrm = DIAG_GetVehStoppedThreshold();  pmACCToOFFDelayprm = DIAG_GetACCToOFFDelay(); pmMultiPressEnPRm = DIAG_GetMultiPressEn(); pmSSBPressTimeToTurnOffprm = DIAG_GetSSBPressTimeToTurnOFF(); PmSSBActivePressTimePrm = DIAG_GetSSBActivePressTime();  pmOperationalMode = DIAG_GetOperationalMode(); if (MANUFACTURE_MODE < pmOperationalMode) { pmOperationalMode = NORMAL_MODE; } else { }  if (MANUFACTURE_MODE == pmOperationalMode) { pwr_SSBlongPreCnt =(pmManuSSBPressTimeToTurnOFFPrm / SSBLONGPRE_PROCESS_PERIOD); /*秒转毫秒的函数*/  if ((NVM_WR_OK != NVM_GetParas(INDEX_NVM_RUNKEEP,&pwr_NetSysBPM,1)) ||(PWR_RUN != pwr_NetSysBPM)) { pwr_NetSysBPM =PWR_OFF; } else { } } else { pwr_SSBlongPreCnt =(U16) (pmSSBPressTimeToTurnOffprm / SSBLONGPRE_PROCESS_PERIOD); /*秒转毫秒的函数*/ }  pwr_SSBShortPrsCnt = ((PmSSBActivePressTimePrm)/PWR_PROCESS_PERIOD); pwr_InitSts = TRUE; } /*************************************************** pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Function: PWR_Process_20ms pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Description: the process of the mom module pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Parameters: none pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Returns: none pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h $Create & Verlog:$ pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Author:Xueping.Chen Date:2016-12-09 Version:V1.0 ****************************************************/ void PWR_Process_20ms(void) { if (TRUE == pwr_InitSts) { pwr_SSBLongPressDetect_20ms(); pwr_PowerMode_10ms(); } else { } }  /*************************************************** pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Function: PWR_Process_50ms pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Description: the process of the mom module pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Parameters: none pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Returns: none pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h $Create & Verlog:$ pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Author:Xueping.Chen Date:2016-12-09 Version:V1.0 ****************************************************/ void PWR_Process_100ms(void) { if (TRUE == pwr_InitSts) { pwr_CntCheckPRO++; if (CHECK_PERIOD_CNT <= pwr_CntCheckPRO) { pwr_CheckStatus_100ms(); pwr_VehicleStop_100ms(); pwr_CntCheckPRO = 0; } else { } } else { } }  /*************************************************** pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Function: pwr_VehicleStop_50ms pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Description: judge if the Vehicle stop pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Parameters: none pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Returns: none pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h $Create & Verlog:$ pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Author:Xueping.Chen Date:2016-12-09 Version:V1.0 ****************************************************/ static void pwr_VehicleStop_100ms(void) { U8 pwr_TrShftLvrPosv = INVALID; U8 pwr_TrShftLvrPos = 0;  pwr_WheelStop(); COM_GetSignalValue_8(INDEX_COM_RS_TRSHFTLVRPOS, &pwr_TrShftLvrPos); COM_GetSignalValue_8(INDEX_COM_RS_TRSHFTLVRPOSV, &pwr_TrShftLvrPosv);  if(TRUE == pwr_ThreeWheelStop) { if ((FALSE == pwr_busoff) && (FALSE == pwr_lostSCS)) { pwr_VStpFlag = TRUE; } else { pwr_VStpFlag = FALSE;  } } else { if (((VALID == pwr_TrShftLvrPosv) && (TYPE_ACC_GEARLVLP == pwr_TrShftLvrPos)) && (FALSE == pwr_busoff)) { pwr_VStpFlag = TRUE; } else { pwr_VStpFlag = FALSE;  } }  if(FALSE == pwr_VStpFlag) { if (((VALID == pwr_TrShftLvrPosv) && (TYPE_ACC_GEARLVLP == pwr_TrShftLvrPos)) && (FALSE == pwr_busoff) && (TRUE == pwr_lostSCS)) { pwr_VStpFlag = TRUE; } else { pwr_VStpFlag = FALSE;  } } else { }   } /*************************************************** pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Function: pwr_SSBLongPressDetect_20ms pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Description: detect if the status of ssb is long press pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Parameters: none pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Returns: none pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h $Create & Verlog:$ pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Author:Xueping.Chen Date:2016-12-09 Version:V1.0 ****************************************************/ static void pwr_SSBLongPressDetect_20ms(void) { SSBData_ST ssbvalue; U8 res = 0;  static U8 KeySts =FALSE;  res = SSB_GetSSBValue(&ssbvalue); if ((RET_OK == res) && (ACTIVE == ssbvalue.status) && (VALID == ssbvalue.valid)) { pwr_Cnt2Second++; if (pwr_Cnt2Second >= pwr_SSBlongPreCnt) { if (FALSE ==KeySts) { KeySts =TRUE; pwr_SsbLongPressedFlag = TRUE; } else { } } else { } } else { pwr_Cnt2Second = 0; pwr_SsbLongPressedFlag = FALSE; KeySts =FALSE; } }  /*************************************************** pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Function: pwr_PowerMode_10ms pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Description: get the mode of power pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Parameters: none pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Returns: none pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h $Create & Verlog:$ pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Author:Xueping.Chen Date:2016-12-09 Version:V1.0 pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Author:LIUYINGYING Date:2017-06-27 Version:V2.0 ****************************************************/ static void pwr_PowerMode_10ms(void) { U8 res = RET_FAIL;  pwr_busoff = NWD_GetBusOffFlt();  res = NWD_GetNodeMissing(INDEX_BCM_NODE,&pwr_LostIcm); res = NWD_GetNodeMissing(INDEX_SCS_NODE,&pwr_lostSCS); res = NWD_GetNodeMissing(INDEX_ECM_NODE, &pwr_lostECM);  COM_GetSignalValue_8(INDEX_COM_RS_BCMPWRMDHWDSTAV, &pwr_NetBCMPwrMdHwdStaV); COM_GetSignalValue_8(INDEX_COM_RS_BCMPwrMdHwdSt, &pwr_NetBCMPwrMdHwdSta); COM_GetSignalValue_BOOL(INDEX_COM_RS_ENRUNA, &pwr_NetEnRunA);  if ((TRUE == pwr_LostIcm) ||(TRUE == pwr_busoff) || (INVALID == pwr_NetBCMPwrMdHwdStaV)) { pwr_NetSysBPMEnbd = TRUE; } else { pwr_NetSysBPMEnbd = FALSE; }  pwr_BackUpPowerMode_Process(); pwr_Update_D001_Value();   }  /*************************************************** pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Function: pwr_CheckStatus_50ms pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Description: the process of the checking pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Parameters: none pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Returns: none pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h $Create & Verlog:$ pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Author:Xueping.Chen Date:2016-12-09 Version:V1.0 ****************************************************/ static void pwr_CheckStatus_100ms(void) { if ((pwr_NetSysBPM != pwr_CPwrMode)) { if(((PWR_OFF == pwr_NetSysBPM) || (PWR_ACC== pwr_NetSysBPM)) && ((PWR_RUN == pwr_CPwrMode) || (PWR_CRANK== pwr_CPwrMode))) {  pwr_CheckStatus = STATUS_SLFCHK_NOT_READY; pwr_Cnt5Second = 0; } else if(((PWR_RUN == pwr_NetSysBPM) || (PWR_CRANK== pwr_NetSysBPM)) && ((PWR_OFF == pwr_CPwrMode) || (PWR_ACC== pwr_CPwrMode))) {  pwr_CheckStatus = STATUS_SLFCHK_ING; pwr_Cnt5Second = 0; } else {  }   } else { if (STATUS_SLFCHK_ING == pwr_CheckStatus) { pwr_Cnt5Second++; if (CHECKSTATUS_50MSPERIOD_MAXCOUNT <= pwr_Cnt5Second) { pwr_Cnt5Second = 0; pwr_CheckStatus = STATUS_SLFCHK_FINISH; } else { } } else {  } }  pwr_CPwrMode = pwr_NetSysBPM;   }  /*************************************************** pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Function: pwr_BackUpPowerMode_Process pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Description: the process of backup power pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Parameters: none pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Returns: none pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h $Create & Verlog:$ pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Author:Xueping.Chen Date:2016-12-09 Version:V1.0 ****************************************************/ static void pwr_BackUpPowerMode_Process(void) { switch (pwr_NetSysBPM) { case PWR_OFF: pwr_OffModeTrans(); break; case PWR_ACC: pwr_AccModeTrans(); break; case PWR_RUN: pwr_RunModeTrans(); break; case PWR_CRANK: pwr_CrankModeTrans(); break; case PWR_UNKNOWN: break; default: break; } }  /*************************************************** pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Function: pwr_OffModeTrans pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Description: the mode of power from off to other pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Parameters: none pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Returns: none pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h $Create & Verlog:$ pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Author:Xueping.Chen Date:2016-12-09 Version:V1.0 ****************************************************/ static void pwr_OffModeTrans(void) {  U8 SCSNodeLost = FALSE; U8 ECMNodeLost = FALSE;  U8 res = RET_FAIL;  res = NWD_GetNodeMissing(INDEX_SCS_NODE, &SCSNodeLost); res = NWD_GetNodeMissing(INDEX_ECM_NODE, &ECMNodeLost);  COM_GetSignalValue_8(INDEX_COM_RS_VEHSPDAVGDRVNV, &pwr_NetVehSpdAvgDrvnV); /*车速有效性*/ COM_GetSignalValue_16(INDEX_COM_RS_VEHSPDAVGDRVN, &pwr_NetVehSpdAvgDrvn); /*车速*/  if ((FALSE == pwr_LostIcm)/*FLOW 2*/ && (VALID == pwr_NetBCMPwrMdHwdStaV) && (PWR_ACC == pwr_NetBCMPwrMdHwdSta) && (FALSE == NWD_GetBusOffFlt())) { pwr_NetSysBPM = PWR_ACC; } else if ((FALSE == pwr_LostIcm)/*FLOW 16*/ && (FALSE == pwr_busoff) && (VALID == pwr_NetBCMPwrMdHwdStaV) && (PWR_CRANK == pwr_NetBCMPwrMdHwdSta) && (NORMAL_MODE == pmOperationalMode)) { pwr_NetSysBPM = PWR_CRANK; } else { if ((MANUFACTURE_MODE == pmOperationalMode)/*FLOW 18*/ && (TRUE== pwr_SsbLongPressedFlag)) { pwr_SsbLongPressedFlag = FALSE; pwr_NetSysBPM = PWR_RUN;  NVM_SetParas(INDEX_NVM_RUNKEEP,&pwr_NetSysBPM,1); } else if ((FALSE == pwr_LostIcm)/*FLOW 17-1*/ && (VALID == pwr_NetBCMPwrMdHwdStaV) && (PWR_RUN == pwr_NetBCMPwrMdHwdSta) && (FALSE == NWD_GetBusOffFlt())) { pwr_NetSysBPM = PWR_RUN; } else if (((TRUE == pwr_LostIcm) || (INVALID == pwr_NetBCMPwrMdHwdStaV))/*FLOW 17-2 NEED CD CONFIRM*/ && (FALSE != pwr_NetEnRunA) && ((VALID == pwr_NetVehSpdAvgDrvnV) && (pwr_NetVehSpdAvgDrvn >= gloVehMovingThresholdPrm) && (FALSE == pwr_lostSCS) && (FALSE == pwr_lostECM))) { pwr_NetSysBPM = PWR_RUN; } else { } } }  /*************************************************** pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Function: pwr_AccModeTrans pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Description: the mode of power from acc to other pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Parameters: none pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Returns: none pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h $Create & Verlog:$ pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Author:Xueping.Chen Date:2016-12-09 Version:V1.0 ****************************************************/ static void pwr_AccModeTrans(void) { SSBData_ST ssbvalue;  COM_GetSignalValue_8(INDEX_COM_RS_VEHSPDAVGDRVNV, &pwr_NetVehSpdAvgDrvnV); /*车速有效性*/ COM_GetSignalValue_16(INDEX_COM_RS_VEHSPDAVGDRVN, &pwr_NetVehSpdAvgDrvn); /*车速*/ COM_GetSignalValue_8(INDEX_COM_RS_BCMPWRMDHWDSTAV, &pwr_NetBCMPwrMdHwdStaV);  if ((TRUE == pwr_busoff) || (TRUE == pwr_LostIcm))/*FLOW 4*/ { pwr_NetSysBPM = PWR_OFF; } else /*(BUS OFF = FALSE) && (FALSE == pwr_LostIcm )*/ { if( (VALID == pwr_NetBCMPwrMdHwdStaV)/*FLOW 3*/ && (PWR_OFF == pwr_NetBCMPwrMdHwdSta)) { pwr_NetSysBPM = PWR_OFF; } else if ((VALID == pwr_NetBCMPwrMdHwdStaV)/*FLOW17-1*/ && (PWR_RUN == pwr_NetBCMPwrMdHwdSta)) { pwr_NetSysBPM = PWR_RUN; } else if (((TRUE == pwr_LostIcm) || (INVALID == pwr_NetBCMPwrMdHwdStaV))/*FLOW 17-2 NEED CD CONFIRM*/ && (FALSE != pwr_NetEnRunA) && ((VALID == pwr_NetVehSpdAvgDrvnV) && (pwr_NetVehSpdAvgDrvn >= gloVehMovingThresholdPrm) && (FALSE == pwr_lostSCS) && (FALSE == pwr_lostECM))) { pwr_NetSysBPM = PWR_RUN; } else if ( (FALSE == pwr_LostIcm) /*16*/ && (FALSE == pwr_busoff) &&(VALID == pwr_NetBCMPwrMdHwdStaV)/*FLOW 16*/ && (PWR_CRANK == pwr_NetBCMPwrMdHwdSta) && (NORMAL_MODE == pmOperationalMode)) { pwr_NetSysBPM = PWR_CRANK; } else { } } }  /*************************************************** pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Function: pwr_RunModeTrans pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Description: the mode of power from run to other pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Parameters: none pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Returns: none pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h $Create & Verlog:$ pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Author:Xueping.Chen Date:2016-12-09 Version:V1.0 ****************************************************/ static void pwr_RunModeTrans(void) { SSBData_ST ssbvalue; U8 res;  COM_GetSignalValue_BOOL(INDEX_COM_RS_BCMEMGCSP, &pwr_NetBCMEmgcSp);  res = SSB_GetSSBValue(&ssbvalue); if ((MANUFACTURE_MODE == pmOperationalMode)/*FLOW 19*/ && (TRUE== pwr_SsbLongPressedFlag)) { pwr_SsbLongPressedFlag = FALSE; pwr_NetSysBPM = PWR_OFF; } else if ((FALSE == pwr_VStpFlag)/*FLOW 11 +8*/ && (NORMAL_MODE == pmOperationalMode) && (TRUE== pwr_SsbLongPressedFlag)) { pwr_SsbLongPressedFlag = FALSE; pwr_NetSysBPM = PWR_OFF; } else if ((FALSE == pwr_LostIcm)/*FLOW 10 +8*/ && (FALSE == pwr_busoff) && (FALSE == pwr_VStpFlag) && (NORMAL_MODE == pmOperationalMode) && (FALSE != pwr_NetBCMEmgcSp)) { pwr_NetSysBPM = PWR_OFF; } else if ((NORMAL_MODE == pmOperationalMode)/*FLOW 12+20 CONFLICT CD CONFIRM*/ && (FALSE == pwr_busoff) && (TRUE == pwr_LostIcm) && (TRUE == pwr_VStpFlag) && ((RET_OK == res) && (ACTIVE == ssbvalue.status) && (VALID== ssbvalue.valid))) { pwr_NetSysBPM = PWR_OFF; } else if ((FALSE == pwr_LostIcm)/*FLOW 15*/ && (FALSE == pwr_busoff) && (NORMAL_MODE == pmOperationalMode) && (TRUE == pwr_VStpFlag) && (PWR_OFF == pwr_NetBCMPwrMdHwdSta) && (VALID == pwr_NetBCMPwrMdHwdStaV)) { pwr_NetSysBPM = PWR_OFF; } else if ((FALSE == pwr_LostIcm)/*FLOW 5*/ && (FALSE == pwr_busoff) && (PWR_ACC == pwr_NetBCMPwrMdHwdSta) && (VALID == pwr_NetBCMPwrMdHwdStaV) && (TRUE == pwr_VStpFlag) && (NORMAL_MODE == pmOperationalMode)) { pwr_NetSysBPM = PWR_ACC; } else if ((FALSE == pwr_LostIcm) /*FLOW 16*/ && (FALSE == pwr_busoff) && (PWR_CRANK == pwr_NetBCMPwrMdHwdSta) && (VALID == pwr_NetBCMPwrMdHwdStaV) && (NORMAL_MODE == pmOperationalMode)) { pwr_NetSysBPM = PWR_CRANK; } else { } }  /*************************************************** pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Function: pwr_CrankModeTrans pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Description: the mode of power from crank to other pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Parameters: none pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Returns: none pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h $Create & Verlog:$ pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Author:Xueping.Chen Date:2016-12-09 Version:V1.0 ****************************************************/ static void pwr_CrankModeTrans(void) { SSBData_ST ssbvalue; U8 res = RET_FAIL;  COM_GetSignalValue_8(INDEX_COM_RS_VEHSPDAVGDRVNV, &pwr_NetVehSpdAvgDrvnV); /*车速有效性*/ COM_GetSignalValue_16(INDEX_COM_RS_VEHSPDAVGDRVN, &pwr_NetVehSpdAvgDrvn); /*车速*/   res = SSB_GetSSBValue(&ssbvalue); if ((VALID == pwr_NetBCMPwrMdHwdStaV)/*FLOW17-1*/ && (PWR_RUN == pwr_NetBCMPwrMdHwdSta)) { pwr_NetSysBPM = PWR_RUN; } else if (((TRUE == pwr_LostIcm) || (INVALID == pwr_NetBCMPwrMdHwdStaV))/*FLOW 17-2 NEED CD CONFIRM*/ && (FALSE != pwr_NetEnRunA) && ((VALID == pwr_NetVehSpdAvgDrvnV) && (pwr_NetVehSpdAvgDrvn >= gloVehMovingThresholdPrm) && (FALSE == pwr_lostSCS) && (FALSE == pwr_lostECM))) { pwr_NetSysBPM = PWR_RUN; }  else if ((RET_OK == res)/*FLOW 21*/ && (ACTIVE == ssbvalue.status) && (VALID== ssbvalue.valid)) {  pwr_NetSysBPM = PWR_RUN; } else {  } }  /*************************************************** pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Function: PWR_SendNetSignal_10ms pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Description: send net signal pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Parameters: none pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Returns: none pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h $Create & Verlog:$ pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Author:Xueping.Chen Date:2016-12-09 Version:V1.0 ****************************************************/ void PWR_SendNetSignal_10ms(void) { v_wr_bool(SysBPMEnbd_handle, pwr_NetSysBPMEnbd); v_wr_8(SysBPM_handle, pwr_NetSysBPM); }  /*************************************************** pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Function: pwr_WheelStop pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Description: judge if the wheel stop pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Parameters: none pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Returns: none pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h $Create & Verlog:$ pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Author:Xueping.Chen Date:2016-12-09 Version:V1.0 ****************************************************/ static void pwr_WheelStop(void) { U8 num = 0; U8 i = 0; U16 pwr_Wheeldata[PWR_WHEEL_NUM]; U8 pwr_WheelVaild[PWR_WHEEL_NUM]; static BOOL pwr_whl_stop[PWR_WHEEL_NUM]={FALSE};  COM_GetSignalValue_16(INDEX_COM_RS_WHLGNDVELLDRVN, &pwr_NetWhlGNDVelLDvn); COM_GetSignalValue_8(INDEX_COM_RS_WHLGNDVELLDRVNV, &pwr_NetWhlGNDVelLDvnv); COM_GetSignalValue_16(INDEX_COM_RS_WHLGNDVELLNONDRVN, &pwr_NetWhlGNDVelLnonDvn); COM_GetSignalValue_8(INDEX_COM_RS_WHLGNDVELLNONDRVNV, &pwr_NetWhlGNDVelLnonDvnv); COM_GetSignalValue_16(INDEX_COM_RS_WhlGndVelRDrvn, &pwr_NetWhlGNDVelRDvn); COM_GetSignalValue_8(INDEX_COM_RS_WHLGNDVELRDRVNV, &pwr_NetWhlGNDVelRDvnv); COM_GetSignalValue_16(INDEX_COM_RS_WHLGNDVELRNONDRVN, &pwr_NetWhlGNDVelRnonDvn); COM_GetSignalValue_8(INDEX_COM_RS_WHLGNDVELRNONDRVNV, &pwr_NetWhlGNDVelLRnonDvnv);  pwr_Wheeldata[0] = pwr_NetWhlGNDVelLDvn; pwr_Wheeldata[1] = pwr_NetWhlGNDVelLnonDvn; pwr_Wheeldata[2] = pwr_NetWhlGNDVelRDvn; pwr_Wheeldata[3] = pwr_NetWhlGNDVelRnonDvn; pwr_WheelVaild[0] = pwr_NetWhlGNDVelLDvnv; pwr_WheelVaild[1] = pwr_NetWhlGNDVelLnonDvnv; pwr_WheelVaild[2] = pwr_NetWhlGNDVelRDvnv; pwr_WheelVaild[3] = pwr_NetWhlGNDVelLRnonDvnv; for (i = 0; i < PWR_WHEEL_NUM; i++) { if (VALID == pwr_WheelVaild[i]) { if(pwr_Wheeldata[i] <= gloVehStoppedThresholdPrm) { pwr_whl_stop[i] = TRUE; } else if(pwr_Wheeldata[i] >= gloVehMovingThresholdPrm) { pwr_whl_stop[i] = FALSE; } } else { } }  for (i = 0; i < PWR_WHEEL_NUM; i++) { if(TRUE == pwr_whl_stop[i]) { num ++; } else { }  } if(PWR_WHEEL_THREASHOLD <= num) { pwr_ThreeWheelStop = TRUE; } else { pwr_ThreeWheelStop = FALSE; } }  /*************************************************** pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Function: pwr_Process_D001_Value pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Description: update D001 pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Parameters: none pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Returns: D001 Value pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h $Create & Verlog:$ pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Author:liuyingying Date:2017-07-11 Version:V2.0 ****************************************************/ static void pwr_Update_D001_Value(void) { U8 Value;  COM_GetSignalValue_8(INDEX_COM_RS_SYSPWRMD,&Value); pwr_D001.pwr_u.gCrkSts = ((Value != 0)? TRUE:FALSE); pwr_D001.pwr_u.gEnginerunA = ((pwr_NetEnRunA != 0)? TRUE:FALSE); COM_GetSignalValue_8(INDEX_COM_RS_PWRMDMSTRRUNCRKA,&Value); pwr_D001.pwr_u.gRunSts = ((Value != 0)? TRUE:FALSE); COM_GetSignalValue_8(INDEX_COM_RS_PWRMDMSTRACCRYA,&Value); pwr_D001.pwr_u.gAccSts = ((Value != 0)? TRUE:FALSE);  pwr_D001.pwr_u.sCrkSts = pwr_D001.pwr_u.gCrkSts; pwr_D001.pwr_u.sEnginerunA =pwr_D001.pwr_u.gEnginerunA; pwr_D001.pwr_u.sRunSts = pwr_D001.pwr_u.gRunSts; pwr_D001.pwr_u.sAccSts = pwr_D001.pwr_u.gAccSts;  } /*************************************************** pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Function: PWR_GetPwrMode pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Description: get the working mode of the power pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Parameters: none pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Returns: RET_FAIL RET_INVALID RET_OK pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h $Create & Verlog:$ pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Author:Xueping.Chen Date:2016-12-09 Version:V1.0 ****************************************************/ U8 PWR_GetPwrMode(PU8 mode) { U8 res = RET_OK;  if (FALSE == pwr_InitSts) { res = RET_FAIL; } else if (NULL_PTR == mode) { res = RET_INVALID; } else { *mode = pwr_NetSysBPM; } return res; }   /*************************************************** pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Function: PWR_GetChkStatus pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Description: get the status of checking pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Parameters: none pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Returns: RET_FAIL RET_INVALID RET_OK pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h $Create & Verlog:$ pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Author:Xueping.Chen Date:2016-12-09 Version:V1.0 ****************************************************/ U8 PWR_GetChkStatus(PU8 chkstatus) { U8 res = RET_OK;  if (FALSE == pwr_InitSts) { res = RET_FAIL; } else if (NULL_PTR == chkstatus) { res = RET_INVALID; } else { *chkstatus = pwr_CheckStatus; } return res; }  /*************************************************** pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Function: PWR_Get_D001_Value pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Description: get the status of checking pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Parameters: none pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Returns: D001 Value pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h $Create & Verlog:$ pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Author:liuyingying Date:2017-07-11 Version:V2.0 ****************************************************/ U8 PWR_Get_D001_Value(void) { return pwr_D001.Value; }  /*=========================================================================== pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h File Revision History(bottom to top:first revision to last revision) *============================================================================ pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h $Log:$ * pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h Rev: Userid: Date: Description *-------- ---------- --------- ------------------------------ * pwr.c pwr_cfg.h pwr_info.inc pwr_private.h pwr_public.h V1.0 Xueping.Chen 2016-12-09 Initial * *===========================================================================*/
