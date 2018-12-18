/bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr app_drw2dcpu app_menu app_tripcomp app_tutorial application.c application.h error.c error.h font.h font_data.h fonts fs_data.h hmi_manager.c hmi_manager.h img.c img.h img_data.h img_drw2d.c img_drw2d.h img_format.h main.c main.h mem_init.c mem_init.h sfma.c wm.c wm.h write.c write.h PROJECT : GRAPE_APP FILE : $Id: error.c 25427 2013-06-14 07:55:45Z nan.wang $ ============================================================================ DESCRIPTION Sample program for demonstration of the GFX features ============================================================================ C O P Y R I G H T ============================================================================ Copyright (c) 2014 by Renesas Electronics (Europe) GmbH. Arcadiastrasse 10 D-40472 Duesseldorf Germany All rights reserved. ============================================================================ Purpose: only for testing, not for mass production DISCLAIMER LICENSEE has read, understood and accepted the terms and conditions defined in the license agreement, especially the usage rights. In any case, it is LICENSEE's responsibility to make sure that any user of the software complies with the terms and conditions of the signed license agreement. SAMPLE CODE is not part of the licensed software, as such it must not be used in mass-production applications. It can only be used for evaluation and demonstration purposes at customer�s premises listed in the signed license agreement. app_drw2dcpu app_menu app_tripcomp app_tutorial application.c application.h error.c error.h font.h font_data.h fonts fs_data.h hmi_manager.c hmi_manager.h img.c img.h img_data.h img_drw2d.c img_drw2d.h img_format.h main.c main.h mem_init.c mem_init.h sfma.c wm.c wm.h write.c write.h app_drw2dcpu/ app_menu/ app_tripcomp/ app_tutorial/ fonts/ /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Title: Error Handler Module This is the application's error handler. app_drw2dcpu/ app_menu/ app_tripcomp/ app_tutorial/ fonts/ /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Section: Includes app_drw2dcpu/ app_menu/ app_tripcomp/ app_tutorial/ fonts/ #include "r_typedefs.h" /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Renesas basic types, e.g. uint32_t app_drw2dcpu/ app_menu/ app_tripcomp/ app_tutorial/ fonts/ #include "fw_clibal_api.h" #include "fw_osal_api.h" #include "error.h" /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Section: Global Functions Description see: <error.h> app_drw2dcpu/ app_menu/ app_tripcomp/ app_tutorial/ fonts/ /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Function: Error app_drw2dcpu/ app_menu/ app_tripcomp/ app_tutorial/ fonts/ void Error(int Err) { FW_CLIBAL_PrintF("ERROR (code = 0x%08x): Thread is now sleeping forever...\n", Err); while (Err) { FW_OSAL_ThreadSleep(100); } }