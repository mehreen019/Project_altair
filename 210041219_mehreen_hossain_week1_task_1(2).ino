#include <Wire.h>

char received_ = '#';

void setup()
{
  Serial.begin(9600);
  Wire.begin(9); //joins the I2C bus as slave on address 9
  Wire.onReceive(handler_); //if a transmission is received, the handler function is called
  
}

void handler_(int bytes){
  
   received_ = (char)Wire.read(); //reads the data from the transmission
  
}

void loop()
{
  Serial.print(received_);//printing the data to the serial monitor
  delay(1000);
}