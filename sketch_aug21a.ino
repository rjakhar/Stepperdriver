int ser = 7;
int x=0;int y = 0;

int rclk=6;

int srclk=5;

#define number_of_74hc595s 1



//do not touch

#define numOfRegisterPins number_of_74hc595s * 8



boolean registers[numOfRegisterPins];



void clearRegisters(){

  for(int i = 7; i >=  0; i--){

     registers[i] = LOW;

  }

}

void setup() {

  // put your setup code here, to run once:

  pinMode(ser,OUTPUT);

  pinMode(rclk,OUTPUT);

  pinMode(srclk,OUTPUT);

  clearRegisters();



}



void loop() {

  // put your main code here, to run repeatedly:
while(x<690||y<345)
{if(x<690){
digitalWrite(rclk, LOW);

  shiftOut(ser,srclk,MSBFIRST,B00001111);

  digitalWrite(rclk, HIGH);

delay(2);

digitalWrite(rclk, LOW);

  shiftOut(ser,srclk,MSBFIRST,B00001110);

  digitalWrite(rclk, HIGH);

  delay(2);
x++;}
if(y<345)
{digitalWrite(rclk, LOW);

  shiftOut(ser,srclk,MSBFIRST,B00000111);

  digitalWrite(rclk, HIGH);

delay(2);

digitalWrite(rclk, LOW);

  shiftOut(ser,srclk,MSBFIRST,B00000101);

  digitalWrite(rclk, HIGH);

  delay(2);
y++;
}}}
