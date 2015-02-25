#include<SoftwareSerial.h>

SoftwareSerial rfid(10,11);

int count=0, f=0, e=0;
char tag, ip;
char id[13], tmp[13];

void setup()
{
  rfid.begin(9600);
  Serial1.begin(9600);
  //Serial.begin(9600);
<<<<<<< HEAD:HEMSProg.ino
  pinMode(13,OUTPUT);
=======
  pinMode(12,OUTPUT);
>>>>>>> RelayFunc:HEMSProg.ino
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
    Serial1.println(id);
    f=0;
    count=0;
    Serial1.println("Press q/w to turn ON/OFF Device");
    e=1;
  }
  if(Serial1.available())
  {
   ip=Serial1.read();
   if(ip=='Q'&&e==1)
   {
     digitalWrite(12,HIGH);
   }
   if(ip=='W'&&e==1)
   {
     digitalWrite(12,LOW);
   }
  }
}  
