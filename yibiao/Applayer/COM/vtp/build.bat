@rem /* ******************************************************************* */
@rem /*                                                                     */
@rem /*                     Mentor Graphics Corporation                     */
@rem /*                         All rights reserved                         */
@rem /*                                                                     */
@rem /* ******************************************************************* */
@rem
@rem /*         File: build.bat                                             */
@rem /*  Description: BUILDs the Volcano 7 "hello world" application        */
@rem /*               GHS v. 6.1.4 / RH850D1L2                              */

@cls

@set VFLAGS=-V -DNO_NM_CALLBACK


@set APP=20170626-ly3-ZS12_P_IPK-V10
@SET V7EXE=.
@rem /* Produce: "v_fp.out" 						   */																		
%V7EXE%\v7cfg -l -t %VFLAGS% %APP%.fix %APP%.pri
pause
@rem /* Produce: "v_fn.out"                                                 */
%V7EXE%\v7cfg -t %VFLAGS% %APP%.fix %APP%.net
pause

@rem /* Produce:"v_gen.c" and "v_hand.h"                                    */
%V7EXE%\v7bnd %VFLAGS% -P %APP%.tgt
pause
@rem /* Produce: "nvram.c"
%V7EXE%\v7bnd %VFLAGS% -N %APP%.tgt
pause