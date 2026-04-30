#include <memory>
#include <chrono>
#include <random>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float32.hpp"

using namespace std::chrono_literals;

class TemperaturePublisher : public rclcpp::Node
{
public:
    TemperaturePublisher() : Node("temperature_publisher")
    {
        publisher_ = this->create_publisher<std_msgs::msg::Float32>("temperature", 10);

        // Random temperature generator (20°C to 80°C)
        std::random_device rd;
        gen_ = std::mt19937(rd());
        dist_ = std::uniform_real_distribution<>(20.0, 80.0);

        timer_ = this->create_wall_timer(
            1s, std::bind(&TemperaturePublisher::publish_temperature, this));
    }

private:
    void publish_temperature()
    {
        auto msg = std_msgs::msg::Float32();
        float temp = dist_(gen_);

        msg.data = temp;

        RCLCPP_INFO(this->get_logger(), "Temperature: %.2f °C", temp);
        publisher_->publish(msg);
    }

    rclcpp::Publisher<std_msgs::msg::Float32>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;

    std::mt19937 gen_;
    std::uniform_real_distribution<> dist_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<TemperaturePublisher>());
    rclcpp::shutdown();
    return 0;
}