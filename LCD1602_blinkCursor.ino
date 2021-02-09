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
#include <I2C.h>
#include <LiquidCrystal_I2C.h>

// The PCF8574 exists in three variants using two different I2C address ranges:
// PCF8574 and PCF8574T (most common): 0x20..0x27, typ. 0x27
// PCF8574A: 0x38..0x3f, typ. 0x3f

LiquidCrystal_I2C(lcd, 0x3F, 16, 2);

void setup()
{
  lcd_begin();      // initialize the LCD
}

void loop()
{
  bool blinking = true;
  lcd_cursor();

  while (1) {
    if (blinking) {
      lcd_clear();
      lcd_print_s("No cursor blink");
      lcd_noBlink();
      blinking = false;
    } else {
      lcd_clear();
      lcd_print_s("Cursor blink");
      lcd_blink();
      blinking = true;
    }
    delay(4000);
  }
}
