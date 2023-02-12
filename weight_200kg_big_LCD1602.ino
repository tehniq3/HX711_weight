/*
 * NOT TESTED YET !!! I wait feedback !
 * 
http://www.instructables.com/id/Custom-Large-Font-For-16x2-LCDs/?ALLSTEPS
A set of custom made large numbers for a 16x2 LCD using the 
 LiquidCrystal librabry. Works with displays compatible with the 
 Hitachi HD44780 driver. 
                                      -------------------
                                      |  LCD  | Arduino |
                                      -------------------
 LCD RS pin to digital pin 7          |  RS   |   D7    |
 LCD Enable pin to digital pin 6      |  E    |   D6    |
 LCD D4 pin to digital pin 5          |  D4   |   D5    |
 LCD D5 pin to digital pin 4          |  D5   |   D4    |
 LCD D6 pin to digital pin 3          |  D6   |   D3    |
 LCD D7 pin to digital pin 2          |  D7   |   D2    |
 LCD R/W pin to ground                |  R/W  |   GND   |
                                      -------------------
// http://arduino.cc/en/Reference/LiquidCrystalCreateChar
 Made by Michael Pilcher, 2/9/2010
 Original changed by Nicu FLORICA aka niq_ro (06-Jan-2014)
 https://www.arduinotehniq.com/
 http://arduinotehniq.blogspot.com/
 http://nicuflorica.blogspot.com
https://nicuflorica.blogspot.com/search/label/caractere%20mari

  */

// include the library
#include <LiquidCrystal.h>

// initialize the interface pins
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

#include <hx711.h>
Hx711 scale(A2, A3);

float greutate = 0;
float tarare = 0; 
float corectie = 1.014541387;
int intreg = 0;
int rest = 0;
  
int x = 0;
// the 8 arrays that form each segment of the custom numbers
byte LT[8] = 
{
  B00111,
  B01111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};
byte UB[8] =
{
  B11111,
  B11111,
  B11111,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};
byte RT[8] =
{
  B11100,
  B11110,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};
byte LL[8] =
{
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B01111,
  B00111
};
byte LB[8] =
{
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B11111,
  B11111,
  B11111
};
byte LR[8] =
{
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11110,
  B11100
};
byte UMB[8] =
{
  B11111,
  B11111,
  B11111,
  B00000,
  B00000,
  B00000,
  B11111,
  B11111
};
byte LMB[8] =
{
  B11111,
  B11111,
  B00000,
  B00000,
  B00000,
  B11111,
  B11111,
  B11111
};

// variables 
int t1, t2;
float t10, t20;
float t11, t21;
float t12, t22;



void setup()
{
  // assignes each segment a write number
  lcd.createChar(8,LT);
  lcd.createChar(1,UB);
  lcd.createChar(2,RT);
  lcd.createChar(3,LL);
  lcd.createChar(4,LB);
  lcd.createChar(5,LR);
  lcd.createChar(6,UMB);
  lcd.createChar(7,LMB);

  // sets the LCD's rows and colums:
  lcd.begin(0, 2);


  lcd.setCursor(2, 0);
  lcd.print("modified by");  
  lcd.setCursor(2, 1);
  lcd.print("Nicu FLORICA");
  delay (2500);
  lcd.clear();


 lcd.clear(); // clear the screen
 lcd.setCursor(0, 0); // put cursor at colon 2 and row 0 = left/up
 lcd.print("  200kg weight  "); // print a text
 lcd.setCursor(0, 1); // put cursor at colon 0 and row 0 = left/down
 lcd.print(" scale by niq_ro"); // print a text
 delay (2000);
 lcd.clear(); // clear the screen

 Serial.begin(9600);
 Serial.println(scale.averageValue());

}

void custom0O()
{ // uses segments to build the number 0
  lcd.setCursor(x, 0); 
  lcd.write(8);  
  lcd.write(1); 
  lcd.write(2);
  lcd.setCursor(x, 1); 
  lcd.write(3);  
  lcd.write(4);  
  lcd.write(5);
}

