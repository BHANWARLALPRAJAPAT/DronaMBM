//Author : BHANWARLAL PRAJAPAT
//Date : 27 June 2023
#define MOTOR_INPUT_PIN_A 4
#define MOTOR_INPUT_PIN_B 5
void setup() {
  pinMode(MOTOR_INPUT_PIN_A, OUTPUT);
  pinMode(MOTOR_INPUT_PIN_B, OUTPUT);
}

void loop() {
  //Rotate Anti-Clockwise
  digitalWrite(MOTOR_INPUT_PIN_A, HIGH);
  digitalWrite(MOTOR_INPUT_PIN_B, LOW);
  delay(2000);
  
  //Stop motor
  digitalWrite(MOTOR_INPUT_PIN_A, LOW);
  digitalWrite(MOTOR_INPUT_PIN_B, LOW);
  delay(2000);

  //Rotate Anti-Clockwise
  digitalWrite(MOTOR_INPUT_PIN_A, LOW);
  digitalWrite(MOTOR_INPUT_PIN_B, HIGH);
  delay(2000);

  //Stop motor
  digitalWrite(MOTOR_INPUT_PIN_A, LOW);
  digitalWrite(MOTOR_INPUT_PIN_B, LOW);
  delay(2000);
}
