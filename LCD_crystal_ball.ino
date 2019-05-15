/*
 *    This program teaches us the basics of the "LiquidCrystal" library. We also learned
 * how to combine these basics with the "random" function and the switch-case tool
 * to create a program that simulates a magic-8 ball. The circuitry makes use of a 
 * tilt switch to ultimately generate a random response. It also uses a potentiometer
 * to adjust the contrast on the LCD screen to make the characters readable. This 
 * makes the breadboard get fairly crowded, but luckily we have used all tools in this 
 * project before, besides the LCD itself. Our use of the tilt switch is fairly similar to 
 * our use of it in the digital hourglass project, making the code fairly similar; however,
 * all of the LCD functions are new in this project, so the code ended up looking fairly 
 * complex compared to our last projects. 
 * 
 * NOTE: The user may change the print statements within the switch/case branch.
 * You just need to keep in mind that the LCD allows 2 lines of 16 characters.
 * Also, if you add print statements, you need to update the call to the 
 * "random" function to allow for more possiblities. 
 *    
 *    
 * Author: Noah Wagnon
 * Date created: 15 May 2019
 * Date last modified: 15 May 2019
 * 
 */

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);//initialize and declare which pins we will use for the LCD
const int switchPin = 6; //location of tilt switch
int switchState = 0; //base condition of tilt switch
int prevSwitchState = 0;// base condition of prev tilt switch
int reply; //variable to determine reply. will be fed a random number

void setup() {
  lcd.begin(16, 2);
  pinMode(switchPin, INPUT);
  lcd.print("Ask the");
  lcd.setCursor(0, 1); //skip to next line
  lcd.print("Crystal Ball!");

}

void loop() {
  switchState = digitalRead(switchPin); //read the state of the tilt switch and enter the if statement if it differs from prev state
  
  if (switchState != prevSwitchState) {
    if (switchState == LOW){
      reply = random(8); //assigns to reply a randomly generated integer from 0-7.
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("The ball says: ");
      lcd.setCursor(0, 1); //skip to next line
      
      //switch/break statement to print the necessary output based on the value of reply
      switch(reply) {
        case 0:
        lcd.print("Yes");
        break;
        case 1:
        lcd.print("Most likely");
        break;
        case 2:
        lcd.print("Certainly");
        break;
        case 3:
        lcd.print("Outlook good");
        break;
        case 4:
        lcd.print("Unsure");
        break;
        case 5:
        lcd.print("Ask again");
        break;
        case 6:
        lcd.print("Doubtful");
        break;
        case 7:
        lcd.print("No");
        break;
      }
    }
  }
  prevSwitchState = switchState; //update the value of the previous switch state

}
