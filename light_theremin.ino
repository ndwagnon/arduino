/*
 *    This simple arduino project uses a phototransistor and a piezo to create sound. 
 * The user can vary the sound's pitch by altering the amount of light received by the
 * phototransistor. Some essential functions include "map" and "tone". 
 * 
 * Author: Noah Wagnon
 * Date created: 08 May 2019
 * Date last modified: 08 May 2019
 * 
 */

int sensorValue;  // create a variable used to store the analog readings
int sensorLow = 1023;  // low and high will be updated during calibration below
int sensorHigh = 0;
const int ledPin = 13; //LED pin will be on during calibration, off otherwise

//NOTE: these variables dictate max and min pitch played. Can be changed
int minPitch = 50; 
int maxPitch = 400;


//Setup is used for calibration
void setup() {

  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH); // Turn on LED to indicate calibration

  // while loop gives sensor 5 seconds to create a min and max reading
  while (millis() < 5000) {
    sensorValue = analogRead(A0);
    if (sensorValue > sensorHigh) sensorHigh = sensorValue;
    if (sensorValue < sensorLow) sensorLow = sensorValue;
  }

  digitalWrite(ledPin, LOW); //turn off LED to indicate calibration is finished

}

// loop goes forever and emits the appropriate sound;
void loop() {
  
  sensorValue = analogRead(A0);// read in the value from phototransistor

  //map function assigns sensor values to appropriate pitches
  int pitch = map(sensorValue, sensorLow, sensorHigh, minPitch, maxPitch); 
  
  tone(8, pitch, 20);//emits sound at "pitch" to pin 8 for 20 ms

  delay(10); //allow 10ms for 

}
