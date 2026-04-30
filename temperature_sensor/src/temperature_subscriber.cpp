#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float32.hpp"

class TemperatureSubscriber : public rclcpp::Node
{
public:
    TemperatureSubscriber() : Node("temperature_subscriber")
    {
        subscription_ = this->create_subscription<std_msgs::msg::Float32>(
            "temperature", 10,
            std::bind(&TemperatureSubscriber::callback, this, std::placeholders::_1));
    }

private:
    void callback(const std_msgs::msg::Float32::SharedPtr msg)
    {
        float temp = msg->data;

        if (temp < 40.0)
        {
            RCLCPP_INFO(this->get_logger(), "Temperature Normal: %.2f °C", temp);
        }
        else if (temp < 60.0)
        {
            RCLCPP_WARN(this->get_logger(), "Temperature High: %.2f °C", temp);
        }
        else
        {
            RCLCPP_ERROR(this->get_logger(), "Temperature CRITICAL: %.2f °C", temp);
        }
    }

    rclcpp::Subscription<std_msgs::msg::Float32>::SharedPtr subscription_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<TemperatureSubscriber>());
    rclcpp::shutdown();
    return 0;
}