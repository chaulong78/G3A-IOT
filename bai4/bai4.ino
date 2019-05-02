#include <LiquidCrystal.h>
#define warning 9
LiquidCrystal lcd(7,6,5,4,3,2);
int lm35 = A0;
void setup() {
  lcd.begin(16,2);
  pinMode(warning, OUTPUT);
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
  if(temp>30){
    digitalWrite(warning, HIGH);
  }
  delay(3000);
  
}
