#include <Wire.h>
#include <AFMotor.h>
#include <Servo.h>
#define Bluetooth Serial1
Servo servo01;
Servo servo02;
Servo servo03;
Servo servo04;
Servo servo05;
Servo servo06;

AF_DCMotor motor(1, MOTOR12_64KHZ);//  فوق يمين                                                                                         
AF_DCMotor motor1(2, MOTOR12_64KHZ); //تحت يمين                                                                                         
AF_DCMotor motor2(3, MOTOR12_64KHZ); //تحت شمال                                                                                         
AF_DCMotor motor3(4, MOTOR12_64KHZ);//فوق شمال                                                                                          

int wheelSpeed=100;
int servo1Pos, servo2Pos, servo3Pos, servo4Pos, servo5Pos, servo6Pos; // current position
int servo1PPos, servo2PPos, servo3PPos, servo4PPos, servo5PPos, servo6PPos; // previous position
int servo01SP[50], servo02SP[50], servo03SP[50], servo04SP[50], servo05SP[50], servo06SP[50]; // for storing positions/steps
int speedDelay = 20; 
int dataIn, m = 0,index = 0;
#define TRIG_PIN 36
#define ECHO_PIN 37
long duration;
int distance;

int getDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration * 0.034 / 2; // تحويل الوقت إلى مسافة بالسنتيمتر
  return distance;
}

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  servo01.attach(30);
  servo02.attach(31);
  servo03.attach(32);
  servo04.attach(33);
  servo05.attach(34);
  servo06.attach(35);
  Serial.begin(9600);  //38400
  Bluetooth.begin(9600); 
  Bluetooth.setTimeout(1);
  delay(20);
  // Move robot arm to initial position
  /*servo1PPos = 90;
  servo01.write(servo1PPos);
  servo2PPos = 100;
  servo02.write(servo2PPos);
  servo3PPos = 120;
  servo03.write(servo3PPos);
  servo4PPos = 95;
  servo04.write(servo4PPos);
  servo5PPos = 60;
  servo05.write(servo5PPos);
  servo6PPos = 110;
  servo06.write(servo6PPos);*/
} 
void loop() {
  // Check for incoming data                  ***************************************** الاستقبال 
  if (Bluetooth.available() > 0) {
    dataIn = Bluetooth.read();  // Read the data
    Serial.println(dataIn);
    if (dataIn == 0) {
      m = 0;
    }
    if (dataIn == 1) {
      m = 1;
    }
    if (dataIn == 2) {
      m = 2;
    }
    if (dataIn == 3) {
      m = 3;
    }
    if (dataIn == 4) {
      m = 4;
    }
    if (dataIn == 5) {
      m = 5;
    }
    if (dataIn == 6) {
      m = 6;
    }
    if (dataIn == 7) {
      m = 7;
    }
    if (dataIn == 8) {
      m = 8;
    }
    if (dataIn == 9) {
      m = 9;
    }
    if (dataIn == 10) {
      m = 10;
    }
    if (dataIn == 11) {
      m = 11;
    }
    if (dataIn == 12) {
      m = 12;
    }
    if (dataIn == 14) {
      m = 14;
    }
    if (dataIn == 16) {
      m = 16;
    }
    if (dataIn == 17) {
      m = 17;
    }
    if (dataIn == 18) {
      m = 18;
    }
    if (dataIn == 19) {
      m = 19;
    }
    if (dataIn == 20) {
      m = 20;
    } 
    if (dataIn == 21) {
      m = 21;
    }
    if (dataIn == 22) {
      m = 22;
    }
    if (dataIn == 23) {
      m = 23;
    }
    if (dataIn == 24) {
      m = 24;
    }
    if (dataIn == 25) {
      m = 25;
    }
    if (dataIn == 26) {
      m = 26;
    }
    if (dataIn == 27) {
      m = 27;
    }

    // Set speed ممكن يعمل مشكله                  000000000000000                   *******************   *********
    //                                                                                          sd سرعه العجل
   /* if (dataIn >= 16) {
      wheelSpeed = dataIn;
      Serial.println(wheelSpeed);
    }*/
  }
// Move the Mecanum wheels platform
    if (m == 4) {
      moveSidewaysLeft();
    }
    if (m == 5) {
      moveSidewaysRight();
    }
    if (m == 2) {
      moveForward();
    }
    if (m == 7) {
      moveBackward();
    }
    if (m == 3) {
      moveRightForward();
    }
    if (m == 1) {
      moveLeftForward();
    }
    if (m == 8) {
      moveRightBackward();
    }
    if (m == 6) {
      moveLeftBackward();
    }
    if (m == 9) {
      rotateLeft();
    }
    if (m == 10) {
      rotateRight();
    }

    if (m == 0) {
      stopMoving();
    }

 //  Mecanum wheels speed                                                          **********************          لو مشكله حلها اهو
    if (dataIn > 30 & dataIn < 100) {
      wheelSpeed = dataIn * 20;
    }
  

     // Move robot arm
    // Move servo 1 in positive direction
    while (m == 16) {
      if (Bluetooth.available() > 0) {
        m = Bluetooth.read();
      }
      servo01.write(servo1PPos);
      servo1PPos++;
      delay(speedDelay);
    }
    // Move servo 1 in negative direction
    while (m == 17) {
      if (Bluetooth.available() > 0) {
        m = Bluetooth.read();
      }
      servo01.write(servo1PPos);
      servo1PPos--;
      delay(speedDelay);
    }
    // Move servo 2
    while (m == 19) {
      if (Bluetooth.available() > 0) {
        m = Bluetooth.read();
      }
      servo02.write(servo2PPos);
      servo2PPos++;
      delay(speedDelay);
    }
    while (m == 18) {
      if (Bluetooth.available() > 0) {
        m = Bluetooth.read();
      }
      servo02.write(servo2PPos);
      servo2PPos--;
      delay(speedDelay);
    }
    // Move servo 3
    while (m == 20) {
      if (Bluetooth.available() > 0) {
        m = Bluetooth.read();
      }
      servo03.write(servo3PPos);
      servo3PPos++;
      delay(speedDelay);
    }
    while (m == 21) {
      if (Bluetooth.available() > 0) {
        m = Bluetooth.read();
      }
      servo03.write(servo3PPos);
      servo3PPos--;
      delay(speedDelay);
    }
    // Move servo 4
    while (m == 23) {
      if (Bluetooth.available() > 0) {
        m = Bluetooth.read();
      }
      servo04.write(servo4PPos);
      servo4PPos++;
      delay(speedDelay);
    }
    while (m == 22) {
      if (Bluetooth.available() > 0) {
        m = Bluetooth.read();
      }
      servo04.write(servo4PPos);
      servo4PPos--;
      delay(speedDelay);
    }
    // Move servo 5
    while (m == 25) {
      if (Bluetooth.available() > 0) {
        m = Bluetooth.read();
      }
      servo05.write(servo5PPos);
      servo5PPos++;
      delay(speedDelay);
    }
    while (m == 24) {
      if (Bluetooth.available() > 0) {
        m = Bluetooth.read();
      }
      servo05.write(servo5PPos);
      servo5PPos--;
      delay(speedDelay);
    }
    // Move servo 6
    while (m == 26) {
      if (Bluetooth.available() > 0) {
        m = Bluetooth.read();
      }
      servo06.write(servo6PPos);
      servo6PPos++;
      delay(speedDelay);
    }
    while (m == 27) {
      if (Bluetooth.available() > 0) {
        m = Bluetooth.read();
      }
      servo06.write(servo6PPos);
      servo6PPos--;
      delay(speedDelay);
    }
     // If arm speed slider is changed
    if (dataIn > 101 & dataIn < 250) {
      speedDelay = dataIn / 10; // Change servo speed (delay time)
    }

    // If button "SAVE" is pressed
    if (m == 12) {
      servo01SP[index] = servo1PPos;  // save position into the array
      servo02SP[index] = servo2PPos;
      servo03SP[index] = servo3PPos;
      servo04SP[index] = servo4PPos;
      servo05SP[index] = servo5PPos;
      servo06SP[index] = servo6PPos;
      index++;                        // Increase the array index
      m = 0;
    }

    // If button "RUN" is pressed
    if (m == 14) {
      runSteps();

      // If button "RESET" is pressed
      if (dataIn != 14) {
        stopMoving();
        memset(servo01SP, 0, sizeof(servo01SP)); // Clear the array data to 0
        memset(servo02SP, 0, sizeof(servo02SP));
        memset(servo03SP, 0, sizeof(servo03SP));
        memset(servo04SP, 0, sizeof(servo04SP));
        memset(servo05SP, 0, sizeof(servo05SP));
        memset(servo06SP, 0, sizeof(servo06SP));
        index = 0;  // Index to 0
      }
    }
}



