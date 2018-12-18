/***************************************************************************** nvm.c nvm_cfg.h nvm_info.inc nvm_private.h nvm_public.h Copyright (C) 2016 ShenZhen Yeedon Media co.,LTD. All rights reserved. * nvm.c nvm_cfg.h nvm_info.inc nvm_private.h nvm_public.h File Name : nvm_private.h nvm.c nvm_cfg.h nvm_info.inc nvm_private.h nvm_public.h Description : the private informations datas of the nvm nvm.c nvm_cfg.h nvm_info.inc nvm_private.h nvm_public.h Author: Xuenian.Feng nvm.c nvm_cfg.h nvm_info.inc nvm_private.h nvm_public.h Date: 2016-12-1 ******************************************************************************/ //  /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr check of multiple include */ #ifndef _NVM_PRIVATE_H_ #define _NVM_PRIVATE_H_ #include "yd_typedefs.h" #include "nvm_public.h" /*Private Macros defines*/  #define WRITE_EEPROM_BUFEER_SIZE 10 #define BYTEOFFSET_1 0/* 字节偏移 0 与EEPROM的对应，开始为1*/  #define ADDR_SYS_DIDAF00 0x0000 /*地址*/ #define ADDR_SYS_PAGE0 0x0000 #define ADDR_SYS_PAGE1 0x0010 #define ADDR_SYS_PAGE2 0x0020 #define ADDR_SYS_PAGE3 0x0030 #define ADDR_LOGIST_PAGE0 0x00E0 #define ADDR_LOGIST_PAGE1 0x0200 #define ADDR_FBL_PAGE0 0x0280  #define ADDR_CONFIG_PAGE0 0x02D0 #define ADDR_DTC_PAGE0 0x0400 #define ADDR_SNAPSHOT_PAGE0 0x0590 #define ADDR_FUNCTION_PAGE0 0x0700  #define SIZE_NVM_PAGE 0X10 #define CNT_CONFIG_PAGE 0X10  #define CNT_FUNCTION_PAGE 0X08 #define NVM_SNAPSHOT_TIMELEN 6   /*@SYS BLOCK =====START*/ #define NVM_SYS0_AF00_LEN 5 #define NVM_SYS0_AF01_LEN 5 #define NVM_SYS0_AF02_LEN 5   #define NVM_SYS1_AF03_LEN 5 #define NVM_SYS1_D101_LEN 4 #define NVM_SYS1_RESERVE_LEN 6  #define NVM_CFG_LEN_4 4 #define NVM_CFG_LEN_8 8 /*@SYS BOLCK DEFINE STRUCT END*/  /*@FBL BLOCK =====END*/ /*@CONFIG BLOCK =====START*/ #define NVM_CFG_DID_LEN8 8 #define NVM_CFG_DID_LEN4 4 #define NVM_CFG_PAGE_LEN 16 /*@CONFIG BLOCK =====END*/  #define NVM_FUN_LEN_1 1 #define NVM_FUN_LEN_2 2 #define NVM_FUN_LEN_3 3 #define NVM_FUN_LEN_4 4   /*Private Data Structures defines*/ typedef struct NVMWriteMatrix_Tag { U16 addr;/*参数所在的页地址*/ PU8 pValue; U8 offset; U8 size; }NVMWriteMatrix_ST;  typedef struct NVMDataSts_Tag { BOOL valid; U8 PageNum; U8 sts; }NVMDataSts_ST;  /*SYS BOLCK DEFINE STRUCT START*/ typedef struct nvm_SYS0S_Tag { U8 AF00[NVM_SYS0_AF00_LEN]; U8 AF01[NVM_SYS0_AF01_LEN]; U8 AF02[NVM_SYS0_AF02_LEN]; U8 chksum; }nvm_SYS0_ST;  typedef struct nvm_SYS1S_Tag { U8 AF03[NVM_SYS1_AF03_LEN]; U8 D101[NVM_SYS1_D101_LEN]; U8 Reserve[NVM_SYS1_RESERVE_LEN]; U8 chksum; }nvm_SYS1_ST;  typedef union nvm_SYS0U_Tag { U8 buf[16];  nvm_SYS0_ST data;  }nvm_SYS0_UN;   typedef union nvm_SYS1U_Tag { U8 buf[16];  nvm_SYS1_ST data;  }nvm_SYS1_UN;  /*SYS BOLCK DEFINE STRUCT END*/   /*FBL BLOCK RESERVED FOR V2 */  /*LOGIST BOLCK DEFINE STRUCT START*/ typedef struct nvm_logist_page0_Tag { U8 Rev[5]; U8 F100[NVM_LOGIST_F100_LEN]; }nvm_logist_page0_ST;  typedef union nvm_LOGIST_page0_Tag { U8 buf[16]; nvm_logist_page0_ST data; }nvm_LOGIST_page0_UN;  typedef union nvm_LOGIST_page1_Tag { U8 buf[16]; U8 F110[NVM_LOGIST_F110_LEN]; }nvm_LOGIST_page1_UN;     typedef struct nvm_logist_flow1_Tag { U8 AppEntry[NVM_LOGIST_APPENTRY_LEN]; U8 Rev1[2]; U8 F111[NVM_LOGIST_F111_LEN]; U8 F112[NVM_LOGIST_F112_LEN]; U8 F113[NVM_LOGIST_F113_LEN]; U8 F114[NVM_LOGIST_F110_LEN]; U8 F115[NVM_LOGIST_F110_LEN]; U8 F116[NVM_LOGIST_F116_LEN]; U8 F117[NVM_LOGIST_F117_LEN]; U8 F118[NVM_LOGIST_F118_LEN]; U8 F119[NVM_LOGIST_F119_LEN]; U8 F11A[NVM_LOGIST_F11A_LEN]; U8 F11B[NVM_LOGIST_F11B_LEN]; U8 F11C[NVM_LOGIST_F11C_LEN]; U8 F11D[NVM_LOGIST_F11D_LEN]; U8 F11E[NVM_LOGIST_F11E_LEN]; U8 F11F[NVM_LOGIST_F11F_LEN]; U8 F120[NVM_LOGIST_F120_LEN]; U8 F121[NVM_LOGIST_F121_LEN]; U8 Rev2[10]; }nvm_logist_flow1_ST;  typedef union nvm_LOGIST_flow1_Tag { U8 buf[18][16]; nvm_logist_flow1_ST data; }nvm_LOGIST_flow1_UN;   typedef struct nvm_logist_flow2_Tag { U8 F187[NVM_LOGIST_F187_LEN]; U8 F18A[NVM_LOGIST_F18A_LEN]; U8 F18B[NVM_LOGIST_F18B_LEN]; U8 F18C[NVM_LOGIST_F18C_LEN]; U8 F190[NVM_LOGIST_F190_LEN]; U8 F191[NVM_LOGIST_F191_LEN]; U8 F192[NVM_LOGIST_F192_LEN]; U8 F198[NVM_LOGIST_F198_LEN]; U8 F1A8[NVM_LOGIST_F1A8_LEN]; U8 F1A9[NVM_LOGIST_F1A9_LEN]; U8 F1AA[NVM_LOGIST_F1AA_LEN]; U8 AFFC[NVM_FBL_AFFC_LEN]; U8 AFFD[NVM_FBL_AFFD_LEN]; U8 AFFE[NVM_FBL_AFFE_LEN]; U8 AFFF[NVM_FBL_AFFF_LEN]; U8 BLA[NVM_FBL_BOOTLOADER_LEN];/*BOAT LOAD AREA*/ U8 PrjEntry[NVM_FBL_PJTENTRY_LEN]; U8 F11LWSF[NVM_FBL_F110WSF_LEN]; U8 CaliData[NVM_FBL_CALIDATA_LEN]; U8 Rev[15]; }nvm_logist_flow2_ST;  typedef union nvm_LOGIST_flow2_Tag { U8 buf[10][16]; nvm_logist_flow2_ST data; }nvm_LOGIST_flow2_UN;  typedef struct nvm_LOGIST_Tag { /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr start reserved size:0xA6*/ // U8 F100[NVM_LOGIST_F100_LEN]; nvm_LOGIST_page0_UN page0; nvm_LOGIST_page1_UN page1; /*page2~page19*/ nvm_LOGIST_flow1_UN flow1; nvm_LOGIST_flow2_UN flow2;  }nvm_LOGIST_ST;  /*FBL BLOCK STRUCT STRUCT START*/   typedef union nvm_CFG_PAGE0_Tag { U8 page[NVM_CFG_PAGE_LEN]; struct { nvm_CFGC111_ST C111; nvm_CFGC112_ST C112; }page0_U; }nvm_CFG_PAGE0_UN; typedef union nvm_CFG_PAGE1_Tag { U8 page[NVM_CFG_PAGE_LEN]; struct { nvm_CFGC113_ST C113; nvm_CFGC121_ST C121; nvm_CFGC122_ST C122; }page1_U; }nvm_CFG_PAGE1_UN;  typedef union nvm_CFG_PAGE2_Tag { U8 page[NVM_CFG_PAGE_LEN]; struct { nvm_CFGC131_ST C131; U8 buf[4]; nvm_CFGC141_ST C141; }page2_U; }nvm_CFG_PAGE2_UN;    typedef union nvm_CFG_PAGE3_Tag { U8 page[NVM_CFG_PAGE_LEN]; struct { nvm_CFGC151_ST C151; nvm_CFGC164_ST C164; }page3_U; }nvm_CFG_PAGE3_UN;    typedef union nvm_CFG_PAGE4_Tag { U8 page[NVM_CFG_PAGE_LEN]; struct { nvm_CFGC165_ST C165; nvm_CFGC166_ST C166; }page4_U; }nvm_CFG_PAGE4_UN;    typedef union nvm_CFG_PAGE5_Tag { U8 page[NVM_CFG_PAGE_LEN]; struct { nvm_CFGC167_ST C167; nvm_CFGC171_ST C171; }page5_U; }nvm_CFG_PAGE5_UN;   typedef union nvm_CFG_PAGE6_Tag { U8 page[NVM_CFG_PAGE_LEN]; struct { nvm_CFGC172_ST C172; U8 buf[4]; nvm_CFGC181_ST C181; }page6_U; }nvm_CFG_PAGE6_UN;    typedef union nvm_CFG_PAGE7_Tag { U8 page[NVM_CFG_PAGE_LEN]; struct { nvm_CFGC182_ST C182; nvm_CFGC191_ST C191; }page7_U; }nvm_CFG_PAGE7_UN;     typedef union nvm_CFG_PAGE8_Tag { U8 page[NVM_CFG_PAGE_LEN]; struct { nvm_CFGC192_ST C192; nvm_CFGC1A1_ST C1A1; }page8_U; }nvm_CFG_PAGE8_UN;    typedef union nvm_CFG_PAGE9_Tag { U8 page[NVM_CFG_PAGE_LEN]; struct { nvm_CFGC1B1_ST C1B1; nvm_CFGC1B2_ST C1B2; }page9_U; }nvm_CFG_PAGE9_UN;    typedef union nvm_CFG_PAGE10_Tag { U8 page[NVM_CFG_PAGE_LEN]; struct { nvm_CFGC1C1_ST C1C1; nvm_CFGC1C2_ST C1C2; }page10_U; }nvm_CFG_PAGE10_UN;    typedef union nvm_CFG_PAGE11_Tag { U8 page[NVM_CFG_PAGE_LEN]; struct { nvm_CFGC1C3_ST C1C3; nvm_CFGC1C4_ST C1C4; }page11_U; }nvm_CFG_PAGE11_UN;     typedef union nvm_CFG_PAGE12_Tag { U8 page[NVM_CFG_PAGE_LEN]; struct { nvm_CFGC1C5_ST C1C5; nvm_CFGC1C6_ST C1C6; }page12_U; }nvm_CFG_PAGE12_UN;     typedef union nvm_CFG_PAGE13_Tag { U8 page[NVM_CFG_PAGE_LEN]; struct { nvm_CFGC1C7_ST C1C7; nvm_CFGC1C8_ST C1C8; }page13_U; }nvm_CFG_PAGE13_UN;     typedef union nvm_CFG_PAGE14_Tag { U8 page[NVM_CFG_PAGE_LEN]; struct { nvm_CFGC1D1_ST C1D1; nvm_CFGC1E1_ST C1E1; }page14_U; }nvm_CFG_PAGE14_UN;    typedef union nvm_CFG_PAGE15_Tag { U8 page[NVM_CFG_PAGE_LEN]; struct { nvm_CFGC1E2_ST C1E2; U8 buf[8]; }page15_U; }nvm_CFG_PAGE15_UN;   typedef struct nvm_CFG_Tag { nvm_CFG_PAGE0_UN page0; nvm_CFG_PAGE1_UN page1; nvm_CFG_PAGE2_UN page2; nvm_CFG_PAGE3_UN page3; nvm_CFG_PAGE4_UN page4; nvm_CFG_PAGE5_UN page5; nvm_CFG_PAGE6_UN page6; nvm_CFG_PAGE7_UN page7; nvm_CFG_PAGE8_UN page8; nvm_CFG_PAGE9_UN page9; nvm_CFG_PAGE10_UN page10; nvm_CFG_PAGE11_UN page11; nvm_CFG_PAGE12_UN page12; nvm_CFG_PAGE13_UN page13; nvm_CFG_PAGE14_UN page14; nvm_CFG_PAGE15_UN page15; }nvm_CFG_ST;   /*DTC*/ typedef union nvm_DTC_PAGE0_Tag { U8 buf[NVM_CFG_PAGE_LEN]; struct { U8 dtc_0100[NVM_CFG_PAGE_LEN]; }page0_U; }nvm_DTC_PAGE0_UN;  typedef union nvm_DTC_PAGE1_Tag { U8 buf[NVM_CFG_PAGE_LEN]; struct { U8 dtc01[8]; U8 dtc02[8]; }page1_U; }nvm_DTC_PAGE1_UN;  typedef union nvm_DTC_PAGE2_Tag { U8 buf[NVM_CFG_PAGE_LEN]; struct { U8 dtc03[8]; U8 dtc04[8]; }page2_U; }nvm_DTC_PAGE2_UN;  typedef union nvm_DTC_PAGE3_Tag { U8 buf[NVM_CFG_PAGE_LEN]; struct { U8 dtc05[8]; U8 dtc06[8]; }page3_U; }nvm_DTC_PAGE3_UN;  typedef union nvm_DTC_PAGE4_Tag { U8 buf[NVM_CFG_PAGE_LEN]; struct { U8 dtc07[8]; U8 dtc08[8]; }page4_U; }nvm_DTC_PAGE4_UN;  typedef union nvm_DTC_PAGE5_Tag { U8 buf[NVM_CFG_PAGE_LEN]; struct { U8 dtc09[8]; U8 dtc10[8]; }page5_U; }nvm_DTC_PAGE5_UN;  typedef union nvm_DTC_PAGE6_Tag { U8 buf[NVM_CFG_PAGE_LEN]; struct { U8 dtc11[8]; U8 dtc12[8]; }page6_U; }nvm_DTC_PAGE6_UN;  typedef union nvm_DTC_PAGE7_Tag { U8 buf[NVM_CFG_PAGE_LEN]; struct { U8 dtc13[8]; U8 dtc14[8]; }page7_U; }nvm_DTC_PAGE7_UN;  typedef union nvm_DTC_PAGE8_Tag { U8 buf[NVM_CFG_PAGE_LEN]; struct { U8 dtc15[8]; U8 dtc16[8]; }page8_U; }nvm_DTC_PAGE8_UN;  typedef union nvm_DTC_PAGE9_Tag { U8 buf[NVM_CFG_PAGE_LEN]; struct { U8 dtc17[8]; U8 dtc18[8]; }page9_U; }nvm_DTC_PAGE9_UN;  typedef union nvm_DTC_PAGE10_Tag { U8 buf[NVM_CFG_PAGE_LEN]; struct { U8 dtc19[8]; U8 dtc20[8]; }page10_U; }nvm_DTC_PAGE10_UN;  typedef union nvm_DTC_PAGE11_Tag { U8 buf[NVM_CFG_PAGE_LEN]; struct { U8 dtc21[8]; U8 dtc22[8]; }page11_U; }nvm_DTC_PAGE11_UN;  typedef union nvm_DTC_PAGE12_Tag { U8 buf[NVM_CFG_PAGE_LEN]; struct { U8 dtc23[8]; U8 dtc24[8]; }page12_U; }nvm_DTC_PAGE12_UN;  typedef union nvm_DTC_PAGE13_Tag { U8 buf[NVM_CFG_PAGE_LEN]; struct { U8 dtc25[8]; U8 dtc26[8]; }page13_U; }nvm_DTC_PAGE13_UN;  typedef union nvm_DTC_PAGE14_Tag { U8 buf[NVM_CFG_PAGE_LEN]; struct { U8 dtc27[8]; U8 dtc28[8]; }page14_U; }nvm_DTC_PAGE14_UN;  typedef union nvm_DTC_PAGE15_Tag { U8 buf[NVM_CFG_PAGE_LEN]; struct { U8 dtc29[8]; U8 dtc30[8]; }page15_U; }nvm_DTC_PAGE15_UN;  typedef union nvm_DTC_PAGE16_Tag { U8 buf[NVM_CFG_PAGE_LEN]; struct { U8 dtc31[8]; U8 dtc32[8]; }page16_U; }nvm_DTC_PAGE16_UN;  typedef union nvm_DTC_PAGE17_Tag { U8 buf[NVM_CFG_PAGE_LEN]; struct { U8 dtc33[8]; U8 rev[8]; }page17_U; }nvm_DTC_PAGE17_UN;  typedef union nvm_DTC_PAGE18_Tag { U8 buf[NVM_CFG_PAGE_LEN]; struct { U8 dtc34[8]; U8 rev[8]; }page18_U; }nvm_DTC_PAGE18_UN;  typedef union nvm_DTC_PAGE19_Tag { U8 buf[NVM_CFG_PAGE_LEN]; struct { U8 dtc35[8]; U8 rev[8]; }page19_U; }nvm_DTC_PAGE19_UN; typedef union nvm_DTC_PAGE20_Tag { U8 buf[NVM_CFG_PAGE_LEN]; struct { U8 dtc36[8]; U8 rev[8]; }page20_U; }nvm_DTC_PAGE20_UN;  typedef union nvm_DTC_PAGE21_Tag { U8 buf[NVM_CFG_PAGE_LEN]; struct { U8 dtc37[8]; U8 rev[8]; }page21_U; }nvm_DTC_PAGE21_UN;  typedef union nvm_DTC_PAGE22_Tag { U8 buf[NVM_CFG_PAGE_LEN]; struct { U8 dtc38[8]; U8 rev[8]; }page22_U; }nvm_DTC_PAGE22_UN;  typedef union nvm_DTC_PAGE23_Tag { U8 buf[NVM_CFG_PAGE_LEN]; struct { U8 dtc39[8]; U8 rev[8]; }page23_U; }nvm_DTC_PAGE23_UN;  typedef union nvm_DTC_PAGE24_Tag { U8 buf[NVM_CFG_PAGE_LEN]; struct { U8 rev1[8]; U8 rev2[8]; }page24_U; }nvm_DTC_PAGE24_UN;  typedef struct nvm_DTC_Tag { nvm_DTC_PAGE0_UN page0; nvm_DTC_PAGE1_UN page1; nvm_DTC_PAGE2_UN page2; nvm_DTC_PAGE3_UN page3; nvm_DTC_PAGE4_UN page4; nvm_DTC_PAGE5_UN page5; nvm_DTC_PAGE6_UN page6; nvm_DTC_PAGE7_UN page7; nvm_DTC_PAGE8_UN page8; nvm_DTC_PAGE9_UN page9; nvm_DTC_PAGE10_UN page10; nvm_DTC_PAGE11_UN page11; nvm_DTC_PAGE12_UN page12; nvm_DTC_PAGE13_UN page13; nvm_DTC_PAGE14_UN page14; nvm_DTC_PAGE15_UN page15; nvm_DTC_PAGE16_UN page16; nvm_DTC_PAGE17_UN page17; nvm_DTC_PAGE18_UN page18; nvm_DTC_PAGE19_UN page19; nvm_DTC_PAGE20_UN page20; nvm_DTC_PAGE21_UN page21; nvm_DTC_PAGE22_UN page22; nvm_DTC_PAGE23_UN page23; nvm_DTC_PAGE24_UN page24; }nvm_DTC_ST;   /*SNAPSHOT*/ typedef union nvm_SnapShot_Tag { U8 buf[32]; }nvm_SnapShot_ST;  typedef union nvm_Function_Page0_Tag { U8 buf[16]; struct { U8 B102[3]; U8 B111[3]; U8 E102[2]; U8 E103; U16 E104; U8 E105; U8 SIAOdoPriy[3]; U8 chksum; }FunPage0_U; }nvm_Function_Page0_UN;   typedef union nvm_Function_Page1_Tag { U8 buf[16]; struct { U16 K_CompareFuel; U16 K_DisplayFuel; U32 K_RangeToEmpty; U8 K_FullFuelConsumption; U8 K_RecentFuelConsumption; U8 K_OdometerSum; U16 K_FuelSum; U16 lastDistanceCnt; U8 chksum; }FunPage1_U;  }nvm_Function_Page1_UN;  typedef union nvm_Function_ODO_Tag { U8 buf[16]; struct { U32 B101; U8 Reserve[11]; U8 chksum;  }Funodo_U;  }nvm_Function_ODO_UN;  typedef union nvm_Function_Page7_Tag { U8 buf[16]; struct { U16 AngleOffset; U32 e_sum_fuel; U32 e_sum2_fuel; U8 F18B_WRCNT; U8 F18C_WRCNT; U8 SA_FailCnt; U8 F190_WRCNT; U8 Reserve;  U8 chksum; }FunPage7_U;  }nvm_Function_Page7_UN;  typedef union nvm_Function_Page8_Tag { U8 buf[16]; struct { U8 pmOperationMode; U8 runkeep; U8 Reserve[13]; U8 chksum; }FunPage8_U;  }nvm_Function_Page8_UN;     typedef struct nvm_Function_Tag { nvm_Function_Page0_UN page0; nvm_Function_Page1_UN page1; nvm_Function_ODO_UN odo[5]; nvm_Function_Page7_UN angle; nvm_Function_Page8_UN page8;  }nvm_Function_ST;   typedef struct nvm_MapData_Tag { /*@SYS BLOCK====START=====*/ nvm_SYS0_UN page0; nvm_SYS1_UN page1; /*SYS RESERVED 32 BYTES HERE*/  /*@FBL BLOCK == RESERVEDHERE=*/ //nvm_FBL_ST fbl; /*@LOGIST BLOCK====START=====*/ nvm_LOGIST_ST logist; nvm_CFG_ST config; nvm_DTC_ST dtc; nvm_SnapShot_ST snapshort[10]; nvm_Function_ST function;  }nvm_MapData_ST; static nvm_MapData_ST nvm_Data;   typedef struct nvm_RW_Tag { U8 FirstByte; U8 EndByte;  U16 PageNum; U16 PageAddr; U16 ofs;  U8 Error; U8 Step;  }nvm_RW_ST;   /*constant define*/  NVMDataSts_ST nvm_datasts[INDEX_NVM_ALL] = {  {/*INDEX_NVM_NONE*/VALID,1,STS_IDLE}, {/*INDEX_NVM_AF00*/VALID,1,STS_IDLE}, {/*INDEX_NVM_AF01*/VALID,1,STS_IDLE}, {/*INDEX_NVM_AF02*/VALID,1,STS_IDLE}, {/*INDEX_NVM_AF03*/VALID,1,STS_IDLE}, {/*INDEX_NVM_D101*/VALID,1,STS_IDLE},  {/*INDEX_NVM_F100*/VALID,1,STS_IDLE}, {/*INDEX_NVM_F110*/VALID,1,STS_IDLE}, {/*INDEX_NVM_F111*/VALID,2,STS_IDLE}, {/*INDEX_NVM_F112*/VALID,2,STS_IDLE}, {/*INDEX_NVM_F113*/VALID,2,STS_IDLE}, {/*INDEX_NVM_F114*/VALID,2,STS_IDLE}, {/*INDEX_NVM_F115*/VALID,2,STS_IDLE}, {/*INDEX_NVM_F116*/VALID,2,STS_IDLE}, {/*INDEX_NVM_F117*/VALID,2,STS_IDLE}, {/*INDEX_NVM_F118*/VALID,2,STS_IDLE}, {/*INDEX_NVM_F119*/VALID,2,STS_IDLE}, {/*INDEX_NVM_F11A*/VALID,2,STS_IDLE}, {/*INDEX_NVM_F11B*/VALID,2,STS_IDLE}, {/*INDEX_NVM_F11C*/VALID,2,STS_IDLE}, {/*INDEX_NVM_F11D*/VALID,2,STS_IDLE}, {/*INDEX_NVM_F11E*/VALID,2,STS_IDLE}, {/*INDEX_NVM_F11F*/VALID,2,STS_IDLE}, {/*INDEX_NVM_F120*/VALID,2,STS_IDLE}, {/*INDEX_NVM_F121*/VALID,2,STS_IDLE}, /*reserve 6 bytes*/  {/*INDEX_NVM_F187*/VALID,1,STS_IDLE}, {/*INDEX_NVM_F18A*/VALID,1,STS_IDLE}, {/*INDEX_NVM_F18B*/VALID,1,STS_IDLE}, {/*INDEX_NVM_F18C*/VALID,2,STS_IDLE}, {/*INDEX_NVM_F190*/VALID,2,STS_IDLE}, {/*INDEX_NVM_F191*/VALID,2,STS_IDLE}, {/*INDEX_NVM_F192*/VALID,1,STS_IDLE}, {/*INDEX_NVM_F198*/VALID,1,STS_IDLE}, {/*INDEX_NVM_F1A8*/VALID,1,STS_IDLE}, {/*INDEX_NVM_F1A9*/VALID,2,STS_IDLE}, {/*INDEX_NVM_F1AA*/VALID,1,STS_IDLE}, {/*INDEX_NVM_AFFC*/VALID,1,STS_IDLE}, {/*INDEX_NVM_AFFD*/VALID,1,STS_IDLE}, {/*INDEX_NVM_AFFE*/VALID,1,STS_IDLE}, {/*INDEX_NVM_AFFF*/VALID,1,STS_IDLE}, {/*INDEX_NVM_ISPFLG*/VALID,1,STS_IDLE},  /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr others no need to write ,will ignore*/ {/*INDEX_NVM_C111*/VALID,1,STS_IDLE}, {/*INDEX_NVM_C112*/VALID,1,STS_IDLE}, {/*INDEX_NVM_C113*/VALID,1,STS_IDLE}, {/*INDEX_NVM_C121*/VALID,1,STS_IDLE}, {/*INDEX_NVM_C122*/VALID,1,STS_IDLE}, {/*INDEX_NVM_C131*/VALID,1,STS_IDLE}, {/*INDEX_NVM_C141*/VALID,1,STS_IDLE}, {/*INDEX_NVM_C151*/VALID,1,STS_IDLE}, {/*INDEX_NVM_C164*/VALID,1,STS_IDLE}, {/*INDEX_NVM_C165*/VALID,1,STS_IDLE}, {/*INDEX_NVM_C166*/VALID,1,STS_IDLE}, {/*INDEX_NVM_C167*/VALID,1,STS_IDLE}, {/*INDEX_NVM_C171*/VALID,1,STS_IDLE}, {/*INDEX_NVM_C172*/VALID,1,STS_IDLE}, {/*INDEX_NVM_C181*/VALID,1,STS_IDLE}, {/*INDEX_NVM_C182*/VALID,1,STS_IDLE}, {/*INDEX_NVM_C191*/VALID,1,STS_IDLE}, {/*INDEX_NVM_C192*/VALID,1,STS_IDLE}, {/*INDEX_NVM_C1A1*/VALID,1,STS_IDLE}, {/*INDEX_NVM_C1B1*/VALID,1,STS_IDLE}, {/*INDEX_NVM_C1B2*/VALID,1,STS_IDLE}, {/*INDEX_NVM_C1C1*/VALID,1,STS_IDLE}, {/*INDEX_NVM_C1C2*/VALID,1,STS_IDLE}, {/*INDEX_NVM_C1C3*/VALID,1,STS_IDLE}, {/*INDEX_NVM_C1C4*/VALID,1,STS_IDLE}, {/*INDEX_NVM_C1C5*/VALID,1,STS_IDLE}, {/*INDEX_NVM_C1C6*/VALID,1,STS_IDLE}, {/*INDEX_NVM_C1C7*/VALID,1,STS_IDLE}, {/*INDEX_NVM_C1C8*/VALID,1,STS_IDLE}, {/*INDEX_NVM_C1D1*/VALID,1,STS_IDLE}, {/*INDEX_NVM_C1E1*/VALID,1,STS_IDLE}, {/*INDEX_NVM_C1E2*/VALID,1,STS_IDLE}, {/*INDEX_NVM_0100*/VALID,1,STS_IDLE}, {/*INDEX_NVM_DTC01*/VALID,1,STS_IDLE}, {/*INDEX_NVM_DTC02*/VALID,1,STS_IDLE}, {/*INDEX_NVM_DTC03*/VALID,1,STS_IDLE}, {/*INDEX_NVM_DTC04*/VALID,1,STS_IDLE}, {/*INDEX_NVM_DTC05*/VALID,1,STS_IDLE}, {/*INDEX_NVM_DTC06*/VALID,1,STS_IDLE}, {/*INDEX_NVM_DTC07*/VALID,1,STS_IDLE}, {/*INDEX_NVM_DTC08*/VALID,1,STS_IDLE}, {/*INDEX_NVM_DTC09*/VALID,1,STS_IDLE}, {/*INDEX_NVM_DTC10*/VALID,1,STS_IDLE}, {/*INDEX_NVM_DTC11*/VALID,1,STS_IDLE}, {/*INDEX_NVM_DTC12*/VALID,1,STS_IDLE}, {/*INDEX_NVM_DTC13*/VALID,1,STS_IDLE}, {/*INDEX_NVM_DTC14*/VALID,1,STS_IDLE}, {/*INDEX_NVM_DTC15*/VALID,1,STS_IDLE}, {/*INDEX_NVM_DTC16*/VALID,1,STS_IDLE}, {/*INDEX_NVM_DTC17*/VALID,1,STS_IDLE}, {/*INDEX_NVM_DTC18*/VALID,1,STS_IDLE}, {/*INDEX_NVM_DTC19*/VALID,1,STS_IDLE}, {/*INDEX_NVM_DTC20*/VALID,1,STS_IDLE}, {/*INDEX_NVM_DTC21*/VALID,1,STS_IDLE}, {/*INDEX_NVM_DTC22*/VALID,1,STS_IDLE}, {/*INDEX_NVM_DTC23*/VALID,1,STS_IDLE}, {/*INDEX_NVM_DTC24*/VALID,1,STS_IDLE}, {/*INDEX_NVM_DTC25*/VALID,1,STS_IDLE}, {/*INDEX_NVM_DTC26*/VALID,1,STS_IDLE}, {/*INDEX_NVM_DTC27*/VALID,1,STS_IDLE}, {/*INDEX_NVM_DTC28*/VALID,1,STS_IDLE}, {/*INDEX_NVM_DTC29*/VALID,1,STS_IDLE}, {/*INDEX_NVM_DTC30*/VALID,1,STS_IDLE}, {/*INDEX_NVM_DTC31*/VALID,1,STS_IDLE}, {/*INDEX_NVM_DTC32*/VALID,1,STS_IDLE}, {/*INDEX_NVM_DTC33*/VALID,1,STS_IDLE}, {/*INDEX_NVM_DTC34*/VALID,1,STS_IDLE}, {/*INDEX_NVM_DTC35*/VALID,1,STS_IDLE}, {/*INDEX_NVM_DTC36*/VALID,1,STS_IDLE}, {/*INDEX_NVM_DTC37*/VALID,1,STS_IDLE}, {/*INDEX_NVM_DTC38*/VALID,1,STS_IDLE}, {/*INDEX_NVM_DTC39*/VALID,1,STS_IDLE}, {/*INDEX_NVM_SNAPSHORT01*/VALID,1,STS_IDLE}, {/*INDEX_NVM_SNAPSHORT02*/VALID,1,STS_IDLE}, {/*INDEX_NVM_SNAPSHORT03*/VALID,1,STS_IDLE}, {/*INDEX_NVM_SNAPSHORT04*/VALID,1,STS_IDLE}, {/*INDEX_NVM_SNAPSHORT05*/VALID,1,STS_IDLE}, {/*INDEX_NVM_SNAPSHORT06*/VALID,1,STS_IDLE}, {/*INDEX_NVM_SNAPSHORT07*/VALID,1,STS_IDLE}, {/*INDEX_NVM_SNAPSHORT08*/VALID,1,STS_IDLE}, {/*INDEX_NVM_SNAPSHORT09*/VALID,1,STS_IDLE}, {/*INDEX_NVM_SNAPSHORT10*/VALID,1,STS_IDLE}, {/*INDEX_NVM_B102*/VALID,1,STS_IDLE}, {/*INDEX_NVM_B111*/VALID,1,STS_IDLE}, {/*INDEX_NVM_E102*/VALID,1,STS_IDLE}, {/*INDEX_NVM_E103*/VALID,1,STS_IDLE}, {/*INDEX_NVM_E104*/VALID,1,STS_IDLE}, {/*INDEX_NVM_E105*/VALID,1,STS_IDLE}, {/*INDEX_NVM_Y_SIAODOPRIY*/VALID,1,STS_IDLE}, {/*INDEX_NVM_K_COMPAREFUEL*/VALID,1,STS_IDLE}, {/*INDEX_NVM_K_DISPLAYFUEL*/VALID,1,STS_IDLE}, {/*INDEX_NVM_K_RANGETOEMPTY*/VALID,1,STS_IDLE}, {/*INDEX_NVM_K_FULLFUELCOMSUMPTION*/VALID,1,STS_IDLE}, {/*INDEX_NVM_K_RECENTFUELCONSUMPTION*/VALID,1,STS_IDLE}, {/*INDEX_NVM_K_ODOMETERSUM*/VALID,1,STS_IDLE}, {/*INDEX_NVM_K_FUELSUM*/VALID,1,STS_IDLE}, {/*INDEX_NVM_Y_LASTDISTANCECNT*/VALID,1,STS_IDLE}, {/*INDEX_NVM_ODO0*/VALID,1,STS_IDLE}, {/*INDEX_NVM_ODO1*/VALID,1,STS_IDLE}, {/*INDEX_NVM_ODO2*/VALID,1,STS_IDLE}, {/*INDEX_NVM_ODO3*/VALID,1,STS_IDLE}, {/*INDEX_NVM_ODO4*/VALID,1,STS_IDLE}, {/*INDEX_NVM_Y_ANGLEOFFSET*/VALID,1,STS_IDLE}, {/*INDEX_NVM_ESUM_FUEL*/VALID,1,STS_IDLE}, {/*INDEX_NVM_ESUM2_FUEL*/VALID,1,STS_IDLE}, {/*INDEX_NVM_WRT_181B*/VALID,1,STS_IDLE}, {/*INDEX_NVM_WRT_181C*/VALID,1,STS_IDLE}, {/*INDEX_NVM_SAFAIL_CNT*/VALID,1,STS_IDLE}, {/*INDEX_NVM_WRT_1890*/VALID,1,STS_IDLE}, {/*INDEX_NVM_B112*/VALID,1,STS_IDLE}, {/*INDEX_NVM_RUNKEEP*/VALID,1,STS_IDLE},  };  const NVMWriteMatrix_ST nvm_WriteMatrix[INDEX_NVM_ALL]= { {/*INDEX_NVM_NONE*/ADDR_SYS_PAGE0 + 0X00, nvm_Data.page0.buf, 0, 0}, {/*INDEX_NVM_AF00*/ADDR_SYS_PAGE0 + 0X00, nvm_Data.page0.buf, BYTEOFFSET_1, NVM_SYS0_AF00_LEN}, {/*INDEX_NVM_AF01*/ADDR_SYS_PAGE0 + 0X00, nvm_Data.page0.buf, NVM_SYS0_AF00_LEN + 0, NVM_SYS0_AF01_LEN}, {/*INDEX_NVM_AF02*/ADDR_SYS_PAGE0 + 0X00, nvm_Data.page0.buf, NVM_SYS0_AF01_LEN + NVM_SYS0_AF00_LEN, NVM_SYS0_AF02_LEN}, {/*INDEX_NVM_AF03*/ADDR_SYS_PAGE0 + 0X10, nvm_Data.page1.buf, BYTEOFFSET_1, NVM_SYS1_AF03_LEN}, {/*INDEX_NVM_D101*/ADDR_SYS_PAGE0 + 0X10, nvm_Data.page1.buf, NVM_SYS1_AF03_LEN + 0, NVM_SYS1_D101_LEN},  {/*INDEX_NVM_F100*/0X00E0, nvm_Data.logist.page0.buf,5, NVM_LOGIST_F100_LEN}, {/*INDEX_NVM_F110*/0X00F0, nvm_Data.logist.page1.buf,0, NVM_LOGIST_F110_LEN}, {/*INDEX_NVM_F111*/0X0100, nvm_Data.logist.flow1.buf[0],6, NVM_LOGIST_F111_LEN},/* LYY @ ATTENTION PLS THIS ID OCCUPY 2 PAGES*/ {/*INDEX_NVM_F112*/0X0110, nvm_Data.logist.flow1.buf[1],6, NVM_LOGIST_F112_LEN}, /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr LYY @ ATTENTION PLS THIS ID OCCUPY 2 PAGES*/ {/*INDEX_NVM_F113*/0X0120, nvm_Data.logist.flow1.buf[2],6, NVM_LOGIST_F113_LEN},/* LYY @ ATTENTION PLS THIS ID OCCUPY 2 PAGES*/ {/*INDEX_NVM_F114*/0X0130, nvm_Data.logist.flow1.buf[3],6,NVM_LOGIST_F113_LEN},/* LYY @ ATTENTION PLS THIS ID OCCUPY 2 PAGES*/ {/*INDEX_NVM_F115*/0X0140, nvm_Data.logist.flow1.buf[4],6, NVM_LOGIST_F115_LEN},/* LYY @ ATTENTION PLS THIS ID OCCUPY 2 PAGES*/ {/*INDEX_NVM_F116*/0X0150, nvm_Data.logist.flow1.buf[5],6, NVM_LOGIST_F116_LEN},/* LYY @ ATTENTION PLS THIS ID OCCUPY 2 PAGES*/ {/*INDEX_NVM_F117*/0X0160, nvm_Data.logist.flow1.buf[6],6, NVM_LOGIST_F117_LEN},/* LYY @ ATTENTION PLS THIS ID OCCUPY 2 PAGES*/ {/*INDEX_NVM_F118*/0X0170, nvm_Data.logist.flow1.buf[7],6, NVM_LOGIST_F118_LEN},/* LYY @ ATTENTION PLS THIS ID OCCUPY 2 PAGES*/ {/*INDEX_NVM_F119*/0X0180, nvm_Data.logist.flow1.buf[8],6, NVM_LOGIST_F119_LEN},/* LYY @ ATTENTION PLS THIS ID OCCUPY 2 PAGES*/ {/*INDEX_NVM_F11A*/0X0190, nvm_Data.logist.flow1.buf[9],6, NVM_LOGIST_F11A_LEN},/* LYY @ ATTENTION PLS THIS ID OCCUPY 2 PAGES*/ {/*INDEX_NVM_F11B*/0X01A0, nvm_Data.logist.flow1.buf[10],6, NVM_LOGIST_F11B_LEN},/* LYY @ ATTENTION PLS THIS ID OCCUPY 2 PAGES*/ {/*INDEX_NVM_F11C*/0X01B0, nvm_Data.logist.flow1.buf[11],6, NVM_LOGIST_F11C_LEN},/* LYY @ ATTENTION PLS THIS ID OCCUPY 2 PAGES*/ {/*INDEX_NVM_F11D*/0X01C0, nvm_Data.logist.flow1.buf[12],6, NVM_LOGIST_F11D_LEN},/* LYY @ ATTENTION PLS THIS ID OCCUPY 2 PAGES*/ {/*INDEX_NVM_F11E*/0X01D0, nvm_Data.logist.flow1.buf[13],6, NVM_LOGIST_F11F_LEN},/* LYY @ ATTENTION PLS THIS ID OCCUPY 2 PAGES*/ {/*INDEX_NVM_F11F*/0X01E0, nvm_Data.logist.flow1.buf[14],6, NVM_LOGIST_F11F_LEN},/* LYY @ ATTENTION PLS THIS ID OCCUPY 2 PAGES*/ {/*INDEX_NVM_F120*/0X01F0, nvm_Data.logist.flow1.buf[15],6, NVM_LOGIST_F120_LEN},/* LYY @ ATTENTION PLS THIS ID OCCUPY 2 PAGES*/ {/*INDEX_NVM_F121*/0X0200, nvm_Data.logist.flow1.buf[16],6, NVM_LOGIST_F121_LEN},/* LYY @ ATTENTION PLS THIS ID OCCUPY 2 PAGES*/  /*reserve 6 bytes*/ {/*INDEX_NVM_F187*/0X0220, nvm_Data.logist.flow2.buf[0],0,NVM_LOGIST_F187_LEN}, {/*INDEX_NVM_F18A*/0X0220, nvm_Data.logist.flow2.buf[0],5,NVM_LOGIST_F18A_LEN}, {/*INDEX_NVM_F18B*/0X0220, nvm_Data.logist.flow2.buf[0],10,NVM_LOGIST_F18B_LEN}, {/*INDEX_NVM_F18C*/0X0220, nvm_Data.logist.flow2.buf[0],13,NVM_LOGIST_F18C_LEN},/* LYY @ ATTENTION PLS THIS ID OCCUPY 2 PAGES*/ {/*INDEX_NVM_F190*/0X0230, nvm_Data.logist.flow2.buf[1],13,NVM_LOGIST_F190_LEN},/* LYY @ ATTENTION PLS THIS ID OCCUPY 2 PAGES*/ {/*INDEX_NVM_F191*/0X0240, nvm_Data.logist.flow2.buf[2],14,NVM_LOGIST_F191_LEN},/* LYY @ ATTENTION PLS THIS ID OCCUPY 2 PAGES*/ {/*INDEX_NVM_F192*/0X0250, nvm_Data.logist.flow2.buf[3],3,NVM_LOGIST_F192_LEN}, {/*INDEX_NVM_F198*/0X0250, nvm_Data.logist.flow2.buf[3],13,NVM_LOGIST_F198_LEN}, {/*INDEX_NVM_F1A8*/0X0260, nvm_Data.logist.flow2.buf[4],8,NVM_LOGIST_F1A8_LEN}, {/*INDEX_NVM_F1A9*/0X0270, nvm_Data.logist.flow2.buf[5],12,NVM_LOGIST_F1A9_LEN},/* LYY @ ATTENTION PLS THIS ID OCCUPY 2 PAGES*/ {/*INDEX_NVM_F1AA*/0X0280, nvm_Data.logist.flow2.buf[6],1,NVM_LOGIST_F1AA_LEN}, {/*INDEX_NVM_AFFC*/0x0280, nvm_Data.logist.flow2.buf[6],6,NVM_FBL_AFFC_LEN}, {/*INDEX_NVM_AFFD*/0x0280, nvm_Data.logist.flow2.buf[6],8,NVM_FBL_AFFD_LEN}, {/*INDEX_NVM_AFFE*/0x0280, nvm_Data.logist.flow2.buf[6],9,NVM_FBL_AFFE_LEN}, {/*INDEX_NVM_AFFF*/0x0280, nvm_Data.logist.flow2.buf[6],10,NVM_FBL_AFFF_LEN}, {/*INDEX_NVM_ISPFLG*/0x02a0,nvm_Data.logist.flow2.buf[8],11,NVM_FBL_AFFF_LEN},  /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr others no need to write ,will ignore*/ {/*INDEX_NVM_C111*/ADDR_CONFIG_PAGE0 + 0X00, nvm_Data.config.page0.page, BYTEOFFSET_1, NVM_CFG_LEN_8}, {/*INDEX_NVM_C112*/ADDR_CONFIG_PAGE0 + 0X00, nvm_Data.config.page0.page, NVM_CFG_LEN_8 + 0, NVM_CFG_LEN_8}, {/*INDEX_NVM_C113*/ADDR_CONFIG_PAGE0 + 0X10, nvm_Data.config.page1.page, BYTEOFFSET_1 , NVM_CFG_LEN_8}, {/*INDEX_NVM_C121*/ADDR_CONFIG_PAGE0 + 0X10, nvm_Data.config.page1.page, NVM_CFG_LEN_8 + 0, NVM_CFG_LEN_4}, {/*INDEX_NVM_C122*/ADDR_CONFIG_PAGE0 + 0X10, nvm_Data.config.page1.page, NVM_CFG_LEN_8 + NVM_CFG_LEN_4, NVM_CFG_LEN_4}, {/*INDEX_NVM_C131*/ADDR_CONFIG_PAGE0 + 0X20, nvm_Data.config.page2.page, BYTEOFFSET_1 ,NVM_CFG_LEN_4}, {/*INDEX_NVM_C141*/ADDR_CONFIG_PAGE0 + 0X20, nvm_Data.config.page2.page, NVM_CFG_LEN_8 + 0, NVM_CFG_LEN_8}, {/*INDEX_NVM_C151*/ADDR_CONFIG_PAGE0 + 0X30, nvm_Data.config.page3.page, BYTEOFFSET_1, NVM_CFG_LEN_8}, {/*INDEX_NVM_C164*/ADDR_CONFIG_PAGE0 + 0X30, nvm_Data.config.page3.page, NVM_CFG_LEN_8 + 0, NVM_CFG_LEN_8}, {/*INDEX_NVM_C165*/ADDR_CONFIG_PAGE0 + 0X40, nvm_Data.config.page4.page, BYTEOFFSET_1, NVM_CFG_LEN_8}, {/*INDEX_NVM_C166*/ADDR_CONFIG_PAGE0 + 0X40, nvm_Data.config.page4.page, NVM_CFG_LEN_8 + 0, NVM_CFG_LEN_8}, {/*INDEX_NVM_C167*/ADDR_CONFIG_PAGE0 + 0X50, nvm_Data.config.page5.page, BYTEOFFSET_1, NVM_CFG_LEN_8}, {/*INDEX_NVM_C171*/ADDR_CONFIG_PAGE0 + 0X50, nvm_Data.config.page5.page, NVM_CFG_LEN_8 + 0, NVM_CFG_LEN_8}, {/*INDEX_NVM_C172*/ADDR_CONFIG_PAGE0 + 0X60, nvm_Data.config.page6.page, BYTEOFFSET_1, NVM_CFG_LEN_4}, {/*INDEX_NVM_C181*/ADDR_CONFIG_PAGE0 + 0X60, nvm_Data.config.page6.page, NVM_CFG_LEN_8 + 0, NVM_CFG_LEN_8}, {/*INDEX_NVM_C182*/ADDR_CONFIG_PAGE0 + 0X70, nvm_Data.config.page7.page, BYTEOFFSET_1, NVM_CFG_LEN_8}, {/*INDEX_NVM_C191*/ADDR_CONFIG_PAGE0 + 0X70, nvm_Data.config.page7.page, NVM_CFG_LEN_8 + 0, NVM_CFG_LEN_8}, {/*INDEX_NVM_C192*/ADDR_CONFIG_PAGE0 + 0X80, nvm_Data.config.page8.page, BYTEOFFSET_1, NVM_CFG_LEN_8}, {/*INDEX_NVM_C1A1*/ADDR_CONFIG_PAGE0 + 0X80, nvm_Data.config.page8.page, NVM_CFG_LEN_8 + 0, NVM_CFG_LEN_8}, {/*INDEX_NVM_C1B1*/ADDR_CONFIG_PAGE0 + 0X90, nvm_Data.config.page9.page, BYTEOFFSET_1, NVM_CFG_LEN_8}, {/*INDEX_NVM_C1B2*/ADDR_CONFIG_PAGE0 + 0X90, nvm_Data.config.page9.page, NVM_CFG_LEN_8 + 0, NVM_CFG_LEN_8}, {/*INDEX_NVM_C1C1*/ADDR_CONFIG_PAGE0 + 0XA0, nvm_Data.config.page10.page, BYTEOFFSET_1, NVM_CFG_LEN_8}, {/*INDEX_NVM_C1C2*/ADDR_CONFIG_PAGE0 + 0XA0, nvm_Data.config.page10.page, NVM_CFG_LEN_8 + 0, NVM_CFG_LEN_8}, {/*INDEX_NVM_C1C3*/ADDR_CONFIG_PAGE0 + 0XB0, nvm_Data.config.page11.page, BYTEOFFSET_1, NVM_CFG_LEN_8}, {/*INDEX_NVM_C1C4*/ADDR_CONFIG_PAGE0 + 0XB0, nvm_Data.config.page11.page, NVM_CFG_LEN_8 + 0, NVM_CFG_LEN_8}, {/*INDEX_NVM_C1C5*/ADDR_CONFIG_PAGE0 + 0XC0, nvm_Data.config.page12.page, BYTEOFFSET_1, NVM_CFG_LEN_8}, {/*INDEX_NVM_C1C6*/ADDR_CONFIG_PAGE0 + 0XC0, nvm_Data.config.page12.page, NVM_CFG_LEN_8 + 0, NVM_CFG_LEN_8}, {/*INDEX_NVM_C1C7*/ADDR_CONFIG_PAGE0 + 0XD0, nvm_Data.config.page13.page, BYTEOFFSET_1, NVM_CFG_LEN_8}, {/*INDEX_NVM_C1C8*/ADDR_CONFIG_PAGE0 + 0XD0, nvm_Data.config.page13.page, NVM_CFG_LEN_8 + 0, NVM_CFG_LEN_8}, {/*INDEX_NVM_C1D1*/ADDR_CONFIG_PAGE0 + 0XE0, nvm_Data.config.page14.page, BYTEOFFSET_1, NVM_CFG_LEN_8}, {/*INDEX_NVM_C1E1*/ADDR_CONFIG_PAGE0 + 0XE0, nvm_Data.config.page14.page, NVM_CFG_LEN_8 + 0, NVM_CFG_LEN_8}, {/*INDEX_NVM_C1E2*/ADDR_CONFIG_PAGE0 + 0XF0, nvm_Data.config.page15.page, BYTEOFFSET_1, NVM_CFG_LEN_8},  {/*INDEX_NVM_0100*/ADDR_DTC_PAGE0, nvm_Data.dtc.page0.buf, 0, 16}, {/*INDEX_NVM_DTC01*/ADDR_DTC_PAGE0 + 0X10, nvm_Data.dtc.page1.buf, 0, NVM_CFG_LEN_8}, {/*INDEX_NVM_DTC02*/ADDR_DTC_PAGE0 + 0X10, nvm_Data.dtc.page1.buf, 8, NVM_CFG_LEN_8}, {/*INDEX_NVM_DTC03*/ADDR_DTC_PAGE0 + 0X20, nvm_Data.dtc.page2.buf, 0, NVM_CFG_LEN_8}, {/*INDEX_NVM_DTC04*/ADDR_DTC_PAGE0 + 0X20, nvm_Data.dtc.page2.buf, 8, NVM_CFG_LEN_8}, {/*INDEX_NVM_DTC05*/ADDR_DTC_PAGE0 + 0X30, nvm_Data.dtc.page3.buf, 0, NVM_CFG_LEN_8}, {/*INDEX_NVM_DTC06*/ADDR_DTC_PAGE0 + 0X30, nvm_Data.dtc.page3.buf, 8, NVM_CFG_LEN_8}, {/*INDEX_NVM_DTC07*/ADDR_DTC_PAGE0 + 0X40, nvm_Data.dtc.page4.buf,0, NVM_CFG_LEN_8}, {/*INDEX_NVM_DTC08*/ADDR_DTC_PAGE0 + 0X40, nvm_Data.dtc.page4.buf, 8, NVM_CFG_LEN_8}, {/*INDEX_NVM_DTC09*/ADDR_DTC_PAGE0 + 0X50, nvm_Data.dtc.page5.buf, 0, NVM_CFG_LEN_8}, {/*INDEX_NVM_DTC10*/ADDR_DTC_PAGE0 + 0X50, nvm_Data.dtc.page5.buf, 8, NVM_CFG_LEN_8}, {/*INDEX_NVM_DTC11*/ADDR_DTC_PAGE0 + 0X60, nvm_Data.dtc.page6.buf, 0, NVM_CFG_LEN_8}, {/*INDEX_NVM_DTC12*/ADDR_DTC_PAGE0 + 0X60, nvm_Data.dtc.page6.buf, 8, NVM_CFG_LEN_8}, {/*INDEX_NVM_DTC13*/ADDR_DTC_PAGE0 + 0X70, nvm_Data.dtc.page7.buf, 0, NVM_CFG_LEN_8}, {/*INDEX_NVM_DTC14*/ADDR_DTC_PAGE0 + 0X70, nvm_Data.dtc.page7.buf, 8, NVM_CFG_LEN_8}, {/*INDEX_NVM_DTC15*/ADDR_DTC_PAGE0 + 0X80, nvm_Data.dtc.page8.buf,0, NVM_CFG_LEN_8}, {/*INDEX_NVM_DTC16*/ADDR_DTC_PAGE0 + 0X80, nvm_Data.dtc.page8.buf,8, NVM_CFG_LEN_8}, {/*INDEX_NVM_DTC17*/ADDR_DTC_PAGE0 + 0X90, nvm_Data.dtc.page9.buf,0, NVM_CFG_LEN_8}, {/*INDEX_NVM_DTC18*/ADDR_DTC_PAGE0 + 0X90, nvm_Data.dtc.page9.buf,8, NVM_CFG_LEN_8}, {/*INDEX_NVM_DTC19*/ADDR_DTC_PAGE0 + 0XA0, nvm_Data.dtc.page10.buf,0, NVM_CFG_LEN_8}, {/*INDEX_NVM_DTC20*/ADDR_DTC_PAGE0 + 0XA0, nvm_Data.dtc.page10.buf, 8, NVM_CFG_LEN_8}, {/*INDEX_NVM_DTC21*/ADDR_DTC_PAGE0 + 0XB0,nvm_Data.dtc.page11.buf, 0, NVM_CFG_LEN_8}, {/*INDEX_NVM_DTC22*/ADDR_DTC_PAGE0 + 0XB0, nvm_Data.dtc.page11.buf,8, NVM_CFG_LEN_8}, {/*INDEX_NVM_DTC23*/ADDR_DTC_PAGE0 + 0XC0, nvm_Data.dtc.page12.buf, 0, NVM_CFG_LEN_8}, {/*INDEX_NVM_DTC24*/ADDR_DTC_PAGE0 + 0XC0, nvm_Data.dtc.page12.buf, 8, NVM_CFG_LEN_8}, {/*INDEX_NVM_DTC25*/ADDR_DTC_PAGE0 + 0XD0, nvm_Data.dtc.page13.buf, 0, NVM_CFG_LEN_8}, {/*INDEX_NVM_DTC26*/ADDR_DTC_PAGE0 + 0XD0, nvm_Data.dtc.page13.buf, 8, NVM_CFG_LEN_8}, {/*INDEX_NVM_DTC27*/ADDR_DTC_PAGE0 + 0XE0, nvm_Data.dtc.page14.buf, 0, NVM_CFG_LEN_8}, {/*INDEX_NVM_DTC28*/ADDR_DTC_PAGE0 + 0XE0, nvm_Data.dtc.page14.buf, 8, NVM_CFG_LEN_8}, {/*INDEX_NVM_DTC29*/ADDR_DTC_PAGE0 + 0XF0, nvm_Data.dtc.page15.buf, 0, NVM_CFG_LEN_8}, {/*INDEX_NVM_DTC30*/ADDR_DTC_PAGE0 + 0XF0, nvm_Data.dtc.page15.buf, 8, NVM_CFG_LEN_8}, {/*INDEX_NVM_DTC31*/ADDR_DTC_PAGE0 + 0X100, nvm_Data.dtc.page16.buf,0, NVM_CFG_LEN_8}, {/*INDEX_NVM_DTC32*/ADDR_DTC_PAGE0 + 0X100, nvm_Data.dtc.page16.buf,8, NVM_CFG_LEN_8}, {/*INDEX_NVM_DTC33*/ADDR_DTC_PAGE0 + 0X110, nvm_Data.dtc.page17.buf, 0, NVM_CFG_LEN_8}, {/*INDEX_NVM_DTC34*/ADDR_DTC_PAGE0 + 0X120, nvm_Data.dtc.page18.buf, 0, NVM_CFG_LEN_8}, {/*INDEX_NVM_DTC35*/ADDR_DTC_PAGE0 + 0X130,nvm_Data.dtc.page19.buf, 0, NVM_CFG_LEN_8}, {/*INDEX_NVM_DTC36*/ADDR_DTC_PAGE0 + 0X140, nvm_Data.dtc.page20.buf, 0, NVM_CFG_LEN_8}, {/*INDEX_NVM_DTC37*/ADDR_DTC_PAGE0 + 0X150, nvm_Data.dtc.page21.buf, 0, NVM_CFG_LEN_8}, {/*INDEX_NVM_DTC38*/ADDR_DTC_PAGE0 + 0X160, nvm_Data.dtc.page22.buf, 0, NVM_CFG_LEN_8}, {/*INDEX_NVM_DTC39*/ADDR_DTC_PAGE0 + 0X170, nvm_Data.dtc.page23.buf, 0, NVM_CFG_LEN_8},  {/*INDEX_NVM_SNAPSHORT01*/ADDR_SNAPSHOT_PAGE0 + 0X00, nvm_Data.snapshort[0].buf, 0,32}, {/*INDEX_NVM_SNAPSHORT02*/ADDR_SNAPSHOT_PAGE0 + 0X20,nvm_Data.snapshort[1].buf, 0,32}, {/*INDEX_NVM_SNAPSHORT03*/ADDR_SNAPSHOT_PAGE0 + 0X40, nvm_Data.snapshort[2].buf, 0,32}, {/*INDEX_NVM_SNAPSHORT04*/ADDR_SNAPSHOT_PAGE0 + 0X60, nvm_Data.snapshort[3].buf, 0,32}, {/*INDEX_NVM_SNAPSHORT05*/ADDR_SNAPSHOT_PAGE0 + 0X80, nvm_Data.snapshort[4].buf, 0,32}, {/*INDEX_NVM_SNAPSHORT06*/ADDR_SNAPSHOT_PAGE0 + 0Xa0, nvm_Data.snapshort[5].buf, 0,32}, {/*INDEX_NVM_SNAPSHORT07*/ADDR_SNAPSHOT_PAGE0 + 0Xc0,nvm_Data.snapshort[6].buf, 0,32}, {/*INDEX_NVM_SNAPSHORT08*/ADDR_SNAPSHOT_PAGE0 + 0Xe0, nvm_Data.snapshort[7].buf, 0,32}, {/*INDEX_NVM_SNAPSHORT09*/ADDR_SNAPSHOT_PAGE0 + 0X100, nvm_Data.snapshort[8].buf, 0,32}, {/*INDEX_NVM_SNAPSHORT10*/ADDR_SNAPSHOT_PAGE0 + 0X120, nvm_Data.snapshort[9].buf, 0,32},  {/*INDEX_NVM_B102*/ADDR_FUNCTION_PAGE0 + 0x00, nvm_Data.function.page0.buf, 0, NVM_FUN_LEN_3}, {/*INDEX_NVM_B111*/ADDR_FUNCTION_PAGE0 + 0x00, nvm_Data.function.page0.buf, 3, NVM_FUN_LEN_3}, {/*INDEX_NVM_E102*/ADDR_FUNCTION_PAGE0 + 0x00, nvm_Data.function.page0.buf,6, NVM_FUN_LEN_2}, {/*INDEX_NVM_E103*/ADDR_FUNCTION_PAGE0 + 0x00, nvm_Data.function.page0.buf,8, NVM_FUN_LEN_1}, {/*INDEX_NVM_E104*/ADDR_FUNCTION_PAGE0 + 0x00, nvm_Data.function.page0.buf,9, NVM_FUN_LEN_2}, {/*INDEX_NVM_E105*/ADDR_FUNCTION_PAGE0 + 0x00, nvm_Data.function.page0.buf,11, NVM_FUN_LEN_1}, {/*INDEX_NVM_Y_SIAODOPRIY*/ADDR_FUNCTION_PAGE0 + 0x00,nvm_Data.function.page0.buf,12,NVM_FUN_LEN_3}, {/*INDEX_NVM_K_COMPAREFUEL*/ADDR_FUNCTION_PAGE0 + 0x10,nvm_Data.function.page1.buf,0, NVM_FUN_LEN_2}, {/*INDEX_NVM_K_DISPLAYFUEL*/ADDR_FUNCTION_PAGE0 + 0x10,nvm_Data.function.page1.buf,2, NVM_FUN_LEN_2}, {/*INDEX_NVM_K_RANGETOEMPTY*/ADDR_FUNCTION_PAGE0 + 0x10, nvm_Data.function.page1.buf,4, NVM_FUN_LEN_4}, {/*INDEX_NVM_K_FULLFUELCOMSUMPTION*/ADDR_FUNCTION_PAGE0 + 0x10, nvm_Data.function.page1.buf, 8, NVM_FUN_LEN_1}, {/*INDEX_NVM_K_RECENTFUELCONSUMPTION*/ADDR_FUNCTION_PAGE0 + 0x10, nvm_Data.function.page1.buf,9, NVM_FUN_LEN_1}, {/*INDEX_NVM_K_ODOMETERSUM*/ADDR_FUNCTION_PAGE0 + 0x10, nvm_Data.function.page1.buf, 10, NVM_FUN_LEN_1}, {/*INDEX_NVM_K_FUELSUM*/ADDR_FUNCTION_PAGE0 + 0x10, nvm_Data.function.page1.buf, 11, NVM_FUN_LEN_2}, {/*INDEX_NVM_Y_LASTDISTANCECNT*/ ADDR_FUNCTION_PAGE0 + 0x10, nvm_Data.function.page1.buf, 13, NVM_FUN_LEN_2}, {/*INDEX_NVM_ODO0*/ADDR_FUNCTION_PAGE0 + 0x20, nvm_Data.function.odo[0].buf, 0, NVM_FUN_LEN_4}, {/*INDEX_NVM_ODO1*/ADDR_FUNCTION_PAGE0 + 0x30, nvm_Data.function.odo[1].buf, 0, NVM_FUN_LEN_4}, {/*INDEX_NVM_ODO2*/ADDR_FUNCTION_PAGE0 + 0x40, nvm_Data.function.odo[2].buf, 0, NVM_FUN_LEN_4}, {/*INDEX_NVM_ODO3*/ADDR_FUNCTION_PAGE0 + 0x50, nvm_Data.function.odo[3].buf, 0, NVM_FUN_LEN_4}, {/*INDEX_NVM_ODO4*/ADDR_FUNCTION_PAGE0 + 0x60, nvm_Data.function.odo[4].buf, 0, NVM_FUN_LEN_4}, {/*INDEX_NVM_Y_ANGLEOFFSET*/ADDR_FUNCTION_PAGE0 + 0x70, nvm_Data.function.angle.buf, 0, NVM_FUN_LEN_2}, {/*INDEX_NVM_ESUM_FUEL*/ADDR_FUNCTION_PAGE0 + 0x70, nvm_Data.function.angle.buf, 2, 4}, {/*INDEX_NVM_ESUM2_FUEL*/ADDR_FUNCTION_PAGE0 + 0x70, nvm_Data.function.angle.buf, 6, 4}, {/*INDEX_NVM_WRT_181B*/ADDR_FUNCTION_PAGE0 + 0x70, nvm_Data.function.angle.buf, 10, 1}, {/*INDEX_NVM_WRT_181C*/ADDR_FUNCTION_PAGE0 + 0x70, nvm_Data.function.angle.buf, 11, 1}, {/*INDEX_NVM_SAFAIL_CNT*/ADDR_FUNCTION_PAGE0 + 0x70, nvm_Data.function.angle.buf, 12, 1}, {/*INDEX_NVM_WRT_1890*/ADDR_FUNCTION_PAGE0 + 0x70, nvm_Data.function.angle.buf, 14, 1}, {/*INDEX_NVM_B112*/ADDR_FUNCTION_PAGE0 + 0x80, nvm_Data.function.page8.buf, 0, 1}, {/*INDEX_NVM_RUNKEEP*/ADDR_FUNCTION_PAGE0 + 0x80, nvm_Data.function.page8.buf, 1, 1},  };  /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Private static functions declare */ static U8 nvm_Write(NVMKeyBlock_ENUM index); static U8 nvm_Update(NVMKeyBlock_ENUM index, PU8 pRes, U8 size);  static U8 nvm_SYS_GetPage0(NVMKeyBlock_ENUM index, PU8 pRes, U8 size); static U8 nvm_SYS_GetPage1(NVMKeyBlock_ENUM index, PU8 pRes, U8 size);  static U8 nvm_CFG_GetPage0(NVMKeyBlock_ENUM index, PU8 pRes, U8 size); static U8 nvm_CFG_GetPage1(NVMKeyBlock_ENUM index, PU8 pRes, U8 size); static U8 nvm_CFG_GetPage2(NVMKeyBlock_ENUM index, PU8 pRes, U8 size); static U8 nvm_CFG_GetPage3(NVMKeyBlock_ENUM index, PU8 pRes, U8 size); static U8 nvm_CFG_GetPage4(NVMKeyBlock_ENUM index, PU8 pRes, U8 size); static U8 nvm_CFG_GetPage5(NVMKeyBlock_ENUM index, PU8 pRes, U8 size); static U8 nvm_CFG_GetPage6(NVMKeyBlock_ENUM index, PU8 pRes, U8 size); static U8 nvm_CFG_GetPage7(NVMKeyBlock_ENUM index, PU8 pRes, U8 size); static U8 nvm_CFG_GetPage8(NVMKeyBlock_ENUM index, PU8 pRes, U8 size); static U8 nvm_CFG_GetPage9(NVMKeyBlock_ENUM index, PU8 pRes, U8 size); static U8 nvm_CFG_GetPage10(NVMKeyBlock_ENUM index, PU8 pRes, U8 size); static U8 nvm_CFG_GetPage11(NVMKeyBlock_ENUM index, PU8 pRes, U8 size); static U8 nvm_CFG_GetPage12(NVMKeyBlock_ENUM index, PU8 pRes, U8 size); static U8 nvm_CFG_GetPage13(NVMKeyBlock_ENUM index, PU8 pRes, U8 size); static U8 nvm_CFG_GetPage14(NVMKeyBlock_ENUM index, PU8 pRes, U8 size); static U8 nvm_CFG_GetPage15(NVMKeyBlock_ENUM index, PU8 pRes, U8 size);   static U8 nvm_Function_GetPage0(NVMKeyBlock_ENUM index, PU8 pRes, U8 size); static U8 nvm_Function_GetPage1(NVMKeyBlock_ENUM index, PU8 pRes, U8 size); static U8 nvm_Function_GetPageODO(NVMKeyBlock_ENUM index, PU8 pRes, U8 size); static U8 nvm_Function_GetPage7(NVMKeyBlock_ENUM index, PU8 pRes, U8 size); static U8 nvm_Function_GetPage8(NVMKeyBlock_ENUM index, PU8 pRes, U8 size); static U8 nvm_CalCheckSum(PU8 pRes, U8 size);  #endif /*------------------end of file----------------------------*/  /*=========================================================================== nvm.c nvm_cfg.h nvm_info.inc nvm_private.h nvm_public.h File Revision History(bottom to top:first revision to last revision) *============================================================================ nvm.c nvm_cfg.h nvm_info.inc nvm_private.h nvm_public.h $Log:$ * nvm.c nvm_cfg.h nvm_info.inc nvm_private.h nvm_public.h Rev: Userid: Date: Description *-------- ---------- --------- ------------------------------ * nvm.c nvm_cfg.h nvm_info.inc nvm_private.h nvm_public.h V1.0 Xuenian.Feng 2016-12-1 Initial * *===========================================================================*/
