#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "ros/ros.h"
#include "nav_msgs/Odometry.h"
#include "geometry_msgs/PoseStamped.h"

#define ZERO	0
#define DEBUG  -1
#define NORM    1
#define MODE	(DEBUG) //todo: cfg support

using namespace std;

namespace Pathfinder
{

/**
*  Utility class
*/
class Utils
{
  public:
    double controller_frequency_;
    float  pose_x, pose_y, orient_z, orient_w;
    float  CurrPose_x, CurrPose_y, CurrOrient_z, CurrOrient_w;
    bool   Status(bool);
    bool   getCurrentPose();
  private:
} util;

/**
*  Class related algorithms
*/
class Alg
{
  public:
  private:
} alg;

/**
 * Callback function executes when new topic data comes.
 * Task of the callback function is to print data to screen.
 */
void odomCallback(const nav_msgs::Odometry::ConstPtr& msg)
{
  ROS_INFO("Seq: [%d]", msg->header.seq);
  ROS_INFO("Position-> x: [%f], y: [%f], z: [%f]", msg->pose.pose.position.x,msg->pose.pose.position.y, msg->pose.pose.position.z);
  ROS_INFO("Orientation-> x: [%f], y: [%f], z: [%f], w: [%f]", msg->pose.pose.orientation.x, msg->pose.pose.orientation.y, msg->pose.pose.orientation.z, msg->pose.pose.orientation.w);
  ROS_INFO("Vel-> Linear: [%f], Angular: [%f]", msg->twist.twist.linear.x,msg->twist.twist.angular.z);
}

/**
*  Callback function for recording current pose every second
*  this is called on main() to subscribe to /robot_pose rostopic
*/
void poseCallback(const geometry_msgs::Pose::ConstPtr& msg)
{
  util.pose_x = msg->position.x;
  util.pose_y = msg->position.y;
  util.orient_z = msg->orientation.z;
  util.orient_w = msg->orientation.w;
}

/**
*  Callback function for getting current or active goal
*  this is called on main() to subscribe to /move_base/current_goal rostopic
*/
void goalCallback(const geometry_msgs::PoseStamped::ConstPtr& msg)
{
  uint8_t getPos;

  getPos = util.getCurrentPose();

  if(getPos == true)
  {
    if(MODE == DEBUG)
    {
      ROS_INFO("********************** Start *********************");
      ROS_INFO("Point A-> x: [%2f], y: [%2f], z: [%2f], w: [%2f]", util.CurrPose_x, util.CurrPose_y, util.CurrOrient_z, util.CurrOrient_w);
      ROS_INFO("Point B-> x: [%2f], y: [%2f], z: [%2f], w: [%2f]", msg->pose.position.x, msg->pose.position.y, msg->pose.orientation.z, msg->pose.orientation.w);
      ROS_INFO("**********************  End  *********************");
      ROS_INFO(" ");
    }
  }else
    ROS_WARN("Failed to get Current Pose!!");

  
}

bool Utils::Status(bool status)
{
  return status;
}

bool Utils::getCurrentPose()
{

  util.CurrPose_x = util.pose_x;
  util.CurrPose_y = util.pose_y;
  util.CurrOrient_z = util.orient_z;
  util.CurrOrient_w = util.orient_w;

  if(util.CurrPose_x != 0 && util.CurrPose_y != 0)
    return true;
  else
    return false;
}

} //end namespace
