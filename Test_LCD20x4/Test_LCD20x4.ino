#include <LiquidCrystal_I2C.h>;
LiquidCrystal_I2C lcd(0x27,20,4);

void setup() {
  
  lcd.init();  
  lcd.backlight();  
  lcd.clear();
  
}

void loop() {
  lcd.setCursor(5,0);
  lcd.print("LLAB Co.Ltd");
  lcd.setCursor(2,1);
  lcd.print("B&W AUTO PROCESS");
  lcd.setCursor(1,2);
  lcd.print("DO NOT OPEN COVER");
  lcd.setCursor(1,3);
  lcd.print("Thank You & Enjoy");

}
