#include <iostream>

#include "sensor_int.h"
#include "node.h"

#define SENSOR_TYPE 2

SensorInt::SensorInt(unsigned char sensorId) : Sensor(SENSOR_TYPE, sensorId) {
  std::cout << "Int sensor init " << sensorId << "\n";
  mValue = 0;
}

bool SensorInt::setValue(int value){
  mValue = value;
  return true;
}

int SensorInt::getValue(){
  return mValue;
}

int SensorInt::serialize_size() {
  return Sensor::main_serialize_size() + sizeof(mValue);
}

void SensorInt::serialize(char* dataOut) {
  Sensor::main_serialize(dataOut);
  memcpy( &dataOut[3], &mValue, sizeof(mValue) );
}

void SensorInt::sentUpdate() {
  // noop
  std::cout << "Update sent" << std::endl;
}