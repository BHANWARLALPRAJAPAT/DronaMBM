//Question 8: 
// Write an Interactive program for switching the LEDs, ON and OFF. Connect four LEDs to the Arduino

// Author: BHANWARLAL PRAJAPAT
// Date : 24 June 2023

// HardWare :
// 1. Arduino UNO : 1
// 2. Arduino USB Connector : 1
// 3. BreadBoard : 1
// 4. Male to Male Connector : 5
// 5. LED : 4
// 6. Resistor : 4 (470 Ohm)

// INSTRUCTION:
// 1. Connect -ve Terminal of all LEDs to Resistors one by one
// 2. Connect other Terminal of Resistor to GND Line BreadBoard
// 3. Connect +ve terminal of RED_LED to PIN 2 using Jumper Wire (red Prefered)
// 4. Connect +ve terminal of GREEN_LED to PIN 3 using Jumper Wire (green Prefered)
// 5. Connect +ve terminal of YELLOW_LED to PIN 4 using Jumper Wire (yellow Prefered)
// 6. Connect +ve terminal of BLUE_LED to PIN 5 using Jumper Wire (blue Prefered)
// 7. Connect GND LINE of BreadBoard to GND PIN of Arduino Board Using Jumping Wire.
//Run the Code to get Desired Output

#define RED_LED    2
#define GREEN_LED  3
#define YELLOW_LED 4
#define WHITE_LED  5
String instruction;

void setup() {
 Serial.begin(9600);
 Serial.setTimeout(5000);
 pinMode(RED_LED    , OUTPUT);
 pinMode(GREEN_LED  , OUTPUT);
 pinMode(YELLOW_LED , OUTPUT);
 pinMode(WHITE_LED  , OUTPUT);
}
void loop() {
  Serial.println("Enter the instruction");

  instruction = Serial.readStringUntil('\n');
  instruction.trim();

  if(instruction[0] == 'R')
    digitalWrite(RED_LED, HIGH);
  else if(instruction[0]=='r')
    digitalWrite(RED_LED, LOW);

  if(instruction[1] == 'G')
    digitalWrite(GREEN_LED, HIGH);
  else if(instruction[1]=='g')
    digitalWrite(GREEN_LED, LOW);
 
  if(instruction[2] == 'Y')
    digitalWrite(YELLOW_LED, HIGH);
  else if(instruction[2]=='y')
    digitalWrite(YELLOW_LED, LOW);

  if(instruction[3] == 'W')
    digitalWrite(WHITE_LED, HIGH);
  else if(instruction[3]=='w')
    digitalWrite(WHITE_LED,LOW);
  
}