/*
  https://github.com/dcback/STM8/blob/master/stm8_pinout.png
  https://github.com/tenbaht/sduino/tree/development/sduino/stm8/libraries/Generic_Examples/examples
  [STM8 Pinout]
  PA1=0 PA2=1 PA3=2 PB5=3 PB4=4  PC3=5 PC4=6=A0 PC5=7 PC6=8 PC7=9 PD1=10 PD2=11=A1 PD3=12=A2 PD4=13 PD5=14=A3=TX PD6=15=A4=RX
  No #include <Serial.h> run ok, 5=PD5=TX, 6=PD6=RX
*/
#define sensorPin     A0    // pin that the sensor is attached to
#define ledPin        3     // PB5 pin that the LED is attached to

// variables:
unsigned int sensorValue = 0;     // the sensor value
unsigned int sensorMin   = 1023;  // minimum sensor value
unsigned int sensorMax   = 0;     // maximum sensor value

void setup() {
  Serial_begin(9600);
  delay(1000);
  Serial_println_s("[Calibration]");
  
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);    // turn on LED to signal the start of the calibration period:

  // calibrate during the first five seconds
  while (millis() < 5000)
  {
    sensorValue = analogRead(sensorPin);

    // record the maximum sensor value
    if (sensorValue > sensorMax)
    {
      sensorMax = sensorValue;
    }

    // record the minimum sensor value
    if (sensorValue < sensorMin)
    {
      sensorMin = sensorValue;
    }
  }
  digitalWrite(ledPin, LOW); // signal the end of the calibration period
}

void loop() {
  sensorValue = analogRead(sensorPin);  // read the sensor:
  Serial_print_s("analogRead Value = [");
  Serial_print_u(sensorValue);
  Serial_println_s("]");

  sensorValue = map(sensorValue, sensorMin, sensorMax, 0, 255); // apply the calibration to the sensor reading
  Serial_print_s("map Value = [");
  Serial_print_u(sensorValue);
  Serial_println_s("]");

  sensorValue = constrain(sensorValue, 0, 255); // in case the sensor value is outside the range seen during calibration
  Serial_print_s("constrain Value = [");
  Serial_print_u(sensorValue);
  Serial_println_s("]");
  Serial_println_s("------------------------");

  analogWrite(ledPin, sensorValue); // fade the LED using the calibrated value:
  delay(1000);
}
