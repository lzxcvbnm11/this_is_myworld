/************************************************************************** | Copyright |------------------------------------------------------------------------ |Copyright(c) by YEEDON MultiMedia Co.LTD. All rights reserved. | | this software if furnished under a license and may be used and copied | only in accordance with the terms of such license and with the inclusion | of he above copyright notic.This software or any other copies thereof | may not be provided of otherwise made available to any other persion. | No title to and ownership of the software is hereby transferred. | | the information in this software is subject to change without notice | and should not be construed as a commitment by | YEEDON MultiMedia Co.LTD. | | YEEDON MultiMedia Co.LTD. assumes no responsibility for the use or reliability | of its Software on equipment which is not supported by YEEDON MultiMedia Co.LTD. |-------------------------------------------------------------- **************************************************************************/    /*-----------------------------------------------------------------------*/ /*----Description of file-----------------------------------------------------*/ /*-----------------------------------------------------------------------*/    /************************************************************************* LED public file used for LED ON,OFF,FLASH control when warn or other event trigged *************************************************************************/  /*------------------------------------------------------------------------*/ /*-----Head of file----------------------------------------------------------*/ /*------------------------------------------------------------------------*/  /*check of multiple include*/ #ifndef _LED_PUBLIC_H_ #define _LED_PUBLIC_H_  #include "yd_typedefs.h" #include "stsmg_public.h" #include "lrm_public.h" /*Files for including*/   /*Public Macro definitions*/   /*Public external functions declarations*/ extern void LED_Init(void); extern void LED_Process_50ms(void); extern BOOL LED_GetLevel(void); extern BOOL LED_Get_Brake_Level(void);  extern BOOL LED_GetEventResult(LED_EVENT_ENUM index); extern U8 LED_GetLampStatus(LRMState_UN *value,U8 size);    /*-----End of File----------------------------------------*/ #endif/*_LED_PUBLIC_H*/  /*======================================================= led.c led_cfg.h led_info.inc led_private.h led_public.h File Revision History (bottom to top:first revision to last revision) * *======================================================== *$Log:$ *  *Rev: Userid: date: description *----- ----- ----------- ----------- *Rev 1 liuyingying 2016-11-24 initial =========================================================*/
