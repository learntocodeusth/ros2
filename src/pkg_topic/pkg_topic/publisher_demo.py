# Import the rclpy library
import rclpy
from rclpy.node import Node
# Import String message type
from std_msgs.msg import String 

# Create a subclass of Node called Topic_Pub, passing a parameter name
class Topic_Pub(Node):
    def __init__(self, name):
        super().__init__(name)
        # Create a publisher using the create_publisher function, passing the parameters:
        # topic data type, topic name, and message queue length
        self.pub = self.create_publisher(String, "/topic_demo", 1) 
        # Create a timer that triggers every 1 second, passing the parameters:
        # time interval and interrupt handler function
        self.timer = self.create_timer(1, self.pub_msg)

    # Define the interrupt handler function
    def pub_msg(self):
        msg = String()  # Create a variable msg of type String
        msg.data = "Hi, I send a message."  # Assign a value to msg's data
        self.pub.publish(msg)  # Publish the topic data
        
# Main function
def main():
    rclpy.init()  # Initialize
    pub_demo = Topic_Pub("publisher_node")  # Create an instance of Topic_Pub, passing the node name
    rclpy.spin(pub_demo)  # Execute rclpy.spin function, passing the Topic_Pub instance
    pub_demo.destroy_node()  # Destroy the node object
    rclpy.shutdown()  # Shutdown the ROS2 Python interface