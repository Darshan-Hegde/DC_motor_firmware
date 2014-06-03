//example code to work with i2c dc motor firmware

#include <Wire.h>

void setup()
{
  Wire.begin(); // join i2c bus (address optional for master)
  
  
  Wire.beginTransmission(4); // transmit to device #4
  Wire.write("$ motor 1 aclk 100 /n ");        
  Wire.endTransmission();    // stop transmitting
  delay(4000);
   
  Wire.beginTransmission(4); // transmit to device #4
  Wire.write("$ stop b /n ");        
  Wire.endTransmission();    // stop transmitting
  delay(4000);
  
  Wire.beginTransmission(4); // transmit to device #4
  Wire.write("$ motor 2 cclk 100 /n ");        
  Wire.endTransmission();    // stop transmitting
  delay(4000);
  
    Wire.beginTransmission(4); // transmit to device #4
  Wire.write("$ stop b /n ");        
  Wire.endTransmission();    // stop transmitting
  delay(4000);
  
  Wire.beginTransmission(4); // transmit to device #4
  Wire.write("$ motor 1 cclk 100 /n ");        
  Wire.endTransmission();    // stop transmitting
  delay(4000);
  
  Wire.beginTransmission(4); // transmit to device #4
  Wire.write("$ stop 1 /n ");        
  Wire.endTransmission();    // stop transmitting
  delay(4000);
  
  Wire.beginTransmission(4); // transmit to device #4
  Wire.write("$ stop 2 /n ");        
  Wire.endTransmission();    // stop transmitting
  delay(4000);
  
}





void loop()
{
  
  
  
}
