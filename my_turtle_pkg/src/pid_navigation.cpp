#include "rclcpp/rclcpp.hpp"

#include "geometry_msgs/msg/twist.hpp"

#include "turtlesim/msg/pose.hpp"

#include <cmath>

class PIDNavigation : public rclcpp::Node
{
public:

    PIDNavigation()
    : Node("pid_navigation")
    {
        pose_subscriber_ =
            this->create_subscription<
                turtlesim::msg::Pose>(
                    "/turtle1/pose",

                    10,

                    std::bind(
                        &PIDNavigation::pose_callback,
                        this,
                        std::placeholders::_1));

        velocity_publisher_ =
            this->create_publisher<
                geometry_msgs::msg::Twist>(
                    "/turtle1/cmd_vel",

                    10);

        timer_ =
            this->create_wall_timer(
                std::chrono::milliseconds(100),

                std::bind(
                    &PIDNavigation::control_loop,
                    this));

        RCLCPP_INFO(
            this->get_logger(),
            "PID Navigation Started");
    }

private:

    void pose_callback(
        const turtlesim::msg::Pose::SharedPtr msg)
    {
        x_ = msg->x;
        y_ = msg->y;
        theta_ = msg->theta;
    }

    void control_loop()
    {
        double target_x = 8.0;
        double target_y = 8.0;

        double distance =
            std::sqrt(
                std::pow(target_x - x_, 2) +
                std::pow(target_y - y_, 2));

        double target_angle =
            std::atan2(
                target_y - y_,
                target_x - x_);

        double error =
            target_angle - theta_;

        // PID TERMS
        integral_ += error;

        double derivative =
            error - previous_error_;

        double output =
            kp_ * error +
            ki_ * integral_ +
            kd_ * derivative;

        previous_error_ = error;

        geometry_msgs::msg::Twist cmd;

        cmd.angular.z = output;

        if(distance > 0.5)
        {
            cmd.linear.x = 2.0;
        }
        else
        {
            cmd.linear.x = 0.0;

            cmd.angular.z = 0.0;

            RCLCPP_INFO(
                this->get_logger(),
                "Target Reached!");
        }

        velocity_publisher_->publish(cmd);

        RCLCPP_INFO(
            this->get_logger(),
            "Error: %.2f | PID Output: %.2f",
            error,
            output);
    }

    // Pose
    double x_ = 5.5;
    double y_ = 5.5;
    double theta_ = 0.0;

    // PID Variables
    double kp_ = 4.0;
    double ki_ = 0.01;
    double kd_ = 1.5;

    double previous_error_ = 0.0;
    double integral_ = 0.0;

    rclcpp::Subscription<
        turtlesim::msg::Pose>::SharedPtr pose_subscriber_;

    rclcpp::Publisher<
        geometry_msgs::msg::Twist>::SharedPtr velocity_publisher_;

    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    rclcpp::spin(
        std::make_shared<PIDNavigation>());

    rclcpp::shutdown();

    return 0;
}