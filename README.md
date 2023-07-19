### Microcontrollers covered

- :heavy_exclamation_mark: ATMEGA328P-PU, AVRC Example Codes [WIP] 

- :registered: ATMEGA32L, AVRC Example Codes [Scheduled] 

- :registered: ATMEGA168-20PU, AVRC Example Codes [Scheduled] 

##### Legend
:heavy_exclamation_mark:[WIP] :registered:[Scheduled] :copyright:[Completed]

---

### Recommended AVR Microcontrollers
| Family  | Part #      | I/Os | Flash (KB) | SRAM (B) | EEPROM (B) | ADC      | Features                         |
| ------- | ----------- | ---- | ---------- | -------- | ---------- | -------- | -------------------------------- |
| TinyAVR | ATTINY44A   | 12   |      4     |    256   |     256    | 8x10 bit | Qtouch, Diff ADC, Gain Stage     |
| TinyAVR | ATTINY45    | 6    |      4     |    256   |     256    | 4x10 bit | High Speed, Diff ADC, Gain Stage |
| MegaAVR | ATMEGA328PB | 27   |     32     |    2K    |     1K     | 8x10 bit |                  		  |
| MegaAVR | ATMEGA32A   | 32   |     32     |    2K    |     1K     | 8x10 bit | 16-bit timer, Low cost, Qtouch   |
| MegaAVR | ATMEGA168PB | 27   |     16     |    1K    |     512    | 8x10 bit |                                  |

{ Source: Microchip - https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-45154-Product-Selection-Guide_Brochure.pdf }

Note: Qtouch is an added feature for capacitive touch screens, Microchip provides the library allowing easier implementation in terms of code for these devices.

--- 

### Pin Configurations
- ATMEGA328P-PU

