//Question 1: 
// Program to blink RED LED connected to Arduino Pin Number: Analog 0 (A0)

// Author: BHANWARLAL PRAJAPAT
// Date : 23 June 2023

// HardWare :
// 1. Arduino UNO : 1
// 2. Arduino USB Connector : 1
// 3. BreadBoard : 1
// 4. Male to Male Connector : 2
// 5. LED : 1
// 6. Resistor : 1 (470 Ohm)

// INSTRUCTION:
// 1. Connect -ve Terminal of RED LED to Resistor.
// 2. Connect other Terminal of Resistor to GND PIN of Arduino Board using Jumping Wire (Black Wire Prefered).
// 3. Connect +ve terminal of RED_LED to PIN A0 using Jumper Wire (Red Prefered)
//Run the Code to get Desired Output
#define RED_LED A0

void setup() {
  pinMode(RED_LED,OUTPUT);
}
void loop() {
  digitalWrite(RED_LED,HIGH);
  delay(500);
  digitalWrite(RED_LED,LOW);
  delay(500);
}