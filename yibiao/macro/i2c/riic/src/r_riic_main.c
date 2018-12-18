/* **************************************************************************** PROJECT : RIIC driver FILE : $Id: r_riic_main.c 6367 2015-10-20 08:25:02Z florian.zimmermann $ ============================================================================  DESCRIPTION Driver for RIIC macro  ============================================================================ C O P Y R I G H T  ============================================================================ Copyright (c) 2014 by  Renesas Electronics (Europe) GmbH.  Arcadiastrasse 10 D-40472 Duesseldorf Germany All rights reserved. ============================================================================ Purpose: only for testing  DISCLAIMER  This software is supplied by Renesas Electronics Corporation and is only  intended for use with Renesas products. No other uses are authorized. This  software is owned by Renesas Electronics Corporation and is protected under  all applicable laws, including copyright laws.  THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING  THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT  LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE  AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.  TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS  ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE  FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR  ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE  BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.  Renesas reserves the right, without notice, to make changes to this software  and to discontinue the availability of this software. By using this software, you agree to the additional terms and conditions found by accessing the  following link:  http://www.renesas.com/disclaimer r_riic_main.c r_riic_main.h r_riic_regs.h  Copyright (C) 2011 Renesas Electronics Corporation. All rights reserved.   ****************************************************************************  **************************************************************************** */  /******************************************************************************* Title: Main Module  Implementation of the API and other global functions. */  /******************************************************************************* Section: Includes */  #include "r_typedefs.h" #include "r_cdi_api.h" #include "r_config_riic.h" #include "r_riic_regs.h" #include "r_riic_api.h" #define RIIC_MAIN_GLOBALS #include "r_riic_main.h" #include "r_riic_sys.h" #include "r_dev_api.h"  #if defined (R_DBG_PRINT_DEV_REGS) || defined (R_DBG_PRINT_MSG) #include <stdio.h>  #include "r_dbg_api.h" #endif  /******************************************************************************* Section: Local Defines */  /******************************************************************************* Section: Local Variables */  /******************************************************************************* Section: Local Functions */  /******************************************************************************* Section: Global Functions */  /******************************************************************************* Section: Global API Functions  For API documentation see riic_api.h */  /******************************************************************************* Function: R_RIIC_Init */  r_riic_Error_t R_RIIC_Init(uint32_t Unit, r_riic_Parameter_t *Config)  { uint32_t base; uint32_t clk_in; uint32_t clk_phi; uint32_t div; uint32_t value;  base = R_SYS_RIIC_BaseAddr(Unit); r_riic_Dev[Unit].BaseAddr = base;  /*Complete the intialisation in the device level */ R_SYS_RIIC_Init(Unit);  clk_in = 0; clk_in = R_SYS_RIIC_SysGetClockHz(Unit); if (clk_in == 0) { return R_RIIC_ERR_NG; }  { /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr IIC Reset */ R_RIIC_WRITE_REG(8, (base + R_RIIC_CR1), 0x1F); /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr ICE = 0 */ R_RIIC_WRITE_REG(8, (base + R_RIIC_CR1), 0x5F); /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr ICE = 0, IICRST = 1 */ R_RIIC_WRITE_REG(8, (base + R_RIIC_CR1), 0xDF); /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr ICE = 1, IICRST = 1 */  /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Slave address setup */ R_RIIC_WRITE_REG(16, (base + R_RIIC_SAR0), 0x0000); /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr 7bit address, Slave address="0000000" */ R_RIIC_WRITE_REG(8, (base + R_RIIC_SER), 0x01); /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr SAR0 = 1 */  /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Clock setup */ /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr PCLK: clk_in -> baudrate: Config.baudrate */  /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr calculate CKS to generate IIC_PHI_CLK to be IIC_PHI_CLK ~= 40..50x Baud rate (Transfer Rate) e.g. 100kHz Baudrate -> try to generate IIC_PHI_CLK of approximatly 4..5MHz  This is a approximation, not 100% accurate setup of baudrate. */  div = 0; clk_phi = clk_in / (uint32_t)(1ul << div); while(clk_phi > (Config->Baudrate r_riic_main.c r_riic_main.h r_riic_regs.h 50u))  { div += 1; clk_phi = clk_in / (uint32_t)(1ul << div); }  value = ((div<<4u) | 0x08u); /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr MR1 register; CKS (bit6-4) PCLK/(1<<div), (bit4 always "1") */ R_RIIC_WRITE_REG(8, (base + R_RIIC_MR1), value);  value = ((clk_phi / Config->Baudrate / 2u) - 1u); /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Half-Time is high-level period */ value |= 0xE0u; R_RIIC_WRITE_REG(8, (base + R_RIIC_BRH), value); value = (clk_phi / Config->Baudrate / 2u); /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Half-Time is low-level period, */ value = (((value r_riic_main.c r_riic_main.h r_riic_regs.h 1200u) / 1000u) - 1u); /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr but also it is approx. 20% longer than high-level*/ value |= 0xE0u; R_RIIC_WRITE_REG(8, (base + R_RIIC_BRL), value);  R_RIIC_WRITE_REG(8, (base + R_RIIC_CR1), 0x9Fu); /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr ICE = 1, IICRST = 0 */ }  return R_RIIC_ERR_OK; }   /******************************************************************************* Function: R_RIIC_DeInit */  r_riic_Error_t R_RIIC_DeInit(uint32_t Unit)  { /*Complete the de-intialisation in the device level */  R_SYS_RIIC_DeInit(Unit);  return R_RIIC_ERR_OK; }   /******************************************************************************* Function: R_RIIC_data_receive */ void R_RIIC_data_receive(uint32_t Unit, uint8_t* rx_buffer) { uint32_t base;  base = r_riic_Dev[Unit].BaseAddr;  while((R_RIIC_READ_REG(8, (base + R_RIIC_SR2)) & R_RIIC_SR2_RDRF) == 0u)  { } /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr receive data read */ *rx_buffer = R_RIIC_READ_REG(8, (base + R_RIIC_DRR)); }   /******************************************************************************* Function: R_RIIC_data_send */ r_riic_Error_t R_RIIC_data_send(uint32_t Unit, uint8_t* TxData)  { uint32_t base; r_riic_Error_t ack;  base = r_riic_Dev[Unit].BaseAddr;  while((R_RIIC_READ_REG(8, (base + R_RIIC_SR2)) & R_RIIC_SR2_TDRE) == 0u)  { /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Waiting TDRE empty */ }  R_RIIC_WRITE_REG(8, (base + R_RIIC_DRT), *TxData); /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr send data */  while((R_RIIC_READ_REG(8, (base + R_RIIC_SR2)) & R_RIIC_SR2_TEND) == 0u)  { /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Waiting send end */ }  if((R_RIIC_READ_REG(8, (base + R_RIIC_SR2)) & R_RIIC_SR2_NACKF) == 0u)  { ack = R_RIIC_ERR_OK; } else { ack = R_RIIC_ERR_NG; } return(ack); }   /****************************************************************************** r_riic_main.c r_riic_main.h r_riic_regs.h Function Name : R_RIIC_Master_start_condition r_riic_main.c r_riic_main.h r_riic_regs.h Description : Start condition r_riic_main.c r_riic_main.h r_riic_regs.h Arguments : none r_riic_main.c r_riic_main.h r_riic_regs.h Return Value : none ******************************************************************************/ void R_RIIC_Master_start_condition(uint32_t Unit) { uint8_t bbsy_flg; uint8_t mst_trs_flg; uint32_t base; uint32_t tmp;  base = r_riic_Dev[Unit].BaseAddr;  bbsy_flg = (R_RIIC_READ_REG(8, (base + R_RIIC_CR2)) & 0x80u);  while(bbsy_flg != 0x00) { /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Waiting BBSY = 0 */ bbsy_flg = (R_RIIC_READ_REG(8, (base + R_RIIC_CR2)) & 0x80u); }  tmp = R_RIIC_READ_REG(8, (base + R_RIIC_CR2)); R_RIIC_WRITE_REG(8, (base + R_RIIC_CR2), (tmp | 0x02u)); /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr start condition ST = 1 */   if((R_RIIC_READ_REG(8, (base + R_RIIC_SR2)) & R_RIIC_SR2_START) == 0u)  { /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Waiting start condition */ }  /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr check master send mode */ mst_trs_flg = (R_RIIC_READ_REG(8, (base + R_RIIC_CR2)) & 0x60u); while(mst_trs_flg != 0x60u) { mst_trs_flg = (R_RIIC_READ_REG(8, (base + R_RIIC_CR2)) & 0x60u); } }   /****************************************************************************** r_riic_main.c r_riic_main.h r_riic_regs.h Function Name : R_RIIC_Master_stop_condition r_riic_main.c r_riic_main.h r_riic_regs.h Description : Stop condition r_riic_main.c r_riic_main.h r_riic_regs.h Arguments : uint8_t* RxBuffer : received data r_riic_main.c r_riic_main.h r_riic_regs.h Return Value : none ******************************************************************************/ void R_RIIC_Master_stop_condition(uint32_t Unit, uint8_t* RxBuffer) { uint8_t dummy; uint32_t base;  base = r_riic_Dev[Unit].BaseAddr;  dummy = R_RIIC_READ_REG(8, (base + R_RIIC_SR2)); /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr dummy read */ dummy &= ~R_RIIC_SR2_STOP; R_RIIC_WRITE_REG(8, (base + R_RIIC_SR2), dummy); /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr STOP flg clear */  dummy = R_RIIC_READ_REG(8, (base + R_RIIC_SR2)); /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr dummy read */ dummy &= ~R_RIIC_SR2_TEND; R_RIIC_WRITE_REG(8, (base + R_RIIC_SR2), dummy); /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr TEND flg clear */  dummy = R_RIIC_READ_REG(8, (base + R_RIIC_CR2)); /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr dummy read */ dummy |= 0x08u; R_RIIC_WRITE_REG(8, (base + R_RIIC_CR2), dummy); /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr stop condition SP = 1 */  r_riic_main.c r_riic_main.h r_riic_regs.h RxBuffer = R_RIIC_READ_REG(8, (base + R_RIIC_DRR)); /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr last data read for recieve mode */  dummy = R_RIIC_READ_REG(8, (base + R_RIIC_MR3)); /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr dummy read */ dummy |= 0x10u; R_RIIC_WRITE_REG(8, (base + R_RIIC_MR3), dummy); /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr ACKWP set */  dummy = R_RIIC_READ_REG(8, (base + R_RIIC_MR3)); /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr dummy read */ dummy |= 0x18u; R_RIIC_WRITE_REG(8, (base + R_RIIC_MR3), dummy); /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr NACK set */  dummy = R_RIIC_READ_REG(8, (base + R_RIIC_MR3)); /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr dummy read */ dummy &= 0xBFu; R_RIIC_WRITE_REG(8, (base + R_RIIC_MR3), dummy); /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr WAIT clear */  while((R_RIIC_READ_REG(8, (base + R_RIIC_SR2)) & R_RIIC_SR2_STOP) == 0u)  { /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Waiting Stop condition */ }  dummy = R_RIIC_READ_REG(8, (base + R_RIIC_MR3)); /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr dummy read */ dummy |= 0x10u; R_RIIC_WRITE_REG(8, (base + R_RIIC_MR3), dummy); /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr ACKWP set */  dummy = R_RIIC_READ_REG(8, (base + R_RIIC_MR3)); /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr dummy read */ dummy &= 0xD7u; R_RIIC_WRITE_REG(8, (base + R_RIIC_MR3), dummy); /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr DRFS,ACKBT clear */  dummy = R_RIIC_READ_REG(8, (base + R_RIIC_SR2)); /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr dummy read */ dummy &= ~R_RIIC_SR2_NACKF; R_RIIC_WRITE_REG(8, (base + R_RIIC_SR2), dummy); /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr NACKF flg clear */ dummy &= ~R_RIIC_SR2_STOP; R_RIIC_WRITE_REG(8, (base + R_RIIC_SR2), dummy); /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr STOP flg clear */ }   /****************************************************************************** r_riic_main.c r_riic_main.h r_riic_regs.h Function Name : R_RIIC_Slave_address_send r_riic_main.c r_riic_main.h r_riic_regs.h Description : Sending Slave address at Master mode r_riic_main.c r_riic_main.h r_riic_regs.h Arguments : uint8_t *data :Send data r_riic_main.c r_riic_main.h r_riic_regs.h Return Value : ACK OK :R_RIIC_ERR_OK : ACK NG :R_RIIC_ERR_NG ******************************************************************************/ r_riic_Error_t R_RIIC_Slave_address_send(uint32_t Unit, uint8_t *TxData) { r_riic_Error_t ack;  ack = R_RIIC_data_send(Unit, TxData); /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr slave device address */ if (ack == R_RIIC_ERR_OK)  { return(ack); }  return(ack); }   /******************************************************************************* Function: R_RIIC_transmit_to_slave  Write a series of values to a IIC slave.  IIC slave address is assumed to by first data value in tdata. Function generates a complete Start-Condition, Slave-Address-Send, Data-Send and End-Condition cycle.  Parameters: Unit - Instance number tdata - array with data to be send size - number of data to be send (size of tdata array)  Returns: see: <r_riic_Error_t> */ r_riic_Error_t R_RIIC_transmit_to_slave(uint32_t Unit, uint8_t *Tdata, uint32_t Size) { uint8_t data; uint8_t i; r_riic_Error_t ack;  if (Size <= 1) { return R_RIIC_ERR_NG; }  /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr transmit in master mode */ R_RIIC_Master_start_condition(Unit); data = Tdata[0]; /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Slave Address */ ack = R_RIIC_Slave_address_send(Unit, &data); for (i = 1; i < Size; i++) { data = Tdata[i]; /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr data n for slave (n=1 -> register name n>=2 -> register value) */ ack += R_RIIC_data_send(Unit, &data); } R_RIIC_Master_stop_condition(Unit, &data);  return ack; }   /******************************************************************************* Function: R_RIIC_receive_from_slave16b  Read 1 or 2 bytes from IIC slave with a 16bit address. (note: not all devices may support this format)  <slave address 7bit> <internal address 16 bit> <read 2 bytes>  Parameters: Unit - Instance number SlaveAddress - slave address 7bit InternalAddress - the device's internal addtess (16bit) Rdata - buffer to store data read from slave size - number of data bytes to be read  Returns: see: <r_riic_Error_t> */ r_riic_Error_t R_RIIC_receive_from_slave16b(uint32_t Unit, uint8_t SlaveAddress, uint16_t InternalAddress, uint8_t *Rdata, uint32_t Size) { uint8_t index; uint8_t data; uint8_t tmp; r_riic_Error_t ack; uint32_t base;  /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr only 1 or 2 byte can be read */ if ((Size == 0) || (Size > 2)) { return R_RIIC_ERR_NG; }  /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr index for the read data buffer pointer */ index = 0;  /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr transmit in master mode */ R_RIIC_Master_start_condition(Unit);  /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr send the slave address */ data = SlaveAddress;  ack = R_RIIC_Slave_address_send(Unit, &data);  /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr send the MSB internal address */ data = (InternalAddress >> 8u) & 0xFFu; R_RIIC_data_send(Unit, &data);  /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr send the LSB internal address */ data = InternalAddress & 0xFFu; R_RIIC_data_send(Unit, &data);  /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr repeated start condition */ R_RIIC_Master_stop_condition(Unit, &data);  /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr transmit in master mode */ R_RIIC_Master_start_condition(Unit);  data = SlaveAddress + 1; /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Slave Address + 1 for read */  base = r_riic_Dev[Unit].BaseAddr;  while((R_RIIC_READ_REG(8, (base + R_RIIC_SR2)) & R_RIIC_SR2_TDRE) == 0u)  { /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Waiting TDRE empty */ }  R_RIIC_WRITE_REG(8, (base + R_RIIC_DRT), data); /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr send data */  while((R_RIIC_READ_REG(8, (base + R_RIIC_SR2)) & R_RIIC_SR2_RDRF) == 0u)  { /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Waiting receive */ }  if((R_RIIC_READ_REG(8, (base + R_RIIC_SR2)) & R_RIIC_SR2_NACKF) == 0u)  { ack = R_RIIC_ERR_OK; } else { ack = R_RIIC_ERR_NG; }  if(ack == R_RIIC_ERR_OK) { /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr set wait = 1 */ tmp = R_RIIC_READ_REG(8, (base + R_RIIC_MR3)); R_RIIC_WRITE_REG(8, (base + R_RIIC_MR3), (tmp | 0x40u));   /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr dummy read */ R_RIIC_READ_REG(8, (base + R_RIIC_DRR));   while((R_RIIC_READ_REG(8, (base + R_RIIC_SR2)) & R_RIIC_SR2_RDRF) == 0u)  { }  /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr do an extra read byte if required */  if(2 == Size) {  /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr receive data read */ Rdata[index] = R_RIIC_READ_REG(8, (base + R_RIIC_DRR));  index++;  while((R_RIIC_READ_REG(8, (base + R_RIIC_SR2)) & R_RIIC_SR2_RDRF) == 0u)  { } }  /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr set RDRFS=1 */ tmp = R_RIIC_READ_REG(8, (base + R_RIIC_MR3)); R_RIIC_WRITE_REG(8, (base + R_RIIC_MR3), (tmp | 0x20u));   /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr set ACKBT=1 */ tmp = R_RIIC_READ_REG(8, (base + R_RIIC_MR3)); R_RIIC_WRITE_REG(8, (base + R_RIIC_MR3), (tmp | 0x08u));   /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr receive data read */ Rdata[index] = R_RIIC_READ_REG(8, (base + R_RIIC_DRR)); index++;   while((R_RIIC_READ_REG(8, (base + R_RIIC_SR2)) & R_RIIC_SR2_RDRF) == 0u)  { } }  R_RIIC_Master_stop_condition(Unit, &data);  return ack; }   /******************************************************************************* Function: R_RIIC_receive_from_slave8b  Read 1 or 2 bytes from IIC slave with a 8bit address. (note: not all devices may support this format)  <slave address 7bit> <internal address 8 bit> <read 2 bytes>  Parameters: Unit - Instance number SlaveAddress - slave address 7bit InternalAddress - the device's internal addtess (8bit) Rdata - buffer to store data read from slave size - number of data bytes to be read  Returns: see: <r_riic_Error_t> */ r_riic_Error_t R_RIIC_receive_from_slave8b(uint32_t Unit, uint8_t SlaveAddress, uint8_t InternalAddress, uint8_t *Rdata, uint32_t Size) { uint8_t index;  uint8_t data; uint8_t tmp; r_riic_Error_t ack; uint32_t base;  /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr only 1 or 2 byte can be read */ if ((Size == 0) || (Size > 2)) { return R_RIIC_ERR_NG; }  /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr index for the read data buffer pointer */ index = 0;  /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr transmit in master mode */ R_RIIC_Master_start_condition(Unit);  /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr send the slave address */ data = SlaveAddress;  ack = R_RIIC_Slave_address_send(Unit, &data);  /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr send the MSB internal address */ data = InternalAddress & 0xFFu; R_RIIC_data_send(Unit, &data);  /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr repeated start condition */ R_RIIC_Master_stop_condition(Unit, &data);  /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr transmit in master mode */ R_RIIC_Master_start_condition(Unit);  data = SlaveAddress + 1; /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Slave Address + 1 for read */  base = r_riic_Dev[Unit].BaseAddr;  while((R_RIIC_READ_REG(8, (base + R_RIIC_SR2)) & R_RIIC_SR2_TDRE) == 0u)  { /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Waiting TDRE empty */ }  R_RIIC_WRITE_REG(8, (base + R_RIIC_DRT), data); /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr send data */  while((R_RIIC_READ_REG(8, (base + R_RIIC_SR2)) & R_RIIC_SR2_RDRF) == 0u)  { /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Waiting receive */ }  if((R_RIIC_READ_REG(8, (base + R_RIIC_SR2)) & R_RIIC_SR2_NACKF) == 0u)  { ack = R_RIIC_ERR_OK; } else { ack = R_RIIC_ERR_NG; }  if(ack == R_RIIC_ERR_OK) { /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr set wait = 1 */ tmp = R_RIIC_READ_REG(8, (base + R_RIIC_MR3)); R_RIIC_WRITE_REG(8, (base + R_RIIC_MR3), (tmp | 0x40u));   /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr dummy read */ R_RIIC_READ_REG(8, (base + R_RIIC_DRR));   while((R_RIIC_READ_REG(8, (base + R_RIIC_SR2)) & R_RIIC_SR2_RDRF) == 0u)  { }  /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr do an extra read byte if required */  if(2 == Size) {  /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr receive data read */ Rdata[index] = R_RIIC_READ_REG(8, (base + R_RIIC_DRR));  index++;   while((R_RIIC_READ_REG(8, (base + R_RIIC_SR2)) & R_RIIC_SR2_RDRF) == 0u)  { } }  /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr set RDRFS=1 */ tmp = R_RIIC_READ_REG(8, (base + R_RIIC_MR3)); R_RIIC_WRITE_REG(8, (base + R_RIIC_MR3), (tmp | 0x20u));   /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr set ACKBT=1 */ tmp = R_RIIC_READ_REG(8, (base + R_RIIC_MR3)); R_RIIC_WRITE_REG(8, (base + R_RIIC_MR3), (tmp | 0x08u));   /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr receive data read */ Rdata[index] = R_RIIC_READ_REG(8, (base + R_RIIC_DRR)); index++;   while((R_RIIC_READ_REG(8, (base + R_RIIC_SR2)) & R_RIIC_SR2_RDRF) == 0u)  { } }  R_RIIC_Master_stop_condition(Unit, &data);  return ack; }
