/***************************************************************************** iom.c iom_cfg.h iom_info.inc iom_private.h iom_public.h Copyright (C) 2016 ShenZhen Yeedon Media co.,LTD. All rights reserved. * iom.c iom_cfg.h iom_info.inc iom_private.h iom_public.h File Name : iom_private.h iom.c iom_cfg.h iom_info.inc iom_private.h iom_public.h Description : the private informations of the Iom module iom.c iom_cfg.h iom_info.inc iom_private.h iom_public.h Author: Xueping.Chen iom.c iom_cfg.h iom_info.inc iom_private.h iom_public.h Date: 2016-11-24 ******************************************************************************/  /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr check of multiple include */ #ifndef _IOM_PRIVATE_H_  #define _IOM_PRIVATE_H_  #include "yd_typedefs.h" #include "dio_public.h"   /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Macro defines */ #define IOM_DEBOUNCE_MAXCNT 3 /*the counter of the IO debounce*/ #define INPUT 1 /*IO is input port*/ #define OUTPUT 0 /*IO is output port*/   /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Private data structures defines */ typedef struct IomMatrix_Tag { BOOL enable; /*whether enable the IO*/ DioPortNum_ENUM ch; /*the channel of the IO port*/ BOOL type; /*the type of the IO port(input or output)*/ }IomMatrix_ST;  typedef struct IomDebounceData_Tag {  BOOL value; /*read the level of the IO real-timeIO*/ BOOL debounce; /*store the level of the IO after debounce*/ U8 res; /*the result of the debounce*/ U8 cnt; /*the counter of the debounce*/ }IomDebounceData_ST;  /*constant define*/ const IomMatrix_ST Iom_Matrix[INDEX_IOINTPUT_ALL+INDEX_IOOUTPUT_ALL]= { {TRUE, INDEX_DIO_PIN93, INPUT}, /*冬季模式端口*/  {TRUE, INDEX_DIO_PIN97, INPUT}, /*自动启停开关*/ {TRUE, INDEX_DIO_PIN99, INPUT}, /*巡航数字IO*/ {TRUE, INDEX_DIO_PIN100, INPUT}, /*经济驾驶模式开关*/ {TRUE, INDEX_DIO_PIN101, INPUT}, /*机油压力低信号*/ {TRUE, INDEX_DIO_PIN103, INPUT}, /*手刹数字信号*/ {TRUE, INDEX_DIO_PIN12, INPUT}, /*启停AD唤醒输入*/ {TRUE, INDEX_DIO_PIN104, INPUT}, /*交流灯状态*/ {TRUE, INDEX_DIO_PIN10, OUTPUT}, /*防盗灯输出控制*/ {TRUE, INDEX_DIO_PIN16, OUTPUT}, /*受控电源输出端口*/ {TRUE, INDEX_DIO_PIN86, OUTPUT}, /*报警灯的使能控制*/ {TRUE, INDEX_DIO_PIN87, OUTPUT}, /*蜂鸣器的频率控制*/ {TRUE, INDEX_DIO_PIN88, OUTPUT}, /*蜂鸣器的电源控制*/ {TRUE, INDEX_DIO_PIN89, OUTPUT}, /*IGN高驱输出端口*/ {TRUE, INDEX_DIO_PIN90, OUTPUT}, /*ACC高驱输出端口*/ {TRUE, INDEX_DIO_PIN91, OUTPUT}, /*AUTO HOLD*/ {TRUE, INDEX_DIO_PIN92, OUTPUT}, /*自启停LED灯控制*/ {TRUE, INDEX_DIO_PIN142, OUTPUT}, /*CAN STANDBY 控制*/ };   /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Private static functions declare */ static U8 iom_InputDebounce(IomInPut_ENUM index);   #endif /*_IOM_PRIVATE_H_*/  /*------------------end of file----------------------------*/  /*=========================================================================== iom.c iom_cfg.h iom_info.inc iom_private.h iom_public.h File Revision History(bottom to top:first revision to last revision) *============================================================================ iom.c iom_cfg.h iom_info.inc iom_private.h iom_public.h $Log:$ * iom.c iom_cfg.h iom_info.inc iom_private.h iom_public.h Rev: Userid: Date: Description *-------- ---------- --------- ------------------------------ * iom.c iom_cfg.h iom_info.inc iom_private.h iom_public.h V1.0 Xueping.Chen 2016-11-24 Initial * *===========================================================================*/
