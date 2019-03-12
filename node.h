#ifndef __NODE__
#define __NODE__

#include "sensor.h"

#define CONFIG_MAX_SENSORS 8

class Node
{
public:
  Node(unsigned char nId, unsigned char hwVersion, unsigned char swVersion);

  void addSensor(Sensor *sensor);
  Sensor* getSensor(int index);

  unsigned char getNodeId();
  unsigned int numSensors() { return mNumSensors; };

private:
  unsigned int mNumSensors;
  Sensor *mSensors[CONFIG_MAX_SENSORS];
  unsigned char mVersionHW, mVersionSW, mNodeId;
};

#endif // __NODE__
