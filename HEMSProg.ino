#include<SoftwareSerial.h>

SoftwareSerial rfid(10,11);

int count=0, f=0, ask=0, flag2=0;
char tag, ip;
char id[13], tmp[13];

void setup()
{
  rfid.begin(9600);
  Serial1.begin(9600);
  Serial.begin(9600);
  pinMode(13,OUTPUT);
}

void readtag()
{
  tag=rfid.read();
  id[count++]=tag;
} 

void loop()
{
  if(rfid.available())
  {
    readtag();
    f++;
   }  
  if(f==12)
  {
    Serial1.write(id);
    f=0;
    count=0;
  }
}  
