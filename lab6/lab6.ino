//const int forward=5;
//const int backward=7;
//int time_delay=3000;
//int val=0;
//int outval=0;
//char temp;
//String instr="Input Value: ";
//String outstr=", Output Value: ";
//String rotation="";
//
//void setup() {
//  // put your setup code here, to run once:
//  pinMode(forward,OUTPUT);
//  pinMode(backward,OUTPUT);
//  Serial.begin(9600);
//}
//
//void loop() {
//  // put your main code here, to run repeatedly:
//  if(Serial.available()>0){
//    val=Serial.parseInt();
//    temp=Serial.read();
//    outval=map(val,0,1023,-255,255);
//    if(outval>0){
//      rotation=", Going Forward";
//      analogWrite(backward,0);
//      analogWrite(forward,outval);
//    }
//    if(outval==0){
//      rotation=", Stopped";
//      analogWrite(backward,0);
//      analogWrite(forward,0);
//    }
//    if(outval<0){
//      rotation=", Going Backward";
//      analogWrite(forward,0);
//      analogWrite(backward,-outval);
//    }
//    Serial.println(instr+val+outstr+outval+rotation);
//  }
//}









// ---------------------------------------------------------------- //
// Arduino Ultrasoninc Sensor HC-SR04
// Re-writed by Arbi Abdul Jabbaar
// Using Arduino IDE 1.8.7
// Using HC-SR04 Module
// Tested on 17 September 2019
// https://create.arduino.cc/projecthub/abdularbi17/ultrasonic-sensor-hc-sr04-with-arduino-tutorial-327ff6
// ---------------------------------------------------------------- //

#define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3 //attach pin D3 Arduino to pin Trig of HC-SR04

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement
int motor_speed=0;
int led1=8;
int led2=9;
int led3=10;

const int forward=11;

void setup() {
//  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
//  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
//  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
//  Serial.println("with Arduino UNO R3");
//  pinMode(led1, OUTPUT);
//  pinMode(led2, OUTPUT);
//  pinMode(led3, OUTPUT);
  
  pinMode(forward,OUTPUT);
}
void loop() {
  // Clears the trigPin condition
//  digitalWrite(trigPin, LOW);
//  delayMicroseconds(2);
//  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
//  digitalWrite(trigPin, HIGH);
//  delayMicroseconds(10);
//  digitalWrite(trigPin, LOW);
//  // Reads the echoPin, returns the sound wave travel time in microseconds
//  duration = pulseIn(echoPin, HIGH);
//  // Calculating the distance
//  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
//  // Displays the distance on the Serial Monitor
//  Serial.print("Distance: ");
//  Serial.print(distance);
//  Serial.println(" cm");
//  delay(250);
//  if(distance > 30){
//    distance = 30;
//  }
//  // Change motor speed based on 0-30cm distance
//  motor_speed=map(distance,0,30,0,255);
//  analogWrite(forward,motor_speed);
//
//  // Set LEDs to change as ditance gets closer
//  if(distance < 10){
//    digitalWrite(led1, HIGH);
//    digitalWrite(led2, HIGH);
//    digitalWrite(led3, HIGH);
//  }
//  else if(distance > 10 && distance < 16){
//    digitalWrite(led1, HIGH);
//    digitalWrite(led2, HIGH);
//    digitalWrite(led3, LOW);
//  }
//  else if(distance > 16 && distance < 24){
//    digitalWrite(led1, HIGH);
//    digitalWrite(led2, LOW);
//    digitalWrite(led3, LOW);
//  }
//  else if (distance > 24){
//    digitalWrite(led1, LOW);
//    digitalWrite(led2, LOW);
//    digitalWrite(led3, LOW);
//  }
  analogWrite(forward,255);
}
