/*
 * File: rt_nonfinite.h
 *
 * Code generated for Simulink model 'FuelLevelAlgorithm_V2'.
 *
 * Model version                  : 1.310
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Mon Dec 11 13:32:48 2017
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Generic->32-bit Embedded Processor
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_rt_nonfinite_h_
#define RTW_HEADER_rt_nonfinite_h_
#include <stddef.h>
#include "rtwtypes.h"

extern DBL rtInf;
extern DBL rtMinusInf;
extern DBL rtNaN;
extern real32_T rtInfF;
extern real32_T rtMinusInfF;
extern real32_T rtNaNF;
extern void rt_InitInfAndNaN(size_t realSize);
extern BOOL rtIsInf(DBL value);
extern BOOL rtIsInfF(real32_T value);
extern BOOL rtIsNaN(DBL value);
extern BOOL rtIsNaNF(real32_T value);
typedef struct {
  struct {
    U32 wordH;
    U32 wordL;
  } words;
} BigEndianIEEEDouble;

typedef struct {
  struct {
    U32 wordL;
    U32 wordH;
  } words;
} LittleEndianIEEEDouble;

typedef struct {
  union {
    real32_T wordLreal;
    U32 wordLuint;
  } wordL;
} IEEESingle;

#endif                                 /* RTW_HEADER_rt_nonfinite_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
