# Import relevant libraries
import rclpy
from rclpy.node import Node
from example_interfaces.srv import AddTwoInts

class Service_Server(Node):
    def __init__(self, name):
        super().__init__(name)
        # Create a server using the create_service function, passing the parameters:
        # the service data type, the service name, and the service callback function (the content of the service)
        self.srv = self.create_service(AddTwoInts, '/add_two_ints', self.Add2Ints_callback)

    # The content of the service callback function adds two integers and returns the result
    def Add2Ints_callback(self, request, response):
        response.sum = request.a + request.b
        print("response.sum = ", response.sum)
        return response

def main():
    rclpy.init()
    server_demo = Service_Server("publisher_node")
    rclpy.spin(server_demo)
    server_demo.destroy_node()                     # Destroy the node object
    rclpy.shutdown()                               # Shutdown the ROS2 Python interface