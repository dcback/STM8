/*
  https://github.com/dcback/STM8/blob/master/stm8_pinout.png
  https://github.com/tenbaht/sduino/tree/development/sduino/stm8/libraries/Generic_Examples/examples
  [STM8 Pinout]
  PA1=0 PA2=1 PA3=2 PB5=3 PB4=4  PC3=5 PC4=6=A0 PC5=7 PC6=8 PC7=9 PD1=10 PD2=11=A1 PD3=12=A2 PD4=13 PD5=14=A3=TX PD6=15=A4=RX
  No #include <Serial.h> run ok, 5=PD5=TX, 6=PD6=RX
*/

#include <Serial.h>

#define ledPin    5   // PB5

bool ledStatus = LOW;

void setup()
{
  Serial_begin(9600);
  pinMode(ledPin, OUTPUT);
  delay(1000);
  Serial_println_s("[ATtiny analoRead : ADC to Voltage]");
}

void loop() {
  int sensorValue = analogRead(A0);   // A0 = 6 = PC4
  Serial_print_s("A0 sensorValue int[");
  Serial_print_i(sensorValue);
  Serial_print_s("]");
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 3.3V):
  float voltage = sensorValue * (3.3 / 1023.0);
  Serial_print_s(" -> Convert voltage[");
  Serial_print_f(voltage);
  Serial_println_s("V]");

  digitalWrite(ledPin, ledStatus);
  delay(1000);
  ledStatus = !ledStatus;
}
