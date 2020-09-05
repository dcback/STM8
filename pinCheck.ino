/*
  https://github.com/dcback/STM8/blob/master/stm8_pinout.png
  https://github.com/tenbaht/sduino/tree/development/sduino/stm8/libraries/Generic_Examples/examples
  [STM8 Pinout]
  PA1=0 PA2=1 PA3=2 PB5=3 PB4=4  PC3=5 PC4=6=A0 PC5=7 PC6=8 PC7=9 PD1=10 PD2=11=A1 PD3=12=A2 PD4=13 PD5=14=A3=TX PD6=15=A4=RX
  No #include <Serial.h> run ok, 5=PD5=TX, 6=PD6=RX
*/
#include <Serial.h>

void setup()
{
  Serial_begin(9600);
  delay(1000);
  Serial_println_s("[Pin check]");
}

void loop()
{
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
  Serial_print_i(PA1);Serial_print_i(PA2);Serial_print_i(PA3);Serial_print_i(PB5);
  Serial_print_i(PB4);Serial_print_i(PC3);Serial_print_i(PC4);Serial_print_i(PC5);
  Serial_print_i(PC6);Serial_print_i(PC7);Serial_print_i(PD1);Serial_print_i(PD2);
  Serial_print_i(PD3);Serial_print_i(PD4);Serial_print_i(PD5);Serial_println_i(PD6);
  delay(1000);
}
