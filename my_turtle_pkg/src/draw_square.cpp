#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"

#include <chrono>
#include <thread>

using namespace std::chrono_literals;

class DrawSquare : public rclcpp::Node
{
public:
    DrawSquare()
    : Node("draw_square")
    {
        publisher_ =
            this->create_publisher<
                geometry_msgs::msg::Twist>(
                    "/turtle1/cmd_vel",
                    10);

        timer_ =
            this->create_wall_timer(
                1s,
                std::bind(
                    &DrawSquare::draw_square,
                    this));
    }

private:
    void move_forward()
    {
        geometry_msgs::msg::Twist msg;

        msg.linear.x = 2.0;
        msg.angular.z = 0.0;

        for(int i = 0; i < 20; i++)
        {
            publisher_->publish(msg);

            rclcpp::sleep_for(100ms);
        }
    }

    void turn_left()
    {
        geometry_msgs::msg::Twist msg;

        msg.linear.x = 0.0;
        msg.angular.z = 1.57;

        for(int i = 0; i < 10; i++)
        {
            publisher_->publish(msg);

            rclcpp::sleep_for(100ms);
        }
    }

    void stop_turtle()
    {
        geometry_msgs::msg::Twist msg;

        msg.linear.x = 0.0;
        msg.angular.z = 0.0;

        publisher_->publish(msg);
    }

    void draw_square()
    {
        timer_->cancel();

        RCLCPP_INFO(
            this->get_logger(),
            "Drawing Square...");

        for(int i = 0; i < 4; i++)
        {
            move_forward();

            turn_left();
        }

        stop_turtle();

        RCLCPP_INFO(
            this->get_logger(),
            "Square Completed!");
    }

    rclcpp::Publisher<
        geometry_msgs::msg::Twist>::SharedPtr publisher_;

    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    rclcpp::spin(
        std::make_shared<DrawSquare>());

    rclcpp::shutdown();

    return 0;
}