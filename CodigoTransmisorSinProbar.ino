#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
 
const int pinCE = 9;
const int pinCSN = 10;
RF24 radio(pinCE, pinCSN);

// Single radio pipe address for the 2 nodes to communicate.
const uint64_t pipe = 0xE8E8F0F0E1LL;

float data[2];
float dataIn[2];

bool flagSec = 0;
bool flag1 = 0;
bool flag2 = 0;
bool flag3 = 0;
bool flag4 = 0;
bool flag5 = 0;
bool flag6 = 0;

void setup()
{
   radio.begin();
   radio.openWritingPipe(pipe);
   radio.openReadingPipe(1, pipe);
   pinMode(2, INPUT_PULLUP);
   pinMode(4, INPUT_PULLUP);
   pinMode(3, INPUT_PULLUP);
   pinMode(6, INPUT_PULLUP);
   pinMode(7, INPUT_PULLUP);
   pinMode(5, INPUT_PULLUP);
   pinMode(8, INPUT_PULLUP);
   pinMode(A5, INPUT_PULLUP);
   pinMode(A0, INPUT_PULLUP);
   pinMode(A1, INPUT_PULLUP);
   pinMode(A2, OUTPUT);
   
   Serial.begin(9600);
}
 
void loop()
{ 
   data[0]= 3.1415;

   if (radio.available()){    
      radio.read(dataIn, sizeof dataIn);
      if(dataIn[0] == 3.14451 && flag1 == 0){
        data[0]= 3.10061;
        radio.write(data, sizeof data);
        flag1 = 1;
      }
      if(dataIn[0] == 3.14452 && flag2 == 0){
        data[0]= 3.10062;
        radio.write(data, sizeof data);
        flag1 = 2;
      }
      if(dataIn[0] == 3.14453 && flag3 == 0){
        data[0]= 3.10063;
        radio.write(data, sizeof data);
        flag1 = 3;
      }
      if(dataIn[0] == 3.14454 && flag4 == 0){
        data[0]= 3.10064;
        radio.write(data, sizeof data);
        flag1 = 4;
      }
      if(dataIn[0] == 3.14455 && flag5 == 0){
        data[0]= 3.10065;
        radio.write(data, sizeof data);
        flag1 = 5;
      }
      if(dataIn[0] == 3.14456 && flag6 == 0){
        data[0]= 3.10066;
        radio.write(data, sizeof data);
        flag1 = 6;
      }
    }
//-------Modulo 1----------------------------------
  if(digitalRead(2) == LOW && flag1 == 1){
    data[0]= 3.14151;
    radio.write(data, sizeof data);
    //Serial.println("jjjj");
   }else{
    data[0]= 3.1415;
    radio.write(data, sizeof data);
   }
//---------Modulo 2--------------------------------
   if(digitalRead(6) == LOW && flag2 == 1)){
    data[0]= 3.14152;
    radio.write(data, sizeof data);
    //Serial.println("jjjj");
   }else{
    data[0]= 3.1415;
    radio.write(data, sizeof data);
   }
//---------Modulo 3--------------------------------
   if(digitalRead(4) == LOW && flag3 == 1)){
    data[0]= 3.14153;
    radio.write(data, sizeof data);
    //Serial.println("jjjj");
   }else{
    data[0]= 3.1415;
    radio.write(data, sizeof data);
   }
//---------Modulo 4--------------------------------
   if(digitalRead(7) == LOW && flag4 == 1)){
    data[0]= 3.14154;
    radio.write(data, sizeof data);
    //Serial.println("jjjj");
   }else{
    data[0]= 3.1415;
    radio.write(data, sizeof data);
   }
//----------Modulo 5-------------------------------
   if(digitalRead(3) == LOW && flag5 == 1)){
    data[0]= 3.14155;
    radio.write(data, sizeof data);
    //Serial.println("jjjj");
   }else{
    data[0]= 3.1415;
    radio.write(data, sizeof data);
   }
//----------Modulo 6-------------------------------
   if(digitalRead(5) == LOW && flag6 == 1)){
    data[0]= 3.14156;
    radio.write(data, sizeof data);
    //Serial.println("jjjj");
   }else{
    data[0]= 3.1415;
    radio.write(data, sizeof data);
   }
 //____________Todos______________________________
   if(digitalRead(8) == LOW){
    data[0]= 3.14157;
    radio.write(data, sizeof data);
    //Serial.println("jjjj");
   }else{
    data[0]= 3.1415;
    radio.write(data, sizeof data);
   }
//------------Pares-----------------------------
   if(digitalRead(A5) == LOW){
    data[0]= 3.14158;
    radio.write(data, sizeof data);
    //Serial.println("jjjj");
   }else{
    data[0]= 3.1415;
    radio.write(data, sizeof data);
   }
//--------------Impares---------------------------
   if(digitalRead(A1) == LOW){
    data[0]= 3.14159;
    radio.write(data, sizeof data);
    //Serial.println("jjjj");
   }else{
    data[0]= 3.1415;
    radio.write(data, sizeof data);
   }
//---------------Secuencia--------------------------
   if(digitalRead(A0) == LOW){
    flagSec = 1;
   }else{
    data[0]= 3.1415;
    radio.write(data, sizeof data);
   }
   while(flagSec == 1){
    data[0]= 3.14151;
    radio.write(data, sizeof data);
    delay(200);
    data[0]= 3.14152;
    radio.write(data, sizeof data);
    delay(200);
    data[0]= 3.14153;
    radio.write(data, sizeof data);
    delay(200);
    data[0]= 3.14154;
    radio.write(data, sizeof data);
    delay(200);
    data[0]= 3.14155;
    radio.write(data, sizeof data);
    delay(200);
    data[0]= 3.14156;
    radio.write(data, sizeof data);
    flagSec = 0;
   }
}