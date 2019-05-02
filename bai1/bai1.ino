#include <LiquidCrystal.h>
LiquidCrystal lcd(7,6,5,4,3,2);
String foods[]={" ","Com 15K","Bun 20K","Pho 20K"};
String drinks[]={" ","Coca 20K","Pepsi 15K","Lipton 10K"};
#define btnFood 13
#define btnDrink 12
#define btnChoose 11
int select[2]={0,0};
int i;
int flag=0;
void setup(){
  lcd.begin(16,2);
  pinMode(btnFood,INPUT);
  pinMode(btnDrink, INPUT);
  pinMode(btnChoose, INPUT);
}

void loop(){
  setFlag();
  if(flag==0){
    if(digitalRead(btnChoose)==LOW){
      if(select[0]==0 && select[1]==0){
        lcd.clear();
        lcd.print("Ban chua chon gi");
      }else{
        lcd.clear();
        lcd.print("ban da chon:");
        lcd.setCursor(0,1);
        lcd.print(foods[select[0]]);
        lcd.print(" ");
        lcd.print(drinks[select[1]]);
        select[0]=select[1]=0;
        delay(2000);
      }
      
    }else{
      lcd.clear();
      lcd.print("Moi ban chon nut");
    }
    delay(1000);
  }
  else if(flag==1){
    i=0;
    lcd.clear();
    lcd.print("Chon do an:");
    while(digitalRead(btnDrink)==HIGH && digitalRead(btnChoose)==HIGH){
      lcd.setCursor(0,1);
      clear();
      lcd.setCursor(0,1);
      lcd.print(foods[i]);
      delay(1000);
      if(digitalRead(btnFood)==LOW){
        if(i==3){
          i=0;
        }
        else{
          i++;
        }
      }
    }
    if(digitalRead(btnDrink)==LOW){
      flag==2;
    }
    if(digitalRead(btnChoose)==LOW){
      select[0]=i;
      flag=0;
      lcd.clear();
      lcd.print("Da chon");
      delay(1000);
    } 
  }
  else if(flag==2){
    i=0;
    lcd.clear();
    lcd.print("Chon do uong:");
    while(digitalRead(btnFood)==HIGH && digitalRead(btnChoose)==HIGH){
      lcd.setCursor(0,1);
      clear();
      lcd.setCursor(0,1);
      lcd.print(drinks[i]);
      delay(1000);
      if(digitalRead(btnDrink)==LOW){
        if(i==3){
          i=0;
        }
        else{
          i++;
        }
      }
    }
    if(digitalRead(btnFood)==LOW){
      flag==1;
    }
    if(digitalRead(btnChoose)==LOW){
      select[1]=i;
      flag=0;
      lcd.clear();
      lcd.print("Da chon");
      delay(1000);
    } 
  }
}
void setFlag(){
  if(digitalRead(btnFood)==LOW){
    flag=1;
  }else if(digitalRead(btnDrink)==LOW){
    flag=2;
  }
}
void clear(){
  lcd.print("                ");
}
