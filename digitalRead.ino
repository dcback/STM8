/*
  https://github.com/dcback/STM8/blob/master/stm8_pinout.png
  https://github.com/tenbaht/sduino/tree/development/sduino/stm8/libraries/Generic_Examples/examples
  [STM8 Pinout]
  PA1=0 PA2=1 PA3=2 PB5=3 PB4=4  PC3=5 PC4=6=A0 PC5=7 PC6=8 PC7=9 PD1=10 PD2=11=A1 PD3=12=A2 PD4=13 PD5=14=A3=TX PD6=15=A4=RX
  No #include <Serial.h> run ok, 5=PD5=TX, 6=PD6=RX
*/
#include <Serial.h>

#define ledPin      3         // PB5        
#define buttonPin   2         // PA3         

void setup()
{
  Serial_begin(9600);
  delay(1000);
  Serial_println_s("[Digital Read]");
  
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop()
{
  int buttonState = digitalRead(buttonPin);
  Serial_print_s("buttonState bool[");
  Serial_print_i(buttonState);
  Serial_print_s("] ");
  Serial_print_s("int[");
  Serial_print_i(buttonState);
  Serial_println_s("]");

  digitalWrite(ledPin, buttonState);
  delay(1000);
}
