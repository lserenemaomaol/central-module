
//***********************************************************************************
void i2c_request(char index, int timerInterval)
{
  if( (millis()-timer_request) > timerInterval) {
    timer_request = millis();
    char text[2];

    if(index == 'L') {
      Wire.requestFrom(I2C_ADDRESS_LEFTPULLEY,2);
      while(Wire.available()) {
        Wire.readBytes(text,2);
        stateL = text[0];
        inMotionL = text[1];
      }
    }

    if(index == 'R') {
      Wire.requestFrom(I2C_ADDRESS_RIGHTPULLEY,2);
      while(Wire.available()) {
        Wire.readBytes(text,2);
        stateR = text[0];
        inMotionR = text[1];
      }
    }
  }
}


//***********************************************************************************
//*******************************************    
void i2c_send_left_thigh() {
  char text[BUFFER_SIZE_32];
  char buf_pitch[ANGLE_BUF_SIZE];

  dtostrf(left_thigh_angles.pitch,ANGLE_BUF_SIZE-1,ANGLE_DECIMAL_SIZE,buf_pitch);


  text[0] = stateL_desired;
  text[1] = 'A';
  text[2] = left_thigh_angles.flag;
  
  for ( int i=0; i< ANGLE_BUF_SIZE; i++ ) {
    text[i+3] = buf_pitch[i];
  }
  Wire.beginTransmission(I2C_ADDRESS_LEFTPULLEY);
  Wire.write(text,sizeof(text));
  Wire.endTransmission();  
}
//*************************************************
//**************************************************************************************
void i2c_send_right_thigh() {
  char text[BUFFER_SIZE_32];
  char buf_pitch[ANGLE_BUF_SIZE];

  dtostrf(right_thigh_angles.pitch,ANGLE_BUF_SIZE-1,ANGLE_DECIMAL_SIZE,buf_pitch);

  text[0] = stateR_desired;
  text[1] = 'C';
  text[2] = right_thigh_angles.flag;
  
  for ( int i=0; i< ANGLE_BUF_SIZE; i++ ) {
    text[i+3] = buf_pitch[i];
  }
  Wire.beginTransmission(I2C_ADDRESS_RIGHTPULLEY);
  Wire.write(text,sizeof(text));
  Wire.endTransmission();  
}
//****************************************************************************************
