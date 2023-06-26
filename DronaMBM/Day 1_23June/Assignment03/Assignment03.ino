// Question 03 :  Display A P P L E on seven segment display With Arduino UNO

// Author: BHANWARLAL PRAJAPAT
// Date : 23 June 2023

// Hardware :
// 1. Microcontroller : Arduino UNO
// 2. Resistor : 8 (470 Ohm)
// 3. Seven Segment Display LED : 1
// 4. BreadBoard : 1
// 5. Male to Male Jumper Wire : 9
// 6. Arduino-USB Cable : 1

// Instruction :-
// 1. Connect Common of Seven Segment LED to GND pin of Arduino UNO Board using Jumper Wire(Black Prefferable)
// 2. Connect Resistors to all 8 Terminals (including DP) individually
// 3. Connect a Jumper Wire between A-Resistors to PIN 2 
// 4. Repeat Step 3 for other 7 (including DP ) Resisors B,C,D,E,F,G,DP to PIN 3, 4, 5, 6, 7, 8, 9 .
// Run the Following Code to get the Desired Output.

// PIN no. 2 to 9 is assigned to the Seven Segment Display

int LEDAlphaMatrix[5][8] = {
// a b c d e f g dp
  {1,1,1,0,1,1,1,0},//A
  {1,1,0,0,1,1,1,0},//P
  {0,0,0,1,1,1,0,0},//L
  {1,0,0,1,1,1,1,0},//E
  {0,0,0,0,0,0,0,0} //BLANK
};
#define A 0
#define P 1
#define L 2
#define E 3
#define BLANK 4
#define Show_Duration 1000
#define Delay_Duration 500

void displayAlphabet(int digit){
  for(int i = 2;i<10;i++)
  {
    digitalWrite(i,LEDAlphaMatrix[digit][i-2]);
  }
  delay(Show_Duration);
  for(int i = 2;i<10;i++)
  {
    digitalWrite(i,LEDAlphaMatrix[BLANK][i-2]);
  }
  delay(Delay_Duration);
}
void setup() {
  for(int i = 2;i<10;i++)
    pinMode(i,OUTPUT);
}
void loop() {
  displayAlphabet(A);
  displayAlphabet(P);
  displayAlphabet(P);
  displayAlphabet(L);
  displayAlphabet(E);
}