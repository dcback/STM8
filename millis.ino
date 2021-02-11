/* https://github.com/tenbaht/sduino
                [STM8 Pinout]
                  ----------
       SDA=PB5=3-|   STM8   |-2=PA3=SS
       SCL=PB4=4-|  Sduino  |-3.3V
        PC3=5(~)-|          |-5V
     A0=PC4=6(~)-|          |-GND
    SCK=PC5=7(~)-|          |-1=PA2 
  MOSI=PC6=x8(~)-|          |-0=PA1
   MISO=PC7=9(~)-|          |-RESET 
     SWIM=PD1=10-|          |-15=PD6=A4=RX
       A1=PD2=11-|    --    |-14=PD5=A3=TX 
       A2=PD3=12-|   |  |   |-13=PD4
                  ----------
*/
#include <Serial.h>

#define ledPin  3     // PB5

bool ledState = LOW;
unsigned long previousMillis = 0;   // will store last time LED was updated
const long interval = 1000;         // interval at which to blink (milliseconds)

void setup()
{
  Serial_begin(115200);
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
