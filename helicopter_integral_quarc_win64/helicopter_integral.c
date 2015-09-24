/*
 * helicopter_integral.c
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
#include "helicopter_integral.h"
#include "helicopter_integral_private.h"
#include "helicopter_integral_dt.h"

/* Block signals (auto storage) */
BlockIO_helicopter_integral helicopter_integral_B;

/* Continuous states */
ContinuousStates_helicopter_int helicopter_integral_X;

/* Block states (auto storage) */
D_Work_helicopter_integral helicopter_integral_DWork;

/* Real-time model */
RT_MODEL_helicopter_integral helicopter_integral_M_;
RT_MODEL_helicopter_integral *const helicopter_integral_M =
  &helicopter_integral_M_;
static void rate_monotonic_scheduler(void);
time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(helicopter_integral_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(helicopter_integral_M, 2);
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
  if (helicopter_integral_M->Timing.TaskCounters.TID[1] == 0) {
    helicopter_integral_M->Timing.RateInteraction.TID1_2 =
      (helicopter_integral_M->Timing.TaskCounters.TID[2] == 0);
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (helicopter_integral_M->Timing.TaskCounters.TID[2])++;
  if ((helicopter_integral_M->Timing.TaskCounters.TID[2]) > 4) {/* Sample time: [0.01s, 0.0s] */
    helicopter_integral_M->Timing.TaskCounters.TID[2] = 0;
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
  int_T nXc = 14;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  helicopter_integral_derivatives();
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
void helicopter_integral_step0(void)   /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_Clock;
  real_T rtb_DesPositionElevationdeg;
  real_T rtb_HILReadEncoderTimebase[3];
  if (rtmIsMajorTimeStep(helicopter_integral_M)) {
    /* set solver stop time */
    if (!(helicopter_integral_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&helicopter_integral_M->solverInfo,
                            ((helicopter_integral_M->Timing.clockTickH0 + 1) *
        helicopter_integral_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&helicopter_integral_M->solverInfo,
                            ((helicopter_integral_M->Timing.clockTick0 + 1) *
        helicopter_integral_M->Timing.stepSize0 +
        helicopter_integral_M->Timing.clockTickH0 *
        helicopter_integral_M->Timing.stepSize0 * 4294967296.0));
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(helicopter_integral_M)) {
    helicopter_integral_M->Timing.t[0] = rtsiGetT
      (&helicopter_integral_M->solverInfo);
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
    if (rtmIsMajorTimeStep(helicopter_integral_M)) {
      /* S-Function (hil_read_encoder_timebase_block): '<S1>/HIL Read Encoder Timebase' */

      /* S-Function Block: helicopter_integral/3-DOF Plant/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
      {
        t_error result;
        result = hil_task_read_encoder
          (helicopter_integral_DWork.HILReadEncoderTimebase_Task, 1,
           &helicopter_integral_DWork.HILReadEncoderTimebase_Buffer[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(helicopter_integral_M, _rt_error_message);
        } else {
          rtb_HILReadEncoderTimebase[0] =
            helicopter_integral_DWork.HILReadEncoderTimebase_Buffer[0];
          rtb_HILReadEncoderTimebase[1] =
            helicopter_integral_DWork.HILReadEncoderTimebase_Buffer[1];
          rtb_HILReadEncoderTimebase[2] =
            helicopter_integral_DWork.HILReadEncoderTimebase_Buffer[2];
        }
      }

      /* Constant: '<Root>/Program = 1 Joystick = 2' */
      helicopter_integral_B.Program1Joystick2 =
        helicopter_integral_P.Program1Joystick2_Value;
    }

    /* SignalGenerator: '<S2>/Signal Generator: Elevation' */
    rtb_SignalGeneratorTravel =
      helicopter_integral_P.SignalGeneratorElevation_Freque *
      helicopter_integral_M->Timing.t[0];
    if (rtb_SignalGeneratorTravel - floor(rtb_SignalGeneratorTravel) >= 0.5) {
      rtb_SignalGeneratorElevation =
        helicopter_integral_P.SignalGeneratorElevation_Amplit;
    } else {
      rtb_SignalGeneratorElevation =
        -helicopter_integral_P.SignalGeneratorElevation_Amplit;
    }

    /* End of SignalGenerator: '<S2>/Signal Generator: Elevation' */
    if (rtmIsMajorTimeStep(helicopter_integral_M)) {
      /* Gain: '<S6>/Slider Gain' incorporates:
       *  Constant: '<S2>/Elev Constant'
       */
      helicopter_integral_B.SliderGain = helicopter_integral_P.SliderGain_Gain *
        helicopter_integral_P.ElevConstant_Value;

      /* Constant: '<S2>/Constant: Pitch (deg)' */
      helicopter_integral_B.ConstantPitchdeg =
        helicopter_integral_P.ConstantPitchdeg_Value;
    }

    /* SignalGenerator: '<S2>/Signal Generator: Travel' */
    rtb_SignalGeneratorTravel =
      helicopter_integral_P.SignalGeneratorTravel_Frequency *
      helicopter_integral_M->Timing.t[0];
    if (rtb_SignalGeneratorTravel - floor(rtb_SignalGeneratorTravel) >= 0.5) {
      rtb_SignalGeneratorTravel =
        helicopter_integral_P.SignalGeneratorTravel_Amplitude;
    } else {
      rtb_SignalGeneratorTravel =
        -helicopter_integral_P.SignalGeneratorTravel_Amplitude;
    }

    /* End of SignalGenerator: '<S2>/Signal Generator: Travel' */
    if (rtmIsMajorTimeStep(helicopter_integral_M)) {
      /* Gain: '<S7>/Slider Gain' incorporates:
       *  Constant: '<S2>/Travel Constant'
       */
      helicopter_integral_B.SliderGain_l =
        helicopter_integral_P.SliderGain_Gain_p *
        helicopter_integral_P.TravelConstant_Value;

      /* Constant: '<S8>/Constant' */
      helicopter_integral_B.Constant_k = helicopter_integral_P.Constant_Value_p;
    }

    /* Clock: '<S9>/Clock' */
    rtb_Clock = helicopter_integral_M->Timing.t[0];
    if (rtmIsMajorTimeStep(helicopter_integral_M)) {
      /* Constant: '<S9>/Constant' */
      helicopter_integral_B.Constant = helicopter_integral_P.Constant_Value;
    }

    /* Integrator: '<S3>/Des Position:  Elevation (deg)'
     *
     * Regarding '<S3>/Des Position:  Elevation (deg)':
     *  Limited Integrator
     */
    if (helicopter_integral_X.DesPositionElevationdeg_CSTATE >=
        helicopter_integral_P.DesPositionElevationdeg_UpperSa ) {
      helicopter_integral_X.DesPositionElevationdeg_CSTATE =
        helicopter_integral_P.DesPositionElevationdeg_UpperSa;
    } else if (helicopter_integral_X.DesPositionElevationdeg_CSTATE <=
               helicopter_integral_P.DesPositionElevationdeg_LowerSa ) {
      helicopter_integral_X.DesPositionElevationdeg_CSTATE =
        helicopter_integral_P.DesPositionElevationdeg_LowerSa;
    }

    rtb_DesPositionElevationdeg =
      helicopter_integral_X.DesPositionElevationdeg_CSTATE;
    if (rtmIsMajorTimeStep(helicopter_integral_M)) {
      /* Constant: '<S3>/Constant: Pitch (deg)' */
      helicopter_integral_B.ConstantPitchdeg_j =
        helicopter_integral_P.ConstantPitchdeg_Value_h;
    }

    /* MultiPortSwitch: '<Root>/Multiport Switch' incorporates:
     *  Gain: '<S10>/Gain1'
     *  Gain: '<S12>/Gain1'
     *  Gain: '<S2>/Amplitude: Elevation (deg)'
     *  Integrator: '<S3>/Des Position:  Travel (deg)'
     *  Sum: '<S2>/Sum1'
     */
    if ((int32_T)helicopter_integral_B.Program1Joystick2 == 1) {
      /* Switch: '<S8>/SwitchControl' incorporates:
       *  Gain: '<S2>/Amplitude: Travel (deg)'
       *  Lookup: '<S9>/Look-Up Table1'
       *  Math: '<S9>/Math Function'
       *  S-Function (sfun_tstart): '<S9>/startTime'
       *  Sum: '<S2>/Sum2'
       *  Sum: '<S9>/Sum'
       */
      if (helicopter_integral_B.Constant_k >
          helicopter_integral_P.SwitchControl_Threshold) {
        rtb_SignalGeneratorTravel =
          helicopter_integral_P.AmplitudeTraveldeg_Gain *
          rtb_SignalGeneratorTravel + helicopter_integral_B.SliderGain_l;
      } else {
        rtb_SignalGeneratorTravel = rt_Lookup((const real_T *)
          &helicopter_integral_P.LookUpTable1_XData, 7, rt_remd_snf(rtb_Clock -
          (0.0), helicopter_integral_B.Constant), (const real_T *)
          &helicopter_integral_P.LookUpTable1_YData);
      }

      /* End of Switch: '<S8>/SwitchControl' */
      rtb_MultiportSwitch[0] = (helicopter_integral_P.AmplitudeElevationdeg_Gain
        * rtb_SignalGeneratorElevation + helicopter_integral_B.SliderGain) *
        helicopter_integral_P.Gain1_Gain_d;
      rtb_MultiportSwitch[1] = helicopter_integral_P.Gain1_Gain_d *
        helicopter_integral_B.ConstantPitchdeg;
      rtb_MultiportSwitch[2] = helicopter_integral_P.Gain1_Gain_d *
        rtb_SignalGeneratorTravel;
    } else {
      rtb_MultiportSwitch[0] = helicopter_integral_P.Gain1_Gain *
        rtb_DesPositionElevationdeg;
      rtb_MultiportSwitch[1] = helicopter_integral_P.Gain1_Gain *
        helicopter_integral_B.ConstantPitchdeg_j;
      rtb_MultiportSwitch[2] = helicopter_integral_P.Gain1_Gain *
        helicopter_integral_X.DesPositionTraveldeg_CSTATE;
    }

    /* End of MultiPortSwitch: '<Root>/Multiport Switch' */

    /* RateLimiter: '<Root>/Des Position Rate Limiter' */
    if (helicopter_integral_DWork.LastMajorTime == (rtInf)) {
      helicopter_integral_B.DesPositionRateLimiter[0] = rtb_MultiportSwitch[0];
      helicopter_integral_B.DesPositionRateLimiter[1] = rtb_MultiportSwitch[1];
      helicopter_integral_B.DesPositionRateLimiter[2] = rtb_MultiportSwitch[2];
    } else {
      rtb_SignalGeneratorTravel = helicopter_integral_M->Timing.t[0] -
        helicopter_integral_DWork.LastMajorTime;
      rtb_SignalGeneratorElevation = rtb_SignalGeneratorTravel *
        helicopter_integral_P.DesPositionRateLimiter_RisingLi;
      rateLimiterRate_idx = rtb_MultiportSwitch[0] -
        helicopter_integral_DWork.PrevY[0];
      rateLimiterRate_idx_0 = rtb_MultiportSwitch[1] -
        helicopter_integral_DWork.PrevY[1];
      rateLimiterRate_idx_1 = rtb_MultiportSwitch[2] -
        helicopter_integral_DWork.PrevY[2];
      rtb_SignalGeneratorTravel *=
        helicopter_integral_P.DesPositionRateLimiter_FallingL;
      if (rateLimiterRate_idx > rtb_SignalGeneratorElevation) {
        helicopter_integral_B.DesPositionRateLimiter[0] =
          helicopter_integral_DWork.PrevY[0] + rtb_SignalGeneratorElevation;
      } else if (rateLimiterRate_idx < rtb_SignalGeneratorTravel) {
        helicopter_integral_B.DesPositionRateLimiter[0] =
          helicopter_integral_DWork.PrevY[0] + rtb_SignalGeneratorTravel;
      } else {
        helicopter_integral_B.DesPositionRateLimiter[0] = rtb_MultiportSwitch[0];
      }

      if (rateLimiterRate_idx_0 > rtb_SignalGeneratorElevation) {
        helicopter_integral_B.DesPositionRateLimiter[1] =
          helicopter_integral_DWork.PrevY[1] + rtb_SignalGeneratorElevation;
      } else if (rateLimiterRate_idx_0 < rtb_SignalGeneratorTravel) {
        helicopter_integral_B.DesPositionRateLimiter[1] =
          helicopter_integral_DWork.PrevY[1] + rtb_SignalGeneratorTravel;
      } else {
        helicopter_integral_B.DesPositionRateLimiter[1] = rtb_MultiportSwitch[1];
      }

      if (rateLimiterRate_idx_1 > rtb_SignalGeneratorElevation) {
        helicopter_integral_B.DesPositionRateLimiter[2] =
          helicopter_integral_DWork.PrevY[2] + rtb_SignalGeneratorElevation;
      } else if (rateLimiterRate_idx_1 < rtb_SignalGeneratorTravel) {
        helicopter_integral_B.DesPositionRateLimiter[2] =
          helicopter_integral_DWork.PrevY[2] + rtb_SignalGeneratorTravel;
      } else {
        helicopter_integral_B.DesPositionRateLimiter[2] = rtb_MultiportSwitch[2];
      }
    }

    /* End of RateLimiter: '<Root>/Des Position Rate Limiter' */
    if (rtmIsMajorTimeStep(helicopter_integral_M)) {
      /* Constant: '<S5>/des vel' */
      helicopter_integral_B.desvel = helicopter_integral_P.desvel_Value;
    }

    /* Outputs for Atomic SubSystem: '<Root>/Observer' */
    /* Integrator: '<S4>/Integrator' */
    for (i = 0; i < 6; i++) {
      helicopter_integral_B.Integrator[i] =
        helicopter_integral_X.Integrator_CSTATE_i[i];
    }

    /* End of Integrator: '<S4>/Integrator' */

    /* Gain: '<S4>/Gain1' */
    for (i = 0; i < 6; i++) {
      helicopter_integral_B.Gain1[i] = 0.0;
      for (i_0 = 0; i_0 < 6; i_0++) {
        helicopter_integral_B.Gain1[i] += helicopter_integral_P.Gain1_Gain_f[6 *
          i_0 + i] * helicopter_integral_B.Integrator[i_0];
      }
    }

    /* End of Gain: '<S4>/Gain1' */

    /* Gain: '<S4>/Gain3' */
    for (i = 0; i < 3; i++) {
      rtb_MultiportSwitch[i] = 0.0;
      for (i_0 = 0; i_0 < 6; i_0++) {
        rtb_MultiportSwitch[i] += helicopter_integral_P.Gain3_Gain[3 * i_0 + i] *
          helicopter_integral_B.Integrator[i_0];
      }
    }

    /* End of Gain: '<S4>/Gain3' */
    /* End of Outputs for SubSystem: '<Root>/Observer' */

    /* Gain: '<Root>/Gain1' */
    tmp[0] = helicopter_integral_B.DesPositionRateLimiter[0];
    tmp[1] = helicopter_integral_B.DesPositionRateLimiter[1];
    tmp[2] = helicopter_integral_B.DesPositionRateLimiter[2];
    tmp[3] = helicopter_integral_B.desvel;
    tmp[4] = helicopter_integral_B.desvel;
    tmp[5] = helicopter_integral_B.desvel;

    /* Sum: '<Root>/Sum' incorporates:
     *  Gain: '<Root>/Gain1'
     *  Gain: '<Root>/Gain2'
     *  Gain: '<Root>/Gain3'
     *  Integrator: '<Root>/Integrator'
     */
    for (i = 0; i < 6; i++) {
      tmp_0[i] = (helicopter_integral_P.Gain1_Gain_b * tmp[i] +
                  helicopter_integral_P.Gain3_Gain_p *
                  helicopter_integral_X.Integrator_CSTATE[i]) -
        helicopter_integral_B.Integrator[i];
    }

    /* End of Sum: '<Root>/Sum' */

    /* Bias: '<Root>/Bias' incorporates:
     *  Gain: '<Root>/Gain2'
     */
    for (i = 0; i < 2; i++) {
      rtb_SignalGeneratorTravel = 0.0;
      for (i_0 = 0; i_0 < 6; i_0++) {
        rtb_SignalGeneratorTravel += helicopter_integral_P.Gain2_Gain_i[(i_0 <<
          1) + i] * tmp_0[i_0];
      }

      helicopter_integral_B.Bias[i] = rtb_SignalGeneratorTravel +
        helicopter_integral_P.Bias_Bias;
    }

    /* End of Bias: '<Root>/Bias' */

    /* Saturate: '<S1>/Amplifier Voltage  Limit (V)' */
    if (helicopter_integral_B.Bias[0] >=
        helicopter_integral_P.AmplifierVoltageLimitV_UpperSat) {
      rtb_SignalGeneratorTravel =
        helicopter_integral_P.AmplifierVoltageLimitV_UpperSat;
    } else if (helicopter_integral_B.Bias[0] <=
               helicopter_integral_P.AmplifierVoltageLimitV_LowerSat) {
      rtb_SignalGeneratorTravel =
        helicopter_integral_P.AmplifierVoltageLimitV_LowerSat;
    } else {
      rtb_SignalGeneratorTravel = helicopter_integral_B.Bias[0];
    }

    /* Gain: '<S1>/Amplifier Gain Pre-Compensation' incorporates:
     *  Saturate: '<S1>/Amplifier Voltage  Limit (V)'
     */
    rtb_SignalGeneratorTravel *=
      helicopter_integral_P.AmplifierGainPreCompensation_Ga;

    /* Saturate: '<S1>/DACB Limit (V)' */
    if (rtb_SignalGeneratorTravel >= helicopter_integral_P.DACBLimitV_UpperSat)
    {
      helicopter_integral_B.DACBLimitV[0] =
        helicopter_integral_P.DACBLimitV_UpperSat;
    } else if (rtb_SignalGeneratorTravel <=
               helicopter_integral_P.DACBLimitV_LowerSat) {
      helicopter_integral_B.DACBLimitV[0] =
        helicopter_integral_P.DACBLimitV_LowerSat;
    } else {
      helicopter_integral_B.DACBLimitV[0] = rtb_SignalGeneratorTravel;
    }

    /* Saturate: '<S1>/Amplifier Voltage  Limit (V)' */
    if (helicopter_integral_B.Bias[1] >=
        helicopter_integral_P.AmplifierVoltageLimitV_UpperSat) {
      rtb_SignalGeneratorTravel =
        helicopter_integral_P.AmplifierVoltageLimitV_UpperSat;
    } else if (helicopter_integral_B.Bias[1] <=
               helicopter_integral_P.AmplifierVoltageLimitV_LowerSat) {
      rtb_SignalGeneratorTravel =
        helicopter_integral_P.AmplifierVoltageLimitV_LowerSat;
    } else {
      rtb_SignalGeneratorTravel = helicopter_integral_B.Bias[1];
    }

    /* Gain: '<S1>/Amplifier Gain Pre-Compensation' incorporates:
     *  Saturate: '<S1>/Amplifier Voltage  Limit (V)'
     */
    rtb_SignalGeneratorTravel *=
      helicopter_integral_P.AmplifierGainPreCompensation_Ga;

    /* Saturate: '<S1>/DACB Limit (V)' */
    if (rtb_SignalGeneratorTravel >= helicopter_integral_P.DACBLimitV_UpperSat)
    {
      helicopter_integral_B.DACBLimitV[1] =
        helicopter_integral_P.DACBLimitV_UpperSat;
    } else if (rtb_SignalGeneratorTravel <=
               helicopter_integral_P.DACBLimitV_LowerSat) {
      helicopter_integral_B.DACBLimitV[1] =
        helicopter_integral_P.DACBLimitV_LowerSat;
    } else {
      helicopter_integral_B.DACBLimitV[1] = rtb_SignalGeneratorTravel;
    }

    if (rtmIsMajorTimeStep(helicopter_integral_M)) {
      /* S-Function (hil_write_analog_block): '<S1>/HIL Write Analog' */

      /* S-Function Block: helicopter_integral/3-DOF Plant/HIL Write Analog (hil_write_analog_block) */
      {
        t_error result;
        result = hil_write_analog(helicopter_integral_DWork.HILInitialize_Card,
          helicopter_integral_P.HILWriteAnalog_Channels, 2,
          helicopter_integral_B.DACBLimitV);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(helicopter_integral_M, _rt_error_message);
        }
      }
    }

    /* Gain: '<S1>/Amplifier Gain' */
    helicopter_integral_B.AmplifierGain[0] =
      helicopter_integral_P.AmplifierGain_Gain *
      helicopter_integral_B.DACBLimitV[0];
    helicopter_integral_B.AmplifierGain[1] =
      helicopter_integral_P.AmplifierGain_Gain *
      helicopter_integral_B.DACBLimitV[1];
    if (rtmIsMajorTimeStep(helicopter_integral_M)) {
      /* Bias: '<S1>/Initial Elevation (rad)' incorporates:
       *  Gain: '<S1>/Encoder Resolution: Elevation (rad//count)'
       */
      helicopter_integral_B.InitialElevationrad =
        helicopter_integral_P.EncoderResolutionElevationradco *
        rtb_HILReadEncoderTimebase[2] +
        helicopter_integral_P.InitialElevationrad_Bias;

      /* Gain: '<S1>/Encoder Resolution: Pitch (rad//count)' */
      helicopter_integral_B.EncoderResolutionPitchradcount =
        helicopter_integral_P.EncoderResolutionPitchradcount_ *
        rtb_HILReadEncoderTimebase[1];

      /* Gain: '<S1>/Encoder Resolution: Travel (rad//count)' */
      helicopter_integral_B.EncoderResolutionTravelradcount =
        helicopter_integral_P.EncoderResolutionTravelradcount *
        rtb_HILReadEncoderTimebase[0];

      /* S-Function (hil_write_digital_block): '<S1>/HIL Write Digital' */

      /* S-Function Block: helicopter_integral/3-DOF Plant/HIL Write Digital (hil_write_digital_block) */
      {
        t_error result;
        helicopter_integral_DWork.HILWriteDigital_Buffer[0] =
          (helicopter_integral_P.EnableAmp_Value[0] != 0);
        helicopter_integral_DWork.HILWriteDigital_Buffer[1] =
          (helicopter_integral_P.EnableAmp_Value[1] != 0);
        helicopter_integral_DWork.HILWriteDigital_Buffer[2] =
          (helicopter_integral_P.EnableAmp_Value[2] != 0);
        helicopter_integral_DWork.HILWriteDigital_Buffer[3] =
          (helicopter_integral_P.EnableAmp_Value[3] != 0);
        result = hil_write_digital(helicopter_integral_DWork.HILInitialize_Card,
          helicopter_integral_P.HILWriteDigital_Channels, 4,
          &helicopter_integral_DWork.HILWriteDigital_Buffer[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(helicopter_integral_M, _rt_error_message);
        }
      }

      /* RateTransition: '<S3>/Rate Transition: z' */
      if (helicopter_integral_M->Timing.RateInteraction.TID1_2) {
        helicopter_integral_B.RateTransitionz =
          helicopter_integral_DWork.RateTransitionz_Buffer0;
      }

      /* End of RateTransition: '<S3>/Rate Transition: z' */

      /* Product: '<S11>/Divide' incorporates:
       *  Bias: '<S11>/Bias'
       *  Constant: '<S11>/Constant'
       *  Gain: '<S11>/Inverse'
       */
      rtb_SignalGeneratorTravel = (helicopter_integral_P.Inverse_Gain *
        helicopter_integral_B.RateTransitionz +
        helicopter_integral_P.Bias_Bias_k) /
        helicopter_integral_P.Constant_Value_c;

      /* RateTransition: '<S3>/Rate Transition: x' */
      if (helicopter_integral_M->Timing.RateInteraction.TID1_2) {
        helicopter_integral_B.RateTransitionx =
          helicopter_integral_DWork.RateTransitionx_Buffer0;
      }

      /* End of RateTransition: '<S3>/Rate Transition: x' */

      /* Gain: '<S3>/Calibration: X  (deg//s//V)' incorporates:
       *  Product: '<S3>/Travel Speed  Adj.'
       */
      helicopter_integral_B.CalibrationXdegsV = rtb_SignalGeneratorTravel *
        helicopter_integral_B.RateTransitionx *
        helicopter_integral_P.CalibrationXdegsV_Gain;

      /* RateTransition: '<S3>/Rate Transition: y' */
      if (helicopter_integral_M->Timing.RateInteraction.TID1_2) {
        helicopter_integral_B.RateTransitiony =
          helicopter_integral_DWork.RateTransitiony_Buffer0;
      }

      /* End of RateTransition: '<S3>/Rate Transition: y' */

      /* Gain: '<S3>/Calibration: Y  (deg//s//V)' incorporates:
       *  Product: '<S3>/Elevation Speed  Adj'
       */
      helicopter_integral_B.CalibrationYdegsV =
        helicopter_integral_B.RateTransitiony * rtb_SignalGeneratorTravel *
        helicopter_integral_P.CalibrationYdegsV_Gain;
    }

    /* Sum: '<Root>/Sum1' */
    helicopter_integral_B.Sum1[0] = helicopter_integral_B.InitialElevationrad -
      rtb_MultiportSwitch[0];
    helicopter_integral_B.Sum1[1] =
      helicopter_integral_B.EncoderResolutionPitchradcount -
      rtb_MultiportSwitch[1];
    helicopter_integral_B.Sum1[2] =
      helicopter_integral_B.EncoderResolutionTravelradcount -
      rtb_MultiportSwitch[2];

    /* Sum: '<Root>/Sum2' */
    helicopter_integral_B.Sum2[0] =
      helicopter_integral_B.DesPositionRateLimiter[0] -
      helicopter_integral_B.Integrator[0];
    helicopter_integral_B.Sum2[1] =
      helicopter_integral_B.DesPositionRateLimiter[1] -
      helicopter_integral_B.Integrator[1];
    helicopter_integral_B.Sum2[2] =
      helicopter_integral_B.DesPositionRateLimiter[2] -
      helicopter_integral_B.Integrator[2];
    helicopter_integral_B.Sum2[3] = helicopter_integral_B.desvel -
      helicopter_integral_B.Integrator[3];
    helicopter_integral_B.Sum2[4] = helicopter_integral_B.desvel -
      helicopter_integral_B.Integrator[4];
    helicopter_integral_B.Sum2[5] = helicopter_integral_B.desvel -
      helicopter_integral_B.Integrator[5];
  }

  if (rtmIsMajorTimeStep(helicopter_integral_M)) {
    int32_T i;

    /* Update for RateLimiter: '<Root>/Des Position Rate Limiter' */
    helicopter_integral_DWork.PrevY[0] =
      helicopter_integral_B.DesPositionRateLimiter[0];
    helicopter_integral_DWork.PrevY[1] =
      helicopter_integral_B.DesPositionRateLimiter[1];
    helicopter_integral_DWork.PrevY[2] =
      helicopter_integral_B.DesPositionRateLimiter[2];
    helicopter_integral_DWork.LastMajorTime = helicopter_integral_M->Timing.t[0];

    /* Update for Atomic SubSystem: '<Root>/Observer' */
    for (i = 0; i < 6; i++) {
      /* Gain: '<S4>/Gain2' */
      helicopter_integral_B.Gain2[i] = 0.0;
      helicopter_integral_B.Gain2[i] += helicopter_integral_P.Gain2_Gain[i] *
        helicopter_integral_B.Bias[0];
      helicopter_integral_B.Gain2[i] += helicopter_integral_P.Gain2_Gain[i + 6] *
        helicopter_integral_B.Bias[1];

      /* Gain: '<S4>/Gain4' */
      helicopter_integral_B.Gain4[i] = 0.0;
      helicopter_integral_B.Gain4[i] += helicopter_integral_P.Gain4_Gain[i] *
        helicopter_integral_B.Sum1[0];
      helicopter_integral_B.Gain4[i] += helicopter_integral_P.Gain4_Gain[i + 6] *
        helicopter_integral_B.Sum1[1];
      helicopter_integral_B.Gain4[i] += helicopter_integral_P.Gain4_Gain[i + 12]
        * helicopter_integral_B.Sum1[2];

      /* Sum: '<S4>/Sum' */
      helicopter_integral_B.Sum[i] = (helicopter_integral_B.Gain2[i] +
        helicopter_integral_B.Gain4[i]) + helicopter_integral_B.Gain1[i];
    }

    /* End of Update for SubSystem: '<Root>/Observer' */

    /* External mode */
    rtExtModeUploadCheckTrigger(3);
    rtExtModeUpload(1, helicopter_integral_M->Timing.t[0]);
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(helicopter_integral_M)) {
    rt_ertODEUpdateContinuousStates(&helicopter_integral_M->solverInfo);

    /* Update absolute time */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++helicopter_integral_M->Timing.clockTick0)) {
      ++helicopter_integral_M->Timing.clockTickH0;
    }

    helicopter_integral_M->Timing.t[0] = rtsiGetSolverStopTime
      (&helicopter_integral_M->solverInfo);

    /* Update absolute time */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.002, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    helicopter_integral_M->Timing.clockTick1++;
    if (!helicopter_integral_M->Timing.clockTick1) {
      helicopter_integral_M->Timing.clockTickH1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void helicopter_integral_derivatives(void)
{
  int32_T i;
  StateDerivatives_helicopter_int *_rtXdot;
  _rtXdot = ((StateDerivatives_helicopter_int *)
             helicopter_integral_M->ModelData.derivs);

  /* Derivatives for Integrator: '<S3>/Des Position:  Elevation (deg)' */
  {
    boolean_T lsat;
    boolean_T usat;
    lsat = ( helicopter_integral_X.DesPositionElevationdeg_CSTATE <=
            helicopter_integral_P.DesPositionElevationdeg_LowerSa );
    usat = ( helicopter_integral_X.DesPositionElevationdeg_CSTATE >=
            helicopter_integral_P.DesPositionElevationdeg_UpperSa );
    if ((!lsat && !usat) ||
        (lsat && (helicopter_integral_B.CalibrationYdegsV > 0)) ||
        (usat && (helicopter_integral_B.CalibrationYdegsV < 0)) ) {
      ((StateDerivatives_helicopter_int *)
        helicopter_integral_M->ModelData.derivs)->DesPositionElevationdeg_CSTATE
        = helicopter_integral_B.CalibrationYdegsV;
    } else {
      /* in saturation */
      ((StateDerivatives_helicopter_int *)
        helicopter_integral_M->ModelData.derivs)->DesPositionElevationdeg_CSTATE
        = 0.0;
    }
  }

  /* Derivatives for Integrator: '<S3>/Des Position:  Travel (deg)' */
  _rtXdot->DesPositionTraveldeg_CSTATE = helicopter_integral_B.CalibrationXdegsV;

  /* Derivatives for Atomic SubSystem: '<Root>/Observer' */
  for (i = 0; i < 6; i++) {
    /* Derivatives for Integrator: '<Root>/Integrator' */
    _rtXdot->Integrator_CSTATE[i] = helicopter_integral_B.Sum2[i];

    /* Gain: '<S4>/Gain2' */
    helicopter_integral_B.Gain2[i] = 0.0;
    helicopter_integral_B.Gain2[i] += helicopter_integral_P.Gain2_Gain[i] *
      helicopter_integral_B.Bias[0];
    helicopter_integral_B.Gain2[i] += helicopter_integral_P.Gain2_Gain[i + 6] *
      helicopter_integral_B.Bias[1];

    /* Gain: '<S4>/Gain4' */
    helicopter_integral_B.Gain4[i] = 0.0;
    helicopter_integral_B.Gain4[i] += helicopter_integral_P.Gain4_Gain[i] *
      helicopter_integral_B.Sum1[0];
    helicopter_integral_B.Gain4[i] += helicopter_integral_P.Gain4_Gain[i + 6] *
      helicopter_integral_B.Sum1[1];
    helicopter_integral_B.Gain4[i] += helicopter_integral_P.Gain4_Gain[i + 12] *
      helicopter_integral_B.Sum1[2];

    /* Sum: '<S4>/Sum' */
    helicopter_integral_B.Sum[i] = (helicopter_integral_B.Gain2[i] +
      helicopter_integral_B.Gain4[i]) + helicopter_integral_B.Gain1[i];

    /* Derivatives for Integrator: '<S4>/Integrator' */
    _rtXdot->Integrator_CSTATE_i[i] = helicopter_integral_B.Sum[i];
  }

  /* End of Derivatives for SubSystem: '<Root>/Observer' */
}

/* Model step function for TID2 */
void helicopter_integral_step2(void)   /* Sample time: [0.01s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_GameController_o4;
  real_T rtb_GameController_o5;
  real_T rtb_GameController_o6;

  /* S-Function (game_controller_block): '<S3>/Game Controller' */

  /* S-Function Block: helicopter_integral/Desired Position from Joystick/Game Controller (game_controller_block) */
  {
    if (helicopter_integral_P.GameController_Enabled) {
      t_game_controller_states state;
      t_boolean new_data;
      t_error result;
      result = game_controller_poll
        (helicopter_integral_DWork.GameController_Controller, &state, &new_data);
      if (result == 0) {
        {
          int_T i1;
          boolean_T *y1 = helicopter_integral_B.GameController_o2;
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
        boolean_T *y1 = helicopter_integral_B.GameController_o2;
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
  if (helicopter_integral_B.GameController_o2[0] &&
      (helicopter_integral_P.Constant_Value_l != 0.0)) {
    rtmSetStopRequested(helicopter_integral_M, 1);
  }

  /* End of Stop: '<S3>/Stop Simulation' */

  /* Update for RateTransition: '<S3>/Rate Transition: z' */
  helicopter_integral_DWork.RateTransitionz_Buffer0 = rtb_GameController_o6;

  /* Update for RateTransition: '<S3>/Rate Transition: x' */
  helicopter_integral_DWork.RateTransitionx_Buffer0 = rtb_GameController_o4;

  /* Update for RateTransition: '<S3>/Rate Transition: y' */
  helicopter_integral_DWork.RateTransitiony_Buffer0 = rtb_GameController_o5;
  rtExtModeUpload(2, (((helicopter_integral_M->Timing.clockTick2+
                        helicopter_integral_M->Timing.clockTickH2* 4294967296.0))
                      * 0.01));

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.01, which is the step size
   * of the task. Size of "clockTick2" ensures timer will not overflow during the
   * application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick2 and the high bits
   * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
   */
  helicopter_integral_M->Timing.clockTick2++;
  if (!helicopter_integral_M->Timing.clockTick2) {
    helicopter_integral_M->Timing.clockTickH2++;
  }
}

void helicopter_integral_step(int_T tid)
{
  switch (tid) {
   case 0 :
    helicopter_integral_step0();
    break;

   case 2 :
    helicopter_integral_step2();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void helicopter_integral_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)helicopter_integral_M, 0,
                sizeof(RT_MODEL_helicopter_integral));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&helicopter_integral_M->solverInfo,
                          &helicopter_integral_M->Timing.simTimeStep);
    rtsiSetTPtr(&helicopter_integral_M->solverInfo, &rtmGetTPtr
                (helicopter_integral_M));
    rtsiSetStepSizePtr(&helicopter_integral_M->solverInfo,
                       &helicopter_integral_M->Timing.stepSize0);
    rtsiSetdXPtr(&helicopter_integral_M->solverInfo,
                 &helicopter_integral_M->ModelData.derivs);
    rtsiSetContStatesPtr(&helicopter_integral_M->solverInfo,
                         &helicopter_integral_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&helicopter_integral_M->solverInfo,
      &helicopter_integral_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&helicopter_integral_M->solverInfo,
                          (&rtmGetErrorStatus(helicopter_integral_M)));
    rtsiSetRTModelPtr(&helicopter_integral_M->solverInfo, helicopter_integral_M);
  }

  rtsiSetSimTimeStep(&helicopter_integral_M->solverInfo, MAJOR_TIME_STEP);
  helicopter_integral_M->ModelData.intgData.f[0] =
    helicopter_integral_M->ModelData.odeF[0];
  helicopter_integral_M->ModelData.contStates = ((real_T *)
    &helicopter_integral_X);
  rtsiSetSolverData(&helicopter_integral_M->solverInfo, (void *)
                    &helicopter_integral_M->ModelData.intgData);
  rtsiSetSolverName(&helicopter_integral_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = helicopter_integral_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    helicopter_integral_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    helicopter_integral_M->Timing.sampleTimes =
      (&helicopter_integral_M->Timing.sampleTimesArray[0]);
    helicopter_integral_M->Timing.offsetTimes =
      (&helicopter_integral_M->Timing.offsetTimesArray[0]);

    /* task periods */
    helicopter_integral_M->Timing.sampleTimes[0] = (0.0);
    helicopter_integral_M->Timing.sampleTimes[1] = (0.002);
    helicopter_integral_M->Timing.sampleTimes[2] = (0.01);

    /* task offsets */
    helicopter_integral_M->Timing.offsetTimes[0] = (0.0);
    helicopter_integral_M->Timing.offsetTimes[1] = (0.0);
    helicopter_integral_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(helicopter_integral_M, &helicopter_integral_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = helicopter_integral_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits =
      helicopter_integral_M->Timing.perTaskSampleHitsArray;
    helicopter_integral_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    helicopter_integral_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(helicopter_integral_M, -1);
  helicopter_integral_M->Timing.stepSize0 = 0.002;

  /* External mode info */
  helicopter_integral_M->Sizes.checksums[0] = (399056132U);
  helicopter_integral_M->Sizes.checksums[1] = (2885919158U);
  helicopter_integral_M->Sizes.checksums[2] = (2332119279U);
  helicopter_integral_M->Sizes.checksums[3] = (3375140509U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[7];
    helicopter_integral_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(helicopter_integral_M->extModeInfo,
      &helicopter_integral_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(helicopter_integral_M->extModeInfo,
                        helicopter_integral_M->Sizes.checksums);
    rteiSetTPtr(helicopter_integral_M->extModeInfo, rtmGetTPtr
                (helicopter_integral_M));
  }

  helicopter_integral_M->solverInfoPtr = (&helicopter_integral_M->solverInfo);
  helicopter_integral_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&helicopter_integral_M->solverInfo, 0.002);
  rtsiSetSolverMode(&helicopter_integral_M->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  (void) memset(((void *) &helicopter_integral_B), 0,
                sizeof(BlockIO_helicopter_integral));

  {
    int_T i;
    for (i = 0; i < 6; i++) {
      helicopter_integral_B.Sum2[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      helicopter_integral_B.Integrator[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      helicopter_integral_B.Gain1[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      helicopter_integral_B.Gain2[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      helicopter_integral_B.Gain4[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      helicopter_integral_B.Sum[i] = 0.0;
    }

    helicopter_integral_B.Program1Joystick2 = 0.0;
    helicopter_integral_B.SliderGain = 0.0;
    helicopter_integral_B.ConstantPitchdeg = 0.0;
    helicopter_integral_B.SliderGain_l = 0.0;
    helicopter_integral_B.Constant = 0.0;
    helicopter_integral_B.ConstantPitchdeg_j = 0.0;
    helicopter_integral_B.DesPositionRateLimiter[0] = 0.0;
    helicopter_integral_B.DesPositionRateLimiter[1] = 0.0;
    helicopter_integral_B.DesPositionRateLimiter[2] = 0.0;
    helicopter_integral_B.desvel = 0.0;
    helicopter_integral_B.Bias[0] = 0.0;
    helicopter_integral_B.Bias[1] = 0.0;
    helicopter_integral_B.DACBLimitV[0] = 0.0;
    helicopter_integral_B.DACBLimitV[1] = 0.0;
    helicopter_integral_B.AmplifierGain[0] = 0.0;
    helicopter_integral_B.AmplifierGain[1] = 0.0;
    helicopter_integral_B.InitialElevationrad = 0.0;
    helicopter_integral_B.EncoderResolutionPitchradcount = 0.0;
    helicopter_integral_B.EncoderResolutionTravelradcount = 0.0;
    helicopter_integral_B.RateTransitionz = 0.0;
    helicopter_integral_B.RateTransitionx = 0.0;
    helicopter_integral_B.CalibrationXdegsV = 0.0;
    helicopter_integral_B.RateTransitiony = 0.0;
    helicopter_integral_B.CalibrationYdegsV = 0.0;
    helicopter_integral_B.Sum1[0] = 0.0;
    helicopter_integral_B.Sum1[1] = 0.0;
    helicopter_integral_B.Sum1[2] = 0.0;
  }

  /* states (continuous) */
  {
    (void) memset((void *)&helicopter_integral_X, 0,
                  sizeof(ContinuousStates_helicopter_int));
  }

  /* states (dwork) */
  (void) memset((void *)&helicopter_integral_DWork, 0,
                sizeof(D_Work_helicopter_integral));
  helicopter_integral_DWork.HILInitialize_AIMinimums[0] = 0.0;
  helicopter_integral_DWork.HILInitialize_AIMinimums[1] = 0.0;
  helicopter_integral_DWork.HILInitialize_AIMinimums[2] = 0.0;
  helicopter_integral_DWork.HILInitialize_AIMinimums[3] = 0.0;
  helicopter_integral_DWork.HILInitialize_AIMaximums[0] = 0.0;
  helicopter_integral_DWork.HILInitialize_AIMaximums[1] = 0.0;
  helicopter_integral_DWork.HILInitialize_AIMaximums[2] = 0.0;
  helicopter_integral_DWork.HILInitialize_AIMaximums[3] = 0.0;
  helicopter_integral_DWork.HILInitialize_AOMinimums[0] = 0.0;
  helicopter_integral_DWork.HILInitialize_AOMinimums[1] = 0.0;
  helicopter_integral_DWork.HILInitialize_AOMinimums[2] = 0.0;
  helicopter_integral_DWork.HILInitialize_AOMinimums[3] = 0.0;
  helicopter_integral_DWork.HILInitialize_AOMaximums[0] = 0.0;
  helicopter_integral_DWork.HILInitialize_AOMaximums[1] = 0.0;
  helicopter_integral_DWork.HILInitialize_AOMaximums[2] = 0.0;
  helicopter_integral_DWork.HILInitialize_AOMaximums[3] = 0.0;
  helicopter_integral_DWork.HILInitialize_AOVoltages[0] = 0.0;
  helicopter_integral_DWork.HILInitialize_AOVoltages[1] = 0.0;
  helicopter_integral_DWork.HILInitialize_AOVoltages[2] = 0.0;
  helicopter_integral_DWork.HILInitialize_AOVoltages[3] = 0.0;
  helicopter_integral_DWork.HILInitialize_FilterFrequency[0] = 0.0;
  helicopter_integral_DWork.HILInitialize_FilterFrequency[1] = 0.0;
  helicopter_integral_DWork.HILInitialize_FilterFrequency[2] = 0.0;
  helicopter_integral_DWork.HILInitialize_FilterFrequency[3] = 0.0;
  helicopter_integral_DWork.PrevY[0] = 0.0;
  helicopter_integral_DWork.PrevY[1] = 0.0;
  helicopter_integral_DWork.PrevY[2] = 0.0;
  helicopter_integral_DWork.LastMajorTime = 0.0;
  helicopter_integral_DWork.RateTransitionz_Buffer0 = 0.0;
  helicopter_integral_DWork.RateTransitionx_Buffer0 = 0.0;
  helicopter_integral_DWork.RateTransitiony_Buffer0 = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    helicopter_integral_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 18;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Initialize Sizes */
  helicopter_integral_M->Sizes.numContStates = (14);/* Number of continuous states */
  helicopter_integral_M->Sizes.numY = (0);/* Number of model outputs */
  helicopter_integral_M->Sizes.numU = (0);/* Number of model inputs */
  helicopter_integral_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  helicopter_integral_M->Sizes.numSampTimes = (3);/* Number of sample times */
  helicopter_integral_M->Sizes.numBlocks = (82);/* Number of blocks */
  helicopter_integral_M->Sizes.numBlockIO = (28);/* Number of block outputs */
  helicopter_integral_M->Sizes.numBlockPrms = (267);/* Sum of parameter "widths" */

  /* Start for S-Function (hil_initialize_block): '<S1>/HIL Initialize' */

  /* S-Function Block: helicopter_integral/3-DOF Plant/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q4", "0", &helicopter_integral_DWork.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(helicopter_integral_M, _rt_error_message);
      return;
    }

    is_switching = false;
    if ((helicopter_integral_P.HILInitialize_CKPStart && !is_switching) ||
        (helicopter_integral_P.HILInitialize_CKPEnter && is_switching)) {
      result = hil_set_clock_mode(helicopter_integral_DWork.HILInitialize_Card,
                                  (t_clock *)
        helicopter_integral_P.HILInitialize_CKChannels, 2U, (t_clock_mode *)
        helicopter_integral_P.HILInitialize_CKModes);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helicopter_integral_M, _rt_error_message);
        return;
      }
    }

    result = hil_watchdog_clear(helicopter_integral_DWork.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(helicopter_integral_M, _rt_error_message);
      return;
    }

    if ((helicopter_integral_P.HILInitialize_AIPStart && !is_switching) ||
        (helicopter_integral_P.HILInitialize_AIPEnter && is_switching)) {
      helicopter_integral_DWork.HILInitialize_AIMinimums[0] =
        helicopter_integral_P.HILInitialize_AILow;
      helicopter_integral_DWork.HILInitialize_AIMinimums[1] =
        helicopter_integral_P.HILInitialize_AILow;
      helicopter_integral_DWork.HILInitialize_AIMinimums[2] =
        helicopter_integral_P.HILInitialize_AILow;
      helicopter_integral_DWork.HILInitialize_AIMinimums[3] =
        helicopter_integral_P.HILInitialize_AILow;
      helicopter_integral_DWork.HILInitialize_AIMaximums[0] =
        helicopter_integral_P.HILInitialize_AIHigh;
      helicopter_integral_DWork.HILInitialize_AIMaximums[1] =
        helicopter_integral_P.HILInitialize_AIHigh;
      helicopter_integral_DWork.HILInitialize_AIMaximums[2] =
        helicopter_integral_P.HILInitialize_AIHigh;
      helicopter_integral_DWork.HILInitialize_AIMaximums[3] =
        helicopter_integral_P.HILInitialize_AIHigh;
      result = hil_set_analog_input_ranges
        (helicopter_integral_DWork.HILInitialize_Card,
         helicopter_integral_P.HILInitialize_AIChannels, 4U,
         &helicopter_integral_DWork.HILInitialize_AIMinimums[0],
         &helicopter_integral_DWork.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helicopter_integral_M, _rt_error_message);
        return;
      }
    }

    if ((helicopter_integral_P.HILInitialize_AOPStart && !is_switching) ||
        (helicopter_integral_P.HILInitialize_AOPEnter && is_switching)) {
      helicopter_integral_DWork.HILInitialize_AOMinimums[0] =
        helicopter_integral_P.HILInitialize_AOLow;
      helicopter_integral_DWork.HILInitialize_AOMinimums[1] =
        helicopter_integral_P.HILInitialize_AOLow;
      helicopter_integral_DWork.HILInitialize_AOMinimums[2] =
        helicopter_integral_P.HILInitialize_AOLow;
      helicopter_integral_DWork.HILInitialize_AOMinimums[3] =
        helicopter_integral_P.HILInitialize_AOLow;
      helicopter_integral_DWork.HILInitialize_AOMaximums[0] =
        helicopter_integral_P.HILInitialize_AOHigh;
      helicopter_integral_DWork.HILInitialize_AOMaximums[1] =
        helicopter_integral_P.HILInitialize_AOHigh;
      helicopter_integral_DWork.HILInitialize_AOMaximums[2] =
        helicopter_integral_P.HILInitialize_AOHigh;
      helicopter_integral_DWork.HILInitialize_AOMaximums[3] =
        helicopter_integral_P.HILInitialize_AOHigh;
      result = hil_set_analog_output_ranges
        (helicopter_integral_DWork.HILInitialize_Card,
         helicopter_integral_P.HILInitialize_AOChannels, 4U,
         &helicopter_integral_DWork.HILInitialize_AOMinimums[0],
         &helicopter_integral_DWork.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helicopter_integral_M, _rt_error_message);
        return;
      }
    }

    if ((helicopter_integral_P.HILInitialize_AOStart && !is_switching) ||
        (helicopter_integral_P.HILInitialize_AOEnter && is_switching)) {
      helicopter_integral_DWork.HILInitialize_AOVoltages[0] =
        helicopter_integral_P.HILInitialize_AOInitial;
      helicopter_integral_DWork.HILInitialize_AOVoltages[1] =
        helicopter_integral_P.HILInitialize_AOInitial;
      helicopter_integral_DWork.HILInitialize_AOVoltages[2] =
        helicopter_integral_P.HILInitialize_AOInitial;
      helicopter_integral_DWork.HILInitialize_AOVoltages[3] =
        helicopter_integral_P.HILInitialize_AOInitial;
      result = hil_write_analog(helicopter_integral_DWork.HILInitialize_Card,
        helicopter_integral_P.HILInitialize_AOChannels, 4U,
        &helicopter_integral_DWork.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helicopter_integral_M, _rt_error_message);
        return;
      }
    }

    if (helicopter_integral_P.HILInitialize_AOReset) {
      helicopter_integral_DWork.HILInitialize_AOVoltages[0] =
        helicopter_integral_P.HILInitialize_AOWatchdog;
      helicopter_integral_DWork.HILInitialize_AOVoltages[1] =
        helicopter_integral_P.HILInitialize_AOWatchdog;
      helicopter_integral_DWork.HILInitialize_AOVoltages[2] =
        helicopter_integral_P.HILInitialize_AOWatchdog;
      helicopter_integral_DWork.HILInitialize_AOVoltages[3] =
        helicopter_integral_P.HILInitialize_AOWatchdog;
      result = hil_watchdog_set_analog_expiration_state
        (helicopter_integral_DWork.HILInitialize_Card,
         helicopter_integral_P.HILInitialize_AOChannels, 4U,
         &helicopter_integral_DWork.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helicopter_integral_M, _rt_error_message);
        return;
      }
    }

    result = hil_set_digital_directions
      (helicopter_integral_DWork.HILInitialize_Card,
       helicopter_integral_P.HILInitialize_DIChannels, 8U,
       helicopter_integral_P.HILInitialize_DOChannels, 8U);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(helicopter_integral_M, _rt_error_message);
      return;
    }

    if ((helicopter_integral_P.HILInitialize_DOStart && !is_switching) ||
        (helicopter_integral_P.HILInitialize_DOEnter && is_switching)) {
      {
        int_T i1;
        boolean_T *dw_DOBits = &helicopter_integral_DWork.HILInitialize_DOBits[0];
        for (i1=0; i1 < 8; i1++) {
          dw_DOBits[i1] = helicopter_integral_P.HILInitialize_DOInitial;
        }
      }

      result = hil_write_digital(helicopter_integral_DWork.HILInitialize_Card,
        helicopter_integral_P.HILInitialize_DOChannels, 8U, (t_boolean *)
        &helicopter_integral_DWork.HILInitialize_DOBits[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helicopter_integral_M, _rt_error_message);
        return;
      }
    }

    if (helicopter_integral_P.HILInitialize_DOReset) {
      {
        int_T i1;
        int32_T *dw_DOStates =
          &helicopter_integral_DWork.HILInitialize_DOStates[0];
        for (i1=0; i1 < 8; i1++) {
          dw_DOStates[i1] = helicopter_integral_P.HILInitialize_DOWatchdog;
        }
      }

      result = hil_watchdog_set_digital_expiration_state
        (helicopter_integral_DWork.HILInitialize_Card,
         helicopter_integral_P.HILInitialize_DOChannels, 8U, (const
          t_digital_state *) &helicopter_integral_DWork.HILInitialize_DOStates[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helicopter_integral_M, _rt_error_message);
        return;
      }
    }

    if ((helicopter_integral_P.HILInitialize_EIPStart && !is_switching) ||
        (helicopter_integral_P.HILInitialize_EIPEnter && is_switching)) {
      helicopter_integral_DWork.HILInitialize_QuadratureModes[0] =
        helicopter_integral_P.HILInitialize_EIQuadrature;
      helicopter_integral_DWork.HILInitialize_QuadratureModes[1] =
        helicopter_integral_P.HILInitialize_EIQuadrature;
      helicopter_integral_DWork.HILInitialize_QuadratureModes[2] =
        helicopter_integral_P.HILInitialize_EIQuadrature;
      helicopter_integral_DWork.HILInitialize_QuadratureModes[3] =
        helicopter_integral_P.HILInitialize_EIQuadrature;
      result = hil_set_encoder_quadrature_mode
        (helicopter_integral_DWork.HILInitialize_Card,
         helicopter_integral_P.HILInitialize_EIChannels, 4U,
         (t_encoder_quadrature_mode *)
         &helicopter_integral_DWork.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helicopter_integral_M, _rt_error_message);
        return;
      }

      helicopter_integral_DWork.HILInitialize_FilterFrequency[0] =
        helicopter_integral_P.HILInitialize_EIFrequency;
      helicopter_integral_DWork.HILInitialize_FilterFrequency[1] =
        helicopter_integral_P.HILInitialize_EIFrequency;
      helicopter_integral_DWork.HILInitialize_FilterFrequency[2] =
        helicopter_integral_P.HILInitialize_EIFrequency;
      helicopter_integral_DWork.HILInitialize_FilterFrequency[3] =
        helicopter_integral_P.HILInitialize_EIFrequency;
      result = hil_set_encoder_filter_frequency
        (helicopter_integral_DWork.HILInitialize_Card,
         helicopter_integral_P.HILInitialize_EIChannels, 4U,
         &helicopter_integral_DWork.HILInitialize_FilterFrequency[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helicopter_integral_M, _rt_error_message);
        return;
      }
    }

    if ((helicopter_integral_P.HILInitialize_EIStart && !is_switching) ||
        (helicopter_integral_P.HILInitialize_EIEnter && is_switching)) {
      helicopter_integral_DWork.HILInitialize_InitialEICounts[0] =
        helicopter_integral_P.HILInitialize_EIInitial;
      helicopter_integral_DWork.HILInitialize_InitialEICounts[1] =
        helicopter_integral_P.HILInitialize_EIInitial;
      helicopter_integral_DWork.HILInitialize_InitialEICounts[2] =
        helicopter_integral_P.HILInitialize_EIInitial;
      helicopter_integral_DWork.HILInitialize_InitialEICounts[3] =
        helicopter_integral_P.HILInitialize_EIInitial;
      result = hil_set_encoder_counts
        (helicopter_integral_DWork.HILInitialize_Card,
         helicopter_integral_P.HILInitialize_EIChannels, 4U,
         &helicopter_integral_DWork.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helicopter_integral_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_encoder_timebase_block): '<S1>/HIL Read Encoder Timebase' */

  /* S-Function Block: helicopter_integral/3-DOF Plant/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader
      (helicopter_integral_DWork.HILInitialize_Card,
       helicopter_integral_P.HILReadEncoderTimebase_SamplesI,
       helicopter_integral_P.HILReadEncoderTimebase_Channels, 3,
       &helicopter_integral_DWork.HILReadEncoderTimebase_Task);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(helicopter_integral_M, _rt_error_message);
    }
  }

  /* Start for S-Function (game_controller_block): '<S3>/Game Controller' */

  /* S-Function Block: helicopter_integral/Desired Position from Joystick/Game Controller (game_controller_block) */
  {
    if (helicopter_integral_P.GameController_Enabled) {
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
        (helicopter_integral_P.GameController_ControllerNumber,
         helicopter_integral_P.GameController_BufferSize, deadzone, saturation,
         helicopter_integral_P.GameController_AutoCenter, 0, 1.0,
         &helicopter_integral_DWork.GameController_Controller);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helicopter_integral_M, _rt_error_message);
      }
    }
  }

  /* Start for RateTransition: '<S3>/Rate Transition: z' */
  helicopter_integral_B.RateTransitionz =
    helicopter_integral_P.RateTransitionz_X0;

  /* Start for RateTransition: '<S3>/Rate Transition: x' */
  helicopter_integral_B.RateTransitionx =
    helicopter_integral_P.RateTransitionx_X0;

  /* Start for RateTransition: '<S3>/Rate Transition: y' */
  helicopter_integral_B.RateTransitiony =
    helicopter_integral_P.RateTransitiony_X0;

  {
    int32_T i;

    /* InitializeConditions for Integrator: '<S3>/Des Position:  Elevation (deg)' */
    helicopter_integral_X.DesPositionElevationdeg_CSTATE =
      helicopter_integral_P.DesPositionElevationdeg_IC;

    /* InitializeConditions for Integrator: '<S3>/Des Position:  Travel (deg)' */
    helicopter_integral_X.DesPositionTraveldeg_CSTATE =
      helicopter_integral_P.DesPositionTraveldeg_IC;

    /* InitializeConditions for RateLimiter: '<Root>/Des Position Rate Limiter' */
    helicopter_integral_DWork.LastMajorTime = (rtInf);

    /* InitializeConditions for Atomic SubSystem: '<Root>/Observer' */
    for (i = 0; i < 6; i++) {
      /* InitializeConditions for Integrator: '<Root>/Integrator' */
      helicopter_integral_X.Integrator_CSTATE[i] =
        helicopter_integral_P.Integrator_IC_n;

      /* InitializeConditions for Integrator: '<S4>/Integrator' */
      helicopter_integral_X.Integrator_CSTATE_i[i] =
        helicopter_integral_P.Integrator_IC;
    }

    /* End of InitializeConditions for SubSystem: '<Root>/Observer' */

    /* InitializeConditions for RateTransition: '<S3>/Rate Transition: z' */
    helicopter_integral_DWork.RateTransitionz_Buffer0 =
      helicopter_integral_P.RateTransitionz_X0;

    /* InitializeConditions for RateTransition: '<S3>/Rate Transition: x' */
    helicopter_integral_DWork.RateTransitionx_Buffer0 =
      helicopter_integral_P.RateTransitionx_X0;

    /* InitializeConditions for RateTransition: '<S3>/Rate Transition: y' */
    helicopter_integral_DWork.RateTransitiony_Buffer0 =
      helicopter_integral_P.RateTransitiony_X0;
  }
}

/* Model terminate function */
void helicopter_integral_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<S1>/HIL Initialize' */

  /* S-Function Block: helicopter_integral/3-DOF Plant/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_digital_outputs = 0;
    hil_task_stop_all(helicopter_integral_DWork.HILInitialize_Card);
    hil_monitor_stop_all(helicopter_integral_DWork.HILInitialize_Card);
    is_switching = false;
    if ((helicopter_integral_P.HILInitialize_AOTerminate && !is_switching) ||
        (helicopter_integral_P.HILInitialize_AOExit && is_switching)) {
      helicopter_integral_DWork.HILInitialize_AOVoltages[0] =
        helicopter_integral_P.HILInitialize_AOFinal;
      helicopter_integral_DWork.HILInitialize_AOVoltages[1] =
        helicopter_integral_P.HILInitialize_AOFinal;
      helicopter_integral_DWork.HILInitialize_AOVoltages[2] =
        helicopter_integral_P.HILInitialize_AOFinal;
      helicopter_integral_DWork.HILInitialize_AOVoltages[3] =
        helicopter_integral_P.HILInitialize_AOFinal;
      num_final_analog_outputs = 4U;
    }

    if ((helicopter_integral_P.HILInitialize_DOTerminate && !is_switching) ||
        (helicopter_integral_P.HILInitialize_DOExit && is_switching)) {
      {
        int_T i1;
        boolean_T *dw_DOBits = &helicopter_integral_DWork.HILInitialize_DOBits[0];
        for (i1=0; i1 < 8; i1++) {
          dw_DOBits[i1] = helicopter_integral_P.HILInitialize_DOFinal;
        }
      }

      num_final_digital_outputs = 8U;
    }

    if (0
        || num_final_analog_outputs > 0
        || num_final_digital_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(helicopter_integral_DWork.HILInitialize_Card
                         , helicopter_integral_P.HILInitialize_AOChannels,
                         num_final_analog_outputs
                         , NULL, 0
                         , helicopter_integral_P.HILInitialize_DOChannels,
                         num_final_digital_outputs
                         , NULL, 0
                         , &helicopter_integral_DWork.HILInitialize_AOVoltages[0]
                         , NULL
                         , &helicopter_integral_DWork.HILInitialize_DOBits[0]
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog
            (helicopter_integral_DWork.HILInitialize_Card,
             helicopter_integral_P.HILInitialize_AOChannels,
             num_final_analog_outputs,
             &helicopter_integral_DWork.HILInitialize_AOVoltages[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_digital_outputs > 0) {
          local_result = hil_write_digital
            (helicopter_integral_DWork.HILInitialize_Card,
             helicopter_integral_P.HILInitialize_DOChannels,
             num_final_digital_outputs,
             &helicopter_integral_DWork.HILInitialize_DOBits[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(helicopter_integral_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(helicopter_integral_DWork.HILInitialize_Card);
    hil_monitor_delete_all(helicopter_integral_DWork.HILInitialize_Card);
    hil_close(helicopter_integral_DWork.HILInitialize_Card);
    helicopter_integral_DWork.HILInitialize_Card = NULL;
  }

  /* Terminate for S-Function (game_controller_block): '<S3>/Game Controller' */

  /* S-Function Block: helicopter_integral/Desired Position from Joystick/Game Controller (game_controller_block) */
  {
    if (helicopter_integral_P.GameController_Enabled) {
      game_controller_close(helicopter_integral_DWork.GameController_Controller);
      helicopter_integral_DWork.GameController_Controller = NULL;
    }
  }
}
