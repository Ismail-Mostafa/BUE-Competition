int sw1=3;
int sw2=4;
int sw3=5;
int sw4=6;
int sw5=7;
int x,y;
byte packet;
#define setbit(ADDRESS,BIT) (ADDRESS |= (1<<BIT))
#define clearbit(ADDRESS,BIT) (ADDRESS &= ~(1<<BIT))




void setup()
{
  pinMode(sw1,INPUT_PULLUP);
  pinMode(sw2,INPUT_PULLUP);
  pinMode(sw3,INPUT_PULLUP);
  pinMode(sw4,INPUT_PULLUP);
  pinMode(sw5,INPUT_PULLUP);
  Serial.begin(9600);
}

void loop()
{
  x=analogRead(0);
  y=analogRead(1);
  if(digitalRead(sw1)==LOW)
  {
   setbit(packet,0);
 
  }
  else
  {
   clearbit(packet,0); 
  }
   if(digitalRead(sw2)==LOW)
  {
   setbit(packet,1);
 
  }
  else
  {
   clearbit(packet,1); 
  }
  if(digitalRead(sw3)==LOW)
  {
   setbit(packet,2);
 
  }
  else
  {
   clearbit(packet,2); 
  }
  if(digitalRead(sw4)==LOW)
  {
   setbit(packet,3);
 
  }
  else
  {
   clearbit(packet,3); 
  }
   if(x<100)
  {
   setbit(packet,4);
 
  }
  else
  {
   clearbit(packet,4); 
  }
   if(x>800)
  {
   setbit(packet,5);
 
  }
  else
  {
   clearbit(packet,5); 
  }
   if(y<100)
  {
   setbit(packet,6);
 
  }
  else
  {
   clearbit(packet,6); 
  }
   if(y>800)
  {
   setbit(packet,7);
 
  }
  else
  {
   clearbit(packet,7); 
  }
 
 Serial.write(packet);
 //Serial.println(packet,BIN);
  delay(50);
 
 
  
  
  
}
