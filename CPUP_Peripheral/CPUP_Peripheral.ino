void setup() {
  Serial.begin(115200);
  Serial1.begin(115200);

  Serial.setTimeout(1);
  Serial1.setTimeout(1);
}

byte serial_buff[1024];

void loop() {
  //From PC to CPUP
    size_t len = Serial.readBytes(serial_buff,1024);
    Serial1.write(serial_buff,len);
    
  //From CPUP to PC
    len = Serial1.readBytes(serial_buff,1024);
    Serial.write(serial_buff,len);
}
