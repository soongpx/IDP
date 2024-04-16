// Locomotion
#define Left_Pwm 2
#define Left_Dir 22
#define Right_Pwm 3
#define Right_Dir 23

// Mechanism
#define Rotate_Pwm 4
#define Rotate_Dir 24
#define Tilt_Pwm 5
#define Tilt_Dir 25
#define Extend_Pwm 6
#define Extend_Dir 26
#define Vibrate_Pwm 7
#define Vibrate_Dir 27

// Serial
#define Serial_Size 9
#define Serial_Header_Byte 0x33

// State
enum
{
  WaitStart,
  CheckActionToDo,
} state;


//++++++++++++++++++++++++++++++++++++++ Program State +++++++++++++++++++++++++++++++++++++++//
uint8_t OperatingState;
uint8_t LocoState;
uint8_t MechanismState;


//++++++++++++++++++++++++++++++++ Output Bool Switch & Value ++++++++++++++++++++++++++++++++++//
// USB Serial
uint8_t serial_buffer[Serial_Size];
uint8_t input_data[Serial_Size-2];
uint8_t serial_counter = 0;
bool serial_data_ready = 0;
int serial_time_counter = 0;

// Locomotion
uint8_t left_speed = 0;
uint8_t right_speed = 0;
uint8_t LeftSpeed = 0;
uint8_t RightSpeed = 0;
bool left_dir = 0;
bool right_dir = 0;

// Mechanism
uint8_t rotate_speed = 0;
uint8_t tilt_speed = 0;
uint8_t extend_speed = 0;
uint8_t vibrate_speed = 0;
uint8_t RotateSpeed = -1;
uint8_t TiltSpeed = -1;
uint8_t ExtendSpeed = -1;
uint8_t VibrateSpeed = -1;
int left_counter = 0;
int right_counter = 0;
int vibrate_counter = 0;
bool rotate_dir = 0;
bool tilt_dir = 0;
bool extend_dir = 0;
bool vibrate_dir = 0;
uint8_t direction = 0;


void Serial_Init()
{
  // Serial Setup
  Serial.begin(115200);

  // Serial Signal Setup
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
}

void Motor_Init()
{
  // Setup Motor Pin
  DDRA = B11111111;
  PORTA = B00000000;
}

void InputTaskCode()
{
  // Serial input
  if (Serial.available())
  {
    serial_buffer[serial_counter] = (uint8_t)Serial.read();
    if (serial_counter == 0 && serial_buffer[0] != Serial_Header_Byte)
      return;
    serial_counter++;
    serial_time_counter = 0;
    if (serial_counter == Serial_Size)  // All packet received, bool imu_data_ready = true
    {
      serial_counter = 0;
      serial_data_ready = true;
      for (int i = 1; i < (Serial_Size - 1); i++)
        input_data[i-1] = serial_buffer[i];
      Serial.write(0x33);
      Serial.write(2);
      Serial.write(5);
    }
  }
  else if (serial_time_counter >= 250)
  {
    for (int i = i; i < 7; i++)
      input_data[i] = 0;
  }
  else
  {
    serial_time_counter++;
  }
}

void ProcessTaskCode()
{
  switch(OperatingState)
  {
    case WaitStart:
      if(vibrate_speed > 0)
      {
        OperatingState = CheckActionToDo;
      }
      break;

    case CheckActionToDo:
      left_speed = input_data[0];
      right_speed = input_data[1];
      rotate_speed = input_data[2];
      tilt_speed = input_data[3];
      extend_speed = input_data[4];
      vibrate_speed = input_data[5];
      direction = input_data[6];      
      
      left_dir = 0;
      right_dir = 0;
      rotate_dir = 0;
      tilt_dir = 0;
      extend_dir = 0;
      vibrate_dir = 0;

      right_dir = (direction >> 1) & 1;
      left_dir = (direction >> 0) & 1;
      rotate_dir = (direction >> 2) & 1;
      tilt_dir = (direction >> 3) & 1;
      extend_dir = (direction >> 4) & 1;
      vibrate_dir = (direction >> 5) & 1;
      


      if (LeftSpeed < left_speed)
      {
        if (left_counter >= 200)
        {
          LeftSpeed++;
          left_counter = 0;
        }
        else
        {
          left_counter++;
        }
      } else if (LeftSpeed > left_speed)
      {
        if (left_counter >= 150)
        {
          LeftSpeed--;
          left_counter = 0;
        } else
        {
          left_counter++;
        }
      }
      // if (left_speed == 0)
      // {
      //   LeftSpeed = 0;
      // }

      if (RightSpeed < right_speed)
      {
        if (right_counter >= 200)
        {
          RightSpeed++;
          right_counter = 0;
        } else
        {
          right_counter++;
        }
      } else if (RightSpeed > right_speed)
      {
        if (right_counter >= 150)
        {
          RightSpeed--;
          right_counter = 0;
        } else
        {
          right_counter++;
        }
      }
      // if (right_speed == 0)
      // {
      //   RightSpeed = 0;
      // }

      if (VibrateSpeed < vibrate_speed)
      {
        if (vibrate_counter == 100)
        {
          VibrateSpeed++;
          vibrate_counter = 0;
        } else
        {
          vibrate_counter++;
        }
      } else if (VibrateSpeed > vibrate_speed)
      {
        if (vibrate_counter == 100)
        {
          VibrateSpeed--;
          vibrate_counter = 0;
        } else
        {
          vibrate_counter++;
        }
      }
      // if (vibrate_speed == 0)
      // {
      //   VibrateSpeed = 0;
      // }

      RotateSpeed = rotate_speed;
      TiltSpeed = tilt_speed;
      ExtendSpeed = extend_speed;

      OperatingState = CheckActionToDo;
      break;
  }
}

