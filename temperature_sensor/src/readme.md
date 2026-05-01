# 🌡️ ROS2 C++ Temperature Sensor System

A real-time temperature monitoring system built using ROS2 Jazzy and Modern C++ (rclcpp).  
This project demonstrates how robotic systems collect and process temperature data from multiple sensors using ROS2 topic communication.

---

## 📌 Overview

This system simulates temperature sensors and continuously monitors environmental conditions using ROS2 pub/sub architecture.

- **Temperature Publisher** → Generates temperature readings (simulates sensor data)
- **Temperature Subscriber** → Monitors temperature and provides alerts based on thresholds

---

## ⚙️ Features

- Real-time temperature data publishing  
- Continuous temperature reading simulation  
- Intelligent alert system:
  - ✅ **Temperature Normal** (20°C – 30°C)
  - ⚠️ **Temperature Warning** (30°C – 40°C)
  - ❌ **Temperature Critical** (> 40°C or < 15°C)
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
- Threshold-based decision logic  

---

## 🏗️ Project Structure
```bash
temperature_sensor/
├── src/
│   ├── temperature_publisher.cpp
│   ├── temperature_subscriber.cpp
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
ros2 run temperature_sensor temperature_publisher

# Run Subscriber
ros2 run temperature_sensor temperature_subscriber
```

---

# 📸 Output
```bash
Temperature Normal: 24.5°C
Temperature Warning: 35.0°C
Temperature CRITICAL: 42.3°C
```

---

# 🔍 Verification
```bash
ros2 topic list
ros2 topic echo /temperature
```
# 💡 Why This Project Matters

Temperature monitoring is a critical component in robotics and IoT systems.
This project simulates how systems:

- Continuously monitor environmental conditions
- Detect temperature anomalies
- Trigger alerts or preventive actions based on thresholds

Such systems are essential in autonomous robots, industrial equipment, climate control systems, and environmental monitoring.

# 🛠️ Technologies Used
- ROS2 Jazzy
- Modern C++ (C++17)
- rclcpp
- Ubuntu Linux
