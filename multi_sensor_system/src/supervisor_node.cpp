#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float32.hpp"

class SupervisorNode : public rclcpp::Node
{
public:
    SupervisorNode() : Node("supervisor_node")
    {
        battery_sub_ = this->create_subscription<std_msgs::msg::Float32>(
            "/battery_level", 10,
            std::bind(&SupervisorNode::battery_callback, this, std::placeholders::_1));

        temp_sub_ = this->create_subscription<std_msgs::msg::Float32>(
            "/temperature", 10,
            std::bind(&SupervisorNode::temp_callback, this, std::placeholders::_1));

        distance_sub_ = this->create_subscription<std_msgs::msg::Float32>(
            "/distance", 10,
            std::bind(&SupervisorNode::distance_callback, this, std::placeholders::_1));
    }

private:
    float battery_ = 100.0;
    float temperature_ = 25.0;
    float distance_ = 2.0;

    void battery_callback(const std_msgs::msg::Float32::SharedPtr msg)
    {
        battery_ = msg->data;
        evaluate_system();
    }

    void temp_callback(const std_msgs::msg::Float32::SharedPtr msg)
    {
        temperature_ = msg->data;
        evaluate_system();
    }

    void distance_callback(const std_msgs::msg::Float32::SharedPtr msg)
    {
        distance_ = msg->data;
        evaluate_system();
    }

    void evaluate_system()
    {
        // Priority logic
        if (distance_ < 0.5)
        {
            RCLCPP_ERROR(this->get_logger(), "🚨 OBSTACLE DETECTED → STOP ROBOT");
        }
        else if (battery_ < 20.0)
        {
            RCLCPP_WARN(this->get_logger(), "⚠️ LOW BATTERY → REDUCE OPERATIONS");
        }
        else if (temperature_ > 60.0)
        {
            RCLCPP_WARN(this->get_logger(), "🔥 HIGH TEMP → ACTIVATE COOLING");
        }
        else
        {
            RCLCPP_INFO(this->get_logger(), "✅ SYSTEM NORMAL");
        }
    }

    rclcpp::Subscription<std_msgs::msg::Float32>::SharedPtr battery_sub_;
    rclcpp::Subscription<std_msgs::msg::Float32>::SharedPtr temp_sub_;
    rclcpp::Subscription<std_msgs::msg::Float32>::SharedPtr distance_sub_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<SupervisorNode>());
    rclcpp::shutdown();
    return 0;
}