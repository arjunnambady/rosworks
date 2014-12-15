#!/usr/bin/env python

import rospy
from nav_msgs.msg import Odometry

def callback(data):
	pose_data = data.pose.pose
	x = pose_data.position.x
	y = pose_data.position.y
	theta = pose_data.orientation.z
	#rospy.loginfo("x coordinate = %s", x)
	#rospy.loginfo("y coordinate = %s", y)
	#rospy.loginfo("Theta value = %s", theta)
	print "x = ", x
	print "y = ", y
	print "theta = ", theta
	print "\n\n"
	#rospy.loginfo(pose_data)
	
def get_position_data():
	rospy.init_node("postion_logger", anonymous=True)
	rospy.Subscriber("/odom",Odometry,callback)
	rospy.spin()

if __name__ == '__main__':
	get_position_data()
