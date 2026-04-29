#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float32.hpp"

class BatterySubscriber : public rclcpp::Node
{
public:
    BatterySubscriber() : Node("battery_subscriber")
    {
        subscription_ = this->create_subscription<std_msgs::msg::Float32>(
            "battery_level", 10,
            std::bind(&BatterySubscriber::callback, this, std::placeholders::_1));
    }

private:
    void callback(const std_msgs::msg::Float32::SharedPtr msg)
    {
        float level = msg->data;

        if (level > 50)
        {
            RCLCPP_INFO(this->get_logger(), "Battery OK: %.2f%%", level);
        }
        else if (level > 20)
        {
            RCLCPP_WARN(this->get_logger(), "Battery Low: %.2f%%", level);
        }
        else
        {
            RCLCPP_ERROR(this->get_logger(), "Battery CRITICAL: %.2f%%", level);
        }
    }

    rclcpp::Subscription<std_msgs::msg::Float32>::SharedPtr subscription_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<BatterySubscriber>());
    rclcpp::shutdown();
    return 0;
}