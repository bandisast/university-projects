TYPE
  LOGLEVEL : (CRITICAL, WARNING, INFO, DEBUG) := INFO;
END_TYPE

FUNCTION_BLOCK LOGGER
  VAR_INPUT
    TRIG : BOOL;
    MSG : STRING;
    LEVEL : LOGLEVEL := INFO;
  END_VAR
  VAR
    TRIG0 : BOOL;
  END_VAR

  IF TRIG AND NOT TRIG0 THEN
  {{
   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  }}
  END_IF;
  TRIG0:=TRIG;
END_FUNCTION_BLOCK



FUNCTION_BLOCK python_eval
  VAR_INPUT
    TRIG : BOOL;
    CODE : STRING;
  END_VAR
  VAR_OUTPUT
    ACK : BOOL;
    RESULT : STRING;
  END_VAR
  VAR
    STATE : DWORD;
    BUFFER : STRING;
    PREBUFFER : STRING;
    TRIGM1 : BOOL;
    TRIGGED : BOOL;
  END_VAR

  {extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(0, data__);}
END_FUNCTION_BLOCK

FUNCTION_BLOCK python_poll
  VAR_INPUT
    TRIG : BOOL;
    CODE : STRING;
  END_VAR
  VAR_OUTPUT
    ACK : BOOL;
    RESULT : STRING;
  END_VAR
  VAR
    STATE : DWORD;
    BUFFER : STRING;
    PREBUFFER : STRING;
    TRIGM1 : BOOL;
    TRIGGED : BOOL;
  END_VAR

  {extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(1,(PYTHON_EVAL*)(void*)data__);}
END_FUNCTION_BLOCK

FUNCTION_BLOCK python_gear
  VAR_INPUT
    N : UINT;
    TRIG : BOOL;
    CODE : STRING;
  END_VAR
  VAR_OUTPUT
    ACK : BOOL;
    RESULT : STRING;
  END_VAR
  VAR
    py_eval : python_eval;
    COUNTER : UINT;
    ADD10_OUT : UINT;
    EQ13_OUT : BOOL;
    SEL15_OUT : UINT;
    AND7_OUT : BOOL;
  END_VAR

  ADD10_OUT := ADD(COUNTER, 1);
  EQ13_OUT := EQ(N, ADD10_OUT);
  SEL15_OUT := SEL(EQ13_OUT, ADD10_OUT, 0);
  COUNTER := SEL15_OUT;
  AND7_OUT := AND(EQ13_OUT, TRIG);
  py_eval(TRIG := AND7_OUT, CODE := CODE);
  ACK := py_eval.ACK;
  RESULT := py_eval.RESULT;
END_FUNCTION_BLOCK


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
    reset : BOOL;
  END_VAR

  IF reset = 1 THEN
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
    START : BOOL;
    STOP : BOOL;
    ENTRY_CONVEYOR : BOOL;
    LEFT_CONVEYOR : BOOL;
    RIGHT_CONVEYOR : BOOL;
    FRONT_CONVEYOR : BOOL;
    SEND_FORWARD : BOOL;
  END_VAR
  VAR
    SR0 : SR;
    CTU0 : CTU;
  END_VAR
  VAR
    ENTRY_SENSOR : BOOL;
    EXIT_SENSOR : BOOL;
  END_VAR
  VAR
    colourblock0 : colourblock;
  END_VAR
  VAR
    blue_camera : BOOL;
    green_camera : BOOL;
    metal_camera : BOOL;
  END_VAR
  VAR
    colour : ARRAY [0..5] OF INT;
  END_VAR
  VAR
    ROLLER_LEFT : BOOL;
    ROLLER_RIGHT : BOOL;
  END_VAR
  VAR
    CTU1 : CTU;
    TOF0 : TOF;
    TOF1 : TOF;
  END_VAR
  VAR
    START_LIGHT : BOOL;
    STOP_LIGHT : BOOL;
    DOOR_SIREN : BOOL;
    DOOR_LIGHT : BOOL;
    RESET_LIGHT : BOOL;
    DOOR_SENSOR : BOOL;
    RESET_BUTTON : BOOL;
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
  CTU0(CU := R_TRIG1.Q, R := EQ17_OUT OR RESET_BUTTON, PV := 6);
  F_TRIG2(CLK := EXIT_SENSOR);
  R_TRIG2(CLK := F_TRIG2.Q);
  EQ5_OUT := EQ(CTU1.CV, 6);
  CTU1(CU := R_TRIG2.Q, R := EQ5_OUT OR RESET_BUTTON, PV := 6);
  colourblock0(counterIn := CTU0.CV, counterOut := CTU1.CV, camera_blue := blue_camera, camera_green := green_camera, camera_metal := metal_camera, entry_sensor := ENTRY_SENSOR, exit_sensor := EXIT_SENSOR, reset := NOT(RESET_BUTTON));
  TOF1(IN := colourblock0.go_left, PT := T#250ms);
  ROLLER_LEFT := TOF1.Q;
  TOF0(IN := colourblock0.go_right, PT := T#250ms);
  ROLLER_RIGHT := TOF0.Q;
  DOOR_LIGHT := NOT(DOOR_SENSOR);
  TP0(IN := NOT(DOOR_SENSOR), PT := T#2000ms);
  DOOR_SIREN := TP0.Q;
  RESET_LIGHT := RESET_BUTTON;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : main;
  END_RESOURCE
END_CONFIGURATION
