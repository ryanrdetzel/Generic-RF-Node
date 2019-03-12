#include "node.h"
#include <iostream>

Node::Node(unsigned char nId, unsigned char hwVersion, unsigned char swVersion)
{
  mNumSensors = 0;
  mVersionHW = hwVersion;
  mVersionSW = swVersion;
  mNodeId = nId;
}

unsigned char Node::getNodeId(){
  return mNodeId;
}

void Node::addSensor(Sensor *sensor) {
  // Check to see if we have a duplicate id node.
  if (mNumSensors <= CONFIG_MAX_SENSORS) {
    sensor->setNode(this);
    mSensors[mNumSensors++] = sensor;
  }
}

Sensor* Node::getSensor(int index) {
  return mSensors[index];
}