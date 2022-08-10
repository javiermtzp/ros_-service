#!/usr/bin/env python3

from __future__ import print_function

from request_service.srv import InvertString,InvertStringResponse
import rospy

def handle_response(req):
    print("Returning inverted [%s]"%(req.a[::-1]))
    return InvertStringResponse(req.a[::-1])
    

if __name__ == "__main__":
    rospy.init_node('invert_string_server')
    s = rospy.Service('invert_string', InvertString, handle_response)
    print("Ready to invert strings.")
    rospy.spin()
