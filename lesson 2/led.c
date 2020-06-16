int i;
void setup()
{
  for(i=0;i<8;i++)
  {
    pinMode(i, OUTPUT);
  }
  
}

void loop()
{
  for(i=0;i<4;i++)
  {digitalWrite(i, HIGH);
   delay(1000); 
   digitalWrite(i, LOW);
   delay(1000); 
   digitalWrite(7-i, HIGH);
   delay(1000); 
   digitalWrite(7-i, LOW);
   delay(1000); 
   
  }
  
}