void custom1()
{
  lcd.setCursor(x,0);
  lcd.write(1);
  lcd.write(2);
  lcd.setCursor(x+1,1);
  lcd.write(255);
}

void custom2()
{
  lcd.setCursor(x,0);
  lcd.write(1);
  lcd.write(6);
  lcd.write(2);
  lcd.setCursor(x, 1);
  lcd.write(8);
  lcd.write(7);
  lcd.write(4);
}

void custom3()
{
  lcd.setCursor(x,0);
  lcd.write(6);
  lcd.write(6);
  lcd.write(2);
  lcd.setCursor(x, 1);
  lcd.write(7);
  lcd.write(7);
  lcd.write(5); 
}

void custom4()
{
  lcd.setCursor(x,0);
  lcd.write(8);
  lcd.write(4);
  lcd.write(255);
  lcd.setCursor(x, 1);
  lcd.write(1);
  lcd.write(1);
  lcd.write(255);
}

void custom5()
{
  lcd.setCursor(x,0);
  lcd.write(255);
  lcd.write(6);
  lcd.write(1);
  lcd.setCursor(x, 1);
  lcd.write(7);
  lcd.write(7);
  lcd.write(5);
}

void custom6()
{
  lcd.setCursor(x,0);
  lcd.write(8);
  lcd.write(6);
  lcd.write(6);
  lcd.setCursor(x, 1);
  lcd.write(3);
  lcd.write(7);
  lcd.write(5);
}

void custom7()
{
  lcd.setCursor(x,0);
  lcd.write(1);
  lcd.write(1);
  lcd.write(2);
  lcd.setCursor(x+1, 1);
  lcd.write(8);
}

void custom8()
{
  lcd.setCursor(x,0);
  lcd.write(8);
  lcd.write(6);
  lcd.write(2);
  lcd.setCursor(x, 1);
  lcd.write(3);
  lcd.write(7);
  lcd.write(5);
}

void custom9()
{
  lcd.setCursor(x,0);
  lcd.write(8);
  lcd.write(6);
  lcd.write(2);
  lcd.setCursor(x, 1);
  lcd.write(4);
  lcd.write(7);
  lcd.write(5);
}

void customA()
{
  lcd.setCursor(x,0);
  lcd.write(8);
  lcd.write(6);
  lcd.write(2);
  lcd.setCursor(x, 1);
  lcd.write(255);
  lcd.write(254);
  lcd.write(255);
}

void customB()
{
  lcd.setCursor(x,0);
  lcd.write(255);
  lcd.write(6);
  lcd.write(5);
  lcd.setCursor(x, 1);
  lcd.write(255);
  lcd.write(7);
  lcd.write(2);
}

void customC()
{
  lcd.setCursor(x,0);
  lcd.write(8);
  lcd.write(1);
  lcd.write(1);
  lcd.setCursor(x,1);
  lcd.write(3);
  lcd.write(4);
  lcd.write(4);
}

void customD()
{
  lcd.setCursor(x, 0); 
  lcd.write(255);  
  lcd.write(1); 
  lcd.write(2);
  lcd.setCursor(x, 1); 
  lcd.write(255);  
  lcd.write(4);  
  lcd.write(5);
}

void customE()
{
  lcd.setCursor(x,0);
  lcd.write(255);
  lcd.write(6);
  lcd.write(6);
  lcd.setCursor(x, 1);
  lcd.write(255);
  lcd.write(7);
  lcd.write(7); 
}

void customF()
{
  lcd.setCursor(x,0);
  lcd.write(255);
  lcd.write(6);
  lcd.write(6);
  lcd.setCursor(x, 1);
  lcd.write(255);
}

void customG()
{
  lcd.setCursor(x,0);
  lcd.write(8);
  lcd.write(1);
  lcd.write(1);
  lcd.setCursor(x,1);
  lcd.write(3);
  lcd.write(4);
  lcd.write(2);
}

