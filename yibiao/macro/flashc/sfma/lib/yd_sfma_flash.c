/* **************************************************************************** PROJECT : SFMA driver FILE : $Id: yd_sfma_flash.c 3935 2014-09-23 08:52:32Z golczewskim $ ============================================================================ DESCRIPTION Driver for the SFMA(Serial Flash Memory Interface) macro ============================================================================ C O P Y R I G H T ============================================================================ Copyright (c) 2013 - 2014 by Renesas Electronics (Europe) GmbH. Arcadiastrasse 10 D-40472 Duesseldorf Germany All rights reserved. ============================================================================  DISCLAIMER  LICENSEE has read, understood and accepted the terms and conditions defined in the license agreement, especially the usage rights. In any case, it is LICENSEE's responsibility to make sure that any user of the software complies with the terms and conditions of the signed license agreement.  **************************************************************************** */  /*************************************************************************** Title: SFMA Flash Driver  SFMA Internal Interface  */  /*************************************************************************** Section: Includes */ #include "r_typedefs.h" #include "yd_sfma_api.h" #include "r_sfma_api.h" #include "yd_sfma_spibsc.h" #include "yd_sfma_flash.h"  /*************************************************************************** Section: Local Defines */ /*************************************************************************** Constants: LOC_YD_SFMA_SHIFT_BIT  This constant is the bit shift. */ #define LOC_YD_SFMA_SHIFT_BIT (1uL)  /*************************************************************************** Constants: LOC_YD_SFMA_UNIT  This constant is the size to have aligned.  LOC_YD_SFMA_UNIT_8BIT - Specifies that the size to have aligned by 8 bit. LOC_YD_SFMA_UNIT_16BIT - Specifies that the size to have aligned by 16 bit. LOC_YD_SFMA_UNIT_32BIT - Specifies that the size to have aligned by 24 bit. LOC_YD_SFMA_UNIT_64BIT - Specifies that the size to have aligned by 32 bit. */ #define LOC_YD_SFMA_UNIT_8BIT (1) #define LOC_YD_SFMA_UNIT_16BIT (2) #define LOC_YD_SFMA_UNIT_32BIT (4) #define LOC_YD_SFMA_UNIT_64BIT (8)  /*************************************************************************** Constants: LOC_YD_SFMA_DUMMY_WRITE_DATA  This constant is the dummy data. */ #define LOC_YD_SFMA_DUMMY_WRITE_DATA (0xffuL)  /*************************************************************************** Section: Local functions */  /*************************************************************************** Function: loc_SFMA_8bitDataWrite  Description: This function writes 8 bit data to the serial flash memory.  Parameter: Unit - The parameter specifies the instance number. r_Spibsc - This is a pointer to the yd_sfma_SpibscSpimdReg_t structure to the register setting to transfer data. Buffer - This is a pointer to the address of buffer. Size - The parameter specifies the data size (in bytes) to read.  Return value: See <yd_sfma_Error_t>. */ static yd_sfma_Error_t YD_SFMA_8bitDataWrite(const uint32_t Unit, yd_sfma_SpibscSpimdReg_t *SpibscReg, const uint8_t *Buffer, int32_t Size);  static yd_sfma_Error_t YD_SFMA_8bitDataWrite(const uint32_t Unit, yd_sfma_SpibscSpimdReg_t *SpibscReg, const uint8_t *Buffer, int32_t Size) { yd_sfma_Error_t ret = YD_SFMA_ERR_OK; uint32_t tmp32; uint32_t buf_point;  if ((Buffer == R_NULL) || (SpibscReg == R_NULL)) { ret = YD_SFMA_ERR_PARAM_INCORRECT; } else { buf_point = 0; while (Size > 0L) { tmp32 = *(Buffer + buf_point); tmp32 = (tmp32 << YD_SFMA_SHIFT_3BYTE); SpibscReg->Smwdr[YD_SFMA_SMWDR_DATA_0] = tmp32;  buf_point++; Size -= LOC_YD_SFMA_UNIT_8BIT; if (Size <= 0) { SpibscReg->Sslkp = YD_SFMA_SPIBSC_SPISSL_NEGATE; }  ret = YD_SFMA_SpibscWriteTransfer(Unit, SpibscReg); if (ret != YD_SFMA_ERR_OK) { break; } } }  return ret; }  /*************************************************************************** Function: loc_SFMA_16bitDataWrite  Description: This function writes 16 bit data to the serial flash memory.  Parameter: Unit - The parameter specifies the instance number. r_Spibsc - This is a pointer to the yd_sfma_SpibscSpimdReg_t structure to the register setting to transfer data. Buffer - This is a pointer to the address of buffer. Size - The parameter specifies the data size (in bytes) to read.  Return value: See <yd_sfma_Error_t>. */ static yd_sfma_Error_t YD_SFMA_16bitDataWrite(const uint32_t Unit, yd_sfma_SpibscSpimdReg_t *SpibscReg, const uint8_t *Buffer, int32_t Size);  static yd_sfma_Error_t YD_SFMA_16bitDataWrite(const uint32_t Unit, yd_sfma_SpibscSpimdReg_t *SpibscReg, const uint8_t *Buffer, int32_t Size) { yd_sfma_Error_t ret = YD_SFMA_ERR_OK; uint32_t tmp32; uint32_t buf_point;  if ((Buffer == R_NULL) || (SpibscReg == R_NULL)) { ret = YD_SFMA_ERR_PARAM_INCORRECT; } else { buf_point = 0; while (Size > 0L) { SpibscReg->Smwdr[YD_SFMA_SMWDR_DATA_0] = *(Buffer + buf_point); if (Size >= LOC_YD_SFMA_UNIT_16BIT) { buf_point++; tmp32 = *(Buffer + buf_point); buf_point++; tmp32 = (tmp32 << YD_SFMA_SHIFT_BYTE); SpibscReg->Smwdr[YD_SFMA_SMWDR_DATA_0] |= tmp32; } else { SpibscReg->Smwdr[YD_SFMA_SMWDR_DATA_0] |= (LOC_YD_SFMA_DUMMY_WRITE_DATA << YD_SFMA_SHIFT_BYTE); } SpibscReg->Smwdr[YD_SFMA_SMWDR_DATA_0] = (SpibscReg->Smwdr[YD_SFMA_SMWDR_DATA_0] << YD_SFMA_SHIFT_2BYTE);  Size -= LOC_YD_SFMA_UNIT_16BIT; if (Size <= 0) { SpibscReg->Sslkp = YD_SFMA_SPIBSC_SPISSL_NEGATE; }  ret = YD_SFMA_SpibscWriteTransfer(Unit, SpibscReg); if (ret != YD_SFMA_ERR_OK) { break; } } }  return ret; }  /*************************************************************************** Function: loc_SFMA_32bitDataWrite  Description: This function writes 32 bit data to the serial flash memory.  Parameter: Unit - The parameter specifies the instance number. r_Spibsc - This is a pointer to the yd_sfma_SpibscSpimdReg_t structure to the register setting to transfer data. Buffer - This is a pointer to the address of buffer. Size - The parameter specifies the data size (in bytes) to read.  Return value: See <yd_sfma_Error_t>. */ static yd_sfma_Error_t YD_SFMA_32bitDataWrite(const uint32_t Unit, yd_sfma_SpibscSpimdReg_t *SpibscReg, const uint8_t *Buffer, int32_t Size);  static yd_sfma_Error_t YD_SFMA_32bitDataWrite(const uint32_t Unit, yd_sfma_SpibscSpimdReg_t *SpibscReg, const uint8_t *Buffer, int32_t Size) { yd_sfma_Error_t ret = YD_SFMA_ERR_OK; uint32_t tmp32; uint32_t buf_point;  if ((Buffer == R_NULL) || (SpibscReg == R_NULL)) { ret = YD_SFMA_ERR_PARAM_INCORRECT; } else { buf_point = 0; while (Size > 0L) { SpibscReg->Smwdr[YD_SFMA_SMWDR_DATA_0] = *(Buffer + buf_point); buf_point++; tmp32 = *(Buffer + buf_point); buf_point++; tmp32 = (tmp32 << YD_SFMA_SHIFT_BYTE); SpibscReg->Smwdr[YD_SFMA_SMWDR_DATA_0] |= tmp32; tmp32 = *(Buffer + buf_point); buf_point++; tmp32 = (tmp32 << YD_SFMA_SHIFT_2BYTE); SpibscReg->Smwdr[YD_SFMA_SMWDR_DATA_0] |= tmp32; tmp32 = *(Buffer + buf_point); buf_point++; tmp32 = (tmp32 << YD_SFMA_SHIFT_3BYTE); SpibscReg->Smwdr[YD_SFMA_SMWDR_DATA_0] |= tmp32;  Size -= LOC_YD_SFMA_UNIT_32BIT; if (Size <= 0) { SpibscReg->Sslkp = YD_SFMA_SPIBSC_SPISSL_NEGATE; }  ret = YD_SFMA_SpibscWriteTransfer(Unit, SpibscReg); if (ret != YD_SFMA_ERR_OK) { break; } } }  return ret; }  /*************************************************************************** Function: loc_SFMA_64bitDataWrite  Description: This function writes 64 bit data to the serial flash memory.  Parameter: Unit - The parameter specifies the instance number. r_Spibsc - This is a pointer to the yd_sfma_SpibscSpimdReg_t structure to the register setting to transfer data. Buffer - This is a pointer to the address of buffer. Size - The parameter specifies the data size (in bytes) to read.  Return value: See <yd_sfma_Error_t>. */ static yd_sfma_Error_t YD_SFMA_64bitDataWrite(const uint32_t Unit, yd_sfma_SpibscSpimdReg_t *SpibscReg, const uint8_t *Buffer, int32_t Size);  static yd_sfma_Error_t YD_SFMA_64bitDataWrite(const uint32_t Unit, yd_sfma_SpibscSpimdReg_t *SpibscReg, const uint8_t *Buffer, int32_t Size) { yd_sfma_Error_t ret = YD_SFMA_ERR_OK; uint32_t tmp32; uint32_t buf_point;  if ((Buffer == R_NULL) || (SpibscReg == R_NULL)) { ret = YD_SFMA_ERR_PARAM_INCORRECT; } else { buf_point = 0; while (Size > 0L) { SpibscReg->Smwdr[YD_SFMA_SMWDR_DATA_1] = *(Buffer + buf_point); buf_point++; tmp32 = *(Buffer + buf_point); buf_point++; tmp32 = (tmp32 << YD_SFMA_SHIFT_BYTE); SpibscReg->Smwdr[YD_SFMA_SMWDR_DATA_1] |= tmp32; tmp32 = *(Buffer + buf_point); buf_point++; tmp32 = (tmp32 << YD_SFMA_SHIFT_2BYTE); SpibscReg->Smwdr[YD_SFMA_SMWDR_DATA_1] |= tmp32; tmp32 = *(Buffer + buf_point); buf_point++; tmp32 = (tmp32 << YD_SFMA_SHIFT_3BYTE); SpibscReg->Smwdr[YD_SFMA_SMWDR_DATA_1] |= tmp32;  SpibscReg->Smwdr[YD_SFMA_SMWDR_DATA_0] = *(Buffer + buf_point); buf_point++; tmp32 = *(Buffer + buf_point); buf_point++; tmp32 = (tmp32 << YD_SFMA_SHIFT_BYTE); SpibscReg->Smwdr[YD_SFMA_SMWDR_DATA_0] |= tmp32; tmp32 = *(Buffer + buf_point); buf_point++; tmp32 = (tmp32 << YD_SFMA_SHIFT_2BYTE); SpibscReg->Smwdr[YD_SFMA_SMWDR_DATA_0] |= tmp32; tmp32 = *(Buffer + buf_point); buf_point++; tmp32 = (tmp32 << YD_SFMA_SHIFT_3BYTE); SpibscReg->Smwdr[YD_SFMA_SMWDR_DATA_0] |= tmp32;  Size -= LOC_YD_SFMA_UNIT_64BIT; if (Size <= 0) { SpibscReg->Sslkp = YD_SFMA_SPIBSC_SPISSL_NEGATE; }  ret = YD_SFMA_SpibscWriteTransfer(Unit, SpibscReg); if (ret != YD_SFMA_ERR_OK) { break; } } }  return ret; }  /*************************************************************************** Function: loc_SFMA_8bitDataRead  Description: This function reads 8 bit data from the serial flash memory.  Parameter: Unit - The parameter specifies the instance number. r_Spibsc - This is a pointer to the yd_sfma_SpibscSpimdReg_t structure to the register setting to transfer data. Buffer - This is a pointer to the address of buffer. Size - The parameter specifies the data size (in bytes) to read.  Return value: See <yd_sfma_Error_t>. */ static yd_sfma_Error_t YD_SFMA_8bitDataRead(const uint32_t Unit, yd_sfma_SpibscSpimdReg_t *SpibscReg, uint8_t *Buffer, int32_t Size);  static yd_sfma_Error_t YD_SFMA_8bitDataRead(const uint32_t Unit, yd_sfma_SpibscSpimdReg_t *SpibscReg, uint8_t *Buffer, int32_t Size) { yd_sfma_Error_t ret = YD_SFMA_ERR_OK; uint32_t buf_point;  if ((Buffer == R_NULL) || (SpibscReg == R_NULL)) { ret = YD_SFMA_ERR_PARAM_INCORRECT; } else { buf_point = 0; while (Size > 0L) { if ((Size - LOC_YD_SFMA_UNIT_8BIT) <= 0) { SpibscReg->Sslkp = YD_SFMA_SPIBSC_SPISSL_NEGATE; }  ret = YD_SFMA_SpibscReadTransfer(Unit, SpibscReg); if (ret == YD_SFMA_ERR_OK) { *(Buffer + buf_point) = (uint8_t)(SpibscReg->Smrdr[YD_SFMA_SMRDR_DATA_0] >> YD_SFMA_SHIFT_3BYTE); buf_point++; Size -= LOC_YD_SFMA_UNIT_8BIT; } else { break; } } }  return ret; }  /*************************************************************************** Function: loc_SFMA_16bitDataRead  Description: This function reads 16 bit data from the serial flash memory.  Parameter: Unit - The parameter specifies the instance number. r_Spibsc - This is a pointer to the yd_sfma_SpibscSpimdReg_t structure to the register setting to transfer data. Buffer - This is a pointer to the address of buffer. Size - The parameter specifies the data size (in bytes) to read.  Return value: See <yd_sfma_Error_t>. */ static yd_sfma_Error_t YD_SFMA_16bitDataRead(const uint32_t Unit, yd_sfma_SpibscSpimdReg_t *SpibscReg, uint8_t *Buffer, int32_t Size);   static yd_sfma_Error_t YD_SFMA_16bitDataRead(const uint32_t Unit, yd_sfma_SpibscSpimdReg_t *SpibscReg, uint8_t *Buffer, int32_t Size) { yd_sfma_Error_t ret = YD_SFMA_ERR_OK; uint32_t buf_point;  if ((Buffer == R_NULL) || (SpibscReg == R_NULL)) { ret = YD_SFMA_ERR_PARAM_INCORRECT; } else { buf_point = 0; while (Size > 0L) { if ((Size - LOC_YD_SFMA_UNIT_16BIT) <= 0) { SpibscReg->Sslkp = YD_SFMA_SPIBSC_SPISSL_NEGATE; }  ret = YD_SFMA_SpibscReadTransfer(Unit, SpibscReg); if (ret == YD_SFMA_ERR_OK) { *(Buffer + buf_point) = (uint8_t)(SpibscReg->Smrdr[YD_SFMA_SMRDR_DATA_0] >> YD_SFMA_SHIFT_2BYTE); if (Size >= LOC_YD_SFMA_UNIT_16BIT) { buf_point++; *(Buffer + buf_point) = (uint8_t)(SpibscReg->Smrdr[YD_SFMA_SMRDR_DATA_0] >> YD_SFMA_SHIFT_3BYTE); buf_point++; } Size -= LOC_YD_SFMA_UNIT_16BIT; } else { break; } } }  return ret; }  /*************************************************************************** Function: loc_SFMA_32bitDataRead  Description: This function reads 32 bit data from the serial flash memory.  Parameter: Unit - The parameter specifies the instance number. r_Spibsc - This is a pointer to the yd_sfma_SpibscSpimdReg_t structure to the register setting to transfer data. Buffer - This is a pointer to the address of buffer. Size - The parameter specifies the data size (in bytes) to read.  Return value: See <yd_sfma_Error_t>. */ static yd_sfma_Error_t YD_SFMA_32bitDataRead(const uint32_t Unit, yd_sfma_SpibscSpimdReg_t *SpibscReg, uint8_t *Buffer, int32_t Size);  static yd_sfma_Error_t YD_SFMA_32bitDataRead(const uint32_t Unit, yd_sfma_SpibscSpimdReg_t *SpibscReg, uint8_t *Buffer, int32_t Size) { yd_sfma_Error_t ret = YD_SFMA_ERR_OK; uint32_t buf_point;  if ((Buffer == R_NULL) || (SpibscReg == R_NULL)) { ret = YD_SFMA_ERR_PARAM_INCORRECT; } else { buf_point = 0; while (Size > 0L) { if ((Size - LOC_YD_SFMA_UNIT_32BIT) <= 0) { SpibscReg->Sslkp = YD_SFMA_SPIBSC_SPISSL_NEGATE; }  ret = YD_SFMA_SpibscReadTransfer(Unit, SpibscReg); if (ret == YD_SFMA_ERR_OK) { *(Buffer + buf_point) = (uint8_t)SpibscReg->Smrdr[YD_SFMA_SMRDR_DATA_0]; buf_point++; *(Buffer + buf_point) = (uint8_t)(SpibscReg->Smrdr[YD_SFMA_SMRDR_DATA_0] >> YD_SFMA_SHIFT_BYTE); buf_point++; *(Buffer + buf_point) = (uint8_t)(SpibscReg->Smrdr[YD_SFMA_SMRDR_DATA_0] >> YD_SFMA_SHIFT_2BYTE); buf_point++; *(Buffer + buf_point) = (uint8_t)(SpibscReg->Smrdr[YD_SFMA_SMRDR_DATA_0] >> YD_SFMA_SHIFT_3BYTE); buf_point++;  Size -= LOC_YD_SFMA_UNIT_32BIT; } else { break; } } }  return ret; }  /*************************************************************************** Function: loc_SFMA_64bitDataRead  Description: This function reads 64 bit data from the serial flash memory.  Parameter: Unit - The parameter specifies the instance number. r_Spibsc - This is a pointer to the yd_sfma_SpibscSpimdReg_t structure to the register setting to transfer data. Buffer - This is a pointer to the address of buffer. Size - The parameter specifies the data size (in bytes) to read.  Return value: See <yd_sfma_Error_t>. */ static yd_sfma_Error_t YD_SFMA_64bitDataRead(const uint32_t Unit, yd_sfma_SpibscSpimdReg_t *SpibscReg, uint8_t *Buffer, int32_t Size);  static yd_sfma_Error_t YD_SFMA_64bitDataRead(const uint32_t Unit, yd_sfma_SpibscSpimdReg_t *SpibscReg, uint8_t *Buffer, int32_t Size) { yd_sfma_Error_t ret = YD_SFMA_ERR_OK; uint32_t buf_point;  if ((Buffer == R_NULL) || (SpibscReg == R_NULL)) { ret = YD_SFMA_ERR_PARAM_INCORRECT; } else { buf_point = 0; while (Size > 0L) { if ((Size - LOC_YD_SFMA_UNIT_64BIT) <= 0) { SpibscReg->Sslkp = YD_SFMA_SPIBSC_SPISSL_NEGATE; }  ret = YD_SFMA_SpibscReadTransfer(Unit, SpibscReg); if (ret == YD_SFMA_ERR_OK) { *(Buffer + buf_point) = (uint8_t)SpibscReg->Smrdr[YD_SFMA_SMRDR_DATA_1]; buf_point++; *(Buffer + buf_point) = (uint8_t)(SpibscReg->Smrdr[YD_SFMA_SMRDR_DATA_1] >> YD_SFMA_SHIFT_BYTE); buf_point++; *(Buffer + buf_point) = (uint8_t)(SpibscReg->Smrdr[YD_SFMA_SMRDR_DATA_1] >> YD_SFMA_SHIFT_2BYTE); buf_point++; *(Buffer + buf_point) = (uint8_t)(SpibscReg->Smrdr[YD_SFMA_SMRDR_DATA_1] >> YD_SFMA_SHIFT_3BYTE); buf_point++;  *(Buffer + buf_point) = (uint8_t)SpibscReg->Smrdr[YD_SFMA_SMRDR_DATA_0]; buf_point++; *(Buffer + buf_point) = (uint8_t)(SpibscReg->Smrdr[YD_SFMA_SMRDR_DATA_0] >> YD_SFMA_SHIFT_BYTE); buf_point++; *(Buffer + buf_point) = (uint8_t)(SpibscReg->Smrdr[YD_SFMA_SMRDR_DATA_0] >> YD_SFMA_SHIFT_2BYTE); buf_point++; *(Buffer + buf_point) = (uint8_t)(SpibscReg->Smrdr[YD_SFMA_SMRDR_DATA_0] >> YD_SFMA_SHIFT_3BYTE); buf_point++;  Size -= LOC_YD_SFMA_UNIT_64BIT; } else { break; } } }  return ret; }  /*************************************************************************** Function: loc_SFMA_DataWriteSelect  Description: This function selects an appropriate writing function in the data size.  Parameter: Unit - The parameter specifies the instance number. r_Spibsc - This is a pointer to the yd_sfma_SpibscSpimdReg_t structure to the register setting to transfer data. Buffer - This is a pointer to the address of buffer. Size - The parameter specifies the data size (in bytes) to read. Config - This is a pointer to the yd_sfma_SpiConfig_t structure to the configuration of the unit.  Return value: See <yd_sfma_Error_t>. */ static yd_sfma_Error_t YD_SFMA_DataWriteSelect(const uint32_t Unit, yd_sfma_SpibscSpimdReg_t *SpibscReg, const uint8_t r_sfma_api.c r_sfma_api.h r_sfma_driver_api.h r_sfma_flash.c r_sfma_flash.h r_sfma_iodevice_api.h r_sfma_spibsc.c r_sfma_spibsc.h r_sfma_spibsc_drv.c r_sfma_sys.h sfma_params.h yd_config_sfma.h yd_dev_api.h yd_dev_asm.s yd_sfma_api.c yd_sfma_api.h yd_sfma_flash.c yd_sfma_flash.h yd_sfma_spibsc.c yd_sfma_spibsc.h yd_sfma_spibsc_drv.c yd_sfma_sys.h yd_sys_sfma.c const Buf, const int32_t Size, const yd_sfma_SpiConfig_t *Config);  static yd_sfma_Error_t YD_SFMA_DataWriteSelect(const uint32_t Unit, yd_sfma_SpibscSpimdReg_t *SpibscReg, const uint8_t r_sfma_api.c r_sfma_api.h r_sfma_driver_api.h r_sfma_flash.c r_sfma_flash.h r_sfma_iodevice_api.h r_sfma_spibsc.c r_sfma_spibsc.h r_sfma_spibsc_drv.c r_sfma_sys.h sfma_params.h yd_config_sfma.h yd_dev_api.h yd_dev_asm.s yd_sfma_api.c yd_sfma_api.h yd_sfma_flash.c yd_sfma_flash.h yd_sfma_spibsc.c yd_sfma_spibsc.h yd_sfma_spibsc_drv.c yd_sfma_sys.h yd_sys_sfma.c const Buf, const int32_t Size, const yd_sfma_SpiConfig_t *Config) { yd_sfma_Error_t ret;  if ((Config == R_NULL) || (SpibscReg == R_NULL)) { ret = YD_SFMA_ERR_PARAM_INCORRECT; } else { /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr ---- Data ---- */ SpibscReg->Spidb = Config->DataWidth;  if (Config->MemoryNum == YD_SFMA_SPIBSC_CMNCR_BSZ_DUAL) { if ((Size % LOC_YD_SFMA_UNIT_64BIT) == 0) { SpibscReg->Spide = YD_SFMA_SPIBSC_OUTPUT_SPID_32; /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Enable(64bit) */ ret = YD_SFMA_64bitDataWrite(Unit, SpibscReg, Buf, Size); } else if ((Size % LOC_YD_SFMA_UNIT_32BIT) == 0) { SpibscReg->Spide = YD_SFMA_SPIBSC_OUTPUT_SPID_16; /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Enable(32bit) */ ret = YD_SFMA_32bitDataWrite(Unit, SpibscReg, Buf, Size); } else { SpibscReg->Spide = YD_SFMA_SPIBSC_OUTPUT_SPID_8; /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Enable(16bit) */ ret = YD_SFMA_16bitDataWrite(Unit, SpibscReg, Buf, Size); } } else { if ((Size % LOC_YD_SFMA_UNIT_32BIT) == 0) { SpibscReg->Spide = YD_SFMA_SPIBSC_OUTPUT_SPID_32; /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Enable(32bit) */ ret = YD_SFMA_32bitDataWrite(Unit, SpibscReg, Buf, Size); } else if ((Size % LOC_YD_SFMA_UNIT_16BIT) == 0) { SpibscReg->Spide = YD_SFMA_SPIBSC_OUTPUT_SPID_16; /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Enable(16bit) */ ret = YD_SFMA_16bitDataWrite(Unit, SpibscReg, Buf, Size); } else { SpibscReg->Spide = YD_SFMA_SPIBSC_OUTPUT_SPID_8; /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Enable(8bit) */ ret = YD_SFMA_8bitDataWrite(Unit, SpibscReg, Buf, Size); } }  if (ret == YD_SFMA_ERR_OK) { ret = YD_SFMA_SpibscBusyWait(Unit, Config); } }  return ret; }  /*************************************************************************** Function: loc_SFMA_DataReadSelect  Description: This function selects an appropriate reading function in the data size.  Parameter: Unit - The parameter specifies the instance number. r_Spibsc - This is a pointer to the yd_sfma_SpibscSpimdReg_t structure to the register setting to transfer data. Buffer - This is a pointer to the address of buffer. Size - The parameter specifies the data size (in bytes) to read. Config - This is a pointer to the yd_sfma_SpiConfig_t structure to the configuration of the unit.  Return value: See <yd_sfma_Error_t>. */ static yd_sfma_Error_t YD_SFMA_DataReadSelect(const uint32_t Unit, yd_sfma_SpibscSpimdReg_t *SpibscReg, uint8_t r_sfma_api.c r_sfma_api.h r_sfma_driver_api.h r_sfma_flash.c r_sfma_flash.h r_sfma_iodevice_api.h r_sfma_spibsc.c r_sfma_spibsc.h r_sfma_spibsc_drv.c r_sfma_sys.h sfma_params.h yd_config_sfma.h yd_dev_api.h yd_dev_asm.s yd_sfma_api.c yd_sfma_api.h yd_sfma_flash.c yd_sfma_flash.h yd_sfma_spibsc.c yd_sfma_spibsc.h yd_sfma_spibsc_drv.c yd_sfma_sys.h yd_sys_sfma.c const Buf, const int32_t Size, const yd_sfma_SpiConfig_t *Config);  static yd_sfma_Error_t YD_SFMA_DataReadSelect(const uint32_t Unit, yd_sfma_SpibscSpimdReg_t *SpibscReg, uint8_t r_sfma_api.c r_sfma_api.h r_sfma_driver_api.h r_sfma_flash.c r_sfma_flash.h r_sfma_iodevice_api.h r_sfma_spibsc.c r_sfma_spibsc.h r_sfma_spibsc_drv.c r_sfma_sys.h sfma_params.h yd_config_sfma.h yd_dev_api.h yd_dev_asm.s yd_sfma_api.c yd_sfma_api.h yd_sfma_flash.c yd_sfma_flash.h yd_sfma_spibsc.c yd_sfma_spibsc.h yd_sfma_spibsc_drv.c yd_sfma_sys.h yd_sys_sfma.c const Buf, const int32_t Size, const yd_sfma_SpiConfig_t *Config) { yd_sfma_Error_t ret;  if ((Config == R_NULL) || (SpibscReg == R_NULL)) { ret = YD_SFMA_ERR_PARAM_INCORRECT; } else { /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr ---- Data ---- */ SpibscReg->Spidb = Config->DataWidth;  if (Config->MemoryNum == YD_SFMA_SPIBSC_CMNCR_BSZ_DUAL) { if ((Size % LOC_YD_SFMA_UNIT_64BIT) == 0) { SpibscReg->Spide = YD_SFMA_SPIBSC_OUTPUT_SPID_32; /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Enable(64bit) */ ret = YD_SFMA_64bitDataRead(Unit, SpibscReg, Buf, Size); } else if ((Size % LOC_YD_SFMA_UNIT_32BIT) == 0) { SpibscReg->Spide = YD_SFMA_SPIBSC_OUTPUT_SPID_16; /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Enable(32bit) */ ret = YD_SFMA_32bitDataRead(Unit, SpibscReg, Buf, Size); } else { SpibscReg->Spide = YD_SFMA_SPIBSC_OUTPUT_SPID_8; /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Enable(16bit) */ ret = YD_SFMA_16bitDataRead(Unit, SpibscReg, Buf, Size); } } else { if ((Size % LOC_YD_SFMA_UNIT_32BIT) == 0) { SpibscReg->Spide = YD_SFMA_SPIBSC_OUTPUT_SPID_32; /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Enable(32bit) */ ret = YD_SFMA_32bitDataRead(Unit, SpibscReg, Buf, Size); } else if ((Size % LOC_YD_SFMA_UNIT_16BIT) == 0) { SpibscReg->Spide = YD_SFMA_SPIBSC_OUTPUT_SPID_16; /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Enable(16bit) */ ret = YD_SFMA_16bitDataRead(Unit, SpibscReg, Buf, Size); } else { SpibscReg->Spide = YD_SFMA_SPIBSC_OUTPUT_SPID_8; /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Enable(8bit) */ ret = YD_SFMA_8bitDataRead(Unit, SpibscReg, Buf, Size); } } }  return ret; }  /*************************************************************************** Function: loc_SFMA_CheckProtectMode  Description: This function checks the protection mode of the connected the serial flash.  Parameter: Unit - The parameter specifies the instance number. Config - This is a pointer to the yd_sfma_SpiConfig_t structure to the configuration of the unit.  Return value: See <yd_sfma_Error_t>. */ static yd_sfma_Error_t YD_SFMA_CheckProtectMode(const uint32_t Unit, const yd_sfma_SpiConfig_t *Config);  static yd_sfma_Error_t YD_SFMA_CheckProtectMode(const uint32_t Unit, const yd_sfma_SpiConfig_t *Config) { uint8_t status1 = 0; uint8_t status2 = 0; yd_sfma_Error_t ret;  if (Config == R_NULL) { ret = YD_SFMA_ERR_PARAM_INCORRECT; } else { if (Config->Command.BlockProtect.Reg == YD_SFMA_STATUS_REG) { ret = YD_SFMA_SpibscReadStatusRegister(Unit, &status1, &status2, Config); } else if (Config->Command.BlockProtect.Reg == YD_SFMA_CONFIG_REG) { ret = YD_SFMA_SpibscReadConfigRegister(Unit, &status1, &status2, Config); } else { ret = YD_SFMA_ERR_PARAM_INCORRECT; }  if (ret == YD_SFMA_ERR_OK) { if ((status1 & Config->Command.BlockProtect.BitPosition) != 0) { ret = YD_SFMA_ERR_SFLASH_PROTECTED; } } }  return ret; }  /*************************************************************************** Section: Global Functions */  /*************************************************************************** Function: YD_SFMA_FlashSectorErase  see: <yd_sfma_flash.h> */ yd_sfma_Error_t YD_SFMA_FlashSectorErase(const uint32_t Unit, const uint64_t Addr, const yd_sfma_SpiConfig_t *Config) { yd_sfma_SpibscSpimdReg_t spibsc_reg; yd_sfma_Error_t ret;  if (Config == R_NULL) { ret = YD_SFMA_ERR_PARAM_INCORRECT; } else { /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr check the protect status */ ret = YD_SFMA_CheckProtectMode(Unit, Config); if (ret == YD_SFMA_ERR_OK) { /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr sector erase in Single-SPI */ ret = YD_SFMA_SpibscWriteEnableRegister(Unit, Config); if (ret == YD_SFMA_ERR_OK) { ret = YD_SFMA_SpibscRegsetInit(&spibsc_reg); if (ret == YD_SFMA_ERR_OK) { /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr command */ spibsc_reg.Cmd = Config->Command.Erase; /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr address set */ spibsc_reg.Ade = Config->AddressMode; spibsc_reg.Adb = YD_SFMA_SPIBSC_1BIT; if (Config->MemoryNum == YD_SFMA_SPIBSC_CMNCR_BSZ_DUAL) { spibsc_reg.Addr = (uint32_t)(Addr >> LOC_YD_SFMA_SHIFT_BIT); } else { spibsc_reg.Addr = (uint32_t)Addr; }  ret = YD_SFMA_SpibscCommandTransfer(Unit, &spibsc_reg); if (ret == YD_SFMA_ERR_OK) { ret = YD_SFMA_SpibscBusyWait(Unit, Config); } } } } }  return ret; }   /*************************************************************************** Function: YD_SFMA_FlashBulkErase  see: <yd_sfma_flash.h> */ yd_sfma_Error_t YD_SFMA_FlashBulkErase(const uint32_t Unit, const yd_sfma_SpiConfig_t *Config) { yd_sfma_SpibscSpimdReg_t spibsc_reg; yd_sfma_Error_t ret;  if (Config == R_NULL) { ret = YD_SFMA_ERR_PARAM_INCORRECT; } else { /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr check the protect status */ ret = YD_SFMA_CheckProtectMode(Unit, Config); if (ret == YD_SFMA_ERR_OK) { /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr sector erase in Single-SPI */ ret = YD_SFMA_SpibscWriteEnableRegister(Unit, Config); if (ret == YD_SFMA_ERR_OK) { ret = YD_SFMA_SpibscRegsetInit(&spibsc_reg); if (ret == YD_SFMA_ERR_OK) { /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr command */ spibsc_reg.Cmd = Config->Command.BulkErase;  ret = YD_SFMA_SpibscCommandTransfer(Unit, &spibsc_reg); if (ret == YD_SFMA_ERR_OK) { ret = YD_SFMA_SpibscBusyWait(Unit, Config); } } } } }  return ret; }  /*************************************************************************** Function: YD_SFMA_FlashDataWrite  see: <yd_sfma_flash.h> */ yd_sfma_Error_t YD_SFMA_FlashDataWrite(const uint32_t Unit, const uint64_t Addr, const uint8_t r_sfma_api.c r_sfma_api.h r_sfma_driver_api.h r_sfma_flash.c r_sfma_flash.h r_sfma_iodevice_api.h r_sfma_spibsc.c r_sfma_spibsc.h r_sfma_spibsc_drv.c r_sfma_sys.h sfma_params.h yd_config_sfma.h yd_dev_api.h yd_dev_asm.s yd_sfma_api.c yd_sfma_api.h yd_sfma_flash.c yd_sfma_flash.h yd_sfma_spibsc.c yd_sfma_spibsc.h yd_sfma_spibsc_drv.c yd_sfma_sys.h yd_sys_sfma.c const Buf, const int32_t Size, const yd_sfma_SpiConfig_t *Config) { yd_sfma_SpibscSpimdReg_t spibsc_reg; yd_sfma_Error_t ret;  if ((Buf == R_NULL) || (Config == R_NULL)) { ret = YD_SFMA_ERR_PARAM_INCORRECT; } else { /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr check the protect status */ ret = YD_SFMA_CheckProtectMode(Unit, Config); if (ret == YD_SFMA_ERR_OK) { ret = YD_SFMA_SpibscWriteEnableRegister(Unit, Config); if (ret == YD_SFMA_ERR_OK) { ret = YD_SFMA_SpibscRegsetInit(&spibsc_reg); if (ret == YD_SFMA_ERR_OK) { /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr command */ if (Config->DataWidth == YD_SFMA_SPIBSC_4BIT) { /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr PP: Quad Program */ if (Config->TransferMode == YD_SFMA_SPIBSC_SDR_TRANS) { spibsc_reg.Cmd = Config->Command.WriteSdrQuad; } else { spibsc_reg.Cmd = Config->Command.WriteDdrQuad; } } else if (Config->DataWidth == YD_SFMA_SPIBSC_2BIT) { if (Config->TransferMode == YD_SFMA_SPIBSC_SDR_TRANS) { /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr PP: Page Program */ spibsc_reg.Cmd = Config->Command.WriteSdrDual; } else { spibsc_reg.Cmd = Config->Command.WriteDdrDual; } } else { if (Config->TransferMode == YD_SFMA_SPIBSC_SDR_TRANS) { /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr PP: Page Program */ spibsc_reg.Cmd = Config->Command.WriteSdr; } else { spibsc_reg.Cmd = Config->Command.WriteDdr; } }  if (spibsc_reg.Cmd != YD_SFMA_NOT_SUPPORT_COMMAND) { /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr address set */ spibsc_reg.Ade = Config->AddressMode; spibsc_reg.Adb = Config->Command.WriteAddressBit; /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Keep after transfer */ spibsc_reg.Sslkp = YD_SFMA_SPIBSC_SPISSL_KEEP; if (Config->MemoryNum == YD_SFMA_SPIBSC_CMNCR_BSZ_DUAL) { spibsc_reg.Addr = (uint32_t)(Addr >> LOC_YD_SFMA_SHIFT_BIT); } else { spibsc_reg.Addr = (uint32_t)Addr; }  if (Config->TransferMode == YD_SFMA_SPIBSC_DDR_TRANS) { spibsc_reg.Addre = YD_SFMA_SPIBSC_DDR_TRANS; spibsc_reg.Opdre = YD_SFMA_SPIBSC_DDR_TRANS; spibsc_reg.Spidre = YD_SFMA_SPIBSC_DDR_TRANS; } ret = YD_SFMA_SpibscCommandTransfer(Unit, &spibsc_reg);  if (ret == YD_SFMA_ERR_OK) { ret = YD_SFMA_DataWriteSelect(Unit, &spibsc_reg, Buf, Size, Config); } } else { ret = YD_SFMA_ERR_NOT_SUPPORT_TRANSFER; } } } } }  return ret; }  /*************************************************************************** Function: YD_SFMA_FlashDataRead  see: <yd_sfma_flash.h> */ yd_sfma_Error_t YD_SFMA_FlashDataRead(const uint32_t Unit, const uint64_t Addr, uint8_t r_sfma_api.c r_sfma_api.h r_sfma_driver_api.h r_sfma_flash.c r_sfma_flash.h r_sfma_iodevice_api.h r_sfma_spibsc.c r_sfma_spibsc.h r_sfma_spibsc_drv.c r_sfma_sys.h sfma_params.h yd_config_sfma.h yd_dev_api.h yd_dev_asm.s yd_sfma_api.c yd_sfma_api.h yd_sfma_flash.c yd_sfma_flash.h yd_sfma_spibsc.c yd_sfma_spibsc.h yd_sfma_spibsc_drv.c yd_sfma_sys.h yd_sys_sfma.c const Buf, const int32_t Size, const yd_sfma_SpiConfig_t *Config) { yd_sfma_SpibscSpimdReg_t spibsc_reg; yd_sfma_Error_t ret;  if ((Buf == R_NULL) || (Config == R_NULL)) { ret = YD_SFMA_ERR_PARAM_INCORRECT; } else { ret = YD_SFMA_SpibscRegsetInit(&spibsc_reg); if (ret == YD_SFMA_ERR_OK) { /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr command */ if (Config->DataWidth == YD_SFMA_SPIBSC_1BIT) { if (Config->TransferMode == YD_SFMA_SPIBSC_SDR_TRANS) { spibsc_reg.Cmd = Config->Command.ReadSdr; } else { spibsc_reg.Cmd = Config->Command.ReadDdr; } } else if (Config->DataWidth == YD_SFMA_SPIBSC_2BIT) { if (Config->TransferMode == YD_SFMA_SPIBSC_SDR_TRANS) { spibsc_reg.Cmd = Config->Command.ReadSdrDual; } else { spibsc_reg.Cmd = Config->Command.ReadDdrDual; } } else { if (Config->TransferMode == YD_SFMA_SPIBSC_SDR_TRANS) { spibsc_reg.Cmd = Config->Command.ReadSdrQuad; } else { spibsc_reg.Cmd = Config->Command.ReadDdrQuad; } } if (spibsc_reg.Cmd != YD_SFMA_NOT_SUPPORT_COMMAND) { /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr address set */ spibsc_reg.Ade = Config->AddressMode; spibsc_reg.Adb = YD_SFMA_SPIBSC_1BIT; /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Keep after transfer */ spibsc_reg.Sslkp = YD_SFMA_SPIBSC_SPISSL_KEEP;  /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Dummy cycle insertion enable */ if (Config->Command.ReadSdrDummyCycle != YD_SFMA_DUMMY_0CYC) { spibsc_reg.Dme = YD_SFMA_SPIBSC_DUMMY_CYC_ENABLE; } spibsc_reg.Dmdb = YD_SFMA_SPIBSC_1BIT; /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Latency Code of configuration */ spibsc_reg.Dmcyc = Config->Command.ReadSdrDummyCycle; if (Config->MemoryNum == YD_SFMA_SPIBSC_CMNCR_BSZ_DUAL) { spibsc_reg.Addr = (uint32_t)(Addr >> LOC_YD_SFMA_SHIFT_BIT); } else { spibsc_reg.Addr = (uint32_t)Addr; }  if (Config->TransferMode == YD_SFMA_SPIBSC_DDR_TRANS) { spibsc_reg.Addre = YD_SFMA_SPIBSC_DDR_TRANS; spibsc_reg.Opdre = YD_SFMA_SPIBSC_DDR_TRANS; spibsc_reg.Spidre = YD_SFMA_SPIBSC_DDR_TRANS; } ret = YD_SFMA_SpibscCommandTransfer(Unit, &spibsc_reg); if (ret == YD_SFMA_ERR_OK) { ret = YD_SFMA_DataReadSelect(Unit, &spibsc_reg, Buf, Size, Config); } } else { ret = YD_SFMA_ERR_NOT_SUPPORT_TRANSFER; } } }  return ret; }  /*************************************************************************** Function: YD_SFMA_FlashProtectModeSet  see: <yd_sfma_flash.h> */ yd_sfma_Error_t YD_SFMA_FlashProtectModeSet(const uint32_t Unit, const yd_sfma_Req_t Req, const yd_sfma_SpiConfig_t *Config) { yd_sfma_Error_t ret; uint8_t st_reg1; uint8_t st_reg2; uint8_t cf_reg1; uint8_t cf_reg2;  if (Config == R_NULL) { ret = YD_SFMA_ERR_PARAM_INCORRECT; } else if ((Req != YD_SFMA_REQ_UNPROTECT) && (Req != YD_SFMA_REQ_PROTECT)) { ret = YD_SFMA_ERR_PARAM_INCORRECT; } else { ret = YD_SFMA_SpibscReadStatusRegister(Unit, &st_reg1, &st_reg2, Config); if (ret == YD_SFMA_ERR_OK) { ret = YD_SFMA_SpibscReadConfigRegister(Unit, &cf_reg1, &cf_reg2, Config); if (ret == YD_SFMA_ERR_OK) { if (Req == YD_SFMA_REQ_UNPROTECT) { /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr un-protect in all area */ if (Config->Command.BlockProtect.Reg == YD_SFMA_STATUS_REG) { st_reg1 &= (uint8_t)~Config->Command.BlockProtect.BitPosition; } else if (Config->Command.BlockProtect.Reg == YD_SFMA_CONFIG_REG) { cf_reg1 &= (uint8_t)~Config->Command.BlockProtect.BitPosition; } else { /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Do Nothing */ ; } } else { /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr un-protect in all area */ if (Config->Command.BlockProtect.Reg == YD_SFMA_STATUS_REG) { st_reg1 |= Config->Command.BlockProtect.BitPosition; } else if (Config->Command.BlockProtect.Reg == YD_SFMA_CONFIG_REG) { cf_reg1 |= Config->Command.BlockProtect.BitPosition; } else { /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Do Nothing */ ; } }  /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr ---- clear or set protect bit in status register ---- */ ret = YD_SFMA_SpibscWriteStatusRegister( Unit, st_reg1, cf_reg1, Config); } } }  return ret; }
