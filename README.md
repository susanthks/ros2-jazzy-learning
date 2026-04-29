# ROS2 C++ Learning Journey 🚀

This repository contains my hands-on robotics projects built using ROS2 Jazzy and Modern C++ (rclcpp).  
The goal is to develop real-time robotic systems and strengthen core ROS2 concepts.

---

## 📌 Projects

### 🔹 1. Publisher–Subscriber (C++)
**Description:**  
Basic communication between two ROS2 nodes using topics.

**Key Features:**
- Publisher node sends messages on `/chatter`
- Subscriber node receives and prints messages
- Demonstrates asynchronous communication

---

### 🔋 2. Battery Monitoring System (C++)
**Description:**  
Simulates a robot battery monitoring system with real-time alerts.

**Key Features:**
- Battery Publisher simulates battery drain (100% → 0%)
- Battery Subscriber monitors battery level
- Implements alert system:
  - ✅ Battery OK (>50%)
  - ⚠️ Battery Low (20–50%)
  - ❌ Battery Critical (<20%)
- Auto reset (charging simulation)

---

## 🧠 Concepts Covered

- ROS2 Nodes  
- Publisher–Subscriber Communication  
- Topics & Message Passing  
- rclcpp (C++ Client Library)  
- Timer-based Execution  
- Callback Functions  
- Real-time Monitoring Systems  

---

## 🏗️ Repository Structure
```bash
ros2-cpp-learning/
│
├── cpp_pub_sub/
│ ├── src/
│ │ ├── publisher.cpp
│ │ ├── subscriber.cpp
│
├── battery_monitor/
│ ├── src/
│ │ ├── battery_publisher.cpp
│ │ ├── battery_subscriber.cpp
│
├── README.md
bash```

---

## ▶️ How to Run

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

---
Run Publisher–Subscriber
ros2 run cpp_pub_sub publisher
ros2 run cpp_pub_sub subscriber
---
Run Battery Monitoring System
ros2 run battery_monitor battery_publisher
ros2 run battery_monitor battery_subscriber
---
📸 Sample Output

Publisher–Subscriber

Publishing: Hello I'm Ready: 0
Received: Hello I'm Ready: 0

Battery Monitoring

Battery OK: 78.5%
Battery Low: 45.0%
Battery CRITICAL: 18.5%

---

🛠️ Technologies Used
ROS2 Jazzy
Modern C++
rclcpp
Ubuntu Linux
🚀 Future Work
Temperature Sensor System 🌡️
Distance Sensor (Obstacle Detection) 📏
Multi-Sensor Monitoring System 🤖
Turtlesim Automation
ROS2 + OpenCV Integration
SLAM Implementation
🎯 Goal

To build strong expertise in robotics software development using ROS2 and C++, and apply these concepts in real-world robotic systems.

🤝 Connect with Me

LinkedIn: [(https://www.linkedin.com/in/susanth-k-s-93a110325/)]

