# 🚗 BT-RoboCar – Bluetooth-Controlled Smart Car  

BT-RoboCar is a **Bluetooth-controlled robotic car** powered by **ESP32 and Arduino**. It allows remote control via a mobile app, enabling movement and robotic arm operations. The ESP32 acts as a **bridge**, receiving commands from the mobile app via **Bluetooth** and forwarding them to the Arduino through **Serial1** to execute actions.  

## ✨ Features  
- 📡 **Bluetooth Control** – Wirelessly control the car using a mobile app.  
- 🎮 **Real-Time Commands** – Sends movement and robotic arm actions instantly.  
- 🔄 **ESP32-Arduino Communication** – Serial communication between ESP32 and Arduino.  
- ⚙️ **Expandable & Customizable** – Easily add new features like sensors or automation.  

## 📦 Requirements  
Ensure you have the necessary hardware and software installed:  

### 🔧 Hardware:  
- ✅ **ESP32** (for Bluetooth communication)  
- ✅ **Arduino** (for motor and arm control)  
- ✅ **Motor Driver** (L298N or similar)  
- ✅ **Bluetooth-Compatible Mobile App**  

### 💻 Software:  
- Install the required Arduino libraries and tools.  
- Ensure **Bluetooth is enabled** on your device.  

## 🛠️ How to Use  
1. Upload the ESP32 code to your **ESP32 board**.  
2. Upload the Arduino code to your **Arduino board**.  
3. Connect the mobile app to **ESP32-BT** via Bluetooth.  
4. Use the app to send commands (`F` for forward, `B` for backward, etc.).  
5. The **ESP32** forwards commands to **Arduino**, controlling the motors and robotic arm.  

## 📜 Code Overview  

### **ESP32 Code:**  
```cpp  
#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

void setup() {
    Serial.begin(115200);          
    Serial1.begin(9600, SERIAL_8N1, 3, 1);
    SerialBT.begin("ESP32-BT");    
    Serial.println("Bluetooth is ready!");
}

void loop() {
    if (SerialBT.available()) {  
        char data = SerialBT.read();
        Serial1.write(data);         
    }
    if (Serial1.available()) {  
        char data = Serial1.read();  
        SerialBT.write(data);        
    }
}
```
- **Receives** commands from the mobile app via **Bluetooth**.  
- **Sends** commands to **Arduino** via `Serial1`.  
- **Receives** responses from **Arduino** and forwards them back to the app.  

## 📌 photos  
![image](https://github.com/user-attachments/assets/b58d2b5a-1f59-478b-9f39-9e77a78d82e9)
![image](https://github.com/user-attachments/assets/f9407ec4-1099-4912-92eb-fd8c36ea2a43)
![image](https://github.com/user-attachments/assets/1061dc06-23bf-457e-af23-d47b57f8630c)


## ⚡ Future Improvements  
- ✅ Add **sensor feedback** (e.g., obstacle detection).  
- ✅ Implement **voice control** for hands-free operation.  
- ✅ Support **multiple movement modes** (autonomous, manual).  

🚀 **Ready to take control? Let’s build the future of smart cars!**  

