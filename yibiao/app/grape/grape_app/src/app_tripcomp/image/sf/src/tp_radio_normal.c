#include "r_typedefs.h" #include "img_format.h"  static uint8_t fan_0.c fan_1.c fan_2.c fan_3.c fan_4.c fan_focus.c fan_select.c tp_bg.c tp_fuel_gauge.c tp_fuel_hand.c tp_Mic_Normal.c tp_Mic_Selected.c tp_radio_normal.c tp_radio_selected.c tp_Sync_Normal.c tp_Sync_Selected.c tp_volume_normal.c tp_volume_selected.c tp_warning_sign.c tp_Weather_Icon.c locImgPtr = (uint8_t*)0;  const Img_t Img_tp_radio_normal = { "tp_radio_normal.bin", 0, 38, 37, IMG_ARGB6666, IMG_ATTRIBUTE_USE_FROM_PERSISTENT_MEMORY, 0, 0, 0, &locImgPtr, 4218 };
