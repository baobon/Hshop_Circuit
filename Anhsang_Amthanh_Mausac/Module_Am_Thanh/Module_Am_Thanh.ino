/* Chương trình test module Am Thanh - *BQB* - Hshop.vn
Link sản phẩm :https://hshop.vn/products/cam-bien-am-thanh-2
Module Âm Thanh --- Arduino
    VCC               5v
    GND               GND
    OUT               D7
Khi nhận được âm thanh thì tín hiệu OUT ra mức thấp
*/
int i=0;
void setup() {
  pinMode(7,INPUT);
  Serial.begin(9600);
  Serial.println("Test Module Am thanh - Hshop");
 
}

void loop() {
  if(digitalRead(7)==LOW){
    ++i;
    Serial.println("Dang nhan duoc am thanh " +String(i));
  }
  delay(10);

}
