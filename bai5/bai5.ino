#include <LiquidCrystal.h>
LiquidCrystal lcd(7,6,5,4,3,2);
int led[4]={13,12,11,10};
int lm35 = A0;
void setup() {
  lcd.begin(16,2);
  for(int i=0; i<4; i++){
    pinMode(led[i],OUTPUT);
  }
  lcd.print("Nhiet do : ");
}

void loop() {
  int readLm35 = analogRead(lm35);
  float voltage = readLm35 * 5.0 / 1023;
  float temp = voltage * 100.0;
  Serial.print(temp);
  lcd.setCursor(0,1);
  lcd.print("                            ");
  lcd.setCursor(0,1);
  lcd.print(temp);
  digitalWrite(led[0],HIGH);
  if(temp>=20){
    digitalWrite(led[1],HIGH);
    if(temp>=30){
      digitalWrite(led[2],HIGH);
      if(temp>40){
        digitalWrite(led[3],HIGH);
      }
    }
  }
  delay(3000);
  
}
