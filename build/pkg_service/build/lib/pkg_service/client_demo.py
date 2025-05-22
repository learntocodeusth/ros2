# Import relevant libraries
import rclpy
from rclpy.node import Node
from example_interfaces.srv import AddTwoInts

class Service_Client(Node):
    def __init__(self, name):
        super().__init__(name)
        # Create client using create_client function, passing the service data type and service topic name
        self.client = self.create_client(AddTwoInts, '/add_two_ints')
        # Loop to wait for the server to start successfully
        while not self.client.wait_for_service(timeout_sec=1.0):
            print("Service not available, waiting again...")
        # Create the service request data object
        self.request = AddTwoInts.Request()
        
    def send_request(self): 
        self.request.a = 10
        self.request.b = 90
        # Send the service request
        self.future = self.client.call_async(self.request)
        
def main():
    rclpy.init()  # Node initialization
    service_client = Service_Client("client_node")  # Create object
    service_client.send_request()  # Send service request
    while rclpy.ok():
        rclpy.spin_once(service_client)
        # Check if the data processing is complete
        if service_client.future.done():
            try:
                # Get the service feedback and print it
                response = service_client.future.result()
                print("service_client.request.a = ", service_client.request.a)
                print("service_client.request.b = ", service_client.request.b)
                print("Result = ", response.sum)
            except Exception as e:
                service_client.get_logger().info('Service call failed %r' % (e,))
            break
    service_client.destroy_node()                    
    rclpy.shutdown()