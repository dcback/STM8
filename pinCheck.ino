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

void setup()
{
  Serial_begin(115200);
}

void loop()
{
  Serial_println_s("[Pin check]");
  Serial_print_s("PA1 = "); Serial_println_i(PA1);    // 0
  Serial_print_s("PA2 = "); Serial_println_i(PA2);    // 1
  Serial_print_s("PA3 = "); Serial_println_i(PA3);    // 2
  Serial_print_s("PB5 = "); Serial_println_i(PB5);    // 3
  Serial_print_s("PB4 = "); Serial_println_i(PB4);    // 4
  Serial_print_s("PC3 = "); Serial_println_i(PC3);    // 5
  Serial_print_s("PC4 = "); Serial_println_i(PC4);    // 6
  Serial_print_s("PC5 = "); Serial_println_i(PC5);    // 7
  Serial_print_s("PC6 = "); Serial_println_i(PC6);    // 8
  Serial_print_s("PC7 = "); Serial_println_i(PC7);    // 9
  Serial_print_s("PD1 = "); Serial_println_i(PD1);    // 10
  Serial_print_s("PD2 = "); Serial_println_i(PD2);    // 11
  Serial_print_s("PD3 = "); Serial_println_i(PD3);    // 12
  Serial_print_s("PD4 = "); Serial_println_i(PD4);    // 13
  Serial_print_s("PD5 = "); Serial_println_i(PD5);    // 14
  Serial_print_s("PD6 = "); Serial_println_i(PD6);    // 15
  delay(1000);
}
