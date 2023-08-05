import rospy
from turtlesim.msg import Pose

def sub_call(msg):
    rospy.loginfo(msg)

if __name__ == '__main__':
    rospy.init_node("sub_node")
    rospy.loginfo("subscriber node is starting")

    sub = rospy.Subscriber("/turtle1/pose", Pose, callback=sub_call)

    rospy.spin()
