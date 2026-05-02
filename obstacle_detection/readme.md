# 📏 ROS2 C++ Obstacle Detection System

A real-time obstacle detection system built using ROS2 Jazzy and Modern C++ (rclcpp).  
This project demonstrates how robotic systems detect obstacles and assess environmental safety using distance sensors with ROS2 topic communication.

---

## 📌 Overview

This system simulates distance sensors and continuously monitors for obstacles using ROS2 pub/sub architecture.

- **Distance Publisher** → Generates distance readings (simulates sensor data)
- **Distance Subscriber** → Monitors distance and provides alerts based on thresholds

---

## ⚙️ Features

- Real-time distance data publishing  
- Continuous obstacle detection simulation  
- Intelligent alert system:
  - ✅ **SAFE** (> 1.0m)
  - ⚠️ **CAUTION** (0.5m – 1.0m)
  - ❌ **OBSTACLE DETECTED! STOP** (< 0.5m)
- Configurable sensor frequency
- Multi-sensor support capability

---

## 🧠 Concepts Covered

- ROS2 Nodes  
- Publisher–Subscriber architecture  
- Topic-based communication  
- std_msgs/msg/Float32  
- Timer-based execution  
- Callback-driven monitoring  
- Distance-based decision logic  

---

## 🏗️ Project Structure
```bash
obstacle_detection/
├── src/
│   ├── distance_publisher.cpp
│   ├── distance_subscriber.cpp
├── CMakeLists.txt
├── package.xml
```

---
## ▶️ How to Run
```bash
# Create workspace
mkdir -p ~/ros2_ws/src
cd ~/ros2_ws/src

# Clone repository
git clone https://github.com/susanthks/ros2-jazzy-learning.git

# Build
cd ~/ros2_ws
colcon build
source install/setup.bash

# Run Publisher
ros2 run obstacle_detection distance_publisher

# Run Subscriber
ros2 run obstacle_detection distance_subscriber
```

---

# 📸 Output
```bash
Distance: 1.45 m
SAFE: 1.45 m

Distance: 0.72 m
CAUTION: 0.72 m

Distance: 0.32 m
OBSTACLE DETECTED! STOP: 0.32 m
```

---

# 🔍 Verification
```bash
ros2 topic list
ros2 topic echo /obstacle_distance
```

# 💡 Why This Project Matters

Obstacle detection is a critical component in robotics and autonomous systems.
This project simulates how systems:

- Continuously monitor environmental obstacles
- Detect proximity hazards
- Trigger alerts or evasive actions based on thresholds

Such systems are essential in autonomous robots, self-driving vehicles, drones, and collision avoidance systems.

# 🛠️ Technologies Used
- ROS2 Jazzy
- Modern C++ (C++17)
- rclcpp
- Ubuntu Linux
