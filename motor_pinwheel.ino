/*
 *    This project teaches us about transistors, diodes, motors, how to integrate exterior power sources such as batteries
 *  and how to combine all of these to make a colorful display. We learned how transistors allow us to control current and
 *  voltage sources that are higher than those of the Arduino. We also learned how motors use induction to create
 *  rotational movement. We also learned how diodes protect a circuit against back voltage that is 
 *  created when the motor is slowing down. While these topics are completely new and relatively
 *  complex compared to the previous projects, luckily, the code and operation of the project
 *  are very simple. The code is almost identical to the program that made our first LED blink. 
 *  
 * Author: Noah Wagnon
 * Date created: 15 May 2019
 * Date last modified: 15 May 2019
 * 
 */

const int switchPin = 2; //location for switch
const int motorPin = 9; //location for motor
int switchState = 0;// base condition for switch


void setup() {
  //simply declare the appropriate inputs and outputs
  pinMode(motorPin, OUTPUT); //motor will be output, because it spins when we press the switch
  pinMode(switchPin, INPUT);//switch will be input, because its status controls the output
}

void loop() {
  //simply check the state of the switch and perform the appropriate action
  switchState = digitalRead(switchPin);

  if (switchState == HIGH) {
      digitalWrite(motorPin, HIGH);//switch is pressed, turn motor on
  } else{
    digitalWrite(motorPin, LOW);//switch is idle, leave motor off
  }

}
