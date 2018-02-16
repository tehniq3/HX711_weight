/* sample for digital weight scale of hx711, display with a HD44780 liquid crtstal monitor
 *
 * hardware design: syyyd
 * available at http://syyyd.taobao.com
 *
 * library design: Weihong Guan (@aguegu)
 * http://aguegu.net
 *
 * library host on
 * https://github.com/aguegu/Arduino
 * small changes by Nicu FLORICA (niq_ro), Craiova, 16.2.2018
 */

// Hx711.DOUT - pin #A2
// Hx711.SCK - pin #A3

// LCD.RS - pin 12
// LCD.En - pin 11
// LCD.D4 - pin 5
// LCD.D5 - pin 4
// LCD.D6 - pin 3
// LCD.D7 - pin 2

#include <LiquidCrystal.h>
#include <hx711.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
Hx711 scale(A2, A3);

void setup() {

  lcd.begin(16, 2);

}

void loop() {

  lcd.setCursor(0, 0);
  lcd.print(scale.getGram(), 1);
  lcd.print(" g");
  lcd.print("       ");

  delay(200);
}
