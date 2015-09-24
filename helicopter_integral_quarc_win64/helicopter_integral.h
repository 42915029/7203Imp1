/*
 * helicopter_integral.h
 *
 * Code generation for model "helicopter_integral".
 *
 * Model version              : 1.32
 * Simulink Coder version : 8.2 (R2012a) 29-Dec-2011
 * C source code generated on : Fri Sep 18 14:59:51 2015
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#ifndef RTW_HEADER_helicopter_integral_h_
#define RTW_HEADER_helicopter_integral_h_
#ifndef helicopter_integral_COMMON_INCLUDES_
# define helicopter_integral_COMMON_INCLUDES_
#include <math.h>
#include <float.h>
#include <string.h>
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "hil.h"
#include "quanser_messages.h"
#include "quanser_hid.h"
#include "quanser_memory.h"
#include "rt_nonfinite.h"
#include "quanser_extern.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include "rt_defines.h"
#include "rt_look.h"
#include "rt_look1d.h"
#endif                                 /* helicopter_integral_COMMON_INCLUDES_ */

#include "helicopter_integral_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->ModelData.blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->ModelData.blkStateChange = (val))
#endif

#ifndef rtmGetBlockIO
# define rtmGetBlockIO(rtm)            ()
#endif

#ifndef rtmSetBlockIO
# define rtmSetBlockIO(rtm, val)       ()
#endif

#ifndef rtmGetChecksums
# define rtmGetChecksums(rtm)          ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
# define rtmSetChecksums(rtm, val)     ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
# define rtmGetConstBlockIO(rtm)       ()
#endif

#ifndef rtmSetConstBlockIO
# define rtmSetConstBlockIO(rtm, val)  ()
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->ModelData.contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->ModelData.contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->ModelData.contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->ModelData.contStates = (val))
#endif

#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        ()
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)   ()
#endif

#ifndef rtmGetDefaultParam
# define rtmGetDefaultParam(rtm)       ()
#endif

#ifndef rtmSetDefaultParam
# define rtmSetDefaultParam(rtm, val)  ()
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->ModelData.derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->ModelData.derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetDirectFeedThrough
# define rtmGetDirectFeedThrough(rtm)  ((rtm)->Sizes.sysDirFeedThru)
#endif

#ifndef rtmSetDirectFeedThrough
# define rtmSetDirectFeedThrough(rtm, val) ((rtm)->Sizes.sysDirFeedThru = (val))
#endif

#ifndef rtmGetErrorStatusFlag
# define rtmGetErrorStatusFlag(rtm)    ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatusFlag
# define rtmSetErrorStatusFlag(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetFinalTime
# define rtmSetFinalTime(rtm, val)     ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetFirstInitCondFlag
# define rtmGetFirstInitCondFlag(rtm)  ()
#endif

#ifndef rtmSetFirstInitCondFlag
# define rtmSetFirstInitCondFlag(rtm, val) ()
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->ModelData.intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->ModelData.intgData = (val))
#endif

#ifndef rtmGetMdlRefGlobalTID
# define rtmGetMdlRefGlobalTID(rtm)    ()
#endif

#ifndef rtmSetMdlRefGlobalTID
# define rtmSetMdlRefGlobalTID(rtm, val) ()
#endif

#ifndef rtmGetMdlRefTriggerTID
# define rtmGetMdlRefTriggerTID(rtm)   ()
#endif

#ifndef rtmSetMdlRefTriggerTID
# define rtmSetMdlRefTriggerTID(rtm, val) ()
#endif

#ifndef rtmGetModelMappingInfo
# define rtmGetModelMappingInfo(rtm)   ((rtm)->SpecialInfo.mappingInfo)
#endif

#ifndef rtmSetModelMappingInfo
# define rtmSetModelMappingInfo(rtm, val) ((rtm)->SpecialInfo.mappingInfo = (val))
#endif

#ifndef rtmGetModelName
# define rtmGetModelName(rtm)          ((rtm)->modelName)
#endif

#ifndef rtmSetModelName
# define rtmSetModelName(rtm, val)     ((rtm)->modelName = (val))
#endif

#ifndef rtmGetNonInlinedSFcns
# define rtmGetNonInlinedSFcns(rtm)    ()
#endif

#ifndef rtmSetNonInlinedSFcns
# define rtmSetNonInlinedSFcns(rtm, val) ()
#endif

#ifndef rtmGetNumBlockIO
# define rtmGetNumBlockIO(rtm)         ((rtm)->Sizes.numBlockIO)
#endif

#ifndef rtmSetNumBlockIO
# define rtmSetNumBlockIO(rtm, val)    ((rtm)->Sizes.numBlockIO = (val))
#endif

#ifndef rtmGetNumBlockParams
# define rtmGetNumBlockParams(rtm)     ((rtm)->Sizes.numBlockPrms)
#endif

#ifndef rtmSetNumBlockParams
# define rtmSetNumBlockParams(rtm, val) ((rtm)->Sizes.numBlockPrms = (val))
#endif

#ifndef rtmGetNumBlocks
# define rtmGetNumBlocks(rtm)          ((rtm)->Sizes.numBlocks)
#endif

#ifndef rtmSetNumBlocks
# define rtmSetNumBlocks(rtm, val)     ((rtm)->Sizes.numBlocks = (val))
#endif

#ifndef rtmGetNumContStates
# define rtmGetNumContStates(rtm)      ((rtm)->Sizes.numContStates)
#endif

#ifndef rtmSetNumContStates
# define rtmSetNumContStates(rtm, val) ((rtm)->Sizes.numContStates = (val))
#endif

#ifndef rtmGetNumDWork
# define rtmGetNumDWork(rtm)           ((rtm)->Sizes.numDwork)
#endif

#ifndef rtmSetNumDWork
# define rtmSetNumDWork(rtm, val)      ((rtm)->Sizes.numDwork = (val))
#endif

#ifndef rtmGetNumInputPorts
# define rtmGetNumInputPorts(rtm)      ((rtm)->Sizes.numIports)
#endif

