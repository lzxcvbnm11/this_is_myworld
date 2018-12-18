#ifndef HMI_APPLICATION_DATA_C
#define HMI_APPLICATION_DATA_C	


#if HMI_STATIC_FILL_PAGES_NUMBER>0

/*Static Fill coordinate  */
 static HMI_FILL_RECT_STR CONST DISPLAY_SEGMENT_ROM hmi_fills_static_xy_rect [ ]=
{
};
/*StaticFILL width,heigh,colour  */
 static HMI_FILL_PAGE_STR CONST DISPLAY_SEGMENT_ROM hmi_fills_static_prop_table[ ]=
{
};
 static HMI_CONTAINER_STR CONST DISPLAY_SEGMENT_ROM hmi_static_fill_container_table[]=
{
};
#endif
#if HMI_DYN_FILL_PAGES_NUMBER>0
/*Dynamic Fill coordinate  */
 static HMI_FILL_RECT_STR DISPLAY_SEGMENT_RAM hmi_fills_dyn_xy_rect[ ]=
{
};
 static HMI_CONTAINER_STR CONST DISPLAY_SEGMENT_ROM hmi_dyn_fill_container_table[]=
{
};
/*Dynamic FILL width,heigh,colour  */
 static HMI_FILL_PAGE_STR DISPLAY_SEGMENT_RAM hmi_fills_dyn_prop_table[ ]=
{
};
#endif
#if HMI_STATIC_GFILL_NUMBER>0

