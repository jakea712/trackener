
#include <Wire.h>
#include <Arduino.h>

#include <HTS221.h>
#include <VL6180.h>

// the setup function runs once when you press reset or power the board
void setup() {
  smeHumidity.begin();
  smeAmbient.begin();
  
  SerialUSB.begin(115200);

  pinMode(A0,INPUT);
  pinMode(A1,INPUT);

}

// the loop function runs over and over again forever
void loop() 
{
  SerialUSB.print(analogRead(A0));
  SerialUSB.print(" ");
  SerialUSB.print(smeHumidity.readHumidity());
  SerialUSB.print(" ");
  SerialUSB.print(smeHumidity.readTemperature());
  SerialUSB.print(" ");
  SerialUSB.print(smeAmbient.ligthPollingRead());
  SerialUSB.print(" ");
  SerialUSB.println(analogRead(A1));
  delay(5);
}
