void LOGGER_init__(LOGGER *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MSG,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->LEVEL,LOGLEVEL__INFO,retain)
  __INIT_VAR(data__->TRIG0,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void LOGGER_body__(LOGGER *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->TRIG,) && !(__GET_VAR(data__->TRIG0,)))) {
    #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
    #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)

   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  
    #undef GetFbVar
    #undef SetFbVar
;
  };
  __SET_VAR(data__->,TRIG0,,__GET_VAR(data__->TRIG,));

  goto __end;

__end:
  return;
} // LOGGER_body__() 





void PYTHON_EVAL_init__(PYTHON_EVAL *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CODE,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->ACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESULT,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->STATE,0,retain)
  __INIT_VAR(data__->BUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->PREBUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->TRIGM1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TRIGGED,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PYTHON_EVAL_body__(PYTHON_EVAL *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __IL_DEFVAR_T __IL_DEFVAR;
  __IL_DEFVAR_T __IL_DEFVAR_BACK;
  #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
  #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)
extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(0, data__);
  #undef GetFbVar
  #undef SetFbVar
;

  goto __end;

__end:
  return;
} // PYTHON_EVAL_body__() 





void PYTHON_POLL_init__(PYTHON_POLL *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CODE,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->ACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESULT,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->STATE,0,retain)
  __INIT_VAR(data__->BUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->PREBUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->TRIGM1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TRIGGED,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PYTHON_POLL_body__(PYTHON_POLL *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __IL_DEFVAR_T __IL_DEFVAR;
  __IL_DEFVAR_T __IL_DEFVAR_BACK;
  #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
  #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)
extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(1,(PYTHON_EVAL*)(void*)data__);
  #undef GetFbVar
  #undef SetFbVar
;

  goto __end;

__end:
  return;
} // PYTHON_POLL_body__() 





void PYTHON_GEAR_init__(PYTHON_GEAR *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->N,0,retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CODE,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->ACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESULT,__STRING_LITERAL(0,""),retain)
  PYTHON_EVAL_init__(&data__->PY_EVAL,retain);
  __INIT_VAR(data__->COUNTER,0,retain)
  __INIT_VAR(data__->ADD10_OUT,0,retain)
  __INIT_VAR(data__->EQ13_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SEL15_OUT,0,retain)
  __INIT_VAR(data__->AND7_OUT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PYTHON_GEAR_body__(PYTHON_GEAR *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,ADD10_OUT,,ADD__UINT__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (UINT)__GET_VAR(data__->COUNTER,),
    (UINT)1));
  __SET_VAR(data__->,EQ13_OUT,,EQ__BOOL__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (UINT)__GET_VAR(data__->N,),
    (UINT)__GET_VAR(data__->ADD10_OUT,)));
  __SET_VAR(data__->,SEL15_OUT,,SEL__UINT__BOOL__UINT__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__GET_VAR(data__->EQ13_OUT,),
    (UINT)__GET_VAR(data__->ADD10_OUT,),
    (UINT)0));
  __SET_VAR(data__->,COUNTER,,__GET_VAR(data__->SEL15_OUT,));
  __SET_VAR(data__->,AND7_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->EQ13_OUT,),
    (BOOL)__GET_VAR(data__->TRIG,)));
  __SET_VAR(data__->PY_EVAL.,TRIG,,__GET_VAR(data__->AND7_OUT,));
  __SET_VAR(data__->PY_EVAL.,CODE,,__GET_VAR(data__->CODE,));
  PYTHON_EVAL_body__(&data__->PY_EVAL);
  __SET_VAR(data__->,ACK,,__GET_VAR(data__->PY_EVAL.ACK,));
  __SET_VAR(data__->,RESULT,,__GET_VAR(data__->PY_EVAL.RESULT,));

  goto __end;

__end:
  return;
} // PYTHON_GEAR_body__() 





