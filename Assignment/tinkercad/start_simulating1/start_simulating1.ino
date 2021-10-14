#include <Keypad.h>
#include <Wire.h>

const byte ROWS = 4;
const byte COL = 4;
int sec = 0;

char keys[ROWS][COL] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COL] = {5, 4, 3, 2};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COL);

String code = "";


void setup()
{
  Wire.begin(8);
  Wire.onReceive(receiveEvent);
  pinMode(10, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  char key = keypad.getKey();
  
  if (key) {
    if (key =='1' || key == '3' || key == '5' || key == '7' || key == '9')
      tone(10, 400, 100);
    if (key =='2' || key == '4' || key == '6' || key == '8' || key == '0')
      tone(10, 500, 100);
    if (key =='A' || key == 'B' || key == 'C' || key == 'D' || key == '0')
      tone(10, 300, 100);
    if (key =='*' || key == '#')
      tone(10, 600, 120);
    }
  
  if(key != NO_KEY) {
    code += key;
    
  
    if(code == "2589#") {
      /*	
      	delay(300);
      	tone(10, 700, 200);
        delay(150);      
        tone(10, 700, 200);
       */
    	Wire.beginTransmission(8);
      	Wire.print(code);
      	Wire.endTransmission();
    }
    if(key == '*') {
      	code = "lock";
    	Wire.beginTransmission(8);
      	Wire.print(code);
      	Wire.endTransmission();
      	code = "";
    }
    Serial.println(code);
  }
}

void receiveEvent(int bytes) {
  char c = Wire.read();
  sec = c - '0';
  alertOnClose(sec);
}

void alertOnClose(int n) {
  for(int i = 0; i <= n; i++) {
    Serial.println(i);
    delay(1000);
   	tone(10, 600, 100); 
  }
}