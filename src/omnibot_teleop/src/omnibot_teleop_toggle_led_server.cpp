#include <omnibot_msgs/LEDState.h>
#include <ros/ros.h>
#include <std_msgs/Empty.h>
#include <std_msgs/Int8.h>


// Callback type - Function
// Class Methods and Functor objects can also be used as callbacks
bool led_srv_callback(omnibot_msgs::LEDState::Request &req,
											omnibot_msgs::LEDState::Response &res)
	{
		res.LEDState = true;
		ROS_INFO_STREAM("Got request: req.get = " << req.get);
		if (req.get == 10)
			return false;
		return true;
	}


int main(int argc, char** argv)
{
	ros::init(argc, argv, "omnibot_teleop_toggle_led_service_server");
	ros::NodeHandle nh;

	omnibot_msgs::LEDState ledstate_srv;
	ros::ServiceServer led_srv_server = nh.advertiseService("omnibot_led_state", led_srv_callback);
	ros::spin();

	return 0;
}
