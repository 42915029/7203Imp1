  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 6;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (q_heli3d_skeleton_P)
    ;%
      section.nData     = 67;
      section.data(67)  = dumData; %prealloc
      
	  ;% q_heli3d_skeleton_P.Gain1_Gain
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% q_heli3d_skeleton_P.LookUpTable1_XData
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% q_heli3d_skeleton_P.LookUpTable1_YData
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 8;
	
	  ;% q_heli3d_skeleton_P.AmplitudeTraveldeg_Gain
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 15;
	
	  ;% q_heli3d_skeleton_P.AmplitudeElevationdeg_Gain
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 16;
	
	  ;% q_heli3d_skeleton_P.Gain1_Gain_d
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 17;
	
	  ;% q_heli3d_skeleton_P.Gain2_Gain
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 18;
	
	  ;% q_heli3d_skeleton_P.Gain4_Gain
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 30;
	
	  ;% q_heli3d_skeleton_P.Integrator_IC
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 48;
	
	  ;% q_heli3d_skeleton_P.Gain1_Gain_f
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 49;
	
	  ;% q_heli3d_skeleton_P.Gain3_Gain
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 85;
	
	  ;% q_heli3d_skeleton_P.HILInitialize_OOStart
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 103;
	
	  ;% q_heli3d_skeleton_P.HILInitialize_OOEnter
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 104;
	
	  ;% q_heli3d_skeleton_P.HILInitialize_OOTerminate
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 105;
	
	  ;% q_heli3d_skeleton_P.HILInitialize_OOExit
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 106;
	
	  ;% q_heli3d_skeleton_P.HILInitialize_AIHigh
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 107;
	
	  ;% q_heli3d_skeleton_P.HILInitialize_AILow
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 108;
	
	  ;% q_heli3d_skeleton_P.HILInitialize_AOHigh
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 109;
	
	  ;% q_heli3d_skeleton_P.HILInitialize_AOLow
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 110;
	
	  ;% q_heli3d_skeleton_P.HILInitialize_AOInitial
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 111;
	
	  ;% q_heli3d_skeleton_P.HILInitialize_AOFinal
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 112;
	
	  ;% q_heli3d_skeleton_P.HILInitialize_AOWatchdog
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 113;
	
	  ;% q_heli3d_skeleton_P.HILInitialize_EIFrequency
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 114;
	
	  ;% q_heli3d_skeleton_P.HILInitialize_POFrequency
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 115;
	
	  ;% q_heli3d_skeleton_P.HILInitialize_POInitial
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 116;
	
	  ;% q_heli3d_skeleton_P.HILInitialize_POFinal
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 117;
	
	  ;% q_heli3d_skeleton_P.Program1Joystick2_Value
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 118;
	
	  ;% q_heli3d_skeleton_P.SignalGeneratorElevation_Amplit
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 119;
	
	  ;% q_heli3d_skeleton_P.SignalGeneratorElevation_Freque
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 120;
	
	  ;% q_heli3d_skeleton_P.ElevConstant_Value
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 121;
	
	  ;% q_heli3d_skeleton_P.SliderGain_Gain
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 122;
	
	  ;% q_heli3d_skeleton_P.ConstantPitchdeg_Value
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 123;
	
	  ;% q_heli3d_skeleton_P.SignalGeneratorTravel_Amplitude
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 124;
	
	  ;% q_heli3d_skeleton_P.SignalGeneratorTravel_Frequency
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 125;
	
	  ;% q_heli3d_skeleton_P.TravelConstant_Value
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 126;
	
	  ;% q_heli3d_skeleton_P.SliderGain_Gain_p
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 127;
	
	  ;% q_heli3d_skeleton_P.Constant_Value
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 128;
	
	  ;% q_heli3d_skeleton_P.DesPositionElevationdeg_IC
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 129;
	
	  ;% q_heli3d_skeleton_P.DesPositionElevationdeg_UpperSa
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 130;
	
	  ;% q_heli3d_skeleton_P.DesPositionElevationdeg_LowerSa
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 131;
	
	  ;% q_heli3d_skeleton_P.ConstantPitchdeg_Value_h
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 132;
	
	  ;% q_heli3d_skeleton_P.DesPositionTraveldeg_IC
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 133;
	
	  ;% q_heli3d_skeleton_P.DesPositionRateLimiter_RisingLi
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 134;
	
	  ;% q_heli3d_skeleton_P.DesPositionRateLimiter_FallingL
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 135;
	
	  ;% q_heli3d_skeleton_P.desvel_Value
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 136;
	
	  ;% q_heli3d_skeleton_P.Gain2_Gain_d
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 137;
	
	  ;% q_heli3d_skeleton_P.Bias_Bias
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 149;
	
	  ;% q_heli3d_skeleton_P.AmplifierVoltageLimitV_UpperSat
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 150;
	
	  ;% q_heli3d_skeleton_P.AmplifierVoltageLimitV_LowerSat
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 151;
	
	  ;% q_heli3d_skeleton_P.AmplifierGainPreCompensation_Ga
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 152;
	
	  ;% q_heli3d_skeleton_P.DACBLimitV_UpperSat
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 153;
	
	  ;% q_heli3d_skeleton_P.DACBLimitV_LowerSat
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 154;
	
	  ;% q_heli3d_skeleton_P.AmplifierGain_Gain
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 155;
	
	  ;% q_heli3d_skeleton_P.EncoderResolutionElevationradco
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 156;
	
	  ;% q_heli3d_skeleton_P.InitialElevationrad_Bias
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 157;
	
	  ;% q_heli3d_skeleton_P.EncoderResolutionPitchradcount_
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 158;
	
	  ;% q_heli3d_skeleton_P.EncoderResolutionTravelradcount
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 159;
	
	  ;% q_heli3d_skeleton_P.EnableAmp_Value
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 160;
	
	  ;% q_heli3d_skeleton_P.Constant_Value_l
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 164;
	
	  ;% q_heli3d_skeleton_P.RateTransitionz_X0
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 165;
	
	  ;% q_heli3d_skeleton_P.Inverse_Gain
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 166;
	
	  ;% q_heli3d_skeleton_P.Bias_Bias_k
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 167;
	
	  ;% q_heli3d_skeleton_P.Constant_Value_c
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 168;
	
	  ;% q_heli3d_skeleton_P.RateTransitionx_X0
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 169;
	
	  ;% q_heli3d_skeleton_P.CalibrationXdegsV_Gain
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 170;
	
	  ;% q_heli3d_skeleton_P.RateTransitiony_X0
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 171;
	
	  ;% q_heli3d_skeleton_P.CalibrationYdegsV_Gain
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 172;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% q_heli3d_skeleton_P.HILInitialize_CKChannels
	  section.data(1).logicalSrcIdx = 67;
	  section.data(1).dtTransOffset = 0;
	
	  ;% q_heli3d_skeleton_P.HILInitialize_CKModes
	  section.data(2).logicalSrcIdx = 68;
	  section.data(2).dtTransOffset = 2;
	
	  ;% q_heli3d_skeleton_P.HILInitialize_DOWatchdog
	  section.data(3).logicalSrcIdx = 69;
	  section.data(3).dtTransOffset = 4;
	
	  ;% q_heli3d_skeleton_P.HILInitialize_EIInitial
	  section.data(4).logicalSrcIdx = 70;
	  section.data(4).dtTransOffset = 5;
	
	  ;% q_heli3d_skeleton_P.HILInitialize_POModes
	  section.data(5).logicalSrcIdx = 71;
	  section.data(5).dtTransOffset = 6;
	
	  ;% q_heli3d_skeleton_P.HILReadEncoderTimebase_Clock
	  section.data(6).logicalSrcIdx = 72;
	  section.data(6).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% q_heli3d_skeleton_P.HILInitialize_AIChannels
	  section.data(1).logicalSrcIdx = 73;
	  section.data(1).dtTransOffset = 0;
	
	  ;% q_heli3d_skeleton_P.HILInitialize_AOChannels
	  section.data(2).logicalSrcIdx = 74;
	  section.data(2).dtTransOffset = 4;
	
	  ;% q_heli3d_skeleton_P.HILInitialize_DIChannels
	  section.data(3).logicalSrcIdx = 75;
	  section.data(3).dtTransOffset = 8;
	
	  ;% q_heli3d_skeleton_P.HILInitialize_DOChannels
	  section.data(4).logicalSrcIdx = 76;
	  section.data(4).dtTransOffset = 16;
	
	  ;% q_heli3d_skeleton_P.HILInitialize_EIChannels
	  section.data(5).logicalSrcIdx = 77;
	  section.data(5).dtTransOffset = 24;
	
	  ;% q_heli3d_skeleton_P.HILInitialize_EIQuadrature
	  section.data(6).logicalSrcIdx = 78;
	  section.data(6).dtTransOffset = 28;
	
	  ;% q_heli3d_skeleton_P.HILReadEncoderTimebase_Channels
	  section.data(7).logicalSrcIdx = 79;
	  section.data(7).dtTransOffset = 29;
	
	  ;% q_heli3d_skeleton_P.HILReadEncoderTimebase_SamplesI
	  section.data(8).logicalSrcIdx = 80;
	  section.data(8).dtTransOffset = 32;
	
	  ;% q_heli3d_skeleton_P.HILWriteAnalog_Channels
	  section.data(9).logicalSrcIdx = 81;
	  section.data(9).dtTransOffset = 33;
	
	  ;% q_heli3d_skeleton_P.HILWriteDigital_Channels
	  section.data(10).logicalSrcIdx = 82;
	  section.data(10).dtTransOffset = 35;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% q_heli3d_skeleton_P.GameController_BufferSize
	  section.data(1).logicalSrcIdx = 83;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% q_heli3d_skeleton_P.SwitchControl_Threshold
	  section.data(1).logicalSrcIdx = 84;
	  section.data(1).dtTransOffset = 0;
	
	  ;% q_heli3d_skeleton_P.Constant_Value_p
	  section.data(2).logicalSrcIdx = 85;
	  section.data(2).dtTransOffset = 1;
	
	  ;% q_heli3d_skeleton_P.GameController_ControllerNumber
	  section.data(3).logicalSrcIdx = 86;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 40;
      section.data(40)  = dumData; %prealloc
      
	  ;% q_heli3d_skeleton_P.HILInitialize_Active
	  section.data(1).logicalSrcIdx = 87;
	  section.data(1).dtTransOffset = 0;
	
	  ;% q_heli3d_skeleton_P.HILInitialize_CKPStart
	  section.data(2).logicalSrcIdx = 88;
	  section.data(2).dtTransOffset = 1;
	
	  ;% q_heli3d_skeleton_P.HILInitialize_CKPEnter
	  section.data(3).logicalSrcIdx = 89;
	  section.data(3).dtTransOffset = 2;
	
	  ;% q_heli3d_skeleton_P.HILInitialize_CKStart
	  section.data(4).logicalSrcIdx = 90;
	  section.data(4).dtTransOffset = 3;
	
	  ;% q_heli3d_skeleton_P.HILInitialize_CKEnter
	  section.data(5).logicalSrcIdx = 91;
	  section.data(5).dtTransOffset = 4;
	
	  ;% q_heli3d_skeleton_P.HILInitialize_AIPStart
	  section.data(6).logicalSrcIdx = 92;
	  section.data(6).dtTransOffset = 5;
	
	  ;% q_heli3d_skeleton_P.HILInitialize_AIPEnter
	  section.data(7).logicalSrcIdx = 93;
	  section.data(7).dtTransOffset = 6;
	
	  ;% q_heli3d_skeleton_P.HILInitialize_AOPStart
	  section.data(8).logicalSrcIdx = 94;
	  section.data(8).dtTransOffset = 7;
	
	  ;% q_heli3d_skeleton_P.HILInitialize_AOPEnter
	  section.data(9).logicalSrcIdx = 95;
	  section.data(9).dtTransOffset = 8;
	
	  ;% q_heli3d_skeleton_P.HILInitialize_AOStart
	  section.data(10).logicalSrcIdx = 96;
	  section.data(10).dtTransOffset = 9;
	
	  ;% q_heli3d_skeleton_P.HILInitialize_AOEnter
	  section.data(11).logicalSrcIdx = 97;
	  section.data(11).dtTransOffset = 10;
	
	  ;% q_heli3d_skeleton_P.HILInitialize_AOTerminate
	  section.data(12).logicalSrcIdx = 98;
	  section.data(12).dtTransOffset = 11;
	
	  ;% q_heli3d_skeleton_P.HILInitialize_AOExit
	  section.data(13).logicalSrcIdx = 99;
	  section.data(13).dtTransOffset = 12;
	
	  ;% q_heli3d_skeleton_P.HILInitialize_AOReset
	  section.data(14).logicalSrcIdx = 100;
	  section.data(14).dtTransOffset = 13;
	
	  ;% q_heli3d_skeleton_P.HILInitialize_DOPStart
	  section.data(15).logicalSrcIdx = 101;
	  section.data(15).dtTransOffset = 14;
	
	  ;% q_heli3d_skeleton_P.HILInitialize_DOPEnter
	  section.data(16).logicalSrcIdx = 102;
	  section.data(16).dtTransOffset = 15;
	
	  ;% q_heli3d_skeleton_P.HILInitialize_DOStart
	  section.data(17).logicalSrcIdx = 103;
	  section.data(17).dtTransOffset = 16;
	
	  ;% q_heli3d_skeleton_P.HILInitialize_DOEnter
	  section.data(18).logicalSrcIdx = 104;
	  section.data(18).dtTransOffset = 17;
	
	  ;% q_heli3d_skeleton_P.HILInitialize_DOTerminate
	  section.data(19).logicalSrcIdx = 105;
	  section.data(19).dtTransOffset = 18;
	
	  ;% q_heli3d_skeleton_P.HILInitialize_DOExit
	  section.data(20).logicalSrcIdx = 106;
	  section.data(20).dtTransOffset = 19;
	
	  ;% q_heli3d_skeleton_P.HILInitialize_DOReset
	  section.data(21).logicalSrcIdx = 107;
	  section.data(21).dtTransOffset = 20;
	
	  ;% q_heli3d_skeleton_P.HILInitialize_EIPStart
	  section.data(22).logicalSrcIdx = 108;
	  section.data(22).dtTransOffset = 21;
	
	  ;% q_heli3d_skeleton_P.HILInitialize_EIPEnter
	  section.data(23).logicalSrcIdx = 109;
	  section.data(23).dtTransOffset = 22;
	
	  ;% q_heli3d_skeleton_P.HILInitialize_EIStart
	  section.data(24).logicalSrcIdx = 110;
	  section.data(24).dtTransOffset = 23;
	
	  ;% q_heli3d_skeleton_P.HILInitialize_EIEnter
	  section.data(25).logicalSrcIdx = 111;
	  section.data(25).dtTransOffset = 24;
	
	  ;% q_heli3d_skeleton_P.HILInitialize_POPStart
	  section.data(26).logicalSrcIdx = 112;
	  section.data(26).dtTransOffset = 25;
	
	  ;% q_heli3d_skeleton_P.HILInitialize_POPEnter
	  section.data(27).logicalSrcIdx = 113;
	  section.data(27).dtTransOffset = 26;
	
	  ;% q_heli3d_skeleton_P.HILInitialize_POStart
	  section.data(28).logicalSrcIdx = 114;
	  section.data(28).dtTransOffset = 27;
	
	  ;% q_heli3d_skeleton_P.HILInitialize_POEnter
	  section.data(29).logicalSrcIdx = 115;
	  section.data(29).dtTransOffset = 28;
	
	  ;% q_heli3d_skeleton_P.HILInitialize_POTerminate
	  section.data(30).logicalSrcIdx = 116;
	  section.data(30).dtTransOffset = 29;
	
	  ;% q_heli3d_skeleton_P.HILInitialize_POExit
	  section.data(31).logicalSrcIdx = 117;
	  section.data(31).dtTransOffset = 30;
	
	  ;% q_heli3d_skeleton_P.HILInitialize_POReset
	  section.data(32).logicalSrcIdx = 118;
	  section.data(32).dtTransOffset = 31;
	
	  ;% q_heli3d_skeleton_P.HILInitialize_OOReset
	  section.data(33).logicalSrcIdx = 119;
	  section.data(33).dtTransOffset = 32;
	
	  ;% q_heli3d_skeleton_P.HILInitialize_DOInitial
	  section.data(34).logicalSrcIdx = 120;
	  section.data(34).dtTransOffset = 33;
	
	  ;% q_heli3d_skeleton_P.HILInitialize_DOFinal
	  section.data(35).logicalSrcIdx = 121;
	  section.data(35).dtTransOffset = 34;
	
	  ;% q_heli3d_skeleton_P.HILReadEncoderTimebase_Active
	  section.data(36).logicalSrcIdx = 122;
	  section.data(36).dtTransOffset = 35;
	
	  ;% q_heli3d_skeleton_P.HILWriteAnalog_Active
	  section.data(37).logicalSrcIdx = 123;
	  section.data(37).dtTransOffset = 36;
	
	  ;% q_heli3d_skeleton_P.HILWriteDigital_Active
	  section.data(38).logicalSrcIdx = 124;
	  section.data(38).dtTransOffset = 37;
	
	  ;% q_heli3d_skeleton_P.GameController_AutoCenter
	  section.data(39).logicalSrcIdx = 125;
	  section.data(39).dtTransOffset = 38;
	
	  ;% q_heli3d_skeleton_P.GameController_Enabled
	  section.data(40).logicalSrcIdx = 126;
	  section.data(40).dtTransOffset = 39;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 3;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (q_heli3d_skeleton_B)
    ;%
      section.nData     = 25;
      section.data(25)  = dumData; %prealloc
      
	  ;% q_heli3d_skeleton_B.Program1Joystick2
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% q_heli3d_skeleton_B.SliderGain
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% q_heli3d_skeleton_B.ConstantPitchdeg
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% q_heli3d_skeleton_B.SliderGain_l
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% q_heli3d_skeleton_B.Constant
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% q_heli3d_skeleton_B.ConstantPitchdeg_j
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% q_heli3d_skeleton_B.DesPositionRateLimiter
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% q_heli3d_skeleton_B.desvel
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 9;
	
	  ;% q_heli3d_skeleton_B.Bias
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 10;
	
	  ;% q_heli3d_skeleton_B.DACBLimitV
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 12;
	
	  ;% q_heli3d_skeleton_B.AmplifierGain
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 14;
	
	  ;% q_heli3d_skeleton_B.InitialElevationrad
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 16;
	
	  ;% q_heli3d_skeleton_B.EncoderResolutionPitchradcount
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 17;
	
	  ;% q_heli3d_skeleton_B.EncoderResolutionTravelradcount
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 18;
	
	  ;% q_heli3d_skeleton_B.RateTransitionz
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 19;
	
	  ;% q_heli3d_skeleton_B.RateTransitionx
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 20;
	
	  ;% q_heli3d_skeleton_B.CalibrationXdegsV
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 21;
	
	  ;% q_heli3d_skeleton_B.RateTransitiony
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 22;
	
	  ;% q_heli3d_skeleton_B.CalibrationYdegsV
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 23;
	
	  ;% q_heli3d_skeleton_B.Sum1
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 24;
	
	  ;% q_heli3d_skeleton_B.Integrator
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 27;
	
	  ;% q_heli3d_skeleton_B.Gain1
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 33;
	
	  ;% q_heli3d_skeleton_B.Gain2
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 39;
	
	  ;% q_heli3d_skeleton_B.Gain4
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 45;
	
	  ;% q_heli3d_skeleton_B.Sum
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 51;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% q_heli3d_skeleton_B.Constant_k
	  section.data(1).logicalSrcIdx = 25;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% q_heli3d_skeleton_B.GameController_o2
	  section.data(1).logicalSrcIdx = 26;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 8;
    sectIdxOffset = 3;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (q_heli3d_skeleton_DWork)
    ;%
      section.nData     = 11;
      section.data(11)  = dumData; %prealloc
      
	  ;% q_heli3d_skeleton_DWork.HILInitialize_AIMinimums
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% q_heli3d_skeleton_DWork.HILInitialize_AIMaximums
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 4;
	
	  ;% q_heli3d_skeleton_DWork.HILInitialize_AOMinimums
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 8;
	
	  ;% q_heli3d_skeleton_DWork.HILInitialize_AOMaximums
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 12;
	
	  ;% q_heli3d_skeleton_DWork.HILInitialize_AOVoltages
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 16;
	
	  ;% q_heli3d_skeleton_DWork.HILInitialize_FilterFrequency
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 20;
	
	  ;% q_heli3d_skeleton_DWork.PrevY
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 24;
	
	  ;% q_heli3d_skeleton_DWork.LastMajorTime
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 27;
	
	  ;% q_heli3d_skeleton_DWork.RateTransitionz_Buffer0
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 28;
	
	  ;% q_heli3d_skeleton_DWork.RateTransitionx_Buffer0
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 29;
	
	  ;% q_heli3d_skeleton_DWork.RateTransitiony_Buffer0
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 30;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% q_heli3d_skeleton_DWork.GameController_Controller
	  section.data(1).logicalSrcIdx = 11;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% q_heli3d_skeleton_DWork.HILInitialize_Card
	  section.data(1).logicalSrcIdx = 12;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% q_heli3d_skeleton_DWork.HILReadEncoderTimebase_Task
	  section.data(1).logicalSrcIdx = 13;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% q_heli3d_skeleton_DWork.HILWriteAnalog_PWORK
	  section.data(1).logicalSrcIdx = 14;
	  section.data(1).dtTransOffset = 0;
	
	  ;% q_heli3d_skeleton_DWork.Scope_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 15;
	  section.data(2).dtTransOffset = 1;
	
	  ;% q_heli3d_skeleton_DWork.HILWriteDigital_PWORK
	  section.data(3).logicalSrcIdx = 16;
	  section.data(3).dtTransOffset = 2;
	
	  ;% q_heli3d_skeleton_DWork.Motorvoltage_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 17;
	  section.data(4).dtTransOffset = 3;
	
	  ;% q_heli3d_skeleton_DWork.Position_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 18;
	  section.data(5).dtTransOffset = 4;
	
	  ;% q_heli3d_skeleton_DWork.Velocity_PWORK.LoggedData
	  section.data(6).logicalSrcIdx = 19;
	  section.data(6).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% q_heli3d_skeleton_DWork.HILInitialize_DOStates
	  section.data(1).logicalSrcIdx = 20;
	  section.data(1).dtTransOffset = 0;
	
	  ;% q_heli3d_skeleton_DWork.HILInitialize_QuadratureModes
	  section.data(2).logicalSrcIdx = 21;
	  section.data(2).dtTransOffset = 8;
	
	  ;% q_heli3d_skeleton_DWork.HILInitialize_InitialEICounts
	  section.data(3).logicalSrcIdx = 22;
	  section.data(3).dtTransOffset = 12;
	
	  ;% q_heli3d_skeleton_DWork.HILReadEncoderTimebase_Buffer
	  section.data(4).logicalSrcIdx = 23;
	  section.data(4).dtTransOffset = 16;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% q_heli3d_skeleton_DWork.HILInitialize_DOBits
	  section.data(1).logicalSrcIdx = 24;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% q_heli3d_skeleton_DWork.HILWriteDigital_Buffer
	  section.data(1).logicalSrcIdx = 25;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 2053634143;
  targMap.checksum1 = 269281018;
  targMap.checksum2 = 3300606927;
  targMap.checksum3 = 1460317102;

