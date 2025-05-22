import rclpy                                     # ROS2 Python interface library
from rclpy.node import Node                      # ROS2 node class

class ParameterNode(Node):
    def __init__(self, name):
        super().__init__(name)                                    # Initialize parent class of ROS2 node
        self.timer = self.create_timer(2, self.timer_callback)    # Create a timer (period in seconds, callback function to be executed)
        self.declare_parameter('robot_name', 'muto')              # Declare a parameter and set its default value

    def timer_callback(self):                                      # Callback function executed periodically by the timer
        robot_name_param = self.get_parameter('robot_name').get_parameter_value().string_value   # Read the parameter value from the ROS2 system

        self.get_logger().info('Hello %s!' % robot_name_param)     # Log information, printing the read parameter value

        # new_name_param = rclpy.parameter.Parameter('robot_name',   # Reset the parameter value to a specified value
        #                     rclpy.Parameter.Type.STRING, 'muto')
        # all_new_parameters = [new_name_param]
        # self.set_parameters(all_new_parameters)                    # Send the newly created parameter list to the ROS2 system

def main(args=None):                                 # Main entry function for the ROS2 node
    rclpy.init(args=args)                            # Initialize the ROS2 Python interface
    node = ParameterNode("param_declare")            # Create and initialize the ROS2 node object
    rclpy.spin(node)                                 # Loop to wait for ROS2 to exit
    node.destroy_node()                              # Destroy the node object
    rclpy.shutdown()                                 # Shutdown the ROS2 Python interface