void moveForward() {

    distance = getDistance();
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance < 10) {
    stopMoving();
    Serial.println("Obstacle detected! Stopping.");
    return;
  }

  motor.setSpeed(wheelSpeed); 
  motor1.setSpeed(wheelSpeed); 
  motor2.setSpeed(wheelSpeed); 
  motor3.setSpeed(wheelSpeed);
  motor1.run(FORWARD);
  motor.run(FORWARD); 
  motor3.run(FORWARD);
  motor2.run(FORWARD);
}
void moveBackward() {

  motor.setSpeed(wheelSpeed); 
  motor1.setSpeed(wheelSpeed); 
  motor2.setSpeed(wheelSpeed); 
  motor3.setSpeed(wheelSpeed);
  motor1.run(BACKWARD);
  motor.run(BACKWARD); 
  motor3.run(BACKWARD);
  motor2.run(BACKWARD);
}
void moveSidewaysLeft() {

  motor.setSpeed(wheelSpeed); 
  motor1.setSpeed(wheelSpeed); 
  motor2.setSpeed(wheelSpeed); 
  motor3.setSpeed(wheelSpeed);
  motor1.run(BACKWARD);
  motor.run(FORWARD); 
  motor3.run(BACKWARD);
  motor2.run(FORWARD);
}
void moveSidewaysRight() {

  motor.setSpeed(wheelSpeed); 
  motor1.setSpeed(wheelSpeed); 
  motor2.setSpeed(wheelSpeed); 
  motor3.setSpeed(wheelSpeed);
  motor1.run(FORWARD);
  motor.run(BACKWARD); 
  motor3.run(FORWARD);
  motor2.run(BACKWARD);
}
void rotateLeft() {

  motor.setSpeed(wheelSpeed); 
  motor1.setSpeed(wheelSpeed); 
  motor2.setSpeed(wheelSpeed); 
  motor3.setSpeed(wheelSpeed);
  motor1.run(FORWARD);
  motor.run(FORWARD); 
  motor3.run(BACKWARD);
  motor2.run(BACKWARD);
}
void rotateRight() {

  motor.setSpeed(wheelSpeed); 
  motor1.setSpeed(wheelSpeed); 
  motor2.setSpeed(wheelSpeed); 
  motor3.setSpeed(wheelSpeed);
  motor1.run(BACKWARD);
  motor.run(BACKWARD); 
  motor3.run(FORWARD);
  motor2.run(FORWARD);
}
void moveLeftForward() {

    distance = getDistance();
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance < 10) {
    stopMoving();
    Serial.println("Obstacle detected! Stopping.");
    return;
  }

  motor.setSpeed(wheelSpeed); 
  motor1.setSpeed(0); 
  motor2.setSpeed(wheelSpeed); 
  motor3.setSpeed(0);
  motor3.run(RELEASE);
  motor1.run(RELEASE);
  motor.run(FORWARD); 
  motor2.run(FORWARD);
}
void moveLeftBackward() {

  motor1.setSpeed(wheelSpeed); 
  motor.setSpeed(0); 
  motor3.setSpeed(wheelSpeed); 
  motor2.setSpeed(0);
  motor.run(RELEASE);
  motor2.run(RELEASE);
  motor1.run(BACKWARD); 
  motor3.run(BACKWARD);
   
}
void moveRightForward() {

    distance = getDistance();
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance < 10) {
    stopMoving();
    Serial.println("Obstacle detected! Stopping.");
    return;
  }

  motor.setSpeed(0); 
  motor1.setSpeed(wheelSpeed); 
  motor2.setSpeed(0); 
  motor3.setSpeed(wheelSpeed);
  motor2.run(RELEASE);
  motor.run(RELEASE);
  motor1.run(FORWARD); 
  motor3.run(FORWARD);
}
void moveRightBackward() {
  

  motor.setSpeed(wheelSpeed); 
  motor1.setSpeed(0); 
  motor2.setSpeed(wheelSpeed); 
  motor3.setSpeed(0);
  motor3.run(RELEASE);
  motor1.run(RELEASE);
  motor.run(BACKWARD); 
  motor2.run(BACKWARD);
}
void stopMoving() {
  motor.run(RELEASE);
  motor1.run(RELEASE); 
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor1.setSpeed(0);
  motor2.setSpeed(0);
  motor3.setSpeed(0);
  motor.setSpeed(0);
}
// Automatic mode custom function - run the saved steps
void runSteps() {
  while (dataIn != 13) {   // Run the steps over and over again until "RESET" button is pressed
    for (int i = 0; i <= index - 2; i++) {  // Run through all steps(index)
      if (Bluetooth.available() > 0) {      // Check for incomding data
        dataIn = Bluetooth.read();
        if ( dataIn == 15) {           // If button "PAUSE" is pressed
          while (dataIn != 14) {         // Wait until "RUN" is pressed again
            if (Bluetooth.available() > 0) {
              dataIn = Bluetooth.read();
              if ( dataIn == 13) {
                break;
              }
            }
          }
        }
        // If speed slider is changed
        if (dataIn > 100 & dataIn < 150) {
          speedDelay = dataIn / 10; // Change servo speed (delay time)
        }
       
      }
     
      // Servo 1
      if (servo01SP[i] == servo01SP[i + 1]) {
      }
      if (servo01SP[i] > servo01SP[i + 1]) {
        for ( int j = servo01SP[i]; j >= servo01SP[i + 1]; j--) {
          servo01.write(j);
          delay(speedDelay);
        }
      }
      if (servo01SP[i] < servo01SP[i + 1]) {
        for ( int j = servo01SP[i]; j <= servo01SP[i + 1]; j++) {
          servo01.write(j);
          delay(speedDelay);
        }
      }

      // Servo 2
      if (servo02SP[i] == servo02SP[i + 1]) {
      }
      if (servo02SP[i] > servo02SP[i + 1]) {
        for ( int j = servo02SP[i]; j >= servo02SP[i + 1]; j--) {
          servo02.write(j);
          delay(speedDelay);
        }
      }
      if (servo02SP[i] < servo02SP[i + 1]) {
        for ( int j = servo02SP[i]; j <= servo02SP[i + 1]; j++) {
          servo02.write(j);
          delay(speedDelay);
        }
      }

      // Servo 3
      if (servo03SP[i] == servo03SP[i + 1]) {
      }
      if (servo03SP[i] > servo03SP[i + 1]) {
        for ( int j = servo03SP[i]; j >= servo03SP[i + 1]; j--) {
          servo03.write(j);
          delay(speedDelay);
        }
      }
      if (servo03SP[i] < servo03SP[i + 1]) {
        for ( int j = servo03SP[i]; j <= servo03SP[i + 1]; j++) {
          servo03.write(j);
          delay(speedDelay);
        }
      }

      // Servo 4
      if (servo04SP[i] == servo04SP[i + 1]) {
      }
      if (servo04SP[i] > servo04SP[i + 1]) {
        for ( int j = servo04SP[i]; j >= servo04SP[i + 1]; j--) {
          servo04.write(j);
          delay(speedDelay);
        }
      }
      if (servo04SP[i] < servo04SP[i + 1]) {
        for ( int j = servo04SP[i]; j <= servo04SP[i + 1]; j++) {
          servo04.write(j);
          delay(speedDelay);
        }
      }

      // Servo 5
      if (servo05SP[i] == servo05SP[i + 1]) {
      }
      if (servo05SP[i] > servo05SP[i + 1]) {
        for ( int j = servo05SP[i]; j >= servo05SP[i + 1]; j--) {
          servo05.write(j);
          delay(speedDelay);
        }
      }
      if (servo05SP[i] < servo05SP[i + 1]) {
        for ( int j = servo05SP[i]; j <= servo05SP[i + 1]; j++) {
          servo05.write(j);
          delay(speedDelay);
        }
      }

      // Servo 6
      if (servo06SP[i] == servo06SP[i + 1]) {
      }
      if (servo06SP[i] > servo06SP[i + 1]) {
        for ( int j = servo06SP[i]; j >= servo06SP[i + 1]; j--) {
          servo06.write(j);
          delay(speedDelay);
        }
      }
      if (servo06SP[i] < servo06SP[i + 1]) {
        for ( int j = servo06SP[i]; j <= servo06SP[i + 1]; j++) {
          servo06.write(j);
          delay(speedDelay);
        }
      }
    }
  }
}