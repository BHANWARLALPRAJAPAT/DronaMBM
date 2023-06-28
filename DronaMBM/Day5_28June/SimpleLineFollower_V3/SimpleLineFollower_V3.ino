#include "hal.h"
#include "motor.h"
#include "ir_sensor.h"
Motor  leftMotor(MOTOR_LEFT_PIN_A , MOTOR_LEFT_PIN_B, MOTOR_LEFT_ENABLE , ENCODE_LEFT_1_PIN , ENCODE_LEFT_2_PIN );
Motor rightMotor(MOTOR_RIGHT_PIN_A, MOTOR_LEFT_PIN_B, MOTOR_RIGHT_ENABLE, ENCODE_RIGHT_1_PIN, ENCODE_RIGHT_2_PIN);
IR_Sensor  leftIR(IR_SENSOR_LEFT );
IR_Sensor rightIR(IR_SENSOR_RIGHT);
void forward() {
  leftMotor.forward(MOTOR_SPEED_LEFT);
  rightMotor.forward(MOTOR_SPEED_RIGHT);
}
void right() {
  leftMotor.forward(MOTOR_SPEED_LEFT+15);
  rightMotor.reverse(MOTOR_SPEED_RIGHT);
}
void left() {
  leftMotor.reverse(MOTOR_SPEED_LEFT-5);
  rightMotor.forward(MOTOR_SPEED_RIGHT-22);
}
void stop() {
  leftMotor.stop();
  rightMotor.stop();
}
void setup() {

}
void loop() {
  bool IR_LEFT_DATA = leftIR.getDigitalData();
  bool IR_RIGHT_DATA = rightIR.getDigitalData();
  if(IR_LEFT_DATA)
  {
    if(IR_RIGHT_DATA) stop();
    else right();
  }
  else {
    if(IR_RIGHT_DATA) left();
    else forward();
  }
}
