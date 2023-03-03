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
   Serial.begin(9600);
}
 
void loop()
{ 
   data[0]= 3.14;
   if(digitalRead(3) == LOW){
    radio.write(data, sizeof data);
    Serial.println("jjjj");
    delay(1000);
   }
}
