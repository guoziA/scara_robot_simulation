#include <ros/ros.h>

#include <actionlib/server/simple_action_server.h>
#include <control_msgs/FollowJointTrajectoryAction.h>
#include <control_msgs/FollowJointTrajectoryGoal.h>
#include <trajectory_msgs/JointTrajectory.h>
#include <trajectory_msgs/JointTrajectoryPoint.h>
#include <moveit/move_group_interface/move_group.h>

int main(int argc, char** argv){
	ros::init(argc, argv, "nav_test");

	moveit::planning_interface::MoveGroup group("scara_arm");
	ROS_INFO("connect to move group...");

	group.setJointValueTarget("link1_to_link2", 1.0);
	ROS_INFO("set joint value target...");

	moveit::planning_interface::MoveGroup::Plan plan;
	group.plan(plan);
	ROS_INFO("planning");
	group.execute(plan);
	ROS_INFO("moving arm to target...");

	ros::Duration(5.0);
	return 0;
}
