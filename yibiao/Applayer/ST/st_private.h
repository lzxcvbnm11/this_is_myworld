/***************************************************************************** st.c st_cfg.h st_info.inc st_private.h st_public.h Copyright (C) 2016 ShenZhen Yeedon Media co.,LTD. All rights reserved. * st.c st_cfg.h st_info.inc st_private.h st_public.h File Name : st_private.h st.c st_cfg.h st_info.inc st_private.h st_public.h Description :the private datas of the st module. st.c st_cfg.h st_info.inc st_private.h st_public.h Author: Xueping.Chen st.c st_cfg.h st_info.inc st_private.h st_public.h Date: 2016-12-06 ******************************************************************************/  /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr check of multiple include */ #ifndef _ST_PRIVATE_H_  #define _ST_PRIVATE_H_  /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Private Macros defines */ #define TACHO_MAX_VAULE 800000 /*发动机最大转速*/ #define ANGLE_MIN 0 /*最大转角*/ #define ANGLE_MAX 270 /*最大转角*/ #define ANGLE_SPEED_RANGE 45 /*20km对应的转角*/ #define SPEED_MAX 22000000 /*最大车速(单位100m)*/ #define SPEED_DIVISION 2000000 /*刻度不同的分割点(单位100m)*/ #define DELAY_DETECT_TIME 1000 /*仪表在KL15上电后后延时的时间，此后后执行自检:ms*/ #define CHECK_TRANSIT_TIME 1620 /*1500 */ /*自检时从0刻度到最大刻度的过渡时间ms*/ #define CHECK_REMAIN_WAIT_TIME 380/*500*/ /*自检时维持在最大刻度的等待时间时间ms*/ #define METER_SPEED_RANGE_NUM 2 /*定义车速表分成的范围/*20km以上和以下*/ #define METER_PRECISION_FACTOR1 1 /*马达1精度*/ #define METER_PRECISION_FACTOR2 3 /*马达1/3精度*/ #define METER_PRECISION_FACTOR3 12 /*马达1/12精度*/ #define ST_SPEED_SCALE1_LOWER20 444 /*速度表在20km以下的灵敏度（米）（对应1马达工作模式）*/ #define ST_SPEED_SCALE2_LOWER20 148 /*速度表在20km以下的灵敏度（米）（对应1/3马达工作模式）*/ #define ST_SPEED_SCALE3_LOWER20 3703 /*速度表在20km以下的灵敏度（米）（对应1/12马达工作模式）*/ #define ST_SPEED_SCALE1_UPPER20 852 /*速度表在20km以上的灵敏度（米）（对应1马达工作模式）*/ #define ST_SPEED_SCALE2_UPPER20 284 /*速度表在20km以上的灵敏度（米）（对应1/3马达工作模式）*/ #define ST_SPEED_SCALE3_UPPER20 7407 /*速度表在20km以上的灵敏度（米）（对应1/12马达工作模式）*/ #define ST_TACHO_SCALE1 400 /*转速表的灵敏度1 (转换因子前：转速*4)（对应1马达工作模式）*/ #define ST_TACHO_SCALE2 133 /*转速表的灵敏度1 (转换因子前：转速*4)（对应1/3马达工作模式）*/ #define ST_TACHO_SCALE3 247 /*转速表的灵敏度1 (转换因子前：转速*4)（对应1/12马达工作模式）*/ #define PROCESS_SIGNAL_CNT 10//20 /*网络信号计数总数*/ #define ST_PROCESS_PERIOD 50 /*ST的周期*/ #define CHECK_DELAY_CNT (DELAY_DETECT_TIME / ST_PROCESS_PERIOD) #define CHECK_TRANSIT_CNT (CHECK_TRANSIT_TIME / ST_PROCESS_PERIOD) #define CHECK_REMAIN_WAIT_CNT (CHECK_REMAIN_WAIT_TIME / ST_PROCESS_PERIOD) #define ST_CHECKSTATUS_PERIOD 5000 #define CHECK_MAX_CNT (ST_CHECKSTATUS_PERIOD / ST_PROCESS_PERIOD)  #define OVERSPEED_NUM 12000000 /*限制车速(单位100m)*/ #define KILOMETER_TO_CMETER 100000 /*千米转换成米*/ #define CHECK_MOTOR_STEP ((ANGLE_MAX*METER_PRECISION_FACTOR3)/(CHECK_TRANSIT_TIME/ST_PROCESS_PERIOD)) #define MAX_SPEED_VALUE 220  #define TACHO_ENGINERUNNING_THREASHOLD 400 //160 /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Private data structures defines */ typedef struct STFactor_Tag { U16 maxStep;/*支持的最大步数*/ U16 Precision;/*一步对应的灵敏度*/ }STFactor_ST;  typedef struct STAngle_Tag { U16 preStep; /*上一次位置的取值范围为0~270*FACTOR,FACTOR取值12*/ U16 TgtStep; /*目标位置0~270*FACTOR,FACTOR取值为12*/ MOMWorkStatus_ENUM status;/*表的工作状态*/ U16 value; /*TgtStep对应的值*/ }STAngle_ST;  typedef enum MeterDrvnType_Tag { TYPE_ST_FULLSTEP = ( 0U ),/*全步驱动模式*/ TYPE_ST_PARTIALSTEP,/*分步驱动模式*/ TYPE_ST_MICROSTEP,/*微步驱动模式*/ TYPE_ST_STEP_ALL }MeterDrvnType_ENUM;  typedef enum MeterStatus_Tag { STATUS_ST_IDLE = ( 0U ),/*空闲状态*/ STATUS_ST_SET,/*设置状态*/ STATUS_ST_WAIT,/*马达执行中*/ STATUS_ST_DONE,/*马达执行结束*/ STATUS_ST_ALL }MeterStatus_ENUM;  const STFactor_ST st_Speed[TYPE_ST_STEP_ALL][METER_SPEED_RANGE_NUM]= { { {(ANGLE_MAX*METER_PRECISION_FACTOR3), ST_SPEED_SCALE1_LOWER20}, {(ANGLE_MAX*METER_PRECISION_FACTOR3), ST_SPEED_SCALE1_UPPER20}, }, { {(ANGLE_MAX*METER_PRECISION_FACTOR3), ST_SPEED_SCALE2_LOWER20}, {(ANGLE_MAX*METER_PRECISION_FACTOR3), ST_SPEED_SCALE2_UPPER20}, }, { {(ANGLE_MAX*METER_PRECISION_FACTOR3), ST_SPEED_SCALE3_LOWER20}, {(ANGLE_MAX*METER_PRECISION_FACTOR3), ST_SPEED_SCALE3_UPPER20}, }, };  const STFactor_ST st_Tacho[TYPE_ST_STEP_ALL]= { {(ANGLE_MAX*METER_PRECISION_FACTOR3), ST_TACHO_SCALE1}, {(ANGLE_MAX*METER_PRECISION_FACTOR3), ST_TACHO_SCALE2}, {(ANGLE_MAX*METER_PRECISION_FACTOR3), ST_TACHO_SCALE3}, };  const U8 st_meterMode = TYPE_ST_MICROSTEP;  /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Private extern functions declare */ static void st_Zero_Process(void); static void st_Normal_Process(void); static void st_Check_Process(void); static void st_SpeedProcess_100ms(void); static void st_TachoProcess_50ms(void); static void st_CalCurSpeedMotorAngle(void);  #endif /*_ST_PRIVATE_H_*/  /*----------------end of file------------------------*/  /*=========================================================================== st.c st_cfg.h st_info.inc st_private.h st_public.h File Revision History(bottom to top:first revision to last revision) *============================================================================ st.c st_cfg.h st_info.inc st_private.h st_public.h $Log:$ * st.c st_cfg.h st_info.inc st_private.h st_public.h Rev: Userid: Date: Description *-------- ---------- --------- ------------------------------ * st.c st_cfg.h st_info.inc st_private.h st_public.h V1.0 Xueping.Chen 2016-12-06 Initial * *===========================================================================*/
