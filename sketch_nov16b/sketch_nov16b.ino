#define MOSI_PIN 11
#define SCK_PIN 13
#define CS_PIN 10
#define DATA_INDICATOR 6 

#define SPI_MODE0 0  
#define SPI_MODE1 1  
#define SPI_MODE2 2  
#define SPI_MODE3 3  

#define SPI_CLOCK_DELAY 1000

void setup() {
  pinMode(MOSI_PIN, OUTPUT);
  pinMode(SCK_PIN, OUTPUT);
  pinMode(CS_PIN, OUTPUT);
  pinMode(DATA_INDICATOR, OUTPUT);  
  
  digitalWrite(CS_PIN, HIGH); 
  digitalWrite(SCK_PIN, LOW); 
  digitalWrite(DATA_INDICATOR, LOW);
}

void manualSPIsendWithIndicator(int data, int mode) {
  if (mode == SPI_MODE0 || mode == SPI_MODE1) {
    digitalWrite(SCK_PIN, LOW);
  } else {
    digitalWrite(SCK_PIN, HIGH);
  }
  
  digitalWrite(CS_PIN, LOW);
  
  for (int i = 7; i >= 0; i--) {
    digitalWrite(MOSI_PIN, (data >> i) & 0x01);
    digitalWrite(DATA_INDICATOR, HIGH); 
    
    delay(SPI_CLOCK_DELAY / 2);
    
    if (mode == SPI_MODE0 || mode == SPI_MODE2) {
      digitalWrite(SCK_PIN, !digitalRead(SCK_PIN));
      digitalWrite(DATA_INDICATOR, LOW);
      
      delay(SPI_CLOCK_DELAY / 2);
      digitalWrite(SCK_PIN, !digitalRead(SCK_PIN));
    } else {
      digitalWrite(SCK_PIN, !digitalRead(SCK_PIN));
      delay(SPI_CLOCK_DELAY / 2);
      
      digitalWrite(MOSI_PIN, (data >> i) & 0x01); 
      digitalWrite(SCK_PIN, !digitalRead(SCK_PIN)); 
      digitalWrite(DATA_INDICATOR, LOW); 
    }
  }
  
  digitalWrite(CS_PIN, HIGH);
}

void loop() {
  manualSPIsendWithIndicator('A', SPI_MODE0);
  
  delay(1000);
}