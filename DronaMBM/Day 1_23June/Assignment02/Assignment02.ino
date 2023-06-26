//Question 2: 
// Show moving light effect (walking ones effect) on 4 LEDs connected to Arduino’s Pin no. A0, A1, A2, A3. 

// Author: BHANWARLAL PRAJAPAT
// Date : 23 June 2023

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
// 3. Connect +ve terminal of RED_LED to PIN A0 using Jumper Wire (red Prefered)
// 4. Connect +ve terminal of YELLOW_LED to PIN A1 using Jumper Wire (yellow Prefered)
// 5. Connect +ve terminal of GREEN_LED to PIN A2 using Jumper Wire (green Prefered)
// 6. Connect +ve terminal of BLUE_LED to PIN A3 using Jumper Wire (blue Prefered)
// 7. Connect GND LINE of BreadBoard to GND PIN of Arduino Board Using Jumping Wire.
//Run the Code to get Desired Output

#define RED_LED A0
#define YELLOW_LED A1
#define GREEN_LED A2
#define BLUE_LED A3

int walk[4][4] = {{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};
int counter = 0;

void setup() {
  pinMode(RED_LED,OUTPUT);
  pinMode(YELLOW_LED,OUTPUT);
  pinMode(GREEN_LED,OUTPUT);
  pinMode(BLUE_LED,OUTPUT);
}
void loop() {
  digitalWrite(RED_LED   , walk[a][0]);
  digitalWrite(YELLOW_LED, walk[a][1]);
  digitalWrite(GREEN_LED , walk[a][2]);
  digitalWrite(BLUE_LED  , walk[a][3]);

  delay(500);
  counter = (counter+1) % 4;
}