/*
  https://github.com/dcback/STM8/blob/master/stm8_pinout.png
  https://github.com/tenbaht/sduino/tree/development/sduino/stm8/libraries/Generic_Examples/examples
  [STM8 Pinout]
  PA1=0 PA2=1 PA3=2 PB5=3 PB4=4  PC3=5 PC4=6=A0 PC5=7 PC6=8 PC7=9 PD1=10 PD2=11=A1 PD3=12=A2 PD4=13 PD5=14=A3=TX PD6=15=A4=RX
  No #include <Serial.h> run ok, 5=PD5=TX, 6=PD6=RX
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
