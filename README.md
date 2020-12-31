# Sduino 환경설정
ST-LINK V2로 Upload to TargetBoard
Start the Arduino-IDE. In File->Preferences, Settings tab, enter
https://raw.githubusercontent.com/tenbaht/sduino/master/package_sduino_stm8_index.json

as an Additional Boards Manager URL.

Open Tools->Board:...->Boards Manager
Find Sduino by typing 'sd' into the search line
Click on the list entry
Click on Install.

# STM8
The STM8S103F2/x3 access line 8-bit microcontrollers offers 8 Kbyte Flash program memory, plus integrated true data EEPROM. The STM8S microcontroller family reference manual (RM0016) refers to devices in this family as low-density. They provide the following benefits: performance, robustness, and reduced system cost.
Device performance and robustness are ensured by advanced core and peripherals made in a state-of-the art technology, a 16 MHz clock frequency, robust I/Os, independent watchdogs with separate clock source, and a clock security system.
The system cost is reduced thanks to an integrated true data EEPROM for up to 300 k write/erase cycles and a high system integration level with internal clock oscillators, watchdog and brown-out reset.
Full documentation is offered as well as a wide choice of development tools.

# Key Features
- Core
  - 16 MHz advanced STM8 core with Harvard architecture and 3-stage pipeline
  - Extended instruction set
- Memories
  - Program memory: 8 Kbyte Flash; data retention 20 years at 55 °C after 10 kcycle
  - Data memory: 640 byte true data EEPROM; endurance 300 kcycle
  - RAM: 1 Kbyte
- Clock, reset and supply management
  - 2.95 to 5.5 V operating voltage
  - Flexible clock control, 4 master clock sources
    - Low power crystal resonator oscillator
    - External clock input
    - Internal, user-trimmable 16 MHz RC
    - Internal low-power 128 kHz RC
= Clock security system with clock monitor
- Power management:
  - Low-power modes (wait, active-halt, halt)
  - Switch-off peripheral clocks individually
  - Permanently active, low-consumption power-on and power-down reset
-Interrupt management
  - Nested interrupt controller with 32 interrupts
  - Up to 27 external interrupts on 6 vectors
- Timers
  - Advanced control timer: 16-bit, 4 CAPCOM channels, 3 complementary outputs, dead-time insertion and flexible synchronization
  - 16-bit general purpose timer, with 3 CAPCOM channels (IC, OC or PWM)
  - 8-bit basic timer with 8-bit prescaler
  - Auto wake-up timer
  - Window watchdog and independent watchdog timers
- Communication interfaces
  - UART with clock output for synchronous operation, SmartCard, IrDA, LIN master mode
  - SPI interface up to 8 Mbit/s
  - I2C interface up to 400 kbit/s
- Analog to digital converter (ADC)
  -10-bit, ±1 LSB ADC with up to 5 multiplexed channels, scan mode and analog watchdog
- I/Os
  - Up to 28 I/Os on a 32-pin package including 21 high sink outputs
  - Highly robust I/O design, immune against current injection
- Unique ID
  - 96-bit unique key for each device
  
# Sduino schematic
  https://j.lnwfile.com/_/j/_raw/rw/td/8t.jpg

  
# Attiny/Sduino combo schematic
  
  
  
