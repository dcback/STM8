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

#define ledPin      3     // PB5
#define buttonPin   2     // PA3         

bool buttonState = 0;

void setup()
{
  Serial_begin(115200);
  delay(1000);
  Serial_println_s("[Button & LED On/Off]");

  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop()
{
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH)
  {
    digitalWrite(ledPin, LOW);      // turn LED on:
  }
  else
  {
    digitalWrite(ledPin, HIGH);     // turn LED off:
  }
  Serial_print_s("buttonState bool[");
  Serial_print_i(buttonState);
  Serial_println_s("] ");

  delay(1000);
}
