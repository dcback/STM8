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
#include <I2C.h>
#include <LiquidCrystal_I2C.h>

// The PCF8574 exists in three variants using two different I2C address ranges:
// PCF8574 and PCF8574T (most common): 0x20..0x27, typ. 0x27
// PCF8574A: 0x38..0x3f, typ. 0x3f

LiquidCrystal_I2C(lcd, 0x3F, 16, 2);

void setup()
{
  lcd_begin();      // initialize the LCD

  lcd_backlight();  // Turn on the blacklight and print a message.
  lcd_print_s("Hello, world!");
}

void loop()
{
  lcd_setCursor(0, 1);
  lcd_print_s("Counter :");
  lcd_print_u(millis() / 1000);
}
