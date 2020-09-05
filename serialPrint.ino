/*
  https://github.com/dcback/STM8/blob/master/stm8_pinout.png
  https://github.com/tenbaht/sduino/tree/development/sduino/stm8/libraries/Generic_Examples/examples
  [STM8 Pinout]
  PA1=0 PA2=1 PA3=2 PB5=3 PB4=4  PC3=5 PC4=6=A0 PC5=7 PC6=8 PC7=9 PD1=10 PD2=11=A1 PD3=12=A2 PD4=13 PD5=14=A3=TX PD6=15=A4=RX
  No #include <Serial.h> run ok, 5=PD5=TX, 6=PD6=RX
*/
#define ledPin  3     // PB5   

int intValue = 4095;            // FFF
unsigned int uintValue = 65535; // FFFF
float floatValue = 3.14;
char charName = 'A';
char* strName = "ABC 백동철";
bool ledStatus = LOW;

void setup() 
{
  Serial_begin(9600);
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
  Serial_println_s("----------------------");

  digitalWrite(ledPin, ledStatus);
  delay(1000);
  ledStatus = !ledStatus;
}
