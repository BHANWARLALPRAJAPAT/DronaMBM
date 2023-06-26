//Question 6: 
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

#define RED_LED 2
#define GREEN_LED 3
#define YELLOW_LED 4
#define BLUE_LED 5

void setup() {
 Serial.begin(9600);
 Serial.setTimeout(2000);
 pinMode(RED_LED, OUTPUT);
 pinMode(GREEN_LED, OUTPUT);
 pinMode(YELLOW_LED, OUTPUT);
 pinMode(BLUE_LED, OUTPUT);
}
String redOutput,greenOutput,yellowOutput,blueOutput;
void loop() {
 Serial.println("Do you want to glow RED LED : y/n");
 redOutput = Serial.readStringUntil('\n');
 redOutput.trim();
 if(redOutput=="y")
  digitalWrite(RED_LED, HIGH);
 else if(redOutput=="n")
  digitalWrite(RED_LED, LOW);

 Serial.println("Do you want to glow GREEN LED : y/n");
 greenOutput = Serial.readStringUntil('\n');
 greenOutput.trim();
 if(greenOutput=="y")
  digitalWrite(GREEN_LED, HIGH);
 else if(greenOutput=="n")
  digitalWrite(GREEN_LED, LOW); 

 Serial.println("Do you want to glow YELLOW LED : y/n");
 yellowOutput = Serial.readStringUntil('\n');
 yellowOutput.trim();
 if(yellowOutput=="y")
  digitalWrite(YELLOW_LED, HIGH);
 else if (yellowOutput =="n")
  digitalWrite(YELLOW_LED, LOW);

 Serial.println("Do you want to glow BLUE LED : y/n");
 blueOutput = Serial.readStringUntil('\n');
 blueOutput.trim();
 if(blueOutput=="y")
  digitalWrite(BLUE_LED, HIGH);
 else if(blueOutput=="n")
  digitalWrite(BLUE_LED, LOW);
}
