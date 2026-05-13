#include "rclcpp/rclcpp.hpp"

#include "geometry_msgs/msg/twist.hpp"

#include "turtlesim/msg/pose.hpp"

#include <cmath>

class TurtleFollower : public rclcpp::Node
{
public:
    TurtleFollower()
    : Node("turtle_follower")
    {
        turtle1_sub_ =
            this->create_subscription<
                turtlesim::msg::Pose>(
                    "/turtle1/pose",

                    10,

                    std::bind(
                        &TurtleFollower::turtle1_callback,
                        this,
                        std::placeholders::_1));

        turtle2_sub_ =
            this->create_subscription<
                turtlesim::msg::Pose>(
                    "/turtle2/pose",

                    10,

                    std::bind(
                        &TurtleFollower::turtle2_callback,
                        this,
                        std::placeholders::_1));

        publisher_ =
            this->create_publisher<
                geometry_msgs::msg::Twist>(
                    "/turtle2/cmd_vel",

                    10);

        timer_ =
            this->create_wall_timer(
                std::chrono::milliseconds(100),

                std::bind(
                    &TurtleFollower::follow_turtle,
                    this));
    }

private:
    void turtle1_callback(
        const turtlesim::msg::Pose::SharedPtr msg)
    {
        turtle1_x_ = msg->x;
        turtle1_y_ = msg->y;
    }

    void turtle2_callback(
        const turtlesim::msg::Pose::SharedPtr msg)
    {
        turtle2_x_ = msg->x;
        turtle2_y_ = msg->y;
        turtle2_theta_ = msg->theta;
    }

    void follow_turtle()
    {
        geometry_msgs::msg::Twist cmd;

        double dx = turtle1_x_ - turtle2_x_;
        double dy = turtle1_y_ - turtle2_y_;

        double distance =
            std::sqrt(dx * dx + dy * dy);

        double angle_to_target =
            std::atan2(dy, dx);

        double angle_error =
            angle_to_target - turtle2_theta_;

        cmd.linear.x = 1.5 * distance;

        cmd.angular.z = 4.0 * angle_error;

        publisher_->publish(cmd);
    }

    double turtle1_x_ = 0.0;
    double turtle1_y_ = 0.0;

    double turtle2_x_ = 0.0;
    double turtle2_y_ = 0.0;
    double turtle2_theta_ = 0.0;

    rclcpp::Subscription<
        turtlesim::msg::Pose>::SharedPtr turtle1_sub_;

    rclcpp::Subscription<
        turtlesim::msg::Pose>::SharedPtr turtle2_sub_;

    rclcpp::Publisher<
        geometry_msgs::msg::Twist>::SharedPtr publisher_;

    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    rclcpp::spin(
        std::make_shared<TurtleFollower>());

    rclcpp::shutdown();

    return 0;
}