void OutputTaskCode()
{
  Loco(LeftSpeed, RightSpeed, left_dir, right_dir);

  if(rotate_dir == 1 && RotateSpeed > 0)        Rotate_CW(RotateSpeed);
  else if(rotate_dir == 0 && RotateSpeed > 0)   Rotate_CCW(RotateSpeed);
  else                                          Stop_Rotate();

  if(tilt_dir == 1 && tilt_speed > 0)           Tilt_Up();
  else if(tilt_dir == 0 && tilt_speed > 0)      Tilt_Down();
  else                                          Stop_Tilting();

  if(extend_dir == 1 && extend_speed > 0)       Extend();
  else if(extend_dir == 0 && extend_speed > 0)  Retract();
  else                                          Stop_Extend();

  if(vibrate_speed > 0)                         Vibrate(VibrateSpeed);
  else                                          Stop_Vibrate();
}

//Locomotion
int cap200PWMValue(int pwm){
  if (pwm > 200){
    return 200;
  } else{
    return pwm;
  }
}

void Loco(int PWM1, int PWM2, bool DIR1, bool DIR2)
{
  if (DIR1 == 1){
    digitalWrite(Left_Dir, LOW);
    digitalWrite(13, 1);
  } else {
    digitalWrite(Left_Dir, HIGH);
    digitalWrite(13, 0);
  }

  if (DIR2 == 1){
    digitalWrite(Right_Dir, LOW);
  } else {
    digitalWrite(Right_Dir, HIGH);
  }
  

  analogWrite(Left_Pwm, cap200PWMValue(PWM1));
  analogWrite(Right_Pwm, cap200PWMValue(PWM2));
}

void MotorStopping()
{
  analogWrite(Left_Pwm, 0);
  analogWrite(Right_Pwm, 0);
}

//Mechanism
void Rotate_CW(int PWM){
  digitalWrite(Rotate_Dir, HIGH);
  analogWrite(Rotate_Pwm, PWM);
}

void Rotate_CCW(int PWM){
  digitalWrite(Rotate_Dir, LOW);
  analogWrite(Rotate_Pwm, PWM);
}

void Stop_Rotate(){
  analogWrite(Rotate_Pwm, 0);
}

void Tilt_Up(){
  digitalWrite(13, 1);
  digitalWrite(Tilt_Dir, HIGH);
  analogWrite(Tilt_Pwm, 255);
}

void Tilt_Down(){
  digitalWrite(Tilt_Dir, LOW);
  analogWrite(Tilt_Pwm, 255);
}

void Stop_Tilting()
{
  digitalWrite(13, 0);
  analogWrite(Tilt_Pwm, 0);
}

void Extend(){
  digitalWrite(Extend_Dir, HIGH);
  analogWrite(Extend_Pwm, 255);
}

void Retract(){
  digitalWrite(Extend_Dir, LOW);
  analogWrite(Extend_Pwm, 255);
}

void Stop_Extend(){
  analogWrite(Extend_Pwm, 0);
}

void Vibrate(int PWM){
  digitalWrite(Vibrate_Dir, HIGH);
  analogWrite(Vibrate_Pwm, PWM);
}

void Stop_Vibrate(){
  analogWrite(Vibrate_Pwm, 0);
}

void setup() {
  Serial_Init();
  Motor_Init();
  OperatingState = CheckActionToDo;

}

void loop() {
  InputTaskCode();
  ProcessTaskCode();
  OutputTaskCode();

}
