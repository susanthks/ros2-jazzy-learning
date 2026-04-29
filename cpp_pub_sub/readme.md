# ROS2 C++ Publisher–Subscriber 🚀

This project demonstrates a simple Publisher–Subscriber communication system using ROS2 Jazzy and Modern C++ (rclcpp).

---

## 📌 Overview
- Publisher Node → Sends messages on `/chatter`
- Subscriber Node → Receives and prints messages  
- Demonstrates real-time communication between ROS2 nodes

---

## 🧠 Concepts Used
- ROS2 Nodes  
- Topics (Publisher / Subscriber)  
- rclcpp (C++ client library)  
- Timer-based execution  
- Callback functions  

---

## 🏗️ Project Structure
cpp_pub_sub/
├── src/
│ ├── publisher.cpp
│ ├── subscriber.cpp
├── CMakeLists.txt
├── package.xml

---

## ▶️ How to Run
```bash
# Create workspace
mkdir -p ~/simple_pub_sub_ws/src
cd ~/ros2_ws/src

# Clone repository
git clone https://github.com/susanthks/ros2-jazzy-learning.git

# Build
cd ~/simple_pub_sub_ws
colcon build
source install/setup.bash

# Run Publisher
ros2 run cpp_pub_sub publisher

# Run Subscriber
ros2 run cpp_pub_sub subscriber

📸 Output

Publisher:

Publishing: Hello ROS2 (C++): 0
Publishing: Hello ROS2 (C++): 1

Subscriber:

Received: Hello ROS2 (C++): 0
Received: Hello ROS2 (C++): 1
