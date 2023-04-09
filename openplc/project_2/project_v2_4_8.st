FUNCTION_BLOCK crane
  VAR_INPUT
    in_Sensor : BOOL;
    in_MidLim : BOOL;
  END_VAR
  VAR
    word_to_shift : INT;
  END_VAR
  VAR_INPUT
    in_moveX : BOOL;
    in_MoveZ : BOOL;
  END_VAR
  VAR
    TimeIn : BOOL;
  END_VAR
  VAR_INPUT
    in_RightLim : BOOL;
    in_LeftLim : BOOL;
    isLid : BOOL;
  END_VAR
  VAR
    TimePt : TIME;
    timerOn : TON;
    TimeQ : BOOL;
  END_VAR
  VAR_OUTPUT
    out_Lift : BOOL;
    out_Left : BOOL;
    out_Right : BOOL;
    out_TargetPosition : INT;
  END_VAR
  VAR
    loading_conv_loaded : BOOL;
    stacker_busy : BOOL;
    left_conv_wait : BOOL;
    destination : INT;
    TimeEt : TIME;
  END_VAR


    IF in_Sensor = TRUE AND in_MidLim AND word_to_shift = 0 THEN
        word_to_shift := 1;
        TimePt := T#2000ms;
    END_IF;
    

timerOn(
     IN := TimeIn,
     PT := TimePt,
     Q => TimeQ,
     ET => TimeEt);


    IF word_to_shift = 1 THEN
        out_Left := TRUE;
        word_to_shift := 2;
    END_IF;
    



    IF in_LeftLim AND word_to_shift = 2 THEN
        out_Lift := 1;
        TimeIn := TRUE;
        word_to_shift := 4;
    END_IF;
    

    IF word_to_shift = 4 AND TimeQ THEN
        out_Left := FALSE;
        TimeIn := FALSE;
        word_to_shift := 8;
    END_IF;
 
 
    IF in_MidLim AND word_to_shift = 8 THEN
        IF (destination MOD 10 = 0) and isLid = TRUE and destination <> 0 THEN
          destination := destination + 20;
          END_IF;
        IF isLid THEN
          out_TargetPosition := destination + 9;
          ELSE 
          destination := destination + 1;
          out_TargetPosition := destination;
          END_IF;
        word_to_shift := 16;
        TimeIn := TRUE;
    END_IF;
    

    IF NOT in_moveX AND NOT in_MoveZ AND TimeQ AND word_to_shift = 16 THEN
        out_Right := true;
       TimeIn := FALSE;
        word_to_shift := 32;
    END_IF;
    

    IF in_RightLim AND word_to_shift = 32 THEN
        out_Lift := FALSE;
        TimeIn := TRUE;
        word_to_shift := 64;
    END_IF;


    IF word_to_shift = 64 AND TimeQ THEN
        out_Right := FALSE;
       TimeIn := FALSE;
        word_to_shift := 128;
    END_IF;



    IF in_MidLim AND word_to_shift = 128 THEN
        out_TargetPosition := 55;
        word_to_shift := 256;
       TimeIn := TRUE;
    END_IF;


    IF NOT in_moveX AND NOT in_MoveZ AND word_to_shift = 256 AND TimeQ THEN
        stacker_busy := FALSE;
        loading_conv_loaded := FALSE;
        TimeIn := FALSE;
        left_conv_wait := FALSE;
        word_to_shift := 0;
    END_IF;
    
END_FUNCTION_BLOCK

FUNCTION_BLOCK lids
  VAR_OUTPUT
    lidtype : BOOL;
  END_VAR
  VAR_INPUT
    signal : BOOL;
  END_VAR

  IF (signal=true) THEN
    lidtype := not lidtype;
    END_IF;
    
END_FUNCTION_BLOCK

