/*
 *    This project serves as an introduction to the "resistor ladder" technique. It simulates a piano keyboard of 4 notes
 *  by using 4 switches connected in parallel to analog. Varying the resistance associated with each switch will create a
 *  different analog input for each switch pressed (and combination of switches pressed). We can then use a piezo and an
 *  if-else tree to play a specified note for each different switch. The user is also given the freedom to choose which 
 *  notes he/she wants to be associated with each switch. Altering the global array "notes" will alter the notes played
 *  by the piezo using the "tone" function. 
 *  
 *    NOTE: Due to the slight variance between stated resistor values and actual resistance values, it may be necessary
 *    to alter the conditions of the if-else statement to make sure that each switch creates a note. We use the serial 
 *    log to help debug any possible errors with this. 
 *  
 *  
 *  
 *  Author: Noah Wagnon
 *  Date Created: 09 May 2019
 *  Date Last Modified: 09 May 2019 
 *  
 */


//NOTE: User may choose frequency values to choose notes. Link to frequency chart: https://newt.phys.unsw.edu.au/jw/notes.html
int notes[] = {262, 330, 392, 523}; 

void setup() {
  //Opens up a serial log to help with debugging and program monitoring.
  Serial.begin(9600);

}

void loop() {
  int keyVal = analogRead(A0); //int that hold the current analog value. Will be 0 if no switch is pressed, and will vary otherwise. 
  Serial.println(keyVal);

  //NOTE: The user may need to alter the if condition values, depending on his/her resistor accuracy. 
  if(keyVal <= 1023 && keyVal >= 1015) tone(8, notes[0]);
  else if (keyVal >= 990 && keyVal <= 1010) tone(8, notes[1]);
  else if (keyVal >= 505 && keyVal <= 515) tone(8, notes[2]);
  else if (keyVal >= 5 && keyVal <= 10) tone(8, notes[3]);
  else noTone(8); //play nothing

}
