// Question 5: 
// Declare a variable as ‘unsigned char c=0’, print its numeric value inside a loop and increment it in every
// iteration. After what value it becomes zero again?

// Author : BHANWARLAL PRAJAPAT
// Date : 24 JUNE 2023

// HARDWARE :
// 1. Ardiuno UNO : 1
// 2. Arduino USB connecting Cable : 1

// INSTRUCTION:
// Run the Following Program for the Desired Output
unsigned char c = 0;
void setup(){
 Serial.begin(9600);
}

void loop(){
 c++;
 Serial.print("The value is : ");
 Serial.println(c);
 if(!c){
    while(true){
      // Sabotage the Program from Doing Anything
      continue;
    }
  }
}