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
//initializing and declaring led rows
uint8_t columns[16] = {13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, A2, A1, A5, A4};
uint8_t* column;// = {13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, A2, A1, A5, A4};
const uint8_t COLUMN_COUNT = 16;
//initializing and declaring led layers
const int layer[4] = {A3, A0, 1, 0};
const int LAYER_COUNT = 4;

uint8_t address = 987;

int time = 250;

void setup()
{
  column = columns;
  asm volatile
  (
    "sbi %2, %17 \n\t" // Turn on pin 13
    "sbi %2, %16 \n\t" // Turn on pin 12
    "sbi %2, %15 \n\t" // Turn on pin 11
    "sbi %2, %14 \n\t" // Turn on pin 10
    "sbi %2, %13 \n\t" // Turn on pin 9
    "sbi %2, %12 \n\t" // Turn on pin 8
    "sbi %1, %11 \n\t" // Turn on pin 7
    "sbi %1, %10 \n\t"  // Turn on pin 6
    "sbi %1, %9 \n\t"  // Turn on pin 5
    "sbi %1, %8 \n\t"  // Turn on pin 4
    "sbi %1, %7 \n\t"  // Turn on pin 3
    "sbi %1, %6 \n\t"  // Turn on pin 2
    "sbi %1, %5 \n\t"  // Turn on pin 1
    "sbi %1, %4 \n\t"  // Turn on pin 0
    "sbi %3, %18 \n\t" // Turn on pin A0
    "sbi %3, %19 \n\t" // Turn on pin A1
    "sbi %3, %20 \n\t" // Turn on pin A2
    "sbi %3, %21 \n\t" // Turn on pin A3
    "sbi %3, %22 \n\t" // Turn on pin A4
    "sbi %3, %23 \n\t" // Turn on pin A5
    //"mov z, z+1"
    "ldd r16, z+14 \n\t"
    "mov %0, r16 \n\t"
    //"lds %0, r16 \n\t"
    // ldd load indirect with displacement (address + offset) array access?
    :
    "=r" (address)
    :
    "I" (_SFR_IO_ADDR(DDRD)), // PORTD         %0
    "I" (_SFR_IO_ADDR(DDRB)), // PORTB         %1
    "I" (_SFR_IO_ADDR(DDRC)), // PORTC         %2
    "I" (DDD0),               // Digital 0     %3
    "I" (DDD1),               // Digital 1     %4
    "I" (DDD2),               // Digital 2     %5
    "I" (DDD3),               // Digital 3     %6
    "I" (DDD4),               // Digital 4     %7
    "I" (DDD5),               // Digital 5     %8
    "I" (DDD6),               // Digital 6     %9
    "I" (DDD7),               // Digital 7     %10
    "I" (DDB0),               // Digital 8     %11
    "I" (DDB1),               // Digital 9     %12
    "I" (DDB2),               // Digital 10    %13
    "I" (DDB3),               // Digital 11    %14
    "I" (DDB4),               // Digital 12    %15
    "I" (DDB5),               // Digital 13    %16
    "I" (DDC0),               // Analog  0     %17
    "I" (DDC1),               // Analog  1     %18
    "I" (DDC2),               // Analog  2     %19
    "I" (DDC3),               // Analog  3     %20
    "I" (DDC4),               // Analog  4     %21
    "I" (DDC5),               // Analog  5     %22
    "z" (columns)
    :
    "r16"
  );

  Serial.begin(9600);
  Serial.println(address);
  int pointer = &column;
  Serial.println(pointer);
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
