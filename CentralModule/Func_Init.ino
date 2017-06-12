//********************************************************
void nRF24L01_init() {
  radio.begin();

  radio.setPayloadSize(32);
  radio.setChannel(RF_CHANNEL);
  radio.setDataRate(RF24_1MBPS);  
  radio.setPALevel(RF24_PA_MIN);
  radio.setAutoAck(true);
  radio.enableDynamicPayloads();
  radio.enableAckPayload();
  
  // OPEN THE READING PIPE 1-4 OUT OF 1-5 FOR READING, 0 IS FOR WRITING
  radio.openReadingPipe(1,RF_ADDRESS_READING_A);
  radio.openReadingPipe(2,RF_ADDRESS_READING_B);


  radio.printDetails();
  radio.startListening();
}
//*********************************************************


//**********************************************************
void variables_init() {
  timer_printdata = millis();
  timer_printstate = millis();
  timer_send = millis();
  timer_request = millis();
  timer_sparrow = millis();
  left_thigh_angles = {0,'0'};
  right_thigh_angles = {0,'0'};

  print_count = 0;
}
//**********************************************************
//**********************
void i2c_init() {
  Wire.begin(); // Master node
}
//**********************



