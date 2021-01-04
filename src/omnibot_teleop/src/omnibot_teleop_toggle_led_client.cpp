#include <omnibot_msgs/LEDState.h>
// #include <omnibot_msgs/ToggleLEDState.h>
#include <ros/ros.h>
#include <std_msgs/Empty.h>
#include <std_msgs/Int8.h>

int main(int argc, char** argv)
{
	ros::init(argc, argv, "omnibot_teleop_toggle_led_service_client");
	ros::NodeHandle nh;
	ros::ServiceClient led_client = nh.serviceClient<omnibot_msgs::LEDState>("omnibot_led_state");
	omnibot_msgs::LEDState ledstate_srv;
	// std_msgs::Empty empty;
	// How to have empty request?
	ledstate_srv.request.get = 10;

	if (led_client.call(ledstate_srv))
	{
		ROS_INFO_STREAM("LEDState is " << (int)ledstate_srv.response.LEDState);
	}
	else
	{
		ROS_ERROR_STREAM("LEDState service call failed.");
		return 1;
	}

	return 0;
}