#ifndef rtmSetNumInputPorts
# define rtmSetNumInputPorts(rtm, val) ((rtm)->Sizes.numIports = (val))
#endif

#ifndef rtmGetNumNonSampledZCs
# define rtmGetNumNonSampledZCs(rtm)   ((rtm)->Sizes.numNonSampZCs)
#endif

#ifndef rtmSetNumNonSampledZCs
# define rtmSetNumNonSampledZCs(rtm, val) ((rtm)->Sizes.numNonSampZCs = (val))
#endif

#ifndef rtmGetNumOutputPorts
# define rtmGetNumOutputPorts(rtm)     ((rtm)->Sizes.numOports)
#endif

#ifndef rtmSetNumOutputPorts
# define rtmSetNumOutputPorts(rtm, val) ((rtm)->Sizes.numOports = (val))
#endif

#ifndef rtmGetNumSFcnParams
# define rtmGetNumSFcnParams(rtm)      ((rtm)->Sizes.numSFcnPrms)
#endif

#ifndef rtmSetNumSFcnParams
# define rtmSetNumSFcnParams(rtm, val) ((rtm)->Sizes.numSFcnPrms = (val))
#endif

#ifndef rtmGetNumSFunctions
# define rtmGetNumSFunctions(rtm)      ((rtm)->Sizes.numSFcns)
#endif

#ifndef rtmSetNumSFunctions
# define rtmSetNumSFunctions(rtm, val) ((rtm)->Sizes.numSFcns = (val))
#endif

#ifndef rtmGetNumSampleTimes
# define rtmGetNumSampleTimes(rtm)     ((rtm)->Sizes.numSampTimes)
#endif

#ifndef rtmSetNumSampleTimes
# define rtmSetNumSampleTimes(rtm, val) ((rtm)->Sizes.numSampTimes = (val))
#endif

#ifndef rtmGetNumU
# define rtmGetNumU(rtm)               ((rtm)->Sizes.numU)
#endif

#ifndef rtmSetNumU
# define rtmSetNumU(rtm, val)          ((rtm)->Sizes.numU = (val))
#endif

#ifndef rtmGetNumY
# define rtmGetNumY(rtm)               ((rtm)->Sizes.numY)
#endif

#ifndef rtmSetNumY
# define rtmSetNumY(rtm, val)          ((rtm)->Sizes.numY = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->ModelData.odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->ModelData.odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ()
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ()
#endif

#ifndef rtmGetOffsetTimeArray
# define rtmGetOffsetTimeArray(rtm)    ((rtm)->Timing.offsetTimesArray)
#endif

#ifndef rtmSetOffsetTimeArray
# define rtmSetOffsetTimeArray(rtm, val) ((rtm)->Timing.offsetTimesArray = (val))
#endif

#ifndef rtmGetOffsetTimePtr
# define rtmGetOffsetTimePtr(rtm)      ((rtm)->Timing.offsetTimes)
#endif

#ifndef rtmSetOffsetTimePtr
# define rtmSetOffsetTimePtr(rtm, val) ((rtm)->Timing.offsetTimes = (val))
#endif

#ifndef rtmGetOptions
# define rtmGetOptions(rtm)            ((rtm)->Sizes.options)
#endif

#ifndef rtmSetOptions
# define rtmSetOptions(rtm, val)       ((rtm)->Sizes.options = (val))
#endif

#ifndef rtmGetParamIsMalloced
# define rtmGetParamIsMalloced(rtm)    ()
#endif

#ifndef rtmSetParamIsMalloced
# define rtmSetParamIsMalloced(rtm, val) ()
#endif

#ifndef rtmGetPath
# define rtmGetPath(rtm)               ((rtm)->path)
#endif

#ifndef rtmSetPath
# define rtmSetPath(rtm, val)          ((rtm)->path = (val))
#endif

#ifndef rtmGetPerTaskSampleHits
# define rtmGetPerTaskSampleHits(rtm)  ((rtm)->Timing.RateInteraction)
#endif

#ifndef rtmSetPerTaskSampleHits
# define rtmSetPerTaskSampleHits(rtm, val) ((rtm)->Timing.RateInteraction = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsArray
# define rtmGetPerTaskSampleHitsArray(rtm) ((rtm)->Timing.perTaskSampleHitsArray)
#endif

#ifndef rtmSetPerTaskSampleHitsArray
# define rtmSetPerTaskSampleHitsArray(rtm, val) ((rtm)->Timing.perTaskSampleHitsArray = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsPtr
# define rtmGetPerTaskSampleHitsPtr(rtm) ((rtm)->Timing.perTaskSampleHits)
#endif

#ifndef rtmSetPerTaskSampleHitsPtr
# define rtmSetPerTaskSampleHitsPtr(rtm, val) ((rtm)->Timing.perTaskSampleHits = (val))
#endif

#ifndef rtmGetPrevZCSigState
# define rtmGetPrevZCSigState(rtm)     ()
#endif

#ifndef rtmSetPrevZCSigState
# define rtmSetPrevZCSigState(rtm, val) ()
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmSetRTWExtModeInfo
# define rtmSetRTWExtModeInfo(rtm, val) ((rtm)->extModeInfo = (val))
#endif

#ifndef rtmGetRTWGeneratedSFcn
# define rtmGetRTWGeneratedSFcn(rtm)   ((rtm)->Sizes.rtwGenSfcn)
#endif

#ifndef rtmSetRTWGeneratedSFcn
# define rtmSetRTWGeneratedSFcn(rtm, val) ((rtm)->Sizes.rtwGenSfcn = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ()
#endif

#ifndef rtmSetRTWLogInfo
# define rtmSetRTWLogInfo(rtm, val)    ()
#endif

#ifndef rtmGetRTWRTModelMethodsInfo
# define rtmGetRTWRTModelMethodsInfo(rtm) ()
#endif

#ifndef rtmSetRTWRTModelMethodsInfo
# define rtmSetRTWRTModelMethodsInfo(rtm, val) ()
#endif

#ifndef rtmGetRTWSfcnInfo
# define rtmGetRTWSfcnInfo(rtm)        ((rtm)->sfcnInfo)
#endif