/*Static Fill coordinate  */
 static HMI_FILL_RECT_STR CONST DISPLAY_SEGMENT_ROM hmi_gradient_sxy_fill_rect [ ]=
{
};
 static HMI_CONTAINER_STR CONST DISPLAY_SEGMENT_ROM hmi_static_gfill_container_table[]=
{
};
/*Static GFILL width,heigh,colour  */
 static HMI_GRADIENT_FILL_STR CONST DISPLAY_SEGMENT_ROM hmi_gradient_sxy_fill_table[]=
{
};
#endif
#if HMI_DYN_GFILL_NUMBER>0
/*Dynamic Fill coordinate  */
 static HMI_FILL_RECT_STR DISPLAY_SEGMENT_RAM hmi_gradient_dxy_fill_rect[ ]=
{
};
 static HMI_CONTAINER_STR CONST DISPLAY_SEGMENT_ROM hmi_dyn_gfill_container_table[]=
{
};
/*Dynamic GFILL width,heigh,colour  */
 static HMI_GRADIENT_FILL_STR DISPLAY_SEGMENT_RAM hmi_gradient_dxy_fill_table[]=
{
};
#endif
#if HMI_SXY_CUBE_NUMBER>0
/*Static Cube coordinate ,width,angel,bump,face  */
 static HMI_CUBE_STR CONST DISPLAY_SEGMENT_ROM hmi_cubes_static_xy_rect[ ]=
{
};
/*Static Cube coordinate ,width,angel,bump,face  */
 static HMI_CONTAINER_STR CONST DISPLAY_SEGMENT_ROM hmi_cubes_static_xy_face[ ]=
{
};
/*Static Cube 3d ,axis  */
 static HMI_CUBE_AXIS_PROP CONST DISPLAY_SEGMENT_ROM hmi_cubes_static_xy_axis[ ]=
{
};
#endif
#if HMI_DXY_CUBE_NUMBER>0
/*Dynamic Cube coordinate,width,angel,bump,face  */
 static HMI_CUBE_STR DISPLAY_SEGMENT_RAM hmi_cubes_dyn_xy_rect[ ]=
{
};
/*Dynamic Cube coordinate,width,angel,bump,face  */
 static HMI_CONTAINER_STR CONST DISPLAY_SEGMENT_ROM hmi_cubes_dyn_xy_face[ ]=
{
};
/*Dynamic Cube 3d,axis  */
 static HMI_CUBE_AXIS_PROP CONST DISPLAY_SEGMENT_ROM hmi_cubes_dyn_xy_axis[ ]=
{
};
#endif
#if HMI_SXY_BITMAPS_NUMBER>0
/*Static bmp static coordinate   */
 static HMI_RECT_ALPHA_ANGEL_STR CONST DISPLAY_SEGMENT_ROM hmi_bmp_static_xy_rect[ ]=
{
	/* hmi_bg_image */
	 {0,0,832,480,255,0,0}
	/* hmi_led1_image */
	,{0,0,48,32,255,0,0}
	/* hmi_led2_image */
	,{0,0,48,32,255,0,0}
	/* hmi_led3_image */
	,{0,0,48,32,255,0,0}
	/* hmi_led4_image */
	,{0,5,72,24,255,0,0}
	/* hmi_led5_image */
	,{0,0,42,42,255,0,0}
	/* hmi_needle_bg */
	,{258,18,285,285,255,0,0}
};
/*Static image static xy Prop    */
 static HMI_BITMAP_STR CONST DISPLAY_SEGMENT_ROM hmi_bmp_static_xy_prop_table[]=
{
	/* hmi_bg_image */
	 {832,480,hmi_bg_image_no_loss,HMI_BG_IMAGE_NO_LOSS_LEN}
	/* hmi_led1_image */
	,{48,32,hmi_led1_image_none,HMI_LED1_IMAGE_NONE_LEN}
	/* hmi_led2_image */
	,{48,32,hmi_led2_image_none,HMI_LED2_IMAGE_NONE_LEN}
	/* hmi_led3_image */
	,{48,32,hmi_led3_image_none,HMI_LED3_IMAGE_NONE_LEN}
	/* hmi_led4_image */
	,{72,24,hmi_led4_image_none,HMI_LED4_IMAGE_NONE_LEN}
	/* hmi_led5_image */
	,{42,42,hmi_led5_image_none,HMI_LED5_IMAGE_NONE_LEN}
	/* hmi_needle_bg */
	,{285,285,hmi_needle_bg_none,HMI_NEEDLE_BG_NONE_LEN}
};
 static HMI_CONTAINER_STR CONST DISPLAY_SEGMENT_ROM hmi_sxy_bitmap_container_table[]=
{
	/* bg_image */
	 {{0,NULL}}
	/* led1_image */
	,{{0,NULL}}
	/* led2_image */
	,{{0,NULL}}
	/* led3_image */
	,{{0,NULL}}
	/* led4_image */
	,{{0,NULL}}
	/* led5_image */
	,{{0,NULL}}
	/* needle_bg */
	,{{0,NULL}}
};
 static HMI_IMAGE_ATTR_STR CONST DISPLAY_SEGMENT_ROM hmi_sxy_bitmap_attr_table[ ]=
{
	/* HMI_BG_IMAGE */
	 {HMI_IMAGE_COMPRESS_NO_LOSS}
	/* HMI_LED1_IMAGE */
	,{HMI_ALPHA_IMAGE_FLAG|HMI_IMAGE_COMPRESS_NONE}
	/* HMI_LED2_IMAGE */
	,{HMI_ALPHA_IMAGE_FLAG|HMI_IMAGE_COMPRESS_NONE}
	/* HMI_LED3_IMAGE */
	,{HMI_ALPHA_IMAGE_FLAG|HMI_IMAGE_COMPRESS_NONE}
	/* HMI_LED4_IMAGE */
	,{HMI_ALPHA_IMAGE_FLAG|HMI_IMAGE_COMPRESS_NONE}
	/* HMI_LED5_IMAGE */
	,{HMI_ALPHA_IMAGE_FLAG|HMI_IMAGE_COMPRESS_NONE}
	/* HMI_NEEDLE_BG */
	,{HMI_ALPHA_IMAGE_FLAG|HMI_IMAGE_COMPRESS_NONE}
};
#endif
#if HMI_DXY_BITMAPS_NUMBER>0
/*Static bmp dyamic coordinate   */
 static HMI_RECT_ALPHA_ANGEL_STR DISPLAY_SEGMENT_RAM hmi_bmp_dyn_xy_rect[ ]=
{
	/* hmi_needle_image */
	 {396,210,8,40,255,35,0}
};
/*Static image dyn xy Prop    */
 static HMI_BITMAP_STR CONST DISPLAY_SEGMENT_ROM hmi_bmp_dyn_xy_prop_table[]=
{
	/* hmi_needle_image */
	 {8,40,hmi_needle_image_none_swizzer,HMI_NEEDLE_IMAGE_NONE_SWIZZER_LEN}
};
 static HMI_CONTAINER_STR CONST DISPLAY_SEGMENT_ROM hmi_dxy_bitmap_container_table[]=
{
	/* needle_image */
	 {{0,NULL}}
};
#if HMI_DXY_ROTATION_BITMAPS_NUMBER>0
 static HMI_ROTATION_STR CONST DISPLAY_SEGMENT_ROM hmi_dxy_bitmap_rotation[]=
{
	 {400,161}
};
#endif

