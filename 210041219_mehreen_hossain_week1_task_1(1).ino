#include <Wire.h> //library to handle I2C communication

char message[] = "Hello, this is a message from master to slave";
//message to send
int i=0;

void setup()
{
  Wire.begin(); //joining the bus as a controller
  Serial.begin(9600); //initializing the serial monitor
}

void loop()
{
  Wire.beginTransmission(9); //in order to transmit to the device with address 9
  Wire.write(message[i]);  //sends data serially
  Serial.print(message[i]);//prints to debug			 
  Wire.endTransmission();	 //ends the transmission
  
  if(i==45) i=0; //if the pointer reaches the end of the message, start again
  else i++;
  
  delay(1000); //delay before sending the next character
  
}