//Author : BHANWARLAL PRAJAPAT
//Date : 27 June 2023
#define MOTOR_INPUT_PIN_A 4
#define MOTOR_INPUT_PIN_B 5
#define MOTOR_ENABLE_PIN 3
void setup() {
  pinMode(MOTOR_INPUT_PIN_A, OUTPUT);
  pinMode(MOTOR_INPUT_PIN_B, OUTPUT);
  pinMode(MOTOR_ENABLE_PIN, OUTPUT);
  RotateMotor();
  SpeedMotor();
  
}
void RotateMotor()
{
  digitalWrite(MOTOR_INPUT_PIN_A, HIGH);
  digitalWrite(MOTOR_INPUT_PIN_B, LOW);
  delay(2000);

  digitalWrite(MOTOR_INPUT_PIN_A, LOW);
  digitalWrite(MOTOR_INPUT_PIN_B, LOW);
  delay(2000);

  digitalWrite(MOTOR_INPUT_PIN_A, LOW);
  digitalWrite(MOTOR_INPUT_PIN_B, HIGH);
  delay(2000);

  digitalWrite(MOTOR_INPUT_PIN_A,LOW);
  digitalWrite(MOTOR_INPUT_PIN_B,LOW);
  delay(2000);
}
void SpeedMotor()
{
  //Turn On the Motor
  digitalWrite(MOTOR_INPUT_PIN_A,LOW);
  digitalWrite(MOTOR_INPUT_PIN_B,LOW);
  dalay(10);

  digitalWrite(MOTOR_INPUT_PIN_A,LOW);
  digitalWrite(MOTOR_INPUT_PIN_B,HIGH);

  //ACCERATION 
  for(int i = 0;i<256;i++)
  {
    analogWrite(MOTOR_ENABLE_PIN,i);
    delay(20);
  }


  // De-Accelaration
  for(int i = 255;i>=0;i--)
  {
    analogWrite(MOTOR_ENABLE_PIN,i);
    delay(20);
  }
}
void loop() {

}
