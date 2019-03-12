#include <iostream>
#include <typeinfo>
#include <bitset>

#include "node.h"
#include "sensor.h"
#include "sensor_int.h"
#include "sensor_ping.h"

#define HW_VERSION 1
#define SW_VERSION 1

void send_sensor_data(Node *node);

int main() {
   Node node(1, HW_VERSION, SW_VERSION);

   //TODO Should we include hW/sw version in payload?
   SensorPing ping_sensor(1);
   SensorInt temperature_sensor1(2);

   node.addSensor(&ping_sensor);
   node.addSensor(&temperature_sensor1);

   // void loop
   temperature_sensor1.setValue(2147483647); // max number 32 bit.
   send_sensor_data(&node);

   return 0;
}

void send_sensor_data(Node *node) {
   for(int i=0;i<node->numSensors();i++){
      // Does this sensor need to send up an update?
      Sensor *sensor = node->getSensor(i);
      if (sensor->shouldSendUpdate()){
         int data_size = sensor->serialize_size();

         char *data = new char[data_size];
         sensor->serialize( data );

         // Send the payload via the radio
         for (int x=0;x<data_size;x++){
            std::cout << std::bitset<8>(data[x]) << std::endl;
         }
         sensor->sentUpdate();
         delete [] data;
      }
   }
}