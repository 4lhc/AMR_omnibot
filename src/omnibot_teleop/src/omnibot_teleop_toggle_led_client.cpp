#include <omnibot_msgs/LEDState.h>
// #include <omnibot_msgs/ToggleLEDState.h>
#include <ros/ros.h>
#include <std_msgs/Empty.h>
#include <std_msgs/Int8.h>
#include <map>
#include <iomanip>

int main(int argc, char** argv)
{
	ros::init(argc, argv, "omnibot_teleop_toggle_led_service_client");
	ros::NodeHandle nh;
	std::map<std::string, std::string> header;
	header["a_val"] = "A_VAL";
	ros::ServiceClient led_srv_client = nh.serviceClient<omnibot_msgs::LEDState>
																				("omnibot_led_state", // Service Name
																				 false, // Persistent Connections
																				 header);
	// Persistent Connections
	/************************************************************************************************************/
	/* ros::ServiceClient led_srv_client = nh.serviceClient<omnibot_msgs::LEDState>("omnibot_led_state", true); */
	/* while (led_srv_client)                                                                                   */
	/* {                                                                                                        */
	/* 	// with persistent services, you can tell if the connection failed by                                   */
	/* 	// testing the handle                                                                                   */
	/* 	ROS_INFO_STREAM_DELAYED_THROTTLE(10, "Client is reachable");                                            */
	/* }                                                                                                        */
	/************************************************************************************************************/
	led_srv_client.waitForExistence(ros::Duration(-1)); // Blocking call

	omnibot_msgs::LEDState ledstate_srv;
	// std_msgs::Empty empty;
	// How to have empty request?
	ledstate_srv.request.get = 1;
	if (led_srv_client.call(ledstate_srv))
	{
		// THis is not printing
		ROS_INFO_STREAM("LEDState is "  << ledstate_srv.response.LEDState);
	}
	else
	{
		ROS_ERROR_STREAM("LEDState service call failed.");
		return 1;
	}

	return 0;
}
