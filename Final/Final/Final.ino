// Init DC Motor
int dc_motor=4;
int motor_speed=0;
int motor_prcnt=0;

// Init Ultrasonic Sensor
long duration=0; // variable for the duration of sound wave travel
int distance=0; // variable for the distance measurement
#define echoPin 23 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 22 //attach pin D3 Arduino to pin Trig of HC-SR04

// Init Servo Motor
#include <Servo.h>
Servo servo;
int deg=0;
int servo_pin=6;

#include <dht.h>
dht DHT;
#define DHT11_PIN 30
int temp=0;

// Init Water Level Sensor
int water_level=0;

// Init RFID
#include <SPI.h>
#include <MFRC522.h>
 
#define SS_PIN 53
#define RST_PIN 7
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
int access_flag=0;

// Init IR Remote
// Changed timer in IRemote/src/private/IRTimer.hpp -> #define IR_USE_AVR_TIMER3   // send pin = pin 5
#include <IRremote.h>
#include <IRremoteInt.h>
IRrecv irrecv(42);
decode_results results;
long lastPressTime = 0;
int state = LOW;
int max_speed=255;
#define SEND_PWM_BY_TIMER=0

// Init Buzzer
const int buzzer = 5; //buzzer to arduino pin 9
int piezoPin = 5;

// Init LCD Display
#include <LiquidCrystal.h>
#include <stdlib.h>
LiquidCrystal lcd(2,3,8,9,10,12);

// Init Headlights
int led1 = 13;
int led2 = 11;
int headlight_status=0;


void accepted_sound(){
  tone(piezoPin, 5000, 250);
}

void alarm_sound(){
  tone(piezoPin, 1000, 100);
//  delay(250);
  tone(piezoPin, 1000, 100);
//  delay(250);
  tone(piezoPin, 1000, 100);
//  delay(250);
  tone(piezoPin, 1000, 100);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  // DC Motor setup
  pinMode(dc_motor, OUTPUT);  

  // Ultrasonic Sensor setup
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT

  // Servo Motor setup
  servo.attach(servo_pin);
  servo.write(0);

  // RFID setup
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522

  // IR Remote setup
  irrecv.enableIRIn(); // Start the receiver

  // Buzzer setup
  pinMode(buzzer, OUTPUT); // Set buzzer - pin 9 as an output

  // Setup LCD Display
  pinMode(26,OUTPUT);
  analogWrite(26,120);
  lcd.begin(16,2);

  // Headlights setup
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
}


void loop() {
  if(access_flag==0){ // change back to zero
    analogWrite(dc_motor,0);
    // Look for new cards
    if ( ! mfrc522.PICC_IsNewCardPresent()) 
    {
      return;
    }
    // Select one of the cards
    if ( ! mfrc522.PICC_ReadCardSerial()) 
    {
      return;
    }
    //Show UID on serial monitor
    String content= "";
    byte letter;
    for (byte i = 0; i < mfrc522.uid.size; i++) 
    {
       content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
       content.concat(String(mfrc522.uid.uidByte[i], HEX));
    }
    content.toUpperCase();
    if(content.substring(1) == "1C C6 0C 4A"){
      access_flag=1;
      accepted_sound();
    }
    else{
      access_flag=0;
      alarm_sound();
    }
  }

  if (access_flag==1){
    // Clears the trigPin condition
    digitalWrite(trigPin, LOW);
//    delayMicroseconds(2);
    // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
    digitalWrite(trigPin, HIGH);
//    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);
    // Calculating the distance
    distance = duration * 0.034 / 2;
  
  
    // Check temperature and water level
    int chk = DHT.read11(DHT11_PIN);
    water_level = analogRead(A0);
    temp = DHT.temperature;
    if(temp > 75 || water_level < 200){
      distance=0; 
      analogWrite(led1, 0);
      analogWrite(led2, 0);
      lcd.clear();
    }
    
    if(distance > 30){
      distance = 30;
    }

    // Check for motor speed change from remote
    if(irrecv.decode(&results)){
      if(results.value==16748655){
        max_speed+=25;
      }
      else if(results.value==16769055){
        max_speed-=25;
      }
      irrecv.resume();


      // Headlights logic
      if(results.value==16753245){
        analogWrite(led1, 255);
        analogWrite(led2, 255);
        headlight_status=2;
      }
      if(results.value==16769565){
        analogWrite(led1, 0);
        analogWrite(led2, 0);
        headlight_status=0;
      }
      if(results.value==16736925){
        analogWrite(led1, 50);
        analogWrite(led2, 50);
        headlight_status=1;
      }     
    }
    if(max_speed>255){max_speed=255;motor_prcnt=100;}
    if(max_speed<0){max_speed=0;motor_prcnt=0;}
    
    // Change motor speed based on 0-30cm distance
    motor_speed=map(distance,0,30,0,max_speed);
    motor_prcnt=map(motor_speed,0,255,0,100); // Still need to have LCD speed change in respect to the remote speed change-
    analogWrite(dc_motor,motor_speed);
  
    // Call the breaks
    servo.attach(servo_pin);
    if(distance < 11){
      servo.write(180);
    }
    else{
      servo.write(0);
    }

    // Serial Terminal to MATLAB
    Serial.print(distance);
    Serial.print(",");
    Serial.print(headlight_status);
    Serial.print(",");
    Serial.print(motor_prcnt);
    Serial.print(",");
    Serial.print(temp);
    Serial.print(",");
    Serial.print(water_level);
    Serial.println(",");
    
    // LCD Display Logic
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("S: %");
    lcd.setCursor(4,0);
    lcd.print(motor_prcnt);
    if(water_level < 200){
      lcd.setCursor(0,1);
      lcd.print("W: ");
      lcd.setCursor(3,1);
      lcd.print("LOW");
    }
    if(water_level > 200 && water_level < 350){
      lcd.setCursor(0,1);
      lcd.print("W: ");
      lcd.setCursor(3,1);
      lcd.print("MED");
    }
    if(water_level > 350){
      lcd.setCursor(0,1);
      lcd.print("W: ");
      lcd.setCursor(3,1);
      lcd.print("HIGH");
    }
    lcd.setCursor(9,1);
    lcd.print("T: ");
    lcd.setCursor(12,1);-
    lcd.print((int)DHT.temperature);
    delay(250);
  }
}
