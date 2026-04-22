# 5-Axis-Robotic-Arm-robot
A 5-DOF robotic arm mounted on a mobile platform, controlled via Arduino Uno and PCA9685 PWM driver. The system integrates DC motor control using relays and precise servo positioning via serial commands, enabling both mobility and manipulation in a single robotic system.

# 🤖 5-Axis Robotic Arm on Mobile Base

## 📌 Overview

This project is a **5 Degrees of Freedom (5-DOF) robotic arm** mounted on a **mobile robotic platform**. It combines **servo-based articulation** with **DC motor-driven movement**, allowing the robot to both **navigate** and **manipulate objects**.

The system is controlled using an **Arduino Uno**, with a **PCA9685 PWM driver** for precise servo control and **relay modules** for bidirectional DC motor driving.

---

## 🚀 Features

* 🎯 5-axis robotic arm control (Base, Shoulder, Elbow, Wrist, Gripper)
* 🚗 Mobile platform with forward, backward, left, right motion
* 🎮 Serial command-based control
* ⚡ External power supply for motors and servos
* 🔌 I2C-based PWM control using PCA9685
* 🔁 Relay-based H-bridge logic for DC motors

---

## 🧠 System Architecture

### 🔹 Main Components

* Arduino Uno
* PCA9685 16-channel PWM Driver
* 5 Servo Motors (for robotic arm)
* 4 DC Motors (for mobility)
* 2x Relay Modules (for motor direction control)
* SMPS Power Supply
* Chassis + Wheels

---

## 🔌 Working Principle

### 🦾 Servo Control

* Controlled via PCA9685 using I2C communication
* Each servo is assigned a channel
* Angle input (0–180°) is mapped to PWM pulse width

### 🚗 Motor Control

* Each motor direction is controlled using relays
* Commands:

  * `f` → Forward
  * `b` → Backward
  * `l` → Left
  * `r` → Right
  * `s` → Stop

### 💻 Serial Control Logic

* **Servo Input:**

  ```
  <servo_number> <angle>
  Example: 0 90
  ```
* **Motor Input:**

  ```
  f, b, l, r, s
  ```

---

## 🧾 Code Explanation

### 📌 Servo Mapping

```cpp
uint16_t pulse_width = map(angle, 0, 180, 150, 600);
```

Maps angle to PWM pulse for accurate positioning.

---

### 📌 Motor Functions

* `front()` → Moves robot forward
* `back()` → Moves robot backward
* `left()` → Turns left
* `right()` → Turns right
* `stopMotors()` → Stops all motors

---

## ⚙️ Pin Configuration

| Function       | Arduino Pin |
| -------------- | ----------- |
| Relay1 Forward | D2          |
| Relay1 Reverse | D3          |
| Relay2 Forward | D4          |
| Relay2 Reverse | D5          |
| I2C SDA        | A4          |
| I2C SCL        | A5          |

---

## 🔧 Setup Instructions

1. Connect all components as per circuit diagram
2. Install required library:

   * `Adafruit PWM Servo Driver`
3. Upload code to Arduino Uno
4. Open Serial Monitor (9600 baud)
5. Send commands to control robot

---

## 📷 Hardware Preview

* 5-axis robotic arm mounted on a 4-wheel drive base
* External SMPS powering motors and servos

---

## 🛠️ Future Improvements

* Add wireless control (Bluetooth / WiFi)
* Integrate camera for vision-based control
* Use motor driver (L298N) instead of relays for efficiency
* Add inverse kinematics for precise arm movement

---

## ⚠️ Notes

* Ensure proper grounding between power supply and Arduino
* Avoid powering servos directly from Arduino
* Use separate supply for motors to prevent noise issues

---

## 👨‍💻 Author

**Anurag Singh Rajput**

---

## 📜 License

This project is open-source and available under the MIT License.
