#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <ESP32Servo.h>

#define TRIG 5
#define ECHO 32

#define RED_LED 26
#define GREEN_LED 27
#define BUZZER 25

#define BUTTON 33

#define SS_PIN 21
#define RST_PIN 4

#define SERVO_PIN 13

LiquidCrystal_I2C lcd(0x27,16,2);
Servo trackServo;

long duration;
float distance;

void setup(){

Serial.begin(115200);

pinMode(TRIG,OUTPUT);
pinMode(ECHO,INPUT);

pinMode(RED_LED,OUTPUT);
pinMode(GREEN_LED,OUTPUT);
pinMode(BUZZER,OUTPUT);

pinMode(BUTTON,INPUT_PULLUP);


lcd.init();
lcd.backlight();

trackServo.setPeriodHertz(50);
trackServo.attach(SERVO_PIN,500,2400);

trackServo.write(0);

lcd.setCursor(0,0);
lcd.print("SMART RAILWAY");
lcd.setCursor(0,1);
lcd.print("SYSTEM READY");

delay(3000);
lcd.clear();
}

void loop(){

checkTrack();

}


void checkTrack(){

digitalWrite(TRIG,LOW);
delayMicroseconds(2);

digitalWrite(TRIG,HIGH);
delayMicroseconds(10);

digitalWrite(TRIG,LOW);

duration = pulseIn(ECHO,HIGH);
distance = duration * 0.034 / 2;

Serial.print("Distance: ");
Serial.println(distance);

if(distance < 8){

Serial.println("CRACK DETECTED");

lcd.clear();
lcd.setCursor(0,0);
lcd.print("CRACK DETECTED");

digitalWrite(RED_LED,HIGH);
digitalWrite(GREEN_LED,LOW);

tone(BUZZER,1000);

delay(2000);

selfHealing();

}

else{

Serial.println("TRACK SAFE");

lcd.clear();
lcd.setCursor(0,0);
lcd.print("TRACK SAFE");

digitalWrite(GREEN_LED,HIGH);
digitalWrite(RED_LED,LOW);

noTone(BUZZER);

delay(1500);
}

}

void selfHealing(){

Serial.println("SELF HEALING MODE");

lcd.clear();
lcd.setCursor(0,0);
lcd.print("CHECK ALT TRACK");

delay(1500);

int altTrack = digitalRead(BUTTON);

if(altTrack == HIGH){   // Alternate track free

Serial.println("ALT TRACK FREE");

lcd.clear();
lcd.setCursor(0,0);
lcd.print("ALT TRACK FREE");
delay(1500);

// Ask authority permission

lcd.clear();
lcd.setCursor(0,0);
lcd.print("WAIT AUTHORITY");
lcd.setCursor(0,1);
lcd.print("10 SEC TIME");

Serial.println("Waiting for Authority Permission");

unsigned long startTime = millis();
bool permission = false;

// Wait for 10 seconds

while(millis() - startTime < 10000){

if(digitalRead(BUTTON) == LOW){   // Button pressed
permission = true;
break;
}

delay(50);
}

// If permission granted

if(permission){

Serial.println("PERMISSION GRANTED");

lcd.clear();
lcd.setCursor(0,0);
lcd.print("PERMISSION OK");

delay(1000);

// Switch track

trackServo.write(90);

lcd.clear();
lcd.setCursor(0,0);
lcd.print("TRACK SWITCHED");

// Stop buzzer and indicate safe path

noTone(BUZZER);
digitalWrite(RED_LED,LOW);
digitalWrite(GREEN_LED,HIGH);

delay(2000);

}

// If authority did not respond

else{

Serial.println("NO PERMISSION");

lcd.clear();
lcd.setCursor(0,0);
lcd.print("NO PERMISSION");
lcd.setCursor(0,1);
lcd.print("TRAIN STOPPED");

tone(BUZZER,1500);
digitalWrite(RED_LED,HIGH);
digitalWrite(GREEN_LED,LOW);

delay(3000);
}

}

else{

Serial.println("ALT TRACK BUSY");

lcd.clear();
lcd.setCursor(0,0);
lcd.print("ALT TRACK BUSY");
lcd.setCursor(0,1);
lcd.print("TRAIN STOPPED");

tone(BUZZER,1500);

digitalWrite(RED_LED,HIGH);
digitalWrite(GREEN_LED,LOW);

delay(3000);

}

}
