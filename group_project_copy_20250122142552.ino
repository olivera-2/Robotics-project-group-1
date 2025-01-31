//pins for sensor
#define echoPin 7
#define trigPin 6

//pins for motor
#define FwdRot_leftMotor 2
#define BckRot_LeftMotor 3
#define FwdRot_RgtMotor 4
#define BckRot_RgtMotor 5

//pins for LCD display
#include <LiquidCrystal.h>
LiquidCrystal Lcd(13, 12, 8, 9, 10, 11);

long duration;
int distance;

//pins for GPS
#include <SoftwareSerial.h>
SoftwareSerial gpsSerial(0, 1);
 
void setup() {
pinMode(echoPin, OUTPUT);
pinMode(trigPin, OUTPUT);
pinMode(FwdRot_leftMotor, OUTPUT);
pinMode(BckRot_LeftMotor, OUTPUT);
pinMode(FwdRot_RgtMotor, OUTPUT); 
pinMode(BckRot_RgtMotor, OUTPUT);
Lcd.begin(16, 2);
 Serial.begin(9600);
  gpsSerial.begin(9600);
  Lcd.begin(16, 2);
  Lcd.print("GPS Initializing...");
}

void loop() {
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  
  duration = pulseIn(echoPin, HIGH); 
  distance = duration * 0.034/2
  ;
  Lcd.setCursor(0,0);
  Lcd.print("Distance");
  Lcd.setCursor(9,0);
  Lcd.print("Distance");


  if(distance>= 500) {
   //rotate in opposie direction 
   Lcd.clear();
   Lcd.setCursor(0, 1);
   Lcd.print("Moving Back");
   digitalWrite(BckRot_LeftMotor, HIGH);
   digitalWrite(BckRot_RgtMotor, HIGH);

   digitalWrite(FwdRot_leftMotor, LOW);
   digitalWrite(FwdRot_RgtMotor, LOW);
   
   delay(1000);
   Lcd.clear();
   Lcd.setCursor(1,0);
   Lcd.print("Moving Left");


   //move in left/right direction
   digitalWrite(BckRot_LeftMotor, HIGH);
   digitalWrite(BckRot_RgtMotor, LOW);

   digitalWrite(FwdRot_leftMotor, HIGH);
   digitalWrite(FwdRot_RgtMotor, LOW);

  } else {
    //moving forward
   Lcd.clear();
   Lcd.setCursor(0,1);
   Lcd.print("Moving Forward"); 
   Lcd.setCursor(0,0);
  Lcd.print("Distance");
  Lcd.setCursor(9,0);
  Lcd.print("Distance");
   
   digitalWrite(BckRot_LeftMotor, LOW);
   digitalWrite(BckRot_RgtMotor, LOW);

   digitalWrite(FwdRot_leftMotor, HIGH);
   digitalWrite(FwdRot_RgtMotor, HIGH);
     }
      if (gpsSerial.available()) {
    char c = gpsSerial.read();
    Serial.print(c); // Print raw GPS data in Serial Monitor
     }
   }