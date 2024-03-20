#define CAMERA_BUFFER_SIZE 9
#define CAMERA_HEADER 0x33
uint8_t camera_buffer[CAMERA_BUFFER_SIZE];
uint8_t camera_counter = 0;
bool camera_data_ready = false;



void setup() {
  Serial.begin(115200);
  pinMode(13, OUTPUT);

}

void loop() {
  while (Serial.available())
  {
    camera_buffer[camera_counter] = (uint8_t)Serial.read();
    // The first byte is not the packet header,
    // skip to wait till the packet header to arrive

    if (camera_counter == 0 && camera_buffer[0] != CAMERA_HEADER)
      return;
    camera_counter++;
    if (camera_counter == CAMERA_BUFFER_SIZE)  // All packet received, bool imu_data_ready = true
    {
      long current = millis();
      if (camera_buffer[3] == 50){
      }
      camera_counter = 0;
      camera_data_ready = true;
      delay(20);
        Serial.write(0x33);
        Serial.write(2);
        Serial.write(5);
      delay(20);
      
    }
  }

}