#ifndef rtmSetRTWSfcnInfo
# define rtmSetRTWSfcnInfo(rtm, val)   ((rtm)->sfcnInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfo
# define rtmGetRTWSolverInfo(rtm)      ((rtm)->solverInfo)
#endif

#ifndef rtmSetRTWSolverInfo
# define rtmSetRTWSolverInfo(rtm, val) ((rtm)->solverInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfoPtr
# define rtmGetRTWSolverInfoPtr(rtm)   ((rtm)->solverInfoPtr)
#endif

#ifndef rtmSetRTWSolverInfoPtr
# define rtmSetRTWSolverInfoPtr(rtm, val) ((rtm)->solverInfoPtr = (val))
#endif

#ifndef rtmGetReservedForXPC
# define rtmGetReservedForXPC(rtm)     ()
#endif

#ifndef rtmSetReservedForXPC
# define rtmSetReservedForXPC(rtm, val) ()
#endif

#ifndef rtmGetRootDWork
# define rtmGetRootDWork(rtm)          ()
#endif

#ifndef rtmSetRootDWork
# define rtmSetRootDWork(rtm, val)     ()
#endif

#ifndef rtmGetSFunctions
# define rtmGetSFunctions(rtm)         ((rtm)->childSfunctions)
#endif

#ifndef rtmSetSFunctions
# define rtmSetSFunctions(rtm, val)    ((rtm)->childSfunctions = (val))
#endif

#ifndef rtmGetSampleHitArray
# define rtmGetSampleHitArray(rtm)     ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmSetSampleHitArray
# define rtmSetSampleHitArray(rtm, val) ((rtm)->Timing.sampleHitArray = (val))
#endif

#ifndef rtmGetSampleHitPtr
# define rtmGetSampleHitPtr(rtm)       ((rtm)->Timing.sampleHits)
#endif

#ifndef rtmSetSampleHitPtr
# define rtmSetSampleHitPtr(rtm, val)  ((rtm)->Timing.sampleHits = (val))
#endif

#ifndef rtmGetSampleTimeArray
# define rtmGetSampleTimeArray(rtm)    ((rtm)->Timing.sampleTimesArray)
#endif

#ifndef rtmSetSampleTimeArray
# define rtmSetSampleTimeArray(rtm, val) ((rtm)->Timing.sampleTimesArray = (val))
#endif

#ifndef rtmGetSampleTimePtr
# define rtmGetSampleTimePtr(rtm)      ((rtm)->Timing.sampleTimes)
#endif

#ifndef rtmSetSampleTimePtr
# define rtmSetSampleTimePtr(rtm, val) ((rtm)->Timing.sampleTimes = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDArray
# define rtmGetSampleTimeTaskIDArray(rtm) ((rtm)->Timing.sampleTimeTaskIDArray)
#endif

#ifndef rtmSetSampleTimeTaskIDArray
# define rtmSetSampleTimeTaskIDArray(rtm, val) ((rtm)->Timing.sampleTimeTaskIDArray = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDPtr
# define rtmGetSampleTimeTaskIDPtr(rtm) ((rtm)->Timing.sampleTimeTaskIDPtr)
#endif

#ifndef rtmSetSampleTimeTaskIDPtr
# define rtmSetSampleTimeTaskIDPtr(rtm, val) ((rtm)->Timing.sampleTimeTaskIDPtr = (val))
#endif

#ifndef rtmGetSimMode
# define rtmGetSimMode(rtm)            ((rtm)->simMode)
#endif

#ifndef rtmSetSimMode
# define rtmSetSimMode(rtm, val)       ((rtm)->simMode = (val))
#endif

#ifndef rtmGetSimTimeStep
# define rtmGetSimTimeStep(rtm)        ((rtm)->Timing.simTimeStep)
#endif

#ifndef rtmSetSimTimeStep
# define rtmSetSimTimeStep(rtm, val)   ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStartTime
# define rtmGetStartTime(rtm)          ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetStartTime
# define rtmSetStartTime(rtm, val)     ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           ((rtm)->Timing.stepSize)
#endif

#ifndef rtmSetStepSize
# define rtmSetStepSize(rtm, val)      ((rtm)->Timing.stepSize = (val))
#endif

#ifndef rtmGetStopRequestedFlag
# define rtmGetStopRequestedFlag(rtm)  ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedFlag
# define rtmSetStopRequestedFlag(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetTaskCounters
# define rtmGetTaskCounters(rtm)       ((rtm)->Timing.TaskCounters)
#endif

#ifndef rtmSetTaskCounters
# define rtmSetTaskCounters(rtm, val)  ((rtm)->Timing.TaskCounters = (val))
#endif

#ifndef rtmGetTaskTimeArray
# define rtmGetTaskTimeArray(rtm)      ((rtm)->Timing.tArray)
#endif

#ifndef rtmSetTaskTimeArray
# define rtmSetTaskTimeArray(rtm, val) ((rtm)->Timing.tArray = (val))
#endif

#ifndef rtmGetTimePtr
# define rtmGetTimePtr(rtm)            ((rtm)->Timing.t)
#endif

#ifndef rtmSetTimePtr
# define rtmSetTimePtr(rtm, val)       ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTimingData
# define rtmGetTimingData(rtm)         ((rtm)->Timing.timingData)
#endif

#ifndef rtmSetTimingData
# define rtmSetTimingData(rtm, val)    ((rtm)->Timing.timingData = (val))
#endif

#ifndef rtmGetU
# define rtmGetU(rtm)                  ()
#endif

#ifndef rtmSetU
# define rtmSetU(rtm, val)             ()
#endif

#ifndef rtmGetVarNextHitTimesListPtr
# define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
# define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
# define rtmGetY(rtm)                  ()
#endif

#ifndef rtmSetY
# define rtmSetY(rtm, val)             ()
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->ModelData.zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->ModelData.zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
# define rtmGetZCSignalValues(rtm)     ()
#endif

#ifndef rtmSetZCSignalValues
# define rtmSetZCSignalValues(rtm, val) ()
#endif

