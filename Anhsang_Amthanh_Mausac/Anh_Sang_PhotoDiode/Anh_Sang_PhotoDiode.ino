/* Chương Trình Test Cảm Biến Ánh Sáng Photodiod - *BQB* - Hshop.vn
Link sản phẩm https://hshop.vn/products/cam-bien-anh-sang-photodiod
Module AS Photodiod --- Arduino
    VCC                   5v
    GND                   GND
    A0                    A0
    DO                    D7
Khi trời sáng thì tín hiệu D0 ra mức LOW
Khi trời sáng thì tín hiệu Analog(A0) ~60-120
*/

#define pin_Digital_Sensor D7 // Kết nối chân đọc tín hiệu D0(AS_Photodiode) với chân D7(Arduino);
int sensorphotodiode;
void setup() {
  pinMode(7,INPUT);
  Serial.begin(9600);
  Serial.println("Test Module Cam bien Anh Sang PhotoDiode - Hshop");
}

void loop() {
    sensorphotodiode = analogRead(A0);
    if(digitalRead(7)==LOW){
    Serial.print("Troi dang sang ");
    }else if(digitalRead(7)==HIGH){
    Serial.print("Troi dang toi ");
    }
    Serial.println("                     Gia tri Analog: " +String(sensorphotodiode));
    delay(10);

}
