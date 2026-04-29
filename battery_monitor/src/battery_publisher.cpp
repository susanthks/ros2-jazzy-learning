#include <memory>
#include <chrono>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float32.hpp"

using namespace std::chrono_literals;

class BatteryPublisher : public rclcpp::Node
{
public:
    BatteryPublisher() : Node("battery_publisher"), battery_level_(100.0)
    {
        publisher_ = this->create_publisher<std_msgs::msg::Float32>("battery_level", 10);

        timer_ = this->create_wall_timer(
            1s, std::bind(&BatteryPublisher::publish_battery, this));
    }

private:
    void publish_battery()
    {
        auto msg = std_msgs::msg::Float32();
        msg.data = battery_level_;

        RCLCPP_INFO(this->get_logger(), "Battery Level: %.2f%%", battery_level_);
        publisher_->publish(msg);

        // Simulate battery drain
        battery_level_ -= 0.5;

        // Reset (charging simulation)
        if (battery_level_ <= 0.0)
        {
            RCLCPP_WARN(this->get_logger(), "Battery empty! Charging...");
            battery_level_ = 100.0;
        }
    }

    rclcpp::Publisher<std_msgs::msg::Float32>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    float battery_level_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<BatteryPublisher>());
    rclcpp::shutdown();
    return 0;
}