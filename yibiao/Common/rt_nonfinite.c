/*
 * File: rt_nonfinite.c
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

/*
 * Abstract:
 *      Function to intialize non-finites,
 *      (Inf, NaN and -Inf).
 */
#include "rt_nonfinite.h"
#include "rtGetNaN.h"
#include "rtGetInf.h"

DBL rtInf;
DBL rtMinusInf;
DBL rtNaN;
real32_T rtInfF;
real32_T rtMinusInfF;
real32_T rtNaNF;

/*
 * Initialize the rtInf, rtMinusInf, and rtNaN needed by the
 * generated code. NaN is initialized as non-signaling. Assumes IEEE.
 */
void rt_InitInfAndNaN(size_t realSize)
{
  (void) (realSize);
  rtNaN = rtGetNaN();
  rtNaNF = rtGetNaNF();
  rtInf = rtGetInf();
  rtInfF = rtGetInfF();
  rtMinusInf = rtGetMinusInf();
  rtMinusInfF = rtGetMinusInfF();
}

/* Test if value is infinite */
BOOL rtIsInf(DBL value)
{
  return (BOOL)((value==rtInf || value==rtMinusInf) ? 1U : 0U);
}

/* Test if single-precision value is infinite */
BOOL rtIsInfF(real32_T value)
{
  return (BOOL)(((value)==rtInfF || (value)==rtMinusInfF) ? 1U : 0U);
}

/* Test if value is not a number */
BOOL rtIsNaN(DBL value)
{
  return (BOOL)((value!=value) ? 1U : 0U);
}

/* Test if single-precision value is not a number */
BOOL rtIsNaNF(real32_T value)
{
  return (BOOL)(((value!=value) ? 1U : 0U));
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
