/* 
 * LCD RS(4) to digital pin 12
 * LCD Enable(6) to digital pin 11
 * LCD D4(11) to digital pin 5
 * LCD D5(12) to digital pin 4
 * LCD D6(13) to digital pin 3
 * LCD D7(14) to digital pin 2
 * LCD R/W(5) to ground
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO(3)
 */

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("hola,mundo!");
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(millis()/1000);
}

