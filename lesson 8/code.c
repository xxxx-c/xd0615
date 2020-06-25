/*
  Pitch follower

  Plays a pitch that changes based on a changing
  analog input//播放一个音调的变化，基于变化的模拟输入

  circuit:
  * 8-ohm speaker on digital pin 9//8欧的扬声器接入9脚
  * photoresistor on analog 0 to 5V//使用5V给光敏电阻供电
  * 4.7K resistor on analog 0 to ground//添加4.7K的电阻连接到地

  created 21 Jan 2010
  modified 31 May 2012  by Tom Igoe, with
  suggestion from Michael Flynn

  This example code is in the public domain.
  http://www.arduino.cc/en/Tutorial/Tone2
*/

int sensorReading = 0;//音调变量

void setup()
{
  pinMode(A0, INPUT);//设置A0为输管脚
  Serial.begin(9600);//打开串口

  pinMode(9, OUTPUT);//设置9脚为输出管脚
}

void loop()
{
  sensorReading = analogRead(A0);
  //读取引脚A0输入信号，将A0输入信号转换为0-1023之间的值
  Serial.println(sensorReading);
  // 通过串口监视器显示
  tone(9, 440 * pow(2.0, (constrain(int(map(sensorReading, 0, 1023, 36, 84)), 35, 127) - 57) / 12.0), 1000);
  delay(10); // 将A0输入信号转为为的值改变其范围，限制在35-127赫兹之间，在管脚9产生相应的的频率，并持续1000ms
}