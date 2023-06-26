//Question 12: 
//Capture and display the data of IR Sensor on Serial terminal continuously. Develop
// functions which can be used in future

// Author: BHANWARLAL PRAJAPAT
// Date : 26 June 2023

// HardWare :
// 1. Arduino UNO : 1
// 2. Arduino USB Connector : 1
// 3. BreadBoard : 1
// 4. Male to Male Connector : 4 + 2 = 6
// 5. LED : 1
// 6. Resistor : 1 (470 Ohm)
// 7. IR-SENSOR : 1

// INSTRUCTION:
// 1. Connect -ve Terminal of Signal_LED to Resistor
// 2. Connect other Terminal of Resistor to GND Pin of Arduino UNO using Jumper Wire (Black Preffered)
// 3. Connect +ve terminal of Signal_LED to PIN 3 using Jumper Wire (red Prefered)
// 4. Plug IR sensor into BreadBoard
// 5. Connect VCC pin, GND pin, D0 Pin and A0 Pin of IR-SEnsor to 5V PIN, GND PIN, PIN 2 and A0 PIN respectively of Arduino Board Using Jumping Wires.
//Run the Code to get Desired Output

#define IR_SENSOR_PIN_ANALOG A0
#define IR_SENSOR_PIN_DIGITAL 2
#define SIGNAL_LED 3
int counter = 0;
int analogValue;
int status;
#define BLACK 0
#define WHITE 1
void setup() {
  pinMode(IR_SENSOR_PIN_DIGITAL,INPUT);
  pinMode(IR_SENSOR_PIN_ANALOG,INPUT);
  pinMode(SIGNAL_LED,OUTPUT);
  Serial.begin(9600);
}
void loop() {
  analogValue = analogRead(IR_SENSOR_PIN_ANALOG);
  status = digitalRead(IR_SENSOR_PIN_DIGITAL);
  Serial.print(++counter);
  Serial.print(" ");
  Serial.print(analogValue);
  Serial.print(" ");
  Serial.print(status);
  Serial.print(" ");

  if(status) Serial.println("WHITE");
  else Serial.println("BLACK");
  
  digitalWrite(SIGNAL_LED,status);
  delay(250);
}