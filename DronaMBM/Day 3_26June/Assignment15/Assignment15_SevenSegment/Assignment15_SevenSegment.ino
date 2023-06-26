// Question 15: Experiment With Seven Segment LED with PWM in Arduino UNO
// Hardware :-
// Microcontroller : Arduino UNO
// 8 Resistor : 470 Ohm 
// Seven Segment LED : 1
// BreadBoard : 1
// Male to Male Jumper Wire : 9

// Instruction :-
// 1. Connect Common of Seven Segment LED to Ground Line of the BreadBoard
// 2. Connect a Resistor to all 8 Terminals(including DP) individualaly
// 3. Connect a Jumper Wire Resistors to Voltage Line
// 4. Repeat Step 3 for other 6(excluding DP ) Resisors...
// 5. Connect a jumper wire from OUTPUT_LED PIN to Voltage Line
// 6. Connect GND PIN to Ground Line using Jumper Wire
// 7. Connect DP Resistor to ERROR_LED PIN via Jumper Wire
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

  input = Serial.parseInt(); //Taking Input from User

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