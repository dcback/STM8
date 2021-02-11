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
