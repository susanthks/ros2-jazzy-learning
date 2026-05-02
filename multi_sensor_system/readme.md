# 🤖 ROS2 C++ Multi-Sensor Monitoring System

An integrated real-time monitoring system built using ROS2 Jazzy and Modern C++ (rclcpp).  
This project demonstrates how robotic systems aggregate data from multiple sensors (battery, temperature, distance) for comprehensive system health assessment using ROS2 topic communication.

---

## 📌 Overview

This system aggregates and monitors data from multiple sensor inputs and provides centralized system health assessment using ROS2 pub/sub architecture.

- **Supervisor Node** → Collects, processes, and monitors data from battery, temperature, and obstacle sensors with priority-based alert system

---

## ⚙️ Features

- Real-time multi-sensor data aggregation  
- Continuous system status evaluation  
- Intelligent alert system:
  - ✅ **System OK** (All sensors nominal)
  - ⚠️ **System Warning** (One or more sensors in warning state)
  - ❌ **System Critical** (Any sensor in critical state)
- Cross-sensor anomaly detection
- Priority-based alert queue
- Multi-sensor synchronization and fusion

---

## 🧠 Concepts Covered

- ROS2 Nodes  
- Multi-topic Publisher–Subscriber architecture  
- Topic-based communication  
- std_msgs/msg/Float32 and custom messages  
- Timer-based execution  
- Callback-driven monitoring  
- Data aggregation and fusion  
- State machine logic  
- Priority queue implementation  

---

## 🏗️ Project Structure
```bash
multi_sensor_system/
├── src/
│   ├── supervisor_node.cpp
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

# Run Supervisor Node
ros2 run multi_sensor_system supervisor_node
```

---

# 📸 Output
```bash
🚨 OBSTACLE DETECTED → STOP ROBOT
⚠️ LOW BATTERY → REDUCE OPERATIONS
🔥 HIGH TEMPERATURE → ACTIVATE COOLING
✅ SYSTEM NORMAL
```

---

# 🔍 Verification
```bash
# In terminal 1: Start the supervisor node
ros2 run multi_sensor_system supervisor_node

# In terminal 2-4: Run publishers from other packages
ros2 run battery_monitor battery_publisher
ros2 run temperature_sensor temperature_publisher
ros2 run obstacle_detection distance_publisher

# In another terminal: View system status
ros2 topic list
ros2 topic echo /system_status
```

# 💡 Why This Project Matters

Multi-sensor monitoring is essential in complex robotics and autonomous systems.
This project simulates how integrated systems:

- Aggregate data from diverse sensor sources
- Detect cross-sensor anomalies and correlations
- Make intelligent decisions based on combined data
- Prioritize alerts based on system criticality

Such systems are essential in autonomous robots, industrial automation, UAVs, and safety-critical applications.

# 🛠️ Technologies Used
- ROS2 Jazzy
- Modern C++ (C++17)
- rclcpp
- Ubuntu Linux
