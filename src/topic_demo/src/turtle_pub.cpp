#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

int main(int argc,char** argv)
{
	ros::init(argc,argv,"turtle_pub");
	ros::NodeHandle nh;   //实例化
	geometry_msgs::Twist msg;  //实例化
	msg.linear.x=0.1;
	msg.angular.z=0.2;
	ros::Publisher pub=nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel",1);
	ros::Rate loop_rate(1.0);
	while(ros::ok())
	{
		msg.linear.x=1.3*msg.linear.x;
		msg.angular.z=1.03*msg.angular.z;
		ROS_INFO("turtle_vel_pub:xl=%f,za=%f",msg.linear.x,msg.angular.z);
		pub.publish(msg);
		loop_rate.sleep();
	}
	return 0;

}

