#ifndef HMI_RES_FONT_C
#define HMI_RES_FONT_C	

#include "hmi_engine.h"
#include "hmi_res_font.h"
#include "hmi_bmp_font.c"
/*Font char property table   */
 static HMI_FONT_CHAR_PROP CONST DISPLAY_SEGMENT_ROM hmi_default_font_bitmap_prop[ ]=
{
	 {0,6,20,6,1,1,NULL}
	,{2,4,5,6,2,15,hmi_default_font_bitmap_33}
	,{1,6,5,7,6,5,hmi_default_font_bitmap_34}
	,{0,12,5,12,12,15,hmi_default_font_bitmap_35}
	,{1,11,4,12,9,18,hmi_default_font_bitmap_36}
	,{1,18,5,19,17,15,hmi_default_font_bitmap_37}
	,{1,13,5,14,13,15,hmi_default_font_bitmap_38}
	,{1,3,5,4,2,5,hmi_default_font_bitmap_39}
	,{1,6,5,7,5,19,hmi_default_font_bitmap_40}
	,{1,6,5,7,5,19,hmi_default_font_bitmap_41}
	,{0,8,5,8,8,6,hmi_default_font_bitmap_42}
	,{1,11,8,12,10,10,hmi_default_font_bitmap_43}
	,{2,4,18,6,2,5,hmi_default_font_bitmap_44}
	,{0,7,13,7,6,2,hmi_default_font_bitmap_45}
	,{2,4,18,6,2,2,hmi_default_font_bitmap_46}
	,{0,6,5,6,6,15,hmi_default_font_bitmap_47}
	,{1,11,5,12,10,15,hmi_default_font_bitmap_48}
	,{2,10,5,12,6,15,hmi_default_font_bitmap_49}
	,{1,11,5,12,10,15,hmi_default_font_bitmap_50}
	,{1,11,5,12,10,15,hmi_default_font_bitmap_51}
	,{1,11,5,12,10,15,hmi_default_font_bitmap_52}
	,{1,11,5,12,10,15,hmi_default_font_bitmap_53}
	,{1,11,5,12,10,15,hmi_default_font_bitmap_54}
	,{1,11,5,12,10,15,hmi_default_font_bitmap_55}
	,{1,11,5,12,10,15,hmi_default_font_bitmap_56}
	,{1,11,5,12,10,15,hmi_default_font_bitmap_57}
	,{2,4,9,6,2,11,hmi_default_font_bitmap_58}
	,{2,4,9,6,2,14,hmi_default_font_bitmap_59}
	,{1,11,7,12,10,11,hmi_default_font_bitmap_60}
	,{1,11,9,12,10,7,hmi_default_font_bitmap_61}
	,{1,11,7,12,10,11,hmi_default_font_bitmap_62}
	,{1,11,5,12,10,15,hmi_default_font_bitmap_63}
	,{1,20,5,21,19,19,hmi_default_font_bitmap_64}
	,{0,13,5,13,13,15,hmi_default_font_bitmap_65}
	,{2,12,5,14,11,15,hmi_default_font_bitmap_66}
	,{1,14,5,15,13,15,hmi_default_font_bitmap_67}
	,{2,13,5,15,12,15,hmi_default_font_bitmap_68}
	,{2,12,5,14,11,15,hmi_default_font_bitmap_69}
	,{2,11,5,13,10,15,hmi_default_font_bitmap_70}
	,{1,15,5,16,14,15,hmi_default_font_bitmap_71}
	,{1,13,5,14,12,15,hmi_default_font_bitmap_72}
	,{2,4,5,6,2,15,hmi_default_font_bitmap_73}
	,{1,10,5,11,8,15,hmi_default_font_bitmap_74}
	,{2,12,5,14,12,15,hmi_default_font_bitmap_75}
	,{2,10,5,12,9,15,hmi_default_font_bitmap_76}
	,{1,16,5,17,15,15,hmi_default_font_bitmap_77}
	,{1,13,5,14,12,15,hmi_default_font_bitmap_78}
	,{1,15,5,16,14,15,hmi_default_font_bitmap_79}
	,{2,12,5,14,11,15,hmi_default_font_bitmap_80}
	,{1,15,5,16,14,16,hmi_default_font_bitmap_81}
	,{2,13,5,15,12,15,hmi_default_font_bitmap_82}
	,{1,13,5,14,12,15,hmi_default_font_bitmap_83}
	,{0,12,5,12,12,15,hmi_default_font_bitmap_84}
	,{1,13,5,14,12,15,hmi_default_font_bitmap_85}
	,{0,13,5,13,13,15,hmi_default_font_bitmap_86}
	,{0,21,5,21,21,15,hmi_default_font_bitmap_87}
	,{0,14,5,14,14,15,hmi_default_font_bitmap_88}
	,{0,14,5,14,14,15,hmi_default_font_bitmap_89}
	,{0,13,5,13,12,15,hmi_default_font_bitmap_90}
	,{1,5,5,6,4,19,hmi_default_font_bitmap_91}
	,{0,6,5,6,6,15,hmi_default_font_bitmap_92}
	,{1,5,5,6,4,19,hmi_default_font_bitmap_93}
	,{0,8,5,8,8,8,hmi_default_font_bitmap_94}
	,{0,12,22,12,12,2,hmi_default_font_bitmap_95}
	,{1,6,5,7,3,3,hmi_default_font_bitmap_96}
	,{1,11,9,12,10,11,hmi_default_font_bitmap_97}
	,{1,10,5,11,9,15,hmi_default_font_bitmap_98}
	,{1,10,9,11,9,11,hmi_default_font_bitmap_99}
	,{1,10,5,11,9,15,hmi_default_font_bitmap_100}
	,{1,11,9,12,10,11,hmi_default_font_bitmap_101}
	,{0,6,5,6,7,15,hmi_default_font_bitmap_102}
	,{1,10,9,11,9,15,hmi_default_font_bitmap_103}
	,{1,10,5,11,9,15,hmi_default_font_bitmap_104}
	,{1,4,5,5,2,15,hmi_default_font_bitmap_105}
	,{-1,5,5,4,4,19,hmi_default_font_bitmap_106}
	,{1,9,5,10,9,15,hmi_default_font_bitmap_107}
	,{1,3,5,4,2,15,hmi_default_font_bitmap_108}
	,{1,15,9,16,14,11,hmi_default_font_bitmap_109}
	,{1,10,9,11,9,11,hmi_default_font_bitmap_110}
	,{1,11,9,12,10,11,hmi_default_font_bitmap_111}
	,{1,10,9,11,9,15,hmi_default_font_bitmap_112}
	,{1,10,9,11,9,15,hmi_default_font_bitmap_113}
	,{1,6,9,7,6,11,hmi_default_font_bitmap_114}
	,{1,10,9,11,9,11,hmi_default_font_bitmap_115}
	,{0,6,5,6,5,15,hmi_default_font_bitmap_116}
	,{1,10,9,11,9,11,hmi_default_font_bitmap_117}
	,{0,11,9,11,11,11,hmi_default_font_bitmap_118}
	,{-1,16,9,15,17,11,hmi_default_font_bitmap_119}
	,{0,10,9,10,10,11,hmi_default_font_bitmap_120}
	,{1,10,9,11,9,15,hmi_default_font_bitmap_121}
	,{0,9,9,9,9,11,hmi_default_font_bitmap_122}
	,{0,7,5,7,6,19,hmi_default_font_bitmap_123}
	,{2,4,5,6,2,20,hmi_default_font_bitmap_124}
	,{1,6,5,7,6,19,hmi_default_font_bitmap_125}
	,{1,11,11,12,10,4,hmi_default_font_bitmap_126}
};
/*Font char range   */
#if HMI_NB_DEFAULT_FONT_RANG>0
 static HMI_FONT_RANGE_STR CONST DISPLAY_SEGMENT_ROM hmi_default_font_bitmap_range[ ]=
{
	 {0x0020,HMI_FONT_ENCODING_1BPP|HMI_FONT_SEARCH_MODE_TLUP,&hmi_default_font_bitmap_prop[0]}
	,{0x007e,HMI_FONT_ENCODING_1BPP|HMI_FONT_SEARCH_MODE_DIRECT,&hmi_default_font_bitmap_prop[94]}
};
#endif
/*Font char table   */
#if HMI_ALL_FONT_NUMBER>0
 static HMI_FONT_STR CONST DISPLAY_SEGMENT_ROM hmi_font_table[ ]=
{
	 {2,21,hmi_default_font_bitmap_range}
};
#endif

#endif


