/* Chương Trình Test Cảm Biến Cường Độ Ánh Sáng (Lux) TL2561 - *BQB* - Hshop.vn
Link sản phẩm https://hshop.vn/products/cam-bien-cuong-do-anh-sang-lux-tsl2561
Module AS (Lux) TL2561 --- Arduino
    VCC                      5v
    GND                      GND
    SCL                       A5
    SDA                       A4
    
----Kiểm tra về độ rọi của ánh sáng---
* Vào buổi tối : 0.001 - 0.02 Lux
* Ánh trăng : 0.02 - 0.3 lux
* Trời nhiều mây trong nhà : 5 - 50 lux
* Trời nhiều mây ngoài trời : 50 - 500 lux
* Trời nắng trong nhà : 100 - 1000 lux
* Ánh sáng cần thiết để đọc sách: 50 - 60 lux

Thư viện của tác giả adafruit https://github.com/adafruit/TSL2561-Arduino-Library
*/


#include <Wire.h>
#include "TSL2561.h"
//TSL2561_ADDR_LOW (0x29) or TSL2561_ADDR_HIGH (0x49) , ADDR pin float (addr 0x39)
TSL2561 tsl(0x39); // Địa chỉ là 0x39

void setup(void) {
  Serial.begin(9600);
  Serial.println("Test Cam Bien Cuong Do Anh Sang (Lux) TL2561");
  tsl.setGain(TSL2561_GAIN_16X);
  tsl.setTiming(TSL2561_INTEGRATIONTIME_13MS);
  uint16_t x = tsl.getLuminosity(TSL2561_VISIBLE);   
  delay(2000);
}
void loop()
{ 
  uint32_t lum = tsl.getFullLuminosity();
  uint16_t ir, full;
  ir = lum >> 16;
  full = lum & 0xFFFF;
  Serial.print("IR: "); Serial.print(ir);   Serial.print("\t\t");
  Serial.print("Full: "); Serial.print(full);   Serial.print("\t");
  Serial.print("Visible: "); Serial.print(full - ir);   Serial.print("\t");
  Serial.print("Lux: "); Serial.println(tsl.calculateLux(full, ir));
  delay(100); 
}
