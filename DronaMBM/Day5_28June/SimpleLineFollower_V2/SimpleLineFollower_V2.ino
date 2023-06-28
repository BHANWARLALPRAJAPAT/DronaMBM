#include "hal.h"

void setup() {
  pinMode(IR_SENSOR_LEFT, INPUT);
  pinMode(IR_SENSOR_RIGHT, INPUT);

  pinMode(MOTOR_LEFT_PIN_A, OUTPUT);
  pinMode(MOTOR_LEFT_PIN_B, OUTPUT);
  pinMode(ENCODE_LEFT_1_PIN, INPUT);
  pinMode(ENCODE_LEFT_2_PIN, INPUT);
  pinMode(MOTOR_LEFT_ENABLE, OUTPUT);

  pinMode(MOTOR_RIGHT_PIN_A, OUTPUT);
  pinMode(MOTOR_RIGHT_PIN_B, OUTPUT);
  pinMode(ENCODE_RIGHT_1_PIN, INPUT);
  pinMode(ENCODE_RIGHT_2_PIN, INPUT);
  pinMode(MOTOR_RIGHT_ENABLE, OUTPUT);

  Serial.begin(9600);
}
void forward() {
  //Moving left motor in forward direction
  digitalWrite(MOTOR_LEFT_PIN_A, HIGH);
  digitalWrite(MOTOR_LEFT_PIN_B, LOW);
  analogWrite(MOTOR_LEFT_ENABLE, MOTOR_SPEED_LEFT);
  delay(DELAY_TIME);

  //Moving right motor in forward direction
  digitalWrite(MOTOR_RIGHT_PIN_A, HIGH);
  digitalWrite(MOTOR_RIGHT_PIN_B, LOW);
  analogWrite(MOTOR_RIGHT_ENABLE, MOTOR_SPEED_RIGHT);
  delay(DELAY_TIME);
}
void left() {
  //Moving leftt motor in forward direction
  digitalWrite(MOTOR_LEFT_PIN_A, HIGH);
  digitalWrite(MOTOR_LEFT_PIN_B, LOW);
  analogWrite(MOTOR_LEFT_ENABLE, MOTOR_SPEED_LEFT + 15);
  delay(DELAY_TIME);

  //Moving right motor in reverse direction
  digitalWrite(MOTOR_RIGHT_PIN_A, LOW);
  digitalWrite(MOTOR_RIGHT_PIN_B, HIGH);
  analogWrite(MOTOR_RIGHT_ENABLE, MOTOR_SPEED_RIGHT);
  delay(DELAY_TIME);
}
void right() {
  //Moving left motor in reverse
  digitalWrite(MOTOR_LEFT_PIN_A, LOW);
  digitalWrite(MOTOR_LEFT_PIN_B, HIGH);
  analogWrite(MOTOR_LEFT_ENABLE, MOTOR_SPEED_LEFT - 5);
  delay(DELAY_TIME);

  //Moving right motor in forward direction
  digitalWrite(MOTOR_RIGHT_PIN_A, HIGH);
  digitalWrite(MOTOR_RIGHT_PIN_B, LOW);
  analogWrite(MOTOR_RIGHT_ENABLE, MOTOR_SPEED_RIGHT - 22);
  delay(DELAY_TIME);
}
void stop() {
  digitalWrite(MOTOR_LEFT_PIN_A, LOW);
  digitalWrite(MOTOR_LEFT_PIN_B, LOW);
  // analogWrite(MOTOR_LEFT_ENABLE, MOTOR_SPEED_LEFT);
  delay(DELAY_TIME);

  //stop right motor
  digitalWrite(MOTOR_RIGHT_PIN_A, LOW);
  digitalWrite(MOTOR_RIGHT_PIN_B, LOW);
  // analogWrite(MOTOR_RIGHT_ENABLE, MOTOR_SPEED_RIGHT);
  delay(DELAY_TIME);
}
void loop() {
  bool IR_LEFT_DATA = digitalRead(IR_SENSOR_LEFT);
  bool IR_RIGHT_DATA = digitalRead(IR_SENSOR_RIGHT);
  if (IR_LEFT_DATA == WHITE and IR_RIGHT_DATA == WHITE) {
    forward();
  }
  else if (IR_LEFT_DATA == WHITE and IR_RIGHT_DATA == BLACK) {
    left();
  }
  else if (IR_LEFT_DATA == BLACK and IR_RIGHT_DATA == WHITE) {
    right();
  }
  else {
    stop();
  }
}
