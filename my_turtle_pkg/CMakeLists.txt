cmake_minimum_required(VERSION 3.8)

project(my_turtle_pkg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Dependencies
find_package(ament_cmake REQUIRED)

find_package(rclcpp REQUIRED)

find_package(geometry_msgs REQUIRED)

find_package(turtlesim REQUIRED)

find_package(tf2 REQUIRED)

find_package(tf2_ros REQUIRED)

# Turtle Controller
add_executable(turtle_controller
  src/turtle_controller.cpp
)

ament_target_dependencies(
  turtle_controller
  rclcpp
  geometry_msgs
)

# Draw Square
add_executable(draw_square
  src/draw_square.cpp
)

ament_target_dependencies(
  draw_square
  rclcpp
  geometry_msgs
)

# Pose Subscriber
add_executable(pose_subscriber
  src/pose_subscriber.cpp
)

ament_target_dependencies(
  pose_subscriber
  rclcpp
  turtlesim
)

# Turtle Follower
add_executable(turtle_follower
  src/turtle_follower.cpp
)

ament_target_dependencies(
  turtle_follower
  rclcpp
  geometry_msgs
  turtlesim
)

# Obstacle Avoidance
add_executable(obstacle_avoidance
  src/obstacle_avoidance.cpp
)

ament_target_dependencies(
  obstacle_avoidance
  rclcpp
  geometry_msgs
  turtlesim
)

add_executable(waypoint_navigation
  src/waypoint_navigation.cpp
)

ament_target_dependencies(
  waypoint_navigation
  rclcpp
  geometry_msgs
  turtlesim
)

add_executable(pid_navigation
  src/pid_navigation.cpp
)

ament_target_dependencies(
  pid_navigation
  rclcpp
  geometry_msgs
  turtlesim
)

add_executable(turtle_tf_broadcaster
  src/turtle_tf_broadcaster.cpp
)

ament_target_dependencies(
  turtle_tf_broadcaster
  rclcpp
  turtlesim
  tf2
  tf2_ros
  geometry_msgs

)

# Install Nodes
install(TARGETS

  turtle_controller
  draw_square
  pose_subscriber
  turtle_follower
  obstacle_avoidance
  waypoint_navigation
  pid_navigation
  turtle_tf_broadcaster
  DESTINATION lib/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()