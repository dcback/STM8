/*
  https://github.com/dcback/STM8/blob/master/stm8_pinout.png
  https://github.com/tenbaht/sduino/tree/development/sduino/stm8/libraries/Generic_Examples/examples
  [STM8 Pinout]
  PA1=0 PA2=1 PA3=2 PB5=3 PB4=4  PC3=5 PC4=6=A0 PC5=7 PC6=8 PC7=9 PD1=10 PD2=11=A1 PD3=12=A2 PD4=13 PD5=14=A3=TX PD6=15=A4=RX
  No #include <Serial.h> run ok, 5=PD5=TX, 6=PD6=RX
*/
#include <Serial.h>

#define ledPin  3     // PB5

bool ledState = LOW;
unsigned long previousMillis = 0;   // will store last time LED was updated
const long interval = 1000;         // interval at which to blink (milliseconds)

void setup()
{
  Serial_begin(9600);
  delay(1000);
  Serial_println_s("[millis]");

  pinMode(ledPin, OUTPUT);
}

void loop()
{
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval)
  {
    previousMillis = currentMillis;   // save the last time at blinked the LED

    if (ledState == LOW)    // if the LED is off turn it on and vice-versa:
    {
      ledState = HIGH;
    }
    else
    {
      ledState = LOW;
    }
    digitalWrite(ledPin, ledState);   // set the LED with the ledState of the variable:
    Serial_print_u(currentMillis / 1000);
    Serial_print_s("초 : ");
    Serial_println_i(ledState);
  }
}
