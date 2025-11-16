#define TX_PIN 2
#define BIT_DELAY_US 1000

void setup() {
  pinMode(TX_PIN, OUTPUT);
  digitalWrite(TX_PIN, HIGH);
}

void manualUARTsend(int data) {
  delay(1000);
  digitalWrite(TX_PIN, LOW);
  delay(BIT_DELAY_US);
  
  for (int i = 0; i < 8; i++) {
    digitalWrite(TX_PIN, (data >> i) & 0x01);
    delay(BIT_DELAY_US);
  }
  
  digitalWrite(TX_PIN, HIGH);
  delay(BIT_DELAY_US);
}

void loop() {
  manualUARTsend('A');
  
  delay(1000);
}