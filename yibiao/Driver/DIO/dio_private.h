/***************************************************************************** dio.c dio_cfg.h dio_info.inc dio_private.h dio_public.h Y-AD4-007会议记录 V1.0 20161202.doc Y-AD4-007会议记录 V1.1 20161203.doc Copyright (C) 2016 ShenZhen Yeedon Media co.,LTD. All rights reserved. * dio.c dio_cfg.h dio_info.inc dio_private.h dio_public.h Y-AD4-007会议记录 V1.0 20161202.doc Y-AD4-007会议记录 V1.1 20161203.doc File Name : dio.c dio_cfg.h dio_info.inc dio_private.h dio_public.h Y-AD4-007会议记录 V1.0 20161202.doc Y-AD4-007会议记录 V1.1 20161203.doc Description : dio_private.h dio.c dio_cfg.h dio_info.inc dio_private.h dio_public.h Y-AD4-007会议记录 V1.0 20161202.doc Y-AD4-007会议记录 V1.1 20161203.doc Author: Qinhui.Shen dio.c dio_cfg.h dio_info.inc dio_private.h dio_public.h Y-AD4-007会议记录 V1.0 20161202.doc Y-AD4-007会议记录 V1.1 20161203.doc Date: 2016-10-14 ******************************************************************************/  /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr check of multiple include */ #ifndef _DIO_PRIVATE_H_  #define _DIO_PRIVATE_H_  /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Files for including */ #include "yd_typedefs.h" #include "dio_public.h"  typedef enum DioDir_Tag { DIR_DIO_OUTPUT = (0u), DIR_DIO_INPUT, DIR_DIO_ALL }DioDir_ENUM;  typedef enum DioPort_Tag { PORT_DIO_JP0 = (0u), PORT_DIO_P0, PORT_DIO_P1, PORT_DIO_P3, PORT_DIO_P10, PORT_DIO_P11, PORT_DIO_P16, PORT_DIO_P17, PORT_DIO_P21, PORT_DIO_P42, PORT_DIO_P43, PORT_DIO_P44, PORT_DIO_P45, PORT_DIO_ALL }DioPort_ENUM;  typedef struct DioGpio_Tag { DioPort_ENUM port; /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr 255-JP0, 0-P0, 1-P1, 3-P3....*/ U8 pin; DioDir_ENUM dir; /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr 0-output, 1-input*/ U8 initval; }DioGpio_ST;  const DioGpio_ST GpioList[INDEX_DIO_ALL]= { /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr port, pin, dir, initval */  /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr input */ { PORT_DIO_P17, 11, DIR_DIO_INPUT, 0}, { PORT_DIO_P3, 2, DIR_DIO_INPUT, 0}, { PORT_DIO_P3, 4, DIR_DIO_INPUT, 0}, { PORT_DIO_P3, 5, DIR_DIO_INPUT, 0}, { PORT_DIO_P3, 6, DIR_DIO_INPUT, 0}, { PORT_DIO_P3, 8, DIR_DIO_INPUT, 0}, { PORT_DIO_P0, 0, DIR_DIO_INPUT, 0}, { PORT_DIO_P3, 9, DIR_DIO_INPUT, 0}, /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr output */ { PORT_DIO_P0, 2, DIR_DIO_OUTPUT, 0}, { PORT_DIO_ALL, 0, DIR_DIO_OUTPUT, 0}, /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr no support???*/ { PORT_DIO_P17, 4, DIR_DIO_OUTPUT, 0}, { PORT_DIO_P17, 5, DIR_DIO_OUTPUT, 0}, { PORT_DIO_P17, 6, DIR_DIO_OUTPUT, 0}, { PORT_DIO_P17, 7, DIR_DIO_OUTPUT, 0}, { PORT_DIO_P17, 8, DIR_DIO_OUTPUT, 0}, { PORT_DIO_P17, 9, DIR_DIO_OUTPUT, 0}, { PORT_DIO_P17, 10, DIR_DIO_OUTPUT, 0}, { PORT_DIO_P0, 6, DIR_DIO_OUTPUT, 0}, { PORT_DIO_P16, 7, DIR_DIO_OUTPUT, 0}, { PORT_DIO_P17, 0, DIR_DIO_OUTPUT, 0}, { PORT_DIO_P17, 1, DIR_DIO_OUTPUT, 0}, { PORT_DIO_P17, 2, DIR_DIO_OUTPUT, 0}, { PORT_DIO_P17, 3, DIR_DIO_OUTPUT, 0}, { PORT_DIO_P16, 4, DIR_DIO_OUTPUT, 0}, { PORT_DIO_P16, 5, DIR_DIO_OUTPUT, 0}, { PORT_DIO_P16, 6, DIR_DIO_OUTPUT, 0}, };   #endif /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr _DIO_PRIVATE_H_ */  /*----------------- End of file -----------------*/  /*=========================================================================== dio.c dio_cfg.h dio_info.inc dio_private.h dio_public.h Y-AD4-007会议记录 V1.0 20161202.doc Y-AD4-007会议记录 V1.1 20161203.doc File Revision History(bottom to top:first revision to last revision) *============================================================================ dio.c dio_cfg.h dio_info.inc dio_private.h dio_public.h Y-AD4-007会议记录 V1.0 20161202.doc Y-AD4-007会议记录 V1.1 20161203.doc $Log:$ * dio.c dio_cfg.h dio_info.inc dio_private.h dio_public.h Y-AD4-007会议记录 V1.0 20161202.doc Y-AD4-007会议记录 V1.1 20161203.doc Rev: Userid: Date: Description *-------- ---------- --------- ------------------------------ * dio.c dio_cfg.h dio_info.inc dio_private.h dio_public.h Y-AD4-007会议记录 V1.0 20161202.doc Y-AD4-007会议记录 V1.1 20161203.doc V1.0 Qinhui.Shen 2016-10-14 Initial dio.c dio_cfg.h dio_info.inc dio_private.h dio_public.h Y-AD4-007会议记录 V1.0 20161202.doc Y-AD4-007会议记录 V1.1 20161203.doc V1.1 Qinhui.Shen 2016-12-16 adding pin82(P17_3) into GpioList[]. * *===========================================================================*/
