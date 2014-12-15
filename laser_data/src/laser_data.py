#!/usr/bin/env python

import rospy
from sensor_msgs.msg import LaserScan

def callback(data):
	laser_data = data.ranges
	rospy.loginfo(laser_data)

def get_laser_data():
	rospy.init_node("laser_data", anonymous=True)
	rospy.Subscriber("/base_scan",LaserScan,callback)
	rospy.spin()

if __name__ == '__main__':
	get_laser_data()
