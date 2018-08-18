/*
This sketch controls a 28BYJ-48 stepper motor via a shift register. 

For details on usage, wiring, etc. see link below.
http://projectsfromtech.blogspot.com/2014/03/arduino-shift-register-stepper-motor.html

Last Edited: 3/1/2014 
by Matthew https://projectsfromtech.blogspot.com

Thanks to DrLuke from http://bildr.org/2011/02/74hc595/
for Shift Register Control code
*/

int SER_Pin1 = 5;
int SER_Pin2 = 7; 

//pin 14 on the 75HC595
int RCLK_Pin = 9;  //pin 12 on the 75HC595
int SRCLK_Pin = 10; //pin 11 on the 75HC595

//How many of the shift registers - change this
#define number_of_74hc595s 2 

//do not touch
#define numOfRegisterPins number_of_74hc595s * 8

boolean registers[numOfRegisterPins];



           


//set all register pins to LOW


void clearRegisters(){
  for(int i = numOfRegisterPins - 1; i >=  0; i--){
     registers[i] = LOW;
  }
}
/*  void clearRegisters2(){
  for(int i = numOfRegisterPins -17 ; i >=  8; i--){
     registers[i] = LOW;
  }
  }
  void clearRegisters3(){
  for(int i = numOfRegisterPins - 9; i >=  16; i--){
     registers[i] = LOW;
  }
  }
  void clearRegisters4(){
  for(int i = numOfRegisterPins - 1; i >=  24; i--){
     registers[i] = LOW;

  }
  }*/
