#define IN1 4
#define IN2 5
#define IN3 6
#define IN4 7

#define LT 8
#define BT 9
int pinInterrupt = 2; //接中断信号的脚

int i;
void setup()
{
   pinMode(IN1,OUTPUT);
   pinMode(IN2,OUTPUT);
   pinMode(IN3,OUTPUT);
   pinMode(IN4,OUTPUT);
   pinMode( pinInterrupt, INPUT);//设置管脚为输入
   pinMode(LT,OUTPUT);
   pinMode(BT,OUTPUT);
   Serial.begin(9600);//打开串口
  
   digitalWrite(LT,HIGH);
   digitalWrite(BT,HIGH);
  
}
 
void loop()
{
  for(i=0;i<10;i++)
  { attachInterrupt( digitalPinToInterrupt(pinInterrupt), onChange, CHANGE);
   
    digitalWrite(IN1,i&0x1);
    digitalWrite(IN2,(i>>1)&0x1);
    digitalWrite(IN3,(i>>2)&0x1);
    digitalWrite(IN4,(i>>3)&0x1);
    delay(1000);
  } 
 
}
void onChange()
{  
  i=0;
  digitalWrite(IN1,i&0x1);
    digitalWrite(IN2,(i>>1)&0x1);
    digitalWrite(IN3,(i>>2)&0x1);
    digitalWrite(IN4,(i>>3)&0x1);
    delay(1000);
}