#ifndef HMI_RES_FONT_H
#define HMI_RES_FONT_H	

#define HMI_DEFAULT_FONT                                         (0)
#define HMI_PAGE_FONT                                            (1)
#define HMI_FNC_12_B                                             (2)
#define HMI_FNC_16                                               (3)
#define HMI_FNC_18                                               (4)
#define HMI_MMR_18                                               (5)
#define HMI_MMR_20                                               (6)
#define HMI_SPCIAL_FONT                                          (7)
#define HMI_FNC_12                                               (8)
#define HMI_MMR_16                                               (9)
#define HMI_FONT_SEARCH_MODE_TLUP                                (0x01)
#define HMI_FONT_SEARCH_MODE_DIRECT                              (0x02)
#define HMI_FONT_ENCODING_1BPP                                   (0x04)
#define HMI_FONT_ENCODING_2BPP                                   (0x08)
#define HMI_FONT_ENCODING_4BPP                                   (0x10)
#define HMI_FONT_ENCODING_8BPP                                   (0x20)
#define HMI_LINEAR_ENCODE_STR                                    (0)
#define HMI_BINARY_ENCODE_STR                                    (1)
#define HMI_HYBRID_ENCODE_STR                                    (2)
#define HMI_CHAR_SEARCH_MODE                                     (HMI_LINEAR_ENCODE_STR)

#define HMI_ALL_FONT_NUMBER                                      (10)
#define HMI_NB_DEFAULT_FONT_RANG                                 (2)
#define HMI_NB_PAGE_FONT_RANG                                    (2)
#define HMI_NB_FNC_12_B_RANG                                     (2)
#define HMI_NB_FNC_16_RANG                                       (2)
#define HMI_NB_FNC_18_RANG                                       (2)
#define HMI_NB_MMR_18_RANG                                       (2)
#define HMI_NB_MMR_20_RANG                                       (2)
#define HMI_NB_SPCIAL_FONT_RANG                                  (2)
#define HMI_NB_FNC_12_RANG                                       (2)
#define HMI_NB_MMR_16_RANG                                       (2)

extern HMI_FONT_STR CONST DISPLAY_SEGMENT_ROM hmi_font_table[];

#endif

