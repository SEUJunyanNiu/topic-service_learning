#include <ros/ros.h>
#include <service_demo/Greeting.h>


bool commandCallback(service_demo::Greeting::Request  &req,
         			service_demo::Greeting::Response &res)
{

   	ROS_INFO("Hi! %s with %d age",req.name.c_str(),req.age);


	res.feedback = "Welcome";

   	return true;
}



int main(int argc,char** argv)
{
	ros::init(argc,argv,"greeting_server");
	ros::NodeHandle nh;   //实例化
	
	ros::ServiceServer command_server=nh.advertiseService("/greeting",commandCallback);
	ros::spin();

	ROS_INFO("Ready to receive command.");

	return 0;

}
