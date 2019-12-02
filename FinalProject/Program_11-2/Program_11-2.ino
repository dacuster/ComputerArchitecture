// Program 11.2
// Arduino Uno Blink Program in AVR Assembly
// Copyright (c) 2017 Hall & Slonka

#define LEDPort PORTB           // Arduino pin 13 is bit 5 of port B
#define LEDPort_Direction DDRB  // DDRB is the port B direction register (0=input, 1=output)
#define LEDBit 5                // Constant for bit 5
#define Clock_MHz 16
#define MicroSec 1000000
#define DelayTime (uint32_t)((Clock_MHz * MicroSec / 5))  // set to any rate desired
unsigned long timer = 0;
uint8_t clockByte = 0;

void setup() {         // same as pinMode(13, OUTPUT) 
  asm volatile (       // shows default parameter use instead of our defines/names
    "sbi %0, %1 \n\t"  // sets port and bit direction
    : : "I" (_SFR_IO_ADDR(DDRB)), "I" (DDB5) // I: 6-bit positive integer constant
  );

  Serial.begin(9600);
  //clock_prescale_set((clock_div_t)3);
  //clockByte = clock_prescale_get();

  //Serial.println(clock_prescale_get());
}

void loop() {
  timer = millis();
  asm volatile (
     " mainLoop: "                         // move DelayTime to registers
     "    mov r16, %D3  \n\t"              // LSB of DelayTime
     "    mov r17, %C3  \n\t"              // A2, B2, C2, D2 each is 8 bits
     "    mov r18, %B3  \n\t"
     "    mov r19, %A3  \n\t"              // MSB of DelayTime
     "    mov r20, %D3  \n\t"
     "    mov r21, %C3  \n\t"
     "    mov r22, %B3  \n\t"
     "    mov r23, %A3  \n\t"
     "    sbi %[port], %[ledbit] \n\t"     // set I/O bit (turn LED on)
     " onLoop: "
     "    subi r23, 1  \n\t"       // subtract constant from register
     "    sbci r22, 0  \n\t"       // subtract with carry constant from register
     "    sbci r21, 0  \n\t"
     "    sbci r20, 0  \n\t"
     "    brcc onLoop  \n\t"               // branch if carry cleared
     "    cbi  %[port], %[ledbit] \n\t"    // clear I/O bit (turn LED off)
     " offLoop:"
     "    subi r19, 1  \n\t"
     "    sbci r18, 0  \n\t"
     "    sbci r17, 0  \n\t"
     "    sbci r16, 0  \n\t"
     "    brcc offLoop \n\t"
     : "=r" (clockByte)                                    // no output variables
     : [port] "n" (_SFR_IO_ADDR(LEDPort)), // input variables
       [ledbit] "n" (LEDBit),              // n: integer with known value
       "d" (DelayTime)                     // d: greater than r15
     : "r16","r17","r18","r19","r20","r21","r22","r23"  // clobbers
     );
     Serial.println(clockByte);
}
