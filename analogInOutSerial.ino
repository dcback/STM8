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

#define analoginPin   A0    // Analog input pin that the potentiometer is attached to
#define analogoutPin  5     // Analog output pin that the LED is attached to

int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)

void setup() {
  Serial_begin(115200); 
  delay(1000); 
  Serial_println_s("[STM8 Analog-in to Analog-out(PWM)]");
}

void loop() {
  sensorValue = analogRead(analoginPin);  // read the analog in value
  outputValue = map(sensorValue, 0, 1023, 0, 255);  // map it to the range of the analog out
  analogWrite(analogoutPin, outputValue); // change the analog out value:

  Serial_print_s("sensor = [");
  Serial_print_u(sensorValue);
  Serial_print_s("]\t output = [");
  Serial_print_u(outputValue);
  Serial_println_s("]");

  delay(1000);
}
