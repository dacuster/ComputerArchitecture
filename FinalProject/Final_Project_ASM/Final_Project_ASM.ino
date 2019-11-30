/*
  4x4x4 LED Cube
  Connection Setup:
  Columns
  [(x,y)-Pin]
  (1,1)-13
  (1,2)-12
  (1,3)-11
  (1,4)-10
  (2,1)-9
  (2,2)-8
  (2,3)-7
  (2,4)-6
  (3,1)-5
  (3-2)-4
  (3-3)-3
  (3,4)-2
  (4,1)-1
  (4,2)-0
  (4,3)-A5
  (4,4)-A4
  Layers
  [layer-Pin]
  a-A0
  b-A1
  c-A2
  d-A3
*/
// Initializing and declaring column pins.
//const uint8_t COLUMN_COUNT = 16;
//const uint8_t COLUMN[COLUMN_COUNT] = {13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, A2, A1, A5, A4};

// Initializing and declaring port direction.
//const uint8_t PORT_COUNT = 3;
//const uint8_t PORT_DIRECTION[PORT_COUNT] = {DDRB, DDRC, DDRD};

// Initializing and declaring ports.
//const uint8_t PORT[PORT_COUNT] = {PORTB, PORTC, PORTD};

//initializing and declaring led layers
//const uint8_t LAYER_COUNT = 4;
//const uint8_t LAYER[LAYER_COUNT] = {A3, A0, 1, 0};

//int time = 250;

uint8_t bPort = _SFR_IO_ADDR(DDRB);



//asm volatile
//(
//  ".data \n\t"
//  "num1: .long 2 \n\t"
//);


void setup()
{
  asm volatile
  (
    //"sbi %1, %16 \n\t" // Turn on pin 13
    //"sbi %1, %15 \n\t" // Turn on pin 12
    //"sbi %1, %14 \n\t" // Turn on pin 11
    //"sbi %1, %13 \n\t" // Turn on pin 10
    //"sbi %1, %12 \n\t" // Turn on pin 9
    //"sbi %1, %11 \n\t" // Turn on pin 8
    //"sbi %0, %10 \n\t" // Turn on pin 7
    //"sbi %0, %9 \n\t"  // Turn on pin 6
    //"sbi %0, %8 \n\t"  // Turn on pin 5
    //"sbi %0, %7 \n\t"  // Turn on pin 4
    //"sbi %0, %6 \n\t"  // Turn on pin 3
    //"sbi %0, %5 \n\t"  // Turn on pin 2
    //"sbi %0, %4 \n\t"  // Turn on pin 1
    //"sbi %0, %3 \n\t"  // Turn on pin 0
    //"sbi %2, %17 \n\t" // Turn on pin A0
    //"sbi %2, %18 \n\t" // Turn on pin A1
    //"sbi %2, %19 \n\t" // Turn on pin A2
    //"sbi %2, %20 \n\t" // Turn on pin A3
    //"sbi %2, %21 \n\t" // Turn on pin A4
    //"sbi %2, %22 \n\t" // Turn on pin A5
    //"ld r16, x   \n\t"
    //"mov %0 , r16 \n\t"
    //"ldd r16, y+1   \n\t"
    //"mov %1 , r16 \n\t"
    //"ld r16, z   \n\t"
    "mov %2 , r16 \n\t"
    //"sbi %0, %1 \n\t"
    //"sbi %0, %4 \n\t"
    //"sbi %2, %3 \n\t"
    //"sbi %2, %4 \n\t"
    "sbi 4, 0 \n\t"
    "sbi 4, 1 \n\t"
    "sbi 4, 2 \n\t"
    "sbi 4, 3 \n\t"
    "sbi 4, 4 \n\t"
    "sbi 4, 5 \n\t"
    "sbi 5, 0 \n\t"
    "sbi 5, 2 \n\t"
    "sbi 5, 4 \n\t"
    "sbi 5, 5 \n\t"
    
    
    
    // load indirect with displacement. use 'z' register as input or assign register value to 'z' "ldd r16, z+14 \n\t" (accesses index 15 from input array as 'z' register and places the value in r16. 'z' is input constraint.
    // ldd load indirect with displacement (address + offset) array access?
    :
    // Outputs.
    :
    // Inputs.
    //"I" (_SFR_IO_ADDR(DDRD)), // PORTD         %0
    //"I" (_SFR_IO_ADDR(DDRB)), // PORTB         %1
    //"I" (_SFR_IO_ADDR(DDRC)), // PORTC         %2
    //"I" (DDD0),               // Digital 0     %3
    //"I" (DDD1),               // Digital 1     %4
    //"I" (DDD2),               // Digital 2     %5
    //"I" (DDD3),               // Digital 3     %6
    //"I" (DDD4),               // Digital 4     %7
    //"I" (DDD5),               // Digital 5     %8
    //"I" (DDD6),               // Digital 6     %9
    //"I" (DDD7),               // Digital 7     %10
    //"I" (DDB0),               // Digital 8     %11
    //"I" (DDB1),               // Digital 9     %12
    //"I" (DDB2),               // Digital 10    %13
    //"I" (DDB3),               // Digital 11    %14
    //"I" (DDB4),               // Digital 12    %15
    //"I" (DDB5),               // Digital 13    %16
    //"I" (DDC0),               // Analog  0     %17
    //"I" (DDC1),               // Analog  1     %18
    //"I" (DDC2),               // Analog  2     %19
    //"I" (DDC3),               // Analog  3     %20
    //"I" (DDC4),               // Analog  4     %21
    //"I" (DDC5),               // Analog  5     %22
    //"z" (COLUMN)
    //"I" (_SFR_IO_ADDR(DDRB)), // PORTD         %0
    "I" (bPort),
    "I" (5), // PORTB         %1
    "I" (_SFR_IO_ADDR(PORTB)), // PORTD         %0
    "I" (5),
    "I" (4)
  );

  Serial.begin(9600);
  //Serial.println(xValue, HEX);
  //Serial.println(yValue, HEX);
  //Serial.println(zValue, HEX);
  uint8_t address = PORTB;
  uint8_t address2 = PINC1;
  uint8_t address3 = PINC2;
  uint8_t address4 = _SFR_IO_ADDR(PORTC);
  uint8_t address5 = _SFR_IO_ADDR(DDRD);
  uint8_t address6 = _SFR_IO_ADDR(PORTD);
  Serial.println(address);
  Serial.println(address2);
  Serial.println(address3);
  Serial.println(address4);
  Serial.println(address5);
  Serial.println(address6);
  //Serial.println(_SFR_IO_ADDR(DDRB), HEX);
  //Serial.println(_SFR_IO_ADDR(DDRC), HEX);
  
  //printf("Testing %p\n", &column);
  
  //setting rows to ouput
  //for(int i = 0; i<16; i++)
  //{
  //  pinMode(column[i], OUTPUT);
  //}
  //setting layers to output
  //for(int i = 0; i<4; i++)
  //{
  //  pinMode(layer[i], OUTPUT);
  //}
  //seeding random for random pattern
  //randomSeed(analogRead(10));
}
//xxxxxxxxxxxxxxxxxxxxFUNCTION LOOPxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

void loop()
{
  //merryGoRound();
}


//xxxxxxxxxxxxxxxxxxxxFUNCTIONSxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

///////////////////////////////////////////////////////////turn all off
void turnEverythingOff()
{
  for (int i = 0; i < 16; i++)
  {
    //digitalWrite(column[i], 1);
  }

  for (int i = 0; i < 4; i++)
  {
    //digitalWrite(layer[i], 0);
  }
}
