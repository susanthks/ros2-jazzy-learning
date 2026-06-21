#include "rclcpp/rclcpp.hpp"

#include "geometry_msgs/msg/twist.hpp"

#include "turtlesim/msg/pose.hpp"

#include <vector>
#include <cmath>

class WaypointNavigation : public rclcpp::Node
{
public:

    WaypointNavigation()
    : Node("waypoint_navigation")
    {
        pose_subscriber_ =
            this->create_subscription<
                turtlesim::msg::Pose>(
                    "/turtle1/pose",

                    10,

                    std::bind(
                        &WaypointNavigation::pose_callback,
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
                    &WaypointNavigation::navigate,
                    this));

        waypoints_ = {
            {2.0, 2.0},
            {8.0, 2.0},
            {8.0, 8.0},
            {2.0, 8.0}
        };

        RCLCPP_INFO(
            this->get_logger(),
            "Waypoint Navigation Started");
    }

private:

    void pose_callback(
        const turtlesim::msg::Pose::SharedPtr msg)
    {
        x_ = msg->x;
        y_ = msg->y;
        theta_ = msg->theta;
    }

    void navigate()
    {
        if(current_waypoint_ >= waypoints_.size())
        {
            geometry_msgs::msg::Twist stop_msg;

            velocity_publisher_->publish(stop_msg);

            RCLCPP_INFO(
                this->get_logger(),
                "All Waypoints Completed!");

            return;
        }

        double target_x =
            waypoints_[current_waypoint_].first;

        double target_y =
            waypoints_[current_waypoint_].second;

        double distance =
            std::sqrt(
                std::pow(target_x - x_, 2) +
                std::pow(target_y - y_, 2));

        double target_angle =
            std::atan2(
                target_y - y_,
                target_x - x_);

        double angle_error =
            target_angle - theta_;

        geometry_msgs::msg::Twist cmd;

        // Rotate toward target
        if(std::abs(angle_error) > 0.1)
        {
            cmd.angular.z = 2.0 * angle_error;

            cmd.linear.x = 0.0;
        }

        // Move forward
        else
        {
            cmd.linear.x = 2.0;

            cmd.angular.z = 0.0;
        }

        velocity_publisher_->publish(cmd);

        RCLCPP_INFO(
            this->get_logger(),
            "Target: (%.2f, %.2f) | Distance: %.2f",
            target_x,
            target_y,
            distance);

        // Reached waypoint
        if(distance < 0.5)
        {
            RCLCPP_INFO(
                this->get_logger(),
                "Reached Waypoint %ld",
                current_waypoint_ + 1);

            current_waypoint_++;
        }
    }

    double x_ = 5.5;
    double y_ = 5.5;
    double theta_ = 0.0;

    std::vector<
        std::pair<double,double>> waypoints_;

    size_t current_waypoint_ = 0;

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
        std::make_shared<WaypointNavigation>());

    rclcpp::shutdown();

    return 0;
}