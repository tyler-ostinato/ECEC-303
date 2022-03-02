const int VOL_PIN = A0;

void setup() {
  // put your setup code here, to run once:
  TCCR3A=0b10000010;
  TCCR3B=0b00010001; // Pre-scaler of 1
  ICR3=12500;
  OCR3A=625; // Duty cycle is 5%
  TCNT3=0;
  pinMode(5,OUTPUT);
  Serial.begin(9600);
}


void loop() {

    delay(2000);

    for(int i=1;i<=100;i++){
      
      // Increase duty cycle by 5%
      Serial.print("Duty cycle -> ");
      Serial.print(i);
      Serial.print("%");
      Serial.print("\n");


      long int sum_led=0;
      long int sum_photo=0;
      int loop_count=0;
      int div_count_led=0;
      int div_count_photo=0;
      
      while (loop_count < 100) {
        int analog_led = analogRead(A3);
        int analog_photo = analogRead(A0);
        if(analog_led!=0){
          sum_led += analog_led;
          div_count_led++;
        }
        if(analog_photo!=0){
          sum_photo += analog_photo;
          div_count_photo++;
        }
        loop_count++;
      }
  
      float voltage_of_led = (sum_led/div_count_led) * (5.0 / 1023.0);
      Serial.print("Voltage of R in LED circuit: ");
      Serial.print(voltage_of_led);
      Serial.print("\n");

      float voltage_of_photo = (sum_photo/div_count_photo) * (5.0 / 1023.0);
      Serial.print("Voltage of R in sensor circuit: ");
      Serial.print(voltage_of_photo);
      Serial.print("\n");
      
      delay(2000);

      OCR3A+=125; // Increase duty cycle by 1%
    }
    Serial.print("\n");

    Serial.print("\nDone.");
    delay(1000);
    exit(0);
  
//    delay(2500);
}
