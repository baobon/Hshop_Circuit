// Thứ tự chân GND
// Thứ tự chân GND
// Thứ tự chân VCC
// Thứ tự chân RXD  - TXD CP1202
// Thứ tự chân GND  - RXD CP2102
// Thứ tự chân 6 bỏ trống hoặc nối vào Reset

void setup()
{
  pinMode(13, OUTPUT);
}

void loop() {
  digitalWrite(13, HIGH);   
  delay(1000);                   
  digitalWrite(13, LOW);   
  delay(1000);                     
}