#ifndef rtmGet_TimeOfLastOutput
# define rtmGet_TimeOfLastOutput(rtm)  ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmSet_TimeOfLastOutput
# define rtmSet_TimeOfLastOutput(rtm, val) ((rtm)->Timing.timeOfLastOutput = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->ModelData.derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->ModelData.derivs = (val))
#endif

#ifndef rtmGetChecksumVal
# define rtmGetChecksumVal(rtm, idx)   ((rtm)->Sizes.checksums[idx])
#endif

#ifndef rtmSetChecksumVal
# define rtmSetChecksumVal(rtm, idx, val) ((rtm)->Sizes.checksums[idx] = (val))
#endif

#ifndef rtmGetDWork
# define rtmGetDWork(rtm, idx)         ()
#endif

#ifndef rtmSetDWork
# define rtmSetDWork(rtm, idx, val)    ()
#endif

#ifndef rtmGetOffsetTime
# define rtmGetOffsetTime(rtm, idx)    ((rtm)->Timing.offsetTimes[idx])
#endif

#ifndef rtmSetOffsetTime
# define rtmSetOffsetTime(rtm, idx, val) ((rtm)->Timing.offsetTimes[idx] = (val))
#endif

#ifndef rtmGetSFunction
# define rtmGetSFunction(rtm, idx)     ((rtm)->childSfunctions[idx])
#endif

#ifndef rtmSetSFunction
# define rtmSetSFunction(rtm, idx, val) ((rtm)->childSfunctions[idx] = (val))
#endif

#ifndef rtmGetSampleTime
# define rtmGetSampleTime(rtm, idx)    ((rtm)->Timing.sampleTimes[idx])
#endif

#ifndef rtmSetSampleTime
# define rtmSetSampleTime(rtm, idx, val) ((rtm)->Timing.sampleTimes[idx] = (val))
#endif

#ifndef rtmGetSampleTimeTaskID
# define rtmGetSampleTimeTaskID(rtm, idx) ((rtm)->Timing.sampleTimeTaskIDPtr[idx])
#endif

#ifndef rtmSetSampleTimeTaskID
# define rtmSetSampleTimeTaskID(rtm, idx, val) ((rtm)->Timing.sampleTimeTaskIDPtr[idx] = (val))
#endif

#ifndef rtmGetVarNextHitTime
# define rtmGetVarNextHitTime(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTime
# define rtmSetVarNextHitTime(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmIsSampleHit
# define rtmIsSampleHit(rtm, sti, tid) (((rtm)->Timing.sampleTimeTaskIDPtr[sti] == (tid)))
#endif

#ifndef rtmStepTask
# define rtmStepTask(rtm, idx)         ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmSetT
# define rtmSetT(rtm, val)             (rtmGetTPtr((rtm))[0] = (val))
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTStart
# define rtmGetTStart(rtm)             ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetTStart
# define rtmSetTStart(rtm, val)        ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmTaskCounter
# define rtmTaskCounter(rtm, idx)      ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

#ifndef rtmGetTaskTime
# define rtmGetTaskTime(rtm, sti)      (rtmGetTPtr((rtm))[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmGetTimeOfLastOutput
# define rtmGetTimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifdef rtmGetRTWSolverInfo
#undef rtmGetRTWSolverInfo
#endif

#define rtmGetRTWSolverInfo(rtm)       &((rtm)->solverInfo)

/* Definition for use in the target main file */
#define helicopter_integral_rtModel    RT_MODEL_helicopter_integral

/* Block signals (auto storage) */
typedef struct {
  real_T Program1Joystick2;            /* '<Root>/Program = 1 Joystick = 2' */
  real_T SliderGain;                   /* '<S6>/Slider Gain' */
  real_T ConstantPitchdeg;             /* '<S2>/Constant: Pitch (deg)' */
  real_T SliderGain_l;                 /* '<S7>/Slider Gain' */
  real_T Constant;                     /* '<S9>/Constant' */
  real_T ConstantPitchdeg_j;           /* '<S3>/Constant: Pitch (deg)' */
  real_T DesPositionRateLimiter[3];    /* '<Root>/Des Position Rate Limiter' */
  real_T desvel;                       /* '<S5>/des vel' */
  real_T Bias[2];                      /* '<Root>/Bias' */
  real_T DACBLimitV[2];                /* '<S1>/DACB Limit (V)' */
  real_T AmplifierGain[2];             /* '<S1>/Amplifier Gain' */
  real_T InitialElevationrad;          /* '<S1>/Initial Elevation (rad)' */
  real_T EncoderResolutionPitchradcount;/* '<S1>/Encoder Resolution: Pitch (rad//count)' */
  real_T EncoderResolutionTravelradcount;/* '<S1>/Encoder Resolution: Travel (rad//count)' */
  real_T RateTransitionz;              /* '<S3>/Rate Transition: z' */
  real_T RateTransitionx;              /* '<S3>/Rate Transition: x' */
  real_T CalibrationXdegsV;            /* '<S3>/Calibration: X  (deg//s//V)' */
  real_T RateTransitiony;              /* '<S3>/Rate Transition: y' */
  real_T CalibrationYdegsV;            /* '<S3>/Calibration: Y  (deg//s//V)' */
  real_T Sum1[3];                      /* '<Root>/Sum1' */
  real_T Sum2[6];                      /* '<Root>/Sum2' */
  real_T Integrator[6];                /* '<S4>/Integrator' */
  real_T Gain1[6];                     /* '<S4>/Gain1' */
  real_T Gain2[6];                     /* '<S4>/Gain2' */
  real_T Gain4[6];                     /* '<S4>/Gain4' */
  real_T Sum[6];                       /* '<S4>/Sum' */
  uint8_T Constant_k;                  /* '<S8>/Constant' */
  boolean_T GameController_o2[32];     /* '<S3>/Game Controller' */
} BlockIO_helicopter_integral;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T HILInitialize_AIMinimums[4];  /* '<S1>/HIL Initialize' */
  real_T HILInitialize_AIMaximums[4];  /* '<S1>/HIL Initialize' */
  real_T HILInitialize_AOMinimums[4];  /* '<S1>/HIL Initialize' */
  real_T HILInitialize_AOMaximums[4];  /* '<S1>/HIL Initialize' */
  real_T HILInitialize_AOVoltages[4];  /* '<S1>/HIL Initialize' */
  real_T HILInitialize_FilterFrequency[4];/* '<S1>/HIL Initialize' */
  real_T PrevY[3];                     /* '<Root>/Des Position Rate Limiter' */
  real_T LastMajorTime;                /* '<Root>/Des Position Rate Limiter' */
  real_T RateTransitionz_Buffer0;      /* '<S3>/Rate Transition: z' */
  real_T RateTransitionx_Buffer0;      /* '<S3>/Rate Transition: x' */
  real_T RateTransitiony_Buffer0;      /* '<S3>/Rate Transition: y' */
  t_game_controller GameController_Controller;/* '<S3>/Game Controller' */
  t_card HILInitialize_Card;           /* '<S1>/HIL Initialize' */
  t_task HILReadEncoderTimebase_Task;  /* '<S1>/HIL Read Encoder Timebase' */
  void *HILWriteAnalog_PWORK;          /* '<S1>/HIL Write Analog' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S1>/Scope' */

  void *HILWriteDigital_PWORK;         /* '<S1>/HIL Write Digital' */
  struct {
    void *LoggedData;
  } Motorvoltage_PWORK;                /* '<Root>/Motor voltage' */

  struct {
    void *LoggedData;
  } Position_PWORK;                    /* '<Root>/Position' */

  struct {
    void *LoggedData;
  } Velocity_PWORK;                    /* '<Root>/Velocity' */

  int32_T HILInitialize_DOStates[8];   /* '<S1>/HIL Initialize' */
  int32_T HILInitialize_QuadratureModes[4];/* '<S1>/HIL Initialize' */
  int32_T HILInitialize_InitialEICounts[4];/* '<S1>/HIL Initialize' */
  int32_T HILReadEncoderTimebase_Buffer[3];/* '<S1>/HIL Read Encoder Timebase' */
  boolean_T HILInitialize_DOBits[8];   /* '<S1>/HIL Initialize' */
  t_boolean HILWriteDigital_Buffer[4]; /* '<S1>/HIL Write Digital' */
} D_Work_helicopter_integral;

