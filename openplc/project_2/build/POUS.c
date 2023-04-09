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





void CRANE_init__(CRANE *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN_SENSOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->IN_MIDLIM,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->WORD_TO_SHIFT,0,retain)
  __INIT_VAR(data__->IN_MOVEX,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->IN_MOVEZ,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TIMEIN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->IN_RIGHTLIM,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->IN_LEFTLIM,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ISLID,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TIMEPT,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  TON_init__(&data__->TIMERON,retain);
  __INIT_VAR(data__->TIMEQ,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->OUT_LIFT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->OUT_LEFT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->OUT_RIGHT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->OUT_TARGETPOSITION,0,retain)
  __INIT_VAR(data__->LOADING_CONV_LOADED,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STACKER_BUSY,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LEFT_CONV_WAIT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->DESTINATION,0,retain)
  __INIT_VAR(data__->TIMEET,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
}

// Code part
void CRANE_body__(CRANE *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((((__GET_VAR(data__->IN_SENSOR,) == __BOOL_LITERAL(TRUE)) && __GET_VAR(data__->IN_MIDLIM,)) && (__GET_VAR(data__->WORD_TO_SHIFT,) == 0))) {
    __SET_VAR(data__->,WORD_TO_SHIFT,,1);
    __SET_VAR(data__->,TIMEPT,,__time_to_timespec(1, 2000, 0, 0, 0, 0));
  };
  __SET_VAR(data__->TIMERON.,IN,,__GET_VAR(data__->TIMEIN,));
  __SET_VAR(data__->TIMERON.,PT,,__GET_VAR(data__->TIMEPT,));
  TON_body__(&data__->TIMERON);
  __SET_VAR(data__->,TIMEQ,,__GET_VAR(data__->TIMERON.Q));
  __SET_VAR(data__->,TIMEET,,__GET_VAR(data__->TIMERON.ET));
  if ((__GET_VAR(data__->WORD_TO_SHIFT,) == 1)) {
    __SET_VAR(data__->,OUT_LEFT,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,WORD_TO_SHIFT,,2);
  };
  if ((__GET_VAR(data__->IN_LEFTLIM,) && (__GET_VAR(data__->WORD_TO_SHIFT,) == 2))) {
    __SET_VAR(data__->,OUT_LIFT,,1);
    __SET_VAR(data__->,TIMEIN,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,WORD_TO_SHIFT,,4);
  };
  if (((__GET_VAR(data__->WORD_TO_SHIFT,) == 4) && __GET_VAR(data__->TIMEQ,))) {
    __SET_VAR(data__->,OUT_LEFT,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,TIMEIN,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,WORD_TO_SHIFT,,8);
  };
  if ((__GET_VAR(data__->IN_MIDLIM,) && (__GET_VAR(data__->WORD_TO_SHIFT,) == 8))) {
    if ((((((10 == 0)?0:(__GET_VAR(data__->DESTINATION,) % 10)) == 0) && (__GET_VAR(data__->ISLID,) == __BOOL_LITERAL(TRUE))) && (__GET_VAR(data__->DESTINATION,) != 0))) {
      __SET_VAR(data__->,DESTINATION,,(__GET_VAR(data__->DESTINATION,) + 20));
    };
    if (__GET_VAR(data__->ISLID,)) {
      __SET_VAR(data__->,OUT_TARGETPOSITION,,(__GET_VAR(data__->DESTINATION,) + 9));
    } else {
      __SET_VAR(data__->,DESTINATION,,(__GET_VAR(data__->DESTINATION,) + 1));
      __SET_VAR(data__->,OUT_TARGETPOSITION,,__GET_VAR(data__->DESTINATION,));
    };
    __SET_VAR(data__->,WORD_TO_SHIFT,,16);
    __SET_VAR(data__->,TIMEIN,,__BOOL_LITERAL(TRUE));
  };
  if ((((!(__GET_VAR(data__->IN_MOVEX,)) && !(__GET_VAR(data__->IN_MOVEZ,))) && __GET_VAR(data__->TIMEQ,)) && (__GET_VAR(data__->WORD_TO_SHIFT,) == 16))) {
    __SET_VAR(data__->,OUT_RIGHT,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,TIMEIN,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,WORD_TO_SHIFT,,32);
  };
  if ((__GET_VAR(data__->IN_RIGHTLIM,) && (__GET_VAR(data__->WORD_TO_SHIFT,) == 32))) {
    __SET_VAR(data__->,OUT_LIFT,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,TIMEIN,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,WORD_TO_SHIFT,,64);
  };
  if (((__GET_VAR(data__->WORD_TO_SHIFT,) == 64) && __GET_VAR(data__->TIMEQ,))) {
    __SET_VAR(data__->,OUT_RIGHT,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,TIMEIN,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,WORD_TO_SHIFT,,128);
  };
  if ((__GET_VAR(data__->IN_MIDLIM,) && (__GET_VAR(data__->WORD_TO_SHIFT,) == 128))) {
    __SET_VAR(data__->,OUT_TARGETPOSITION,,55);
    __SET_VAR(data__->,WORD_TO_SHIFT,,256);
    __SET_VAR(data__->,TIMEIN,,__BOOL_LITERAL(TRUE));
  };
  if ((((!(__GET_VAR(data__->IN_MOVEX,)) && !(__GET_VAR(data__->IN_MOVEZ,))) && (__GET_VAR(data__->WORD_TO_SHIFT,) == 256)) && __GET_VAR(data__->TIMEQ,))) {
    __SET_VAR(data__->,STACKER_BUSY,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,LOADING_CONV_LOADED,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,TIMEIN,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,LEFT_CONV_WAIT,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,WORD_TO_SHIFT,,0);
  };

  goto __end;

__end:
  return;
} // CRANE_body__() 





void LIDS_init__(LIDS *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->LIDTYPE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SIGNAL,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void LIDS_body__(LIDS *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->SIGNAL,) == __BOOL_LITERAL(TRUE))) {
    __SET_VAR(data__->,LIDTYPE,,!(__GET_VAR(data__->LIDTYPE,)));
  };

  goto __end;

