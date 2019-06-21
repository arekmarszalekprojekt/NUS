#define X_STEP_PIN         54
#define X_DIR_PIN          55
#define X_ENABLE_PIN       38

#define Y_STEP_PIN         60
#define Y_DIR_PIN          61
#define Y_ENABLE_PIN       56

#define Z_STEP_PIN         46
#define Z_DIR_PIN          48
#define Z_ENABLE_PIN       62

// Limit Switches
//
#define X_MIN_PIN           3
#ifndef X_MAX_PIN
  #define X_MAX_PIN         2
#endif
#define Y_MIN_PIN          14
#define Y_MAX_PIN          15
#define Z_MIN_PIN          18
#define Z_MAX_PIN          19


int krok1,krok2,krok3;
String a;

int czy_mam_odp = 0; // flaga odpowiedz drukarki na sscanf

int krok=0;
int kierunek1 = 0;
int kierunek2 = 0;
int kierunek3 = 0;

void setup() {
 Serial.begin(115200);
 
 pinMode(X_ENABLE_PIN, OUTPUT);
 digitalWrite(X_ENABLE_PIN, LOW);
 pinMode(X_DIR_PIN, OUTPUT);
 digitalWrite(X_DIR_PIN, LOW);
 pinMode(X_STEP_PIN, OUTPUT);

 pinMode(Y_ENABLE_PIN, OUTPUT);
 digitalWrite(Y_ENABLE_PIN, LOW);
 pinMode(Y_DIR_PIN, OUTPUT);
 digitalWrite(Y_DIR_PIN, LOW);
 pinMode(Y_STEP_PIN, OUTPUT);

 pinMode(Z_ENABLE_PIN, OUTPUT);
 digitalWrite(Z_ENABLE_PIN, LOW);
 pinMode(Z_DIR_PIN, OUTPUT);
 digitalWrite(Z_DIR_PIN, LOW);
 pinMode(Z_STEP_PIN, OUTPUT);

 pinMode(X_MAX_PIN, INPUT_PULLUP);
 pinMode(Y_MAX_PIN, INPUT_PULLUP);
 pinMode(Z_MAX_PIN, INPUT_PULLUP);
 Serial.println("Dzien dobry podaj wartosci:a(wartosc),b(wartosc),c(wartosc) :D");
}

void loop() {

  krok++;
  
 /* *************JAZDA DRUKARKI GORA-DOL**********
  *  if (krok==500){
    krok=0;
    kierunek=!kierunek;
    digitalWrite(X_DIR_PIN, kierunek1);
    digitalWrite(Y_DIR_PIN, kierunek2);
    digitalWrite(Z_DIR_PIN, kierunek3);  
  } */

  if((kierunek1 == 1 || (kierunek1==0 && digitalRead(X_MAX_PIN)==0)) && krok1>0){

    digitalWrite(X_STEP_PIN, LOW);
    krok1--;
    
  }
  
  if((kierunek2 == 1 || (kierunek2==0 && digitalRead(Y_MAX_PIN)==0)) && krok2>0){
    
    digitalWrite(Y_STEP_PIN, LOW);
    krok2--;
    
  }
  if((kierunek3 == 1 || (kierunek3==0 && digitalRead(Z_MAX_PIN)==0)) && krok3>0){
    
    digitalWrite(Z_STEP_PIN, LOW);
    krok3--;
    
  }
  delay(1);
  digitalWrite(X_STEP_PIN, HIGH);
  digitalWrite(Y_STEP_PIN, HIGH);
  digitalWrite(Z_STEP_PIN, HIGH);
  delay(1);

  while (Serial.available()> 0)
  {
    a = Serial.readStringUntil('\n');

    sscanf(a.c_str(),"a %d b %d c %d ", &krok1, &krok2, &krok3);
    czy_mam_odp = 1;
    
    if( krok1 < 0 ){

      krok1 = -krok1;
      kierunek1 = 1;
      digitalWrite( X_DIR_PIN, kierunek1);
      
    }else 
    {
      kierunek1 = 0;
      digitalWrite( X_DIR_PIN, kierunek1);
    }

    if( krok2 < 0 ){

      krok2 = -krok2;
      kierunek2 = 1;
      digitalWrite( Y_DIR_PIN, kierunek2);
      
    }else 
    {
      kierunek2 = 0;
      digitalWrite( Y_DIR_PIN, kierunek2);
    }

    if( krok3 < 0 ){

      krok3 = -krok3;
      kierunek3 = 1;
      digitalWrite( Z_DIR_PIN, kierunek3);
      
    }else 
    {
      kierunek3 = 0;
      digitalWrite( Z_DIR_PIN, kierunek3);
    }
    
    Serial.print( krok1 );
    Serial.print( krok2 );
    Serial.print( krok3 );
  }

  if( krok1 == 0 && krok2 == 0 && krok3 == 0 && czy_mam_odp == 1 )
  {
    Serial.println("\n Prawidlowo");
    czy_mam_odp = 0;
  }

}

