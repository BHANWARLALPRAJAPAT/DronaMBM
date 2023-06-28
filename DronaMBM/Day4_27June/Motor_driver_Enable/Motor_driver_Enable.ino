//Assignment : Experimentation with PWM controlled N20 DC MOTOR using Arduino UNO
//Author : BHANWARLAL PRAJAPAT
//Date : 27 June 2023
#define MOTOR_INPUT_PIN_A 4
#define MOTOR_INPUT_PIN_B 5
#define MOTOR_ENABLE_PIN 3
void setup() {
  Serial.begin(9600);
  pinMode(MOTOR_INPUT_PIN_A, OUTPUT);
  pinMode(MOTOR_INPUT_PIN_B, OUTPUT);
  pinMode(MOTOR_ENABLE_PIN, OUTPUT);
}
void RotateMotor() {
  //Turn Motor in ACW direction
  digitalWrite(MOTOR_INPUT_PIN_A, HIGH);
  digitalWrite(MOTOR_INPUT_PIN_B, LOW);
  analogWrite(MOTOR_ENABLE_PIN, 255);
  delay(2000);
  
  //Stop rotaion of Motor
  digitalWrite(MOTOR_INPUT_PIN_A, LOW);
  digitalWrite(MOTOR_INPUT_PIN_B, LOW);
  analogWrite(MOTOR_ENABLE_PIN, LOW);
  delay(1000);

  //Turn Motor in CW direction
  digitalWrite(MOTOR_INPUT_PIN_A, LOW);
  digitalWrite(MOTOR_INPUT_PIN_B, HIGH);
  analogWrite(MOTOR_ENABLE_PIN, 255);
  delay(2000);

  //Stop rotaion of Motor
  digitalWrite(MOTOR_INPUT_PIN_A, LOW);
  digitalWrite(MOTOR_INPUT_PIN_B, LOW);
  analogWrite(MOTOR_ENABLE_PIN, LOW);
  delay(1000);
}
void SpeedMotor() {
  //stop Rotation of Motor for 10 ms
  digitalWrite(MOTOR_INPUT_PIN_A, LOW);
  digitalWrite(MOTOR_INPUT_PIN_B, LOW);
  delay(10);

  //Turn Motor in CW direction
  digitalWrite(MOTOR_INPUT_PIN_A, LOW);
  digitalWrite(MOTOR_INPUT_PIN_B, HIGH);

  // Acceleration of Motor Rotation
  for (int i = 0; i < 256; i++) {
    analogWrite(MOTOR_ENABLE_PIN, i);
    Serial.print("Speed " + String(i));
    delay(50);
  }
  
  // Decelaration  of Motor Rotation
  for (int i = 255; i >= 0; i--) {
    analogWrite(MOTOR_ENABLE_PIN, i);
    Serial.print("Speed " + String(i));
    delay(50);
  }
}
void loop() {
  RotateMotor();
  SpeedMotor();
}