/* Continuous states (auto storage) */
typedef struct {
  real_T DesPositionElevationdeg_CSTATE;/* '<S3>/Des Position:  Elevation (deg)' */
  real_T DesPositionTraveldeg_CSTATE;  /* '<S3>/Des Position:  Travel (deg)' */
  real_T Integrator_CSTATE[6];         /* '<Root>/Integrator' */
  real_T Integrator_CSTATE_i[6];       /* '<S4>/Integrator' */
} ContinuousStates_helicopter_int;

/* State derivatives (auto storage) */
typedef struct {
  real_T DesPositionElevationdeg_CSTATE;/* '<S3>/Des Position:  Elevation (deg)' */
  real_T DesPositionTraveldeg_CSTATE;  /* '<S3>/Des Position:  Travel (deg)' */
  real_T Integrator_CSTATE[6];         /* '<Root>/Integrator' */
  real_T Integrator_CSTATE_i[6];       /* '<S4>/Integrator' */
} StateDerivatives_helicopter_int;

/* State disabled  */
typedef struct {
  boolean_T DesPositionElevationdeg_CSTATE;/* '<S3>/Des Position:  Elevation (deg)' */
  boolean_T DesPositionTraveldeg_CSTATE;/* '<S3>/Des Position:  Travel (deg)' */
  boolean_T Integrator_CSTATE[6];      /* '<Root>/Integrator' */
  boolean_T Integrator_CSTATE_i[6];    /* '<S4>/Integrator' */
} StateDisabled_helicopter_integr;

#ifndef ODE1_INTG
#define ODE1_INTG

/* ODE1 Integration Data */
typedef struct {
  real_T *f[1];                        /* derivatives */
} ODE1_IntgData;

#endif

