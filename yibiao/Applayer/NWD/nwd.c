 /************************************************************************** | Copyright |------------------------------------------------------------------------ |Copyright(c) by YEEDON MultiMedia Co.LTD. All rights reserved. | | this software if furnished under a license and may be used and copied | only in accordance with the terms of such license and with the inclusion | of he above copyright notic.This software or any other copies thereof | may not be provided of otherwise made available to any other persion. | No title to and ownership of the software is hereby transferred. | | the information in this software is subject to change without notice | and should not be construed as a commitment by | YEEDON MultiMedia Co.LTD. | | YEEDON MultiMedia Co.LTD. assumes no responsibility for the use or reliability | of its Software on equipment which is not supported by YEEDON MultiMedia Co.LTD. |-------------------------------------------------------------- **************************************************************************/    /*-----------------------------------------------------------------------*/ /*----Description of file-----------------------------------------------------*/ /*-----------------------------------------------------------------------*/    /************************************************************************* LED source file used for LED ON,OFF,FLASH control when warn or other event trigged *************************************************************************/   /*------------------------------------------------------------------------*/ /*-----Head of file----------------------------------------------------------*/ /*------------------------------------------------------------------------*/ #include "nwd_info.inc"  extern v_nwm_instance nwm_slave_instance ; static v_nwm_state nwd_nwm_state; static U8 nwd_InitSts = 0; static U8 BusOff_Process_Cnt = 0;  /******************************************************************************  nwd.c nwd_cfg.h nwd_info.inc nwd_private.h nwd_public.h Function:NWD_Init  nwd.c nwd_cfg.h nwd_info.inc nwd_private.h nwd_public.h Input:  nwd.c nwd_cfg.h nwd_info.inc nwd_private.h nwd_public.h Output:none  nwd.c nwd_cfg.h nwd_info.inc nwd_private.h nwd_public.h Returns:none  *******************************************************************************/ void NWD_Init(void) { U8 i =0;  nwd_InitSts = COM_GetInitSts(); BusOff_Process_Cnt = 0; }  /******************************************************************************  nwd.c nwd_cfg.h nwd_info.inc nwd_private.h nwd_public.h Function:NWD_Process_10ms  nwd.c nwd_cfg.h nwd_info.inc nwd_private.h nwd_public.h Input:  nwd.c nwd_cfg.h nwd_info.inc nwd_private.h nwd_public.h Output:none  nwd.c nwd_cfg.h nwd_info.inc nwd_private.h nwd_public.h Returns:none  *******************************************************************************/ void NWD_Process_5ms(void) { if(TRUE == nwd_InitSts) { nwd_NodeMissingChk_5ms();  BusOff_Process_Cnt = 1 - BusOff_Process_Cnt; if(0 == BusOff_Process_Cnt) { nwd_CANBusoffMonitor_10ms(); } else { } } else { /*do nothing*/ } }  /******************************************************************************  nwd.c nwd_cfg.h nwd_info.inc nwd_private.h nwd_public.h Function:NWD_GetNodeMissing  nwd.c nwd_cfg.h nwd_info.inc nwd_private.h nwd_public.h Input:none  nwd.c nwd_cfg.h nwd_info.inc nwd_private.h nwd_public.h Output:state  nwd.c nwd_cfg.h nwd_info.inc nwd_private.h nwd_public.h Returns:RET_OK,RET_FAIL,RET_INVALID  *******************************************************************************/ U8 NWD_GetNodeMissing(NwdNodeIndex_ENUM NodeIndex,PU8 sts)  { U8 res = RET_FAIL;  if (FALSE == nwd_InitSts) { res = RET_FAIL; } else if(NULL_PTR == sts) { res = RET_INVALID; } else { if( NO_FAULT_STATE == iNodeTimeout[NodeIndex].FaultState) { *sts = FALSE; } else { *sts = TRUE; }  res = RET_OK; } return res; } /******************************************************************************  nwd.c nwd_cfg.h nwd_info.inc nwd_private.h nwd_public.h Function:NWD_GetBusOffFlt  nwd.c nwd_cfg.h nwd_info.inc nwd_private.h nwd_public.h Input:none  nwd.c nwd_cfg.h nwd_info.inc nwd_private.h nwd_public.h Output:none  nwd.c nwd_cfg.h nwd_info.inc nwd_private.h nwd_public.h Returns: TRUE:BUS OFF FAULT STATE FALSE: NORMAL STATE  *******************************************************************************/ BOOL NWD_GetBusOffFlt(void) { if((CURRENT_FAULT_STATE == iCanBusOff.FaultState) ||(HEAL_FAULT_STATE == iCanBusOff.FaultState) ) { return TRUE; } else { return FALSE; } }  /******************************************************************************  nwd.c nwd_cfg.h nwd_info.inc nwd_private.h nwd_public.h Function:NodeMissingChk_5ms  nwd.c nwd_cfg.h nwd_info.inc nwd_private.h nwd_public.h Input:  nwd.c nwd_cfg.h nwd_info.inc nwd_private.h nwd_public.h Output:none  nwd.c nwd_cfg.h nwd_info.inc nwd_private.h nwd_public.h Returns:none  nwd.c nwd_cfg.h nwd_info.inc nwd_private.h nwd_public.h Calls: v_test_flag  nwd.c nwd_cfg.h nwd_info.inc nwd_private.h nwd_public.h Note:check frame timeout  1.must in normal state  2.timeout time great than 2000ms or 20000ms  3.recovery time = 100*period  *******************************************************************************/ void nwd_NodeMissingChk_5ms(void) {  U8 i;  /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Node Missing check */ nwd_nwm_state = v_nwm_get_state( &nwm_slave_instance ); for (i = (INDEX_ECM_NODE ); i < INDEX_NODE_ALL; i++)  // for (i = (INDEX_FICM_NODE ); i < INDEX_FICM_NODE+1; i++)  {  if (V_NWM_OPERATION == nwd_nwm_state/*flt detect condition is meet*/) {  /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr received monitoring frames */  if (v_test_flag(NODE_MONITOR_FLAGS[i])) {  switch (iNodeTimeout[i].FaultState) {  case NO_FAULT_STATE: { iNodeTimeout[i].TimeOutCount = 0;  iNodeTimeout[i].HealValidFramCount = 0;  break; }   case CURRENT_FAULT_STATE:  {  iNodeTimeout[i].FaultState = HEAL_FAULT_STATE;  iNodeTimeout[i].HealValidFramCount = 0;  break;  }  case HEAL_FAULT_STATE:  {  if (iNodeTimeout[i].HealValidFramCount < NODE_HEAL_COUNT[i])  {  iNodeTimeout[i].HealValidFramCount++; iNodeTimeout[i].LastValidCount=iNodeTimeout[i].HealValidFramCount;  } else  { iNodeTimeout[i].FaultState = NO_FAULT_STATE; iNodeTimeout[i].TimeOutCount = 0; iNodeTimeout[i].HealValidFramCount = 0;  } break; } default: { break; } } iNodeTimeout[i].TimeOutCount = 0;  } /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr end if (iNodeTimeout[i].FaultState == HEAL_FAULT_STATE) */  else /*not received monitoring frames*/ { /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr take count of timeout */ switch (iNodeTimeout[i].FaultState) { case NO_FAULT_STATE: { if (iNodeTimeout[i].TimeOutCount < (NODE_MISSSING_COUNT[i])) { iNodeTimeout[i].TimeOutCount++; } else  { iNodeTimeout[i].FaultState = CURRENT_FAULT_STATE; iNodeTimeout[i].HealValidFramCount = 0; iNodeTimeout[i].LastValidCount = 0;  }/* frame timeout confirm,enter fault state */ } break; case HEAL_FAULT_STATE: { if ((MAX_FRAME_ARRIVAL_DEBOUNCE*NODE_ONE_FRAME_COUNT[i]) < (iNodeTimeout[i].HealValidFramCount -iNodeTimeout[i].LastValidCount)) { iNodeTimeout[i].FaultState = CURRENT_FAULT_STATE; iNodeTimeout[i].HealValidFramCount = 0; iNodeTimeout[i].LastValidCount = 0;  } else if (iNodeTimeout[i].HealValidFramCount < NODE_HEAL_COUNT[i]) { iNodeTimeout[i].HealValidFramCount++; } else  { iNodeTimeout[i].FaultState = NO_FAULT_STATE; iNodeTimeout[i].TimeOutCount = 0; iNodeTimeout[i].HealValidFramCount = 0; iNodeTimeout[i].LastValidCount = 0;  } } break; case CURRENT_FAULT_STATE: { break; } default: { break; } } } /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr end else */   v_clear_flag(NODE_MONITOR_FLAGS[i]);  } else { iNodeTimeout[i].TimeOutCount = 0; iNodeTimeout[i].HealValidFramCount = 0; iNodeTimeout[i].LastValidCount = 0; } } /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr end for(i=(NODE_AAA_INDEX+1);i<NODE_ZZZ_INDEX;i++)*/ } /******************************************************************************* nwd.c nwd_cfg.h nwd_info.inc nwd_private.h nwd_public.h Function:CANBusoffMonitor_10ms nwd.c nwd_cfg.h nwd_info.inc nwd_private.h nwd_public.h Input:CANBusoff state from NWM module nwd.c nwd_cfg.h nwd_info.inc nwd_private.h nwd_public.h Output:none nwd.c nwd_cfg.h nwd_info.inc nwd_private.h nwd_public.h Returns:none nwd.c nwd_cfg.h nwd_info.inc nwd_private.h nwd_public.h Calls:dfpm_set_error_flag ******************************************************************************/ static void nwd_CANBusoffMonitor_10ms(void) {  /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr appear busoff */  if ((V_NWM_BUSOFF == nwd_nwm_state) || (V_NWM_BUSOFF_WAIT==nwd_nwm_state))/*current network status通过调用函数v_nwm_get_state获得*/ { switch (iCanBusOff.FaultState) { case NO_FAULT_STATE: { if (iCanBusOff.CurrentCount < BUSOFF_FAULT_COUNT) { iCanBusOff.CurrentCount++; } else  { iCanBusOff.FaultState = CURRENT_FAULT_STATE; } break; } case HEAL_FAULT_STATE: { iCanBusOff.FaultState = CURRENT_FAULT_STATE; break; } case CURRENT_FAULT_STATE: { break; } default: { break; } } } /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr end*/  else if(V_NWM_OPERATION == nwd_nwm_state)/* disappear busoff */ { switch (iCanBusOff.FaultState) { case CURRENT_FAULT_STATE: { iCanBusOff.FaultState = HEAL_FAULT_STATE; iCanBusOff.HealCount = BUSOFF_HEAL_COUNT; break; } case HEAL_FAULT_STATE: { if (iCanBusOff.HealCount > 0) { iCanBusOff.HealCount--; } else { iCanBusOff.FaultState = NO_FAULT_STATE; iCanBusOff.CurrentCount = 0; } break; } case NO_FAULT_STATE: { break; } default:  { break; } } } /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr end else */ else { }   }     /*=========================================================================================================== nwd.c nwd_cfg.h nwd_info.inc nwd_private.h nwd_public.h File Revision History (bottom to top:first revision to last revision) * *============================================================================================================ *$Log:$ *  *Rev: Userid: date: description *----- ----- ----------- ----------- *Rev 2 huangyifan 2017-07-05 initial ============================================================================================================*/
