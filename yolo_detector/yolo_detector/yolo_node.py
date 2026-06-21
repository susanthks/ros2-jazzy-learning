import sys
sys.path.insert(0, '/home/susanth/ros2_ws/.venv/lib/python3.12/site-packages')

import cv2

from ultralytics import YOLO

import rclpy

from rclpy.node import Node

from sensor_msgs.msg import Image

from std_msgs.msg import String

from cv_bridge import CvBridge


class YoloNode(Node):

    def __init__(self):

        super().__init__('yolo_detector')

        self.bridge = CvBridge()

        self.model = YOLO("yolov8n.pt")

        self.cap = cv2.VideoCapture(0)

        self.image_pub = self.create_publisher(
            Image,
            '/image_detected',
            10)

        self.detect_pub = self.create_publisher(
            String,
            '/detections',
            10)

        self.timer = self.create_timer(
            0.05,
            self.process_frame)

    def process_frame(self):

        ret, frame = self.cap.read()

        if not ret:
            return

        results = self.model(frame)

        detections = []

        annotated = results[0].plot()

        for box in results[0].boxes:

            cls = int(box.cls)

            label = self.model.names[cls]

            detections.append(label)

        detection_text = ",".join(detections)

        msg = String()

        msg.data = detection_text

        self.detect_pub.publish(msg)

        ros_img = self.bridge.cv2_to_imgmsg(
            annotated,
            encoding='bgr8')

        self.image_pub.publish(ros_img)

    def destroy_node(self):

        self.cap.release()

        super().destroy_node()


def main(args=None):

    rclpy.init(args=args)

    node = YoloNode()

    rclpy.spin(node)

    node.destroy_node()

    rclpy.shutdown()


if __name__ == '__main__':
    main()