#include "Hshop_led_blink.h"
#include "Thread.h"
#include "ThreadController.h"
#include <Wire.h>;
#include <LiquidCrystal_I2C.h>;
LiquidCrystal_I2C lcd(0x27,20,4);
#include <SimpleDHT.h>
SimpleDHT11 dht11(4);
int pinDHT11 = 4;

ThreadController cpu;
Thread threadbtn2_led13;
Thread threadbtn3_ledrgb;
Thread threadgetDHT;
Thread threadpot_rgbR;
Thread threadlight_buzzer;
Thread threadgetLM35;


Hshop_led_blink led10(10,100);
Hshop_led_blink led13(13,500);
Hshop_led_blink led12(12,100);
Hshop_led_blink buzzer(5,200);
Hshop_led_blink led11(11,200);

const int  buttonPin1 = 2;
int buttonPushCounter1 = 0;  
int buttonState1 = 0;    
int lastButtonState1 = 0; 

const int  buttonPin2 = 3;
int buttonPushCounter2 = 0;  
int buttonState2 = 0;    
int lastButtonState2 = 0; 

const int pot = A0;  
const int rgbG = 9;
int potvalue = 0;        
int rgbGvalue = 0; 

const int lightsensor = A1;  
int lightsensorvalue = 0;     
 
int LM35 = A2;
int ReadLM35 = 0;

void printlcd(){
  lcd.setCursor(6,0);
  lcd.print("Hshop.vn");
  lcd.setCursor(0,1);
  lcd.print("Arduino 9in1 Shield");
}


void getLM35(){
 ReadLM35 = analogRead(LM35);
 int nhietdo =0;  
 float voltage = ReadLM35 * 4.3 / 1023.0; 
 float temp = voltage * 100.0;
 lcd.setCursor(0,2);
 lcd.print("*LM35*  T:");
 lcd.print(String(temp) +  char(223) +"C");
}


void light_buzzer(){
  lightsensorvalue = analogRead(lightsensor);
  led12.run();
  if(lightsensorvalue<100)
  {
       led12.enable = true;
  }else{
        led12.enable = false;
  }
}

void pot_rgbR(){
  potvalue = analogRead(pot);
  rgbGvalue = map(potvalue, 0, 1023, 0, 255);
  analogWrite(rgbG, rgbGvalue);
}



void Btn3_Ledrgb(){
    led11.run();
    led10.run();
   buttonState2 = digitalRead(buttonPin2);
  if (buttonState2 != lastButtonState2) {
    if (buttonState2 == HIGH) {
      buttonPushCounter2++;
    }
  }
  lastButtonState2 = buttonState2;
  if (buttonPushCounter2 % 2 == 0) 
  { 
    led11.enable = false;
  } else if (buttonPushCounter2 % 3 == 0){
    led10.enable = false;
  } else{ 
    led11.enable = true;
    led10.enable = true;
  }
  

}


void Btn2_Led13(){
    led13.run();
    buzzer.run();
   buttonState1 = digitalRead(buttonPin1);
  if (buttonState1 != lastButtonState1) {
    if (buttonState1 == HIGH) {
      buttonPushCounter1++;
    }
  }
  lastButtonState1 = buttonState1;
  if (buttonPushCounter1 % 2 == 0) { 
    led13.enable = false;
    buzzer.enable = false;
  } else {
    led13.enable = true;
    buzzer.enable = true;
  }
}


void getDHT(){
  int pinDHT11 = 4;
  byte temperature = 0;
  byte humidity = 0;
  int kk = dht11.read(&temperature, &humidity, NULL);
  lcd.setCursor(0,3);
  lcd.print("*DHT11* T:"); 
  lcd.print(String(temperature) +  char(223) +"C ");
  lcd.print("H:" + String(humidity) + "%");
}


void setup() {
  Serial.begin(9600);
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  lcd.init();  
  lcd.backlight();  
  lcd.clear();
  printlcd();
  
  threadgetDHT.setInterval(2000);
  threadgetDHT.onRun(getDHT);

  threadgetLM35.setInterval(2000);
  threadgetLM35.onRun(getLM35);

  threadpot_rgbR.setInterval(1);
  threadpot_rgbR.onRun(pot_rgbR);

  threadbtn2_led13.setInterval(1);
  threadbtn2_led13.onRun(Btn2_Led13);

  threadbtn3_ledrgb.setInterval(1);
  threadbtn3_ledrgb.onRun(Btn3_Ledrgb);

  threadlight_buzzer.setInterval(1);
  threadlight_buzzer.onRun(light_buzzer);

  
  cpu.add(&threadpot_rgbR);
  cpu.add(&threadbtn2_led13);
  cpu.add(&threadbtn3_ledrgb);
  cpu.add(&threadlight_buzzer);
  cpu.add(&threadgetLM35);
  cpu.add(&threadgetDHT);
}


void loop() {
  cpu.run();
}
