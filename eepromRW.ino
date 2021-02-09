/* https://github.com/tenbaht/sduino/tree/development/sduino/stm8/libraries/EEPROM
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

    Iterate through each byte of the EEPROM storage.
    Larger STM8 processors have larger EEPROM sizes, E.g:
    - STM8S003:   128B EEPROM storage.
    - STM8S103:   640B EEPROM storage.
    - STM8S105:   1kB EEPROM storage.
    - STM8S208S:  1.5kB EEPROM storage.
    - STM8S208R:  2kB EEPROM storage.
    Rather than hard-coding the length, you should use the pre-provided length function.
    This will make your code portable to all STM8 processors.
*/
#include <Serial.h>
#include <EEPROM.h>

unsigned int address = 0;
unsigned int value;

void setup()
{
  Serial_begin(115200);
}

void loop()
{
  for (address = 0; address < EEPROM_length(); address++)
  {
    unsigned int val = random(EEPROM_length());
    EEPROM_write(address, val);
  }

  for (address = 0; address < EEPROM_length(); address++)
  {
    value = EEPROM_read(address);

    Serial_print_i(address);
    Serial_print_s("\t");
    Serial_print_i(value);
    Serial_println();
  }
}
