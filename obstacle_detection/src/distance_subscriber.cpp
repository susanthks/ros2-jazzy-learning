#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float32.hpp"

class DistanceSubscriber : public rclcpp::Node
{
public:
    DistanceSubscriber() : Node("distance_subscriber")
    {
        subscription_ = this->create_subscription<std_msgs::msg::Float32>(
            "distance",
            10,
            std::bind(&DistanceSubscriber::callback, this, std::placeholders::_1));
    }

private:
    void callback(const std_msgs::msg::Float32::SharedPtr msg)
    {
        float distance = msg->data;

        if (distance > 1.0)
        {
            RCLCPP_INFO(this->get_logger(), "SAFE: %.2f m", distance);
        }
        else if (distance > 0.5)
        {
            RCLCPP_WARN(this->get_logger(), "CAUTION: %.2f m", distance);
        }
        else
        {
            RCLCPP_ERROR(this->get_logger(), "OBSTACLE DETECTED! STOP: %.2f m", distance);
        }
    }

    rclcpp::Subscription<std_msgs::msg::Float32>::SharedPtr subscription_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<DistanceSubscriber>());
    rclcpp::shutdown();
    return 0;
}