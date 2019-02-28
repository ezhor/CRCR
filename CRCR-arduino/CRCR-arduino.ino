// La velocidad depende del modelo de ESP-01
// siendo habituales 9600 y 115200
#define BAUD_RATE_SERIAL 9600
#define BAUD_RATE_SERIAL1 115200
 

void setup()  {
  Serial.begin(BAUD_RATE_SERIAL);
  Serial1.begin(BAUD_RATE_SERIAL1);
}
void loop()  {
   if (Serial1.available()) {
      Serial.write((char)Serial1.read());
   }
 
  if (Serial.available()) {
     Serial1.write((char)Serial.read());
  }
}
