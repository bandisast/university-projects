TYPE
  colourtype : STRUCT
    colourValue : ARRAY [0..5] OF INT;
  END_STRUCT;
END_TYPE

FUNCTION_BLOCK colourblock
  VAR_INPUT
    counterIn : INT;
    counterOut : INT;
    camera_blue : BOOL;
    camera_green : BOOL;
    camera_metal : BOOL;
    entry_sensor : BOOL;
    exit_sensor : BOOL;
  END_VAR
  VAR
    temp : ARRAY [0..5] OF INT;
  END_VAR
  VAR_OUTPUT
    go_left : BOOL;
    go_right : BOOL;
  END_VAR
  VAR_INPUT
    stop : BOOL;
  END_VAR

  IF stop = 1 THEN
    temp[0]:=0;
    temp[1]:=0;
    temp[2]:=0;
    temp[3]:=0;
    temp[4]:=0;
    temp[5]:=0;
    go_left:=0;
    go_right:=0;
  END_IF;

  IF entry_sensor = 1 THEN
    IF camera_blue=TRUE THEN
      temp[counterIn] := 1;
    ELSIF camera_green=TRUE THEN
      temp[counterIn] := 2;
    ELSIF camera_metal = TRUE THEN
      temp[counterIn] := 3;
    END_IF;
  END_IF;

  IF exit_sensor = 1 THEN
    IF temp[counterOut] = 1 THEN
      go_left := 1;
      go_right := 0;
    ELSIF temp[counterOut] = 2 THEN
      go_right := 1;
      go_left := 0;
    ELSIF temp[counterOut] = 3 THEN
      go_right := 0;
      go_left := 0;
    END_IF;
  END_IF;    
END_FUNCTION_BLOCK

PROGRAM main
  VAR
    START AT %IX100.0 : BOOL;
    STOP AT %IX100.1 : BOOL;
    ENTRY_CONVEYOR AT %QX100.0 : BOOL;
    LEFT_CONVEYOR AT %QX100.1 : BOOL;
    RIGHT_CONVEYOR AT %QX100.2 : BOOL;
    FRONT_CONVEYOR AT %QX100.3 : BOOL;
    SEND_FORWARD AT %QX100.4 : BOOL;
  END_VAR
  VAR
    SR0 : SR;
    CTU0 : CTU;
  END_VAR
  VAR
    ENTRY_SENSOR AT %IX100.5 : BOOL;
    EXIT_SENSOR AT %IX100.6 : BOOL;
  END_VAR
  VAR
    colourblock0 : colourblock;
  END_VAR
  VAR
    blue_camera AT %IX100.2 : BOOL;
    green_camera AT %IX100.3 : BOOL;
    metal_camera AT %IX100.4 : BOOL;
  END_VAR
  VAR
    colour : ARRAY [0..5] OF INT;
  END_VAR
  VAR
    ROLLER_LEFT AT %QX100.5 : BOOL;
    ROLLER_RIGHT AT %QX100.6 : BOOL;
  END_VAR
  VAR
    CTU1 : CTU;
    TOF0 : TOF;
    TOF1 : TOF;
  END_VAR
  VAR
    START_LIGHT AT %QX100.7 : BOOL;
    STOP_LIGHT AT %QX101.0 : BOOL;
    DOOR_SIREN AT %QX101.1 : BOOL;
    DOOR_LIGHT AT %QX101.2 : BOOL;
    DOOR_SENSOR AT %IX100.7 : BOOL;
  END_VAR
  VAR
    TP0 : TP;
    F_TRIG1 : F_TRIG;
    R_TRIG1 : R_TRIG;
    EQ17_OUT : BOOL;
    F_TRIG2 : F_TRIG;
    R_TRIG2 : R_TRIG;
    EQ5_OUT : BOOL;
  END_VAR

  SR0(S1 := START, R := NOT(STOP));
  ENTRY_CONVEYOR := DOOR_SENSOR AND SR0.Q1;
  FRONT_CONVEYOR := DOOR_SENSOR AND SR0.Q1;
  LEFT_CONVEYOR := DOOR_SENSOR AND SR0.Q1;
  RIGHT_CONVEYOR := DOOR_SENSOR AND SR0.Q1;
  SEND_FORWARD := DOOR_SENSOR AND SR0.Q1;
  START_LIGHT := SR0.Q1;
  STOP_LIGHT := NOT(SR0.Q1);
  F_TRIG1(CLK := ENTRY_SENSOR);
  R_TRIG1(CLK := F_TRIG1.Q);
  EQ17_OUT := EQ(CTU0.CV, 6);
  CTU0(CU := R_TRIG1.Q, R := EQ17_OUT OR NOT(STOP), PV := 6);
  F_TRIG2(CLK := EXIT_SENSOR);
  R_TRIG2(CLK := F_TRIG2.Q);
  EQ5_OUT := EQ(CTU1.CV, 6);
  CTU1(CU := R_TRIG2.Q, R := EQ5_OUT OR NOT(STOP), PV := 6);
  colourblock0(counterIn := CTU0.CV, counterOut := CTU1.CV, camera_blue := blue_camera, camera_green := green_camera, camera_metal := metal_camera, entry_sensor := ENTRY_SENSOR, exit_sensor := EXIT_SENSOR, stop := NOT(STOP));
  TOF1(IN := colourblock0.go_left, PT := T#230ms);
  ROLLER_LEFT := TOF1.Q;
  TOF0(IN := colourblock0.go_right, PT := T#230ms);
  ROLLER_RIGHT := TOF0.Q;
  DOOR_LIGHT := NOT(DOOR_SENSOR);
  TP0(IN := NOT(DOOR_SENSOR), PT := T#2000ms);
  DOOR_SIREN := TP0.Q;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : main;
  END_RESOURCE
END_CONFIGURATION
