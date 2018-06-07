/* sample for digital weight scale of hx711
 * library design: Weihong Guan (@aguegu)
 * library host on
 *https://github.com/aguegu/ardulibs/tree/3cdb78f3727d9682f7fd22156604fc1e4edd75d1/hx711
 *adapted by Nicu FLORICA (niq_ro) for 200kg scale cell
 */

// Hx711.DOUT - pin #A2
// Hx711.SCK - pin #A3

#include <Hx711.h>
Hx711 scale(A2, A3);

float greutate = 0;
float tarare = 0; 
float corectie = 1.014541387;

void setup() {
  Serial.begin(9600);
  Serial.println(scale.averageValue());
}

void loop() {
  greutate = scale.getGram();
  greutate = greutate - tarare;
  greutate = greutate /10.;
  greutate = greutate / corectie;
  Serial.print(greutate, 1);
  Serial.println(" kg");
  delay(200);
}
