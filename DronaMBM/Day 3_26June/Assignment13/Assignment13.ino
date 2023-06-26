// Question 13: 
// Connect a 7-segment display with two switches. Initialize the display with zero. First
// switch is for increment. Second switch is for decrement. If initial count is zero and you press
// the increment button then it should display 1, another press will give 2, if you keep on
// pressing it should go up to 9. Nine cannot be incremented further and so it should remain 9.
// This situation will be termed as “overflow”. Similarly if you keep on decrementing the
// number it should not “underflow” below zero. The “DP” (decimal point ‘dot’ LED) should be
// used to indicate “overflow” and “underflow” conditions
// Author : BHANWARLAL PRAJAPAT
// Date : 26 JUNE 2023

// HARDWARE :
// 1. Ardiuno UNO : 1
// 2. Ardiuno UNO2USB Connector : 1
// 3. Resistor : 8 (470 Ohm)
// 4. Seven Segment LED : 1
// 5. Switch : 2
// 6. Male to Male jumper wire: 13

// INSTRUCTION:
// 1. Connect Common of Seven Segment LED to Ground Line of the BreadBoard
// 2. Connect a Resistor to all 8 Terminals (including DP) individually
// 3. Connect a Jumper Wire between A-Resistors to PIN 2 
// 4. Repeat Step 3 for other 7 (including DP ) Resisors B,C,D,E,F,G,DP to PIN 3, 4, 5, 6, 7, 8, 9 .
// 5. Plug LOW_Switch and HIGH_Switch into the Breadboard
// 6. Connect terminal 1 of LOW_Switch and HIGH_Switch to the GND Line 
// 7. Connect terminal 2 of LOW_Switch to PIN 11 and terminal 2 of HIGH _SWITCH to PIN 10 of Arduino UNO using Jumper Wire 
// 8. Connect GND line of BreadBoard to the GND pin of Ardiuno UNO
// Run the Following Program for the Desired Output

#define LOW_SWITCH 11
#define HIGH_SWITCH 10
// PIN 2 to 9 are conserved for SevenSegment Display

int LCDNumMatrix[11][8] = {
//a,b,c,d,e,f,g,dp
 {1,1,1,1,1,1,0,0},//0
 {0,1,1,0,0,0,0,0},//1
 {1,1,0,1,1,0,1,0},//2
 {1,1,1,1,0,0,1,0},//3
 {0,1,1,0,0,1,1,0},//4
 {1,0,1,1,0,1,1,0},//5
 {1,0,1,1,1,1,1,0},//6
 {1,1,1,0,0,0,0,0},//7
 {1,1,1,1,1,1,1,0},//8
 {1,1,1,1,0,1,1.0},//9
 {0,0,0,0,0,0,0,1} //overflow
};	
int Output = 0;

void setup() {
 Serial.begin(9600);

 for(int i = 2;i<10;i++)
    pinMode(i, OUTPUT);
  pinMode(LOW_SWITCH,INPUT_PULLUP);
  pinMode(HIGH_SWITCH,INPUT_PULLUP);
}

void displayNumber(int n){
  if(n < 10 and n > -1) n = 10;
  for(int i = 2;i < 10;i++)
    digitalWrite(i,LCDNumMatrix[10][i-2]);
}

void loop() {
  displayNumber(Output);
  if(!digitalRead(HIGH_SWITCH)){
    Output++;
    delay(250);
  }
  if(!digitalRead(LOW_SWITCH)){
    Output--;
    delay(250);
  }
}