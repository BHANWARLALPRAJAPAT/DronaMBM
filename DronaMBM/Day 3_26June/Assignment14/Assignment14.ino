// QUestion -14 : Switch press Toggles the LED
// Author : BHANWARLAL PRAJAPAT
// Date : 26 JUNE 2023

// HARDWARE :
// 1. Ardiuno UNO : 1
// 2. Ardiuno UNO2USB Connector : 1
// 3. Resistor : 1 (470 Ohm)
// 4. LED : 1
// 5. Switch : 1
// 6. Male to Male jumper wire: 5

// INSTRUCTION:
// 1. Connect +ve terminal of LED to Resistor on BreadBoard
// 2. Connect -ve terminal of LED to GND Line of Breadboard using Jumper Wire
// 3. Connect Other Terminal of Resistor to the GPIO pin 2 of Arduino UNO
// 4. Plug Switch into the Breadboard
// 5. Connect terminal1 of Switch to the GND Line 
// 6. Connect terminal2 of Switch to PIN 3 of Arduino UNO using Jumper Wire 
// 7. Connect GND line of BreadBoard to the GND pin of Ardiuno UNO
// Run the Following Program for the Desired Output
#define TOGGLE_SWITCH_PIN 3
#define LED_PIN 2
bool status = false;
void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN,OUTPUT);
  pinMode(TOGGLE_SWITCH_PIN,INPUT_PULLUP);
}
void loop() {
  // put your main code here, to run repeatedly:
  if(!digitalRead(TOGGLE_SWITCH_PIN)){
    status = !status;
    digitalWrite(LED_PIN,status);
    delay(250);
  }
}