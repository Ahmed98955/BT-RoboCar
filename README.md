# ESP32 and Arduino Mega Bluetooth-Controlled Robot

## Overview
This project integrates an ESP32 and an Arduino Mega to control a robotic platform using Bluetooth communication. The ESP32 receives commands via Bluetooth and transmits them to the Arduino Mega, which interprets them and controls motors and servos accordingly.

---

## Components Used
1. **ESP32** - Handles Bluetooth communication.
2. **Arduino Mega** - Processes received commands and controls motors and servos.
3. **ESP32-CAM** - Captures real-time video and streams it over a web interface.
4. **HC-05 Bluetooth Module** (Embedded in ESP32)
5. **AFMotor Library** - Controls the Mecanum wheels.
6. **Servo Motors** - Controls the robotic arm movements.
7. **Ultrasonic Sensor** - Detects obstacles to prevent collisions.

---

## ESP32 Code Explanation
The ESP32 acts as a Bluetooth transceiver, transmitting commands to the Arduino Mega over Serial communication. Additionally, ESP32-CAM streams video to a web interface.

### Main Functionalities
- Initializes Bluetooth and serial communication.
- Reads Bluetooth commands from a paired device.
- Forwards received commands to the Arduino Mega.
- Echoes responses back from the Arduino Mega to the Bluetooth device.
- Captures and streams live video using ESP32-CAM.

### Code Breakdown
- **Setup Function:**
  - Initializes serial communication (`Serial.begin(115200)` and `Serial1.begin(9600)`).
  - Starts Bluetooth with `SerialBT.begin("ESP32-BT");`.
  - Sets up ESP32-CAM for video streaming.
- **Loop Function:**
  - Listens for incoming Bluetooth commands and transmits them to the Arduino Mega (`Serial1.write(data)`).
  - Reads responses from the Arduino Mega and sends them back over Bluetooth (`SerialBT.write(data)`).
  - Continuously streams video from ESP32-CAM.

---

## Arduino Mega Code Explanation
The Arduino Mega processes commands received from the ESP32 and controls the motors and servos accordingly.

### Main Functionalities
- Decodes received commands and assigns movement instructions.
- Controls Mecanum wheels for movement.
- Manipulates servos for robotic arm control.
- Uses an ultrasonic sensor to detect obstacles.
- Saves and replays servo movements.

### Code Breakdown
#### **Setup Function:**
- Initializes Bluetooth (`Serial1.begin(9600)`), servos, and ultrasonic sensor pins.
- Sets up initial servo positions.

#### **Loop Function:**
- Reads commands from ESP32 over Bluetooth (`Bluetooth.read()`).
- Interprets commands for:
  - Movement: Forward, backward, left, right, rotation.
  - Arm control: Incremental servo movement.
  - Saving and executing movement sequences.
- Checks ultrasonic sensor distance to avoid collisions.

#### **Movement Functions:**
- `moveForward()`, `moveBackward()`, `moveSidewaysLeft()`, `moveSidewaysRight()`, `rotateLeft()`, `rotateRight()`.
- Uses `getDistance()` to measure obstacles and stop movement if necessary.

#### **Arm Control Functions:**
- Moves individual servos based on received commands.
- Saves and replays servo positions for automation.

---
## photos
![IMG-20250208-WA0015](https://github.com/user-attachments/assets/e9a433f1-d203-432c-b3ec-1bae07cd1994)
![IMG-20250208-WA0016](https://github.com/user-attachments/assets/6a413a2f-ddb2-43c2-98de-9ce91e9b52e0)
![IMG-20250208-WA0017](https://github.com/user-attachments/assets/0c936bbe-30cb-4ad4-a474-86174561d847)
![IMG-20250208-WA0018](https://github.com/user-attachments/assets/85a99a53-a242-4cb1-b343-df751c6d6de3)
![IMG-20250208-WA0019](https://github.com/user-attachments/assets/89293d9b-2b56-49a7-8633-456659104aad)
![IMG-20250208-WA0020](https://github.com/user-attachments/assets/e4f76031-77f4-483e-93a2-61729ace6f48)
![IMG-20250208-WA0021](https://github.com/user-attachments/assets/4d5a7f8b-cec7-4934-8529-10e4ac47d94c)
![IMG-20250208-WA0022](https://github.com/user-attachments/assets/b67f8dbc-8575-4a36-a893-1f18ddd905a8)

![IMG-20250208-WA0027](https://github.com/user-attachments/assets/59cacc1b-c3af-4f14-88b1-82bcdc87d1d5)

![IMG-20250208-WA0026](https://github.com/user-attachments/assets/e992bf7c-12fc-45e5-8178-ca0a82fbc964)

![IMG-20250208-WA0025](https://github.com/user-attachments/assets/47359618-9ad5-4f42-9463-f7698d3c80ea)

![IMG-20250208-WA0024](https://github.com/user-attachments/assets/ec7e2af3-95f7-4b45-babf-bc2e7df55161)

![IMG-20250208-WA0028](https://github.com/user-attachments/assets/e496abff-62bb-48d5-ac0a-6a30c66e0f3a)

![IMG-20250208-WA0023](https://github.com/user-attachments/assets/b58f5964-6ced-415f-ad12-fc29870b40e6)

![IMG-20250208-WA0032](https://github.com/user-attachments/assets/2716d259-1dd3-4093-82c3-f19ee3fb95aa)



![IMG-20250208-WA0034](https://github.com/user-attachments/assets/a09ab282-e9b3-403e-a8c8-241c5b171de0)

![IMG-20250208-WA0033](https://github.com/user-attachments/assets/1e099bed-f4c5-48de-8013-eaac31774dd7)

![IMG-20250208-WA0030](https://github.com/user-attachments/assets/8a299293-6613-46fd-92dd-8da837eac308)

![IMG-20250208-WA0029](https://github.com/user-attachments/assets/2786746b-e07b-4f01-86ce-be3f432b92e7)


![IMG-20250208-WA0037](https://github.com/user-attachments/assets/c6403f1b-0f8b-49a2-834b-8aeef88e6985)



## Summary
This project enables wireless control of a robotic system using an ESP32 and Arduino Mega. The ESP32 manages Bluetooth communication, while the Arduino Mega executes the received commands to control movement and servos. The ESP32-CAM provides real-time video streaming, and the ultrasonic sensor ensures obstacle detection and prevents collisions.

