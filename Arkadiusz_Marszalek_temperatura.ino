#include <LiquidCrystal.h>
#define HEATER_0_PIN       10
#define TEMP_0_PIN         13  
#define TEMP_1_PIN         15  
#define TEMP_BED_PIN       14
#define a -5.350489030924815e-07
#define b 8.806656340109155e-04
#define c -0.579740749225015
#define d 2.441240183065808e+02

double x,y;
int p;
int i=0;
LiquidCrystal lcd(16,17,23,25,27,29);

void setup() {
pinMode(HEATER_0_PIN , OUTPUT);
lcd.begin(20,4);
}

void loop() {

  if(i<55){
  digitalWrite(HEATER_0_PIN, HIGH);
  i++;
  }
  else
  {
   digitalWrite(HEATER_0_PIN, LOW);
   delay(100);
   
  }
   lcd.print("\n temperatura:");
p= analogRead(TEMP_0_PIN );
x=(double)p;
y=a*x*x*x+b*x*x+c*x+d;
lcd.setCursor(0,0);
lcd.print(y);
delay(100);
}

