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
void setup() {
  Serial_begin(9600);
  delay(1000);
  Serial_println_s("[ASCII Table ~ Character Map]");  // prints title with ending line break

  while (!Serial)
  {
    ;     // wait for serial port to connect. Needed for native USB port only
  }
}

int thisByte = 33;    // = !
// first visible ASCIIcharacter '!' is number 33:
// you can also write ASCII characters in single quotes.
// for example, '!' is the same as 33, so you could also use this:
// int thisByte = '!';

void loop() {
  // prints value unaltered, i.e. the raw binary version of the byte.
  // The Serial Monitor interprets all bytes as ASCII, so 33, the first number,
  // will show up as '!'
  Serial_write(thisByte);

  Serial_print_s(", dec: ");
  Serial_print_ub(thisByte, DEC); // prints value as string in decimal (base 10):
  Serial_print_s(" ");
  Serial_print_i(thisByte);
  // prints value as string as an ASCII-encoded decimal (base 10).
  // Decimal is the default format for Serial.print() and Serial.println(),
  // so no modifier is needed:

  Serial_print_s(", hex: ");
  Serial_print_ub(thisByte, HEX); // prints value as string in hexadecimal (base 16):

  Serial_print_s(", oct: ");
  Serial_print_ub(thisByte, OCT); // prints value as string in octal (base 8);

  Serial_print_s(", bin: ");
  Serial_println_ub(thisByte, BIN); // prints value as string in binary (base 2) also prints ending line break:

  // if printed last visible character '~' or 126, stop:
  if (thisByte == 126)  // you could also use if (thisByte == '~') {
  {
    // This loop loops forever and does nothing
    while (true)
    {
      continue;
    }
  }
  thisByte++;   // go on to the next character
}
