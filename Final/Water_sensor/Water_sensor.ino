// Website = https://create.arduino.cc/projecthub/123lYT/simple-water-level-sensor-with-led-ebf3f7
int red=2;
int green=3;
int blue=4;

void setup () {
  pinMode (red,OUTPUT);
  pinMode (green,OUTPUT);
  pinMode (blue,OUTPUT);
  Serial.begin (9600);}
 
void loop() {
  // read the input on analog pin 0:
  int value = analogRead(A0);
  Serial.println(value);
  
  
  if (value > 300) {
    Serial.println("Very heavy Rain");
    digitalWrite(red,HIGH);
    digitalWrite(green,LOW);
    digitalWrite(blue,LOW);
    }
  else if ((value > 100) && (value <= 300)) {
    Serial.println("AVERAGE Rain");
    digitalWrite(green,LOW);
    digitalWrite(red,LOW);
    digitalWrite(blue,HIGH);
    
    }
  else if (value < 100){
    Serial.println("Dry Weather");
    digitalWrite(blue,LOW);
    digitalWrite(red,LOW);
    digitalWrite(green,HIGH);
  }
  delay(500);
}
