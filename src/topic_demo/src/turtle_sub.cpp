#include <ros/ros.h>
#include <turtlesim/Pose.h>

void turtleCallback(const turtlesim::Pose::ConstPtr &msg)
{

	ROS_INFO("turtle_pose:x=%f,y=%f",msg->x,msg->y);
}

int main(int argc,char** argv)
{
	ros::init(argc,argv,"turtle_sub");
	ros::NodeHandle n;
	ros::Subscriber sub=n.subscribe("/turtle1/pose",1,turtleCallback);
	ros::spin();
	return 0;
}
