/***************************************************************************** | Copyright |----------------------------------------------------------------------------- | Copyright (c) by SAIC Motor Co. LTD. All rights reserved. | | This software is furnished under a license and may be used and copied  | only in accordance with the terms of such license and with the inclusion | of the above copyright notice. This software or any other copies thereof  | may not be provided or otherwise made available to any other person. | No title to and ownership of the software is hereby transferred. | | The information in this software is subject to change without notice  | and should not be construed as a commitment by  | SAIC Motor Co. LTD. | | SAIC Motor Co. LTD. assumes no responsibility for the use or reliability | of its Software on equipment which is not supported by SAIC Motor Co. LTD. |----------------------------------------------------------------------------- ******************************************************************************/ /******************************************************************************/ /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Version 15.06.04.0.0.1 */ /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Name Date changeLog */ /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr 李秋实 2015/06/04 修改故障码信息结构体 */ /******************************************************************************/ #ifndef _S_FM_TYPEDEF_H #define _S_FM_TYPEDEF_H  typedef unsigned char s_uint8; /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Unsigned 8Bit datatype */ typedef unsigned short int s_uint16; /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Unsigned 16Bit datatype */ typedef unsigned long int s_uint32; /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Unsigned 32Bit datatype */ typedef unsigned char s_bool; /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr s_bool datatype*/   /*******************************结构体定义*************************************/  /*故障码结构体*/ volatile typedef struct { /*配置部分*/ const s_uint16 DTC; /*故障码*/ const s_uint8 f_type; /*失效类型*/ const s_uint8 lightOnType; /*亮灯策略*/ const s_uint8 lightOffType; /*灭灯策略*/ const s_uint8 cycleType; /*关联的操作循环类型*/ const s_uint8 confirmCycle; /*多少操作循环可确认故障*/ const s_uint8 Level; /*严重等级*/ const s_bool configable; /*是否可通过010X进行配置*/ const s_uint16 cfg_010X; /*配置开关的ID*/ const s_uint8 cfg_byte; /*配置开关的字节位置*/ const s_uint8 cfg_bit; /*配置开关的位位置*/ const s_uint8 Priority ; /*优先级*/ const s_uint8 DTCtype; /*故障类型*/ /*不需配置部分*/  volatile s_uint8 f_status; /*故障状态*/ volatile s_uint8 FaultOccurCounter; /*故障出现计数器*/ volatile s_uint8 FaultPendingCounter; /*故障待定计数器*/ volatile s_uint8 AgedCounter; /*已老去计数器*/ volatile s_uint8 AgeingCounter; /*老化计数器*/  volatile s_bool testfailed; /*测试失败位*/ volatile s_bool changeFlag; /*故障信息是否变化*/ volatile s_bool app_status; /*应用层的测试状态*/ volatile s_bool needToRewrite; /*是否需要重写*/ volatile s_bool testNotComplete; /*检测是否完成*/ volatile s_bool enable; /*故障是否使能*/ volatile s_bool TriggerFlag; /*trigger标志*/ volatile s_bool SetFlag; /*APP是否设置该故障状态*/ volatile s_bool Service19enable; /*是否使能，与上面的区别是这个如果禁止不能被19读出*/ }s_fm_dtc; /*快照ID信息结构体*/ const typedef struct { s_uint16 DID; s_uint8 Len;  }s_fm_DID;  /*全局快照信息结构体*/ const typedef struct { s_uint8 globalSnapLen; s_uint8 globalSnapDIDNum; s_fm_DID* DIDInfo; }s_fm_globalSnapshot; /*局部快照信息结构体*/ const typedef struct { s_uint16 DTC; s_uint8 f_type; s_uint8 localSnapLen; s_uint8 localSnapDIDNum; s_fm_DID* DIDInfo; }s_fm_localSnapshot;  /*EEPOM存储信息结构体*/ volatile typedef struct { s_uint8 RamID; s_uint8 EEPROMID;  }s_fm_StoreInfo;   #endif   /*=========================================================================== lib s_fm_api.h s_fm_app.h s_fm_callout.c s_fm_config.c s_fm_config.h s_fm_typeDef.h File Revision History (bottom to top: first revision to last revision) *============================================================================ lib s_fm_api.h s_fm_app.h s_fm_callout.c s_fm_config.c s_fm_config.h s_fm_typeDef.h $Log:$  lib s_fm_api.h s_fm_app.h s_fm_callout.c s_fm_config.c s_fm_config.h s_fm_typeDef.h Rev: Userid: Date: (Description on following lines: CR #, etc.) lib s_fm_api.h s_fm_app.h s_fm_callout.c s_fm_config.c s_fm_config.h s_fm_typeDef.h ------- ------------ ----------- * *===========================================================================*/
