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

#define ledPin    3   // PB5

bool ledStatus = LOW;

void setup()
{
  Serial_begin(115200);
  delay(1000);
  Serial_println_s("[ATtiny analoRead : ADC to Voltage]");

  pinMode(ledPin, OUTPUT);
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
