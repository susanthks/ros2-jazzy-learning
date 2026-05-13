#include "rclcpp/rclcpp.hpp"

#include "turtlesim/msg/pose.hpp"

class PoseSubscriber : public rclcpp::Node
{
public:
    PoseSubscriber()
    : Node("pose_subscriber")
    {
        subscription_ =
            this->create_subscription<
                turtlesim::msg::Pose>(
                    "/turtle1/pose",

                    10,

                    std::bind(
                        &PoseSubscriber::pose_callback,
                        this,
                        std::placeholders::_1));
    }

private:
    void pose_callback(
        const turtlesim::msg::Pose::SharedPtr msg)
    {
        RCLCPP_INFO(
            this->get_logger(),

            "X: %.2f | Y: %.2f | Theta: %.2f",

            msg->x,
            msg->y,
            msg->theta);
    }

    rclcpp::Subscription<
        turtlesim::msg::Pose>::SharedPtr subscription_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    rclcpp::spin(
        std::make_shared<PoseSubscriber>());

    rclcpp::shutdown();

    return 0;
}