/* Parameters (auto storage) */
struct Parameters_helicopter_integral_ {
  real_T Gain1_Gain;                   /* Expression: pi/180
                                        * Referenced by: '<S12>/Gain1'
                                        */
  real_T LookUpTable1_XData[7];        /* Expression: rep_seq_t - min(rep_seq_t)
                                        * Referenced by: '<S9>/Look-Up Table1'
                                        */
  real_T LookUpTable1_YData[7];        /* Expression: rep_seq_y
                                        * Referenced by: '<S9>/Look-Up Table1'
                                        */
  real_T AmplitudeTraveldeg_Gain;      /* Expression: 0
                                        * Referenced by: '<S2>/Amplitude: Travel (deg)'
                                        */
  real_T AmplitudeElevationdeg_Gain;   /* Expression: 0
                                        * Referenced by: '<S2>/Amplitude: Elevation (deg)'
                                        */
  real_T Gain1_Gain_d;                 /* Expression: pi/180
                                        * Referenced by: '<S10>/Gain1'
                                        */
  real_T Gain2_Gain[12];               /* Expression: B
                                        * Referenced by: '<S4>/Gain2'
                                        */
  real_T Gain4_Gain[18];               /* Expression: L'
                                        * Referenced by: '<S4>/Gain4'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S4>/Integrator'
                                        */
  real_T Gain1_Gain_f[36];             /* Expression: A
                                        * Referenced by: '<S4>/Gain1'
                                        */
  real_T Gain3_Gain[18];               /* Expression: C
                                        * Referenced by: '<S4>/Gain3'
                                        */
  real_T HILInitialize_OOStart;        /* Expression: set_other_outputs_at_start
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  real_T HILInitialize_OOEnter;        /* Expression: set_other_outputs_at_switch_in
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  real_T HILInitialize_OOTerminate;    /* Expression: set_other_outputs_at_terminate
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  real_T HILInitialize_OOExit;         /* Expression: set_other_outputs_at_switch_out
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  real_T HILInitialize_AIHigh;         /* Expression: analog_input_maximums
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  real_T HILInitialize_AILow;          /* Expression: analog_input_minimums
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  real_T HILInitialize_AOHigh;         /* Expression: analog_output_maximums
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  real_T HILInitialize_AOLow;          /* Expression: analog_output_minimums
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  real_T HILInitialize_AOInitial;      /* Expression: initial_analog_outputs
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  real_T HILInitialize_AOFinal;        /* Expression: final_analog_outputs
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  real_T HILInitialize_AOWatchdog;     /* Expression: watchdog_analog_outputs
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  real_T HILInitialize_EIFrequency;    /* Expression: encoder_filter_frequency
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  real_T HILInitialize_POFrequency;    /* Expression: pwm_frequency
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  real_T HILInitialize_POInitial;      /* Expression: initial_pwm_outputs
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  real_T HILInitialize_POFinal;        /* Expression: final_pwm_outputs
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  real_T Program1Joystick2_Value;      /* Expression: 2
                                        * Referenced by: '<Root>/Program = 1 Joystick = 2'
                                        */
  real_T SignalGeneratorElevation_Amplit;/* Expression: 1
                                          * Referenced by: '<S2>/Signal Generator: Elevation'
                                          */
  real_T SignalGeneratorElevation_Freque;/* Expression: 0.04
                                          * Referenced by: '<S2>/Signal Generator: Elevation'
                                          */
  real_T ElevConstant_Value;           /* Expression: 1
                                        * Referenced by: '<S2>/Elev Constant'
                                        */
  real_T SliderGain_Gain;              /* Expression: gain
                                        * Referenced by: '<S6>/Slider Gain'
                                        */
  real_T ConstantPitchdeg_Value;       /* Expression: 0
                                        * Referenced by: '<S2>/Constant: Pitch (deg)'
                                        */
  real_T SignalGeneratorTravel_Amplitude;/* Expression: 1
                                          * Referenced by: '<S2>/Signal Generator: Travel'
                                          */
  real_T SignalGeneratorTravel_Frequency;/* Expression: 0.03
                                          * Referenced by: '<S2>/Signal Generator: Travel'
                                          */
  real_T TravelConstant_Value;         /* Expression: 1
                                        * Referenced by: '<S2>/Travel Constant'
                                        */
  real_T SliderGain_Gain_p;            /* Expression: gain
                                        * Referenced by: '<S7>/Slider Gain'
                                        */
  real_T Constant_Value;               /* Expression: period
                                        * Referenced by: '<S9>/Constant'
                                        */
  real_T DesPositionElevationdeg_IC;   /* Expression: elev_0*180/pi
                                        * Referenced by: '<S3>/Des Position:  Elevation (deg)'
                                        */
  real_T DesPositionElevationdeg_UpperSa;/* Expression: CMD_ELEV_POS_LIMIT_UPPER
                                          * Referenced by: '<S3>/Des Position:  Elevation (deg)'
                                          */
  real_T DesPositionElevationdeg_LowerSa;/* Expression: CMD_ELEV_POS_LIMIT_LOWER
                                          * Referenced by: '<S3>/Des Position:  Elevation (deg)'
                                          */
  real_T ConstantPitchdeg_Value_h;     /* Expression: 0
                                        * Referenced by: '<S3>/Constant: Pitch (deg)'
                                        */
  real_T DesPositionTraveldeg_IC;      /* Expression: 0
                                        * Referenced by: '<S3>/Des Position:  Travel (deg)'
                                        */
  real_T DesPositionRateLimiter_RisingLi;/* Expression: CMD_RATE_LIMIT
                                          * Referenced by: '<Root>/Des Position Rate Limiter'
                                          */
  real_T DesPositionRateLimiter_FallingL;/* Expression: -CMD_RATE_LIMIT
                                          * Referenced by: '<Root>/Des Position Rate Limiter'
                                          */
  real_T desvel_Value;                 /* Expression: 0
                                        * Referenced by: '<S5>/des vel'
                                        */
  real_T Gain1_Gain_b;                 /* Expression: Kr
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real_T Integrator_IC_n;              /* Expression: 0
                                        * Referenced by: '<Root>/Integrator'
                                        */
  real_T Gain3_Gain_p;                 /* Expression: Ki
                                        * Referenced by: '<Root>/Gain3'
                                        */
  real_T Gain2_Gain_i[12];             /* Expression: K
                                        * Referenced by: '<Root>/Gain2'
                                        */
  real_T Bias_Bias;                    /* Expression: Vo
                                        * Referenced by: '<Root>/Bias'
                                        */
  real_T AmplifierVoltageLimitV_UpperSat;/* Expression: VMAX_AMP
                                          * Referenced by: '<S1>/Amplifier Voltage  Limit (V)'
                                          */
  real_T AmplifierVoltageLimitV_LowerSat;/* Expression: -VMAX_AMP
                                          * Referenced by: '<S1>/Amplifier Voltage  Limit (V)'
                                          */
  real_T AmplifierGainPreCompensation_Ga;/* Expression:  1 / K_AMP
                                          * Referenced by: '<S1>/Amplifier Gain Pre-Compensation'
                                          */
  real_T DACBLimitV_UpperSat;          /* Expression: VMAX_DAC
                                        * Referenced by: '<S1>/DACB Limit (V)'
                                        */
  real_T DACBLimitV_LowerSat;          /* Expression: -VMAX_DAC
                                        * Referenced by: '<S1>/DACB Limit (V)'
                                        */
  real_T AmplifierGain_Gain;           /* Expression:  K_AMP
                                        * Referenced by: '<S1>/Amplifier Gain'
                                        */
  real_T EncoderResolutionElevationradco;/* Expression: K_EC_E
                                          * Referenced by: '<S1>/Encoder Resolution: Elevation (rad//count)'
                                          */
  real_T InitialElevationrad_Bias;     /* Expression: elev_0
                                        * Referenced by: '<S1>/Initial Elevation (rad)'
                                        */
  real_T EncoderResolutionPitchradcount_;/* Expression: K_EC_P
                                          * Referenced by: '<S1>/Encoder Resolution: Pitch (rad//count)'
                                          */
  real_T EncoderResolutionTravelradcount;/* Expression: K_EC_T
                                          * Referenced by: '<S1>/Encoder Resolution: Travel (rad//count)'
                                          */
  real_T EnableAmp_Value[4];           /* Expression: [1 1 1 1]
                                        * Referenced by: '<S1>/Enable Amp'
                                        */
  real_T Constant_Value_l;             /* Expression: 1
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T RateTransitionz_X0;           /* Expression: 0
                                        * Referenced by: '<S3>/Rate Transition: z'
                                        */
  real_T Inverse_Gain;                 /* Expression: -1
                                        * Referenced by: '<S11>/Inverse'
                                        */
  real_T Bias_Bias_k;                  /* Expression: 1
                                        * Referenced by: '<S11>/Bias'
                                        */
  real_T Constant_Value_c;             /* Expression: 2
                                        * Referenced by: '<S11>/Constant'
                                        */
  real_T RateTransitionx_X0;           /* Expression: 0
                                        * Referenced by: '<S3>/Rate Transition: x'
                                        */
  real_T CalibrationXdegsV_Gain;       /* Expression: K_JOYSTICK_X
                                        * Referenced by: '<S3>/Calibration: X  (deg//s//V)'
                                        */
  real_T RateTransitiony_X0;           /* Expression: 0
                                        * Referenced by: '<S3>/Rate Transition: y'
                                        */
  real_T CalibrationYdegsV_Gain;       /* Expression: K_JOYSTICK_Y
                                        * Referenced by: '<S3>/Calibration: Y  (deg//s//V)'
                                        */
  int32_T HILInitialize_CKChannels[2]; /* Computed Parameter: HILInitialize_CKChannels
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  int32_T HILInitialize_CKModes[2];    /* Computed Parameter: HILInitialize_CKModes
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  int32_T HILInitialize_DOWatchdog;    /* Computed Parameter: HILInitialize_DOWatchdog
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  int32_T HILInitialize_EIInitial;     /* Computed Parameter: HILInitialize_EIInitial
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  int32_T HILInitialize_POModes;       /* Computed Parameter: HILInitialize_POModes
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  int32_T HILReadEncoderTimebase_Clock;/* Computed Parameter: HILReadEncoderTimebase_Clock
                                        * Referenced by: '<S1>/HIL Read Encoder Timebase'
                                        */
  uint32_T HILInitialize_AIChannels[4];/* Computed Parameter: HILInitialize_AIChannels
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  uint32_T HILInitialize_AOChannels[4];/* Computed Parameter: HILInitialize_AOChannels
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  uint32_T HILInitialize_DIChannels[8];/* Computed Parameter: HILInitialize_DIChannels
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  uint32_T HILInitialize_DOChannels[8];/* Computed Parameter: HILInitialize_DOChannels
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  uint32_T HILInitialize_EIChannels[4];/* Computed Parameter: HILInitialize_EIChannels
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  uint32_T HILInitialize_EIQuadrature; /* Computed Parameter: HILInitialize_EIQuadrature
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  uint32_T HILReadEncoderTimebase_Channels[3];/* Computed Parameter: HILReadEncoderTimebase_Channels
                                               * Referenced by: '<S1>/HIL Read Encoder Timebase'
                                               */
  uint32_T HILReadEncoderTimebase_SamplesI;/* Computed Parameter: HILReadEncoderTimebase_SamplesI
                                            * Referenced by: '<S1>/HIL Read Encoder Timebase'
                                            */
  uint32_T HILWriteAnalog_Channels[2]; /* Computed Parameter: HILWriteAnalog_Channels
                                        * Referenced by: '<S1>/HIL Write Analog'
                                        */
  uint32_T HILWriteDigital_Channels[4];/* Computed Parameter: HILWriteDigital_Channels
                                        * Referenced by: '<S1>/HIL Write Digital'
                                        */
  uint16_T GameController_BufferSize;  /* Computed Parameter: GameController_BufferSize
                                        * Referenced by: '<S3>/Game Controller'
                                        */
  uint8_T SwitchControl_Threshold;     /* Expression: uint8(0)
                                        * Referenced by: '<S8>/SwitchControl'
                                        */
  uint8_T Constant_Value_p;            /* Expression: uint8(1)
                                        * Referenced by: '<S8>/Constant'
                                        */
  uint8_T GameController_ControllerNumber;/* Computed Parameter: GameController_ControllerNumber
                                           * Referenced by: '<S3>/Game Controller'
                                           */
  boolean_T HILInitialize_Active;      /* Computed Parameter: HILInitialize_Active
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  boolean_T HILInitialize_CKPStart;    /* Computed Parameter: HILInitialize_CKPStart
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  boolean_T HILInitialize_CKPEnter;    /* Computed Parameter: HILInitialize_CKPEnter
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  boolean_T HILInitialize_CKStart;     /* Computed Parameter: HILInitialize_CKStart
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  boolean_T HILInitialize_CKEnter;     /* Computed Parameter: HILInitialize_CKEnter
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  boolean_T HILInitialize_AIPStart;    /* Computed Parameter: HILInitialize_AIPStart
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  boolean_T HILInitialize_AIPEnter;    /* Computed Parameter: HILInitialize_AIPEnter
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  boolean_T HILInitialize_AOPStart;    /* Computed Parameter: HILInitialize_AOPStart
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  boolean_T HILInitialize_AOPEnter;    /* Computed Parameter: HILInitialize_AOPEnter
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  boolean_T HILInitialize_AOStart;     /* Computed Parameter: HILInitialize_AOStart
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  boolean_T HILInitialize_AOEnter;     /* Computed Parameter: HILInitialize_AOEnter
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  boolean_T HILInitialize_AOTerminate; /* Computed Parameter: HILInitialize_AOTerminate
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  boolean_T HILInitialize_AOExit;      /* Computed Parameter: HILInitialize_AOExit
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  boolean_T HILInitialize_AOReset;     /* Computed Parameter: HILInitialize_AOReset
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  boolean_T HILInitialize_DOPStart;    /* Computed Parameter: HILInitialize_DOPStart
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  boolean_T HILInitialize_DOPEnter;    /* Computed Parameter: HILInitialize_DOPEnter
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  boolean_T HILInitialize_DOStart;     /* Computed Parameter: HILInitialize_DOStart
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  boolean_T HILInitialize_DOEnter;     /* Computed Parameter: HILInitialize_DOEnter
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  boolean_T HILInitialize_DOTerminate; /* Computed Parameter: HILInitialize_DOTerminate
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  boolean_T HILInitialize_DOExit;      /* Computed Parameter: HILInitialize_DOExit
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  boolean_T HILInitialize_DOReset;     /* Computed Parameter: HILInitialize_DOReset
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  boolean_T HILInitialize_EIPStart;    /* Computed Parameter: HILInitialize_EIPStart
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  boolean_T HILInitialize_EIPEnter;    /* Computed Parameter: HILInitialize_EIPEnter
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  boolean_T HILInitialize_EIStart;     /* Computed Parameter: HILInitialize_EIStart
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  boolean_T HILInitialize_EIEnter;     /* Computed Parameter: HILInitialize_EIEnter
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  boolean_T HILInitialize_POPStart;    /* Computed Parameter: HILInitialize_POPStart
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  boolean_T HILInitialize_POPEnter;    /* Computed Parameter: HILInitialize_POPEnter
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  boolean_T HILInitialize_POStart;     /* Computed Parameter: HILInitialize_POStart
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  boolean_T HILInitialize_POEnter;     /* Computed Parameter: HILInitialize_POEnter
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  boolean_T HILInitialize_POTerminate; /* Computed Parameter: HILInitialize_POTerminate
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  boolean_T HILInitialize_POExit;      /* Computed Parameter: HILInitialize_POExit
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  boolean_T HILInitialize_POReset;     /* Computed Parameter: HILInitialize_POReset
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  boolean_T HILInitialize_OOReset;     /* Computed Parameter: HILInitialize_OOReset
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  boolean_T HILInitialize_DOInitial;   /* Computed Parameter: HILInitialize_DOInitial
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  boolean_T HILInitialize_DOFinal;     /* Computed Parameter: HILInitialize_DOFinal
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  boolean_T HILReadEncoderTimebase_Active;/* Computed Parameter: HILReadEncoderTimebase_Active
                                           * Referenced by: '<S1>/HIL Read Encoder Timebase'
                                           */
  boolean_T HILWriteAnalog_Active;     /* Computed Parameter: HILWriteAnalog_Active
                                        * Referenced by: '<S1>/HIL Write Analog'
                                        */
  boolean_T HILWriteDigital_Active;    /* Computed Parameter: HILWriteDigital_Active
                                        * Referenced by: '<S1>/HIL Write Digital'
                                        */
  boolean_T GameController_AutoCenter; /* Computed Parameter: GameController_AutoCenter
                                        * Referenced by: '<S3>/Game Controller'
                                        */
  boolean_T GameController_Enabled;    /* Computed Parameter: GameController_Enabled
                                        * Referenced by: '<S3>/Game Controller'
                                        */
};