void COLOURBLOCK_init__(COLOURBLOCK *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->COUNTERIN,0,retain)
  __INIT_VAR(data__->COUNTEROUT,0,retain)
  __INIT_VAR(data__->CAMERA_BLUE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CAMERA_GREEN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CAMERA_METAL,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ENTRY_SENSOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->EXIT_SENSOR,__BOOL_LITERAL(FALSE),retain)
  {
    static const __ARRAY_OF_INT_6 temp = {{0,0,0,0,0,0}};
    __SET_VAR(data__->,TEMP,,temp);
  }
  __INIT_VAR(data__->GO_LEFT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->GO_RIGHT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESET,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void COLOURBLOCK_body__(COLOURBLOCK *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->RESET,) == 1)) {
    __SET_VAR(data__->,TEMP,.table[(0) - (0)],0);
    __SET_VAR(data__->,TEMP,.table[(1) - (0)],0);
    __SET_VAR(data__->,TEMP,.table[(2) - (0)],0);
    __SET_VAR(data__->,TEMP,.table[(3) - (0)],0);
    __SET_VAR(data__->,TEMP,.table[(4) - (0)],0);
    __SET_VAR(data__->,TEMP,.table[(5) - (0)],0);
    __SET_VAR(data__->,GO_LEFT,,0);
    __SET_VAR(data__->,GO_RIGHT,,0);
  };
  if ((__GET_VAR(data__->ENTRY_SENSOR,) == 1)) {
    if ((__GET_VAR(data__->CAMERA_BLUE,) == __BOOL_LITERAL(TRUE))) {
      __SET_VAR(data__->,TEMP,.table[(__GET_VAR(data__->COUNTERIN,)) - (0)],1);
    } else if ((__GET_VAR(data__->CAMERA_GREEN,) == __BOOL_LITERAL(TRUE))) {
      __SET_VAR(data__->,TEMP,.table[(__GET_VAR(data__->COUNTERIN,)) - (0)],2);
    } else if ((__GET_VAR(data__->CAMERA_METAL,) == __BOOL_LITERAL(TRUE))) {
      __SET_VAR(data__->,TEMP,.table[(__GET_VAR(data__->COUNTERIN,)) - (0)],3);
    };
  };
  if ((__GET_VAR(data__->EXIT_SENSOR,) == 1)) {
    if ((__GET_VAR(data__->TEMP,.table[(__GET_VAR(data__->COUNTEROUT,)) - (0)]) == 1)) {
      __SET_VAR(data__->,GO_LEFT,,1);
      __SET_VAR(data__->,GO_RIGHT,,0);
    } else if ((__GET_VAR(data__->TEMP,.table[(__GET_VAR(data__->COUNTEROUT,)) - (0)]) == 2)) {
      __SET_VAR(data__->,GO_RIGHT,,1);
      __SET_VAR(data__->,GO_LEFT,,0);
    } else if ((__GET_VAR(data__->TEMP,.table[(__GET_VAR(data__->COUNTEROUT,)) - (0)]) == 3)) {
      __SET_VAR(data__->,GO_RIGHT,,0);
      __SET_VAR(data__->,GO_LEFT,,0);
    };
  };

  goto __end;

__end:
  return;
} // COLOURBLOCK_body__() 





