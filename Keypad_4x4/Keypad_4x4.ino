#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

/*
 * 5 4 3 2
 * 9 8 7 6
 */

// connect the pins from right to left to pin 2, 3, 4, 5,6,7,8,9
byte rowPins[ROWS] = {47,49,51,53}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {39,41,43,45}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
  Serial.begin(9600);
 Serial.print("Test KeyPad 4x4");
}
  
void loop(){
  
  char key = keypad.getKey();
    // just print the pressed key
   if (key){
    Serial.print("Key ");
    Serial.print(key);
    Serial.println(" is pressed");
  } 
  
  // this checks if 4 is pressed, then do something. Here  we print the text but you can control something.
  if (key =='4'){
    // do something here is 4 is pressed
    Serial.println("Key 4 is pressed -> Action");
  }
}
