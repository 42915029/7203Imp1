/*
 * q_heli3d_skeleton.c
 *
 * Code generation for model "q_heli3d_skeleton".
 *
 * Model version              : 1.31
 * Simulink Coder version : 8.2 (R2012a) 29-Dec-2011
 * C source code generated on : Fri Sep 18 15:06:46 2015
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "q_heli3d_skeleton.h"
#include "q_heli3d_skeleton_private.h"
#include "q_heli3d_skeleton_dt.h"

/* Block signals (auto storage) */
BlockIO_q_heli3d_skeleton q_heli3d_skeleton_B;

/* Continuous states */
ContinuousStates_q_heli3d_skele q_heli3d_skeleton_X;

/* Block states (auto storage) */
D_Work_q_heli3d_skeleton q_heli3d_skeleton_DWork;

/* Real-time model */
RT_MODEL_q_heli3d_skeleton q_heli3d_skeleton_M_;
RT_MODEL_q_heli3d_skeleton *const q_heli3d_skeleton_M = &q_heli3d_skeleton_M_;
static void rate_monotonic_scheduler(void);
time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(q_heli3d_skeleton_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(q_heli3d_skeleton_M, 2);
  UNUSED_PARAMETER(rtmNumSampTimes);
  UNUSED_PARAMETER(rtmTimingData);
  UNUSED_PARAMETER(rtmPerTaskSampleHits);
  return(-1);
}

