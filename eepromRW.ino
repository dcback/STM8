/* https://github.com/tenbaht/sduino/tree/development/sduino/stm8/libraries/EEPROM
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
