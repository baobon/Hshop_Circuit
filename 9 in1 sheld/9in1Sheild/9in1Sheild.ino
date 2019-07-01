/*Write by BQB
Light_sensor -> buzzer(100ms), led(300ms);
Button 2 click :  

*/


#include "Vietduino_Manager.h"
#include "Vietduino_NewFunction.h"
#include "Hshop_led_blink.h"
#include <Wire.h>;
#include <LiquidCrystal_I2C.h>;
LiquidCrystal_I2C lcd(0x27,20,4);
#include <SimpleDHT.h>
SimpleDHT11 dht11(4);
#define pinDHT11 4
#define led12 12
#define led13 13
#define rgb9 9
#define rgb10 10
#define rgb11 11
#define buttonPin1 3
#define buttonPin2 2
#define pot A0
#define lightsensor A1
#define LM35 A2
#define buzzer 5
byte rgbR = 0;
//const int  buttonPin1 = 2;
int buttonPushCounter1 = 0;  
int buttonState1 = 0;    
int lastButtonState1 = 0; 
int buttonPushCounter2 = 0;  
int buttonState2 = 0;    
int lastButtonState2 = 0; 
const int rgbG = 9;
int potvalue = 0;        
int rgbGvalue = 0; 
int lightsensorvalue = 0;     
int ReadLM35 = 0;

void pinsMode(){
  pinMode(led12,OUTPUT);
  pinMode(led13,OUTPUT);
  pinMode(rgb9,OUTPUT);
  pinMode(rgb10,OUTPUT);
  pinMode(rgb10,OUTPUT);   
  pinMode(buzzer,OUTPUT);   
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
}


void setup() {
 pinsMode();
 Serial.begin(9600);
 lcd.init();  
 lcd.backlight();  
 lcd.clear();

}

void loop() {
   VIETDUINO_UPDATE;
}

CREATE_FUNCTION(Example){
  
    END_CREATE_FUNCTION
}

CREATE_FUNCTION(getLM35){
 ReadLM35 = analogRead(LM35);
 float temp = ReadLM35 *0.48828125;
 lcd.setCursor(0,2);
 lcd.print("*LM35*  T:");
 lcd.print(String(temp) +  char(223) +"C");
   M_DELAY(2000);
    END_CREATE_FUNCTION
}

CREATE_FUNCTION(getDHT){
  byte temperature = 0;
  byte humidity = 0;
  int kk = dht11.read(&temperature, &humidity, NULL);
  lcd.setCursor(0,3);
  lcd.print("*DHT11* T:"); 
  lcd.print(String(temperature) +  char(223) +"C ");
  lcd.print("H:" + String(humidity) + "%");
  M_DELAY(2000);
    END_CREATE_FUNCTION
}

CREATE_FUNCTION(Buzzer_States){
   lightsensorvalue = analogRead(lightsensor);
  if(lightsensorvalue<300)
  {
       digitalWrite(buzzer,1);
        M_DELAY(100);
       digitalWrite(buzzer,0);
        M_DELAY(100);
  }else{
       digitalWrite(buzzer,0);    
  }
    END_CREATE_FUNCTION
}


CREATE_FUNCTION(Light_States){
   lightsensorvalue = analogRead(lightsensor);
  if(lightsensorvalue<300)
  {
       digitalWrite(led12,1);
        M_DELAY(300);
       digitalWrite(led12,0);
        M_DELAY(300);
  }else{
       digitalWrite(led12,0);    
  }
    END_CREATE_FUNCTION
}


CREATE_FUNCTION(Analog_States){
  potvalue = analogRead(pot);
  rgbGvalue = map(potvalue, 0, 1023, 0, 255);
  if(rgbR == 0){
     analogWrite(rgb9, rgbGvalue);
  }
  
  

  END_CREATE_FUNCTION
}

CREATE_FUNCTION(Button_States){
  Serial.print(buttonPushCounter1);
  Serial.print("            ");
  Serial.println(rgbR);
  buttonState2 = digitalRead(buttonPin2);
  if (buttonState2 != lastButtonState2) {
    if (buttonState2 == HIGH) {
      buttonPushCounter2++;
    }
  }
  lastButtonState2 = buttonState2;
  if(buttonPushCounter2==5)
  {
    buttonPushCounter2 = 0;
  }

 
   buttonState1 = digitalRead(buttonPin1);
  if (buttonState1 != lastButtonState1) {
    if (buttonState1 == HIGH) {
      buttonPushCounter1++;
    }
  }
  lastButtonState1 = buttonState1;
  if(buttonPushCounter1==5)
  {
    buttonPushCounter1 =0;
  }

  
  END_CREATE_FUNCTION
}

CREATE_FUNCTION(Btn3_Ledrgb10_11){  
  if (buttonPushCounter1 == 1){ 
    rgbR = 0;
    digitalWrite(rgb10,1);
     M_DELAY(300);
    digitalWrite(rgb10,0);
     M_DELAY(300);
  } else if (buttonPushCounter1 == 2){
    rgbR = 0;
    digitalWrite(rgb11,1);
     M_DELAY(100);
    digitalWrite(rgb11,0);
     M_DELAY(100);
  } else if (buttonPushCounter1 == 3){
    rgbR = 1;
    digitalWrite(rgb9,1);
     M_DELAY(100);
    digitalWrite(rgb9,0);
     M_DELAY(100);   
  } else if (buttonPushCounter1 == 4){
    rgbR = 1;
    digitalWrite(rgb9,1);
    M_DELAY(200);
    digitalWrite(rgb10,1);
    M_DELAY(200);
    digitalWrite(rgb11,1);
    M_DELAY(200);
    digitalWrite(rgb9,0);
    M_DELAY(200);
    digitalWrite(rgb10,0);
    M_DELAY(200);
    digitalWrite(rgb11,0);
    M_DELAY(200);
  }else{  
    rgbR = 0;
    digitalWrite(rgb10,0);
    digitalWrite(rgb11,0);
  }
  END_CREATE_FUNCTION
}

CREATE_FUNCTION(Btn3_Led12){  
  if (buttonPushCounter2 == 1) 
  { 
    digitalWrite(led13,1);
     M_DELAY(50);
    digitalWrite(led13,0);
     M_DELAY(50);
  } else if (buttonPushCounter2 == 2){
    digitalWrite(led13,1);
     M_DELAY(1000);
    digitalWrite(led13,0);
     M_DELAY(1000);
  } else if (buttonPushCounter2 == 3){
    digitalWrite(led13,1);
     M_DELAY(500);
    digitalWrite(led13,0);
     M_DELAY(500);
  } else if (buttonPushCounter2 == 4){
    digitalWrite(led13,1);
     M_DELAY(100);
    digitalWrite(led13,0);
     M_DELAY(500);
  }else{  
    digitalWrite(led13,0);
  }
  END_CREATE_FUNCTION
}
