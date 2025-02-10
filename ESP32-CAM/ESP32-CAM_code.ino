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