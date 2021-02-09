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
