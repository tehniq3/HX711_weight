/* sample for digital weight scale of hx711
 * library design: Weihong Guan (@aguegu)
 * library host on
 *https://github.com/aguegu/ardulibs/tree/3cdb78f3727d9682f7fd22156604fc1e4edd75d1/hx711
 *adapted by Nicu FLORICA (niq_ro) for 200kg scale cell

 LCD1602 circuit: // https://nicuflorica.blogspot.com/2013/01/arduino-si-un-afisaj-lcd-clasic-16.html
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
// Hx711.DOUT - pin #A2
// Hx711.SCK - pin #A3
*/

#include <hx711.h>
Hx711 scale(A2, A3);
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

float greutate = 0;
float tarare = 0; 
float corectie = 1.014541387;

void setup() {
  Serial.begin(9600);
  Serial.println(scale.averageValue());
lcd.begin(16, 2);
lcd.clear();
}

void loop() {
  greutate = scale.getGram();
  greutate = greutate - tarare;
  greutate = greutate /10.;
  greutate = greutate / corectie;
  Serial.print(greutate, 1);
  Serial.println(" kg");

 lcd.setCursor(5, 0);
 lcd.print("Weight:");

 lcd.setCursor(5, 1);
 if (greutate < 100.) 
    lcd.print(" ");
 if (greutate < 10.) 
    lcd.print(" ");
 lcd.print(greutate, 1); 
 lcd.print(" kg");
  delay(500);
}
