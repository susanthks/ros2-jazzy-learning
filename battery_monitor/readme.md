# 🔋 ROS2 C++ Battery Monitoring System

A real-time battery monitoring simulation built using ROS2 Jazzy and Modern C++ (rclcpp).  
This project demonstrates how robotic systems track battery health and respond to different energy levels.

---

## 📌 Overview

This system simulates a robot’s battery behavior and continuously monitors its status using ROS2 topic communication.

- **Battery Publisher** → Simulates battery drain (100% → 0%)
- **Battery Subscriber** → Monitors battery level and provides alerts

---

## ⚙️ Features

- Real-time battery level publishing  
- Continuous battery drain simulation  
- Intelligent alert system:
  - ✅ **Battery OK** (> 50%)
  - ⚠️ **Battery Low** (20% – 50%)
  - ❌ **Battery Critical** (< 20%)
- Auto-reset mechanism (simulates charging cycle)

---

## 🧠 Concepts Covered

- ROS2 Nodes  
- Publisher–Subscriber architecture  
- Topic-based communication  
- std_msgs/msg/Float32  
- Timer-based execution  
- Callback-driven monitoring  
- State-based decision logic  

---

## 🏗️ Project Structure
```bash
battery_monitor/
├── src/
│ ├── battery_publisher.cpp
│ ├── battery_subscriber.cpp
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
ros2 run battery_monitor battery_publisher

# Run Subscriber
ros2 run battery_monitor battery_subscriber
```

---

# 📸 Output
```bash
Battery OK: 78.5%
Battery Low: 45.0%
Battery CRITICAL: 18.5%
```

---

# 🔍 Verification
```bash
ros2 topic list
ros2 topic echo /battery_level
```
# 💡 Why This Project Matters

Battery monitoring is a critical component in robotics systems.
This project simulates how robots:

- Continuously track internal system health
- Detect low-energy conditions
- Trigger warnings or actions based on thresholds

Such systems are essential in autonomous robots, drones, and industrial automation.

# 🛠️ Technologies Used
- ROS2 Jazzy
- Modern C++ (C++17)
- rclcpp
- Ubuntu Linux
