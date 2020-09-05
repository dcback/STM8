/*
  https://github.com/dcback/STM8/blob/master/stm8_pinout.png
  https://github.com/tenbaht/sduino/tree/development/sduino/stm8/libraries/Generic_Examples/examples
  [STM8 Pinout]
  PA1=0 PA2=1 PA3=2 PB5=3 PB4=4  PC3=5 PC4=6=A0 PC5=7 PC6=8 PC7=9 PD1=10 PD2=11=A1 PD3=12=A2 PD4=13 PD5=14=A3=TX PD6=15=A4=RX
  No #include <Serial.h> run ok, 5=PD5=TX, 6=PD6=RX
*/
#define ledPin    9   // PC7 is connected to LED to 9

void setup() 
{
  Serial_begin(9600);
  delay(1000);
  Serial_println_s("[Fading]");
}

void loop()
{
  // fade in from min to max in increments of 5 points:
  Serial_println_s("fadein");
  for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5)
  {
    analogWrite(ledPin, fadeValue);   // sets the value (range from 0 to 255):
    Serial_print_s("[");
    Serial_print_i(fadeValue);
    Serial_print_s("]");
    delay(30);    // wait for 30 milliseconds to see the dimming effect
  }
  Serial_println();
  delay(1000);

  // fade out from max to min in decrements of 5 points:
  Serial_println_s("fadeout");
  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5)
  {
    analogWrite(ledPin, fadeValue);   // sets the value (range from 0 to 255):
    Serial_print_s("[");
    Serial_print_i(fadeValue);
    Serial_print_s("]");
    delay(30);    // wait for 30 milliseconds to see the dimming effect
  }
  Serial_println();
  delay(1000);
}
