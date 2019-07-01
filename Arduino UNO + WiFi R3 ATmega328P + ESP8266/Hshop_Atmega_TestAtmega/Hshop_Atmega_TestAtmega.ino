//Chon Jp : 3,4 ON

void setup() {
 Serial.begin(9600);
 Serial.println("Test Kit Arduino UNO + WiFi R3 ATmega328P + ESP8266");
 pinMode(13,OUTPUT);
 

}

void loop() {
//  Serial.println("Test Kit Arduino UNO + WiFi R3 ATmega328P + ESP8266");
  Serial.println("Hshop.vn");
  digitalWrite(13,HIGH);
  delay(100);
  digitalWrite(13,LOW);
  delay(3000);
}
