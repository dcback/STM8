/*
  https://github.com/dcback/STM8/blob/master/Hardware/09-stm8-image3801.png
  https://github.com/tenbaht/sduino/blob/development/sduino/stm8/libraries/Generic_Examples/examples/03.Analog/AnalogInOutSerial/AnalogInOutSerial.ino
  [STM8S Pinout]
  PA1=0 PA2=1 PA3=2 PB5=3 PB4=4  PC3=5 PC4=6=A0 PC5=7 PC6=8 PC7=9 PD1=10 PD2=11=A1 PD3=12=A2 PD4=13 PD5=14=A3=TX PD6=15=A4=RX
  No #include <Serial.h> run ok, 5=PD5=TX, 6=PD6=RX
*/
#define analoginPin   A0    // Analog input pin that the potentiometer is attached to
#define analogoutPin  PC7   // Analog output pin that the LED is attached to

int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)

void setup() {
  Serial_begin(9600);  
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

  delay(2);     // ADC to settling time
  delay(1000);
}
