/***************************************************************************** common.gpj public.c public.h rt_nonfinite.c rt_nonfinite.h rtGetInf.c rtGetInf.h rtGetNaN.c rtGetNaN.h rtmodel.h rtwtypes.h s_typedef.h yd_typedefs.h Copyright (C) 2016 ShenZhen Yeedon Media co.,LTD. All rights reserved. * common.gpj public.c public.h rt_nonfinite.c rt_nonfinite.h rtGetInf.c rtGetInf.h rtGetNaN.c rtGetNaN.h rtmodel.h rtwtypes.h s_typedef.h yd_typedefs.h File Name : yd_typedefs.h common.gpj public.c public.h rt_nonfinite.c rt_nonfinite.h rtGetInf.c rtGetInf.h rtGetNaN.c rtGetNaN.h rtmodel.h rtwtypes.h s_typedef.h yd_typedefs.h Description : This file is for common definition. common.gpj public.c public.h rt_nonfinite.c rt_nonfinite.h rtGetInf.c rtGetInf.h rtGetNaN.c rtGetNaN.h rtmodel.h rtwtypes.h s_typedef.h yd_typedefs.h Author: Qinhui.Shen common.gpj public.c public.h rt_nonfinite.c rt_nonfinite.h rtGetInf.c rtGetInf.h rtGetNaN.c rtGetNaN.h rtmodel.h rtwtypes.h s_typedef.h yd_typedefs.h Date: 2016-10-14 ******************************************************************************/  #ifndef __YD_TYPEDEFS_H__  #define __YD_TYPEDEFS_H__ #include <stdio.h> #include <stdlib.h> #include <string.h>   /****************************************************************************** Typedef definitions ******************************************************************************/ /* typedef signed char int8_t; typedef signed short int16_t; typedef signed int int32_t; typedef signed long long int64_t; typedef unsigned char uint8_t; typedef unsigned short uint16_t; typedef unsigned int uint32_t; typedef unsigned long long uint64_t; */ typedef signed long long S64; /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Signed 64Bit datatype */ typedef unsigned long long U64; /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Unsigned 64Bit datatype */ typedef signed long long common.gpj public.c public.h rt_nonfinite.c rt_nonfinite.h rtGetInf.c rtGetInf.h rtGetNaN.c rtGetNaN.h rtmodel.h rtwtypes.h s_typedef.h yd_typedefs.h PS64; /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Point to Signed 64Bit datatype */ typedef unsigned long long common.gpj public.c public.h rt_nonfinite.c rt_nonfinite.h rtGetInf.c rtGetInf.h rtGetNaN.c rtGetNaN.h rtmodel.h rtwtypes.h s_typedef.h yd_typedefs.h PU64; /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Point to Unsigned 64Bit datatype */ typedef unsigned char U8; /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Unsigned 8Bit datatype */ typedef unsigned short U16; /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Unsigned 16Bit datatype */ typedef unsigned int U32; /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Unsigned 32Bit datatype */ typedef signed char S8; /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Signed 8Bit datatype */ typedef signed short S16; /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Signed 16Bit datatype */ typedef signed int S32; /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Signed 32Bit datatype */ typedef unsigned char common.gpj public.c public.h rt_nonfinite.c rt_nonfinite.h rtGetInf.c rtGetInf.h rtGetNaN.c rtGetNaN.h rtmodel.h rtwtypes.h s_typedef.h yd_typedefs.h PU8; /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Point to Unsigned 8Bit datatype */ typedef unsigned short common.gpj public.c public.h rt_nonfinite.c rt_nonfinite.h rtGetInf.c rtGetInf.h rtGetNaN.c rtGetNaN.h rtmodel.h rtwtypes.h s_typedef.h yd_typedefs.h PU16; /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Point to Unsigned 16Bit datatype */ typedef unsigned int common.gpj public.c public.h rt_nonfinite.c rt_nonfinite.h rtGetInf.c rtGetInf.h rtGetNaN.c rtGetNaN.h rtmodel.h rtwtypes.h s_typedef.h yd_typedefs.h PU32; /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Point to Unsigned 32Bit datatype */ typedef signed char common.gpj public.c public.h rt_nonfinite.c rt_nonfinite.h rtGetInf.c rtGetInf.h rtGetNaN.c rtGetNaN.h rtmodel.h rtwtypes.h s_typedef.h yd_typedefs.h PS8; /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Point to Signed 8Bit datatype */ typedef signed short common.gpj public.c public.h rt_nonfinite.c rt_nonfinite.h rtGetInf.c rtGetInf.h rtGetNaN.c rtGetNaN.h rtmodel.h rtwtypes.h s_typedef.h yd_typedefs.h PS16; /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Point to Signed 16Bit datatype */ typedef signed int common.gpj public.c public.h rt_nonfinite.c rt_nonfinite.h rtGetInf.c rtGetInf.h rtGetNaN.c rtGetNaN.h rtmodel.h rtwtypes.h s_typedef.h yd_typedefs.h PS32; /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Point to Signed 32Bit datatype */ typedef unsigned char BOOL; /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr BOOL datatype */  #define NULL (0u) /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr NULL type */ #define NULL_PTR ((void *)0) /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr NULL Pointer type */ #define FALSE (0u) /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Def for FALSE */ #define TRUE (1u) /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Def for True */   /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr common define return status */ #define RET_FAIL (0u) #define RET_OK (1u) #define RET_INVALID (2u) #define RET_BUSY (3u) #define RET_IDLE (4u) #define VALID (0u) #define INVALID (1u)  #define ACTIVE 1 #define INACTIVE 0   #define LOW 0 /*低电平*/ #define HIGH 1 /*高电平*/ #define ON 1 #define OFF 0 /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr instrument define */ #define NOP() __nop() #define INT_EN() __EI() #define INT_DIS() __DI()  /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr operation define */ #define SET_BIT(word, bit) (word |= (1ul<<bit)) #define CLR_BIT(word, bit) (word &= ~(1ul<<bit)) #define GET_BIT(word, bit) ((word & (1ul<<bit)) ? 1 : 0)  #define ABS_SUB(x, y) (x>y?(x-y):(y-x)) #define ABS(x) ((x&0x80000000)?((~x)+1):x)   #define S_TO_MS(x) (x common.gpj public.c public.h rt_nonfinite.c rt_nonfinite.h rtGetInf.c rtGetInf.h rtGetNaN.c rtGetNaN.h rtmodel.h rtwtypes.h s_typedef.h yd_typedefs.h 1000) #define S_TO_HOUR(x) (x / 3600) #define MS_TO_MIN(x) (x / 60000) #define MS_TO_S(x) (x / 1000)   #endif /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr __YD_TYPEDEFS_H__ */
