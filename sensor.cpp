#include "sensor.h"
#include <iostream>

#include "node.h"

Sensor::Sensor(unsigned char sensorType, unsigned char sensorId) {
  mId = sensorId;
  mType = sensorType;
  mSendUpdate = true; // Always send unless the sensor overrides
}

int Sensor::main_serialize_size() {
  return 1 + sizeof(mId) + sizeof(mType); 
}

void Sensor::main_serialize(char* dataOut) {
  unsigned char nodeId = mNode->getNodeId();
  memcpy( &dataOut[0], &nodeId, 1);
  memcpy( &dataOut[1], &mId, 1);
  memcpy( &dataOut[2], &mType, 1);
}

void Sensor::setNode(Node *node) {
  mNode = node;
}

bool Sensor::shouldSendUpdate() {
  return mSendUpdate;
}