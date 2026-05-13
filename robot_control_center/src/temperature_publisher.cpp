#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float32.hpp"

using namespace std::chrono_literals;

class TemperaturePublisher : public rclcpp::Node
{
public:
    TemperaturePublisher()
    : Node("temperature_publisher"), temp_(30.0)
    {
        publisher_ =
            this->create_publisher<std_msgs::msg::Float32>(
                "temperature", 10);

        timer_ =
            this->create_wall_timer(
                1s,
                std::bind(&TemperaturePublisher::publish_data, this));
    }

private:
    void publish_data()
    {
        std_msgs::msg::Float32 msg;

        msg.data = temp_;

        publisher_->publish(msg);

        RCLCPP_INFO(this->get_logger(),
                    "Temperature: %.1f C",
                    temp_);

        temp_ += 2.0;

        if (temp_ > 80.0)
            temp_ = 30.0;
    }

    float temp_;

    rclcpp::Publisher<std_msgs::msg::Float32>::SharedPtr publisher_;

    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    rclcpp::spin(
        std::make_shared<TemperaturePublisher>());

    rclcpp::shutdown();

    return 0;
}