#include "ros/ros.h"
#include "request_service/InvertString.h"
#include <cstdlib>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "invert_string_client");
  if (argc != 2)
  {
    ROS_INFO("usage: invert_string_client str");
    return 1;
  }

  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<request_service::InvertString>("invert_string");
  request_service::InvertString srv;
  srv.request.a = argv[1];

  if (client.call(srv))
    ROS_INFO("Response: %s\n", srv.response.b.c_str());
  else
  {
    ROS_ERROR("Failed to call service invert_string");
    return 1;
  }

  return 0;
}