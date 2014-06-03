//example code to use with serial dc motor firmware

void setup()
{
  Serial.begin(9600);
  delay(5000);
}

void loop()
{
   
  Serial.println("$ motor 1 aclk 100 /n");        
  delay(4000);
  
  Serial.println("$ motor 2 aclk 100 /n");        
  delay(4000);
   
  Serial.println("$ stop 1 /n ");        
  delay(4000);
  
  Serial.println("$ stop 2 /n ");        
  delay(4000);
  
  Serial.println("$ motor 1 cclk 100 /n");        
  delay(4000);
  
  Serial.println("$ motor 2 cclk 255 /n");        
  delay(4000);
  
   Serial.println("$ stop b /n ");        
  delay(4000);
  
}
