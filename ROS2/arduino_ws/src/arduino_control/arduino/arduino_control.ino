// Arduino sketch for controlling a DC motor via ROS 2

// Define motor control pins
#define MOTOR_ENA 5 // Enable pin for motor A
#define MOTOR_IN1 6 // Input 1 pin for motor A
#define MOTOR_IN2 7 // Input 2 pin for motor A

// Define serial communication parameters
#define BAUD_RATE 9600

// Variables to store received commands
char command;
int speed;

void setup() {
  // Initialize serial communication
  Serial.begin(BAUD_RATE);

  // Set motor control pins as outputs
  pinMode(MOTOR_ENA, OUTPUT);
  pinMode(MOTOR_IN1, OUTPUT);
  pinMode(MOTOR_IN2, OUTPUT);

  // Initially stop the motor
  stopMotor();
}

void loop() {
  // Check if data is available to read from serial
  if (Serial.available() > 0) {
    // Read the incoming command
    command = Serial.read();

    // Execute command
    switch (command) {
      case 'F':
        speed = 255; // Forward at full speed
        runMotor(speed, HIGH, LOW);
        break;
      case 'B':
        speed = 255; // Backward at full speed
        runMotor(speed, LOW, HIGH);
        break;
      case 'S':
        stopMotor();
        break;
    }
  }
}

// Function to control motor movement
void runMotor(int speed, int dir1, int dir2) {
  analogWrite(MOTOR_ENA, speed); // Set motor speed
  digitalWrite(MOTOR_IN1, dir1); // Set motor direction
  digitalWrite(MOTOR_IN2, dir2);
}

// Function to stop the motor
void stopMotor() {
  analogWrite(MOTOR_ENA, 0); // Turn off motor
  digitalWrite(MOTOR_IN1, LOW); // Set both motor inputs to LOW
  digitalWrite(MOTOR_IN2, LOW);
}

