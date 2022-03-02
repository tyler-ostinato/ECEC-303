// From Slides

#include <IRremote.h>
#include <IRremoteInt.h>
IRrecv irrecv(42);
decode_results results;
long lastPressTime = 0;
int state = LOW;
int motor_speed=255;
// Init DC Motor
int dc_motor=11;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  // DC Motor setup
  pinMode(dc_motor, OUTPUT); 
}
void loop() {
  while(!(irrecv.decode(&results)));
//    analogWrite(dc_motor,motor_speed);
  if(irrecv.decode(&results)){
    if(results.value==16748655){
      motor_speed+=25;
    }
    else if(results.value==16769055){
      motor_speed-=25;
    }
    Serial.println(motor_speed);
    irrecv.resume();
  }
  analogWrite(dc_motor,255);
}

// Cannot figure out why IR receiver breaks after one input. Test on someone elses board for less connections?

// RFID card is creating the issues with the IR Remote (conflicting timers)
