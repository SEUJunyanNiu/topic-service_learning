#include <ros/ros.h>
#include <turtlesim/Spawn.h>

int main(int argc,char** argv)
{
	ros::init(argc,argv,"turtle_spawn");
	ros::NodeHandle nh;   //实例化
	turtlesim::Spawn srv;  //实例化
	srv.request.x=0.1;
	srv.request.y=0.2;
	srv.request.theta=0.2;
	srv.request.name="wc";

	ros::service::waitForService("/spawn");
	ros::ServiceClient add_turtle=nh.serviceClient<turtlesim::Spawn>("/spawn",1);

	ROS_INFO("call service to spawn turtle");
	add_turtle.call(srv);
	
	ROS_INFO("spawn turtle successfully [name:%s]",srv.response.name.c_str());



	return 0;

}