__end:
  return;
} // LIDS_body__() 





static inline INT __PROGRAM0_MOVE__INT__INT1(BOOL EN,
  INT IN,
  PROGRAM0 *data__)
{
  INT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->MOVE18_ENO,);
  __res = MOVE__INT__INT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->MOVE18_ENO,,__TMP_ENO);
  return __res;
}

static inline INT __PROGRAM0_MOVE__INT__INT2(BOOL EN,
  INT IN,
  PROGRAM0 *data__)
{
  INT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->MOVE65_ENO,);
  __res = MOVE__INT__INT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->MOVE65_ENO,,__TMP_ENO);
  return __res;
}

static inline INT __PROGRAM0_MOVE__INT__INT3(BOOL EN,
  INT IN,
  PROGRAM0 *data__)
{
  INT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->MOVE82_ENO,);
  __res = MOVE__INT__INT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->MOVE82_ENO,,__TMP_ENO);
  return __res;
}

static inline INT __PROGRAM0_MOVE__INT__INT4(BOOL EN,
  INT IN,
  PROGRAM0 *data__)
{
  INT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->MOVE68_ENO,);
  __res = MOVE__INT__INT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->MOVE68_ENO,,__TMP_ENO);
  return __res;
}

void PROGRAM0_init__(PROGRAM0 *data__, BOOL retain) {
  __INIT_VAR(data__->INPUT_CONVEYOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->START_BUTTON,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STOP_BUTTON,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MACHINING_EXIT_SENSOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CRANE_ISMOVINGX,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CRANE_ISMOVINGZ,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CRANE_ISLEFTLIM,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CRANE_ISMIDLIM,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CRANE_ISRIGHTLIM,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CRANE_SENSOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->DOOR_SENSOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->EMERGENCY_STOP,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MACHINING_START,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MACHINING_PRODUCELIDS,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TRANSFER_CONVEYOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->EXIT_CONVEYOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->EMITTER_EXIT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CRANE_LIFT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CRANE_LEFT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CRANE_RIGHT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CRANE_LOADING_CONVEYOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->START_LIGHT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STOP_LIGHT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->WARNING_LIGHT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SIREN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MACHINING_STOP,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MACHINING_RESET,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MACHINING_ISBUSY,0,retain)
  __INIT_VAR(data__->POTENTIOMETER,0,retain)
  __INIT_VAR(data__->CRANE_POSITION,0,retain)
  __INIT_VAR(data__->INPUT_CONVEYOR_ALG,0,retain)
  __INIT_VAR(data__->CURRENT_BASE,0,retain)
  __INIT_VAR(data__->CURRENT_LID,0,retain)
  __INIT_VAR(data__->TOTAL_BASE,0,retain)
  __INIT_VAR(data__->TOTAL_LID,0,retain)
  SR_init__(&data__->SR0,retain);
  CTU_init__(&data__->CTU0,retain);
  LIDS_init__(&data__->LIDS0,retain);
  SR_init__(&data__->SR1,retain);
  CTU_init__(&data__->CTU1,retain);
  CRANE_init__(&data__->CRANE0,retain);
  TON_init__(&data__->TON0,retain);
  SR_init__(&data__->SR2,retain);
  TP_init__(&data__->TP0,retain);
  CTU_init__(&data__->CTU2,retain);
  CTU_init__(&data__->CTU3,retain);
  __INIT_VAR(data__->MOVE18_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MOVE18_OUT,0,retain)
  __INIT_VAR(data__->MOVE65_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MOVE65_OUT,0,retain)
  __INIT_VAR(data__->INT_TO_BOOL23_OUT,__BOOL_LITERAL(FALSE),retain)
  R_TRIG_init__(&data__->R_TRIG1,retain);
  __INIT_VAR(data__->EQ15_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->AND62_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->AND19_OUT,__BOOL_LITERAL(FALSE),retain)
  F_TRIG_init__(&data__->F_TRIG1,retain);
  __INIT_VAR(data__->INT_TO_BOOL14_OUT,__BOOL_LITERAL(FALSE),retain)
  R_TRIG_init__(&data__->R_TRIG2,retain);
  __INIT_VAR(data__->EQ4_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ADD105_OUT,0,retain)
  __INIT_VAR(data__->MOVE82_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MOVE82_OUT,0,retain)
  __INIT_VAR(data__->ADD103_OUT,0,retain)
  __INIT_VAR(data__->MOVE68_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MOVE68_OUT,0,retain)
  __INIT_VAR(data__->MOVE50_OUT,0,retain)
  F_TRIG_init__(&data__->F_TRIG2,retain);
  R_TRIG_init__(&data__->R_TRIG3,retain);
  __INIT_VAR(data__->MOVE100_OUT,0,retain)
  R_TRIG_init__(&data__->R_TRIG4,retain);
  R_TRIG_init__(&data__->R_TRIG5,retain);
  __INIT_VAR(data__->MOVE93_OUT,0,retain)
}

