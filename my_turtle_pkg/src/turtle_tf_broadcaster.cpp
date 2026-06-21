#include "rclcpp/rclcpp.hpp"

#include "turtlesim/msg/pose.hpp"

#include "tf2_ros/transform_broadcaster.h"

#include "geometry_msgs/msg/transform_stamped.hpp"

#include "tf2/LinearMath/Quaternion.h"

#include <memory>

class TurtleTFBroadcaster : public rclcpp::Node
{
public:

    TurtleTFBroadcaster()
    : Node("turtle_tf_broadcaster")
    {
        tf_broadcaster_ =
            std::make_unique<
                tf2_ros::TransformBroadcaster>(*this);

        pose_subscriber_ =
            this->create_subscription<
                turtlesim::msg::Pose>(
                    "/turtle1/pose",

                    10,

                    std::bind(
                        &TurtleTFBroadcaster::pose_callback,
                        this,
                        std::placeholders::_1));

        RCLCPP_INFO(
            this->get_logger(),
            "TF Broadcaster Started");
    }

private:

    void pose_callback(
        const turtlesim::msg::Pose::SharedPtr msg)
    {
        geometry_msgs::msg::TransformStamped transform;

        transform.header.stamp =
            this->get_clock()->now();

        transform.header.frame_id = "world";

        transform.child_frame_id = "turtle1";

        transform.transform.translation.x = msg->x;

        transform.transform.translation.y = msg->y;

        transform.transform.translation.z = 0.0;

        tf2::Quaternion q;

        q.setRPY(0, 0, msg->theta);

        transform.transform.rotation.x = q.x();

        transform.transform.rotation.y = q.y();

        transform.transform.rotation.z = q.z();

        transform.transform.rotation.w = q.w();

        tf_broadcaster_->sendTransform(transform);
    }

    rclcpp::Subscription<
        turtlesim::msg::Pose>::SharedPtr pose_subscriber_;

    std::unique_ptr<
        tf2_ros::TransformBroadcaster> tf_broadcaster_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);

    rclcpp::spin(
        std::make_shared<TurtleTFBroadcaster>());

    rclcpp::shutdown();

    return 0;
}