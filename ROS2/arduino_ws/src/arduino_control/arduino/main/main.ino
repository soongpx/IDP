#include <TimedAction.h>
#include "Constant.h"
#include "Variable.h"

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
  DDRA &= 0b11111111;
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
      LeftSpeed = analogRead(Left_Pwm);
      RightSpeed = analogRead(Right_Pwm);
      VibrateSpeed = analogRead(Vibrate_Pwm);
      
      left_dir = 0;
      right_dir = 0;
      rotate_dir = 0;
      tilt_dir = 0;
      extend_dir = 0;
      vibrate_dir = 0;

      for (int i = 0; i < 8; i++)
      {
        int num = pow(2, (7-i));
        if (direction >= num)
        {
          direction -= num;
          switch (i){
            case 2:
              left_dir = 1;
              break;
            case 3:
              right_dir = 1;
              break;
            case 4:
              rotate_dir = 1;
              break;
            case 5:
              tilt_dir = 1;
              break;
            case 6:
              extend_dir = 1;
              break;
            case 7:
              vibrate_dir = 1;
              break;
          }
        }
      }

      if (VibrateSpeed < vibrate_speed)
      {
        VibrateSpeed++;
      }
      if (LeftSpeed < left_speed)
      {
        LeftSpeed++;
      }
      if (RightSpeed < right_speed)
      {
        RightSpeed++;
      }

      OperatingState = CheckActionToDo;
      break;
  }
}

void OutputTaskCode()
{
  if(LeftSpeed > 0 || RightSpeed > 0)           Loco(LeftSpeed, RightSpeed, left_dir, right_dir);
  else                                          MotorStopping();

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
  if (DIR1 == true)
    digitalWrite(Left_Dir, HIGH);
  else
    digitalWrite(Left_Dir, LOW);

  if (DIR2 == true)
    digitalWrite(Right_Dir, HIGH);
  else
    digitalWrite(Right_Dir, LOW);

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
  digitalWrite(Tilt_Dir, HIGH);
  analogWrite(Tilt_Pwm, 255);
}

void Tilt_Down(){
  digitalWrite(Tilt_Dir, LOW);
  analogWrite(Tilt_Pwm, 255);
}

void Stop_Tilting()
{
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

void setup()
{
  Serial.begin(115200);

  OperatingState = WaitStart; 
  InputTask.reset();     // Set InputTask Time stamp to current millis
  delay(3);
  ProcessTask.reset();   // Process Task Execute after 3ms InputTask is execute
  delay(3);
  OutputTask.reset();    // Output Task Execute after 3ms Process Task is execute
  delay(3);
  InputTask.enable();     // Enable Input Task to be monitored
  ProcessTask.enable();   // Enable Process Task to be monitored
  OutputTask.enable();    // Enable Output Task to be monitored
}

void loop()
{
  InputTask.check();              // Input Task fire threads every 10ms (Refer to Variable.h)
  ProcessTask.check();            // Process Task fire threads every 10ms (Refer to Variable.h)
  OutputTask.check();             // Output Task fire threads every 10ms (Refer to Variable.h)
}