/* Real-time Model Data Structure */
struct RT_MODEL_helicopter_integral {
  const char_T *path;
  const char_T *modelName;
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    real_T *contStates;
    real_T *derivs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
    real_T odeF[1][14];
    ODE1_IntgData intgData;
  } ModelData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    uint32_T clockTick2;
    uint32_T clockTickH2;
    struct {
      uint8_T TID[3];
    } TaskCounters;

    struct {
      boolean_T TID1_2;
    } RateInteraction;

    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    void *timingData;
    real_T *varNextHitTimesList;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[3];
    time_T offsetTimesArray[3];
    int_T sampleTimeTaskIDArray[3];
    int_T sampleHitArray[3];
    int_T perTaskSampleHitsArray[9];
    time_T tArray[3];
  } Timing;
};

/* Block parameters (auto storage) */
extern Parameters_helicopter_integral helicopter_integral_P;

/* Block signals (auto storage) */
extern BlockIO_helicopter_integral helicopter_integral_B;

/* Continuous states (auto storage) */
extern ContinuousStates_helicopter_int helicopter_integral_X;

/* Block states (auto storage) */
extern D_Work_helicopter_integral helicopter_integral_DWork;

/* External function called from main */
extern time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
  ;

/* Model entry point functions */
extern void helicopter_integral_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void helicopter_integral_initialize(void);
extern void helicopter_integral_step0(void);
extern void helicopter_integral_step(int_T tid);
extern void helicopter_integral_terminate(void);

