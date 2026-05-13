# 🤖 ROS2 Jazzy Learning Repository (Modern C++)

A structured ROS2 Jazzy learning repository focused on building real-world robotics systems using Modern C++.

This repository documents my journey of learning ROS2 by developing modular robotics applications step-by-step — from basic communication nodes to autonomous robot behaviors and multi-node robotic architectures.

---

# 🚀 Technologies & Concepts

- ROS2 Jazzy
- Modern C++
- Publisher–Subscriber Architecture
- Service–Client Communication
- Custom ROS2 Messages & Services
- Multi-node Robotics Systems
- Autonomous Robot Behaviors
- Robot Monitoring & Safety Systems
- Turtlesim Robotics Simulation
- URDF & RViz
- Gazebo Simulation (Upcoming)

---

# 🏗️ Repository Structure

```bash
ros2-jazzy-learning/
│
├── cpp_pub_sub/
│   ├── src/
│   │   ├── publisher_node.cpp
│   │   └── subscriber_node.cpp
│   ├── CMakeLists.txt
│   ├── package.xml
│   └── README.md
│
├── battery_monitor/
│   ├── src/
│   │   ├── battery_publisher.cpp
│   │   └── battery_subscriber.cpp
│   ├── CMakeLists.txt
│   ├── package.xml
│   └── README.md
│
├── temperature_sensor/
│   ├── src/
│   │   ├── temperature_publisher.cpp
│   │   └── temperature_subscriber.cpp
│   ├── CMakeLists.txt
│   ├── package.xml
│   └── README.md
│
├── obstacle_detection/
│   ├── msg/
│   │   └── ObstacleDistance.msg
│   ├── src/
│   │   ├── obstacle_publisher.cpp
│   │   └── obstacle_subscriber.cpp
│   ├── CMakeLists.txt
│   ├── package.xml
│   └── README.md
│
├── robot_service_cpp/
│   ├── srv/
│   │   └── RobotCommand.srv
│   ├── src/
│   │   ├── robot_server.cpp
│   │   └── robot_client.cpp
│   ├── CMakeLists.txt
│   ├── package.xml
│   └── README.md
│
├── multi_sensor_system/
│   ├── src/
│   │   ├── battery_node.cpp
│   │   ├── temperature_node.cpp
│   │   ├── obstacle_node.cpp
│   │   └── supervisor_node.cpp
│   ├── launch/
│   │   └── multi_sensor.launch.py
│   ├── CMakeLists.txt
│   ├── package.xml
│   └── README.md
│
├── robot_control_center/
│   ├── msg/
│   │   └── RobotStatus.msg
│   ├── srv/
│   │   └── RobotCommand.srv
│   ├── src/
│   │   ├── battery_publisher.cpp
│   │   ├── temperature_publisher.cpp
│   │   ├── control_center.cpp
│   │   ├── robot_server.cpp
│   │   └── robot_client.cpp
│   ├── launch/
│   │   └── robot_control.launch.py
│   ├── CMakeLists.txt
│   ├── package.xml
│   └── README.md
│
├── my_turtle_pkg/
│   ├── src/
│   │   ├── turtle_controller.cpp
│   │   ├── draw_square.cpp
│   │   ├── pose_subscriber.cpp
│   │   └── turtle_follower.cpp
│   ├── CMakeLists.txt
│   ├── package.xml
│   └── README.md
│
├── my_robot_description/
│   ├── urdf/
│   │   └── two_wheel_robot.urdf
│   ├── launch/
│   │   └── display.launch.py
│   ├── rviz/
│   │   └── robot_config.rviz
│   ├── CMakeLists.txt
│   ├── package.xml
│   └── README.md
│
└── README.md
```

---

# 📂 Projects Included

---

## 1️⃣ Publisher–Subscriber System

Basic ROS2 communication using Modern C++.

### Concepts Learned
- ROS2 Nodes
- Topics
- Publishers
- Subscribers
- Timers
- Message Passing

---

## 2️⃣ Battery Monitoring System 🔋

A ROS2-based robot battery monitoring system.

### Features
- Real-time battery level monitoring
- Low battery alerts
- Health monitoring architecture

### Concepts Learned
- Sensor simulation
- Real-time monitoring
- Robotics safety systems

---

## 3️⃣ Temperature Monitoring System 🌡️

A robot thermal monitoring system.

