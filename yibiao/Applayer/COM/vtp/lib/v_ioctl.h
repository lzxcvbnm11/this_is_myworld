/bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr nwm.a nwm_core.h v_core.h v_ioctl.h v_nwm.h v_rlin3.h v_rscan.h v_subbus.h v_target.h volcano.h volcano7.a */ /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr */ /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Mentor Graphics Corporation */ /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr All rights reserved */ /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr */ /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr nwm.a nwm_core.h v_core.h v_ioctl.h v_nwm.h v_rlin3.h v_rscan.h v_subbus.h v_target.h volcano.h volcano7.a */  /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr File: v_ioctl.h */ /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Author: MGC */ /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Description: IOCTL function related definitions */ /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr */  #ifndef __V_IOCTL_H__ #define __V_IOCTL_H__  /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr the following definitions define the core ioctl functions. */  #define V_IOCTL_CAN_CTRL_COMMON_BASE (0x00u) #define V_IOCTL_SUB_BUS_COMMON_BASE (0x20u) #define V_IOCTL_CAN_CTRL_SPECIFIC_BASE (0x30u) #define V_IOCTL_SUB_BUS_SPECIFIC_BASE (0x40u)  #define V_IOCTL_COMMON_SET_SLEEP (V_IOCTL_CAN_CTRL_COMMON_BASE) #define V_IOCTL_COMMON_SET_WAKE (V_IOCTL_CAN_CTRL_COMMON_BASE + 1u) #define V_IOCTL_COMMON_CHECK_SLEEP (V_IOCTL_CAN_CTRL_COMMON_BASE + 2u) #define V_IOCTL_COMMON_CHECK_BUSOFF (V_IOCTL_CAN_CTRL_COMMON_BASE + 3u) #define V_IOCTL_COMMON_CHECK_TX_WARN (V_IOCTL_CAN_CTRL_COMMON_BASE + 4u) #define V_IOCTL_COMMON_CHECK_TX_ERROR (V_IOCTL_CAN_CTRL_COMMON_BASE + 5u) #define V_IOCTL_COMMON_CHECK_RX_WARN (V_IOCTL_CAN_CTRL_COMMON_BASE + 6u) #define V_IOCTL_COMMON_CHECK_RX_ERROR (V_IOCTL_CAN_CTRL_COMMON_BASE + 7u) #define V_IOCTL_COMMON_TX_ERR_COUNT (V_IOCTL_CAN_CTRL_COMMON_BASE + 8u) #define V_IOCTL_COMMON_RX_ERR_COUNT (V_IOCTL_CAN_CTRL_COMMON_BASE + 9u) #define V_IOCTL_COMMON_BUSOFF_COUNTER (V_IOCTL_CAN_CTRL_COMMON_BASE + 10u) #define V_IOCTL_COMMON_CHECK_CONNECTED (V_IOCTL_CAN_CTRL_COMMON_BASE + 11u) #define V_IOCTL_COMMON_SET_LISTEN_ONLY_MODE (V_IOCTL_CAN_CTRL_COMMON_BASE + 12u) #define V_IOCTL_COMMON_SET_NORMAL_MODE (V_IOCTL_CAN_CTRL_COMMON_BASE + 13u) #define V_IOCTL_COMMON_CHECK_LISTEN_ONLY_MODE (V_IOCTL_CAN_CTRL_COMMON_BASE + 14u)  /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr Failed to change mode of CAN */ #define V_IOCTL_LOM_CHANGE_FAILURE (0x01u)  #endif /bin /cmd /dev /etc /git-bash.exe /git-cmd.exe /LICENSE.txt /mingw64 /proc /ReleaseNotes.html /tmp /unins000.dat /unins000.exe /unins000.msg /usr __V_IOCTL_H__ */
