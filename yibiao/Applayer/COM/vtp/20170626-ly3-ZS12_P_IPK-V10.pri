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
flag EcmNodeFlg { latches frame containing CCA; }
flag GearNodeFlg { latches frame containing TrShftLvrPos; }
flag GearDirNodeFlg { latches frame containing EcoDrvngDspStsGearSIS; }
flag TcmSotNodeFlg { latches frame containing TrNonEmsnRltdMalfA; }
flag BcmNodeFlg { latches frame containing BCMPwrMdHwdSta; }
flag EpbNodeFlg { latches frame containing EPBSysAudWrnngReq; }
flag EpsNodeFlg { latches frame containing StrgWhlAngSnsrCalSts; }
flag EsclNodeFlg { latches frame containing wake_network_ESCL; }
flag FicmNodeFlg { latches frame containing wake_network_FICM; }
flag FicmSotNodeFlg { latches frame containing MusSrcMd; }
flag ScsNodeFlg { latches frame containing AutoHoldSysSts; }
flag SdmNodeFlg { latches frame containing AirbagSysFltIndCmd; }
flag TcmNodeFlg { latches frame containing TrNonEmsnRltdMalfA; }
flag TpmsNodeFlg { latches frame containing wake_network_TPMS; }
flag TpmsSotFlg { latches frame containing TPMSAutoLoctnCm; }
flag FCSOTFlg { latches frame containing FuelCsump; }
flag PdcFlg { latches frame containing PDCSysSts_L; }
flag AcNodeFlg { latches frame containing wake_network_AC; }
flag OdoMonitor { latches frame containing DistRCAvgDrvn; }
flag diag_fun { latches frame containing DiagnosticFuncAddrReq; }
flag diag_phy { latches frame containing DiagnosticReqIPK; }
flag naviFlg  {latches frame containing NavDircn; }
