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
