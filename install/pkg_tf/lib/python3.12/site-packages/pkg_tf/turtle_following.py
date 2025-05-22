import math
import rclpy                                              # ROS2 Python interface library
from rclpy.node import Node                               # ROS2 node class
import tf_transformations                                 # TF coordinate transformation library
from tf2_ros import TransformException                    # Exception class for TF transformations
from tf2_ros.buffer import Buffer                         # Buffer class for storing coordinate transformation information
from tf2_ros.transform_listener import TransformListener  # Listener class for coordinate transformations
from geometry_msgs.msg import Twist                       # ROS2 velocity control message
from turtlesim.srv import Spawn                           # Service interface for turtle spawning

class TurtleFollowing(Node):

    def __init__(self, name):
        super().__init__(name)                                      # Initialize parent class of ROS2 node

        self.declare_parameter('source_frame', 'turtle1')           # Declare a parameter for the source frame name
        self.source_frame = self.get_parameter(                     # Use the external parameter value if set, otherwise use default
            'source_frame').get_parameter_value().string_value

        self.tf_buffer = Buffer()                                   # Create a buffer for storing coordinate transformation information
        self.tf_listener = TransformListener(self.tf_buffer, self)  # Create a listener for coordinate transformations

        self.spawner = self.create_client(Spawn, 'spawn')           # Create a client to request turtle spawning
        self.turtle_spawning_service_ready = False                  # Flag indicating if turtle spawning service has been requested
        self.turtle_spawned = False                                 # Flag indicating if the turtle has been successfully spawned

        self.publisher = self.create_publisher(Twist, 'turtle2/cmd_vel', 1) # Create a topic for controlling the following turtle's velocity

        self.timer = self.create_timer(1.0, self.on_timer)         # Create a timer with a fixed period to control the following turtle's movement

    def on_timer(self):
        from_frame_rel = self.source_frame                         # Source coordinate frame
        to_frame_rel   = 'turtle2'                                 # Target coordinate frame

        if self.turtle_spawning_service_ready:                     # If the turtle spawning service has been requested
            if self.turtle_spawned:                                # If the following turtle has been spawned
                try:
                    now = rclpy.time.Time()                        # Get the current time in ROS
                    trans = self.tf_buffer.lookup_transform(       # Listen for the coordinate transformation from source to target frame
                        to_frame_rel,
                        from_frame_rel,
                        now)
                except TransformException as ex:                   # If the coordinate transformation fails, report the exception
                    self.get_logger().info(
                        f'Could not transform {to_frame_rel} to {from_frame_rel}: {ex}')
                    return

                msg = Twist()                                      # Create a velocity control message
                scale_rotation_rate = 1.0                          # Calculate angular velocity based on the turtle's angle
                msg.angular.z = scale_rotation_rate * math.atan2(
                    trans.transform.translation.y,
                    trans.transform.translation.x)

                scale_forward_speed = 0.5                          # Calculate linear velocity based on the turtle's distance
                msg.linear.x = scale_forward_speed * math.sqrt(
                    trans.transform.translation.x ** 2 +
                    trans.transform.translation.y ** 2)

                self.publisher.publish(msg)                        # Publish the velocity command for the turtle to follow
            else:                                                  # If the following turtle has not been spawned
                if self.result.done():                             # Check if the turtle has been spawned
                    self.get_logger().info(
                        f'Successfully spawned {self.result.result().name}')
                    self.turtle_spawned = True                     
                else:                                              # If the turtle has not yet been spawned
                    self.get_logger().info('Spawn is not finished')
        else:                                                      # If the turtle spawning service has not been requested
            if self.spawner.service_is_ready():                    # If the turtle spawning server is ready
                request = Spawn.Request()                          # Create a request data object
                request.name = 'turtle2'                           # Set the request data content, including turtle name, xy position, and orientation
                request.x = float(4)
                request.y = float(2)
                request.theta = float(0)

                self.result = self.spawner.call_async(request)     # Send the service request
                self.turtle_spawning_service_ready = True          # Set flag indicating that the request has been sent
            else:
                self.get_logger().info('Service is not ready')     # Message indicating the turtle spawning server is not ready

def main(args=None):
    rclpy.init(args=args)                       # Initialize the ROS2 Python interface
    node = TurtleFollowing("turtle_following")  # Create and initialize the ROS2 node object
    rclpy.spin(node)                            # Loop to wait for ROS2 to exit
    node.destroy_node()                         # Destroy the node object
    rclpy.shutdown()                            # Shutdown the ROS2 Python interface