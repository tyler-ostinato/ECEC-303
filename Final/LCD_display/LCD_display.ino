// From slides

#include <LiquidCrystal.h>
#include <stdlib.h>

char test[10];

LiquidCrystal lcd(2,3,8,9,10,12);

void setup() {
  // put your setup code here, to run once:
  pinMode(26,OUTPUT);
  analogWrite(26,120);
  lcd.begin(16,2);
}

void loop() {
  // put your main code here, to run repeatedly:

  for(int i=0; i<10; i++){
    lcd.setCursor(0,0);
    lcd.print("Speed: ");
    lcd.setCursor(6,0);
    lcd.print(i);
    delay(1000);
  }
}
