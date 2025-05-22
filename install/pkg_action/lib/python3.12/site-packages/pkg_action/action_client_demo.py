import rclpy
from rclpy.action import ActionClient
from rclpy.node import Node
from pkg_interfaces.action import Progress

class Action_Client(Node):
    def __init__(self):
        super().__init__('progress_action_client')
        # Create action client;
        self._action_client = ActionClient(self, Progress, 'get_sum')

    def send_goal(self, num):
        # Send request;
        goal_msg = Progress.Goal()
        goal_msg.num = num
        self._action_client.wait_for_server()
        self._send_goal_future = self._action_client.send_goal_async(goal_msg, feedback_callback=self.feedback_callback)
        self._send_goal_future.add_done_callback(self.goal_response_callback)

    def goal_response_callback(self, future):
        # Process feedback after sending the goal;
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().info('Request was rejected')
            return

        self.get_logger().info('Request accepted, starting to execute task!')

        self._get_result_future = goal_handle.get_result_async()
        self._get_result_future.add_done_callback(self.get_result_callback)

    # Process final response.
    def get_result_callback(self, future):
        result = future.result().result
        self.get_logger().info('Final computation result: sum = %d' % result.sum)
        # 5. Release resources.
        rclpy.shutdown()

    # Process continuous feedback;
    def feedback_callback(self, feedback_msg):
        feedback = (int)(feedback_msg.feedback.progress * 100)
        self.get_logger().info('Current progress: %d%%' % feedback)

def main(args=None):
    rclpy.init(args=args)
    action_client = Action_Client()
    action_client.send_goal(10)
    rclpy.spin(action_client)