void customH()
{
  lcd.setCursor(x,0);
  lcd.write(255);
  lcd.write(4);
  lcd.write(255);
  lcd.setCursor(x, 1);
  lcd.write(255);
  lcd.write(254);
  lcd.write(255); 
}

void customI()
{
  lcd.setCursor(x,0);
  lcd.write(1);
  lcd.write(255);
  lcd.write(1);
  lcd.setCursor(x,1);
  lcd.write(4);
  lcd.write(255);
  lcd.write(4);
}

void customJ()
{
  lcd.setCursor(x+2,0);
  lcd.write(255);
  lcd.setCursor(x,1);
  lcd.write(4);
  lcd.write(4);
  lcd.write(5);
}

void customK()
{
  lcd.setCursor(x,0);
  lcd.write(255);
  lcd.write(4);
  lcd.write(5);
  lcd.setCursor(x,1);
  lcd.write(255);
  lcd.write(254);
  lcd.write(2); 
}

void customL()
{
  lcd.setCursor(x,0);
  lcd.write(255);
  lcd.setCursor(x,1);
  lcd.write(255);
  lcd.write(4);
  lcd.write(4);
}

void customM()
{
  lcd.setCursor(x,0);
  lcd.write(8);
  lcd.write(3);
  lcd.write(5);
  lcd.write(2);
  lcd.setCursor(x,1);
  lcd.write(255);
  lcd.write(254);
  lcd.write(254);
  lcd.write(255);
}

void customN()
{
  lcd.setCursor(x,0);
  lcd.write(8);
  lcd.write(2);
  lcd.write(254);
  lcd.write(255);
  lcd.setCursor(x,1);
  lcd.write(255);
  lcd.write(254);
  lcd.write(3);
  lcd.write(5);
}

void customP()
{
  lcd.setCursor(x,0);
  lcd.write(255);
  lcd.write(6);
  lcd.write(2);
  lcd.setCursor(x, 1);
  lcd.write(255);
}

void customQ()
{
  lcd.setCursor(x,0);
  lcd.write(8);
  lcd.write(1);
  lcd.write(2);
  lcd.setCursor(x, 1);
  lcd.write(3);
  lcd.write(4);
  lcd.write(255);
  lcd.write(4);
}

void customR()
{
  lcd.setCursor(x,0);
  lcd.write(255);
  lcd.write(6);
  lcd.write(2);
  lcd.setCursor(x,1);
  lcd.write(255);
  lcd.write(254);
  lcd.write(2); 
}

void customS()
{
  lcd.setCursor(x,0);
  lcd.write(8);
  lcd.write(6);
  lcd.write(6);
  lcd.setCursor(x, 1);
  lcd.write(7);
  lcd.write(7);
  lcd.write(5);
}

void customT()
{
  lcd.setCursor(x,0);
  lcd.write(1);
  lcd.write(255);
  lcd.write(1);
  lcd.setCursor(x,1);
  lcd.write(254);
  lcd.write(255);
}

void customU()
{
  lcd.setCursor(x, 0); 
  lcd.write(255);  
  lcd.write(254); 
  lcd.write(255);
  lcd.setCursor(x, 1); 
  lcd.write(3);  
  lcd.write(4);  
  lcd.write(5);
}

void customV()
{
  lcd.setCursor(x, 0); 
  lcd.write(3);  
  lcd.write(254);
  lcd.write(254); 
  lcd.write(5);
  lcd.setCursor(x+1, 1); 
  lcd.write(2);  
  lcd.write(8);
}

void customW()
{
  lcd.setCursor(x,0);
  lcd.write(255);
  lcd.write(254);
  lcd.write(254);
  lcd.write(255);
  lcd.setCursor(x,1);
  lcd.write(3);
  lcd.write(8);
  lcd.write(2);
  lcd.write(5);
}

