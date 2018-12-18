/* ************************************************************************ */
/*                                                                          */
/*                        Mentor Graphics Corporation                       */
/*                            All rights reserved                           */
/*                                                                          */
/* ************************************************************************ */

/*         File: 20161221-ly4-ZS12_PPV_IPK-V07.pri                                                  */
/*  Description: PRIVATE file for Volcano 7 hello world application.        */

private_file;
volcano version "7.20";

flag yytest { latches frame containing network_mode; }
flag crusrollcnt { latches frame containing CCSwStsAlvRC; }
flag tiprollcntPftr { latches frame containing PfTrTapUpDwnSwStsAlvRC; }
flag tiprollcntTrpf { latches frame containing TrPfShftPtrnSwAlvRC; }