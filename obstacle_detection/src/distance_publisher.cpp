#include <memory>
#include <chrono>
#include <random>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float32.hpp"

using namespace std::chrono_literals;

class DistancePublisher : public rclcpp::Node
{
public:
    DistancePublisher() : Node("distance_publisher")
    {
        publisher_ = this->create_publisher<std_msgs::msg::Float32>("distance", 10);

        std::random_device rd;
        gen_ = std::mt19937(rd());
        dist_ = std::uniform_real_distribution<>(0.2, 2.0);

        timer_ = this->create_wall_timer(
            1s,
            std::bind(&DistancePublisher::publish_distance, this));
    }

private:
    void publish_distance()
    {
        auto msg = std_msgs::msg::Float32();
        float distance = dist_(gen_);

        msg.data = distance;

        RCLCPP_INFO(this->get_logger(), "Distance: %.2f m", distance);
        publisher_->publish(msg);
    }

    rclcpp::Publisher<std_msgs::msg::Float32>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;

    std::mt19937 gen_;
    std::uniform_real_distribution<> dist_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<DistancePublisher>());
    rclcpp::shutdown();
    return 0;
}