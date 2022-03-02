#include <Servo.h>

Servo servo;

int deg=0;
int servo_pin=4;

void setup() {
  // put your setup code here, to run once:
  servo.attach(servo_pin);
  servo.write(0);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(deg=0; deg<=180; deg++){
    servo.write(deg);
    delay(30);
  }
  for(deg=180; deg>=0; deg--){
    servo.write(deg);
    delay(30);
  }
}
