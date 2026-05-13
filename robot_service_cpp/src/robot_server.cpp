#include "rclcpp/rclcpp.hpp"

#include "robot_service_cpp/srv/robot_command.hpp"
#include "robot_service_cpp/msg/robot_status.hpp"

using std::placeholders::_1;
using std::placeholders::_2;

class RobotServer : public rclcpp::Node
{
public:
    RobotServer() : Node("robot_server")
    {
        service_ =
            this->create_service<robot_service_cpp::srv::RobotCommand>(
                "robot_command",
                std::bind(&RobotServer::handle_service,
                          this,
                          _1,
                          _2));

        RCLCPP_INFO(this->get_logger(),
                    "Robot Service Ready");
    }

private:
    void handle_service(
        const std::shared_ptr<
            robot_service_cpp::srv::RobotCommand::Request> request,

        std::shared_ptr<
            robot_service_cpp::srv::RobotCommand::Response> response)
    {
        RCLCPP_INFO(this->get_logger(),
                    "Received Command: %s",
                    request->command.c_str());

        if (request->command == "START")
        {
            response->success = true;
            response->message = "Robot Started";
        }
        else if (request->command == "STOP")
        {
            response->success = true;
            response->message = "Robot Stopped";
        }
        else
        {
            response->success = false;
            response->message = "Unknown Command";
        }

        RCLCPP_INFO(this->get_logger(),
                    "Response Sent");
    }

    rclcpp::Service<
        robot_service_cpp::srv::RobotCommand>::SharedPtr service_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    rclcpp::spin(std::make_shared<RobotServer>());

    rclcpp::shutdown();
    return 0;
}