cmake_minimum_required(VERSION 3.8)
project(robot_service_cpp)


cmake_minimum_required(VERSION 3.8)
project(robot_service_cpp)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)

# =========================
# Generate Interfaces
# =========================

rosidl_generate_interfaces(${PROJECT_NAME}

  "msg/RobotStatus.msg"

  "srv/RobotCommand.srv"

)

# =========================
# Server
# =========================

add_executable(robot_server src/robot_server.cpp)

ament_target_dependencies(
  robot_server
  rclcpp
  std_msgs
)

# =========================
# Client
# =========================

add_executable(robot_client src/robot_client.cpp)

ament_target_dependencies(
  robot_client
  rclcpp
  std_msgs
)

# =========================
# Link interfaces
# =========================

rosidl_target_interfaces(robot_server
  ${PROJECT_NAME} "rosidl_typesupport_cpp")

rosidl_target_interfaces(robot_client
  ${PROJECT_NAME} "rosidl_typesupport_cpp")

# =========================
# Install
# =========================

install(TARGETS
  robot_server
  robot_client
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()