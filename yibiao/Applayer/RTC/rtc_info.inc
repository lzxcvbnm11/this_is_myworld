/*****************************************************************************
* Copyright (C) 2016 ShenZhen Yeedon Media co.,LTD. All rights reserved.
*
* File Name : rtc_info.inc
* Description : including rtc module all header files
* Author: Hejianjun
* Date: 2016-12-05
******************************************************************************/

/* check of multiple include */
#ifndef _RTC_INFO_INC_

#define _RTC_INFO_INC_


/* Files for including */

#include "yd_typedefs.h" 
#include "r_tick_api.h"
#include "nzm_public.h"
#include "rtca_public.h"
#include "ostm_public.h"
#include "pwr_public.h"
#include "com_public.h"
#include "st_public.h"

#include "trip_public.h"
#include "rst_public.h"
#include "diag_public.h"

#include "rtc_public.h"
#include "rtc_private.h"
#include "rtc_cfg.h"
#endif /*_RTC_INFO_INC_*/

/*----------------end of file------------------------*/

/*===========================================================================
* File Revision History(bottom to top:first revision to last revision)
*============================================================================
* $Log:$
*
* Rev:         Userid:           Date:               Description
*--------    ----------       ---------       ------------------------------
*
* V1.0        Hejianjun        2016-12-05      Initial
* V2.0         zxx               2017-06-28      modify
*
*                   1.add diag public
*                   2.delete nvm_public 
*===========================================================================*/