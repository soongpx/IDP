// Arduino sketch for controlling a DC motor via ROS 2

// Define motor control pins
// #define MOTOR_ENA 5 // Enable pin for motor A
// #define MOTOR_IN1 6 // Input 1 pin for motor A
// #define MOTOR_IN2 7 // Input 2 pin for motor A

// Define serial communication parameters
#define BAUD_RATE 115200

// Variables to store received commands
int command;
int speed;
bool bytesarray[8] = {0,0,0,0,0,0,0,0};

void setup() {
  // Initialize serial communication
  Serial.begin(BAUD_RATE);

  // Set motor control pins as outputs
  pinMode(13, OUTPUT);
        digitalWrite(13, 0);

  // Initially stop the motor
  stopMotor();
}

void loop() {
  // Check if data is available to read from serial
  if (Serial.available()) {
    // Read the incoming command
    command = int(Serial.read());

    // Execute command
    for (int i = 7; i >= 0; i--){
      if (command % 2 == 1) {
        bytesarray[i] = 1;
      } else{
        bytesarray[i] = 0;
      }
      command = int(command/2);
      // if (command == 0){
      //   break;
      // }
    }
    if (bytesarray[0] == 0){
      speed = 0;
      stopMotor();
    } 
      Serial.println(bytesarray[0]);
      Serial.println(bytesarray[1]);
    if (bytesarray[1] == 0){
      digitalWrite(13, 1);
      speed = 255; // Backward at full speed
      runMotor(speed, LOW, HIGH);
    } else{
      digitalWrite(13, 0);
      speed = 255; // Forward at full speed
      runMotor(speed, HIGH, LOW);
    }
  }
}

// Function to control motor movement
void runMotor(int speed, int dir1, int dir2) {
}

// Function to stop the motor
void stopMotor() {
}
