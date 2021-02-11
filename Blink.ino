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
#define ledPin  3               // PB5  

void setup()
{
  Serial_begin(115200);
  delay(1000);
  Serial_println_s("[LED Blink]");
  
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  digitalWrite(ledPin, LOW);    // LED is ON at LOW state
  Serial_print_s("ledPin LOW->LED ON, "); 
  delay(1000);
  digitalWrite(ledPin, HIGH);
  Serial_println_s("ledPin HIGH->LED OFF ");
  delay(1000);  
}