void customX()
{
  lcd.setCursor(x,0);
  lcd.write(3);
  lcd.write(4);
  lcd.write(5);
  lcd.setCursor(x,1);
  lcd.write(8);
  lcd.write(254);
  lcd.write(2); 
}

void customY()
{
  lcd.setCursor(x,0);
  lcd.write(3);
  lcd.write(4);
  lcd.write(5);
  lcd.setCursor(x+1,1);
  lcd.write(255);
}

void customZ()
{
  lcd.setCursor(x,0);
  lcd.write(1);
  lcd.write(6);
  lcd.write(5);
  lcd.setCursor(x, 1);
  lcd.write(8);
  lcd.write(7);
  lcd.write(4);
}

void customqm()
{
  lcd.setCursor(x,0);
  lcd.write(1);
  lcd.write(6);
  lcd.write(2);
  lcd.setCursor(x, 1);
  lcd.write(254);
  lcd.write(7);
}

void customsm()
{
  lcd.setCursor(x,0);
  lcd.write(255);
  lcd.setCursor(x, 1);
  lcd.write(7);
}

void customplus()  // made by niq_ro
{
  lcd.setCursor(x,0);
  lcd.write(4);
  lcd.write(255);
  lcd.write(4);
  lcd.setCursor(x, 1);
  lcd.write(1);
  lcd.write(255);
  lcd.write(1);
}

void customminus() // made by niq_ro
{
  lcd.setCursor(x,0);
  lcd.write(4);
  lcd.write(4);
  lcd.write(4);
  lcd.setCursor(x, 1);
  lcd.write(1);
  lcd.write(1);
  lcd.write(1);
}

void customgrad()
{
  lcd.setCursor(x,0);
  lcd.write(1);
  lcd.write(8);
  lcd.write(1);
  lcd.write(1);
  lcd.setCursor(x, 1);
  lcd.write(254);
  lcd.write(3);
  lcd.write(4);
  lcd.write(4);
}

void custom2puncte()
{
  lcd.setCursor(x,0);
  lcd.write(1);
  lcd.setCursor(x, 1);
  lcd.write(4);
  
}


// subrutina de afisare a numerelor
void afisare(int numar)
{
  switch (numar)
  {
    case 0:
    custom0O();
    break;

    case 1:
    custom1();
    break;

    case 2:
    custom2();
    break;

    case 3:
    custom3();
    break;

    case 4:
    custom4();
    break;

    case 5:
    custom5();
    break;

    case 6:
    custom6();
    break;

    case 7:
    custom7();
    break;

    case 8:
    custom8();
    break;

    case 9:
    custom9();
    break;
  }
}

void cantar(int t)
{
if (t>=10)
{
  x = 0;
  lcd.clear();
  customplus();
  
  x = x + 4;
  afisare(int(t/10));
  
  x = x + 4;
  afisare(t % 10);
  
  x = x + 4;
}
else
if (t<10)
{
x = 4;
  lcd.clear();
  customplus();
  
   x = x + 4;
  afisare(t);
  
  x = x + 4;
}

if (t==0)
{
  x = 8;
  lcd.clear();
  afisare(0);
  x = x + 4;  
}
}

void cantar2(int z)
{
   lcd.setCursor(12,0);
   lcd.print(z);
   lcd.setCursor(12,1);
   lcd.print("kg");
}

void loop()
{
  greutate = scale.getGram();
  greutate = greutate - tarare;
  greutate = greutate /10.;
  greutate = greutate / corectie;
  intreg = greutate/10.;
  rest = greutate - 10*intreg;
  Serial.print(greutate, 1);
  Serial.print(" --> ");
  Serial.print(intreg);
  Serial.print(",");
  Serial.print(rest);
  Serial.println(" kg ?");


// display int temperature  
lcd.clear();  
cantar(intreg);
cantar2(rest);

delay(1000);
}  // end of program


   
