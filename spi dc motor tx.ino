//example code to work with spi dc motor firmware

#include <SPI.h>

void setup (void)
{
Serial.begin(9600);
delay(5000);
  digitalWrite(SS, HIGH);  // ensure SS stays high for now

  // Put SCK, MOSI, SS pins into output mode
  // also put SCK, MOSI into LOW state, and SS into HIGH state.
  // Then put SPI hardware into Master mode and turn SPI on
  SPI.begin ();

  // Slow down the master a bit
  SPI.setClockDivider(SPI_CLOCK_DIV8);
  
  
   char c;

  // enable Slave Select
  digitalWrite(SS, LOW);    

 
  for (const char * p = "$ motor 2 aclk 150 \n" ; c = *p; p++)
    SPI.transfer (c);

  // disable Slave Select
  digitalWrite(SS, HIGH);
  
  delay(5000);
  
  
  digitalWrite(SS, LOW);    

  
  for (const char * p = "$ motor 1 aclk 050 \n" ; c = *p; p++)
    SPI.transfer (c);

  // disable Slave Select
  digitalWrite(SS, HIGH);
  
  delay(5000);
 
    // enable Slave Select
  digitalWrite(SS, LOW);    

  // send test string
  for (const char * p = "$ stop b \n" ; c = *p; p++)
    SPI.transfer (c);

  // disable Slave Select
  digitalWrite(SS, HIGH);
  
  delay(3000);
  
  digitalWrite(SS, LOW);    

  // send test string
  for (const char * p = "$ motor 1 aclk 100 \n" ; c = *p; p++)
    SPI.transfer (c);

  // disable Slave Select
  digitalWrite(SS, HIGH);
  
  delay(5000);
  
  digitalWrite(SS, LOW);    

  // send test string
  for (const char * p = "$ motor 2 clck 050 \n" ; c = *p; p++)
    SPI.transfer (c);

  // disable Slave Select
  digitalWrite(SS, HIGH);
  
  delay(5000);
  
    // enable Slave Select
  digitalWrite(SS, LOW);    

  // send test string
  for (const char * p = "$ stop 1 \n" ; c = *p; p++)
    SPI.transfer (c);

  // disable Slave Select
  digitalWrite(SS, HIGH);
  
  delay(3000);
  
  digitalWrite(SS, LOW);    

  // send test string
  for (const char * p = "$ stop 2 \n" ; c = *p; p++)
    SPI.transfer (c);

  // disable Slave Select
  digitalWrite(SS, HIGH);
  
  digitalWrite(SS, LOW);    

  // send test string
  for (const char * p = "$ motor 1 clck 150 \n" ; c = *p; p++)
    SPI.transfer (c);

  // disable Slave Select
  digitalWrite(SS, HIGH);
  
  delay(5000);
  
  digitalWrite(SS, LOW);    

  // send test string
  for (const char * p = "$ motor 2 aclk 150 \n" ; c = *p; p++)
    SPI.transfer (c);

  // disable Slave Select
  digitalWrite(SS, HIGH);
  
  delay(5000);
  
  digitalWrite(SS, LOW);    

  // send test string
  for (const char * p = "$ stop b \n" ; c = *p; p++)
    SPI.transfer (c);

  // disable Slave Select
  digitalWrite(SS, HIGH);
  
  
}  // end of setup


void loop (void)
{
  delay (1000);  // 1 seconds delay 
}  // end of loop
