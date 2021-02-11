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
#define ledPin  3               // PB5   

int intValue = 4095;            // FFF
unsigned int uintValue = 65535; // FFFF
float floatValue = 3.14;
char charName = 'A';
char* strName = "한국공학기술연구원";
bool ledStatus = LOW;

void setup()
{
  Serial_begin(115200);
  delay(1000);
  Serial_println_s("[Serial print]");

  pinMode(ledPin, OUTPUT);
}

void loop()
{
  Serial_print_s("Int : ");
  Serial_println_i(intValue);       
  Serial_print_s("Unsigned int : ");
  Serial_println_u(uintValue);
  Serial_print_s("Float : ");
  Serial_println_f(floatValue);
  Serial_print_s("Char : ");
  Serial_print_c(charName);
  Serial_println();
  Serial_print_s("String : ");
  Serial_println_s(strName);
  Serial_print_s("Base conv : 4095->");
  Serial_println_ib(intValue, HEX);
  Serial_println_s("-------------------------");

  digitalWrite(ledPin, ledStatus);
  delay(1000);
  ledStatus = !ledStatus;
}
