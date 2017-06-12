//**********************************************************************************
void radio_update(){  

  // check for incoming radio messages
  if(radio.available()) {
    radio.read( &buf, radio.getDynamicPayloadSize());

    switch( buf[0] )  {

      case 'L': 
        left_thigh_angles = extractEulerAngles(buf);
        break;

      case 'R':
        right_thigh_angles = extractEulerAngles(buf);
        break;

      default:
        {
//          Serial.print("Invalid Data Header: ");
//          Serial.println(buf[0]);
        }
        break;
    }
  }
}
//***********************************************************************************
//************************************************
IMU_Angles extractEulerAngles(char* buf)
{
  IMU_Angles result;
  char buf_pitch[ANGLE_BUF_SIZE];

  for(int i=0; i< ANGLE_BUF_SIZE; i++){
    buf_pitch[i] = buf[i+2];
  }
  
  result.pitch = atof(buf_pitch);
  result.flag = buf[1];

  return result;
}
//***********************************************