PROGRAM program0
  VAR
    input_conveyor AT %QX100.0 : BOOL;
    start_button AT %IX100.0 : BOOL;
    stop_button AT %IX100.1 : BOOL;
    machining_exit_sensor AT %IX100.2 : BOOL;
    crane_isMovingX AT %IX100.3 : BOOL;
    crane_isMovingZ AT %IX100.4 : BOOL;
    crane_isLeftLim AT %IX100.5 : BOOL;
    crane_isMidLim AT %IX100.6 : BOOL;
    crane_isRightLim AT %IX100.7 : BOOL;
    crane_sensor AT %IX101.0 : BOOL;
    door_sensor AT %IX101.1 : BOOL;
    emergency_stop AT %IX101.2 : BOOL;
    machining_start AT %QX100.1 : BOOL;
    machining_produceLids AT %QX100.2 : BOOL;
    transfer_conveyor AT %QX100.3 : BOOL;
    exit_conveyor AT %QX100.4 : BOOL;
    emitter_exit AT %QX100.5 : BOOL;
    crane_lift AT %QX100.6 : BOOL;
    crane_left AT %QX100.7 : BOOL;
    crane_right AT %QX101.0 : BOOL;
    crane_loading_conveyor AT %QX101.1 : BOOL;
    start_light AT %QX101.2 : BOOL;
    stop_light AT %QX101.3 : BOOL;
    warning_light AT %QX101.4 : BOOL;
    siren AT %QX101.5 : BOOL;
    machining_stop AT %QX101.6 : BOOL;
    machining_reset AT %QX101.7 : BOOL;
    machining_isBusy AT %IW100 : INT;
    potentiometer AT %IW101 : INT;
    crane_position AT %QW100 : INT;
    input_conveyor_alg AT %QW101 : INT;
    current_base AT %QW102 : INT;
    current_lid AT %QW103 : INT;
    total_base AT %QW104 : INT;
    total_lid AT %QW105 : INT;
  END_VAR
  VAR
    SR0 : SR;
    CTU0 : CTU;
    lids0 : lids;
    SR1 : SR;
    CTU1 : CTU;
    crane0 : crane;
    TON0 : TON;
    SR2 : SR;
    TP0 : TP;
    CTU2 : CTU;
    CTU3 : CTU;
    MOVE65_ENO : BOOL;
    MOVE65_OUT : INT;
    MOVE18_ENO : BOOL;
    MOVE18_OUT : INT;
    INT_TO_BOOL23_OUT : BOOL;
    R_TRIG1 : R_TRIG;
    EQ15_OUT : BOOL;
    AND62_OUT : BOOL;
    AND19_OUT : BOOL;
    F_TRIG1 : F_TRIG;
    INT_TO_BOOL14_OUT : BOOL;
    R_TRIG2 : R_TRIG;
    EQ4_OUT : BOOL;
    ADD105_OUT : INT;
    MOVE82_ENO : BOOL;
    MOVE82_OUT : INT;
    ADD103_OUT : INT;
    MOVE68_ENO : BOOL;
    MOVE68_OUT : INT;
    MOVE50_OUT : INT;
    F_TRIG2 : F_TRIG;
    R_TRIG3 : R_TRIG;
    MOVE100_OUT : INT;
    R_TRIG4 : R_TRIG;
    R_TRIG5 : R_TRIG;
    MOVE93_OUT : INT;
  END_VAR

  SR0(S1 := start_button, R := NOT(stop_button) OR NOT(emergency_stop));
  machining_start := door_sensor AND SR0.Q1;
  exit_conveyor := door_sensor AND SR0.Q1;
  crane_loading_conveyor := NOT(crane_sensor) AND door_sensor AND SR0.Q1;
  MOVE65_OUT := MOVE(EN := door_sensor AND SR0.Q1, IN := potentiometer, ENO => MOVE65_ENO);
  IF MOVE65_ENO THEN
      input_conveyor_alg := MOVE65_OUT;
  END_IF;
  MOVE18_OUT := MOVE(EN := NOT(exit_conveyor), IN := 0, ENO => MOVE18_ENO);
  IF MOVE18_ENO THEN
      input_conveyor_alg := MOVE18_OUT;
  END_IF;
  INT_TO_BOOL23_OUT := INT_TO_BOOL(machining_isBusy);
  R_TRIG1(CLK := INT_TO_BOOL23_OUT);
  EQ15_OUT := EQ(5, CTU0.CV);
  AND62_OUT := AND(EQ15_OUT, transfer_conveyor);
  CTU0(CU := R_TRIG1.Q, R := AND62_OUT OR NOT(stop_button), PV := 5);
  AND19_OUT := AND(door_sensor AND SR0.Q1, CTU0.Q);
  TON0(IN := AND19_OUT, PT := T#5000ms);
  F_TRIG1(CLK := machining_exit_sensor);
  SR1(S1 := TON0.Q, R := F_TRIG1.Q);
  transfer_conveyor := SR1.Q1;
  emitter_exit := NOT(machining_exit_sensor);
  INT_TO_BOOL14_OUT := INT_TO_BOOL(machining_isBusy);
  R_TRIG2(CLK := INT_TO_BOOL14_OUT);
  EQ4_OUT := EQ(5, CTU1.CV);
  CTU1(CU := R_TRIG2.Q, R := EQ4_OUT OR NOT(stop_button), PV := 5);
  lids0(signal := CTU1.Q);
  machining_produceLids := lids0.lidtype;
  ADD105_OUT := ADD(CTU1.CV, 1);
  MOVE82_OUT := MOVE(EN := NOT(machining_produceLids), IN := ADD105_OUT, ENO => MOVE82_ENO);
  IF MOVE82_ENO THEN
      current_base := MOVE82_OUT;
  END_IF;
  ADD103_OUT := ADD(CTU1.CV, 1);
  MOVE68_OUT := MOVE(EN := machining_produceLids, IN := ADD103_OUT, ENO => MOVE68_ENO);
  IF MOVE68_ENO THEN
      current_lid := MOVE68_OUT;
  END_IF;
  crane0(in_Sensor := crane_sensor, in_MidLim := crane_isMidLim, in_moveX := crane_isMovingX, in_MoveZ := crane_isMovingZ, in_RightLim := crane_isRightLim, in_LeftLim := crane_isLeftLim, isLid := NOT(machining_produceLids));
  crane_lift := crane0.out_Lift;
  crane_left := crane0.out_Left;
  crane_right := crane0.out_Right;
  MOVE50_OUT := MOVE(crane0.out_TargetPosition);
  crane_position := MOVE50_OUT;
  warning_light := NOT(door_sensor) OR NOT(emergency_stop);
  TP0(IN := NOT(door_sensor) OR NOT(emergency_stop), PT := T#2000ms);
  siren := TP0.Q;
  SR2(S1 := start_button, R := NOT(stop_button) OR NOT(emergency_stop));
  start_light := SR2.Q1;
  stop_light := NOT(SR2.Q1);
  F_TRIG2(CLK := machining_produceLids);
  R_TRIG3(CLK := F_TRIG2.Q);
  CTU3(CU := R_TRIG3.Q, R := NOT(stop_button), PV := 256);
  MOVE100_OUT := MOVE(CTU3.CV);
  total_lid := MOVE100_OUT;
  R_TRIG4(CLK := machining_produceLids);
  R_TRIG5(CLK := R_TRIG4.Q);
  CTU2(CU := R_TRIG5.Q, R := NOT(stop_button), PV := 256);
  MOVE93_OUT := MOVE(CTU2.CV);
  total_base := MOVE93_OUT;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : program0;
  END_RESOURCE
END_CONFIGURATION
