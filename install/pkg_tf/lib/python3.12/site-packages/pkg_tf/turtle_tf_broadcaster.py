import rclpy                                       # ROS2 Python interface library
from rclpy.node import Node                        # ROS2 node class
from geometry_msgs.msg import TransformStamped     # Coordinate transformation message
import tf_transformations                          # TF coordinate transformation library
from tf2_ros import TransformBroadcaster           # TF coordinate transformation broadcaster
from turtlesim.msg import Pose                     # Turtlesim turtle position message

class TurtleTFBroadcaster(Node):

    def __init__(self, name):
        super().__init__(name)                                # Initialize parent class of ROS2 node

        self.declare_parameter('turtlename', 'turtle')        # Declare a parameter for the turtle's name
        self.turtlename = self.get_parameter(                 # Use the external parameter value if set, otherwise use default
            'turtlename').get_parameter_value().string_value

        self.tf_broadcaster = TransformBroadcaster(self)      # Create and initialize a TF coordinate transformation broadcaster

        self.subscription = self.create_subscription(         # Create a subscriber to receive turtle position messages
            Pose,
            f'/{self.turtlename}/pose',                       # Use the turtle name obtained from the parameter
            self.turtle_pose_callback, 1)

    def turtle_pose_callback(self, msg):                              # Callback function to handle turtle position messages and convert them to transformations
        transform = TransformStamped()                                # Create a coordinate transformation message object

        transform.header.stamp = self.get_clock().now().to_msg()      # Set the timestamp for the transformation message
        transform.header.frame_id = 'world'                           # Set the source coordinate frame
        transform.child_frame_id = self.turtlename                    # Set the target coordinate frame
        transform.transform.translation.x = msg.x                     # Set translation in X, Y, Z directions
        transform.transform.translation.y = msg.y
        transform.transform.translation.z = 0.0
        q = tf_transformations.quaternion_from_euler(0, 0, msg.theta) # Convert Euler angles to quaternion (roll, pitch, yaw)
        transform.transform.rotation.x = q[0]                         # Set rotation in X, Y, Z directions (quaternion)
        transform.transform.rotation.y = q[1]
        transform.transform.rotation.z = q[2]
        transform.transform.rotation.w = q[3]

        # Send the transformation
        self.tf_broadcaster.sendTransform(transform)     # Broadcast the transformation; updates the transformation information as the turtle's position changes

def main(args=None):
    rclpy.init(args=args)                                # Initialize the ROS2 Python interface
    node = TurtleTFBroadcaster("turtle_tf_broadcaster")  # Create and initialize the ROS2 node object
    rclpy.spin(node)                                     # Loop to wait for ROS2 to exit
    node.destroy_node()                                  # Destroy the node object
    rclpy.shutdown()                                     # Shutdown the ROS2 Python interface