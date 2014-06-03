//firmware that combines all the three protocols

#include <Wire.h>

#include <SPI.h>


char buf [26];
volatile byte pos;
volatile boolean process_it;

int dont=1,yes=0,inc=0;
char readf[26]={0};
int dummy=0,dumv=0;
int wmotor=0;//which motor
int motorpwm=0;
int aspwm=0;
volatile int yesdo=0;

void setup()
{
  Wire.begin(4);                // join i2c bus with address #4
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);           // start serial for output
  
  // have to send on master in, *slave out*
  pinMode(MISO, OUTPUT);
  
  // turn on SPI in slave mode
  SPCR |= _BV(SPE);
  
  // get ready for an interrupt 
  pos = 0;   // buffer empty
  process_it = false;

  // now turn on interrupts
  SPI.attachInterrupt();
  
  pinMode(3,OUTPUT);//load a
  pinMode(5,OUTPUT);//load a
  pinMode(6,OUTPUT);//load b
  pinMode(9,OUTPUT);//load b
  analogWrite(3,0);
  analogWrite(5,0);
  analogWrite(6,0);
  analogWrite(9,0);
}

// SPI interrupt routine
ISR (SPI_STC_vect)
{
byte c = SPDR;  // grab byte from SPI Data Register
  
  // add to buffer if room
  if (pos < sizeof buf)
    {
    buf [pos++] = c;
    
    // example: newline means time to process buffer
    if (c == '\n')
      process_it = true;
      
    }  // end of room available
}


void loop()
{
  if(Serial.available()>0)
    {
      readf[inc]=Serial.read();
      
      if(readf[0]=='$')
      dont=0;
    
      if(readf[inc]=='/')
      {
        dummy=inc;
      }
      
      dumv=inc-dummy;
      
      if(dumv==1)
      {
        if(readf[inc]=='n')
        {
          gopera();
          dont=1;
          for(inc=0;inc<21;inc++)
          readf[inc]='0';
          inc=0;
          dumv=0;
          dummy=0;
        }
      }
      
      if(dont==0)
      inc++;
    }
    
    if(yesdo==1)
  {
    gopera();
    for(inc=0;inc<26;inc++)
    readf[inc]='0';
    inc=0;
    yesdo=0;
  }
  
  if (process_it)
    {
    buf [pos] = 0;  
    Serial.println (buf);
    pos = 0;
    process_it = false;
    for(inc=0;inc<26;inc++)
    readf[inc]=buf[inc];
    gopera();
    }  // end of flag set
  
}

void receiveEvent(int howMany)
{
  while(1 < Wire.available()) // loop through all but the last
  {
    readf[inc] = Wire.read(); // receive byte as a character
    Serial.print(readf[inc]);
    inc++;    
  }
  
  int x = Wire.read();    // receive byte as an integer
  Serial.println();         // print the integer
   yesdo=1;
}

void gopera(void)
{
  for(inc=0;inc<26;inc++)
  Serial.print(readf[inc]); 
  Serial.println(" ");
  
  if((readf[2]=='M')||(readf[2]=='m'))
  motordrive();
  if((readf[2]=='s')||(readf[2]=='S'))
  haltmotor();
}

void motordrive(void)
{
  Serial.println("motor drive func");
  wmotor=readf[8]-48;
  Serial.println("the motor to be controlled");
  Serial.println(wmotor); 
  
  aspwm=readf[15]-48;
  motorpwm=aspwm*100;
  
  aspwm=readf[16]-48;
  motorpwm=motorpwm+(aspwm*10);
  
  aspwm=readf[17]-48;
  motorpwm=motorpwm+aspwm;
  
  if(motorpwm>255)
  motorpwm=0;
  
  Serial.println("pwm of motor");
  Serial.println(motorpwm);
  
  if((readf[10]=='a')||(readf[10]=='A'))
  amotor();
  
  if((readf[10]=='c')||(readf[10]=='C'))
  cmotor();
  
}

void amotor(void)//anti clock wise
{
  
  
  Serial.println("anti clock wise direction");
  Serial.println(wmotor); 
  Serial.println(motorpwm);
  if(wmotor==1)
  {
   analogWrite(5,motorpwm);
   analogWrite(3,0);
  }
  if(wmotor==2)
  {
   analogWrite(9,motorpwm);
   analogWrite(6,0);
  }
}

void cmotor(void)//clock wise
{
  
  
  Serial.println("clock wise direction");
  Serial.println(wmotor); 
  Serial.println(motorpwm);
  if(wmotor==1)
  {
   analogWrite(3,motorpwm);
   analogWrite(5,0);//load 1
  }
  if(wmotor==2)
  {
   analogWrite(6,motorpwm);
   analogWrite(9,0);//load 2
  }
}

void haltmotor(void)
{
  Serial.println("motor halt func");
  Serial.println("the motor to be stopped");
  
  if((readf[7]=='b')||(readf[7]=='B'))
  {
    Serial.println("both the motor to be stoped");
    analogWrite(3,0);
    analogWrite(5,0);
    analogWrite(6,0);
    analogWrite(9,0);
  }
  else
  {
    wmotor=readf[7]-48;
    Serial.println(wmotor); 
    if(wmotor==1)
    {
      analogWrite(3,0);
      analogWrite(5,0);
    }
    if(wmotor==2)
    {
      analogWrite(6,0);
      analogWrite(9,0);
    }
  }
  
  
}
