# ****************************************************************************
# PROJECT : VLIB
# FILE    : $Id: help.mk 149 2012-09-04 08:19:33Z michael.golczewski $
# ============================================================================ 
# DESCRIPTION
# Ship project generator for V800
# ============================================================================
#                             C O P Y R I G H T                                    
# ============================================================================
#                            Copyright (c) 2012
#                                   by 
#                        Renesas Electronics (Europe) GmbH. 
#                            Arcadiastrasse 10
#                           D-40472 Duesseldorf
#                                Germany
#                           All rights reserved.
# ============================================================================
# Purpose: only for testing
# 
# DISCLAIMER                                                                   
# This software is supplied by Renesas Electronics Corporation and is only     
# intended for use with Renesas products. No other uses are authorized. This   
# software is owned by Renesas Electronics Corporation and is protected under  
# all applicable laws, including copyright laws.                               
# THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING  
# THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT      
# LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE   
# AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.          
# TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS       
# ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE  
# FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR   
# ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE  
# BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.                             
# Renesas reserves the right, without notice, to make changes to this software 
# and to discontinue the availability of this software. By using this software,
# you agree to the additional terms and conditions found by accessing the      
# following link:                                                              
# http://www.renesas.com/disclaimer *                                          
# Copyright (C) 2011 Renesas Electronics Corporation. All rights reserved.     
# ****************************************************************************


.PHONY : help

help :
	@echo " "
	@echo " "
	@echo "*********************************************************"
	@echo " "
	@echo "               Help for make"
	@echo " "
	@echo "*********************************************************"
	@echo " "
	@echo " "
	@echo "Available options are:"
	@echo " "
	@echo "svnupdate"
	@echo "  Perform an SVN update for the project files"
	@echo " "
	@echo "********* "
	@echo " "
	@echo "multi"
	@echo "  Creates a multi project based on the make files."
	@echo " "
	@echo "********* "
	@echo " "
	@echo "ship"
	@echo "  Creates a folder containing all files of the project."	
	@echo "  This folder can then be sent to other colleagues."
	@echo "  Note: The creation process invokes a make 'all'."
	@echo " "
	@echo "********* "
	@echo " "
	@echo "ultraedit"
	@echo "  Creates an ultraedit project."
	@echo " "
	@echo "********* "
	@echo " "
	@echo " "
	@echo "*********************************************************"
