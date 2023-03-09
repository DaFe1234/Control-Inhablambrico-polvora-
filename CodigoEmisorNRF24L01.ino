#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
 
const int pinCE = 9;
const int pinCSN = 10;
RF24 radio(pinCE, pinCSN);

// Single radio pipe address for the 2 nodes to communicate.
const uint64_t pipe = 0xE8E8F0F0E1LL;

float data[2];

void setup()
{
   radio.begin();
   radio.openWritingPipe(pipe);
   pinMode(3, INPUT_PULLUP);
   pinMode(4, INPUT_PULLUP);
   pinMode(5, INPUT_PULLUP);
   pinMode(6, INPUT_PULLUP);
   pinMode(7, INPUT_PULLUP);
   pinMode(8, INPUT_PULLUP);
   Serial.begin(9600);
}
 
void loop()
{ 
   data[0]= 3.1415;
   if(digitalRead(3) == LOW){
    data[0]= 3.14151;
    radio.write(data, sizeof data);
    Serial.println("jjjj");
   }else{
    data[0]= 3.1415;
    radio.write(data, sizeof data);
   }
   if(digitalRead(4) == LOW){
    data[0]= 3.14152;
    radio.write(data, sizeof data);
    Serial.println("jjjj");
   }else{
    data[0]= 3.1415;
    radio.write(data, sizeof data);
   }
   if(digitalRead(5) == LOW){
    data[0]= 3.14153;
    radio.write(data, sizeof data);
    Serial.println("jjjj");
   }else{
    data[0]= 3.1415;
    radio.write(data, sizeof data);
   }
   if(digitalRead(6) == LOW){
    data[0]= 3.14154;
    radio.write(data, sizeof data);
    Serial.println("jjjj");
   }else{
    data[0]= 3.1415;
    radio.write(data, sizeof data);
   }
   if(digitalRead(7) == LOW){
    data[0]= 3.14155;
    radio.write(data, sizeof data);
    Serial.println("jjjj");
   }else{
    data[0]= 3.1415;
    radio.write(data, sizeof data);
   }
   if(digitalRead(8) == LOW){
    data[0]= 3.14156;
    radio.write(data, sizeof data);
    Serial.println("jjjj");
   }else{
    data[0]= 3.1415;
    radio.write(data, sizeof data);
   }
}
