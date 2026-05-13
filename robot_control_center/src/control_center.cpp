#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float32.hpp"

class ControlCenter : public rclcpp::Node
{
public:
    ControlCenter()
    : Node("control_center")
    {
        battery_sub_ =
            this->create_subscription<std_msgs::msg::Float32>(
                "battery_level",
                10,
                std::bind(&ControlCenter::battery_callback,
                          this,
                          std::placeholders::_1));

        temp_sub_ =
            this->create_subscription<std_msgs::msg::Float32>(
                "temperature",
                10,
                std::bind(&ControlCenter::temp_callback,
                          this,
                          std::placeholders::_1));
    }

private:
    void battery_callback(
        const std_msgs::msg::Float32::SharedPtr msg)
    {
        battery_ = msg->data;

        evaluate_system();
    }

    void temp_callback(
        const std_msgs::msg::Float32::SharedPtr msg)
    {
        temp_ = msg->data;

        evaluate_system();
    }

    void evaluate_system()
    {
        if (battery_ < 20.0)
        {
            RCLCPP_WARN(this->get_logger(),
                        "LOW BATTERY!");
        }

        if (temp_ > 60.0)
        {
            RCLCPP_ERROR(this->get_logger(),
                         "HIGH TEMPERATURE!");
        }

        if (battery_ >= 20.0 && temp_ <= 60.0)
        {
            RCLCPP_INFO(this->get_logger(),
                        "SYSTEM NORMAL");
        }
    }

    float battery_ = 100.0;
    float temp_ = 30.0;

    rclcpp::Subscription<std_msgs::msg::Float32>::SharedPtr battery_sub_;

    rclcpp::Subscription<std_msgs::msg::Float32>::SharedPtr temp_sub_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    rclcpp::spin(
        std::make_shared<ControlCenter>());

    rclcpp::shutdown();

    return 0;
}