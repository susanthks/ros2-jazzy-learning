#include "rclcpp/rclcpp.hpp"

#include "robot_control_center/srv/robot_command.hpp"

using std::placeholders::_1;
using std::placeholders::_2;

class RobotServer : public rclcpp::Node
{
public:
    RobotServer()
    : Node("robot_server")
    {
        service_ =
            this->create_service<
                robot_control_center::srv::RobotCommand>(
                    "robot_command",

                    std::bind(
                        &RobotServer::handle_service,
                        this,
                        _1,
                        _2));

        RCLCPP_INFO(this->get_logger(),
                    "Robot Service Ready");
    }

private:
    void handle_service(
        const std::shared_ptr<
            robot_control_center::srv::RobotCommand::Request> request,

        std::shared_ptr<
            robot_control_center::srv::RobotCommand::Response> response)
    {
        std::string cmd = request->command;

        RCLCPP_INFO(this->get_logger(),
                    "Received Command: %s",
                    cmd.c_str());

        if (cmd == "START")
        {
            response->success = true;
            response->message = "Robot Started";
        }
        else if (cmd == "STOP")
        {
            response->success = true;
            response->message = "Robot Stopped";
        }
        else if (cmd == "SAFE_MODE")
        {
            response->success = true;
            response->message = "Safe Mode Activated";
        }
        else if (cmd == "AUTONOMOUS")
        {
            response->success = true;
            response->message = "Autonomous Mode Enabled";
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
        robot_control_center::srv::RobotCommand>::SharedPtr service_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    rclcpp::spin(
        std::make_shared<RobotServer>());

    rclcpp::shutdown();

    return 0;
}