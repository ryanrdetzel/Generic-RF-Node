#ifndef __SENSOR_INT__
#define __SENSOR_INT__

#include "sensor.h"

class SensorInt: public Sensor
{
public:
  SensorInt(unsigned char sensorId);

  int getValue();
  bool setValue(int value);

  virtual int serialize_size();
  virtual void serialize(char* dataOut);
  virtual void sentUpdate();
private:
  int mValue;
};

#endif // __SENSOR_INT__