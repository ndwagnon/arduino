/*
 *    This program teaches us how to use the piezo as an analog input device,
 * while also giving us more experience using the servo and its library.
 * It uses a red light and servo position of 90 to indicate "locked" status.
 * It also uses a green light and a servo position of 0 to indicate "unlocked" status.
 * When locked, the user can knock directly on the piezo (or any vibrating material
 * around it) and if the knock is acceptable, the yellow light will flash and 
 * the serial monitor will tell you how many more knocks you have to go until it is 
 * unlocked. This can be combined with a simple box to create a real use for the program.
 * 
 * NOTE: The global int variables "quietKnock", "loudKnock", and "minValue" will likely
 * need to be updated for each user. This is because the piezo may or may not pick up
 * the noise created by the servo, which can alter the analog values outputted by the 
 * piezo. I recommend using the serial monitor to check values and determine appropriate 
 * values for these variables. 
 * 
 * Author: Noah Wagnon
 * Date created: 15 May 2019
 * Date last modified: 17 May 2019
 * 
 */

#include <Servo.h>

Servo myServo;

const int piezo = A0; //location of piezo analog
const int switchPin = 2; //location of switch

//locations of led pins
const int yellowLed = 3;
const int greenLed = 4;
const int redLed = 5;

int knockVal, switchVal; //to be read throughout the loop

const int quietKnock = 185; //can be changed
const int loudKnock = 1000; //can be changed
const int minValue = 150; //can be changed

boolean locked = false; //status of lock. starts unlocked
int numberOfKnocks = 0; //keeps track of number of knocks



void setup() {
  myServo.attach(9);

  //declare proper inputs and outputs
  pinMode(yellowLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(switchPin, INPUT);

  //begin unlocked
  Serial.begin(9600);
  digitalWrite(greenLed, HIGH);
  myServo.write(0);
  Serial.println("The box is unlocked!");
  
}

void loop() {
  if (locked == false){
    switchVal = digitalRead(switchPin);
    
    //lock the box if the switch is pressed
    if (switchVal == HIGH){
      locked = true;
      if (numberOfKnocks >= 3){ //reset lock count if necessary
        numberOfKnocks = 0;
      }
      digitalWrite(greenLed, LOW);
      digitalWrite(redLed, HIGH);
      myServo.write(90);
      Serial.println("The box is locked!");
      delay(1000);
    }
  }
  if (locked == true){
    knockVal = analogRead(piezo);
    if (numberOfKnocks < 3 && knockVal > minValue){
      if (checkForKnock(knockVal) == true){ //registers a valid knock
        numberOfKnocks++;
      }
      Serial.print(3 - numberOfKnocks);
      Serial.println(" more knocks to go");
    }
    if (numberOfKnocks >= 3){ //unlocks the box since the required number of knocks has been met
      locked = false;
      myServo.write(0);
      delay(20);
      digitalWrite(greenLed, HIGH);
      digitalWrite(redLed, LOW);
      Serial.println("The box is unlocked!");
    }
  }
}

//function that returns either true or false, depending on whether the knock was acceptable
boolean checkForKnock(int value){
  if (value > quietKnock && value < loudKnock){
    digitalWrite(yellowLed, HIGH);
    delay(50);
    digitalWrite(yellowLed, LOW);
    Serial.print("Valid knock of value ");
    Serial.println(value);
    return true;
  }
  else{ // knock was either too soft or too loud
    Serial.print("Bad knock value ");
    Serial.println(value);
    return false;
  }
}
