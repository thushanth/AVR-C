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

{Source: Microchip - https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-45154-Product-Selection-Guide_Brochure.pdf}

--- 

### Pin Configurations
- ATMEGA328P-PU

![Pinout-Diagram-1-2047x2048-3137328113](https://github.com/thushanth/AVR-C/assets/9505927/d6a9b536-2294-4190-871c-54d54d7896cf)

{Source: Arduino.cc - docs.arduino.cc/retired/boards/arduino-uno-rev3-with-long-pins}

- ATMEGA32L

![Screenshot 2023-07-19 130412](https://github.com/thushanth/AVR-C/assets/9505927/32e3f417-9fbe-450a-b01b-69d2741e4d78)

{Source: Ibrar Ayyub - https://atmega32-avr.com/atmega-32-pinout/}

- ATMEGA168

![arduino-vs-atmega168-chip-pinouts](https://github.com/thushanth/AVR-C/assets/9505927/3dbf903b-cb61-4bb5-af0f-023ce7111475)

{Source: Christophe VG - https://christophe.vg/technology/ATMEGA168}

---

### AVR Product Line UP

AVR Offers their microcontrollers from the family range from small 8-bit to larger 32-bit ARM based products. 
- We are only focusing on 8-bit microcontrollers in this repo. 
- For 32 bit we switch to STMicro in another repo.

AVR 8-bit are organized as the following
TINYAVR :arrow_forward: MEGAAVR :arrow_forward: XMEGAAVR

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
|             | SAMC V71  |

---

### Functionalities & Features
- ATmega328P-PU
	- Low Power CMOS 8-bit Microcontroller
	- RISC 
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
	- -40 to 85c

---

### Architecture
- ATmega328P-PU

![Pasted image 20230709213944](https://github.com/thushanth/AVR-C/assets/9505927/6eae0da0-f2d3-4490-b49e-3a6ef4af2c1e)

{Source: Microchip Datasheet}


![Pasted image 20230709214009](https://github.com/thushanth/AVR-C/assets/9505927/6590e58f-702b-4c93-a5d7-66aac6006b06)

{Source: Microchip Datasheet}

---

### Status Register

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

### External Interrupts Examples
- Example 4: Interrupt with LEDs
  
---

### UART Examples
- Example 5: UART to PC FTDI
- HC-05 ZS-040 Bluetooth

---

### ADC Examples
- Example 13: LCD with Potentiometer
- Example 14: LCD with two Potentiometer
- Example 15: LCD with LDR
- Heart Beat Sensor
- Example 16: LCD with 4x4 Keypad
- Measure Temperature Internal
- Measure Temperature with NTC

---

### Analog Comparator Examples
- Analog Comparator with interrupt

---

### On-Board EEPROM Examples
- 

---

### Timers and Counter Examples
- Measuring Frequency and DUT with timer input capture

---

### Timer CTC Mode and Input Capture Examples
- 

---

### Timer PWM Examples
- Example 17: PWM L298N DC MOTOR
- Example 18: PWM Servo
- Example 19: LCD with HC-SR04 Ultrasonic Distance Sensor
- Example 20: LCD with Encoder
- Example 21: DHT11 with LCD
- Servo PWM {Pot Position Control, Continous rotation, }
- Buzzer Active PWM
- Rotary Encoder PWM

---

### Watchdog Timer Examples
- 

---

### Low Power Mode Examples
- 

---

### SPI Examples
- 8x8 dot matrix led with max7219
- MicroSD Card
- SPI USB
- SPI Ethernet
- SPI MCU to MCU {with and without interrupts}
- SPI Flash Memory
- SPI Registers


---

### I2C Examples
- 1602 LCD Backup
- I2C Address Scanner
- BME180
- HMC5883L
- INA219
- PCA8685
- DS1307
- EEPROM
- VL530LX TOF Sensor I2C
- I2C or TWI Registers settings (Interrupts)

---

### Graphic LCD Examples 
- SPI LCD
- LCD I2C
- OLED LCD


PIC16f887A (PIC), STM32F401RE (ARMv7), FPGA?? {Xilinx AMD, Microchip FirePolar, Altera Intel}
