#include <ros.h>
#include <ros/time.h>
#include <sensor_msgs/Range.h>

ros::NodeHandle  nh;

sensor_msgs::Range range_msg;
ros::Publisher pub_range( "/ultrasound", &range_msg);

const int pingPin = 7;
char frameid[] = "/ultrasound";
long duration, cm;
float meter;
float d = 100;

void setup()
{
  nh.initNode();
  nh.advertise(pub_range);
  
  range_msg.radiation_type = sensor_msgs::Range::ULTRASOUND;
  range_msg.header.frame_id =  frameid;
  range_msg.field_of_view = 0.1; 
  range_msg.min_range = 0.04;
  range_msg.max_range = 1.54;
}

void loop()
{
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);
  
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);

  cm = microsecondsToCentimeters(duration);
  meter = cm/d;
  
  range_msg.range = meter;
  range_msg.header.stamp = nh.now();
  pub_range.publish(&range_msg);
  delay(100);
  nh.spinOnce();
}

long microsecondsToCentimeters(long microseconds)
{
  return microseconds / 29 / 2;
}
  
  
  
    
