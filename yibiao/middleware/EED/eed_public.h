/***************************************************************************** eed.c eed_cfg.h eed_info.inc eed_private.h eed_public.h Copyright (C) 2016 ShenZhen Yeedon Media co.,LTD. All rights reserved. * eed.c eed_cfg.h eed_info.inc eed_private.h eed_public.h File Name : eed_public.h eed.c eed_cfg.h eed_info.inc eed_private.h eed_public.h Description : the public informations datas of the eed eed.c eed_cfg.h eed_info.inc eed_private.h eed_public.h Author: Xuenian.Feng eed.c eed_cfg.h eed_info.inc eed_private.h eed_public.h Date: 2016-11-29 ******************************************************************************/  /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr check of multiple include */ #ifndef _EED_PUBLIC_H_  #define _EED_PUBLIC_H_ #include "yd_typedefs.h"  #define DSPI_EED_CMD_READ (0x03) #define DSPI_EED_CMD_WRITE (0x02) #define DSPI_EED_CMD_WREN (0x06) #define DSPI_EED_CMD_WRDI (0x04) #define DSPI_EED_CMD_RDSR (0x05) #define DSPI_EED_CMD_WRSR (0x01) #define DSPI_EED_CMD_PE (0x42) #define DSPI_EED_CMD_SE (0xD8) #define DSPI_EED_CMD_CE (0xC7) #define DSPI_EED_CMD_RDID (0xAB) #define DSPI_EED_CMD_DPD (0xB9)  typedef enum EedWorkStatus_Tag { STATUS_EED_UNKNOWN = (0U), /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr EEDδ֪״̬��δ��ʼ��ʱ��Ĭ��ֵ*/ STATUS_EED_IDLE, /*EED����״̬*/ STATUS_EED_READING, /*EED��ȡ״̬*/ STATUS_EED_WRITEING, /*EEDд��״̬*/ STATUS_EED_PROTECTING, /*EEDд����״̬*/ STATUS_EED_ERR, /*EED����*/ STATUS_EED_ALL }EedWorkStatus_ENUM;  /*Public Extern Functions Declare*/ extern void EED_Init(void); extern void EED_EraseAllBlock(void); extern void EED_WriteInitData(void); extern BOOL EED_GetInitStatus(void); extern U8 EED_GetEEPROMStatus(PU8 status); extern U8 EED_WriteByte(U32 address, U8 data); extern U8 EED_WriteBytes (U32 address, const PU8 Data, U16 size); extern U8 EED_ReadByte(U32 address, PU8 Data); extern U8 EED_ReadBytes(U32 address, PU8 Data, U16 size); extern U8 EED_ReleaseProtectBlock(void);  #endif   /*------------------end of file----------------------------*/  /*=========================================================================== eed.c eed_cfg.h eed_info.inc eed_private.h eed_public.h File Revision History(bottom to top:first revision to last revision) *============================================================================ eed.c eed_cfg.h eed_info.inc eed_private.h eed_public.h $Log:$ * eed.c eed_cfg.h eed_info.inc eed_private.h eed_public.h Rev: Userid: Date: Description *-------- ---------- --------- ------------------------------ * eed.c eed_cfg.h eed_info.inc eed_private.h eed_public.h V1.0 Xuenian.Feng 2016-11-29 Initial * *===========================================================================*/
