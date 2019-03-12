#include <iostream>

#include "sensor_ping.h"
#include "node.h"

#define SENSOR_TYPE 1

SensorPing::SensorPing(unsigned char sensorId) : Sensor(SENSOR_TYPE, sensorId) {
  std::cout << "Ping sensor init " << sensorId << "\n";
  mValue = 0;
}

bool SensorPing::setValue(int value){
  mValue = value;
  return true;
}

int SensorPing::getValue(){
  return mValue;
}

int SensorPing::serialize_size() {
  return Sensor::main_serialize_size() + sizeof(mValue);
}

void SensorPing::serialize(char* dataOut) {
  Sensor::main_serialize(dataOut);
  memcpy( &dataOut[3], &mValue, sizeof(mValue) );
}

void SensorPing::sentUpdate() {
  // noop
  std::cout << "Update sent" << std::endl;
}