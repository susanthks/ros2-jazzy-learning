# 🚀 ROS2 C++ Robotics Projects | susanthks

A hands-on collection of robotics projects built using ROS2 Jazzy and Modern C++ (rclcpp), focused on developing real-time communication systems and robot monitoring architectures.

---

## 🎯 Objective

To build strong foundations in robotics software engineering by implementing core ROS2 concepts and simulating real-world robotic subsystems using Modern C++.

---

## 📌 Projects

### 🔹 1. Publisher–Subscriber System (C++)
**Overview:**  
Implementation of basic inter-node communication using ROS2 topics.

**Key Features:**
- Publisher node sends messages on `/chatter`
- Subscriber node receives and processes messages
- Demonstrates asynchronous communication using rclcpp

**Concepts Covered:**
- ROS2 Nodes  
- Topics & Message Passing  
- Callback Mechanism  
- Timer-based Execution  

---

### 🔋 2. Battery Monitoring System (C++)
**Overview:**  
Simulation of a robot battery monitoring system with real-time status evaluation.

**Key Features:**
- Battery level simulation (100% → 0%)
- Real-time monitoring using subscriber node
- Intelligent alert system:
  - ✅ Normal (>50%)
  - ⚠️ Low (20–50%)
  - ❌ Critical (<20%)
- Auto reset simulating charging cycle

**Concepts Covered:**
- Real-time data streaming  
- State-based decision logic  
- System health monitoring  

---

## 🧠 Core Skills Demonstrated

- ROS2 (rclcpp) development in C++  
- Publisher–Subscriber architecture  
- Real-time system simulation  
- Modular robotics software design  
- Debugging and ROS2 CLI tools  

---

## 🏗️ Repository Structure
```bash
ros2-cpp-learning/
│
├── cpp_pub_sub/
│ ├── src/
│ │ ├── publisher.cpp
│ │ ├── subscriber.cpp
│ └── README.md
│
├── battery_monitor/
│ ├── src/
│ │ ├── battery_publisher.cpp
│ │ ├── battery_subscriber.cpp
│ └── README.md
│
├── screenshots/
│
└── README.md
```

---

## ▶️ Getting Started

# 1. Create Workspace
```bash
mkdir -p ~/ros2_ws/src
cd ~/ros2_ws/src
```

# 2. Clone repository
```bash
---git clone https://github.com/susanthks/ros2-jazzy-learning.git
```
# 3. Build
```bash
cd ~/ros2_ws
colcon build
source install/setup.bash
```
---
## ▶️ Run Projects
# 1. Publisher–Subscriber
```bash
ros2 run cpp_pub_sub publisher
ros2 run cpp_pub_sub subscriber
```
---
# 2. Battery Monitoring System
```bash
ros2 run battery_monitor battery_publisher
ros2 run battery_monitor battery_subscriber
```
---

📸 Sample Output
<img width="1024" height="640" alt="Screenshot from 2026-04-29 15-57-43" src="https://github.com/user-attachments/assets/55e68bdd-2d7e-458d-898f-11ad12252480" />
<img width="1024" height="640" alt="Screenshot from 2026-04-29 15-56-00" src="https://github.com/user-attachments/assets/aa02d69c-a688-421f-a891-31846a4862b9" />
<img width="1024" height="640" alt="Screenshot from 2026-04-29 15-55-17" src="https://github.com/user-attachments/assets/28c2074f-a6d4-44f7-83ac-2af385c3503d" />
<img width="1024" height="640" alt="Screenshot from 2026-04-29 15-55-06" src="https://github.com/user-attachments/assets/31addc09-593f-4a73-9ed6-a20261aec39e" />
<img width="1024" height="640" alt="Screenshot from 2026-04-29 15-54-59" src="https://github.com/user-attachments/assets/873596fa-58ac-4bc7-9de6-06792f0b0485" />
<img width="1024" height="640" alt="Screenshot from 2026-04-29 15-53-28" src="https://github.com/user-attachments/assets/cc907534-32f0-4aa5-8afb-417a58ccae08" />


---
## 🔍 Verification
```bash
ros2 topic list
ros2 topic echo /chatter
ros2 topic echo /battery_level
```
---

## 🛠️ Technologies Used
- ROS2 Jazzy
- Modern C++
- rclcpp
- Ubuntu Linux
---
🚀 🚀 Future Roadmap
---
🌡️ Temperature Sensor System
📏 Distance / Obstacle Detection System
🤖 Multi-Sensor Monitoring System
🐢 Turtlesim Automation
🎥 ROS2 + OpenCV Integration
🧭 SLAM Implementation


🤝 Connect with Me
---
LinkedIn: https://www.linkedin.com/in/susanth-k-s-93a110325/

