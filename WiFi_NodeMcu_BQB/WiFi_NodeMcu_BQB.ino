/*
    WiFiScan
      - Scan OK    => Led blink 50ms
      - Scan Error => Led Blink 300ms
*/
#include "Hshop_led_blink.h"
#include "Thread.h"
#include "ThreadController.h"
#include "ESP8266WiFi.h"
Hshop_led_blink led1(2,200,0,1);
Hshop_led_blink led2(16,300,0,1);
int check_blink_led = 0;

ThreadController cpu;
Thread Thread_Check_Blink;
Thread Thread_ScanWiFi;

void blinkled(){
  led1.run();
  led2.run();
  led1.enable=false;
  led2.enable=false;
//  Serial.println(check_blink_led);
  if(check_blink_led==0)
  {
    led1.enable=true;
    led2.enable=false;
  }else if(check_blink_led==1){
    led1.enable=false;
    led2.enable=true;
  }
}

void ScanWifi(){
  int n = WiFi.scanNetworks();
  Serial.print("Scan done -- ");
  if (n == 0) {
    check_blink_led = 1;
    Serial.println("no networks found");
  } else {
    check_blink_led = 0;   
    Serial.print(n);
    Serial.println(" networks found");
    for (int i = 0; i < n; ++i) {
      // Print SSID and RSSI for each network found
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.print(WiFi.SSID(i));
      Serial.print(" (");
      Serial.print(WiFi.RSSI(i));
      Serial.print(")");
      Serial.println((WiFi.encryptionType(i) == ENC_TYPE_NONE) ? " " : "*");
      check_blink_led = 0;
    }         
  }
//  check_blink_led = 1;
  Serial.println("");
}

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
  Serial.println("Hshop_Test_WiFiScan");

  Thread_Check_Blink.setInterval(1);
  Thread_Check_Blink.onRun(blinkled);

  Thread_ScanWiFi.setInterval(5000);
  Thread_ScanWiFi.onRun(ScanWifi);

  cpu.add(&Thread_Check_Blink);
  cpu.add(&Thread_ScanWiFi);  
}

void loop() {
  cpu.run();
}
