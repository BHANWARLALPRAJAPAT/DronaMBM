#ifndef _MOTOR_H
#define _MOTOR_H
#include "hal.h"
class Motor {
public:
  int ENABLE_PIN;
  int A_PIN;
  int B_PIN;
  int C1;
  int C2;
  Motor(int A_PIN, int B_PIN, int ENABLE_PIN, int C1, int C2) {
    this->A_PIN = A_PIN;
    this->B_PIN = B_PIN;
    this->ENABLE_PIN = ENABLE_PIN;
    this->C1 = C1;
    this->C2 = C2;
    pinMode(A_PIN, OUTPUT);
    pinMode(B_PIN, OUTPUT);
    pinMode(ENABLE_PIN, OUTPUT);
    pinMode(C1, INPUT);
    pinMode(C2, INPUT);
  }
  void forward(int speed = 0) {
    digitalWrite(A_PIN, HIGH);
    digitalWrite(B_PIN, LOW);
    analogWrite(ENABLE_PIN, speed);
    delay(DELAY_TIME);
  }
  void reverse(int speed = 0) {
    digitalWrite(A_PIN, LOW);
    digitalWrite(B_PIN, HIGH);
    analogWrite(ENABLE_PIN, speed);
    delay(DELAY_TIME);
  }
  void stop() {
    digitalWrite(A_PIN, LOW);
    digitalWrite(B_PIN, LOW);
    // analogWrite(ENABLE_PIN, speed);
    delay(DELAY_TIME);
  }
};
#endif
