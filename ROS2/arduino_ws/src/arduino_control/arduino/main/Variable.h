//++++++++++++++++++++++++++++++++++++++ TimedAction Threads +++++++++++++++++++++++++++++++++++++++//
void InputTaskCode();
void ProcessTaskCode();
void OutputTaskCode();
TimedAction InputTask = TimedAction(10, InputTaskCode); // fire threads every 10ms
TimedAction ProcessTask = TimedAction(10, ProcessTaskCode);
TimedAction OutputTask = TimedAction(10, OutputTaskCode);

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

// Locomotion
uint8_t left_speed = 0;
uint8_t right_speed = 0;
uint8_t LeftSpeed = -1;
uint8_t RightSpeed = -1;
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
bool rotate_dir = 0;
bool tilt_dir = 0;
bool extend_dir = 0;
bool vibrate_dir = 0;
uint8_t direction = 0;
