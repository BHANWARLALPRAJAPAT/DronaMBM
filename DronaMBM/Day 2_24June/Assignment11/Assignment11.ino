//Question 11: 
//Capture and display the data of IR Sensor on Serial terminal continuously. Develop
// functions which can be used in future

// Author: BHANWARLAL PRAJAPAT
// Date : 24 June 2023

// HardWare :
// 1. Arduino UNO : 1
// 2. Arduino USB Connector : 1

// INSTRUCTION:
//Run the Code to get Desired Output
String name;
int length;
void setup(){
 Serial.begin(9600);
 Serial.setTimeout(10000);
}

void displayDesign(){
  for(int i = 0;i<length;i++)
    Serial.print("+---");
  Serial.println("+");
}

void displayName(){ 
  displayDesign();

  for(int i = 0;i<length;i++){
    Serial.print("| ");
    Serial.print(name[i]);
    Serial.print(' ');
  }
  Serial.println('|');

  displayDesign();
}

void loop(){
  Serial.println("O: Enter your name :");

  name = Serial.readStringUntil('\n');
  name.toUpperCase();
  name.trim();

  length = name.length();
  if(length>0){
    Serial.println("I: " + name);
    Serial.print("O: The name has ");
    Serial.print(length);
    Serial.println(" char");

    displayName();
    Serial.println("");
  }
  delay(10000);
}