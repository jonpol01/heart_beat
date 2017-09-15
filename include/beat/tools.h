#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "ros/ros.h"
#include "nav_msgs/Odometry.h"
#include "geometry_msgs/PoseStamped.h"

namespace Pathfinder
{
using namespace std;

class Utils
{
  public:
	double controller_frequency_;
	//float A_x, A_y, A_z;
  private:
};

/**
 * Callback function executes when new topic data comes.
 * Task of the callback function is to print data to screen.
 */
void poseCallback(const geometry_msgs::Pose::ConstPtr& msg)
{
  ROS_INFO("Point A-> x: [%2f], y: [%2f], z: [%2f]", msg->position.x, msg->position.y, msg->position.z);
  float A_x, A_y, A_z;
  A_x = msg->position.x;
  A_y = msg->position.y;
  A_z = msg->position.z;
}

 /*
 void util::odomCallback(const nav_msgs::Odometry::ConstPtr& msg)
 {
   ROS_INFO("Seq: [%d]", msg->header.seq);
   ROS_INFO("Position-> x: [%f], y: [%f], z: [%f]", msg->pose.pose.position.x,msg->pose.pose.position.y, msg->pose.pose.position.z);
   ROS_INFO("Orientation-> x: [%f], y: [%f], z: [%f], w: [%f]", msg->pose.pose.orientation.x, msg->pose.pose.orientation.y, msg->pose.pose.orientation.z, msg->pose.pose.orientation.w);
   ROS_INFO("Vel-> Linear: [%f], Angular: [%f]", msg->twist.twist.linear.x,msg->twist.twist.angular.z);
 }

 void util::goalCallback(const geometry_msgs::PoseStamped::ConstPtr& msg)
 {
 //  ROS_INFO("Point B-> x: [%f], y: [%f], z: [%f]", msg->position.x, msg->position.y, msg->position.z);
   ROS_INFO("Point B-> x: [%f]", msg->pose.position.x);
 }
 */
} //end namespace