// Code part
void PROGRAM0_body__(PROGRAM0 *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->SR0.,S1,,__GET_VAR(data__->START_BUTTON,));
  __SET_VAR(data__->SR0.,R,,(!(__GET_VAR(data__->STOP_BUTTON,)) || !(__GET_VAR(data__->EMERGENCY_STOP,))));
  SR_body__(&data__->SR0);
  __SET_VAR(data__->,MACHINING_START,,(__GET_VAR(data__->DOOR_SENSOR,) && __GET_VAR(data__->SR0.Q1,)));
  __SET_VAR(data__->,EXIT_CONVEYOR,,(__GET_VAR(data__->DOOR_SENSOR,) && __GET_VAR(data__->SR0.Q1,)));
  __SET_VAR(data__->,CRANE_LOADING_CONVEYOR,,((!(__GET_VAR(data__->CRANE_SENSOR,)) && __GET_VAR(data__->DOOR_SENSOR,)) && __GET_VAR(data__->SR0.Q1,)));
  __SET_VAR(data__->,MOVE18_OUT,,__PROGRAM0_MOVE__INT__INT1(
    (BOOL)!(__GET_VAR(data__->EXIT_CONVEYOR,)),
    (INT)0,
    data__));
  if (__GET_VAR(data__->MOVE18_ENO,)) {
    __SET_VAR(data__->,INPUT_CONVEYOR_ALG,,__GET_VAR(data__->MOVE18_OUT,));
  };
  __SET_VAR(data__->,MOVE65_OUT,,__PROGRAM0_MOVE__INT__INT2(
    (BOOL)(__GET_VAR(data__->DOOR_SENSOR,) && __GET_VAR(data__->SR0.Q1,)),
    (INT)__GET_VAR(data__->POTENTIOMETER,),
    data__));
  if (__GET_VAR(data__->MOVE65_ENO,)) {
    __SET_VAR(data__->,INPUT_CONVEYOR_ALG,,__GET_VAR(data__->MOVE65_OUT,));
  };
  __SET_VAR(data__->,INT_TO_BOOL23_OUT,,INT_TO_BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)__GET_VAR(data__->MACHINING_ISBUSY,)));
  __SET_VAR(data__->R_TRIG1.,CLK,,__GET_VAR(data__->INT_TO_BOOL23_OUT,));
  R_TRIG_body__(&data__->R_TRIG1);
  __SET_VAR(data__->,EQ15_OUT,,EQ__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)5,
    (INT)__GET_VAR(data__->CTU0.CV,)));
  __SET_VAR(data__->,AND62_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->EQ15_OUT,),
    (BOOL)__GET_VAR(data__->TRANSFER_CONVEYOR,)));
  __SET_VAR(data__->CTU0.,CU,,__GET_VAR(data__->R_TRIG1.Q,));
  __SET_VAR(data__->CTU0.,R,,(__GET_VAR(data__->AND62_OUT,) || !(__GET_VAR(data__->STOP_BUTTON,))));
  __SET_VAR(data__->CTU0.,PV,,5);
  CTU_body__(&data__->CTU0);
  __SET_VAR(data__->,AND19_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)(__GET_VAR(data__->DOOR_SENSOR,) && __GET_VAR(data__->SR0.Q1,)),
    (BOOL)__GET_VAR(data__->CTU0.Q,)));
  __SET_VAR(data__->TON0.,IN,,__GET_VAR(data__->AND19_OUT,));
  __SET_VAR(data__->TON0.,PT,,__time_to_timespec(1, 5000, 0, 0, 0, 0));
  TON_body__(&data__->TON0);
  __SET_VAR(data__->F_TRIG1.,CLK,,__GET_VAR(data__->MACHINING_EXIT_SENSOR,));
  F_TRIG_body__(&data__->F_TRIG1);
  __SET_VAR(data__->SR1.,S1,,__GET_VAR(data__->TON0.Q,));
  __SET_VAR(data__->SR1.,R,,__GET_VAR(data__->F_TRIG1.Q,));
  SR_body__(&data__->SR1);
  __SET_VAR(data__->,TRANSFER_CONVEYOR,,__GET_VAR(data__->SR1.Q1,));
  __SET_VAR(data__->,EMITTER_EXIT,,!(__GET_VAR(data__->MACHINING_EXIT_SENSOR,)));
  __SET_VAR(data__->,INT_TO_BOOL14_OUT,,INT_TO_BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)__GET_VAR(data__->MACHINING_ISBUSY,)));
  __SET_VAR(data__->R_TRIG2.,CLK,,__GET_VAR(data__->INT_TO_BOOL14_OUT,));
  R_TRIG_body__(&data__->R_TRIG2);
  __SET_VAR(data__->,EQ4_OUT,,EQ__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)5,
    (INT)__GET_VAR(data__->CTU1.CV,)));
  __SET_VAR(data__->CTU1.,CU,,__GET_VAR(data__->R_TRIG2.Q,));
  __SET_VAR(data__->CTU1.,R,,(__GET_VAR(data__->EQ4_OUT,) || !(__GET_VAR(data__->STOP_BUTTON,))));
  __SET_VAR(data__->CTU1.,PV,,5);
  CTU_body__(&data__->CTU1);
  __SET_VAR(data__->LIDS0.,SIGNAL,,__GET_VAR(data__->CTU1.Q,));
  LIDS_body__(&data__->LIDS0);
  __SET_VAR(data__->,MACHINING_PRODUCELIDS,,__GET_VAR(data__->LIDS0.LIDTYPE,));
  __SET_VAR(data__->,ADD105_OUT,,ADD__INT__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->CTU1.CV,),
    (INT)1));
  __SET_VAR(data__->,MOVE82_OUT,,__PROGRAM0_MOVE__INT__INT3(
    (BOOL)!(__GET_VAR(data__->MACHINING_PRODUCELIDS,)),
    (INT)__GET_VAR(data__->ADD105_OUT,),
    data__));
  if (__GET_VAR(data__->MOVE82_ENO,)) {
    __SET_VAR(data__->,CURRENT_BASE,,__GET_VAR(data__->MOVE82_OUT,));
  };
  __SET_VAR(data__->,ADD103_OUT,,ADD__INT__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->CTU1.CV,),
    (INT)1));
  __SET_VAR(data__->,MOVE68_OUT,,__PROGRAM0_MOVE__INT__INT4(
    (BOOL)__GET_VAR(data__->MACHINING_PRODUCELIDS,),
    (INT)__GET_VAR(data__->ADD103_OUT,),
    data__));
  if (__GET_VAR(data__->MOVE68_ENO,)) {
    __SET_VAR(data__->,CURRENT_LID,,__GET_VAR(data__->MOVE68_OUT,));
  };
  __SET_VAR(data__->CRANE0.,IN_SENSOR,,__GET_VAR(data__->CRANE_SENSOR,));
  __SET_VAR(data__->CRANE0.,IN_MIDLIM,,__GET_VAR(data__->CRANE_ISMIDLIM,));
  __SET_VAR(data__->CRANE0.,IN_MOVEX,,__GET_VAR(data__->CRANE_ISMOVINGX,));
  __SET_VAR(data__->CRANE0.,IN_MOVEZ,,__GET_VAR(data__->CRANE_ISMOVINGZ,));
  __SET_VAR(data__->CRANE0.,IN_RIGHTLIM,,__GET_VAR(data__->CRANE_ISRIGHTLIM,));
  __SET_VAR(data__->CRANE0.,IN_LEFTLIM,,__GET_VAR(data__->CRANE_ISLEFTLIM,));
  __SET_VAR(data__->CRANE0.,ISLID,,!(__GET_VAR(data__->MACHINING_PRODUCELIDS,)));
  CRANE_body__(&data__->CRANE0);
  __SET_VAR(data__->,CRANE_LIFT,,__GET_VAR(data__->CRANE0.OUT_LIFT,));
  __SET_VAR(data__->,CRANE_LEFT,,__GET_VAR(data__->CRANE0.OUT_LEFT,));
  __SET_VAR(data__->,CRANE_RIGHT,,__GET_VAR(data__->CRANE0.OUT_RIGHT,));
  __SET_VAR(data__->,MOVE50_OUT,,MOVE__INT__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)__GET_VAR(data__->CRANE0.OUT_TARGETPOSITION,)));
  __SET_VAR(data__->,CRANE_POSITION,,__GET_VAR(data__->MOVE50_OUT,));
  __SET_VAR(data__->SR2.,S1,,__GET_VAR(data__->START_BUTTON,));
  __SET_VAR(data__->SR2.,R,,(!(__GET_VAR(data__->STOP_BUTTON,)) || !(__GET_VAR(data__->EMERGENCY_STOP,))));
  SR_body__(&data__->SR2);
  __SET_VAR(data__->,START_LIGHT,,__GET_VAR(data__->SR2.Q1,));
  __SET_VAR(data__->,WARNING_LIGHT,,(!(__GET_VAR(data__->DOOR_SENSOR,)) || !(__GET_VAR(data__->EMERGENCY_STOP,))));
  __SET_VAR(data__->,STOP_LIGHT,,!(__GET_VAR(data__->SR2.Q1,)));
  __SET_VAR(data__->TP0.,IN,,(!(__GET_VAR(data__->DOOR_SENSOR,)) || !(__GET_VAR(data__->EMERGENCY_STOP,))));
  __SET_VAR(data__->TP0.,PT,,__time_to_timespec(1, 2000, 0, 0, 0, 0));
  TP_body__(&data__->TP0);
  __SET_VAR(data__->,SIREN,,__GET_VAR(data__->TP0.Q,));
  __SET_VAR(data__->F_TRIG2.,CLK,,__GET_VAR(data__->MACHINING_PRODUCELIDS,));
  F_TRIG_body__(&data__->F_TRIG2);
  __SET_VAR(data__->R_TRIG3.,CLK,,__GET_VAR(data__->F_TRIG2.Q,));
  R_TRIG_body__(&data__->R_TRIG3);
  __SET_VAR(data__->CTU3.,CU,,__GET_VAR(data__->R_TRIG3.Q,));
  __SET_VAR(data__->CTU3.,R,,!(__GET_VAR(data__->STOP_BUTTON,)));
  __SET_VAR(data__->CTU3.,PV,,256);
  CTU_body__(&data__->CTU3);
  __SET_VAR(data__->,MOVE100_OUT,,MOVE__INT__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)__GET_VAR(data__->CTU3.CV,)));
  __SET_VAR(data__->,TOTAL_LID,,__GET_VAR(data__->MOVE100_OUT,));
  __SET_VAR(data__->R_TRIG4.,CLK,,__GET_VAR(data__->MACHINING_PRODUCELIDS,));
  R_TRIG_body__(&data__->R_TRIG4);
  __SET_VAR(data__->R_TRIG5.,CLK,,__GET_VAR(data__->R_TRIG4.Q,));
  R_TRIG_body__(&data__->R_TRIG5);
  __SET_VAR(data__->CTU2.,CU,,__GET_VAR(data__->R_TRIG5.Q,));
  __SET_VAR(data__->CTU2.,R,,!(__GET_VAR(data__->STOP_BUTTON,)));
  __SET_VAR(data__->CTU2.,PV,,256);
  CTU_body__(&data__->CTU2);
  __SET_VAR(data__->,MOVE93_OUT,,MOVE__INT__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)__GET_VAR(data__->CTU2.CV,)));
  __SET_VAR(data__->,TOTAL_BASE,,__GET_VAR(data__->MOVE93_OUT,));

  goto __end;

__end:
  return;
} // PROGRAM0_body__() 





