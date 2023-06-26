// Question 15: Experiment With Two LED's with PWM in arduino
// Hardware :
// Microcontroller : Arduino UNO
// Resistor : 470 Ohm
// LED : 2
// BreadBoard : 1
// Male to Male Jumper Wire : 2
// 1. Connect Ground of LED's Negative Terminal to Ground
// 2. Connect Resistor to Positive Terminal of LED
// 3. Connect Resistor1 to PWM pin 3 using Jumper Wire
// 4. Connect Resistor2 to digitalPin 2 using Jumper Wire
// Run the Following Code to get the Desired Output.

#define ERROR_LED 2
#define OUTPUT_LED 3
int input;


void setup() {
  // put your setup code here, to run once:
  pinMode(OUTPUT_LED,OUTPUT);
  pinMode(ERROR_LED,OUTPUT);
  Serial.begin(9600);
  Serial.setTimeout(2500);
}

void loop() {
  Serial.println("Enter the Brightness Scale from 0- 5:");
  Serial.println("0 : OFF");
  Serial.println("1 : DIMMER");
  Serial.println("2 : DIMM");
  Serial.println("3 : BRIGHT");
  Serial.println("4 : BRIGHTER");
  Serial.println("5 : BRIGHTEST");

  input = Serial.parseInt();

  if(input < 0 or input > 5){
    Serial.println("Error in input");
    digitalWrite(ERROR_LED,HIGH);
    analogWrite (OUTPUT_LED,0);
  }
  else{
    digitalWrite(ERROR_LED,LOW);
    analogWrite(OUTPUT_LED, input*51);
  }
}