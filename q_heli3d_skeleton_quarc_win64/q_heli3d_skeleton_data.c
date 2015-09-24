/*
 * q_heli3d_skeleton_data.c
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

/* Block parameters (auto storage) */
Parameters_q_heli3d_skeleton q_heli3d_skeleton_P = {
  0.017453292519943295,                /* Expression: pi/180
                                        * Referenced by: '<S12>/Gain1'
                                        */

  /*  Expression: rep_seq_t - min(rep_seq_t)
   * Referenced by: '<S9>/Look-Up Table1'
   */
  { 0.0, 15.0, 16.0, 30.0, 45.0, 46.0, 60.0 },

  /*  Expression: rep_seq_y
   * Referenced by: '<S9>/Look-Up Table1'
   */
  { 0.0, 0.0, 30.0, 30.0, 30.0, 0.0, 0.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Amplitude: Travel (deg)'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Amplitude: Elevation (deg)'
                                        */
  0.017453292519943295,                /* Expression: pi/180
                                        * Referenced by: '<S10>/Gain1'
                                        */

  /*  Expression: B
   * Referenced by: '<S4>/Gain2'
   */
  { 0.0, 0.0, 0.0, 0.085794874947817359, 0.58101432973052292, 0.0, 0.0, 0.0, 0.0,
    0.085794874947817359, -0.58101432973052292, 0.0 },

  /*  Expression: L'
   * Referenced by: '<S4>/Gain4'
   */
  { 28.953763498392302, 2.7769419379538962, 1.1187688943238812, 422.247800855479,
    50.593387767422143, 9.7052236840461266, 0.76791464049009073,
    28.026143055334238, -0.21347939828758725, 50.667589780049944,
    390.07575540073657, 27.134956988026783, -0.53751164421304887,
    2.3572745603323622, 27.872907188659145, 10.272364411477543,
    28.857838769453924, 389.04635246435811 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Integrator'
                                        */

  /*  Expression: A
   * Referenced by: '<S4>/Gain1'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.2303958542095543,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0 },

  /*  Expression: C
   * Referenced by: '<S4>/Gain3'
   */
  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0 },
  0.0,                                 /* Expression: set_other_outputs_at_start
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  0.0,                                 /* Expression: set_other_outputs_at_switch_in
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  0.0,                                 /* Expression: set_other_outputs_at_terminate
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  0.0,                                 /* Expression: set_other_outputs_at_switch_out
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  10.0,                                /* Expression: analog_input_maximums
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  -10.0,                               /* Expression: analog_input_minimums
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  10.0,                                /* Expression: analog_output_maximums
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  -10.0,                               /* Expression: analog_output_minimums
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  0.0,                                 /* Expression: initial_analog_outputs
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  0.0,                                 /* Expression: final_analog_outputs
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  0.0,                                 /* Expression: watchdog_analog_outputs
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  1.6666666666666668E+7,               /* Expression: encoder_filter_frequency
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  16276.041666666668,                  /* Expression: pwm_frequency
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  0.0,                                 /* Expression: initial_pwm_outputs
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  0.0,                                 /* Expression: final_pwm_outputs
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<Root>/Program = 1 Joystick = 2'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S2>/Signal Generator: Elevation'
                                        */
  0.04,                                /* Expression: 0.04
                                        * Referenced by: '<S2>/Signal Generator: Elevation'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S2>/Elev Constant'
                                        */
  -27.5,                               /* Expression: gain
                                        * Referenced by: '<S6>/Slider Gain'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Constant: Pitch (deg)'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S2>/Signal Generator: Travel'
                                        */
  0.03,                                /* Expression: 0.03
                                        * Referenced by: '<S2>/Signal Generator: Travel'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S2>/Travel Constant'
                                        */
  0.0,                                 /* Expression: gain
                                        * Referenced by: '<S7>/Slider Gain'
                                        */
  60.0,                                /* Expression: period
                                        * Referenced by: '<S9>/Constant'
                                        */
  -27.5,                               /* Expression: elev_0*180/pi
                                        * Referenced by: '<S3>/Des Position:  Elevation (deg)'
                                        */
  27.5,                                /* Expression: CMD_ELEV_POS_LIMIT_UPPER
                                        * Referenced by: '<S3>/Des Position:  Elevation (deg)'
                                        */
  -27.5,                               /* Expression: CMD_ELEV_POS_LIMIT_LOWER
                                        * Referenced by: '<S3>/Des Position:  Elevation (deg)'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Constant: Pitch (deg)'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Des Position:  Travel (deg)'
                                        */
  0.78539816339744828,                 /* Expression: CMD_RATE_LIMIT
                                        * Referenced by: '<Root>/Des Position Rate Limiter'
                                        */
  -0.78539816339744828,                /* Expression: -CMD_RATE_LIMIT
                                        * Referenced by: '<Root>/Des Position Rate Limiter'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S5>/des vel'
                                        */

  /*  Expression: K
   * Referenced by: '<Root>/Gain2'
   */
  { 10.000000000000009, 10.000000000000009, 13.391584681902659,
    -13.391584681902659, -14.142135623730999, 14.142135623730999,
    10.796160373059895, 10.796160373059895, 4.8008989407153315,
    -4.8008989407153315, -17.545512289276086, 17.545512289276086 },
  7.4556381118881161,                  /* Expression: Vo
                                        * Referenced by: '<Root>/Bias'
                                        */
  24.0,                                /* Expression: VMAX_AMP
                                        * Referenced by: '<S1>/Amplifier Voltage  Limit (V)'
                                        */
  -24.0,                               /* Expression: -VMAX_AMP
                                        * Referenced by: '<S1>/Amplifier Voltage  Limit (V)'
                                        */
  0.2,                                 /* Expression:  1 / K_AMP
                                        * Referenced by: '<S1>/Amplifier Gain Pre-Compensation'
                                        */
  10.0,                                /* Expression: VMAX_DAC
                                        * Referenced by: '<S1>/DACB Limit (V)'
                                        */
  -10.0,                               /* Expression: -VMAX_DAC
                                        * Referenced by: '<S1>/DACB Limit (V)'
                                        */
  5.0,                                 /* Expression:  K_AMP
                                        * Referenced by: '<S1>/Amplifier Gain'
                                        */
  -0.0015339807878856412,              /* Expression: K_EC_E
                                        * Referenced by: '<S1>/Encoder Resolution: Elevation (rad//count)'
                                        */
  -0.47996554429844063,                /* Expression: elev_0
                                        * Referenced by: '<S1>/Initial Elevation (rad)'
                                        */
  0.0015339807878856412,               /* Expression: K_EC_P
                                        * Referenced by: '<S1>/Encoder Resolution: Pitch (rad//count)'
                                        */
  0.00076699039394282058,              /* Expression: K_EC_T
                                        * Referenced by: '<S1>/Encoder Resolution: Travel (rad//count)'
                                        */

  /*  Expression: [1 1 1 1]
   * Referenced by: '<S1>/Enable Amp'
   */
  { 1.0, 1.0, 1.0, 1.0 },
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S3>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Rate Transition: z'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S11>/Inverse'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S11>/Bias'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S11>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Rate Transition: x'
                                        */
  40.0,                                /* Expression: K_JOYSTICK_X
                                        * Referenced by: '<S3>/Calibration: X  (deg//s//V)'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Rate Transition: y'
                                        */
  45.0,                                /* Expression: K_JOYSTICK_Y
                                        * Referenced by: '<S3>/Calibration: Y  (deg//s//V)'
                                        */

  /*  Computed Parameter: HILInitialize_CKChannels
   * Referenced by: '<S1>/HIL Initialize'
   */
  { 0, 1 },

  /*  Computed Parameter: HILInitialize_CKModes
   * Referenced by: '<S1>/HIL Initialize'
   */
  { 0, 0 },
  2,                                   /* Computed Parameter: HILInitialize_DOWatchdog
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_EIInitial
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_POModes
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILReadEncoderTimebase_Clock
                                        * Referenced by: '<S1>/HIL Read Encoder Timebase'
                                        */

  /*  Computed Parameter: HILInitialize_AIChannels
   * Referenced by: '<S1>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U },

  /*  Computed Parameter: HILInitialize_AOChannels
   * Referenced by: '<S1>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U },

  /*  Computed Parameter: HILInitialize_DIChannels
   * Referenced by: '<S1>/HIL Initialize'
   */
  { 8U, 9U, 10U, 11U, 12U, 13U, 14U, 15U },

  /*  Computed Parameter: HILInitialize_DOChannels
   * Referenced by: '<S1>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /*  Computed Parameter: HILInitialize_EIChannels
   * Referenced by: '<S1>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U },
  4U,                                  /* Computed Parameter: HILInitialize_EIQuadrature
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */

  /*  Computed Parameter: HILReadEncoderTimebase_Channels
   * Referenced by: '<S1>/HIL Read Encoder Timebase'
   */
  { 0U, 1U, 2U },
  500U,                                /* Computed Parameter: HILReadEncoderTimebase_SamplesI
                                        * Referenced by: '<S1>/HIL Read Encoder Timebase'
                                        */

  /*  Computed Parameter: HILWriteAnalog_Channels
   * Referenced by: '<S1>/HIL Write Analog'
   */
  { 0U, 1U },

  /*  Computed Parameter: HILWriteDigital_Channels
   * Referenced by: '<S1>/HIL Write Digital'
   */
  { 0U, 1U, 2U, 3U },
  12U,                                 /* Computed Parameter: GameController_BufferSize
                                        * Referenced by: '<S3>/Game Controller'
                                        */
  0U,                                  /* Expression: uint8(0)
                                        * Referenced by: '<S8>/SwitchControl'
                                        */
  1U,                                  /* Expression: uint8(1)
                                        * Referenced by: '<S8>/Constant'
                                        */
  1U,                                  /* Computed Parameter: GameController_ControllerNumber
                                        * Referenced by: '<S3>/Game Controller'
                                        */
  1,                                   /* Computed Parameter: HILInitialize_Active
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  1,                                   /* Computed Parameter: HILInitialize_CKPStart
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_CKPEnter
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_CKStart
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_CKEnter
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_AIPStart
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_AIPEnter
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  1,                                   /* Computed Parameter: HILInitialize_AOPStart
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_AOPEnter
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  1,                                   /* Computed Parameter: HILInitialize_AOStart
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_AOEnter
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  1,                                   /* Computed Parameter: HILInitialize_AOTerminate
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_AOExit
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_AOReset
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_DOPStart
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_DOPEnter
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  1,                                   /* Computed Parameter: HILInitialize_DOStart
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_DOEnter
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  1,                                   /* Computed Parameter: HILInitialize_DOTerminate
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_DOExit
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_DOReset
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  1,                                   /* Computed Parameter: HILInitialize_EIPStart
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_EIPEnter
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  1,                                   /* Computed Parameter: HILInitialize_EIStart
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_EIEnter
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  1,                                   /* Computed Parameter: HILInitialize_POPStart
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_POPEnter
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  1,                                   /* Computed Parameter: HILInitialize_POStart
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_POEnter
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  1,                                   /* Computed Parameter: HILInitialize_POTerminate
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_POExit
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_POReset
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_OOReset
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_DOInitial
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_DOFinal
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  1,                                   /* Computed Parameter: HILReadEncoderTimebase_Active
                                        * Referenced by: '<S1>/HIL Read Encoder Timebase'
                                        */
  0,                                   /* Computed Parameter: HILWriteAnalog_Active
                                        * Referenced by: '<S1>/HIL Write Analog'
                                        */
  0,                                   /* Computed Parameter: HILWriteDigital_Active
                                        * Referenced by: '<S1>/HIL Write Digital'
                                        */
  0,                                   /* Computed Parameter: GameController_AutoCenter
                                        * Referenced by: '<S3>/Game Controller'
                                        */
  1                                    /* Computed Parameter: GameController_Enabled
                                        * Referenced by: '<S3>/Game Controller'
                                        */
};