void MAIN_init__(MAIN *data__, BOOL retain) {
  __INIT_VAR(data__->START,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STOP,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ENTRY_CONVEYOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LEFT_CONVEYOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RIGHT_CONVEYOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FRONT_CONVEYOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SEND_FORWARD,__BOOL_LITERAL(FALSE),retain)
  SR_init__(&data__->SR0,retain);
  CTU_init__(&data__->CTU0,retain);
  __INIT_VAR(data__->ENTRY_SENSOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->EXIT_SENSOR,__BOOL_LITERAL(FALSE),retain)
  COLOURBLOCK_init__(&data__->COLOURBLOCK0,retain);
  __INIT_VAR(data__->BLUE_CAMERA,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->GREEN_CAMERA,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->METAL_CAMERA,__BOOL_LITERAL(FALSE),retain)
  {
    static const __ARRAY_OF_INT_6 temp = {{0,0,0,0,0,0}};
    __SET_VAR(data__->,COLOUR,,temp);
  }
  __INIT_VAR(data__->ROLLER_LEFT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ROLLER_RIGHT,__BOOL_LITERAL(FALSE),retain)
  CTU_init__(&data__->CTU1,retain);
  TOF_init__(&data__->TOF0,retain);
  TOF_init__(&data__->TOF1,retain);
  __INIT_VAR(data__->START_LIGHT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STOP_LIGHT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->DOOR_SIREN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->DOOR_LIGHT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESET_LIGHT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->DOOR_SENSOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESET_BUTTON,__BOOL_LITERAL(FALSE),retain)
  TP_init__(&data__->TP0,retain);
  F_TRIG_init__(&data__->F_TRIG1,retain);
  R_TRIG_init__(&data__->R_TRIG1,retain);
  __INIT_VAR(data__->EQ17_OUT,__BOOL_LITERAL(FALSE),retain)
  F_TRIG_init__(&data__->F_TRIG2,retain);
  R_TRIG_init__(&data__->R_TRIG2,retain);
  __INIT_VAR(data__->EQ5_OUT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void MAIN_body__(MAIN *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->SR0.,S1,,__GET_VAR(data__->START,));
  __SET_VAR(data__->SR0.,R,,!(__GET_VAR(data__->STOP,)));
  SR_body__(&data__->SR0);
  __SET_VAR(data__->,ENTRY_CONVEYOR,,(__GET_VAR(data__->DOOR_SENSOR,) && __GET_VAR(data__->SR0.Q1,)));
  __SET_VAR(data__->,FRONT_CONVEYOR,,(__GET_VAR(data__->DOOR_SENSOR,) && __GET_VAR(data__->SR0.Q1,)));
  __SET_VAR(data__->,LEFT_CONVEYOR,,(__GET_VAR(data__->DOOR_SENSOR,) && __GET_VAR(data__->SR0.Q1,)));
  __SET_VAR(data__->,RIGHT_CONVEYOR,,(__GET_VAR(data__->DOOR_SENSOR,) && __GET_VAR(data__->SR0.Q1,)));
  __SET_VAR(data__->,SEND_FORWARD,,(__GET_VAR(data__->DOOR_SENSOR,) && __GET_VAR(data__->SR0.Q1,)));
  __SET_VAR(data__->,START_LIGHT,,__GET_VAR(data__->SR0.Q1,));
  __SET_VAR(data__->,STOP_LIGHT,,!(__GET_VAR(data__->SR0.Q1,)));
  __SET_VAR(data__->F_TRIG1.,CLK,,__GET_VAR(data__->ENTRY_SENSOR,));
  F_TRIG_body__(&data__->F_TRIG1);
  __SET_VAR(data__->R_TRIG1.,CLK,,__GET_VAR(data__->F_TRIG1.Q,));
  R_TRIG_body__(&data__->R_TRIG1);
  __SET_VAR(data__->,EQ17_OUT,,EQ__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->CTU0.CV,),
    (INT)6));
  __SET_VAR(data__->CTU0.,CU,,__GET_VAR(data__->R_TRIG1.Q,));
  __SET_VAR(data__->CTU0.,R,,(__GET_VAR(data__->EQ17_OUT,) || __GET_VAR(data__->RESET_BUTTON,)));
  __SET_VAR(data__->CTU0.,PV,,6);
  CTU_body__(&data__->CTU0);
  __SET_VAR(data__->F_TRIG2.,CLK,,__GET_VAR(data__->EXIT_SENSOR,));
  F_TRIG_body__(&data__->F_TRIG2);
  __SET_VAR(data__->R_TRIG2.,CLK,,__GET_VAR(data__->F_TRIG2.Q,));
  R_TRIG_body__(&data__->R_TRIG2);
  __SET_VAR(data__->,EQ5_OUT,,EQ__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->CTU1.CV,),
    (INT)6));
  __SET_VAR(data__->CTU1.,CU,,__GET_VAR(data__->R_TRIG2.Q,));
  __SET_VAR(data__->CTU1.,R,,(__GET_VAR(data__->EQ5_OUT,) || __GET_VAR(data__->RESET_BUTTON,)));
  __SET_VAR(data__->CTU1.,PV,,6);
  CTU_body__(&data__->CTU1);
  __SET_VAR(data__->COLOURBLOCK0.,COUNTERIN,,__GET_VAR(data__->CTU0.CV,));
  __SET_VAR(data__->COLOURBLOCK0.,COUNTEROUT,,__GET_VAR(data__->CTU1.CV,));
  __SET_VAR(data__->COLOURBLOCK0.,CAMERA_BLUE,,__GET_VAR(data__->BLUE_CAMERA,));
  __SET_VAR(data__->COLOURBLOCK0.,CAMERA_GREEN,,__GET_VAR(data__->GREEN_CAMERA,));
  __SET_VAR(data__->COLOURBLOCK0.,CAMERA_METAL,,__GET_VAR(data__->METAL_CAMERA,));
  __SET_VAR(data__->COLOURBLOCK0.,ENTRY_SENSOR,,__GET_VAR(data__->ENTRY_SENSOR,));
  __SET_VAR(data__->COLOURBLOCK0.,EXIT_SENSOR,,__GET_VAR(data__->EXIT_SENSOR,));
  __SET_VAR(data__->COLOURBLOCK0.,RESET,,!(__GET_VAR(data__->RESET_BUTTON,)));
  COLOURBLOCK_body__(&data__->COLOURBLOCK0);
  __SET_VAR(data__->TOF1.,IN,,__GET_VAR(data__->COLOURBLOCK0.GO_LEFT,));
  __SET_VAR(data__->TOF1.,PT,,__time_to_timespec(1, 250, 0, 0, 0, 0));
  TOF_body__(&data__->TOF1);
  __SET_VAR(data__->,ROLLER_LEFT,,__GET_VAR(data__->TOF1.Q,));
  __SET_VAR(data__->TOF0.,IN,,__GET_VAR(data__->COLOURBLOCK0.GO_RIGHT,));
  __SET_VAR(data__->TOF0.,PT,,__time_to_timespec(1, 250, 0, 0, 0, 0));
  TOF_body__(&data__->TOF0);
  __SET_VAR(data__->,ROLLER_RIGHT,,__GET_VAR(data__->TOF0.Q,));
  __SET_VAR(data__->,DOOR_LIGHT,,!(__GET_VAR(data__->DOOR_SENSOR,)));
  __SET_VAR(data__->TP0.,IN,,!(__GET_VAR(data__->DOOR_SENSOR,)));
  __SET_VAR(data__->TP0.,PT,,__time_to_timespec(1, 2000, 0, 0, 0, 0));
  TP_body__(&data__->TP0);
  __SET_VAR(data__->,DOOR_SIREN,,__GET_VAR(data__->TP0.Q,));
  __SET_VAR(data__->,RESET_LIGHT,,__GET_VAR(data__->RESET_BUTTON,));

  goto __end;

__end:
  return;
} // MAIN_body__() 





