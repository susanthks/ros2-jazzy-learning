#include "rclcpp/rclcpp.hpp"

#include "geometry_msgs/msg/twist.hpp"
#include "turtlesim/msg/pose.hpp"

class ObstacleAvoidance : public rclcpp::Node
{
public:
    ObstacleAvoidance()
    : Node("obstacle_avoidance")
    {
        pose_subscriber_ =
            this->create_subscription<
                turtlesim::msg::Pose>(
                    "/turtle1/pose",

                    10,

                    std::bind(
                        &ObstacleAvoidance::pose_callback,
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
                    &ObstacleAvoidance::move_robot,
                    this));
    }

private:
    void pose_callback(
        const turtlesim::msg::Pose::SharedPtr msg)
    {
        x_ = msg->x;
        y_ = msg->y;
    }

    void move_robot()
    {
        geometry_msgs::msg::Twist cmd;

        bool near_wall =
            (x_ > 9.0 || x_ < 2.0 ||
             y_ > 9.0 || y_ < 2.0);

        if(near_wall)
        {
            cmd.linear.x = 0.0;

            cmd.angular.z = 2.0;

            RCLCPP_WARN(
                this->get_logger(),
                "Obstacle Detected! Turning...");
        }
        else
        {
            cmd.linear.x = 2.0;

            cmd.angular.z = 0.0;
        }

        velocity_publisher_->publish(cmd);
    }

    double x_ = 5.5;
    double y_ = 5.5;

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
        std::make_shared<ObstacleAvoidance>());

    rclcpp::shutdown();

    return 0;
}