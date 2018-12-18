/***************************************************************************** lrm.c lrm_cfg.h lrm_info.inc lrm_private.h lrm_public.h Copyright (C) 2016 ShenZhen Yeedon Media co.,LTD. All rights reserved. * lrm.c lrm_cfg.h lrm_info.inc lrm_private.h lrm_public.h File Name : lrm_public.h lrm.c lrm_cfg.h lrm_info.inc lrm_private.h lrm_public.h Description : public infomations of the LRM module. lrm.c lrm_cfg.h lrm_info.inc lrm_private.h lrm_public.h Author: Xueping.Chen lrm.c lrm_cfg.h lrm_info.inc lrm_private.h lrm_public.h Date: 2016-11-26 ******************************************************************************/  /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr check of multiple include */ #ifndef _LRM_PUBLIC_H_  #define _LRM_PUBLIC_H_  #include "lrm_private.h"  /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Public data structures defines */ typedef union LRMState_Tag  { U8 LRM_value[LRM_LAMP_ALL]; /*���������LRM�Ƶ�״̬*/ struct /*48bit,���԰�λ����*/ {  U8 LRM_TYPE_AUTOHOLD_GREEN : 1; /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr MASK Bit */ U8 LRM_TYPE_TURNLEFT : 1; /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr ��ת����� */  U8 LRM_TYPE_BRAKEERROR : 1; /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr �ƶ������ϵƺ�*/  U8 LRM_TYPE_SRS : 1; /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr ��ȫ���ҵƺ� */ U8 LRM_TYPE_ABS_ERROR : 1; /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr ABS���ϵƻ� */ U8 LRM_TYPE_SEATBELT_UNFASTEN : 1;/* ��ȫ��δϵ�ƺ�*/ U8 LRM_TYPE_TPMS_WARN : 1; /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr ̥ѹ�����ƻ�*/ U8 LRM_TYPE_SCSSTART : 1; /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr SCS�����ƻ�*/  U8 LRM_TYPE_EPB_RED : 1; /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr EPB Ԥ�� */ U8 LRM_TYPE_FUEL_WARN : 1; /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr ȼ�ͱ����ƻ� */ U8 LRM_TYPE_BEAM_LAMP : 1; /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Զ����� */ U8 LRM_TYPE_REAR_FOG : 1; /*�����ƻ�*/ U8 LRM_TYPE_EPB_OFF : 1; /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr EPB OFF�ƻ�*/ U8 LRM_TYPE_SCS_OFF : 1; /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr SCS�رյƻ�*/  U8 LRM_TYPE_CRUISE_GREEN : 1; /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Ѳ������*/  U8 LRM_TYPE_CRUISE_YELLOW : 1; /*Ѳ���ƻ� */   U8 LRM_TYPE_FUELSEGMENT8 : 1;/* ȼ��8�εư�*/ U8 LRM_TYPE_FUELSEGMENT7 : 1;/* ȼ��7�εư�*/ U8 LRM_TYPE_FUELSEGMENT6 : 1;/* ȼ��6�εư� */ U8 LRM_TYPE_FUELSEGMENT5 : 1;/* ȼ��5�εư� */ U8 LRM_TYPE_FUELSEGMENT4 : 1;/* ȼ��4�εư� */ U8 LRM_TYPE_FUELSEGMENT3 : 1;/* ȼ��3�εư� */ U8 LRM_TYPE_FUELSEGMENT2 : 1;/* ȼ��2�εư� */ U8 LRM_TYPE_FUELSEGMENT1 : 1;/* ȼ��1�εư� */  U8 LRM_TYPE_TEMPSEGMENT1 : 1;/* ˮ��1�εư� */ U8 LRM_TYPE_TEMPSEGMENT8 : 1;/* ˮ��8�εư� */ U8 LRM_TYPE_TEMPSEGMENT7 : 1;/*ˮ��7�εư� */ U8 LRM_TYPE_TEMPSEGMENT6 : 1;/* ˮ��6�εư� */ U8 LRM_TYPE_TEMPSEGMENT5 : 1;/* ˮ��5�εư� */ U8 LRM_TYPE_TEMPSEGMENT4 : 1;/* ˮ��4�εư� */ U8 LRM_TYPE_TEMPSEGMENT3 : 1;/* ˮ��3�εư� */ U8 LRM_TYPE_TEMPSEGMENT2 : 1;/* ˮ��2�εư� */  U8 LRM_TYPE_TEMP_WARN : 1; /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Reserved Bits */ U8 LRM_TYPE_SSB_ACTIVE : 1; /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr SSB������� */ U8 LRM_TYPE_SSB_ERROR : 1; /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr ��ͣ���ϵƻ�*/ U8 LRM_TYPE_ECOMODE : 1; /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr ����ģʽ���� */ U8 LRM_TYPE_SIDELIGHTS : 1; /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr λ�õ���*/ U8 LRM_TYPE_FRONG_FOG : 1; /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr ǰ������ */ U8 LRM_TYPE_HDC_GREEN : 1;/* MASK ˮ�±�������*/ U8 LRM_TYPE_HDC_YELLOW : 1;/* ˮ�±����ƺ�*/  U8 LRM_TYPE_THEFTPROOF : 1; /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr �����ƺ� */ U8 LRM_TYPE_EPS_ERROR : 1; /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr EPS���ϵƺ� */ U8 LRM_TYPE_EPS_WARN : 1; /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr EPS����ƻ� */ U8 LRM_TYPE_CHARGER : 1; /*�������ƺ� */ U8 LRM_TYPE_EMS_ERROR : 1; /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr ���������ϵƻ�*/ U8 LRM_TYPE_EMISSION_ERROR : 1; /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr �ŷŹ��ϵƻ� */ U8 LRM_TYPE_FUELPRESURE_LOW : 1;/* ����ѹ���͵ƺ� */  U8 LRM_TYPE_TURNRIGHT : 1; /*��ת����� */  }BYTES;  }LRMState_UN;   /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Public extern functions declare */ extern void LRM_Init(void); extern void LRM_Process_100ms(void); extern U8 LRM_GetInitStatus(void); extern U8 LRM_SetLampOnEnable(BOOL Enable);   #endif /*_LRM_PUBLIC_H_*/  /*----------------end of file------------------------*/   /*=========================================================================== lrm.c lrm_cfg.h lrm_info.inc lrm_private.h lrm_public.h File Revision History(bottom to top:first revision to last revision) *============================================================================ lrm.c lrm_cfg.h lrm_info.inc lrm_private.h lrm_public.h $Log:$ * lrm.c lrm_cfg.h lrm_info.inc lrm_private.h lrm_public.h Rev: Userid: Date: Description *-------- ---------- --------- ------------------------------ * lrm.c lrm_cfg.h lrm_info.inc lrm_private.h lrm_public.h V1.0 Xueping.Chen 2016-11-26 Initial * *===========================================================================*/
