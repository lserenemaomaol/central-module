//*********************************************************************************
void printdata(char index, int timerInterval) {

  if( (millis() - timer_printdata)>timerInterval ) {
    timer_printdata = millis();
        
    if( index == 'L' ) {
      Serial.print("Left  Thigh--  ");
      Serial.print("P: ");
      Serial.print(left_thigh_angles.pitch);
      Serial.print(",  Flag: ");
      Serial.println(left_thigh_angles.flag);
    }
    else if (index == 'R') {
      Serial.print("Right Thigh--  ");
      Serial.print("P: ");
      Serial.print(right_thigh_angles.pitch);
      Serial.print(",  Flag: ");
      Serial.println(right_thigh_angles.flag);
    }
    else if (index == 'B') {
      Serial.print("Left  Thigh--  ");
      Serial.print("P: ");
      Serial.print(left_thigh_angles.pitch);
      Serial.print(",  Flag: ");
      Serial.println(left_thigh_angles.flag);

      Serial.print("Right Thigh--  ");
      Serial.print("P: ");
      Serial.print(right_thigh_angles.pitch);
      Serial.print(",  Flag: ");
      Serial.println(right_thigh_angles.flag);
      Serial.println();  
    }
  }   
}
//*********************************************************************************
//********************************************************
void printstate(int timerInterval) {
  if( (millis()- timer_printstate)>timerInterval )   {
    timer_printstate = millis();
    print_count = print_count + 1;
    
    Serial.println(print_count);
    Serial.print("Key_central: ");
    Serial.println(key_central);

    Serial.print("Desired:     ");
    Serial.print(stateL_desired);
    Serial.print(", ");
    Serial.println(stateR_desired);

    Serial.print("StateL:      ");
    Serial.println(stateL);
    Serial.print("InMotionL:   ");
    Serial.println(inMotionL);

    Serial.print("StateR:      ");
    Serial.println(stateR);
    Serial.print("InMotionR:   ");
    Serial.println(inMotionR);

    Serial.println();
  }
}
//*********************************************************

