#include <Wire.h>
#include <Servo.h>
#include <LiquidCrystal.h>
#include <Adafruit_NeoPixel.h>

#define PIN 8	 // input pin Neopixel is attached to

#define NUMPIXELS      12 // number of neopixels in strip
int delayval = 50; // timing delay in milliseconds

int redColor = 0;
int greenColor = 0;
int blueColor = 0;
int pos = 0;
int seconds = 5;
int status = 0; //closed
int buttonState = 0;

Servo lock;
LiquidCrystal lcd(11, 10, 5, 4, 3, 2);
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int greenLed = 12;
int redLed = 13;
int buttonPin = 6;
const int pingPin = 7;

String code = "";

void setup()
{
  Wire.begin(8);
  Wire.onReceive(receiveEvent);
  
  pixels.begin();
  
  lcd.begin(16, 2);
  lcd.print("Status:");
  printStatus(status);
  
  lock.attach(9, 500, 2500);
  lock.write(90);
  
  pinMode(greenLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(buttonPin, INPUT);
  
  digitalWrite(greenLed, LOW);
  digitalWrite(redLed, HIGH);
  
  Serial.begin(9600);
}

void loop()
{
  //PING setup
  long duration, cm;
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);
  cm = microsecondsToCentimeters(duration);
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  
  
  Serial.println("Loop starting");
  buttonState = digitalRead(buttonPin);
  
  if (buttonState == HIGH & cm < 50) {
    openDoor(1);
    status = 1;
  } else {
    closeDoor(0);
  }
  delay(100);
  
  if (status == 1) {
    delay(1000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Closing in:");
    
    while(seconds > 0) {
      	lcd.setCursor(0, 1);
    	lcd.print(seconds);
      	Serial.print(seconds);
      	ledBlink();
      	pixels.clear();
		delay(900);
      	seconds--;
    }
    Serial.println("Closing door");
    lcd.clear();
    status = 0;
    closeDoor(0);
  } 
}

void closeDoor(int status) {
	digitalWrite(greenLed, LOW);
    digitalWrite(redLed, HIGH);
  	ledStop();
    printStatus(status);
  	seconds = 5;
    lock.write(90);  
}

void openDoor(int status){
	digitalWrite(greenLed, HIGH);
    digitalWrite(redLed, LOW);
    printStatus(status);
  	//sendEvent(5);
    lock.write(0); 
  	
    Serial.println("Opening door");
}

void receiveEvent(int bytes){
  String code = "";
  while(Wire.available() > 0) {
  	char c = Wire.read();
	code += c;
  }
  if(code == "lock") {
    	status = 0;
		closeDoor(status);
    } 
  	if(code == "2589#") {
      	status = 1;
        Serial.println(status);
    	openDoor(status);
    }
}

void sendEvent(int seconds) {
 	Wire.beginTransmission(8);
  Serial.println("Sending seconds");
    Wire.print(seconds);
    Wire.endTransmission(); 
  Serial.println("Sent!");
  return;
}

void printStatus(int status) {
  if (status == 1) {
    lcd.setCursor(0, 1);
    lcd.print("Door open");
    lcd.setCursor(0, 0);
    lcd.print("Closing in:");
    lcd.setCursor(0, 1);
    lcd.print(seconds);
  }
  if (status == 0) {
    lcd.setCursor(0, 0);
    lcd.print("Status:");
	lcd.setCursor(0, 1);
    lcd.print("Door closed");    
  }
}

void setColor(){
  redColor = random(0, 255);
  greenColor = random(0,255);
  blueColor = random(0, 255);
}

void ledBlink() {
  setColor();

  for (int i=0; i < NUMPIXELS; i++) {
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(0, 128, 0));

    // This sends the updated pixel color to the hardware.
    pixels.show();

    // Delay for a period of time (in milliseconds).
    delay(delayval);
  }
}

void ledStop() {
  uint32_t red = pixels.Color(255, 0, 0);
  pixels.fill(red, 0);
  pixels.show();
}

long microsecondsToInches(long microseconds) {
  // According to Parallax's datasheet for the PING))), there are 73.746
  // microseconds per inch (i.e. sound travels at 1130 feet per second).
  // This gives the distance travelled by the ping, outbound and return,
  // so we divide by 2 to get the distance of the obstacle.
  // See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the object we
  // take half of the distance travelled.
  return microseconds / 29 / 2;
}
  

