char dirn='c'; 

  int count =0;
  void setup() {
 Serial.begin(9600);
 int bluewire = 2;
 int orangewire = 3;
 int yellowwire = 4;
 int pinkwire = 5;
// int dirn = 6;
 
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
 // pinMode(6,OUTPUT);
}
void t_pd( )

{const int a = 13;
  delay(a);
}
//char dirn;
void loop() {
  int x =0;

if (Serial.available() > 0)
 {
Serial.println(dirn);
 dirn = Serial.read(); //read int or parseFloat for ..float...

Serial.println(dirn); 
 } 
 Serial.println(dirn);/*if (Serial.available()>0) {
                // read the incoming byte:
                Serial.println("read");
                dirn = Serial.read();

                // say what you got:
                Serial.print("I received: ");
                Serial.println(dirn, DEC);
  } 
// Serial.println("test");*/


if(dirn == 'c' || dirn =='a')
{
  while(x<2048)
  {

  if(dirn=='a')
  {
  digitalWrite(2,HIGH);
  digitalWrite(3,LOW);
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
  t_pd();
 digitalWrite(2,LOW);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
  t_pd();
 digitalWrite(2,LOW);
  digitalWrite(3,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);
  t_pd(); 
   
  digitalWrite(2,HIGH);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);
  t_pd();
  x= x+4;
}

if(dirn == 'c')
{
  digitalWrite(2,HIGH);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);
  t_pd();
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  t_pd(); 
   digitalWrite(2,LOW);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
  t_pd();
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  t_pd();
  x=x+4;
  }

  
}
}
count++;
}