/* Real-time Model object */
extern struct RT_MODEL_helicopter_integral *const helicopter_integral_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'helicopter_integral'
 * '<S1>'   : 'helicopter_integral/3-DOF Plant'
 * '<S2>'   : 'helicopter_integral/Desired Angle from Program'
 * '<S3>'   : 'helicopter_integral/Desired Position from Joystick'
 * '<S4>'   : 'helicopter_integral/Observer'
 * '<S5>'   : 'helicopter_integral/appendZeros'
 * '<S6>'   : 'helicopter_integral/Desired Angle from Program/Constant: Elevation (deg)'
 * '<S7>'   : 'helicopter_integral/Desired Angle from Program/Constant: Travel (deg)'
 * '<S8>'   : 'helicopter_integral/Desired Angle from Program/Manual Switch'
 * '<S9>'   : 'helicopter_integral/Desired Angle from Program/Repeating Sequence'
 * '<S10>'  : 'helicopter_integral/Desired Angle from Program/deg to rad'
 * '<S11>'  : 'helicopter_integral/Desired Position from Joystick/Convert (-1,1) to (0,1)'
 * '<S12>'  : 'helicopter_integral/Desired Position from Joystick/deg to rad'
 */
#endif                                 /* RTW_HEADER_helicopter_integral_h_ */
