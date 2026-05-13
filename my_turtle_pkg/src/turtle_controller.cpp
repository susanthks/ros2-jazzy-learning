#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"

using namespace std::chrono_literals;

class TurtleController : public rclcpp::Node
{
public:
    TurtleController()
    : Node("turtle_controller")
    {
        publisher_ =
            this->create_publisher<
                geometry_msgs::msg::Twist>(
                    "/turtle1/cmd_vel",
                    10);

        timer_ =
            this->create_wall_timer(
                500ms,
                std::bind(
                    &TurtleController::move_turtle,
                    this));
    }

private:
    void move_turtle()
    {
        geometry_msgs::msg::Twist msg;

        msg.linear.x = 2.0;

        msg.angular.z = 1.0;

        publisher_->publish(msg);

        RCLCPP_INFO(
            this->get_logger(),
            "Moving Turtle...");
    }

    rclcpp::Publisher<
        geometry_msgs::msg::Twist>::SharedPtr publisher_;

    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    rclcpp::spin(
        std::make_shared<TurtleController>());

    rclcpp::shutdown();

    return 0;
}