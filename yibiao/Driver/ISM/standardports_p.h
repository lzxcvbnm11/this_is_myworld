//============================================================================ // PROJECT = Any, using standard ports set // MODULE = $Source$ // VERSION = $Revision: 4594 $ // DATE = $Date: 2015-01-08 18:13:58 +0100 (Do, 08 Jan 2015) $ //============================================================================ // C O P Y R I G H T  //============================================================================ // Copyright (c) 2002 by NEC Electronics (Europe) GmbH. All rights reserved. // Kanzlerstrasse 2 // D-40472 Duesseldorf // Germany //============================================================================ //Purpose: Standard Port Driver Functions Include // //Warranty Disclaimer // //Because the Product(s) is licensed free of charge, there is no warranty  //of any kind whatsoever and expressly disclaimed and excluded by NEC,  //either expressed or implied, including but not limited to those for  //non-infringement of intellectual property, merchantability and/or  //fitness for the particular purpose.  //NEC shall not have any obligation to maintain, service or provide bug  //fixes for the supplied Product(s) and/or the Application. // //Each User is solely responsible for determining the appropriateness of  //using the Product(s) and assumes all risks associated with its exercise  //of rights under this Agreement, including, but not limited to the risks  //and costs of program errors, compliance with applicable laws, damage to  //or loss of data, programs or equipment, and unavailability or  //interruption of operations. // //Limitation of Liability // //In no event shall NEC be liable to the User for any incidental,  //consequential, indirect, or punitive damage (including but not limited  //to lost profits) regardless of whether such liability is based on breach  //of contract, tort, strict liability, breach of warranties, failure of  //essential purpose or otherwise and even if advised of the possibility of  //such damages. NEC shall not be liable for any services or products  //provided by third party vendors, developers or consultants identified or //referred to the User by NEC in connection with the Product(s) and/or the  //Application. // // // //============================================================================ // Environment: Devices: all featuring standard ports // Assembler: GHS MULTI 2000 // C-Compiler: GHS MULTI 2000 // Linker: GHS MULTI 2000 // Debugger: GHS MULTI 2000 //============================================================================ // // $Log$ // Revision 1.1 2003/12/11 14:17:55 liederr // Initial creation. // // //============================================================================  #ifndef _STANDARDPORTS_P_H #define _STANDARDPORTS_P_H   #define PORT_DIR_INPUT 1 /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Port Direction */ #define PORT_DIR_OUTPUT 0  #define PORT_MODE_IO 0 /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Port Mode Control */ #define PORT_MODE_PERIPHERAL 1  #define PORT_FUNCTION_NORMAL 0 /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Port Function Control */ #define PORT_FUNCTION_ALTLV0 1 #define PORT_FUNCTION_ALTLV1 2 #define PORT_FUNCTION_ALTLV2 3 #define PORT_FUNCTION_ALTLV3 4   //extern uint8_t PORT_GetStatus( uint16_t PortNumber_u16, // uint16_t BitSpecification_u16, // uint8_t* PortDirection_pu08, // uint8_t* PeripheralMode_pu08, // uint8_t* AlternateFunction_pu08 );  extern uint8_t PORT_Enable( uint16_t PortNumber_u16, uint16_t BitSpecification_u16, uint8_t PortDirection_u08, uint8_t PeripheralMode_u08, uint8_t AlternateFunction_u08 );  extern uint8_t PORT_Disable( uint16_t PortNumber_u16, uint16_t BitSpecification_u16 );  //extern uint8_t PORT_Write( uint16_t PortNumber_u16, // uint16_t PortData_u16 ); // //extern uint8_t PORT_Read( uint16_t PortNumber_u16, // uint16_t* PortData_pu16 );  #endif
