void setup() {
  Serial.begin(9600);

}

void loop() {
  for(int i=0;i<255/2;i++){
    analogWrite(9,i);
    delay(10);
  Serial.println(i);
  }
  delay(2000); 
  for(int i=255/2;i<255;i++){
      Serial.println(i);
    analogWrite(9,i);
    delay(100);
  }
  delay(2000);
}
