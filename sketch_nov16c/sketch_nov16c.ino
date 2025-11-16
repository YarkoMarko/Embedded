#define SDA_PIN 2
#define SCL_PIN 3
#define I2C_CLOCK_DELAY 1000

void setup() {
  pinMode(SDA_PIN, OUTPUT);
  pinMode(SCL_PIN, OUTPUT);
  
  digitalWrite(SDA_PIN, HIGH);
  digitalWrite(SCL_PIN, HIGH);
}

void manualI2Ctransmit(int address, int data) {
  delay(2000);
  
  int writeAddr = (address << 1) | 0x00;
  for (int i = 7; i >= 0; i--) {
    digitalWrite(SDA_PIN, (writeAddr >> i) & 0x01);
    delay(I2C_CLOCK_DELAY / 2);
    digitalWrite(SCL_PIN, HIGH);
    delay(I2C_CLOCK_DELAY / 2);
    digitalWrite(SCL_PIN, LOW);
    delay(I2C_CLOCK_DELAY / 2);
  }
  
  for (int i = 7; i >= 0; i--) {
    digitalWrite(SDA_PIN, (data >> i) & 0x01);
    delay(I2C_CLOCK_DELAY / 2);
    digitalWrite(SCL_PIN, HIGH);
    delay(I2C_CLOCK_DELAY / 2);
    digitalWrite(SCL_PIN, LOW);
    delay(I2C_CLOCK_DELAY / 2);
  }
  
  digitalWrite(SDA_PIN, LOW);
  digitalWrite(SCL_PIN, HIGH);
  delay(I2C_CLOCK_DELAY);
  digitalWrite(SDA_PIN, HIGH);
  delay(I2C_CLOCK_DELAY);
}

void loop() {
  manualI2Ctransmit(0b0101000, 'A');
  
  //delay(1000);
}