//Set and display registers
//Only call AFTER all values are set how you would like (slow otherwise)
int writeRegisters(int x,int a){
  int d;
  if(a==1)
  {d=x+1;}
  else
  {d=x;}

  digitalWrite(RCLK_Pin, LOW);

  for(int i = numOfRegisterPins - 13+ 4*(d-5); i >=  4*(d-5); i--){
    digitalWrite(SRCLK_Pin, LOW);

    int val = registers[i];

    digitalWrite(x, val);
    digitalWrite(SRCLK_Pin, HIGH);

  }
  if(a==1){
    for(int i=0
  }
  digitalWrite(RCLK_Pin, HIGH);

}

//set an individual pin HIGH or LOW
void setRegisterPin(int index, boolean value){
  registers[index] = value;
}

////////////////////////////////////////////////////////////////////
int motorPin[16]={0};//declare variables for the motor pins
void motorpin()
{
for(int j=0; j<16; j++)
{
  motorPin[j]=j;
}
}
/*int motorPin1 = 0;	// Blue   - 28BYJ48 pin 1
int motorPin2 = 1;	// Pink   - 28BYJ48 pin 2
int motorPin3 = 2;	// yellow - 28BYJ48 pin 3
int motorPin4 = 3;
int motorPin5 = 3;
int motorPin6 = 3;
int motorPin7 = 3;
int motorPin8 = 3;
int motorPin4 = 3;
int motorPin4 = 3;
int motorPin4 = 3;// Orange - 28BYJ48 pin 4
  
 */                       // Red    - 28BYJ48 pin 5 (VCC)
int x=0;
int motorSpeed = 10;     //variable to set stepper speed
//r0 to pin1 of uln2003
//R1 TO PIN2

//////////////////////////////////////////////////////////////////////////////
void setup() {

  Serial.begin(9600);
  
  pinMode(SER_Pin1, OUTPUT);
  pinMode(RCLK_Pin, OUTPUT);
  pinMode(SRCLK_Pin, OUTPUT);
  pinMode(SER_Pin2, OUTPUT);
  /*pinMode(SER_Pin3, OUTPUT);
  pinMode(SER_Pin4, OUTPUT);
*/
  //reset all register pins
  clearRegisters();
  
  
  writeRegisters(5,0);
  writeRegisters(5,1);
  writeRegisters(7,0);
  writeRegisters(7,1);
  /* writeRegisters(7);
 writeRegisters(8);
 */}

//////////////////////////////////////////////////////////////////////////////
void loop(){
  
  {
   
clockwise(SER_Pin1,1);
//clockwise(SER_Pin1,0);
//clockwise(SER_Pin2,1);
//clockwise(SER_Pin1,0);
  }


}

//////////////////////////////////////////////////////////////////////////////
//set pins to ULN2003 high in sequence from 1 to 4
//delay "motorSpeed" between each pin setting (to determine speed)

void clockwise (int p,int c){
 motorpin();
 /*if(c==1 && p==5){
  p=6;
 }
 if(c==0 && p==8){
  p=7;
 }
 if(c==0 && p==8){
  p=8;
 }
 */
 if(c==1){
 p++;
 }
  
 
  setRegisterPin(motorPin[(p-4)*4-4], LOW);
  setRegisterPin(motorPin[(p-4)*4-3], LOW);
  setRegisterPin(motorPin[(p-4)*4-2], HIGH);
  setRegisterPin(motorPin[(p-4)*4-1], HIGH);
  writeRegisters(p,c); 
  delay (motorSpeed);
 
  setRegisterPin(motorPin[(p-4)*4-4], HIGH);
  setRegisterPin(motorPin[(p-4)*4-3], LOW);
  setRegisterPin(motorPin[(p-4)*4-2], LOW);
  setRegisterPin(motorPin[(p-4)*4-1], HIGH);
  writeRegisters(p,c); 
  delay (motorSpeed);
  setRegisterPin(motorPin[(p-4)*4-4], HIGH);
  setRegisterPin(motorPin[(p-4)*4-3], HIGH);
  setRegisterPin(motorPin[(p-4)*4-2], LOW);
  setRegisterPin(motorPin[(p-4)*4-1], LOW);
  writeRegisters(p,c); 
  delay (motorSpeed);
  setRegisterPin(motorPin[(p-4)*4-4], LOW);
  setRegisterPin(motorPin[(p-4)*4-3], HIGH);
  setRegisterPin(motorPin[(p-4)*4-2], HIGH);
  setRegisterPin(motorPin[(p-4)*4-1], LOW);
  writeRegisters(p,c); 
  delay (motorSpeed);
}
  
/*setRegisterPin(motorPin1, HIGH);
  setRegisterPin(motorPin2, LOW);
  setRegisterPin(motorPin3, LOW);
  setRegisterPin(motorPin4, HIGH);
  writeRegisters(p); 
  delay(motorSpeed);
  
  setRegisterPin(motorPin1, HIGH);
  setRegisterPin(motorPin2, HIGH);
  setRegisterPin(motorPin3, LOW);
  setRegisterPin(motorPin4, LOW);
  writeRegisters(p); 
  delay (motorSpeed);
  
   setRegisterPin(motorPin1, LOW);
  setRegisterPin(motorPin2, HIGH);
  setRegisterPin(motorPin3, HIGH);
  setRegisterPin(motorPin4, LOW);
  writeRegisters(p); 
  delay(motorSpeed);
 
  
}*/

//////////////////////////////////////////////////////////////////////////////
//set pins to ULN2003 high in sequence from 4 to 1
//delay "motorSpeed" between each pin setting (to determine speed)

/*void counterclockwise(int p){
  setRegisterPin(motorPin4, HIGH);
  setRegisterPin(motorPin3, HIGH);
  setRegisterPin(motorPin2, LOW);
  setRegisterPin(motorPin1, LOW);
  writeRegisters(p); 
  delay (motorSpeed);

  setRegisterPin(motorPin4, LOW);
  setRegisterPin(motorPin3, HIGH);
  setRegisterPin(motorPin2, HIGH);
  setRegisterPin(motorPin1, LOW);
  writeRegisters(p); 
  delay(motorSpeed);
  
  
  setRegisterPin(motorPin4, LOW);
  setRegisterPin(motorPin3, LOW);
  setRegisterPin(motorPin2, HIGH);
  setRegisterPin(motorPin1, HIGH);
  writeRegisters(p); 
  delay (motorSpeed);
  
  setRegisterPin(motorPin4, HIGH);
  setRegisterPin(motorPin3, LOW);
  setRegisterPin(motorPin2, LOW);
  setRegisterPin(motorPin1, HIGH);
  writeRegisters(p); 
  delay(motorSpeed);

}*/

