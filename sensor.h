#ifndef __SENSOR__
#define __SENSOR__

class Node;

class Sensor {
  public:
    Sensor(unsigned char sensorType, unsigned char sensorId);
      
    void setNode(Node *node);
    bool shouldSendUpdate();
    
    int main_serialize_size();
    void main_serialize(char* dataOut);

    virtual int serialize_size() = 0;
    virtual void serialize(char* dataOut) = 0;
    virtual void sentUpdate() = 0;
  protected:
    Node *mNode;
    unsigned char mId;
    unsigned char mType;
    bool mSendUpdate;
};

#endif // __SENSOR__