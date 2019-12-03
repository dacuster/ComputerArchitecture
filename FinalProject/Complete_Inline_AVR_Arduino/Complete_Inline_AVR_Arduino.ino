/******************************************
**  Author: Nick DaCosta                 **
**  Class: CSI 370-01                    **
**  Professor: Brian R. Hall             **
**  Assignment: Final Project            **
**  Description: 4x4x4 LED Cube Effects  **
******************************************/

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

/******************************
**  INLINE ASSEMBLY (START)  **
******************************/
asm volatile
(
  /***************************
  **  DATA SEGMENT (START)  **
  ***************************/
  ".data \n\t"

  // Create variable for clock delay timer.
  // Uno uses clock prescaler of 1.
  // At 16MHz with prescaler of 1, ~3963 cycles occur in 1 millisecond.
  ".equ clockCycleCounter, 3963 \n\t"

  // Set global delay time.
  ".equ globalDelayTime, 250 \n\t"

  // Data Direction Register Addresses.
  ".equ DDRD, 0x0A \n\t"
  ".equ DDRB, 0x04 \n\t"
  ".equ DDRC, 0x07 \n\t"

  // Port Register Addresses.
  ".equ PORTD, 0x0B \n\t"
  ".equ PORTB, 0x05 \n\t"
  ".equ PORTC, 0x08 \n\t"
  /***************************
  **  DATA SEGMENT (START)  **
  ***************************/

  /***************************
  **  CODE SEGMENT (START)  **
  ***************************/
  ".text \n\t"
  
  // List all global subroutines.
  ".globl setup, loop \n\t"

  /*******************************
  **  SETUP SUBROUTINE (START)  **
  *******************************/
  // Needed for Arduino build if using complete inline asm.
  "setup: \n\t"

    // Call port setup subroutine.
    "call setPortDirections \n\t"
  /*****************************
  **  SETUP SUBROUTINE (END)  **
  *****************************/

  /******************************
  **  LOOP SUBROUTINE (START)  **
  ******************************/
  // Needed for Arduino build if using complete inline asm.
  "loop: \n\t"

    // Turn everything off.
    "call turnEverythingOff \n\t"
    
    // Flicker everything on.
    "call flickerOn \n\t"

    // Turn everything on.
    "call turnEverythingOn \n\t"

    // Load global delay time.
    "ldi XL, lo8(globalDelayTime) \n\t"
    "ldi XH, hi8(globalDelayTime) \n\t"

    // Delay
    "call delay \n\t"

    // Turn all the columns off.
    "call turnColumnsOff \n\t"

    // Toggle layers up and down
    "call toggleLayersUpAndDown \n\t"











    
    
    // Delay for 1000 milliseconds.
    //"ldi XL, lo8(0x03E8) \n\t"
    //"ldi XH, hi8(0x03E8) \n\t"

    //"call delay \n\t"

    // Turn everything on.
    //"call turnEverythingOn \n\t"

    // Delay for 1000 milliseconds.
    //"ldi XL, lo8(0x03E8) \n\t"
    //"ldi XH, hi8(0x03E8) \n\t"

    //"call delay \n\t"

    // Jump back to the beginning of this loop.
    "jmp loop \n\t"
  /****************************
  **  LOOP SUBROUTINE (END)  **
  ****************************/

  /********************************************
  **  SET PORT DIRECTION SUBROUTINE (START)  **
  ********************************************/
  // Set all the port directions to output.
  "setPortDirections: \n\t"

    // Push registers used by subroutine before proceeding.
    "push r24 \n\t"

    // Load bitmask for data registers B and C as all output. (0b00111111 = 63 = 0x3F)
    "ldi r24, 0x3F \n\t"

    // Set the direction of data registers B and C. (0x04 and 0x07)
    "out DDRB, r24 \n\t"
    "out DDRC, r24 \n\t"

    // Load bitmask for data register D as all output. (0b11111111 = 255 = 0xFF)
    "ldi r24, 0xFF \n\t"

    // Set the direction of data register D. (0x0a)
    "out DDRD, r24 \n\t"

    // Pop registers before returning to caller.
    "pop r24 \n\t"

    // Return to caller.
    "ret \n\t"
  /******************************************
  **  SET PORT DIRECTION SUBROUTINE (END)  **
  ******************************************/

  /*********************************************
  **  TURN EVERYTHING OFF SUBROUTINE (START)  **
  *********************************************/
  // Turn off all the leds.
  "turnEverythingOff: \n\t"

    // Push registers used by subroutine before proceeding.
    "push r24 \n\t"

    // Load bitmask for port D. (0b11111100 = 252 = 0xFC)
    "ldi r24, 0xFC \n\t"

    // Set the bitmask of port D. (0x0b)
    "out PORTD, r24 \n\t"

    // Load bitmask for port B. (0b00111111 = 63 = 0x3F)
    "ldi r24, 0x3F \n\t"

    // Set the bitmask for port B. (0x05)
    "out PORTB, r24 \n\t"

    // Load bitmask for port C. (0b00110110 = 54 = 0x36)
    "ldi r24, 0x36 \n\t"

    // Set the bitmask for port C. (0x08)
    "out PORTC, r24 \n\t"

    // Pop registers before returning to caller.
    "pop r24 \n\t"

    // Return to caller.
    "ret \n\t"
  /*******************************************
  **  TURN EVERYTHING OFF SUBROUTINE (END)  **
  *******************************************/

  /********************************************
  **  TURN EVERYTHING ON SUBROUTINE (START)  **
  ********************************************/
  // Turn on all the leds.
  "turnEverythingOn: \n\t"

    // Push registers used by subroutine before proceeding.
    "push r24 \n\t"

    // Load bitmask for port D. (0b00000011 = 3 = 0x03)
    "ldi r24, 0x03 \n\t"

    // Set the bitmask of port D. (0x0b)
    "out PORTD, r24 \n\t"

    // Load bitmask for port B. (0b00000000 = 0 = 0x00)
    "ldi r24, 0x00 \n\t"

    // Set the bitmask for port B. (0x05)
    "out PORTB, r24 \n\t"

    // Load bitmask for port C. (0b00001001 = 9 = 0x09)
    "ldi r24, 0x09 \n\t"

    // Set the bitmask for port C. (0x08)
    "out PORTC, r24 \n\t"

    // Pop registers before returning to caller.
    "pop r24 \n\t"

    // Return to caller.
    "ret \n\t"
  /******************************************
  **  TURN EVERYTHING ON SUBROUTINE (END)  **
  ******************************************/

  /*****************************************
  **  TURN COLUMNS ON SUBROUTINE (START)  **
  *****************************************/
  // Set columns so LEDs can be turned off.
  // Columns are connected to cathode of LEDs
  // so the columns should be turned on.
  "turnColumnsOn: \n\t"

    // Push registers used by subroutine before proceeding.
    "push r24 \n\t"

    // Load bitmask for port D. (0b11111100 = 252 = 0xFC)
    "ldi r24, 0xFC \n\t"

    // Get the current PORTD bitmask.
    "in r24, PORTD \n\t"

    // Logical OR the current bitmask with the new bitmask (0b11111100 = 252 = 0xFC)
    "ori r24, 0xFC \n\t"

    // Set the bitmask of port D. (0x0b)
    "out PORTD, r24 \n\t"

    // Load bitmask for port B. (0b00111111 = 63 = 0x3F)
    //"ldi r24, 0x3F \n\t"

    // Get the current PORTB bitmask.
    "in r24, PORTB \n\t"

    // Logical OR the current bitmask with the new bitmask (0b00111111 = 63 = 0x3F)
    "ori r24, 0x3F \n\t"

    // Set the bitmask for port B. (0x05)
    "out PORTB, r24 \n\t"

    // Load bitmask for port C. (0b00110110 = 54 = 0x36)
    //"ldi r24, 0x36 \n\t"

    // Get the current PORTC bitmask.
    "in r24, PORTC \n\t"

    // Logical OR the current bitmask with the new bitmask (0b00110110 = 54 = 0x36)
    "ori r24, 0x36 \n\t"

    // Set the bitmask for port C. (0x08)
    "out PORTC, r24 \n\t"

    // Pop registers before returning to caller.
    "pop r24 \n\t"

    // Return to caller.
    "ret \n\t"
  /***************************************
  **  TURN COLUMNS ON SUBROUTINE (END)  **
  ***************************************/

  /******************************************
  **  TURN COLUMNS OFF SUBROUTINE (START)  **
  ******************************************/
  // Set columns so LEDs can be turned on.
  // Columns are connected to cathode of LEDs
  // so the columns should be turned off.
  "turnColumnsOff: \n\t"

    // Push registers used by subroutine before proceeding.
    "push r24 \n\t"

    // Get the current PORTD bitmask.
    "in r24, PORTD \n\t"

    // OR then AND result to keep certain bits on and turn others off.
    // Logical OR the current bitmask with the new bitmask. (0b11111100 = 252 = 0xFC)
    "ori r24, 0xFC \n\t"

    // Logical AND the current bitmask with the new bitmask. (0b00000011 = 3 = 0x03)
    "andi r24, 0x03 \n\t"

    // Set the bitmask of port D. (0x0b)
    "out PORTD, r24 \n\t"

    // Load the new bitmask for PORTB. (0b00000000 = 0 = 0x00)
    "out PORTB, 0x00 \n\t"

    // Get the current PORTC bitmask.
    "in r24, PORTC \n\t"

    // Logical OR the current bitmask with the new bitmask. (0b11110110 = 246 = 0xF6)
    "ori r24, 0xF6 \n\t"

    // Logical AND the current bitmask with the new bitmask. (0b00001001 = 9 = 0x09)
    "andi r24, 0x09 \n\t"

    // Set the bitmask for port C. (0x08)
    "out PORTC, r24 \n\t"

    // Pop registers before returning to caller.
    "pop r24 \n\t"

    // Return to caller.
    "ret \n\t"
  /****************************************
  **  TURN COLUMNS OFF SUBROUTINE (END)  **
  ****************************************/

  /****************************************
  **  TOGGLE LAYERS UP AND DOWN (START)  **
  ****************************************/
  // Turn all layers on and off up and down cube.
  "toggleLayersUpAndDown: \n\t"

    // Push all registers being used in this subroutine.
    "push r16 \n\t"
    "push r17 \n\t"
    "push r18 \n\t"
    "push r19 \n\t"
    "push r20 \n\t"
    "push r21 \n\t"

    // Load delay time for each loop. (75ms = 0x4B)
    "ldi r16, 0x4B \n\t"

    // Turn all the leds off.
    "call turnEverythingOff \n\t"

    // Turn all the columns off so the LEDs can be turned on.
    "call turnColumnsOff \n\t"

    // Load the main loop counter. (5 loops)
    "ldi r17, 0x05 \n\t"

    // Load the current PORTD bitmask.
    "in r18, PORTD \n\t"
    
    // Load the current PORTC bitmask.
    "in r19, PORTC \n\t"

    // Start the main loop.
    "startLayerLoop: \n\t"

      // Load the bottom up loop counter. (2 loops)
      "ldi r20, 0x02 \n\t"

      // Toggle layers starting at bottom.
      "layerBottomUpLoop: \n\t"

        // Toggle layer 0 (bottom). Pin D0 (PORTD bit 0) bitmask = 0b00000001 = 1 = 0x01
        "ldi r21, 0x01 \n\t"
        "eor r18, r21 \n\t"

        // Load new bitmask into PORTD.
        "out PORTD, r18 \n\t"

        // Load the layer delay time into the X register and delay.
        "ldi XL, lo8(0x4B) \n\t"
        "ldi XH, hi8(0x4B) \n\t"
        "call delay \n\t"

        // Toggle layer 1 (2nd from bottom). Pin D1 (PORTD bit 1) bitmask = 0b00000010 = 2 = 0x02
        "ldi r21, 0x02 \n\t"
        "eor r18, r21 \n\t"

        // Load new bitmask into PORTD.
        "out PORTD, r18 \n\t"

        // Load the layer delay time into the X register and delay.
        "ldi XL, lo8(0x4B) \n\t"
        "ldi XH, hi8(0x4B) \n\t"
        "call delay \n\t"

        // Toggle layer 2 (2nd from top). Pin A0 (PORTC bit 0) bitmask = 0b00000001 = 1 = 0x01
        "ldi r21, 0x01 \n\t"
        "eor r19, r21 \n\t"

        // Load new bitmask into PORTC.
        "out PORTC, r19 \n\t"

        // Load the layer delay time into the X register and delay.
        "ldi XL, lo8(0x4B) \n\t"
        "ldi XH, hi8(0x4B) \n\t"
        "call delay \n\t"

        // Toggle layer 3 (top). Pin A3 (PORTC bit 3) bitmask = 0b00001000 = 8 = 0x08
        "ldi r21, 0x08 \n\t"
        "eor r19, r21 \n\t"

        // Load new bitmask into PORTC.
        "out PORTC, r19 \n\t"

        // Load the layer delay time into the X register and delay.
        "ldi XL, lo8(0x4B) \n\t"
        "ldi XH, hi8(0x4B) \n\t"
        "call delay \n\t"

        // Decrement the loop timer.
        "dec r20 \n\t"

        // Branch back to beginning of layer up loop if zero flag isn't set.
        "brne layerBottomUpLoop \n\t"

      // Load the top down loop counter. (2 loops)
      "ldi r20, 0x02 \n\t"

      // Toggle layers starting at top.
      "layerTopDownLoop: \n\t"

        // Toggle layer 3 (top). Pin A3 (PORTC bit 3) bitmask = 0b00001000 = 8 = 0x08
        "ldi r21, 0x08 \n\t"
        "eor r19, r21 \n\t"

        // Load new bitmask into PORTC.
        "out PORTC, r19 \n\t"

        // Load the layer delay time into the X register and delay.
        "ldi XL, lo8(0x4B) \n\t"
        "ldi XH, hi8(0x4B) \n\t"
        "call delay \n\t"

        // Toggle layer 2 (2nd from top). Pin A0 (PORTC bit 0) bitmask = 0b00000001 = 1 = 0x01
        "ldi r21, 0x01 \n\t"
        "eor r19, r21 \n\t"

        // Load new bitmask into PORTC.
        "out PORTC, r19 \n\t"

        // Load the layer delay time into the X register and delay.
        "ldi XL, lo8(0x4B) \n\t"
        "ldi XH, hi8(0x4B) \n\t"
        "call delay \n\t"

        // Toggle layer 1 (2nd from bottom). Pin D1 (PORTD bit 1) bitmask = 0b00000010 = 2 = 0x02
        "ldi r21, 0x02 \n\t"
        "eor r18, r21 \n\t"

        // Load new bitmask into PORTD.
        "out PORTD, r18 \n\t"

        // Load the layer delay time into the X register and delay.
        "ldi XL, lo8(0x4B) \n\t"
        "ldi XH, hi8(0x4B) \n\t"
        "call delay \n\t"

        // Toggle layer 0 (bottom). Pin D0 (PORTD bit 0) bitmask = 0b00000001 = 1 = 0x01
        "ldi r21, 0x01 \n\t"
        "eor r18, r21 \n\t"

        // Load new bitmask into PORTD.
        "out PORTD, r18 \n\t"

        // Load the layer delay time into the X register and delay.
        "ldi XL, lo8(0x4B) \n\t"
        "ldi XH, hi8(0x4B) \n\t"
        "call delay \n\t"

        // Decrement the loop timer.
        "dec r20 \n\t"

        // Branch back to beginning of layer up loop if zero flag isn't set.
        "brne layerTopDownLoop \n\t"

      // Decrement main loop timer.
      "dec r17 \n\t"

      // Branch to the beginning of the main loop if the zero flag isn't set.
      "brne startLayerLoop \n\t"

    // Pop registers used in this subroutine before returning to the caller.
    "pop r21 \n\t"
    "pop r20 \n\t"
    "pop r19 \n\t"
    "pop r18 \n\t"
    "pop r17 \n\t"
    "pop r16 \n\t"

    // Return to caller.
    "ret \n\t"
  /**************************************
  **  TOGGLE LAYERS UP AND DOWN (END)  **
  **************************************/

  /************************************
  **  FLICKER ON SUBROUTINE (START)  **
  ************************************/
  // Flicker all the leds on and off.
  "flickerOn: \n\t"

    // Push any registers used in this subroutine on the stack.
    "push r26 \n\t"
    "push r27 \n\t"

    // Set delay time using X register. (150ms = 0x96)
    "ldi XL, lo8(0x96) \n\t"
    "ldi XH, hi8(0x96) \n\t"

    // Start the flicker loop.
    "flickerOnLoop: \n\t"

      // Turn everything on.
      "call turnEverythingOn \n\t"

      // Delay.
      "call delay \n\t"

      // Turn everything off.
      "call turnEverythingOff \n\t"

      // Delay.
      "call delay \n\t"

      // Subtract from the initial delay timer in the X register.
      "sbiw X, 0x05 \n\t"

      // Go back to the start of the flicker loop if the zero flag is not set.
      "brne flickerOnLoop \n\t"

    // Pop any registers used in this subroutine off the stack.
    "pop r27 \n\t"
    "pop r26 \n\t"

    // Return to the caller.
    "ret \n\t"
  /**********************************
  **  FLICKER ON SUBROUTINE (END)  **
  **********************************/

  /*************************************
  **  DELAY TIMER SUBROUTINE (START)  **
  *************************************/
  // Create millisecond delay timer.
  "delay: \n\t"

    // Push any registers being used in this timer loop.
    "push r28 \n\t"
    "push r29 \n\t"
    "push r30 \n\t"
    "push r31 \n\t"

    // Load the millisecond delay time from the Z register into the Y register.
    "movw Y, X \n\t"

    // Create delay counter loop.
    "delayCounterLoop: \n\t"

      // Subtract 1 from millisecond counter in Y register.
      "sbiw Y, 1 \n\t"

      // Jump to end of subroutine to return to caller.
      "breq delayEnd \n\t"

      // Load clock cycle counter into Z register
      "ldi ZL, lo8(clockCycleCounter) \n\t"
      "ldi ZH, hi8(clockCycleCounter) \n\t"

      // Create clock counter loop.
      "clockCounterLoop: \n\t"

        // Subtract 1 from Z register which holds the clock cycle counter.
        "sbiw Z, 1 \n\t"

        // Branch back to the clock cycle counter loop if the zero flag is not set.
        "brne clockCounterLoop \n\t"

        // Branch back to the start of the delay counter loop if the zero flag has been set.
        "breq delayCounterLoop \n\t"

    // End of the delay timer.
    "delayEnd: \n\t"

      // Pop any registers that were used in the loop.
      "pop r31 \n\t"
      "pop r30 \n\t"
      "pop r29 \n\t"
      "pop r28 \n\t"

    // Return to the caller.
    "ret \n\t"
  /***********************************
  **  DELAY TIMER SUBROUTINE (END)  **
  ***********************************/
  
  /*************************
  **  CODE SEGMENT (END)  **
  *************************/
);
/****************************
**  INLINE ASSEMBLY (END)  **
****************************/
