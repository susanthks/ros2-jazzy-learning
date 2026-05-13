import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist

class TurtleController(Node):
    def __init__(self):
        super().__init__('turtle_controller')
        # Create a publisher to 'turtle1/cmd_vel'
        self.publisher_ = self.create_publisher(Twist, 'turtle1/cmd_vel', 10)
        # Timer to call the move function every 0.1 seconds
        self.timer = self.create_timer(0.1, self.move_turtle)

    def move_turtle(self):
        msg = Twist()
        msg.linear.x = 2.0  # Forward speed
        msg.angular.z = 1.0 # Turning speed
        self.publisher_.publish(msg)

def main(args=None):
    rclpy.init(args=args)
    node = TurtleController()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