![Pinout-Diagram-1-2047x2048-3137328113](https://github.com/thushanth/AVR-C/assets/9505927/d6a9b536-2294-4190-871c-54d54d7896cf)

{ Source: Arduino.cc - https://docs.arduino.cc/retired/boards/arduino-uno-rev3-with-long-pins }

- ATMEGA32L

![Screenshot 2023-07-19 130412](https://github.com/thushanth/AVR-C/assets/9505927/32e3f417-9fbe-450a-b01b-69d2741e4d78)

{ Source: Ibrar Ayyub - https://atmega32-avr.com/atmega-32-pinout/ }

- ATMEGA168

![arduino-vs-atmega168-chip-pinouts](https://github.com/thushanth/AVR-C/assets/9505927/3dbf903b-cb61-4bb5-af0f-023ce7111475)

{ Source: Christophe VG - https://christophe.vg/technology/ATMEGA168 }

---

### AVR Product Line UP

AVR Offers their microcontrollers from the family range from small 8-bit to larger 32-bit ARM based products. 
- We are only focusing on 8-bit microcontrollers in this repo. 
- For 32 bit we switch to STMicro in another repo.

AVR 8-bit are organized as the following

TinyAVR :arrow_forward: MegaAVR :arrow_forward: XmegaAVR

AVR 32-bit ARM Based MCU
| Architeture | Models    |
| ----------- | --------- |
| CORTEX M0   | SAMD10    |
|             | SAMD11    |
|             | SAMD20    |
|             | SAMD21    |
|             | SAML21/22 |
|             | SAMC20/21 |
| CORTEX M4   | SAM4N     |
|             | SAM4S     |
|             | SAM4E     |
|             | SAM4L     |
|             | SAM G     |
| CORTEX M7   | SAM S70   |
|             | SAM E70   |
|             | SAM V70   |
|             | SAM V71   |

![Screenshot 2023-07-19 144504](https://github.com/thushanth/AVR-C/assets/9505927/7990b6cd-b8f8-4648-aa7d-4e93996aaeca)

---

### Functionalities & Features
The AVR Microcontrollers have common features and functionalities throughout their 8-bit microcontroller product line. Due to space and cost contrainst, some MCU will not have certain functionalities. One can access the full list of features from the MCU by accessing the datasheet. 
The bottom lists features and functionality is listed below for the ATmega328P-PU. This information can be found from the datasheet related to the part on page 1. 

{ Source: https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf }

- ATmega328P-PU
	- Low Power CMOS 8-bit Microcontroller
	- RISC {Reduced Insturction Set Computer}
	- 32x8 General Purpose Registers
	- 20 MIPS at 20 MHz
	- 32Kbytes of flash program memory
	- 1Kbytes EEPROM
	- 2Kbytes SRAM
	- 2x 8-Bit Timers/Counters
	- 1x 16-Bit Timer/Counter
	- 6x PWM Channels
	- 6x 10-bit ADC {DIP} 8x 10-bit ADC {TQFP}
	- USART
	- SPI
	- I2C or TWI
	- Watchdog Timer
	- Analog Comparator
	- Interrupt and Wake-up on Pin Change
	- Power-on Reset, Brown-out Detection
	- Internal Oscillator
	- External Oscillator 
	- 6 sleep modes {Idle, ADC Noise Reduction, Power-save, Power-down, Standby, and Extended Standby}
	- 23 I/O
	- 1.8 - 5v {set brown out accordingly}
	- Operating Temperature range: -40 to 85c

---

### Architecture
The following images below are used to explain or give a general idea of how the AVR architecture is to be structured. Having this insight allows for deeper understanding of how the internal of the MCU works. 

Q: What is a Microcontroller?
A: Contains a microprocessor (calculator) and pheripherals. Weaker computation and storage size to a microcomputer. 
	Eg. Raspberry Pi -> Microcomputer, Arduino, ESP -> Microcontroller

- ATmega328P-PU

(Block Diagram - Page 6 of datasheet)

![Pasted image 20230709213944](https://github.com/thushanth/AVR-C/assets/9505927/6eae0da0-f2d3-4490-b49e-3a6ef4af2c1e)

(AVR CPU Core - Page 9 of datasheet)

![Pasted image 20230709214009](https://github.com/thushanth/AVR-C/assets/9505927/6590e58f-702b-4c93-a5d7-66aac6006b06)

{ Source: Microchip - https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-45154-Product-Selection-Guide_Brochure.pdf }

![Architecture_Diagram](https://github.com/thushanth/AVR-C/assets/9505927/c2cf89fb-8ce1-438e-81f1-6d52531d03a6)

This image has two sections highligted in Blue for the program memory and orange for the data memory. 
When uploading your code, the program memory will handle your complied code that is converted from C language to Intel Hex binary file.
When executing your code, the data memory will process the code from the program memory and execute the required functions and call the required pheripherals. 


---

### Status Register

    [ I , T, H, S, V, N, Z, C]

- I: Global Interrupt
- T: Bit Copy Storage
- H: Half carry Flag
- S: Sign Bit
- V: Two's Complement Overflow Flag
- N: Negative Flag
- Z: Zero Flag
- C: Carry Flag

---

### Flash Memory {Program and Bootloader}

---

### Registers {8-bit General registers, Special registers, and SRAM}

---

### EEPROM

---

### Fuses

---

### Lock Bits

---

### Clock Configurations

---

### Programming Methods {SPI, Parallel, Bit-Bang, JTAG, SWDIO}

---

### ATMEL Studio Config, AVRDUDESS, SinaProg

---

### General Purpose Input/Output Registers
AVR Microcontrollers are organized as banks. A bank can be the size of 8 gpios. When looking at the memory organization of the microcontroller we can see if the data is processed byte-wise, we can fit 8 bits. Each bit in this array will act as a control setting for the pins to be configured. Hence if you read further into the documentation, a common rereferenceing of registers appears. E.g. I2C/TWI Registers.

These registers are powerful, allowing the programmer to choose what functionality a pheripheral or pin can do via these settings.

The register settings are organzied as DDRx, PORTx and PINx. Where X is replaced by the channel we which to work with. 
DDR is used to set the direction of the pins, if DDRB is set to 11111111, all 8 pins of port B are set as outputs. 

    [ 7, 6, 5, 4 , 3, 2, 1, 0]

E.g. DDRD = 0xFB -> PORTD has 8 bits on the atmega328P, looking at the Pin Configurations above we see on an arduino uno that uses the same IC, PORTD is pin D0-D7.
1111 1011 is the binary form of the hex value FB. We can say all the pins of PORTD are outputs expect for the third one, which is set to input. (We read from right to left)
This input pin corresponds to the third pin on PORTD which is D2. 
Most significant Bit is the left side, Least Significant bit is the right side. Most significant corresponds to PD7 or the highest for the that PORT. Least is for PD0, or whichever port you use.

Now PORT is reffered as the group of pins and also used to set the status of if the data is HIGH or LOW on that pin. 
E.g. digitalWrite(D3, HIGH); -> DDRD = 0x08; or DDRD = 0b00001000; followed by PORTD = 0xFF; This states the output is active HIGH, 5v. If you have 0x00; all the 8 pins on that port can be configured to be 0v or active low. 

PIN registers a 8 bit register that contains the status of the port, perfect for using to read and compare the status of the pin.
e.g. value = digitalRead(D3); DDRD = 0xF7; D3 is low or set as input. Then value = PINB; then check the fourth bit or use value = PINB & (1 << PINB4); 

I leave the responsibility to you for looking into the datatype to handle the data.

---

### GPIO Examples
- Example 1: Blinking an LED
- Example 2: LED Strobe for LED Bar
- Example 3: Push Button for LED Bar
- Example 6: Relay SPDT with LEDs
- Example 7: Relay SPDT with Motor
- Example 8: Dot Matrix 
- Example 9: Three Digit - Seven Segment LCD
- Example 10: Stepper Motor A4988 {Revisit - DRV8825 and TMC modules}
- Example 11: LCD 1602
- Example 12: 4x4 Keypad Matrix
- Example n: DC Motor L298N NON-PWM
- IR Line Following Sensor (Single & Array)
- HC-SR04 with LCD Range finding
- DHT22 

---

### Interrupt Registers

---

### External Interrupts Examples
- Example 4: Interrupt with LEDs
- UART Interrupt
  
---

### USART Registers 

---

### UART Examples
- Example 5: AVR to PC - FTDI
- PC to LCD
- PC to AVR and back to PC
- HC-05 ZS-040 Bluetooth

---

### ADC Registers

---

### ADC Examples
- Example 13: LCD with Potentiometer (Single ADC)
- Example 14: LCD with two Potentiometer (Multichannel ADC)
- LCD with two Potentiometer (Differential ADC)
- Example 15: LCD with LDR (Single ADC)
- Heart Beat Sensor
- Example 16: LCD with 4x4 Keypad (Interrupt)
- Measure Temperature Internal
- Measure Temperature with NTC

---

### Analog Comparator Registers

---

### Analog Comparator Examples
- Analog Comparator with interrupt (two POTs and LED)

---

### Internal EEPROM Registers 

---

### On-Board EEPROM Examples
- EEPROM with LCD

---

### Timer Registers

---

### Timers and Counter Examples
- Timer0 Interrupt
- Timer0 Counter with PB counting pulses
- Timer0 Delay
- Timer1 as timer
- Timer1 as counter
- Timer1 as overflow interrupt
- Measuring Frequency and DUT with timer input capture

---

### Timer CTC Mode and Input Capture Examples
- 50% DUT square wave timer0 8 bit
- CTC Variable DUT timer0 8 bit
- CTC with Interrupt timer0 8 bit

- 50% DUT square wave timer1 16 bit
- CTC Variable DUT timer1 16 bit
- CTC with Interrupt timer1 16 bit
- CTC with CHA and CHB Timer 1 Variable DUT with interrupt

- PB, SPDT, LED to PC with interrupt
- Stopwatch between two events
- Measuring Frequency and Duty Cycle of input square wave

---

### Timer Registers (Con't)

---

### Timer PWM Examples
- LED FADE
- Example 17: PWM L298N DC MOTOR
- Example 18: PWM Servo
- Example 19: LCD with HC-SR04 Ultrasonic Distance Sensor
- Example 20: LCD with Encoder
- Example 21: DHT11 with LCD
- Servo PWM {Pot Position Control, Continous rotation, }
- Buzzer Active PWM
- Rotary Encoder PWM

---

### WatchDog Registers

---

### Watchdog Timer Examples
- LED with MCU Reset

---

### Low Power Registers 

---

### Low Power Mode Examples
- Idle Mode
- Power Down Mode

---

### SPI Registers

---

### SPI Examples
- 8x8 dot matrix led with max7219
- MicroSD Card
- SPI USB
- SPI Ethernet
- SPI MCU to MCU {with and without interrupts}
- SPI Flash Memory NOR

---

### I2C/TWI Registers

---

### I2C Examples
- 1602 LCD Backup
- I2C Address Scanner
- BME180 Barometeric Pressure sensor
- HMC5883L - 3 axis Gyro
- INA219 Current Sensor
- PCA8685 GPIO Expander
- DS1307 RTC
- EEPROM (External)
- VL530LX TOF Sensor I2C

---

### Graphic LCD Examples 
- SPI LCD
- LCD I2C
- OLED LCD

---

### TO DO IN NEW REPO 
PIC16f887A (PIC), STM32F401RE (ARMv7), FPGA?? {Xilinx AMD, Microchip FirePolar, Altera Intel}
