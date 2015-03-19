#include<SoftwareSerial.h>

SoftwareSerial rfid1(10, 11);

int ip;

int count1=0, f1=0, e1=0;
char tag1, ip1;
char tmp1[20];
String id1;

int count2=0, f2=0, e2=0;
char tag2, ip2;
char tmp2[20];
String id2;

int count3=0, f3=0, e3=0;
char tag3, ip3;
char tmp3[20];
String id3;

void getbtdata()
{
  if(Serial1.available())
  {
   ip1=Serial1.read();
  }
}

void setup()
{
  rfid1.begin(9600);
  Serial2.begin(9600);
  Serial3.begin(9600);
  Serial1.begin(9600);
  pinMode(31,OUTPUT);
  pinMode(33,OUTPUT);
  pinMode(35,OUTPUT);
  pinMode(37,OUTPUT);
  pinMode(39,OUTPUT);
}

void rf1()
{
  if(rfid1.available())
  {
    e1=0;
    tag1=rfid1.read();
    tmp1[count1++]=tag1;
    f1++;
  }
   
  if(f1==12)
  {
    id1=String(tmp1)+":P1";
    Serial1.println(id1);
    f1=0;
    count1=0;
    e1=1;
  }
  
  if(ip=='Q'&&e1==1)
  {
    digitalWrite(35,HIGH);
  }
  if(ip=='W'&&e1==1)
  {
    digitalWrite(35,LOW);
  }
  
}

void rf2()
{
  
  if(Serial2.available())
  {
    e2=0;
    tag2=Serial2.read();
    tmp2[count2++]=tag2;
    f2++;
  }
   
  if(f2==12)
  {
    id2=String(tmp2)+":P2";
    Serial1.println(id2);
    f2=0;
    count2=0;
    e2=1;
  }
  if(ip=='E'&&e2==1)
  {
    digitalWrite(37,HIGH);
  }
  if(ip=='R'&&e2==1)
  {
    digitalWrite(37,LOW);
  }
}

void rf3()
{
  
  if(Serial3.available())
  {
    e3=0;
    tag3=Serial3.read();
    tmp3[count3++]=tag3;
    f3++;
  }
   
  if(f3==12)
  {
    id3=String(tmp3)+":P3";
    Serial1.println(id3);
    f3=0;
    count3=0;
    e3=1;
  }
  if(ip=='T'&&e3==1)
  {
    digitalWrite(39,HIGH);
  }
  if(ip=='Y'&&e3==1)
  {
    digitalWrite(39,LOW);
  }
}

void lnf()
{
  if(ip=='A')
    digitalWrite(31,HIGH);
  if(ip=='S')
    digitalWrite(31,LOW);
  if(ip=='D')
    digitalWrite(33,HIGH);
  if(ip=='F');
    digitalWrite(33,LOW);
}

void loop()
{
  getbtdata();
  lnf();
  rf1();
  rf2();
  rf3();
}
