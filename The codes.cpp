#include <DS1307RTC.h>
#include <Time.h>
#include <Wire.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
byte heart[8] = {
  0b00000,
  0b01010,
  0b11111,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000
};

byte smiley[8] = {
  0b00000,
  0b00000,
  0b01010,
  0b00000,
  0b00000,
  0b10001,
  0b01110,
  0b00000
};

byte frownie[8] = {
  0b00000,
  0b00000,
  0b01010,
  0b00000,
  0b00000,
  0b00000,
  0b01110,
  0b10001
};

byte armsDown[8] = {
  0b00100,
  0b01010,
  0b00100,
  0b00100,
  0b01110,
  0b10101,
  0b00100,
  0b01010
};

byte armsUp[8] = {
  0b00100,
  0b01010,
  0b00100,
  0b10101,
  0b01110,
  0b00100,
  0b00100,
  0b01010
};
int 10 = mi;
int 8 = read;
void setup() 
{
pinMode(read,INPUT);
  // 创建一个新字符
  lcd.createChar(8, heart);
// 创建一个新字符
  lcd.createChar(1, smiley);
// 创建一个新字符
  lcd.createChar(2, frownie);
// 创建一个新字符
  lcd.createChar(3, armsDown);  
// 创建一个新字符
  lcd.createChar(4, armsUp);  
  // 设置LCD有几列几行，1602LCD为16列2行
  lcd.begin(16, 2);
  // 打印一段信息到LCD上
  lcd.ptint("Happy Birthday!");
// 设置光标在第二行，第五列
  lcd.setCursor(4, 1);
  // 小人手臂放下
  lcd.write(3);
  delay(delayTime);
  lcd.setCursor(4, 1);
  // 小人手臂抬起
  lcd.write(4);
  delay(3000);
  lcd.clear();
}

void loop() {
int read1 = digitalRead(read);
if （read1 == HIGH）
{
tone(mi,784,10);
delay(50);
tone(mi,784,10);
delay(125);
tone(mi,880,10);
delay(125);
tone(mi,784,10);
delay(125);
tone(mi,1046,10);
delay(125);
tone(mi,988,2000);
delay(125);
tone(mi,784,10);
delay(50);
tone(mi,784,10);
delay(125);
tone(mi,880,10);
delay(125);
tone(mi,1175,10);
delay(125);
tone(mi,1046,2000);
delay(125);
tone(mi,784,10);
delay(125);
tone(mi,784,10);
delay(125);
tone(mi,784,10);
delay(125);
tone(mi,1318,10);
delay(125);
tone(mi,1046,10);
delay(125);
tone(mi,988,10);
delay(40);
tone(mi,880,10);
delay(125);
tone(mi,1397,10);
delay(125);
tone(mi,1397,10);
delay(125);
tone(mi,1318,10);
delay(125);
tone(mi,1046,10);
delay(125);
tone(mi,1175,10);
delay(125);
tone(mi,1046,2000);
}
// 读A0引脚连接的电位器的值
  int sensorReading = analogRead(A0);
  // 将数据范围转换到 200 - 1000:
  int delayTime = map(sensorReading, 0, 1023, 200, 1000);
  // 设置光标在第二行，第五列
  lcd.setCursor(2, 1);
  // 小人手臂放下
  lcd.write(3);
  delay(delayTime);
  lcd.setCursor(4, 1);
  // 小人手臂抬起
  lcd.write(4);
  delay(delayTime); 
  tmElements_t tm;
  // 读出DS1307中的时间数据，并存入tm中
  if (RTC.read(tm)) 
  {
    // 清除屏幕显示内容
    lcd.clear();
    //在LCD第一行输出日期信息
    lcd.setCursor(0, 0);
    lcd.print(tmYearToCalendar(tm.Year));
    lcd.print("-");
    lcd.print(tm.Month);
    lcd.print("-");
    lcd.print(tm.Day);
    //在LCD第二行输出时间信息
    lcd.setCursor(8, 1);
    lcd.print(tm.Hour);
    lcd.print(":");
    lcd.print(tm.Minute);
    lcd.print(":");
    lcd.print(tm.Second);
  }
// 如果读取数据失败，则输出错误提示
else
  {
    lcd.setCursor(0, 1);
    lcd.print("error");
  }
  //每秒钟更新一次显示内容
  delay(1000);
}