/* rate_monotonic_scheduler */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 1 shares data with slower tid rate: 2 */
  if (q_heli3d_skeleton_M->Timing.TaskCounters.TID[1] == 0) {
    q_heli3d_skeleton_M->Timing.RateInteraction.TID1_2 =
      (q_heli3d_skeleton_M->Timing.TaskCounters.TID[2] == 0);
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (q_heli3d_skeleton_M->Timing.TaskCounters.TID[2])++;
  if ((q_heli3d_skeleton_M->Timing.TaskCounters.TID[2]) > 4) {/* Sample time: [0.01s, 0.0s] */
    q_heli3d_skeleton_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 8;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  q_heli3d_skeleton_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; i++) {
    *x += h * f0[i];
    x++;
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = -0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

real_T rt_remd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T u;
  if (u1 < 0.0) {
    u = ceil(u1);
  } else {
    u = floor(u1);
  }

  if ((u1 != 0.0) && (u1 != u) && ((!rtIsNaN(u0)) && (!rtIsInf(u0)) &&
       ((!rtIsNaN(u1)) && (!rtIsInf(u1))))) {
    u = u0 / u1;
    if (fabs(u - rt_roundd_snf(u)) <= DBL_EPSILON * fabs(u)) {
      y = 0.0;
    } else {
      y = fmod(u0, u1);
    }
  } else {
    y = fmod(u0, u1);
  }

  return y;
}

/* Model step function for TID0 */
void q_heli3d_skeleton_step0(void)     /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_Clock;
  real_T rtb_DesPositionElevationdeg;
  real_T rtb_HILReadEncoderTimebase[3];
  if (rtmIsMajorTimeStep(q_heli3d_skeleton_M)) {
    /* set solver stop time */
    if (!(q_heli3d_skeleton_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&q_heli3d_skeleton_M->solverInfo,
                            ((q_heli3d_skeleton_M->Timing.clockTickH0 + 1) *
        q_heli3d_skeleton_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&q_heli3d_skeleton_M->solverInfo,
                            ((q_heli3d_skeleton_M->Timing.clockTick0 + 1) *
        q_heli3d_skeleton_M->Timing.stepSize0 +
        q_heli3d_skeleton_M->Timing.clockTickH0 *
        q_heli3d_skeleton_M->Timing.stepSize0 * 4294967296.0));
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(q_heli3d_skeleton_M)) {
    q_heli3d_skeleton_M->Timing.t[0] = rtsiGetT(&q_heli3d_skeleton_M->solverInfo);
  }

  {
    real_T rtb_MultiportSwitch[3];
    real_T rtb_SignalGeneratorElevation;
    real_T rtb_SignalGeneratorTravel;
    int32_T i;
    real_T tmp[6];
    real_T tmp_0[6];
    int32_T i_0;
    real_T rateLimiterRate_idx;
    real_T rateLimiterRate_idx_0;
    real_T rateLimiterRate_idx_1;
    if (rtmIsMajorTimeStep(q_heli3d_skeleton_M)) {
      /* S-Function (hil_read_encoder_timebase_block): '<S1>/HIL Read Encoder Timebase' */

      /* S-Function Block: q_heli3d_skeleton/3-DOF Plant/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
      {
        t_error result;
        result = hil_task_read_encoder
          (q_heli3d_skeleton_DWork.HILReadEncoderTimebase_Task, 1,
           &q_heli3d_skeleton_DWork.HILReadEncoderTimebase_Buffer[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(q_heli3d_skeleton_M, _rt_error_message);
        } else {
          rtb_HILReadEncoderTimebase[0] =
            q_heli3d_skeleton_DWork.HILReadEncoderTimebase_Buffer[0];
          rtb_HILReadEncoderTimebase[1] =
            q_heli3d_skeleton_DWork.HILReadEncoderTimebase_Buffer[1];
          rtb_HILReadEncoderTimebase[2] =
            q_heli3d_skeleton_DWork.HILReadEncoderTimebase_Buffer[2];
        }
      }

      /* Constant: '<Root>/Program = 1 Joystick = 2' */
      q_heli3d_skeleton_B.Program1Joystick2 =
        q_heli3d_skeleton_P.Program1Joystick2_Value;
    }

    /* SignalGenerator: '<S2>/Signal Generator: Elevation' */
    rtb_SignalGeneratorTravel =
      q_heli3d_skeleton_P.SignalGeneratorElevation_Freque *
      q_heli3d_skeleton_M->Timing.t[0];
    if (rtb_SignalGeneratorTravel - floor(rtb_SignalGeneratorTravel) >= 0.5) {
      rtb_SignalGeneratorElevation =
        q_heli3d_skeleton_P.SignalGeneratorElevation_Amplit;
    } else {
      rtb_SignalGeneratorElevation =
        -q_heli3d_skeleton_P.SignalGeneratorElevation_Amplit;
    }

    /* End of SignalGenerator: '<S2>/Signal Generator: Elevation' */
    if (rtmIsMajorTimeStep(q_heli3d_skeleton_M)) {
      /* Gain: '<S6>/Slider Gain' incorporates:
       *  Constant: '<S2>/Elev Constant'
       */
      q_heli3d_skeleton_B.SliderGain = q_heli3d_skeleton_P.SliderGain_Gain *
        q_heli3d_skeleton_P.ElevConstant_Value;

      /* Constant: '<S2>/Constant: Pitch (deg)' */
      q_heli3d_skeleton_B.ConstantPitchdeg =
        q_heli3d_skeleton_P.ConstantPitchdeg_Value;
    }

    /* SignalGenerator: '<S2>/Signal Generator: Travel' */
    rtb_SignalGeneratorTravel =
      q_heli3d_skeleton_P.SignalGeneratorTravel_Frequency *
      q_heli3d_skeleton_M->Timing.t[0];
    if (rtb_SignalGeneratorTravel - floor(rtb_SignalGeneratorTravel) >= 0.5) {
      rtb_SignalGeneratorTravel =
        q_heli3d_skeleton_P.SignalGeneratorTravel_Amplitude;
    } else {
      rtb_SignalGeneratorTravel =
        -q_heli3d_skeleton_P.SignalGeneratorTravel_Amplitude;
    }

    /* End of SignalGenerator: '<S2>/Signal Generator: Travel' */
    if (rtmIsMajorTimeStep(q_heli3d_skeleton_M)) {
      /* Gain: '<S7>/Slider Gain' incorporates:
       *  Constant: '<S2>/Travel Constant'
       */
      q_heli3d_skeleton_B.SliderGain_l = q_heli3d_skeleton_P.SliderGain_Gain_p *
        q_heli3d_skeleton_P.TravelConstant_Value;

      /* Constant: '<S8>/Constant' */
      q_heli3d_skeleton_B.Constant_k = q_heli3d_skeleton_P.Constant_Value_p;
    }

    /* Clock: '<S9>/Clock' */
    rtb_Clock = q_heli3d_skeleton_M->Timing.t[0];
    if (rtmIsMajorTimeStep(q_heli3d_skeleton_M)) {
      /* Constant: '<S9>/Constant' */
      q_heli3d_skeleton_B.Constant = q_heli3d_skeleton_P.Constant_Value;
    }

    /* Integrator: '<S3>/Des Position:  Elevation (deg)'
     *
     * Regarding '<S3>/Des Position:  Elevation (deg)':
     *  Limited Integrator
     */
    if (q_heli3d_skeleton_X.DesPositionElevationdeg_CSTATE >=
        q_heli3d_skeleton_P.DesPositionElevationdeg_UpperSa ) {
      q_heli3d_skeleton_X.DesPositionElevationdeg_CSTATE =
        q_heli3d_skeleton_P.DesPositionElevationdeg_UpperSa;
    } else if (q_heli3d_skeleton_X.DesPositionElevationdeg_CSTATE <=
               q_heli3d_skeleton_P.DesPositionElevationdeg_LowerSa ) {
      q_heli3d_skeleton_X.DesPositionElevationdeg_CSTATE =
        q_heli3d_skeleton_P.DesPositionElevationdeg_LowerSa;
    }

    rtb_DesPositionElevationdeg =
      q_heli3d_skeleton_X.DesPositionElevationdeg_CSTATE;
    if (rtmIsMajorTimeStep(q_heli3d_skeleton_M)) {
      /* Constant: '<S3>/Constant: Pitch (deg)' */
      q_heli3d_skeleton_B.ConstantPitchdeg_j =
        q_heli3d_skeleton_P.ConstantPitchdeg_Value_h;
    }

    /* MultiPortSwitch: '<Root>/Multiport Switch' incorporates:
     *  Gain: '<S10>/Gain1'
     *  Gain: '<S12>/Gain1'
     *  Gain: '<S2>/Amplitude: Elevation (deg)'
     *  Integrator: '<S3>/Des Position:  Travel (deg)'
     *  Sum: '<S2>/Sum1'
     */
    if ((int32_T)q_heli3d_skeleton_B.Program1Joystick2 == 1) {
      /* Switch: '<S8>/SwitchControl' incorporates:
       *  Gain: '<S2>/Amplitude: Travel (deg)'
       *  Lookup: '<S9>/Look-Up Table1'
       *  Math: '<S9>/Math Function'
       *  S-Function (sfun_tstart): '<S9>/startTime'
       *  Sum: '<S2>/Sum2'
       *  Sum: '<S9>/Sum'
       */
      if (q_heli3d_skeleton_B.Constant_k >
          q_heli3d_skeleton_P.SwitchControl_Threshold) {
        rtb_SignalGeneratorTravel = q_heli3d_skeleton_P.AmplitudeTraveldeg_Gain *
          rtb_SignalGeneratorTravel + q_heli3d_skeleton_B.SliderGain_l;
      } else {
        rtb_SignalGeneratorTravel = rt_Lookup((const real_T *)
          &q_heli3d_skeleton_P.LookUpTable1_XData, 7, rt_remd_snf(rtb_Clock -
          (0.0), q_heli3d_skeleton_B.Constant), (const real_T *)
          &q_heli3d_skeleton_P.LookUpTable1_YData);
      }

      /* End of Switch: '<S8>/SwitchControl' */
      rtb_MultiportSwitch[0] = (q_heli3d_skeleton_P.AmplitudeElevationdeg_Gain *
        rtb_SignalGeneratorElevation + q_heli3d_skeleton_B.SliderGain) *
        q_heli3d_skeleton_P.Gain1_Gain_d;
      rtb_MultiportSwitch[1] = q_heli3d_skeleton_P.Gain1_Gain_d *
        q_heli3d_skeleton_B.ConstantPitchdeg;
      rtb_MultiportSwitch[2] = q_heli3d_skeleton_P.Gain1_Gain_d *
        rtb_SignalGeneratorTravel;
    } else {
      rtb_MultiportSwitch[0] = q_heli3d_skeleton_P.Gain1_Gain *
        rtb_DesPositionElevationdeg;
      rtb_MultiportSwitch[1] = q_heli3d_skeleton_P.Gain1_Gain *
        q_heli3d_skeleton_B.ConstantPitchdeg_j;
      rtb_MultiportSwitch[2] = q_heli3d_skeleton_P.Gain1_Gain *
        q_heli3d_skeleton_X.DesPositionTraveldeg_CSTATE;
    }

    /* End of MultiPortSwitch: '<Root>/Multiport Switch' */

    /* RateLimiter: '<Root>/Des Position Rate Limiter' */
    if (q_heli3d_skeleton_DWork.LastMajorTime == (rtInf)) {
      q_heli3d_skeleton_B.DesPositionRateLimiter[0] = rtb_MultiportSwitch[0];
      q_heli3d_skeleton_B.DesPositionRateLimiter[1] = rtb_MultiportSwitch[1];
      q_heli3d_skeleton_B.DesPositionRateLimiter[2] = rtb_MultiportSwitch[2];
    } else {
      rtb_SignalGeneratorTravel = q_heli3d_skeleton_M->Timing.t[0] -
        q_heli3d_skeleton_DWork.LastMajorTime;
      rtb_SignalGeneratorElevation = rtb_SignalGeneratorTravel *
        q_heli3d_skeleton_P.DesPositionRateLimiter_RisingLi;
      rateLimiterRate_idx = rtb_MultiportSwitch[0] -
        q_heli3d_skeleton_DWork.PrevY[0];
      rateLimiterRate_idx_0 = rtb_MultiportSwitch[1] -
        q_heli3d_skeleton_DWork.PrevY[1];
      rateLimiterRate_idx_1 = rtb_MultiportSwitch[2] -
        q_heli3d_skeleton_DWork.PrevY[2];
      rtb_SignalGeneratorTravel *=
        q_heli3d_skeleton_P.DesPositionRateLimiter_FallingL;
      if (rateLimiterRate_idx > rtb_SignalGeneratorElevation) {
        q_heli3d_skeleton_B.DesPositionRateLimiter[0] =
          q_heli3d_skeleton_DWork.PrevY[0] + rtb_SignalGeneratorElevation;
      } else if (rateLimiterRate_idx < rtb_SignalGeneratorTravel) {
        q_heli3d_skeleton_B.DesPositionRateLimiter[0] =
          q_heli3d_skeleton_DWork.PrevY[0] + rtb_SignalGeneratorTravel;
      } else {
        q_heli3d_skeleton_B.DesPositionRateLimiter[0] = rtb_MultiportSwitch[0];
      }

      if (rateLimiterRate_idx_0 > rtb_SignalGeneratorElevation) {
        q_heli3d_skeleton_B.DesPositionRateLimiter[1] =
          q_heli3d_skeleton_DWork.PrevY[1] + rtb_SignalGeneratorElevation;
      } else if (rateLimiterRate_idx_0 < rtb_SignalGeneratorTravel) {
        q_heli3d_skeleton_B.DesPositionRateLimiter[1] =
          q_heli3d_skeleton_DWork.PrevY[1] + rtb_SignalGeneratorTravel;
      } else {
        q_heli3d_skeleton_B.DesPositionRateLimiter[1] = rtb_MultiportSwitch[1];
      }

      if (rateLimiterRate_idx_1 > rtb_SignalGeneratorElevation) {
        q_heli3d_skeleton_B.DesPositionRateLimiter[2] =
          q_heli3d_skeleton_DWork.PrevY[2] + rtb_SignalGeneratorElevation;
      } else if (rateLimiterRate_idx_1 < rtb_SignalGeneratorTravel) {
        q_heli3d_skeleton_B.DesPositionRateLimiter[2] =
          q_heli3d_skeleton_DWork.PrevY[2] + rtb_SignalGeneratorTravel;
      } else {
        q_heli3d_skeleton_B.DesPositionRateLimiter[2] = rtb_MultiportSwitch[2];
      }
    }

    /* End of RateLimiter: '<Root>/Des Position Rate Limiter' */
    if (rtmIsMajorTimeStep(q_heli3d_skeleton_M)) {
      /* Constant: '<S5>/des vel' */
      q_heli3d_skeleton_B.desvel = q_heli3d_skeleton_P.desvel_Value;
    }

    /* Outputs for Atomic SubSystem: '<Root>/Observer' */
    /* Integrator: '<S4>/Integrator' */
    for (i = 0; i < 6; i++) {
      q_heli3d_skeleton_B.Integrator[i] =
        q_heli3d_skeleton_X.Integrator_CSTATE[i];
    }

    /* End of Integrator: '<S4>/Integrator' */

    /* Gain: '<S4>/Gain1' */
    for (i = 0; i < 6; i++) {
      q_heli3d_skeleton_B.Gain1[i] = 0.0;
      for (i_0 = 0; i_0 < 6; i_0++) {
        q_heli3d_skeleton_B.Gain1[i] += q_heli3d_skeleton_P.Gain1_Gain_f[6 * i_0
          + i] * q_heli3d_skeleton_B.Integrator[i_0];
      }
    }

    /* End of Gain: '<S4>/Gain1' */

    /* Gain: '<S4>/Gain3' */
    for (i = 0; i < 3; i++) {
      rtb_MultiportSwitch[i] = 0.0;
      for (i_0 = 0; i_0 < 6; i_0++) {
        rtb_MultiportSwitch[i] += q_heli3d_skeleton_P.Gain3_Gain[3 * i_0 + i] *
          q_heli3d_skeleton_B.Integrator[i_0];
      }
    }

    /* End of Gain: '<S4>/Gain3' */
    /* End of Outputs for SubSystem: '<Root>/Observer' */

    /* Sum: '<Root>/Sum' incorporates:
     *  Gain: '<Root>/Gain2'
     */
    tmp[0] = q_heli3d_skeleton_B.DesPositionRateLimiter[0];
    tmp[1] = q_heli3d_skeleton_B.DesPositionRateLimiter[1];
    tmp[2] = q_heli3d_skeleton_B.DesPositionRateLimiter[2];
    tmp[3] = q_heli3d_skeleton_B.desvel;
    tmp[4] = q_heli3d_skeleton_B.desvel;
    tmp[5] = q_heli3d_skeleton_B.desvel;
    for (i = 0; i < 6; i++) {
      tmp_0[i] = tmp[i] - q_heli3d_skeleton_B.Integrator[i];
    }

    /* End of Sum: '<Root>/Sum' */

    /* Bias: '<Root>/Bias' incorporates:
     *  Gain: '<Root>/Gain2'
     */
    for (i = 0; i < 2; i++) {
      rtb_SignalGeneratorTravel = 0.0;
      for (i_0 = 0; i_0 < 6; i_0++) {
        rtb_SignalGeneratorTravel += q_heli3d_skeleton_P.Gain2_Gain_d[(i_0 << 1)
          + i] * tmp_0[i_0];
      }

      q_heli3d_skeleton_B.Bias[i] = rtb_SignalGeneratorTravel +
        q_heli3d_skeleton_P.Bias_Bias;
    }

    /* End of Bias: '<Root>/Bias' */

    /* Saturate: '<S1>/Amplifier Voltage  Limit (V)' */
    if (q_heli3d_skeleton_B.Bias[0] >=
        q_heli3d_skeleton_P.AmplifierVoltageLimitV_UpperSat) {
      rtb_SignalGeneratorTravel =
        q_heli3d_skeleton_P.AmplifierVoltageLimitV_UpperSat;
    } else if (q_heli3d_skeleton_B.Bias[0] <=
               q_heli3d_skeleton_P.AmplifierVoltageLimitV_LowerSat) {
      rtb_SignalGeneratorTravel =
        q_heli3d_skeleton_P.AmplifierVoltageLimitV_LowerSat;
    } else {
      rtb_SignalGeneratorTravel = q_heli3d_skeleton_B.Bias[0];
    }

    /* Gain: '<S1>/Amplifier Gain Pre-Compensation' incorporates:
     *  Saturate: '<S1>/Amplifier Voltage  Limit (V)'
     */
    rtb_SignalGeneratorTravel *=
      q_heli3d_skeleton_P.AmplifierGainPreCompensation_Ga;

    /* Saturate: '<S1>/DACB Limit (V)' */
    if (rtb_SignalGeneratorTravel >= q_heli3d_skeleton_P.DACBLimitV_UpperSat) {
      q_heli3d_skeleton_B.DACBLimitV[0] =
        q_heli3d_skeleton_P.DACBLimitV_UpperSat;
    } else if (rtb_SignalGeneratorTravel <=
               q_heli3d_skeleton_P.DACBLimitV_LowerSat) {
      q_heli3d_skeleton_B.DACBLimitV[0] =
        q_heli3d_skeleton_P.DACBLimitV_LowerSat;
    } else {
      q_heli3d_skeleton_B.DACBLimitV[0] = rtb_SignalGeneratorTravel;
    }

    /* Saturate: '<S1>/Amplifier Voltage  Limit (V)' */
    if (q_heli3d_skeleton_B.Bias[1] >=
        q_heli3d_skeleton_P.AmplifierVoltageLimitV_UpperSat) {
      rtb_SignalGeneratorTravel =
        q_heli3d_skeleton_P.AmplifierVoltageLimitV_UpperSat;
    } else if (q_heli3d_skeleton_B.Bias[1] <=
               q_heli3d_skeleton_P.AmplifierVoltageLimitV_LowerSat) {
      rtb_SignalGeneratorTravel =
        q_heli3d_skeleton_P.AmplifierVoltageLimitV_LowerSat;
    } else {
      rtb_SignalGeneratorTravel = q_heli3d_skeleton_B.Bias[1];
    }

    /* Gain: '<S1>/Amplifier Gain Pre-Compensation' incorporates:
     *  Saturate: '<S1>/Amplifier Voltage  Limit (V)'
     */
    rtb_SignalGeneratorTravel *=
      q_heli3d_skeleton_P.AmplifierGainPreCompensation_Ga;

    /* Saturate: '<S1>/DACB Limit (V)' */
    if (rtb_SignalGeneratorTravel >= q_heli3d_skeleton_P.DACBLimitV_UpperSat) {
      q_heli3d_skeleton_B.DACBLimitV[1] =
        q_heli3d_skeleton_P.DACBLimitV_UpperSat;
    } else if (rtb_SignalGeneratorTravel <=
               q_heli3d_skeleton_P.DACBLimitV_LowerSat) {
      q_heli3d_skeleton_B.DACBLimitV[1] =
        q_heli3d_skeleton_P.DACBLimitV_LowerSat;
    } else {
      q_heli3d_skeleton_B.DACBLimitV[1] = rtb_SignalGeneratorTravel;
    }

    if (rtmIsMajorTimeStep(q_heli3d_skeleton_M)) {
      /* S-Function (hil_write_analog_block): '<S1>/HIL Write Analog' */

      /* S-Function Block: q_heli3d_skeleton/3-DOF Plant/HIL Write Analog (hil_write_analog_block) */
      {
        t_error result;
        result = hil_write_analog(q_heli3d_skeleton_DWork.HILInitialize_Card,
          q_heli3d_skeleton_P.HILWriteAnalog_Channels, 2,
          q_heli3d_skeleton_B.DACBLimitV);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(q_heli3d_skeleton_M, _rt_error_message);
        }
      }
    }

    /* Gain: '<S1>/Amplifier Gain' */
    q_heli3d_skeleton_B.AmplifierGain[0] =
      q_heli3d_skeleton_P.AmplifierGain_Gain * q_heli3d_skeleton_B.DACBLimitV[0];
    q_heli3d_skeleton_B.AmplifierGain[1] =
      q_heli3d_skeleton_P.AmplifierGain_Gain * q_heli3d_skeleton_B.DACBLimitV[1];
    if (rtmIsMajorTimeStep(q_heli3d_skeleton_M)) {
      /* Bias: '<S1>/Initial Elevation (rad)' incorporates:
       *  Gain: '<S1>/Encoder Resolution: Elevation (rad//count)'
       */
      q_heli3d_skeleton_B.InitialElevationrad =
        q_heli3d_skeleton_P.EncoderResolutionElevationradco *
        rtb_HILReadEncoderTimebase[2] +
        q_heli3d_skeleton_P.InitialElevationrad_Bias;

      /* Gain: '<S1>/Encoder Resolution: Pitch (rad//count)' */
      q_heli3d_skeleton_B.EncoderResolutionPitchradcount =
        q_heli3d_skeleton_P.EncoderResolutionPitchradcount_ *
        rtb_HILReadEncoderTimebase[1];

      /* Gain: '<S1>/Encoder Resolution: Travel (rad//count)' */
      q_heli3d_skeleton_B.EncoderResolutionTravelradcount =
        q_heli3d_skeleton_P.EncoderResolutionTravelradcount *
        rtb_HILReadEncoderTimebase[0];

      /* S-Function (hil_write_digital_block): '<S1>/HIL Write Digital' */

      /* S-Function Block: q_heli3d_skeleton/3-DOF Plant/HIL Write Digital (hil_write_digital_block) */
      {
        t_error result;
        q_heli3d_skeleton_DWork.HILWriteDigital_Buffer[0] =
          (q_heli3d_skeleton_P.EnableAmp_Value[0] != 0);
        q_heli3d_skeleton_DWork.HILWriteDigital_Buffer[1] =
          (q_heli3d_skeleton_P.EnableAmp_Value[1] != 0);
        q_heli3d_skeleton_DWork.HILWriteDigital_Buffer[2] =
          (q_heli3d_skeleton_P.EnableAmp_Value[2] != 0);
        q_heli3d_skeleton_DWork.HILWriteDigital_Buffer[3] =
          (q_heli3d_skeleton_P.EnableAmp_Value[3] != 0);
        result = hil_write_digital(q_heli3d_skeleton_DWork.HILInitialize_Card,
          q_heli3d_skeleton_P.HILWriteDigital_Channels, 4,
          &q_heli3d_skeleton_DWork.HILWriteDigital_Buffer[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(q_heli3d_skeleton_M, _rt_error_message);
        }
      }

      /* RateTransition: '<S3>/Rate Transition: z' */
      if (q_heli3d_skeleton_M->Timing.RateInteraction.TID1_2) {
        q_heli3d_skeleton_B.RateTransitionz =
          q_heli3d_skeleton_DWork.RateTransitionz_Buffer0;
      }

      /* End of RateTransition: '<S3>/Rate Transition: z' */

      /* Product: '<S11>/Divide' incorporates:
       *  Bias: '<S11>/Bias'
       *  Constant: '<S11>/Constant'
       *  Gain: '<S11>/Inverse'
       */
      rtb_SignalGeneratorTravel = (q_heli3d_skeleton_P.Inverse_Gain *
        q_heli3d_skeleton_B.RateTransitionz + q_heli3d_skeleton_P.Bias_Bias_k) /
        q_heli3d_skeleton_P.Constant_Value_c;

      /* RateTransition: '<S3>/Rate Transition: x' */
      if (q_heli3d_skeleton_M->Timing.RateInteraction.TID1_2) {
        q_heli3d_skeleton_B.RateTransitionx =
          q_heli3d_skeleton_DWork.RateTransitionx_Buffer0;
      }

      /* End of RateTransition: '<S3>/Rate Transition: x' */

      /* Gain: '<S3>/Calibration: X  (deg//s//V)' incorporates:
       *  Product: '<S3>/Travel Speed  Adj.'
       */
      q_heli3d_skeleton_B.CalibrationXdegsV = rtb_SignalGeneratorTravel *
        q_heli3d_skeleton_B.RateTransitionx *
        q_heli3d_skeleton_P.CalibrationXdegsV_Gain;

      /* RateTransition: '<S3>/Rate Transition: y' */
      if (q_heli3d_skeleton_M->Timing.RateInteraction.TID1_2) {
        q_heli3d_skeleton_B.RateTransitiony =
          q_heli3d_skeleton_DWork.RateTransitiony_Buffer0;
      }

      /* End of RateTransition: '<S3>/Rate Transition: y' */

      /* Gain: '<S3>/Calibration: Y  (deg//s//V)' incorporates:
       *  Product: '<S3>/Elevation Speed  Adj'
       */
      q_heli3d_skeleton_B.CalibrationYdegsV =
        q_heli3d_skeleton_B.RateTransitiony * rtb_SignalGeneratorTravel *
        q_heli3d_skeleton_P.CalibrationYdegsV_Gain;
    }

    /* Sum: '<Root>/Sum1' */
    q_heli3d_skeleton_B.Sum1[0] = q_heli3d_skeleton_B.InitialElevationrad -
      rtb_MultiportSwitch[0];
    q_heli3d_skeleton_B.Sum1[1] =
      q_heli3d_skeleton_B.EncoderResolutionPitchradcount - rtb_MultiportSwitch[1];
    q_heli3d_skeleton_B.Sum1[2] =
      q_heli3d_skeleton_B.EncoderResolutionTravelradcount - rtb_MultiportSwitch
      [2];
  }

  if (rtmIsMajorTimeStep(q_heli3d_skeleton_M)) {
    int32_T i;

    /* Update for RateLimiter: '<Root>/Des Position Rate Limiter' */
    q_heli3d_skeleton_DWork.PrevY[0] =
      q_heli3d_skeleton_B.DesPositionRateLimiter[0];
    q_heli3d_skeleton_DWork.PrevY[1] =
      q_heli3d_skeleton_B.DesPositionRateLimiter[1];
    q_heli3d_skeleton_DWork.PrevY[2] =
      q_heli3d_skeleton_B.DesPositionRateLimiter[2];
    q_heli3d_skeleton_DWork.LastMajorTime = q_heli3d_skeleton_M->Timing.t[0];

    /* Update for Atomic SubSystem: '<Root>/Observer' */
    for (i = 0; i < 6; i++) {
      /* Gain: '<S4>/Gain2' */
      q_heli3d_skeleton_B.Gain2[i] = 0.0;
      q_heli3d_skeleton_B.Gain2[i] += q_heli3d_skeleton_P.Gain2_Gain[i] *
        q_heli3d_skeleton_B.Bias[0];
      q_heli3d_skeleton_B.Gain2[i] += q_heli3d_skeleton_P.Gain2_Gain[i + 6] *
        q_heli3d_skeleton_B.Bias[1];

      /* Gain: '<S4>/Gain4' */
      q_heli3d_skeleton_B.Gain4[i] = 0.0;
      q_heli3d_skeleton_B.Gain4[i] += q_heli3d_skeleton_P.Gain4_Gain[i] *
        q_heli3d_skeleton_B.Sum1[0];
      q_heli3d_skeleton_B.Gain4[i] += q_heli3d_skeleton_P.Gain4_Gain[i + 6] *
        q_heli3d_skeleton_B.Sum1[1];
      q_heli3d_skeleton_B.Gain4[i] += q_heli3d_skeleton_P.Gain4_Gain[i + 12] *
        q_heli3d_skeleton_B.Sum1[2];

      /* Sum: '<S4>/Sum' */
      q_heli3d_skeleton_B.Sum[i] = (q_heli3d_skeleton_B.Gain2[i] +
        q_heli3d_skeleton_B.Gain4[i]) + q_heli3d_skeleton_B.Gain1[i];
    }

    /* End of Update for SubSystem: '<Root>/Observer' */

    /* External mode */
    rtExtModeUploadCheckTrigger(3);
    rtExtModeUpload(1, q_heli3d_skeleton_M->Timing.t[0]);
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(q_heli3d_skeleton_M)) {
    rt_ertODEUpdateContinuousStates(&q_heli3d_skeleton_M->solverInfo);

    /* Update absolute time */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++q_heli3d_skeleton_M->Timing.clockTick0)) {
      ++q_heli3d_skeleton_M->Timing.clockTickH0;
    }

    q_heli3d_skeleton_M->Timing.t[0] = rtsiGetSolverStopTime
      (&q_heli3d_skeleton_M->solverInfo);

    /* Update absolute time */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.002, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    q_heli3d_skeleton_M->Timing.clockTick1++;
    if (!q_heli3d_skeleton_M->Timing.clockTick1) {
      q_heli3d_skeleton_M->Timing.clockTickH1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void q_heli3d_skeleton_derivatives(void)
{
  int32_T i;
  StateDerivatives_q_heli3d_skele *_rtXdot;
  _rtXdot = ((StateDerivatives_q_heli3d_skele *)
             q_heli3d_skeleton_M->ModelData.derivs);

  /* Derivatives for Integrator: '<S3>/Des Position:  Elevation (deg)' */
  {
    boolean_T lsat;
    boolean_T usat;
    lsat = ( q_heli3d_skeleton_X.DesPositionElevationdeg_CSTATE <=
            q_heli3d_skeleton_P.DesPositionElevationdeg_LowerSa );
    usat = ( q_heli3d_skeleton_X.DesPositionElevationdeg_CSTATE >=
            q_heli3d_skeleton_P.DesPositionElevationdeg_UpperSa );
    if ((!lsat && !usat) ||
        (lsat && (q_heli3d_skeleton_B.CalibrationYdegsV > 0)) ||
        (usat && (q_heli3d_skeleton_B.CalibrationYdegsV < 0)) ) {
      ((StateDerivatives_q_heli3d_skele *) q_heli3d_skeleton_M->ModelData.derivs)
        ->DesPositionElevationdeg_CSTATE = q_heli3d_skeleton_B.CalibrationYdegsV;
    } else {
      /* in saturation */
      ((StateDerivatives_q_heli3d_skele *) q_heli3d_skeleton_M->ModelData.derivs)
        ->DesPositionElevationdeg_CSTATE = 0.0;
    }
  }

  /* Derivatives for Integrator: '<S3>/Des Position:  Travel (deg)' */
  _rtXdot->DesPositionTraveldeg_CSTATE = q_heli3d_skeleton_B.CalibrationXdegsV;

  /* Derivatives for Atomic SubSystem: '<Root>/Observer' */
  for (i = 0; i < 6; i++) {
    /* Gain: '<S4>/Gain2' */
    q_heli3d_skeleton_B.Gain2[i] = 0.0;
    q_heli3d_skeleton_B.Gain2[i] += q_heli3d_skeleton_P.Gain2_Gain[i] *
      q_heli3d_skeleton_B.Bias[0];
    q_heli3d_skeleton_B.Gain2[i] += q_heli3d_skeleton_P.Gain2_Gain[i + 6] *
      q_heli3d_skeleton_B.Bias[1];

    /* Gain: '<S4>/Gain4' */
    q_heli3d_skeleton_B.Gain4[i] = 0.0;
    q_heli3d_skeleton_B.Gain4[i] += q_heli3d_skeleton_P.Gain4_Gain[i] *
      q_heli3d_skeleton_B.Sum1[0];
    q_heli3d_skeleton_B.Gain4[i] += q_heli3d_skeleton_P.Gain4_Gain[i + 6] *
      q_heli3d_skeleton_B.Sum1[1];
    q_heli3d_skeleton_B.Gain4[i] += q_heli3d_skeleton_P.Gain4_Gain[i + 12] *
      q_heli3d_skeleton_B.Sum1[2];

    /* Sum: '<S4>/Sum' */
    q_heli3d_skeleton_B.Sum[i] = (q_heli3d_skeleton_B.Gain2[i] +
      q_heli3d_skeleton_B.Gain4[i]) + q_heli3d_skeleton_B.Gain1[i];

    /* Derivatives for Integrator: '<S4>/Integrator' */
    _rtXdot->Integrator_CSTATE[i] = q_heli3d_skeleton_B.Sum[i];
  }

  /* End of Derivatives for SubSystem: '<Root>/Observer' */
}

/* Model step function for TID2 */
void q_heli3d_skeleton_step2(void)     /* Sample time: [0.01s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_GameController_o4;
  real_T rtb_GameController_o5;
  real_T rtb_GameController_o6;

  /* S-Function (game_controller_block): '<S3>/Game Controller' */

  /* S-Function Block: q_heli3d_skeleton/Desired Position from Joystick/Game Controller (game_controller_block) */
  {
    if (q_heli3d_skeleton_P.GameController_Enabled) {
      t_game_controller_states state;
      t_boolean new_data;
      t_error result;
      result = game_controller_poll
        (q_heli3d_skeleton_DWork.GameController_Controller, &state, &new_data);
      if (result == 0) {
        {
          int_T i1;
          boolean_T *y1 = q_heli3d_skeleton_B.GameController_o2;
          for (i1=0; i1 < 32; i1++) {
            y1[i1] = ((state.buttons & (1U << i1)) != 0);
          }
        }

        rtb_GameController_o4 = state.x;
        rtb_GameController_o5 = state.y;
        rtb_GameController_o6 = state.z;
      }
    } else {
      {
        int_T i1;
        boolean_T *y1 = q_heli3d_skeleton_B.GameController_o2;
        for (i1=0; i1 < 32; i1++) {
          y1[i1] = false;
        }
      }

      rtb_GameController_o4 = 0;
      rtb_GameController_o5 = 0;
      rtb_GameController_o6 = 0;
    }
  }

  /* Stop: '<S3>/Stop Simulation' incorporates:
   *  Constant: '<S3>/Constant'
   *  Logic: '<S3>/Logical Operator'
   */
  if (q_heli3d_skeleton_B.GameController_o2[0] &&
      (q_heli3d_skeleton_P.Constant_Value_l != 0.0)) {
    rtmSetStopRequested(q_heli3d_skeleton_M, 1);
  }

  /* End of Stop: '<S3>/Stop Simulation' */

  /* Update for RateTransition: '<S3>/Rate Transition: z' */
  q_heli3d_skeleton_DWork.RateTransitionz_Buffer0 = rtb_GameController_o6;

  /* Update for RateTransition: '<S3>/Rate Transition: x' */
  q_heli3d_skeleton_DWork.RateTransitionx_Buffer0 = rtb_GameController_o4;

  /* Update for RateTransition: '<S3>/Rate Transition: y' */
  q_heli3d_skeleton_DWork.RateTransitiony_Buffer0 = rtb_GameController_o5;
  rtExtModeUpload(2, (((q_heli3d_skeleton_M->Timing.clockTick2+
                        q_heli3d_skeleton_M->Timing.clockTickH2* 4294967296.0)) *
                      0.01));

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.01, which is the step size
   * of the task. Size of "clockTick2" ensures timer will not overflow during the
   * application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick2 and the high bits
   * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
   */
  q_heli3d_skeleton_M->Timing.clockTick2++;
  if (!q_heli3d_skeleton_M->Timing.clockTick2) {
    q_heli3d_skeleton_M->Timing.clockTickH2++;
  }
}

void q_heli3d_skeleton_step(int_T tid)
{
  switch (tid) {
   case 0 :
    q_heli3d_skeleton_step0();
    break;

   case 2 :
    q_heli3d_skeleton_step2();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void q_heli3d_skeleton_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)q_heli3d_skeleton_M, 0,
                sizeof(RT_MODEL_q_heli3d_skeleton));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&q_heli3d_skeleton_M->solverInfo,
                          &q_heli3d_skeleton_M->Timing.simTimeStep);
    rtsiSetTPtr(&q_heli3d_skeleton_M->solverInfo, &rtmGetTPtr
                (q_heli3d_skeleton_M));
    rtsiSetStepSizePtr(&q_heli3d_skeleton_M->solverInfo,
                       &q_heli3d_skeleton_M->Timing.stepSize0);
    rtsiSetdXPtr(&q_heli3d_skeleton_M->solverInfo,
                 &q_heli3d_skeleton_M->ModelData.derivs);
    rtsiSetContStatesPtr(&q_heli3d_skeleton_M->solverInfo,
                         &q_heli3d_skeleton_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&q_heli3d_skeleton_M->solverInfo,
      &q_heli3d_skeleton_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&q_heli3d_skeleton_M->solverInfo, (&rtmGetErrorStatus
      (q_heli3d_skeleton_M)));
    rtsiSetRTModelPtr(&q_heli3d_skeleton_M->solverInfo, q_heli3d_skeleton_M);
  }

  rtsiSetSimTimeStep(&q_heli3d_skeleton_M->solverInfo, MAJOR_TIME_STEP);
  q_heli3d_skeleton_M->ModelData.intgData.f[0] =
    q_heli3d_skeleton_M->ModelData.odeF[0];
  q_heli3d_skeleton_M->ModelData.contStates = ((real_T *) &q_heli3d_skeleton_X);
  rtsiSetSolverData(&q_heli3d_skeleton_M->solverInfo, (void *)
                    &q_heli3d_skeleton_M->ModelData.intgData);
  rtsiSetSolverName(&q_heli3d_skeleton_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = q_heli3d_skeleton_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    q_heli3d_skeleton_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    q_heli3d_skeleton_M->Timing.sampleTimes =
      (&q_heli3d_skeleton_M->Timing.sampleTimesArray[0]);
    q_heli3d_skeleton_M->Timing.offsetTimes =
      (&q_heli3d_skeleton_M->Timing.offsetTimesArray[0]);

    /* task periods */
    q_heli3d_skeleton_M->Timing.sampleTimes[0] = (0.0);
    q_heli3d_skeleton_M->Timing.sampleTimes[1] = (0.002);
    q_heli3d_skeleton_M->Timing.sampleTimes[2] = (0.01);

    /* task offsets */
    q_heli3d_skeleton_M->Timing.offsetTimes[0] = (0.0);
    q_heli3d_skeleton_M->Timing.offsetTimes[1] = (0.0);
    q_heli3d_skeleton_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(q_heli3d_skeleton_M, &q_heli3d_skeleton_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = q_heli3d_skeleton_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits =
      q_heli3d_skeleton_M->Timing.perTaskSampleHitsArray;
    q_heli3d_skeleton_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    q_heli3d_skeleton_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(q_heli3d_skeleton_M, -1);
  q_heli3d_skeleton_M->Timing.stepSize0 = 0.002;

  /* External mode info */
  q_heli3d_skeleton_M->Sizes.checksums[0] = (2053634143U);
  q_heli3d_skeleton_M->Sizes.checksums[1] = (269281018U);
  q_heli3d_skeleton_M->Sizes.checksums[2] = (3300606927U);
  q_heli3d_skeleton_M->Sizes.checksums[3] = (1460317102U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[7];
    q_heli3d_skeleton_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(q_heli3d_skeleton_M->extModeInfo,
      &q_heli3d_skeleton_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(q_heli3d_skeleton_M->extModeInfo,
                        q_heli3d_skeleton_M->Sizes.checksums);
    rteiSetTPtr(q_heli3d_skeleton_M->extModeInfo, rtmGetTPtr(q_heli3d_skeleton_M));
  }

  q_heli3d_skeleton_M->solverInfoPtr = (&q_heli3d_skeleton_M->solverInfo);
  q_heli3d_skeleton_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&q_heli3d_skeleton_M->solverInfo, 0.002);
  rtsiSetSolverMode(&q_heli3d_skeleton_M->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  (void) memset(((void *) &q_heli3d_skeleton_B), 0,
                sizeof(BlockIO_q_heli3d_skeleton));

  {
    int_T i;
    for (i = 0; i < 6; i++) {
      q_heli3d_skeleton_B.Integrator[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      q_heli3d_skeleton_B.Gain1[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      q_heli3d_skeleton_B.Gain2[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      q_heli3d_skeleton_B.Gain4[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      q_heli3d_skeleton_B.Sum[i] = 0.0;
    }

    q_heli3d_skeleton_B.Program1Joystick2 = 0.0;
    q_heli3d_skeleton_B.SliderGain = 0.0;
    q_heli3d_skeleton_B.ConstantPitchdeg = 0.0;
    q_heli3d_skeleton_B.SliderGain_l = 0.0;
    q_heli3d_skeleton_B.Constant = 0.0;
    q_heli3d_skeleton_B.ConstantPitchdeg_j = 0.0;
    q_heli3d_skeleton_B.DesPositionRateLimiter[0] = 0.0;
    q_heli3d_skeleton_B.DesPositionRateLimiter[1] = 0.0;
    q_heli3d_skeleton_B.DesPositionRateLimiter[2] = 0.0;
    q_heli3d_skeleton_B.desvel = 0.0;
    q_heli3d_skeleton_B.Bias[0] = 0.0;
    q_heli3d_skeleton_B.Bias[1] = 0.0;
    q_heli3d_skeleton_B.DACBLimitV[0] = 0.0;
    q_heli3d_skeleton_B.DACBLimitV[1] = 0.0;
    q_heli3d_skeleton_B.AmplifierGain[0] = 0.0;
    q_heli3d_skeleton_B.AmplifierGain[1] = 0.0;
    q_heli3d_skeleton_B.InitialElevationrad = 0.0;
    q_heli3d_skeleton_B.EncoderResolutionPitchradcount = 0.0;
    q_heli3d_skeleton_B.EncoderResolutionTravelradcount = 0.0;
    q_heli3d_skeleton_B.RateTransitionz = 0.0;
    q_heli3d_skeleton_B.RateTransitionx = 0.0;
    q_heli3d_skeleton_B.CalibrationXdegsV = 0.0;
    q_heli3d_skeleton_B.RateTransitiony = 0.0;
    q_heli3d_skeleton_B.CalibrationYdegsV = 0.0;
    q_heli3d_skeleton_B.Sum1[0] = 0.0;
    q_heli3d_skeleton_B.Sum1[1] = 0.0;
    q_heli3d_skeleton_B.Sum1[2] = 0.0;
  }

  /* states (continuous) */
  {
    (void) memset((void *)&q_heli3d_skeleton_X, 0,
                  sizeof(ContinuousStates_q_heli3d_skele));
  }

  /* states (dwork) */
  (void) memset((void *)&q_heli3d_skeleton_DWork, 0,
                sizeof(D_Work_q_heli3d_skeleton));
  q_heli3d_skeleton_DWork.HILInitialize_AIMinimums[0] = 0.0;
  q_heli3d_skeleton_DWork.HILInitialize_AIMinimums[1] = 0.0;
  q_heli3d_skeleton_DWork.HILInitialize_AIMinimums[2] = 0.0;
  q_heli3d_skeleton_DWork.HILInitialize_AIMinimums[3] = 0.0;
  q_heli3d_skeleton_DWork.HILInitialize_AIMaximums[0] = 0.0;
  q_heli3d_skeleton_DWork.HILInitialize_AIMaximums[1] = 0.0;
  q_heli3d_skeleton_DWork.HILInitialize_AIMaximums[2] = 0.0;
  q_heli3d_skeleton_DWork.HILInitialize_AIMaximums[3] = 0.0;
  q_heli3d_skeleton_DWork.HILInitialize_AOMinimums[0] = 0.0;
  q_heli3d_skeleton_DWork.HILInitialize_AOMinimums[1] = 0.0;
  q_heli3d_skeleton_DWork.HILInitialize_AOMinimums[2] = 0.0;
  q_heli3d_skeleton_DWork.HILInitialize_AOMinimums[3] = 0.0;
  q_heli3d_skeleton_DWork.HILInitialize_AOMaximums[0] = 0.0;
  q_heli3d_skeleton_DWork.HILInitialize_AOMaximums[1] = 0.0;
  q_heli3d_skeleton_DWork.HILInitialize_AOMaximums[2] = 0.0;
  q_heli3d_skeleton_DWork.HILInitialize_AOMaximums[3] = 0.0;
  q_heli3d_skeleton_DWork.HILInitialize_AOVoltages[0] = 0.0;
  q_heli3d_skeleton_DWork.HILInitialize_AOVoltages[1] = 0.0;
  q_heli3d_skeleton_DWork.HILInitialize_AOVoltages[2] = 0.0;
  q_heli3d_skeleton_DWork.HILInitialize_AOVoltages[3] = 0.0;
  q_heli3d_skeleton_DWork.HILInitialize_FilterFrequency[0] = 0.0;
  q_heli3d_skeleton_DWork.HILInitialize_FilterFrequency[1] = 0.0;
  q_heli3d_skeleton_DWork.HILInitialize_FilterFrequency[2] = 0.0;
  q_heli3d_skeleton_DWork.HILInitialize_FilterFrequency[3] = 0.0;
  q_heli3d_skeleton_DWork.PrevY[0] = 0.0;
  q_heli3d_skeleton_DWork.PrevY[1] = 0.0;
  q_heli3d_skeleton_DWork.PrevY[2] = 0.0;
  q_heli3d_skeleton_DWork.LastMajorTime = 0.0;
  q_heli3d_skeleton_DWork.RateTransitionz_Buffer0 = 0.0;
  q_heli3d_skeleton_DWork.RateTransitionx_Buffer0 = 0.0;
  q_heli3d_skeleton_DWork.RateTransitiony_Buffer0 = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    q_heli3d_skeleton_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 18;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Initialize Sizes */
  q_heli3d_skeleton_M->Sizes.numContStates = (8);/* Number of continuous states */
  q_heli3d_skeleton_M->Sizes.numY = (0);/* Number of model outputs */
  q_heli3d_skeleton_M->Sizes.numU = (0);/* Number of model inputs */
  q_heli3d_skeleton_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  q_heli3d_skeleton_M->Sizes.numSampTimes = (3);/* Number of sample times */
  q_heli3d_skeleton_M->Sizes.numBlocks = (78);/* Number of blocks */
  q_heli3d_skeleton_M->Sizes.numBlockIO = (27);/* Number of block outputs */
  q_heli3d_skeleton_M->Sizes.numBlockPrms = (264);/* Sum of parameter "widths" */

  /* Start for S-Function (hil_initialize_block): '<S1>/HIL Initialize' */

  /* S-Function Block: q_heli3d_skeleton/3-DOF Plant/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q4", "0", &q_heli3d_skeleton_DWork.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(q_heli3d_skeleton_M, _rt_error_message);
      return;
    }

    is_switching = false;
    if ((q_heli3d_skeleton_P.HILInitialize_CKPStart && !is_switching) ||
        (q_heli3d_skeleton_P.HILInitialize_CKPEnter && is_switching)) {
      result = hil_set_clock_mode(q_heli3d_skeleton_DWork.HILInitialize_Card,
        (t_clock *) q_heli3d_skeleton_P.HILInitialize_CKChannels, 2U,
        (t_clock_mode *) q_heli3d_skeleton_P.HILInitialize_CKModes);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_heli3d_skeleton_M, _rt_error_message);
        return;
      }
    }

    result = hil_watchdog_clear(q_heli3d_skeleton_DWork.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(q_heli3d_skeleton_M, _rt_error_message);
      return;
    }

    if ((q_heli3d_skeleton_P.HILInitialize_AIPStart && !is_switching) ||
        (q_heli3d_skeleton_P.HILInitialize_AIPEnter && is_switching)) {
      q_heli3d_skeleton_DWork.HILInitialize_AIMinimums[0] =
        q_heli3d_skeleton_P.HILInitialize_AILow;
      q_heli3d_skeleton_DWork.HILInitialize_AIMinimums[1] =
        q_heli3d_skeleton_P.HILInitialize_AILow;
      q_heli3d_skeleton_DWork.HILInitialize_AIMinimums[2] =
        q_heli3d_skeleton_P.HILInitialize_AILow;
      q_heli3d_skeleton_DWork.HILInitialize_AIMinimums[3] =
        q_heli3d_skeleton_P.HILInitialize_AILow;
      q_heli3d_skeleton_DWork.HILInitialize_AIMaximums[0] =
        q_heli3d_skeleton_P.HILInitialize_AIHigh;
      q_heli3d_skeleton_DWork.HILInitialize_AIMaximums[1] =
        q_heli3d_skeleton_P.HILInitialize_AIHigh;
      q_heli3d_skeleton_DWork.HILInitialize_AIMaximums[2] =
        q_heli3d_skeleton_P.HILInitialize_AIHigh;
      q_heli3d_skeleton_DWork.HILInitialize_AIMaximums[3] =
        q_heli3d_skeleton_P.HILInitialize_AIHigh;
      result = hil_set_analog_input_ranges
        (q_heli3d_skeleton_DWork.HILInitialize_Card,
         q_heli3d_skeleton_P.HILInitialize_AIChannels, 4U,
         &q_heli3d_skeleton_DWork.HILInitialize_AIMinimums[0],
         &q_heli3d_skeleton_DWork.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_heli3d_skeleton_M, _rt_error_message);
        return;
      }
    }

    if ((q_heli3d_skeleton_P.HILInitialize_AOPStart && !is_switching) ||
        (q_heli3d_skeleton_P.HILInitialize_AOPEnter && is_switching)) {
      q_heli3d_skeleton_DWork.HILInitialize_AOMinimums[0] =
        q_heli3d_skeleton_P.HILInitialize_AOLow;
      q_heli3d_skeleton_DWork.HILInitialize_AOMinimums[1] =
        q_heli3d_skeleton_P.HILInitialize_AOLow;
      q_heli3d_skeleton_DWork.HILInitialize_AOMinimums[2] =
        q_heli3d_skeleton_P.HILInitialize_AOLow;
      q_heli3d_skeleton_DWork.HILInitialize_AOMinimums[3] =
        q_heli3d_skeleton_P.HILInitialize_AOLow;
      q_heli3d_skeleton_DWork.HILInitialize_AOMaximums[0] =
        q_heli3d_skeleton_P.HILInitialize_AOHigh;
      q_heli3d_skeleton_DWork.HILInitialize_AOMaximums[1] =
        q_heli3d_skeleton_P.HILInitialize_AOHigh;
      q_heli3d_skeleton_DWork.HILInitialize_AOMaximums[2] =
        q_heli3d_skeleton_P.HILInitialize_AOHigh;
      q_heli3d_skeleton_DWork.HILInitialize_AOMaximums[3] =
        q_heli3d_skeleton_P.HILInitialize_AOHigh;
      result = hil_set_analog_output_ranges
        (q_heli3d_skeleton_DWork.HILInitialize_Card,
         q_heli3d_skeleton_P.HILInitialize_AOChannels, 4U,
         &q_heli3d_skeleton_DWork.HILInitialize_AOMinimums[0],
         &q_heli3d_skeleton_DWork.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_heli3d_skeleton_M, _rt_error_message);
        return;
      }
    }

    if ((q_heli3d_skeleton_P.HILInitialize_AOStart && !is_switching) ||
        (q_heli3d_skeleton_P.HILInitialize_AOEnter && is_switching)) {
      q_heli3d_skeleton_DWork.HILInitialize_AOVoltages[0] =
        q_heli3d_skeleton_P.HILInitialize_AOInitial;
      q_heli3d_skeleton_DWork.HILInitialize_AOVoltages[1] =
        q_heli3d_skeleton_P.HILInitialize_AOInitial;
      q_heli3d_skeleton_DWork.HILInitialize_AOVoltages[2] =
        q_heli3d_skeleton_P.HILInitialize_AOInitial;
      q_heli3d_skeleton_DWork.HILInitialize_AOVoltages[3] =
        q_heli3d_skeleton_P.HILInitialize_AOInitial;
      result = hil_write_analog(q_heli3d_skeleton_DWork.HILInitialize_Card,
        q_heli3d_skeleton_P.HILInitialize_AOChannels, 4U,
        &q_heli3d_skeleton_DWork.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_heli3d_skeleton_M, _rt_error_message);
        return;
      }
    }

    if (q_heli3d_skeleton_P.HILInitialize_AOReset) {
      q_heli3d_skeleton_DWork.HILInitialize_AOVoltages[0] =
        q_heli3d_skeleton_P.HILInitialize_AOWatchdog;
      q_heli3d_skeleton_DWork.HILInitialize_AOVoltages[1] =
        q_heli3d_skeleton_P.HILInitialize_AOWatchdog;
      q_heli3d_skeleton_DWork.HILInitialize_AOVoltages[2] =
        q_heli3d_skeleton_P.HILInitialize_AOWatchdog;
      q_heli3d_skeleton_DWork.HILInitialize_AOVoltages[3] =
        q_heli3d_skeleton_P.HILInitialize_AOWatchdog;
      result = hil_watchdog_set_analog_expiration_state
        (q_heli3d_skeleton_DWork.HILInitialize_Card,
         q_heli3d_skeleton_P.HILInitialize_AOChannels, 4U,
         &q_heli3d_skeleton_DWork.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_heli3d_skeleton_M, _rt_error_message);
        return;
      }
    }

    result = hil_set_digital_directions
      (q_heli3d_skeleton_DWork.HILInitialize_Card,
       q_heli3d_skeleton_P.HILInitialize_DIChannels, 8U,
       q_heli3d_skeleton_P.HILInitialize_DOChannels, 8U);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(q_heli3d_skeleton_M, _rt_error_message);
      return;
    }

    if ((q_heli3d_skeleton_P.HILInitialize_DOStart && !is_switching) ||
        (q_heli3d_skeleton_P.HILInitialize_DOEnter && is_switching)) {
      {
        int_T i1;
        boolean_T *dw_DOBits = &q_heli3d_skeleton_DWork.HILInitialize_DOBits[0];
        for (i1=0; i1 < 8; i1++) {
          dw_DOBits[i1] = q_heli3d_skeleton_P.HILInitialize_DOInitial;
        }
      }

      result = hil_write_digital(q_heli3d_skeleton_DWork.HILInitialize_Card,
        q_heli3d_skeleton_P.HILInitialize_DOChannels, 8U, (t_boolean *)
        &q_heli3d_skeleton_DWork.HILInitialize_DOBits[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_heli3d_skeleton_M, _rt_error_message);
        return;
      }
    }

    if (q_heli3d_skeleton_P.HILInitialize_DOReset) {
      {
        int_T i1;
        int32_T *dw_DOStates = &q_heli3d_skeleton_DWork.HILInitialize_DOStates[0];
        for (i1=0; i1 < 8; i1++) {
          dw_DOStates[i1] = q_heli3d_skeleton_P.HILInitialize_DOWatchdog;
        }
      }

      result = hil_watchdog_set_digital_expiration_state
        (q_heli3d_skeleton_DWork.HILInitialize_Card,
         q_heli3d_skeleton_P.HILInitialize_DOChannels, 8U, (const
          t_digital_state *) &q_heli3d_skeleton_DWork.HILInitialize_DOStates[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_heli3d_skeleton_M, _rt_error_message);
        return;
      }
    }

    if ((q_heli3d_skeleton_P.HILInitialize_EIPStart && !is_switching) ||
        (q_heli3d_skeleton_P.HILInitialize_EIPEnter && is_switching)) {
      q_heli3d_skeleton_DWork.HILInitialize_QuadratureModes[0] =
        q_heli3d_skeleton_P.HILInitialize_EIQuadrature;
      q_heli3d_skeleton_DWork.HILInitialize_QuadratureModes[1] =
        q_heli3d_skeleton_P.HILInitialize_EIQuadrature;
      q_heli3d_skeleton_DWork.HILInitialize_QuadratureModes[2] =
        q_heli3d_skeleton_P.HILInitialize_EIQuadrature;
      q_heli3d_skeleton_DWork.HILInitialize_QuadratureModes[3] =
        q_heli3d_skeleton_P.HILInitialize_EIQuadrature;
      result = hil_set_encoder_quadrature_mode
        (q_heli3d_skeleton_DWork.HILInitialize_Card,
         q_heli3d_skeleton_P.HILInitialize_EIChannels, 4U,
         (t_encoder_quadrature_mode *)
         &q_heli3d_skeleton_DWork.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_heli3d_skeleton_M, _rt_error_message);
        return;
      }

      q_heli3d_skeleton_DWork.HILInitialize_FilterFrequency[0] =
        q_heli3d_skeleton_P.HILInitialize_EIFrequency;
      q_heli3d_skeleton_DWork.HILInitialize_FilterFrequency[1] =
        q_heli3d_skeleton_P.HILInitialize_EIFrequency;
      q_heli3d_skeleton_DWork.HILInitialize_FilterFrequency[2] =
        q_heli3d_skeleton_P.HILInitialize_EIFrequency;
      q_heli3d_skeleton_DWork.HILInitialize_FilterFrequency[3] =
        q_heli3d_skeleton_P.HILInitialize_EIFrequency;
      result = hil_set_encoder_filter_frequency
        (q_heli3d_skeleton_DWork.HILInitialize_Card,
         q_heli3d_skeleton_P.HILInitialize_EIChannels, 4U,
         &q_heli3d_skeleton_DWork.HILInitialize_FilterFrequency[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_heli3d_skeleton_M, _rt_error_message);
        return;
      }
    }

    if ((q_heli3d_skeleton_P.HILInitialize_EIStart && !is_switching) ||
        (q_heli3d_skeleton_P.HILInitialize_EIEnter && is_switching)) {
      q_heli3d_skeleton_DWork.HILInitialize_InitialEICounts[0] =
        q_heli3d_skeleton_P.HILInitialize_EIInitial;
      q_heli3d_skeleton_DWork.HILInitialize_InitialEICounts[1] =
        q_heli3d_skeleton_P.HILInitialize_EIInitial;
      q_heli3d_skeleton_DWork.HILInitialize_InitialEICounts[2] =
        q_heli3d_skeleton_P.HILInitialize_EIInitial;
      q_heli3d_skeleton_DWork.HILInitialize_InitialEICounts[3] =
        q_heli3d_skeleton_P.HILInitialize_EIInitial;
      result = hil_set_encoder_counts(q_heli3d_skeleton_DWork.HILInitialize_Card,
        q_heli3d_skeleton_P.HILInitialize_EIChannels, 4U,
        &q_heli3d_skeleton_DWork.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_heli3d_skeleton_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_encoder_timebase_block): '<S1>/HIL Read Encoder Timebase' */

  /* S-Function Block: q_heli3d_skeleton/3-DOF Plant/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader
      (q_heli3d_skeleton_DWork.HILInitialize_Card,
       q_heli3d_skeleton_P.HILReadEncoderTimebase_SamplesI,
       q_heli3d_skeleton_P.HILReadEncoderTimebase_Channels, 3,
       &q_heli3d_skeleton_DWork.HILReadEncoderTimebase_Task);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(q_heli3d_skeleton_M, _rt_error_message);
    }
  }

  /* Start for S-Function (game_controller_block): '<S3>/Game Controller' */

  /* S-Function Block: q_heli3d_skeleton/Desired Position from Joystick/Game Controller (game_controller_block) */
  {
    if (q_heli3d_skeleton_P.GameController_Enabled) {
      t_double deadzone[6];
      t_double saturation[6];
      t_int index;
      t_error result;
      for (index = 0; index < 6; index++) {
        deadzone[index] = -1;
      }

      for (index = 0; index < 6; index++) {
        saturation[index] = -1;
      }

      result = game_controller_open
        (q_heli3d_skeleton_P.GameController_ControllerNumber,
         q_heli3d_skeleton_P.GameController_BufferSize, deadzone, saturation,
         q_heli3d_skeleton_P.GameController_AutoCenter, 0, 1.0,
         &q_heli3d_skeleton_DWork.GameController_Controller);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_heli3d_skeleton_M, _rt_error_message);
      }
    }
  }

  /* Start for RateTransition: '<S3>/Rate Transition: z' */
  q_heli3d_skeleton_B.RateTransitionz = q_heli3d_skeleton_P.RateTransitionz_X0;

  /* Start for RateTransition: '<S3>/Rate Transition: x' */
  q_heli3d_skeleton_B.RateTransitionx = q_heli3d_skeleton_P.RateTransitionx_X0;

  /* Start for RateTransition: '<S3>/Rate Transition: y' */
  q_heli3d_skeleton_B.RateTransitiony = q_heli3d_skeleton_P.RateTransitiony_X0;

  {
    int32_T i;

    /* InitializeConditions for Integrator: '<S3>/Des Position:  Elevation (deg)' */
    q_heli3d_skeleton_X.DesPositionElevationdeg_CSTATE =
      q_heli3d_skeleton_P.DesPositionElevationdeg_IC;

    /* InitializeConditions for Integrator: '<S3>/Des Position:  Travel (deg)' */
    q_heli3d_skeleton_X.DesPositionTraveldeg_CSTATE =
      q_heli3d_skeleton_P.DesPositionTraveldeg_IC;

    /* InitializeConditions for RateLimiter: '<Root>/Des Position Rate Limiter' */
    q_heli3d_skeleton_DWork.LastMajorTime = (rtInf);

    /* InitializeConditions for Atomic SubSystem: '<Root>/Observer' */
    /* InitializeConditions for Integrator: '<S4>/Integrator' */
    for (i = 0; i < 6; i++) {
      q_heli3d_skeleton_X.Integrator_CSTATE[i] =
        q_heli3d_skeleton_P.Integrator_IC;
    }

    /* End of InitializeConditions for Integrator: '<S4>/Integrator' */
    /* End of InitializeConditions for SubSystem: '<Root>/Observer' */

    /* InitializeConditions for RateTransition: '<S3>/Rate Transition: z' */
    q_heli3d_skeleton_DWork.RateTransitionz_Buffer0 =
      q_heli3d_skeleton_P.RateTransitionz_X0;

    /* InitializeConditions for RateTransition: '<S3>/Rate Transition: x' */
    q_heli3d_skeleton_DWork.RateTransitionx_Buffer0 =
      q_heli3d_skeleton_P.RateTransitionx_X0;

    /* InitializeConditions for RateTransition: '<S3>/Rate Transition: y' */
    q_heli3d_skeleton_DWork.RateTransitiony_Buffer0 =
      q_heli3d_skeleton_P.RateTransitiony_X0;
  }
}

/* Model terminate function */
void q_heli3d_skeleton_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<S1>/HIL Initialize' */

  /* S-Function Block: q_heli3d_skeleton/3-DOF Plant/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_digital_outputs = 0;
    hil_task_stop_all(q_heli3d_skeleton_DWork.HILInitialize_Card);
    hil_monitor_stop_all(q_heli3d_skeleton_DWork.HILInitialize_Card);
    is_switching = false;
    if ((q_heli3d_skeleton_P.HILInitialize_AOTerminate && !is_switching) ||
        (q_heli3d_skeleton_P.HILInitialize_AOExit && is_switching)) {
      q_heli3d_skeleton_DWork.HILInitialize_AOVoltages[0] =
        q_heli3d_skeleton_P.HILInitialize_AOFinal;
      q_heli3d_skeleton_DWork.HILInitialize_AOVoltages[1] =
        q_heli3d_skeleton_P.HILInitialize_AOFinal;
      q_heli3d_skeleton_DWork.HILInitialize_AOVoltages[2] =
        q_heli3d_skeleton_P.HILInitialize_AOFinal;
      q_heli3d_skeleton_DWork.HILInitialize_AOVoltages[3] =
        q_heli3d_skeleton_P.HILInitialize_AOFinal;
      num_final_analog_outputs = 4U;
    }

    if ((q_heli3d_skeleton_P.HILInitialize_DOTerminate && !is_switching) ||
        (q_heli3d_skeleton_P.HILInitialize_DOExit && is_switching)) {
      {
        int_T i1;
        boolean_T *dw_DOBits = &q_heli3d_skeleton_DWork.HILInitialize_DOBits[0];
        for (i1=0; i1 < 8; i1++) {
          dw_DOBits[i1] = q_heli3d_skeleton_P.HILInitialize_DOFinal;
        }
      }

      num_final_digital_outputs = 8U;
    }

    if (0
        || num_final_analog_outputs > 0
        || num_final_digital_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(q_heli3d_skeleton_DWork.HILInitialize_Card
                         , q_heli3d_skeleton_P.HILInitialize_AOChannels,
                         num_final_analog_outputs
                         , NULL, 0
                         , q_heli3d_skeleton_P.HILInitialize_DOChannels,
                         num_final_digital_outputs
                         , NULL, 0
                         , &q_heli3d_skeleton_DWork.HILInitialize_AOVoltages[0]
                         , NULL
                         , &q_heli3d_skeleton_DWork.HILInitialize_DOBits[0]
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog
            (q_heli3d_skeleton_DWork.HILInitialize_Card,
             q_heli3d_skeleton_P.HILInitialize_AOChannels,
             num_final_analog_outputs,
             &q_heli3d_skeleton_DWork.HILInitialize_AOVoltages[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_digital_outputs > 0) {
          local_result = hil_write_digital
            (q_heli3d_skeleton_DWork.HILInitialize_Card,
             q_heli3d_skeleton_P.HILInitialize_DOChannels,
             num_final_digital_outputs,
             &q_heli3d_skeleton_DWork.HILInitialize_DOBits[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(q_heli3d_skeleton_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(q_heli3d_skeleton_DWork.HILInitialize_Card);
    hil_monitor_delete_all(q_heli3d_skeleton_DWork.HILInitialize_Card);
    hil_close(q_heli3d_skeleton_DWork.HILInitialize_Card);
    q_heli3d_skeleton_DWork.HILInitialize_Card = NULL;
  }

  /* Terminate for S-Function (game_controller_block): '<S3>/Game Controller' */

  /* S-Function Block: q_heli3d_skeleton/Desired Position from Joystick/Game Controller (game_controller_block) */
  {
    if (q_heli3d_skeleton_P.GameController_Enabled) {
      game_controller_close(q_heli3d_skeleton_DWork.GameController_Controller);
      q_heli3d_skeleton_DWork.GameController_Controller = NULL;
    }
  }
}
