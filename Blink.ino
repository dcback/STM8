/*
  https://github.com/dcback/STM8/blob/master/stm8_pinout.png
  https://github.com/tenbaht/sduino/tree/development/sduino/stm8/libraries/Generic_Examples/examples
  [STM8 Pinout]
  PA1=0 PA2=1 PA3=2 PB5=3 PB4=4  PC3=5 PC4=6=A0 PC5=7 PC6=8 PC7=9 PD1=10 PD2=11=A1 PD3=12=A2 PD4=13 PD5=14=A3=TX PD6=15=A4=RX
  No #include <Serial.h> run ok, 5=PD5=TX, 6=PD6=RX
*/
#define ledPin      3     // PB5

void setup()
{
  Serial_begin(9600);
  delay(1000);
  Serial_println_s("[LED Blink]");
  
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  digitalWrite(ledPin, LOW);  // LED is ON at LOW state
  Serial_print_s("ledPin LOW->LED ON, "); 
  delay(1000);
  digitalWrite(ledPin, HIGH);
  Serial_println_s("ledPin HIGH->LED OFF ");
  delay(1000);  
}