#if HMI_DXY_ROTATION_BITMAPS_NUMBER>0
 static HMI_ROTATION_TRAIL_STR CONST DISPLAY_SEGMENT_ROM hmi_dxy_bitmap_rotation_trail[]=
{
	 {FALSE,HMI_NB_ELEMENTS,TRUE,0,120}
};
#endif

 static HMI_IMAGE_ATTR_STR CONST DISPLAY_SEGMENT_ROM hmi_dxy_bitmap_attr_table[ ]=
{
	/* HMI_NEEDLE_IMAGE */
	 {HMI_ALPHA_IMAGE_FLAG|HMI_IMAGE_COMPRESS_NONE|HMI_ROTATION_IMAGE_FLAG}
};
#endif
#if HMI_SXY_IMAGELIST_NUMBER>0
/*Static bmp list static coordinate   */
 static HMI_RECT_ALPHA_STR CONST DISPLAY_SEGMENT_ROM hmi_sxy_imagelist_rect[]=
{
};
/*Static bmp list index    */
 static HMI_RANGE_STR DISPLAY_SEGMENT_RAM hmi_sxy_imagelist_index[]=
{
};
/*Static image list static xy Prop    */
 static HMI_IMAGE_LIST_STR CONST DISPLAY_SEGMENT_ROM hmi_sxy_imagelist_table[]=
{
};
 static HMI_CONTAINER_STR CONST DISPLAY_SEGMENT_ROM hmi_sxy_imagelist_container_table[]=
{
};
 static HMI_IMAGE_ATTR_STR CONST DISPLAY_SEGMENT_ROM hmi_sxy_imglist_attr_table[ ]=
{
};
#endif
#if HMI_DXY_IMAGELIST_NUMBER>0
/*Static bmp list dyamic coordinate   */
 static HMI_RECT_ALPHA_STR DISPLAY_SEGMENT_RAM hmi_dxy_imagelist_rect[]=
{
};
/*Dyn bmp list index    */
 static HMI_RANGE_STR DISPLAY_SEGMENT_RAM hmi_dxy_imagelist_index[]=
{
};
/*Static image list dyn xy Prop    */
 static HMI_IMAGE_LIST_STR CONST DISPLAY_SEGMENT_ROM hmi_dxy_imagelist_table[]=
{
};
 static HMI_CONTAINER_STR CONST DISPLAY_SEGMENT_ROM hmi_dxy_imagelist_container_table[]=
{
};
 static HMI_IMAGE_ATTR_STR CONST DISPLAY_SEGMENT_ROM hmi_dxy_imglist_attr_table[ ]=
{
};
#endif
#if HMI_SXY_SCROLLBAR_NUMBER>0
/*Static scrollbar static coordinate   */
 static HMI_RECT_ALPHA_STR CONST DISPLAY_SEGMENT_ROM hmi_sxy_scrollbar_rect[]=
{
};
/*Static scrollbar Prop    */
 static HMI_SCROLL_BAR_STR CONST DISPLAY_SEGMENT_ROM hmi_sxy_scrollbar_table[ ]=
{
};
/*Static scrollbar index    */
 static HMI_RANGE_STR DISPLAY_SEGMENT_RAM hmi_sxy_scrollbar_cur_range[]=
{
	 0
};
 static HMI_CONTAINER_STR CONST DISPLAY_SEGMENT_ROM hmi_sxy_scrollbar_container_table[]=
{
};
 static HMI_IMAGE_ATTR_STR CONST DISPLAY_SEGMENT_ROM hmi_sxy_scrollbar_attr_table[ ]=
{
};
#endif
#if HMI_DXY_SCROLLBAR_NUMBER>0
/*Static scrollbar dyamic coordinate   */
 static HMI_RECT_ALPHA_STR DISPLAY_SEGMENT_RAM hmi_dxy_scrollbar_rect[]=
{
};
/*Static scrollbar Prop    */
 static HMI_SCROLL_BAR_STR CONST DISPLAY_SEGMENT_ROM hmi_dxy_scrollbar_table[ ]=
{
};
/*Dyn scrollbar index    */
 static HMI_RANGE_STR DISPLAY_SEGMENT_RAM hmi_dxy_scrollbar_cur_range[]=
{
	 0
};
 static HMI_CONTAINER_STR CONST DISPLAY_SEGMENT_ROM hmi_dxy_scrollbar_container_table[]=
{
};
 static HMI_IMAGE_ATTR_STR CONST DISPLAY_SEGMENT_ROM hmi_dxy_scrollbar_attr_table[ ]=
{
};
#endif
#if HMI_SXY_BUTTON_NUMBER>0
/*Static Button static coordinate   */
 static HMI_RECT_ALPHA_STR CONST DISPLAY_SEGMENT_ROM hmi_sxy_button_rect[]=
{
};
/*Static button static xy Prop    */
 static HMI_BUTTON_STR CONST DISPLAY_SEGMENT_ROM hmi_sxy_button_table[]=
{
};
/*Static button static xy index    */
 static HMI_RANGE_STR DISPLAY_SEGMENT_RAM hmi_sxy_button_press_status[]=
{
};
 static HMI_CONTAINER_STR CONST DISPLAY_SEGMENT_ROM hmi_sxy_button_container_table[]=
{
};
 static HMI_IMAGE_ATTR_STR CONST DISPLAY_SEGMENT_ROM hmi_sxy_button_attr_table[ ]=
{
};
#endif
#if HMI_DXY_BUTTON_NUMBER>0
/*Static Button dyamic coordinate   */
 static HMI_RECT_ALPHA_STR DISPLAY_SEGMENT_RAM hmi_dxy_button_rect[]=
{
};
/*Static button dyn xy Prop    */
 static HMI_BUTTON_STR CONST DISPLAY_SEGMENT_ROM hmi_dxy_button_table[]=
{
};
/*Static button dyn xy index    */
 static HMI_RANGE_STR DISPLAY_SEGMENT_RAM hmi_dxy_button_press_status[]=
{
};
 static HMI_CONTAINER_STR CONST DISPLAY_SEGMENT_ROM hmi_dxy_button_container_table[]=
{
};
 static HMI_IMAGE_ATTR_STR CONST DISPLAY_SEGMENT_ROM hmi_dxy_button_attr_table[ ]=
{
};
#endif
#if HMI_DYN_EDIT_TEXTS_NUMBER>0
/*Dynamic text string   */
 static HMI_CHAR_STR DISPLAY_SEGMENT_RAM hmi_edit_text_data[]=
{
	/* new_text3 */
	  0x4e0a,0x6d77,0x9a7b,0x5229,0x7535,0x5b50,0x6709,0x9650,0x516c,0x53f8,'\0'
	/* new_text4 */
	, 0x51,0x44,0x20,0x50,0x6c,0x75,0x73,0x20,0x5de5,0x5177,0x52,0x47,0x4c,0x5e73,0x53f0,0x6d4b,0x8bd5,0x00,0x00,0x00,'\0'
};
#if HMI_TEXT_MAX_SON_CNT>0
 static HMI_CONTAINER_STR CONST DISPLAY_SEGMENT_ROM hmi_edit_text_container_table[]=
{
	/* new_text3 */
	 {{0,NULL}}
	/* new_text4 */
	,{{0,NULL}}
};
#endif
/*Editable text info list   */
 static HMI_TEXT_PROP_STR CONST DISPLAY_SEGMENT_ROM hmi_edit_text_table[ ]=
{
	/* HMI_NEW_TEXT3 */
	 {(HMI_TEXT_PROP_ALIGN_LEFT|HMI_TEXT_PROP_DRAW_TRANSP),HMI_DEFAULT_FONT,10,&hmi_edit_text_data[0]}
	/* HMI_NEW_TEXT4 */
	,{(HMI_TEXT_PROP_ALIGN_LEFT|HMI_TEXT_PROP_DRAW_TRANSP),HMI_DEFAULT_FONT,20,&hmi_edit_text_data[11]}
};
#if HMI_EDIT_TEXT_DXY_DYN_FONT_NUM>0
 static U08 DISPLAY_SEGMENT_RAM hmi_edit_text_dxy_dyn_font_table[ ]=
{
};
#endif
#if HMI_EDIT_TEXT_SXY_DYN_FONT_NUM>0
 static U08 DISPLAY_SEGMENT_RAM hmi_edit_text_sxy_dyn_font_table[ ]=
{
};
#endif
#endif
#if HMI_DYN_EDIT_TEXTS_NUMBER-HMI_DYN_XY_EDIT_TEXTS_NUMBER>0
/*Editable text static property   */
 static HMI_TEXT_RECT_STR CONST DISPLAY_SEGMENT_ROM hmi_static_xy_edit_text_prop_table[ ]=
{
	/* hmi_new_text3 */
	 {{49,83,235,46},4294967295}
	/* hmi_new_text4 */
	,{{526,422,264,53},4294967295}
};
#endif
#if HMI_DYN_XY_EDIT_TEXTS_NUMBER>0
/*Editable text dynamic property   */
 static HMI_TEXT_RECT_STR DISPLAY_SEGMENT_RAM hmi_dyn_xy_edit_text_prop_table[ ]=
{
};
#endif
#if HMI_STATIC_TEXTS_NUMBER>0
#if HMI_UNEDIT_TEXTS_STATIC_XY_NUMBER>0
/*Uneditable text static property   */
 static HMI_TEXT_RECT_STR CONST DISPLAY_SEGMENT_ROM hmi_static_xy_unedit_text_prop_table[ ]=
{
};
#endif
#if HMI_UNEDIT_TEXTS_DYN_XY_NUMBER>0
/*text property   */
 static HMI_TEXT_RECT_STR DISPLAY_SEGMENT_RAM hmi_dyn_xy_unedit_text_prop_table[ ]=
{
};
#endif
/*uneditable text info list   */
 static HMI_TEXT_PROP_STR CONST DISPLAY_SEGMENT_ROM hmi_unedit_text_table[ ]=
{
};
#if HMI_TEXT_MAX_SON_CNT>0
 static HMI_CONTAINER_STR CONST DISPLAY_SEGMENT_ROM hmi_static_text_container_table[]=
{
};
#endif
#if HMI_UNEDIT_TEXT_DXY_DYN_FONT_NUM>0
 static U08 DISPLAY_SEGMENT_RAM hmi_unedit_text_dxy_dyn_font_table[ ]=
{
};
#endif
#if HMI_UNEDIT_TEXT_SXY_DYN_FONT_NUM>0
 static U08 DISPLAY_SEGMENT_RAM hmi_unedit_text_sxy_dyn_font_table[ ]=
{
};
#endif
#endif
#if HMI_DYN_CONTAINERS_NUMBER>0
/*Dynamic widget initial   */
 static HMI_DYN_CONTAINER_DATA_STR DISPLAY_SEGMENT_RAM hmi_dyn_container_table[ ]=
{
	/* hmi_led1_dyn_container */
	 HMI_LED1_CONTAINER
	/* hmi_led2_dyn_container */
	,HMI_LED2_CONTAINER
	/* hmi_led3_dyn_container */
	,HMI_LED3_CONTAINER
	/* hmi_led4_dyn_container */
	,HMI_LED4_CONTAINER
	/* hmi_led5_dyn_container */
	,HMI_LED5_CONTAINER
};
#endif
#if HMI_DXY_CONTAINERS_NUMBER>0
 static HMI_CONTAINER_STR CONST DISPLAY_SEGMENT_ROM hmi_dyn_xy_container_table[]=
{
};
/*Dynamic xy container coordinate  */
 static HMI_RECT_STR DISPLAY_SEGMENT_RAM hmi_dyn_xy_container_rect[]=
{
};
 static HMI_VIDEO_INFO_STR CONST DISPLAY_SEGMENT_ROM hmi_dxy_container_video_fmt[]=
{
};
 static BYTE DISPLAY_SEGMENT_RAM hmi_dxy_container_video_status[]=
{
};
#endif
#if HMI_SXY_CONTAINERS_NUMBER>0
 static HMI_OBJECT_PROP_STR CONST DISPLAY_SEGMENT_ROM hmi_bg_container_container[ ]=
{
	 HMI_BG_IMAGE
};
 static HMI_OBJECT_PROP_STR CONST DISPLAY_SEGMENT_ROM hmi_new_container3_container[ ]=
{
	 HMI_BG_IMAGE
};
 static HMI_OBJECT_PROP_STR CONST DISPLAY_SEGMENT_ROM hmi_sprite_container_container[ ]=
{
	 HMI_LED1_DYN_CONTAINER
	,HMI_LED2_DYN_CONTAINER
	,HMI_LED3_DYN_CONTAINER
	,HMI_LED4_DYN_CONTAINER
	,HMI_LED5_DYN_CONTAINER
};
 static HMI_OBJECT_PROP_STR CONST DISPLAY_SEGMENT_ROM hmi_led1_container_container[ ]=
{
	 HMI_LED1_IMAGE
};
 static HMI_OBJECT_PROP_STR CONST DISPLAY_SEGMENT_ROM hmi_led2_container_container[ ]=
{
	 HMI_LED2_IMAGE
};
 static HMI_OBJECT_PROP_STR CONST DISPLAY_SEGMENT_ROM hmi_led3_container_container[ ]=
{
	 HMI_LED3_IMAGE
};
 static HMI_OBJECT_PROP_STR CONST DISPLAY_SEGMENT_ROM hmi_led4_container_container[ ]=
{
	 HMI_LED4_IMAGE
};
 static HMI_OBJECT_PROP_STR CONST DISPLAY_SEGMENT_ROM hmi_led5_container_container[ ]=
{
	 HMI_LED5_IMAGE
};
 static HMI_OBJECT_PROP_STR CONST DISPLAY_SEGMENT_ROM hmi_needle_container_container[ ]=
{
	 HMI_NEEDLE_BG
	,HMI_NEEDLE_IMAGE
	,HMI_NEW_TEXT3
	,HMI_NEW_TEXT4
};
 static HMI_CONTAINER_STR CONST DISPLAY_SEGMENT_ROM hmi_sxy_container_table[]=
{
	/* bg_container */
	 {{1,hmi_bg_container_container}}
	/* new_container3 */
	,{{1,hmi_new_container3_container}}
	/* sprite_container */
	,{{5,hmi_sprite_container_container}}
	/* led1_container */
	,{{1,hmi_led1_container_container}}
	/* led2_container */
	,{{1,hmi_led2_container_container}}
	/* led3_container */
	,{{1,hmi_led3_container_container}}
	/* led4_container */
	,{{1,hmi_led4_container_container}}
	/* led5_container */
	,{{1,hmi_led5_container_container}}
	/* led_off_container */
	,{{0,NULL}}
	/* needle_container */
	,{{4,hmi_needle_container_container}}
};
/*Static xy container coordinate  */
 static HMI_RECT_STR CONST DISPLAY_SEGMENT_ROM hmi_static_container_rect[]=
{
	/* hmi_bg_container */
	 {0,0,800,480}
	/* hmi_new_container3 */
	,{0,0,420,420}
	/* hmi_sprite_container */
	,{10,20,600,45}
	/* hmi_led1_container */
	,{0,0,48,32}
	/* hmi_led2_container */
	,{70,0,48,32}
	/* hmi_led3_container */
	,{140,0,48,32}
	/* hmi_led4_container */
	,{210,0,72,24}
	/* hmi_led5_container */
	,{550,0,42,42}
	/* hmi_led_off_container */
	,{0,0,2,2}
	/* hmi_needle_container */
	,{0,0,800,480}
};
#endif
#if HMI_DXY_PAGES_NUMBER>0
/*Dynamic xy page coordinate  */
 static HMI_RECT_STR DISPLAY_SEGMENT_RAM hmi_dxy_page_rect[]=
{
};
#if HMI_VDXY_PAGES_NUMBER>0
/*Dynamic xy page video info  */
 static HMI_VIDEO_INFO_STR DISPLAY_SEGMENT_RAM hmi_dxy_page_video_fmt[]=
{
};
#endif
/*All page table info */
 static HMI_PAGE_TABLE_STR CONST DISPLAY_SEGMENT_ROM hmi_dxy_page_table[ ]=
{
};
#endif
#if HMI_SXY_PAGES_NUMBER>0
 static HMI_OBJECT_PROP_STR CONST DISPLAY_SEGMENT_ROM hmi_new_page3_container[ ]=
{
	 HMI_BG_CONTAINER
	,HMI_SPRITE_CONTAINER
	,HMI_NEEDLE_CONTAINER
};
/*Static xy page coordinate  */
 static HMI_RECT_STR CONST DISPLAY_SEGMENT_ROM hmi_sxy_page_rect[]=
{
	/* hmi_new_page3 */
	 {0,0,800,480}
};
#if HMI_VSXY_PAGES_NUMBER>0
/*Static xy page video info  */
 static HMI_VIDEO_INFO_STR CONST DISPLAY_SEGMENT_ROM hmi_sxy_page_video_fmt[]=
{
};
#endif
/*All page table info */
 static HMI_PAGE_TABLE_STR CONST DISPLAY_SEGMENT_ROM hmi_sxy_page_table[ ]=
{
	 {0,{3,hmi_new_page3_container}}
};
#endif
/*Layer info   */

#if HMI_ALL_LAYERS_NUMBER>0
 static HMI_LAYER_TABLE_STR CONST DISPLAY_SEGMENT_ROM hmi_layer_table[ ]=
{
#if HMI_LAYER_0_HIGHEST_PRIORITY>0
	 {HMI_LAYER_0_MAX_W_LENGTH,HMI_LAYER_0_MAX_H_LENGTH,HMI_LAYER_0_HIGHEST_PRIORITY}
#endif
};
#endif

#if HMI_ENABLE_BIN>0
#if HMI_SEGMENT_MAX>0
 static HMI_CONTAINER_STR CONST DISPLAY_SEGMENT_ROM hmi_seg_info_list[]=
{
};
#endif
#endif
#endif
