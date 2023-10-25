#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
 
const int pinCE = 9;
const int pinCSN = 10;
RF24 radio(pinCE, pinCSN);
 
// Single radio pipe address for the 2 nodes to communicate.
const uint64_t pipe = 0xE8E8F0F0E1LL;

float data[10];

int led = 2;
int rele = 3;

void setup()
{
  radio.begin();
  Serial.begin(9600); 
  radio.openReadingPipe(1, pipe);
  radio.startListening();

  pinMode(led, OUTPUT);
  pinMode(rele, OUTPUT);
}
 
void loop()
{
  if (radio.available())
  {    
    radio.read(data, sizeof data);
    if(data[0] == 3.11061){
      digitalWrite(led, HIGH);
      digitalWrite(rele, HIGH);
    }else{
      digitalWrite(led, LOW);
      digitalWrite(rele, LOW);
    }
  }
}