#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float32.hpp"

using namespace std::chrono_literals;

class BatteryPublisher : public rclcpp::Node
{
public:
    BatteryPublisher()
    : Node("battery_publisher"), battery_(100.0)
    {
        publisher_ =
            this->create_publisher<std_msgs::msg::Float32>(
                "battery_level", 10);

        timer_ =
            this->create_wall_timer(
                1s,
                std::bind(&BatteryPublisher::publish_data, this));
    }

private:
    void publish_data()
    {
        std_msgs::msg::Float32 msg;

        msg.data = battery_;

        publisher_->publish(msg);

        RCLCPP_INFO(this->get_logger(),
                    "Battery: %.1f%%",
                    battery_);

        battery_ -= 5.0;

        if (battery_ < 0.0)
            battery_ = 100.0;
    }

    float battery_;

    rclcpp::Publisher<std_msgs::msg::Float32>::SharedPtr publisher_;

    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    rclcpp::spin(
        std::make_shared<BatteryPublisher>());

    rclcpp::shutdown();

    return 0;
}