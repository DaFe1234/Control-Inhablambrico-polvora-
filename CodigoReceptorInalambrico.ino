#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
 
const int pinCE = 9;
const int pinCSN = 10;
RF24 radio(pinCE, pinCSN);
 
// Single radio pipe address for the 2 nodes to communicate.
const uint64_t pipe = 0xE8E8F0F0E1LL;

float data[3];
int led = 2;
int rele = 3;

void setup()
{
   radio.begin();
   pinMode(led, OUTPUT);
   pinMode(rele, OUTPUT);
   Serial.begin(9600); 
   radio.openReadingPipe(1, pipe);
   radio.startListening();
}
 
void loop()
{
   if (radio.available())
   {    
      radio.read(data, sizeof data);
      Serial.print("Dato0= " );
      Serial.print(data[0]);
      if(data[0] == 3.14151 || data[0] == 3.14157 || data[0] == 3.14159){
        digitalWrite(led, HIGH);
        digitalWrite(rele, HIGH);
      }else{
        digitalWrite(led, LOW);
        digitalWrite(rele, LOW);
      }
   }
}
