cmake_minimum_required(VERSION 3.8)

project(robot_control_center)

# =====================================
# Compiler Options
# =====================================

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# =====================================
# Find Packages
# =====================================

find_package(ament_cmake REQUIRED)

find_package(rclcpp REQUIRED)

find_package(std_msgs REQUIRED)

find_package(rosidl_default_generators REQUIRED)

# =====================================
# Generate Interfaces
# =====================================

rosidl_generate_interfaces(${PROJECT_NAME}

  "msg/RobotStatus.msg"

  "srv/RobotCommand.srv"

)

# =====================================
# Battery Publisher
# =====================================

add_executable(battery_publisher
  src/battery_publisher.cpp
)

ament_target_dependencies(
  battery_publisher
  rclcpp
  std_msgs
)

# =====================================
# Temperature Publisher
# =====================================

add_executable(temperature_publisher
  src/temperature_publisher.cpp
)

ament_target_dependencies(
  temperature_publisher
  rclcpp
  std_msgs
)

# =====================================
# Control Center
# =====================================

add_executable(control_center
  src/control_center.cpp
)

ament_target_dependencies(
  control_center
  rclcpp
  std_msgs
)

# =====================================
# Robot Server
# =====================================

add_executable(robot_server
  src/robot_server.cpp
)

ament_target_dependencies(
  robot_server
  rclcpp
  std_msgs
)

# =====================================
# Robot Client
# =====================================

add_executable(robot_client
  src/robot_client.cpp
)

ament_target_dependencies(
  robot_client
  rclcpp
  std_msgs
)

# =====================================
# Link Interfaces
# =====================================

rosidl_target_interfaces(
  robot_server
  ${PROJECT_NAME}
  "rosidl_typesupport_cpp"
)

rosidl_target_interfaces(
  robot_client
  ${PROJECT_NAME}
  "rosidl_typesupport_cpp"
)

# =====================================
# Install Targets
# =====================================

install(TARGETS

  battery_publisher

  temperature_publisher

  control_center

  robot_server

  robot_client

  DESTINATION lib/${PROJECT_NAME}

)

# =====================================
# Package
# =====================================

ament_package()