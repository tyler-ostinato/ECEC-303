// Website = https://www.programmingelectronics.com/an-easy-way-to-make-noise-with-arduino-using-tone/

const int buzzer = 9; //buzzer to arduino pin 9
int piezoPin = 9;

void setup(){
 
  pinMode(buzzer, OUTPUT); // Set buzzer - pin 9 as an output

}

void alarm_sound(){
  tone(piezoPin, 1000, 100);
  delay(250);
  tone(piezoPin, 1000, 100);
  delay(250);
  tone(piezoPin, 1000, 100);
  delay(250);
  tone(piezoPin, 1000, 100);
}

void accepted_sound(){
  tone(piezoPin, 5000, 250);
}

void loop(){
  alarm_sound();
  delay(2000);
  accepted_sound();
  delay(250);
  exit(0);
}
