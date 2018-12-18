/bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr r_gpio_isr.c r_gpio_main.c PROJECT : GPIO driver FILE : $Id: r_gpio_main.c 7402 2016-01-27 15:43:39Z florian.zimmermann $ ============================================================================ DESCRIPTION Driver for GPIO macro ============================================================================ C O P Y R I G H T ============================================================================ Copyright (c) 2013 - 2014 by Renesas Electronics (Europe) GmbH. Arcadiastrasse 10 D-40472 Duesseldorf Germany All rights reserved. ============================================================================ Purpose: only for testing, not for mass production DISCLAIMER LICENSEE has read, understood and accepted the terms and conditions defined in the license agreement, especially the usage rights. In any case, it is LICENSEE's responsibility to make sure that any user of the software complies with the terms and conditions of the signed license agreement. SAMPLE CODE is not part of the licensed software, as such it must not be used in mass-production applications. It can only be used for evaluation and demonstration purposes at customer's premises listed in the signed license agreement. r_gpio_isr.c r_gpio_main.c */ /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Macro description GPIO functions Set/reset read pin Configure and activcate external portpin interrupts */ /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Section: Includes */ #include "r_typedefs.h" #include "r_gpio_api.h" #include "r_gpio_sys.h" /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Section: Local Functions */ /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Section: Global Functions */ /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Function: R_GPIO_Init See: r_gpio_api.h for details */ void R_GPIO_Init(void) { } /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Function: R_GPIO_DeInit See: r_gpio_api.h for details */ void R_GPIO_DeInit(void) { } /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Function: R_GPIO_PinRead See: r_gpio_api.h for details */ uint8_t R_GPIO_PinRead(int32_t Port, uint8_t Pin) { return R_SYS_GPIO_GetPin(Port, Pin); } /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Function: R_GPIO_PinDirection See: r_gpio_api.h for details */ void R_GPIO_PinDirection(int32_t Port, uint8_t Pin, uint8_t Dir) { R_SYS_GPIO_PinDirection(Port, Pin, Dir); } /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Function: R_GPIO_R_GPIO_WritePin See: r_gpio_api.h for details */ void R_GPIO_WritePin(int32_t Port, uint8_t Pin, uint8_t Value) { R_SYS_GPIO_SetPin(Port, Pin, Value); } /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Function: R_GPIO_TogglePin See: r_gpio_api.h for details */ void R_GPIO_TogglePin(int32_t Port, uint8_t Pin) { R_SYS_GPIO_InvPin(Port, Pin); } /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Function: R_GPIO_PortRead See: r_gpio_api.h for details */ uint16_t R_GPIO_PortRead(int32_t Port) { return R_SYS_GPIO_GetPort(Port); } /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Function: R_GPIO_WritePort See: r_gpio_api.h for details */ void R_GPIO_WritePort(int32_t Port, uint16_t Mask, uint16_t Value) { R_SYS_GPIO_WritePort(Port, Mask, Value); } /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Function: R_GPIO_TogglePort See: r_gpio_api.h for details */ void R_GPIO_TogglePort(int32_t Port, uint16_t Mask) { R_SYS_GPIO_InvPort(Port); } /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Function: R_GPIO_IOResetBuffer See: r_gpio_api.h for details */ void R_GPIO_IOReset(uint8_t SetRelease) { R_SYS_GPIO_IOReset(SetRelease); }
