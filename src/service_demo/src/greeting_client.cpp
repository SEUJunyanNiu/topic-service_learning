#include <ros/ros.h>
#include <service_demo/Greeting.h>

int main(int argc,char** argv)
{
	ros::init(argc,argv,"greeting_client");
	ros::NodeHandle nh;   //实例化

	ros::service::waitForService("/greeting");
	ros::ServiceClient add_turtle=nh.serviceClient<service_demo::Greeting>("/greeting",10);

	service_demo::Greeting srv;
	srv.request.name="shawn";
	srv.request.age=21;

	add_turtle.call(srv);
	
	ROS_INFO("%s",srv.response.feedback.c_str());



	return 0;

}
