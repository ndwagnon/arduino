/*
 *   This program is designed to simulate an hourglass. The user can choose the time interval, but the program defaults to 10 mins with the variable "interval". 
 * There are 6 led lights, and once every 10 minutes another light will come on. When all 6 are on (meaning 60 minutes have passed) the lights start to light up 
 * in order to alert the user that an hour has passed. The most useful feature of the program makes use of the tilt switch. Whenver the user activates the 
 * switch (usually triggered by simple movements), the timer resets. The true functionality of this program is seen when paired with a 9V battery rather
 * than a computer. I personally use it so I can know how long I have been sitting down, so I can know when to stand up and stretch. 
 * 
 * Author: Noah Wagnon
 * Date Created: May 13 2019
 * Date Last Modified: May 14 2019
 * 
 */

const int switchPin = 8 //save place of the tilt switch
unsigned long previousTime = 0;//save previous time for keeping track of time passed

//variables used to update the program when tilt switch is activated
int switchState = 0;
int prevSwitchState = 0;

int led = 2;//will be incremented throughout the program to cycle through leds

const unsigned long interval = 600000;//NOTE: change this to alternate the intervals (600,000 for 10 mins)




void setup() {
  //Declare leds as outputs and tilt switch as input
  for (int i = 2; i < 8; ++i){
    pinMode(i, OUTPUT);
  }

  pinMode(switchPin, INPUT);

}

void loop() {
  //loops continuosly to check time and do appropriate action
  unsigned long currentTime = millis(); //grab current time
  
  if (currentTime - previousTime > interval){//if time interval has passed, enter this branch
    previousTime = currentTime;
    digitalWrite(led, HIGH);
    ++led;//increment to move on to next LED
  
  if (led == 8){//shows that all LEDs are on
    while (1){
      switchState  = digitalRead(switchPin);//We must keep reading switch pin to know when to restart
      if (switchState != prevSwitchState) break;
      
      //These two for loops create a flashy display to alert the user
    for (int i = 7; i > 1 ; --i){
      digitalWrite(i, LOW);
      delay(250);
    }
    for (int j = 2; j < 8; ++j){
      digitalWrite(j, HIGH);
      delay(250);
    }
  }
 }
  
}
switchState = 0;
switchState  = digitalRead(switchPin);
if (switchState != prevSwitchState){ //for loop used to reset the LEDS if the tilt switch is activated
  for (int x = 2; x < 8; ++x){
    digitalWrite(x, LOW);
  }
  led = 2;
  previousTime = currentTime;
}
prevSwitchState = switchState;//Lets the program know that the switch state has changed
  
  

}
