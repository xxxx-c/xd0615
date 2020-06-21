#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5

#define S1 8
#define S2 9
#define S3 10
#define S4 11

#define LT 7
#define BT 6
void setup()
{
  pinMode(IN1, OUTPUT);//输入1
  pinMode(IN2, OUTPUT);//输入2
  pinMode(IN3, OUTPUT);//输入3
  pinMode(IN4, OUTPUT);//输入4
  pinMode(S1, OUTPUT);//片选1
  pinMode(S2, OUTPUT);//片选2
  pinMode(S3, OUTPUT);//片选3
  pinMode(S4, OUTPUT);//片选4
  
  pinMode(LT,OUTPUT);//测试
  pinMode(BT,OUTPUT);//消隐
  
  Serial.begin(9600);
  
  digitalWrite(LT,HIGH);
  digitalWrite(BT,HIGH);
  
  digitalWrite(S1,HIGH);
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  digitalWrite(S4,HIGH);
}
byte income[4]={0};
void loop()
{
   int i;
   if(Serial.available()>0)
  {  for(i=0;i<4;i++)
      {income[i]=Serial.read();
       income[i]=income[i]-'0';}
  }
  
      digitalWrite(S1,LOW);
      digitalWrite(IN1,income[0]&0x1);
      digitalWrite(IN2,(income[0]>>1)&0x1);
      digitalWrite(IN3,(income[0]>>2)&0x1);
      digitalWrite(IN4,(income[0]>>3)&0x1);
  	  delay(10);
      digitalWrite(S1,HIGH);
     
    
      digitalWrite(S2,LOW);
      digitalWrite(IN1,income[1]&0x1);
      digitalWrite(IN2,(income[1]>>1)&0x1);
      digitalWrite(IN3,(income[1]>>2)&0x1);
      digitalWrite(IN4,(income[1]>>3)&0x1);
  	  delay(10);
      digitalWrite(S2,HIGH);
     
   
      digitalWrite(S3,LOW);
      digitalWrite(IN1,income[2]&0x1);
      digitalWrite(IN2,(income[2]>>1)&0x1);
      digitalWrite(IN3,(income[2]>>2)&0x1);
      digitalWrite(IN4,(income[2]>>3)&0x1);
  	  delay(10);
      digitalWrite(S3,HIGH);
     
 
      digitalWrite(S4,LOW);
      digitalWrite(IN1,income[3]&0x1);
      digitalWrite(IN2,(income[3]>>1)&0x1);
      digitalWrite(IN3,(income[3]>>2)&0x1);
      digitalWrite(IN4,(income[3]>>3)&0x1);
  	  delay(10);
      digitalWrite(S4,HIGH);
         
     
 
}