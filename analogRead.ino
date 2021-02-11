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
