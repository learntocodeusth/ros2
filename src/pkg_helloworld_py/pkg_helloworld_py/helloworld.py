import rclpy
from rclpy.node import Node
import time

class HelloWorldNode(Node):
    def __init__(self, name):
        super().__init__(name)
        while rclpy.ok():
            self.get_logger().info("Hello World")
            time.sleep(0.5)

def main(args=None):
    rclpy.init(args=args)
    node = HelloWorldNode("helloworld")
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()