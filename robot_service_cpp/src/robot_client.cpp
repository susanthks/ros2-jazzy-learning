#include "rclcpp/rclcpp.hpp"

#include "robot_service_cpp/srv/robot_command.hpp"

using namespace std::chrono_literals;

class RobotClient : public rclcpp::Node
{
public:
    RobotClient()
    : Node("robot_client")
    {
        client_ =
            this->create_client<
                robot_service_cpp::srv::RobotCommand>(
                    "robot_command");
    }

    void send_request()
    {
        while (!client_->wait_for_service(1s))
        {
            RCLCPP_WARN(this->get_logger(),
                        "Waiting for service...");
        }

        auto request =
            std::make_shared<
                robot_service_cpp::srv::RobotCommand::Request>();

        request->command = "START";

        auto future = client_->async_send_request(request);

        // Wait for response
        if (rclcpp::spin_until_future_complete(
                this->get_node_base_interface(),
                future) ==
            rclcpp::FutureReturnCode::SUCCESS)
        {
            auto response = future.get();

            RCLCPP_INFO(this->get_logger(),
                        "Success: %d",
                        response->success);

            RCLCPP_INFO(this->get_logger(),
                        "Message: %s",
                        response->message.c_str());
        }
        else
        {
            RCLCPP_ERROR(this->get_logger(),
                         "Failed to call service");
        }
    }

private:
    rclcpp::Client<
        robot_service_cpp::srv::RobotCommand>::SharedPtr client_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    auto node = std::make_shared<RobotClient>();

    node->send_request();

    rclcpp::shutdown();

    return 0;
}