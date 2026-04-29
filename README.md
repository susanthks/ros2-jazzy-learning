# ROS2 C++ Learning Journey 🚀

This repository contains my hands-on projects built using ROS2 Jazzy and Modern C++ (rclcpp).

---

## 📌 Project: Publisher - Subscriber (C++)

### 🔧 Overview
This project demonstrates communication between two ROS2 nodes using topics.

- Publisher Node: Sends string messages
- Subscriber Node: Receives and displays messages

---

### 🧠 Concepts Used
- ROS2 Nodes
- Topics (Publisher / Subscriber)
- rclcpp (C++ client library)
- Timer-based execution
- Callback functions

---

### ▶️ How to Run

```bash
# Create workspace
mkdir -p ~/ros2_ws/src
cd ~/ros2_ws/src

# Clone repository
git clone https://github.com/YOUR_USERNAME/ros2-cpp-learning.git

# Build
cd ~/ros2_ws
colcon build
source install/setup.bash

# Run Publisher
ros2 run cpp_pub_sub publisher

# Run Subscriber
ros2 run cpp_pub_sub subscriber
