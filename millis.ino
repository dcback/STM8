/* https://github.com/tenbaht/sduino
                 [STM8 Pinout]
                  ----------
          PD4=13-|   STM8   |-12=PD3=A2
    TX=A3=PD5=14-|  Sduino  |-11=PD2=A1
    RX=A4=PD6=15-|          |-10=PD1=SWIM
           RESET-|          |-9(~)=PC7=MISO
           PA1=0-|          |-8(~)=PC6=MOSI
           PA2=1-|          |-7(~)=PC5=SCK
             GND-|          |-6(~)=PC4=A0
              5V-|          |-5(~)=PC3
            3.3V-|          |-4=PB4=SCL
        SS=PA3=2-|          |-3=PB5=SDA
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
