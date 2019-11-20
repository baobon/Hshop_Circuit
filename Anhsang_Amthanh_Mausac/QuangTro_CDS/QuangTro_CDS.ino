/* Chương Trình Test Cảm Biến Ánh Sáng Quang Trở CDS - *BQB* - Hshop.vn
Link sản phẩm https://hshop.vn/products/cam-bien-anh-sang-quang-tro-2
Module AS Quang Trở CDS --- Arduino
    VCC                       5v
    GND                       GNDA0
    DO                        D7
Khi trời sáng thì tín hiệu D0 ra mức LOW
*/

void setup() {
  pinMode(7,INPUT);
  Serial.begin(9600);
  Serial.println("Test Module Ánh Sáng Quang Trở CDS - Hshop");
  delay(2000);

}

void loop() {
    if(digitalRead(7)==LOW){
    Serial.println("Troi dang sang ");
    }else if(digitalRead(7)==HIGH){
    Serial.println("Troi dang toi ");
    }
    delay(10);

}
