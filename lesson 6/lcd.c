#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);
  lcd.print("hello, world!");
}

void loop()
{
  Serial.begin(9600);
  if (Serial.available()>0)
  {lcd.setCursor(0, 0);
   lcd.print(Serial.readString());
  }
  
  
  
}