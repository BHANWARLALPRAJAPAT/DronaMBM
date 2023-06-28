#ifndef _IR_SENSOR_H
  #define _IR_SENSOR_H
  #include "hal.h"
  class IR_Sensor{
    public:
    int digitalPin;
    int analogPin;
    IR_Sensor(){}
     IR_Sensor(int digitalPin){
        this->digitalPin = digitalPin;
        pinMode(digitalPin,INPUT);
     }
    IR_Sensor(int digitalPin,int analogPin){
      this->digitalPin = digitalPin;
      this->analogPin = analogPin;
      pinMode(digitalPin,INPUT);
      pinMode(analogPin,INPUT);
    }
    bool getDigitalData(){
      return  digitalRead(digitalPin);
    }
    int getAnalogData(){
      return analogRead(analogPin);
    }
  };
#endif