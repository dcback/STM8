/*
  https://github.com/dcback/STM8/blob/master/stm8_pinout.png
  https://github.com/tenbaht/sduino/tree/development/sduino/stm8/libraries/Generic_Examples/examples
  [STM8 Pinout]
  PA1=0 PA2=1 PA3=2 PB5=3 PB4=4  PC3=5 PC4=6=A0 PC5=7 PC6=8 PC7=9 PD1=10 PD2=11=A1 PD3=12=A2 PD4=13 PD5=14=A3=TX PD6=15=A4=RX
  No #include <Serial.h> run ok, 5=PD5=TX, 6=PD6=RX
*/
#define numReadings 10

int readings[numReadings];      // the readings from the analog input
int readIndex = 0;              // the index of the current reading
int total = 0;                  // the running total
int average = 0;                // the average

int inputPin = A0;

void setup()
{
  Serial_begin(9600);
  delay(1000);
  Serial_println_s("[Smoothing]");

  // initialize all the readings to 0:
  for (int thisReading = 0; thisReading < numReadings; thisReading++)
  {
    readings[thisReading] = 0;
  }
}

void loop()
{
  total = total - readings[readIndex];  // subtract the last reading:
  readings[readIndex] = analogRead(inputPin); // read from the sensor:
  total = total + readings[readIndex];  // add the reading to the total:
  readIndex = readIndex + 1;  // advance to the next position in the array:

  if (readIndex >= numReadings) // if we're at the end of the array...
  {
    readIndex = 0;  // ...wrap around to the beginning:
  }

  average = total / numReadings;  // calculate the average:
  Serial_println_u(average);    // send it to the computer as ASCII digits
  delay(1);        // delay in between reads for stability
  delay(1000);
}
