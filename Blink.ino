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
