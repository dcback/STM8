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
#define  buzzPin 5        // the PWM pin the buzzer is attached to
int volume = 0;           // how loud the buzzer is
int fadeAmount = 5;       // how many points to fade the buzzer volume by

int duty_cycle = 127;     // 0-255 so 50% = 127 approx

void setup()
{
  pinMode(buzzPin, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop()
{
  analogWrite(buzzPin, volume);

  // change the volume for next time through the loop:
  volume = volume + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (volume <= 0 || volume >= 255) {
    fadeAmount = -fadeAmount;
  }
  // wait for 1~100 milliseconds to see the volume effect
  delay(10);
}
