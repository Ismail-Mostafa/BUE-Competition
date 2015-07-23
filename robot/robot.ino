int m11=52;
int m12=50;
int m21=48;
int m22=46;
int m31=44;
int m32=42;
int m41=40;
int m42=38;
byte packet;
void setup()
{
pinMode(m11,OUTPUT);  
pinMode(m12,OUTPUT);
pinMode(m21,OUTPUT);
pinMode(m22,OUTPUT);
pinMode(m31,OUTPUT);
pinMode(m32,OUTPUT);
pinMode(m41,OUTPUT);
pinMode(m42,OUTPUT);
Serial3.begin(9600);
Serial.begin(9600);
}

void loop()
{
  
 if(Serial3.available())
{
 
 packet=Serial3.read();
 Serial.println(packet,BIN);
 if(packet&1==1)
 right();
 else if((packet&2)==2)
forward();
else if((packet&4)==4)
left();
else if((packet&8)==8)
backward();
else if((packet&0b00010000)==0b00010000)
{
rotate_r();  
  
}

else if((packet&0b00100000)==0b00100000)
{
rotate_l();  
  
}



else
stopm(); 

 
 
} 
  
  
  
  
  
}



void forward()
{
  digitalWrite(m11,1);
  digitalWrite(m12,0);
  // digitalWrite(m21,1);
 // digitalWrite(m22,0);
   digitalWrite(m31,0);
  digitalWrite(m32,1);
 //  digitalWrite(m41,0);
//  digitalWrite(m42,1);
}
void backward()
{
  digitalWrite(m11,0);
  digitalWrite(m12,1);
   //digitalWrite(m21,0);
//  digitalWrite(m22,1);
   digitalWrite(m31,1);
  digitalWrite(m32,0);
  // digitalWrite(m41,1);
  //digitalWrite(m42,0);
}

void right()
{
//  digitalWrite(m11,0);
//  digitalWrite(m12,1);
   digitalWrite(m21,1);
  digitalWrite(m22,0);
 //  digitalWrite(m31,0);
//  digitalWrite(m32,1);
   digitalWrite(m41,0);
  digitalWrite(m42,1);
}


void left()
{
// digitalWrite(m11,1);
//  digitalWrite(m12,0);
   digitalWrite(m21,0);
  digitalWrite(m22,1);
//  digitalWrite(m31,1);
 // digitalWrite(m32,0);
   digitalWrite(m41,1);
  digitalWrite(m42,0);
}

void rotate_r()
{

 digitalWrite(m11,1);
  digitalWrite(m12,0);
   digitalWrite(m21,1);
  digitalWrite(m22,0);
  digitalWrite(m31,1);
  digitalWrite(m32,0);
   digitalWrite(m41,1);
  digitalWrite(m42,0);  
  
  
  
}


void rotate_l()
{

 digitalWrite(m11,0);
  digitalWrite(m12,1);
   digitalWrite(m21,0);
  digitalWrite(m22,1);
  digitalWrite(m31,0);
  digitalWrite(m32,1);
   digitalWrite(m41,0);
  digitalWrite(m42,1);  
  
  
  
}
void stopm()
{
digitalWrite(m11,0);
  digitalWrite(m12,0);
   digitalWrite(m21,0);
  digitalWrite(m22,0);
   digitalWrite(m31,0);
  digitalWrite(m32,0);
   digitalWrite(m41,0);
  digitalWrite(m42,0);  
}