### Features
- Temperature tracking
- Overheating alerts
- Safety threshold detection

### Concepts Learned
- Robot safety monitoring
- Real-time sensor processing
- Fault detection systems

---

## 4️⃣ Obstacle Detection System 🚧

A ROS2 obstacle detection simulation system.

### Features
- Distance monitoring
- Obstacle alerts
- Safety response logic

### Concepts Learned
- Robotics perception
- Reactive systems
- Sensor integration

---

## 5️⃣ Service–Client System ⚙️

A ROS2 command-based robot control system.

### Features
- START / STOP robot commands
- Request–response communication
- Service architecture

### Concepts Learned
- ROS2 Services
- ROS2 Clients
- Custom `.srv` interfaces

---

## 6️⃣ Multi-Sensor System 📡

A centralized robot monitoring system integrating multiple sensor nodes.

### Features
- Battery monitoring
- Temperature monitoring
- Obstacle detection
- Supervisor node

### Concepts Learned
- Multi-node systems
- Distributed robotics architecture
- Centralized monitoring systems

---

## 7️⃣ Robot Control Center 🧠

A complete ROS2 robot monitoring and command architecture.

### Features
- Battery monitoring
- Temperature monitoring
- Robot command services
- Real-time monitoring
- Custom ROS2 interfaces

### Commands Supported
- START
- STOP
- SAFE_MODE
- AUTONOMOUS

### Concepts Learned
- Distributed robotics systems
- Modular robotics architecture
- Real-time robotics software design

---

## 8️⃣ Turtlesim Robotics Learning 🐢

A collection of autonomous turtle robotics projects built using ROS2 and Modern C++.

### Projects Included

#### 🟢 Turtle Controller
Basic autonomous turtle movement.

#### 🟦 Draw Square
Autonomous square path drawing.

#### 🟨 Pose Subscriber
Real-time turtle pose tracking.

#### 🔴 Turtle Follower
Autonomous turtle chasing system.

### Concepts Learned
- Robot motion control
- Pose estimation
- Autonomous following
- Navigation mathematics
- Multi-robot coordination
- Robotics behavior systems

---

# 📊 ROS2 Visualization & Debugging Tools

This repository also explores ROS2 debugging and visualization tools:

- `rqt_graph`
- `rqt_plot`
- `ros2 topic echo`
- `ros2 topic hz`
- `ros2 interface show`
- `rviz2`

### Concepts Learned
- ROS2 communication visualization
- Real-time data plotting
- Runtime debugging
- Topic inspection
- Robot state visualization

---

# 🧠 Learning Journey

This repository reflects my progression from:

```text
Basic ROS2 Communication
        ↓
Sensor Monitoring Systems
        ↓
Service–Client Architecture
        ↓
Multi-node Robotics Systems
        ↓
Robot Behavior Systems
        ↓
Autonomous Navigation Concepts
```

The goal is to build a strong foundation in:
- Robotics Software Engineering
- Autonomous Systems
- Real-time Robotics
- AI-driven robotic applications

---

# 🚀 Upcoming Projects

- Autonomous Obstacle Avoidance Turtle
- Waypoint Navigation
- PID Motion Control
- TF Frames
- URDF Robot Modeling
- RViz Visualization
- Gazebo Simulation
- SLAM & Mapping
- Nav2 Navigation Stack
- Autonomous Mobile Robots
- Computer Vision Integration

---

# 🛠️ Build Instructions

## Clone Repository

```bash
git clone https://github.com/susanthks/ros2-jazzy-learning.git
```

---

## Build Workspace

```bash
cd ~/ros2_ws

colcon build
```

---

## Source Workspace

```bash
source install/setup.bash
```

---

# 👨‍💻 About Me

I am a Robotics and AI Engineer passionate about building intelligent real-time robotic systems using:

- ROS2
- Modern C++
- AI & Computer Vision
- Embedded Systems
- Autonomous Robotics
- Industrial Automation

I enjoy developing systems where software, sensing, and robotics come together to solve real-world engineering problems.

---

# 🌐 Connect With Me

## GitHub
https://github.com/susanthks

## LinkedIn
https://www.linkedin.com/in/susanth-k-s-93a110325

---

# ⭐ Repository Goal

This repository is being developed as a long-term robotics engineering portfolio focused on:

- ROS2 development
- Robotics software architecture
- Autonomous systems
- Real-time robotic applications

---