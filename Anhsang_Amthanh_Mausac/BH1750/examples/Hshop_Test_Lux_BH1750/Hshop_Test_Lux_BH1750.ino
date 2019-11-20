/* Chương Trình Test Cảm Biến Cường Độ Ánh Sáng (Lux) BH1750 - *BQB* - Hshop.vn
Link sản phẩm https://hshop.vn/products/cam-bien-cuong-do-onh-song-lux-bh1750
Module AS (Lux) BH1750 --- Arduino
    VCC                      5v
    GND                      GNDA0
    SCL                       A5
    SDA                       A4
Địa chỉ của BH1750 mặc định là 0x5C    
----Kiểm tra về độ rọi của ánh sáng---
* Vào buổi tối : 0.001 - 0.02 Lux
* Ánh trăng : 0.02 - 0.3 lux
* Trời nhiều mây trong nhà : 5 - 50 lux
* Trời nhiều mây ngoài trời : 50 - 500 lux
* Trời nắng trong nhà : 100 - 1000 lux
* Ánh sáng cần thiết để đọc sách: 50 - 60 lux

Thư viện của tác giả claws https://github.com/claws/BH1750
*/

#include <Wire.h>
#include <BH1750.h>
BH1750 lightSensor(0x5C);



void setup() {
  Serial.begin(9600);
  Wire.begin();
  lightSensor.begin(BH1750::CONTINUOUS_HIGH_RES_MODE);
  Serial.println("Chương trình test CB BH1750(LUX)-Hshop.vn");

}

void loop() {
  float lux = lightSensor.readLightLevel();
  Serial.print("Cuong do anh sang: ");
  Serial.print(lux);
  Serial.println(" lx");
  delay(1000);

}
