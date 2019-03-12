#ifndef __SENSOR_PING__
#define __SENSOR_PING__

#include "sensor.h"

class SensorPing: public Sensor
{
public:
  SensorPing(unsigned char sensorId);

  int getValue();
  bool setValue(int value);

  virtual int serialize_size();
  virtual void serialize(char* dataOut);
  virtual void sentUpdate();
private:
  int mValue;
};

#endif // __SENSOR_PING__