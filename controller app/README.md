# 🚀 MIT App Inventor - Robot Control Application

This repository contains the **MIT App Inventor** project for controlling a **robotic car with an arm** using a **Bluetooth connection**. The application allows real-time movement of the robot and precise control of the robotic arm via a user-friendly interface.

## 📌 Features
- **📱 Intuitive Interface:** Control the robot’s movement with simple button clicks.
- **🔄 Full-Directional Navigation:** Move forward, backward, left, right, and rotate.
- **🦾 Robotic Arm Control:** Adjust the arm’s position and gripper with servo motors.
- **📡 Bluetooth Connectivity:** Communicate seamlessly with Arduino & ESP32.
- **📷 Camera Integration:** View real-time video stream from ESP32-CAM.

---

## 🎮 Application Interface
👉 The app consists of **multiple control buttons**, each mapped to a specific action.

| Action  | Button |
|---------|--------|
| Move Forward  | 🔼 |
| Move Backward | 🔽 |
| Turn Left  | ◀️ |
| Turn Right | ▶️ |
| Rotate Left | ↶ |
| Rotate Right | ↷ |

![image](https://github.com/user-attachments/assets/c613670d-f913-4096-8ede-a09f20578811)


---

## 🔧 How It Works
### 1️⃣ **Connecting to the Robot**
1. **Turn on the robot** and enable **Bluetooth**.
2. Open the app and **connect to the device**.
3. Start controlling the robot with on-screen buttons.

![image](https://github.com/user-attachments/assets/d14bb633-87fb-4d66-8c33-09fba93a8eac)



### 2️⃣ **Controlling Movement**
- Click the **arrow buttons** to move in different directions.
- The robot responds instantly via Bluetooth.

![image](https://github.com/user-attachments/assets/12cb9b48-4c0d-4f52-8394-1ba3be0de133)

### 3️⃣ **Operating the Robotic Arm**
- The arm consists of **six servo motors**, each controlled by dedicated buttons.
- Adjust the **gripper, wrist, and base rotation**.
![image](https://github.com/user-attachments/assets/d15e4bb3-235d-4ccb-93a0-86ed0f6353d9)




---

## 🛠️ Hardware Components
This project works with:
- **Arduino Mega 2560** (Main Controller)
- **ESP32-CAM** (For real-time video streaming)
- **L293D Motor Driver Shield** (Motor Control)
- **HC-SR04** (Ultrasonic Sensor for obstacle detection)
- **Mini DC Gearbox Motors** (For movement)
- **Servo Motors (SG90 & MG996R)** (For robotic arm)

![image](https://github.com/user-attachments/assets/ce93856b-8857-4df4-8b5d-636e6c952da2)
![image](https://github.com/user-attachments/assets/ee1f4e65-cae1-4233-90c9-52c3e19ede52)
![image](https://github.com/user-attachments/assets/9294ce42-747b-4ad5-8844-a3a67780faf3)
![image](https://github.com/user-attachments/assets/0c8d1c97-9511-4fea-b166-c276c40e8cf3)
![image](https://github.com/user-attachments/assets/7d686260-2c29-4b94-9984-0c9c4f081e04)
![image](https://github.com/user-attachments/assets/664f0539-5c77-4c33-8767-2952363d1c58)


---

## 📂 Code & Files
This repository contains:
- 📁 **MIT App Inventor Project File (.aia)**
- 📝 **Arduino & ESP32 Code**
- 📸 **Screenshots & Documentation**





---

## 📥 Installation
1. Download the **MIT App Inventor** project file (`.abk`).
2. Import it into [ App controller ](https://drive.google.com/file/d/1W8ASzxIF9OefUCy8t8d7V6KmDyqxMOfS/view?usp=drive_link).
3. Install the app on your **Android device**.
4. Pair your phone with the **robot's Bluetooth module**.
5. Enjoy controlling your **robotic car with an arm!** 🎮

---



## 📜 Code Blocks Explanation
### 🔹 **Forward Block:**
- `when Button1.Click do` → Executes when `Button1` is clicked.
- `if then else` → If the condition is met, executes `then`; otherwise, executes `else`.
- `Teste whether button1. Image and text are equal` → Sends a command by setting the image to `button1_1.png` and reverses for `button1_0.png`.
- `Set button1.image to no available assets` → Executes the required action.
- `call bluetoothclient1.send1bytenumber number` → Sends a command via Bluetooth with a specific number.


### 🔹 **Servo Block:**
- `when Servo_Up or Down.TouchDown do` → Sends a command when pressing the button.
- `when Servo_Up or Down.TouchUp do` → Sends the opposite command when releasing the button.

These blocks are applied similarly to other buttons with their respective names.

![image](https://github.com/user-attachments/assets/bc608ba8-a95e-4ecb-87f7-06b9aeae60ce)
![image](https://github.com/user-attachments/assets/9e3a190b-5c51-485a-824c-1a6adba3b437)
![image](https://github.com/user-attachments/assets/563f209a-e763-41f4-aad3-381a573fca37)
![image](https://github.com/user-attachments/assets/8d08d6d9-a0c0-4b2b-a9ee-8823f459f0c0)
![image](https://github.com/user-attachments/assets/6be7c83f-ff4d-4335-ac14-d6b14633f806)
![image](https://github.com/user-attachments/assets/30e65cae-e191-44ac-8130-b6196ca30dc6)
![image](https://github.com/user-attachments/assets/cd36f206-e6d0-424f-b302-625cf7e70744)

---

## 🎯 Future Enhancements
✅ Add **Wi-Fi control** for extended range.  
✅ Improve **AI-based automation** for smart tasks.  
✅ Upgrade to **voice control** using Google Assistant.  

---

## 📢 Contributing
Want to improve this project? Feel free to submit **pull requests** or **open issues**! 🚀
