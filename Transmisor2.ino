// incluye las librerias
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
 
// define los pines del NRF
const int pinCE = 9;
const int pinCSN = 10;
RF24 radio(pinCE, pinCSN);

// define el canal de comunicacion
const uint64_t pipe = 0xE8E8F0F0E1LL;

// flotante donde se guardan los datos
float data[10];

void setup()
{
  radio.begin();
  radio.openWritingPipe(pipe);

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
//--------------------- 1 ----------------------
  if(digitalRead(2) == LOW){
    data[0]= (3.11061);
    radio.write(data, sizeof data);
  }else{
    data[0]= (3.1106);
    radio.write(data, sizeof data);
  }
//---------------------- 2 ---------------------
  if(digitalRead(6) == LOW){
    data[1]= (3.11062);
    radio.write(data, sizeof data);
  }else{
    data[1]= (3.1106);
    radio.write(data, sizeof data);
  }
}