//        ATMEL ATMEGA8 & 168 / ARDUINO
//
//                  +-\/-+
//            PC6  1|    |28  PC5 (AI 5)
//      (D 0) PD0  2|    |27  PC4 (AI 4)
//      (D 1) PD1  3|    |26  PC3 (AI 3)
//      (D 2) PD2  4|    |25  PC2 (AI 2)
// PWM+ (D 3) PD3  5|    |24  PC1 (AI 1)
//      (D 4) PD4  6|    |23  PC0 (AI 0)
//            VCC  7|    |22  GND
//            GND  8|    |21  AREF
//            PB6  9|    |20  AVCC
//            PB7 10|    |19  PB5 (D 13)
// PWM+ (D 5) PD5 11|    |18  PB4 (D 12)
// PWM+ (D 6) PD6 12|    |17  PB3 (D 11) PWM
//      (D 7) PD7 13|    |16  PB2 (D 10) PWM
//      (D 8) PB0 14|    |15  PB1 (D 9) PWM
//                  +----+

asm volatile
(
  // Data segment.
  ".data \n\t"
  
  // Create a Data Direction Resgister array of size 3.
  // Data Direction Registers (DDRD(0x0A), DDRB(0x04), DDRC(0x07))
  "ddrArray: .byte 3 \n\t"
  
  // Load the array pointer into the X register.
  "ldi XL, lo8(ddrArray) \n\t"
  "ldi XH, hi8(ddrArray) \n\t"

  // Store the DDR addresses in the array increasing the index after storing.
  "st X+, 0x0A \n\t"
  "st X+, 0x04 \n\t"
  "st X+, 0x07 \n\t"

  // Create a PORT array for the I/O ports.
  // Port Registers (PORTD(0x0B), PORTB(0x05), PORTC(0x08))
  "portArray: .byte 3 \n\t"

  // Load the array pointer into the X register.
  "ldi XL, lo8(portArray) \n\t"
  "ldi XH, hi8(portArray) \n\t"

  // Store the PORT addresses in the array increasing the index after storing.
  "st X+, 0x0B \n\t"
  "st X+, 0x05 \n\t"
  "st X+, 0x08 \n\t"

  // Create a bitmask array for the pinmode for each DDR.
  // Bitmasks to set pins to I/O mode. (1 = Output)
  // DDRD = D-Pins 7 , 6 , 5 , 4 , 3, 2, 1, 0
  // DDRB = D-Pins 13, 12, 11, 10, 9, 8
  // DDRC = A-Pins 5 , 4 , 3 , 2 , 1, 0
  "outputBitmaskArray: .byte 3 \n\t"

  // Load the array pointer into the X register.
  "ldi XL, lo8(outputBitmaskArray) \n\t"
  "ldi XH, hi8(outputBitmaskArray) \n\t"

  // Store the bitmask values for each DDR.
  // Values need to be 31 or less 0b00111111 = 63 and 0b11111111 = 255
  // Load into r16 first then store in the array.
  "ldi r16, 0b11111111 \n\t"
  "st X+, r16 \n\t"
  "ldi r16, 0b00111111 \n\t"
  "st X+, r16 \n\t"
  "ldi r16, 0b00111111 \n\t"
  "st X+, r16 \n\t"













  

  
  // Data Direction Register B at 0x24 (0x20 with offset 0x04)
  //".equ DDRB,   4 \n\t"
  // Pin Output Register B at 0x25 (0x20 with offset 0x05)
  //".equ PORTB,  5 \n\t"
  // Data Direction Register C at 0x27 (0x20 with offset 0x07)
  //".equ DDRC,   7 \n\t"
  // Pin Output Register C at 0x28 (0x20 with offset 0x08)
  //".equ PORTC,  8 \n\t"
  // Data Direction Register D at 0x2A (0x20 with offset 0x0A)
  //".equ DDRD,   10 \n\t"
  // Pin Output Register D at 0x31 (0x2B with offset 0x0B)
  //".equ PORTD,  11 \n\t"
  // Set everything in an array.
  // Calculate array length using .equ and current location - previous variable
  //".equ DDR, ddr \n\t"

  // ** IO operators need constant values. (.equ) **

  // Setup the output pins on DDRD.
  //".equ dOutputBitMask, 0b11111111 \n\t"
  // Setup the output pins on DDRB.
  //".equ bOutputBitMask, 0b00111111 \n\t"
  // Setup the output pins on DDRC.
  //".equ cOutputBitMask, 0b00111111 \n\t"

  //".equ testMask, 0b00010011 \n\t"

  ".text \n\t"
  ".globl setup, loop, assembly \n\t"
  "setup: \n\t"


  //"mov r16, 3 \n\t"
  //"ldi YL, lo8(testing) \n\t"
  //"ldi YH, hi8(testing) \n\t"
  //"movw r16, ddrArray \n\t"
  // Load ddr array into x-register
  //"ldi YL, low(r16) \n\t"
  //"ldi YH, high(r16) \n\t"
  
  // Load output bit mask array into y-register.
  //"lds YL, lo8(outputBitmaskArray) \n\t"
  //"lds YH, hi8(outputBitmaskArray) \n\t"
  
  // Set r17 to loop counter size of arrays.
  //"mov r17, arraySize \n\t"

















  


  // WORKING SETTING ALL PINS AS OUTPUT AND SETTING THEM BASED ON THE BITMASK PASSED TO THEM.
  //"in r16, DDRB \n\t"
  //"ori r16, bBitMask \n\t"
  //"out DDRB, r16 \n\t"
  //"in r16, PORTB \n\t"
  //"ori r16, bBitMask \n\t"
  //"out PORTB, r16 \n\t"
    
  
  
  
  //"sbi ddrb, output \n\t"
  //"sbi portb, bit5 \n\t"
  //"sbi DDRB, 5 \n\t"
  //"sbi PORTB, 5 \n\t"
  //"ldi r28, lo8(ddr + 1) \n\t"
  //"ldi r29, hi8(ddr + 1) \n\t"
  //"ld r1, x \n\t"
  //"sbi $(r1), 7 \n\t"
  //"ld r16, 0x05 \n\t"
  
  // Load in DDRB to r16.
  //"in r16, DDRB \n\t"
  // 
  //"ori r16, bBitMask \n\t"
  //"in r16, bBitMask \n\t"
  //"ori r16, testMask \n\t"
  //"out DDRB, r16 \n\t"
  //"in r16, PORTB \n\t"
  //"ori r16, testMask \n\t"
  //"out PORTB, r16 \n\t"

  




  "assembly: \n\t"
  "loop: \n\t"
);
