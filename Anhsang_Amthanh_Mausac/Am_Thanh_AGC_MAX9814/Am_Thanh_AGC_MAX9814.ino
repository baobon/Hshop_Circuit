/*Chuong trình Test Cảm Biến Âm Thanh Tích Hợp AGC MAX9814 - *BQB* - Hshop
Link sản phẩm :https://hshop.vn/products/cam-bien-am-thanh-tich-hop-max9814
Chân OUT của cảm biến xuất tín hiệu ra Analog
  Module Âm Thanh ----- Arduino
        GND               GND
        VDD(V+)           5V
        OUT               A0
Sau khi nạp chương trình sử dụng Ctrl+Shift+M để mở Serail Plotter
*/

int sensorsound;

void setup() {
  Serial.begin(9600);

}

void loop() {
 sensorsound = analogRead(A0);
 Serial.println(sensorsound);
 delay(5);
}
