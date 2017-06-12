

//*****************************************************
void keypadEvent(KeypadEvent key){
    switch (keypad.getState()){
    case PRESSED:
        break;

    case RELEASED:
//        Serial.print("Key pressed: ");
//        Serial.println(key);
        break;

    case HOLD:
        break;
    }
}
//*****************************************************

//*******************************************
void keypad_update() {
  char key = keypad.getKey();
  if(key) {
    key_central = key;
  }
}
//*******************************************

