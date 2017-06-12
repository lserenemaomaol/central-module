
/*
 * Jun 12, 2017
 * 
 * This is the central module: 
 *  
 * - IMU reading via nRF24L01: 2 pipes
 * - IMU and STATE distribution via I2C to: LEFT & RIGHT
 * - get feedback from LEFT & RIGHT MODULE
 * 
 * 
 * 
 */

//**********  LIBRARIES *****************
#include <RF24.h>
#include <SPI.h>     // SPI bus for nRF24L01
#include <Wire.h>    // I2C bus 
#include <Keypad.h>    // the keypad as UI
//***************************************
//**********  CONSTANTS  *****************
// rf related
#define RF_CHANNEL 0x76
#define RF_ADDRESS_READING_A 0xF0F0F0F0A1LL
#define RF_ADDRESS_READING_B 0xF0F0F0F0B1LL


#define ANGLE_BUF_SIZE 9
#define ANGLE_DECIMAL_SIZE 4
#define BUFFER_SIZE_32 32
#define BUFFER_SIZE_64 64

#define CEPIN 8
#define CSNPIN 7

// I2C addresses
#define I2C_ADDRESS_CENTRAL 0x10
#define I2C_ADDRESS_LEFTPULLEY 0x20
#define I2C_ADDRESS_RIGHTPULLEY 0x40

//****************************************



//********** CUSTOMIZED THINGS **********
struct eulerAngles
{
  float pitch;
  char flag;
};
typedef struct eulerAngles IMU_Angles;
//***************************************
//********** VARIABLES  ******************
RF24 radio(CEPIN,CSNPIN);   //(CEpin, CSNpin)
char buf[BUFFER_SIZE_32];
// EULER ANGLE VAR
IMU_Angles left_thigh_angles, right_thigh_angles;
unsigned long timer_printdata, timer_printstate, timer_send, timer_request, timer_sparrow;
// STATE MACHINE VAR
char key_left;
char inMotionL = 'c';
char inMotionR = 'c';
char stateL = 'c';
char stateR = 'c';
char stateL_desired = 'c';
char stateR_desired = 'c';

// ************************ VARIABLES: KEYPAD    ****************************
const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'},
    {'*','0','#'}
};

//byte rowPins[ROWS] = {18, 19, 20, 7}; //connect to the row pinouts of the keypad
//byte colPins[COLS] = {6, 5, 4}; //connect to the column pinouts of the keypad

byte rowPins[ROWS] = {37, 39, 41, 43}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {45, 47, 49}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
char key_central = '0';

unsigned long print_count;
//
//******************************************************************
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);   // OPEN SERIAL FOR DEBUGGING
  nRF24L01_init();       //  WIRELESS BOARD INITILIZING 
  variables_init();      //  VARIABLES INITILIZING
  i2c_init();             //  I2C MASTER 
  variables_init();       //  VARIABLES INITILIZING
}
//*******************************************************************
//*************************************************************************************************************
void loop() {

  keypad_update();         // GET USER INPUT
  radio_update();          // GET INCOMING DATA 

  // distribute the IMU reading
  i2c_request('L',2);
  i2c_send_left_thigh();

  sparrow_update(100);     // UPDATE STATE MACHINE

  i2c_request('R',2);
  i2c_send_right_thigh();
  
  // DEBUGGING PURPOSE
//  printstate(1000);
  printdata('R', 100);    // printdata( index, timerInterval)     index = 'T', 'C', 'B' (thigh,calf,both)
  
}
//*************************************************************************************************************

















