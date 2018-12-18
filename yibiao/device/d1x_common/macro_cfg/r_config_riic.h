/* **************************************************************************** PROJECT : RIIC driver FILE : $Id: r_config_riic.h 3952 2014-09-24 09:52:47Z golczewskim $ ============================================================================  DESCRIPTION RIIC configuration for r7f701412 ============================================================================ C O P Y R I G H T  ============================================================================ Copyright (c) 2014 by  Renesas Electronics (Europe) GmbH.  Arcadiastrasse 10 D-40472 Duesseldorf Germany All rights reserved. ============================================================================ Purpose: only for testing  DISCLAIMER  This software is supplied by Renesas Electronics Corporation and is only  intended for use with Renesas products. No other uses are authorized. This  software is owned by Renesas Electronics Corporation and is protected under  all applicable laws, including copyright laws.  THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING  THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT  LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE  AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.  TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS  ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE  FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR  ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE  BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.  Renesas reserves the right, without notice, to make changes to this software  and to discontinue the availability of this software. By using this software, you agree to the additional terms and conditions found by accessing the  following link:  http://www.renesas.com/disclaimer r_config_adc.h r_config_awot.h r_config_clma.h r_config_csig.h r_config_csih.h r_config_csisw.h r_config_d1x.h r_config_dcra.h r_config_dma.h r_config_ecm.h r_config_g3dma.h r_config_gpio.h r_config_hwversion.h r_config_ism.h r_config_lcbi.h r_config_ostm.h r_config_pbg.h r_config_pcmp.h r_config_pin.h r_config_pwm.h r_config_riic.h r_config_rlin3.h r_config_rtca.h r_config_sfma.h r_config_sg.h r_config_spea.h r_config_ssif.h r_config_stbc.h r_config_taub.h r_config_tauj.h r_config_tick.h r_config_vdce.h r_config_vram.h r_config_wdta.h r_config_wm.h r_config_xbus.h  Copyright (C) 2011 Renesas Electronics Corporation. All rights reserved.   **************************************************************************** */  #ifndef CONFIG_RIIC_H_ #define CONFIG_RIIC_H_  #if defined (R_DBG_PRINT_RIIC_REGS) || defined (R_DBG_PRINT_MSG) #include <stdio.h>  #include "r_dbg_api.h" #endif  /******************************************************************************* Title: RIIC Configuration */  /******************************************************************************* Section: Global Defines */  /******************************************************************************* Constant: R_RIIC_MACRO_NUM  Number of RIIC macros in the device. */  #define R_RIIC_MACRO_NUM 2   /******************************************************************************* Section: Global Macros */  /******************************************************************************* Macro: R_RIIC_WRITE_REG  Write RIIC register with predefined size. SIZE allowed values are 8, 16, 32 */ #ifdef R_DBG_PRINT_RIIC_REGS #define R_RIIC_WRITE_REG(SIZE, ADDR, VALUE) R_DBG_PrintRegCmd((SIZE), (ADDR), (VALUE)); *((volatile uint##SIZE##_t*)(ADDR)) = (VALUE) #else #define R_RIIC_WRITE_REG(SIZE, ADDR, VALUE) (*((volatile uint##SIZE##_t*)(ADDR)) = (VALUE)) #endif  #define R_RIIC_WRITE_REG_SILENT(SIZE, ADDR, VALUE) {(*((volatile uint##SIZE##_t*)(ADDR)) = (VALUE));}   /******************************************************************************* Macro: R_RIIC_READ_REG  Read RIIC register with predefined size. SIZE allowed values are 8, 16, 32 */  #ifdef R_DBG_PRINT_RIIC_REGS #define R_RIIC_READ_REG(SIZE, ADDR) R_DBG_PrintRegRead##SIZE##(ADDR) #else #define R_RIIC_READ_REG(SIZE, ADDR) (*((volatile uint##SIZE##_t*)((ADDR))))  #endif   #endif /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr CONFIG_RIIC_H_ */
