

//******************************************************
void sparrow_update(int timerInterval) {
/*  if(Serial.available()) {
    state_input = Serial.read();
  }
*/
  if( (millis()-timer_sparrow) > timerInterval )    {
    
    // '0' for emergency stop
    if( (key_central=='0') || (key_central=='5') ) {
      stateL_desired = '0';
      stateR_desired = '0';
    }

    if( key_central=='*') {
      if( (stateL=='0') && (inMotionL=='0') )  {
        stateL_desired = '1';
      }
      if( (stateL=='1') && (inMotionL=='0') )  {
        stateL_desired = '2';
      }
      if( (stateL=='2') && (inMotionL=='0') )  {
        stateL_desired = '3';
      }
      if( (stateL=='3') && (inMotionL=='0') )  {
        key_central = '0';
        stateL_desired = '0';
      }
    }
    
    if( key_central=='#') {
      if( (stateR=='0') && (inMotionR=='0') )  {
        stateR_desired = '1';
      }
      if( (stateR=='1') && (inMotionR=='0') )  {
        stateR_desired = '2';
      }
      if( (stateR=='2') && (inMotionR=='0') )  {
        stateR_desired = '3';
      }
      if( (stateR=='3') && (inMotionR=='0') )  {
        key_central = '0';
        stateR_desired = '0';
      }
    }

    // FOR TUNING LEFT SIDE MOTORS 
    if( key_central=='1' ) {
      stateL_desired = 'a';
      stateR_desired = '0';
    }
    if( key_central=='2' ) {
      stateL_desired = 'b';
      stateR_desired = '0';
    }
    if( key_central=='3' ) {
      stateL_desired = 'c';
      stateR_desired = '0';      
    }
    if( key_central=='4' ) {
      stateL_desired = 'd';
      stateR_desired= '0';
    }
    // FOR TUNING RIGHT SIDE MOTORS
    if( key_central=='6' ) {
      stateL_desired = '0';
      stateR_desired = 'a';
    }
    if( key_central=='7' ) {
      stateL_desired = '0';
      stateR_desired = 'b';
    }
    if( key_central=='8' ) {
      stateL_desired = '0';
      stateR_desired = 'c';      
    }
    if( key_central=='9' ) {
      stateL_desired = '0';
      stateR_desired= 'd';
    }    
  }
}
