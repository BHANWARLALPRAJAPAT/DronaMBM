// Question 10: Turn Off Seven Segment LED when not in Use.

// Author : BHANWARLAL PRAJAPAT
// Date : 24 JUNE 2023

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
int LEDNumMatrix[11][8] = {
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
  {0,0,0,0,0,0,0,1} //dp
};
int number;
void setup() {
  Serial.begin(9600);
  Serial.setTimeout(2000);
  for(int i=2;i<10;i++)
    pinMode(i, OUTPUT);
}
void displayNumber(int n){
  if(n>9 or n<0) n=10;
  for(int i= 2;i<10;i++)
    digitalWrite(i,LEDNumMatrix[n][i-2]);
}
void SwitchOffLED(){
  for(int i = 0;i<8;i++){
    digitalWrite(i+2,LOW);
  }
}
void loop() {
  SwitchOffLED();
  Serial.println("Enter the Number : ");
  while(!Serial.available()){}
  number = Serial.parseInt();
  Serial.println(number);
  displayNumber(number);
  delay(10000);
}