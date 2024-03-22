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
