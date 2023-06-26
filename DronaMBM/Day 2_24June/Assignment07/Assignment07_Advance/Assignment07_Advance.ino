// Question 07_Advance :  Perform Sum of two integers and Display on Two Seven Segment Displays as well as Serial Monitor With Arduino UNO

// Author: BHANWARLAL PRAJAPAT
// Date : 24 June 2023

// Hardware :
// 1. Microcontroller : Arduino UNO
// 2. Resistor : 15 (470 Ohm)
// 3. Seven Segment Display LED : 2
// 4. BreadBoard : 1
// 5. Male to Male Jumper Wire : 17
// 6. Arduino-USB Cable : 1

// Instruction :-
// 1. Connect Common Terminal of Both Seven Segment LEDs to GND pins of Arduino UNO Board using Jumper Wire (Black Prefferable)
// 2. Connect Resistors to all 8 Terminals (including DP) individually on First Seven Segment DIsplay LED
// 3. Connect Resistors to all 7 Terminals (excluding DP) individually on Second Seven Segment DIsplay LED
// 4. Connect a Jumper Wire between A-Resistors of First Seven Segment Display to PIN 2 
// 5. Repeat Step 4 for other 7 (including DP ) Resisors B,C,D,E,F,G,DP to PIN 3, 4, 5, 6, 7, 8, 9 .
// 6. Connect a jumper Wire between A-Resistor of Second Seven Segment Display to PIN 10
// 7. Repeat Step 6 to other 6 (excluding DP) Resistors B,C,D,E,F and G to PIN 10,11,12,13,A0,A1,A2
// Run the Following Code to get the Desired Output.

// PIN no. 2 to 9 are assigned to the First Seven Segment Display
// PIN no. 10 to 13 and A0 to A2 are assigned to Second Seven Segment Display

int LCDNumMatrix[11][8] = {
// a,b,c,d,e,f,g,dp
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
  {0,0,0,0,0,0,0,1}//DP
};

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(2000);
  for(int i=2;i<14;i++)
    pinMode(i, OUTPUT);
  pinMode(A0,OUTPUT);
  pinMode(A1,OUTPUT);
  pinMode(A2,OUTPUT);
}

void displayNumber(int n,int SSDNo){
  if(n<0 or n>9) n=10;

  if(SSDNo == 1 ){
    for(int i= 2;i<10;i++)
      digitalWrite(i,LCDNumMatrix[n][i-2]);
  }
  else if(SSDNo == 2)
  {
    for(int i= 10;i<14;i++)
      digitalWrite(i,LCDNumMatrix[n][i-10]);
    digitalWrite(A0,LCDNumMatrix[n][4]);
    digitalWrite(A1,LCDNumMatrix[n][5]);
    digitalWrite(A2,LCDNumMatrix[n][6]);
  }
}

int num1,num2,sum;
void loop() {
  Serial.println("Enter First Number : ");
  num1 = Serial.parseInt();

  Serial.println("Enter Second Number : ");
  num2 = Serial.parseInt();
  
  sum = num1+num2;
  Serial.print("The Sum is : ");
  Serial.println(sum);
  if(sum<0 or sum>99)
  {
    displayNumber(sum,1);
  }
  else{
    displayNumber(sum%10,1);
    displayNumber(sum/10,2);
  }
  delay(2000);
}