#include <LiquidCrystal.h>

#define btnRIGHT 0
#define btnUP 1
#define btnDOWN 2
#define btnLEFT 3
#define btnSELECT 4
#define btnNONE 5
#define btnUNKNOWN 6

int readkeypad(){
      int adc_key_in = analogRead(0); //
      int ret = btnUNKNOWN;

      if (adc_key_in < 50) ret = btnRIGHT;
      if ((adc_key_in > 500) && (adc_key_in < 1150)) ret = btnNONE;
      if ( (adc_key_in > 120) && (adc_key_in < 150) ) ret = btnUP;
      if ( (adc_key_in > 250) && (adc_key_in < 350) ) ret = btnDOWN;
      if ( (adc_key_in > 450) && (adc_key_in < 500) ) ret = btnLEFT;
      if ( (adc_key_in > 700) && (adc_key_in < 750) ) ret = btnSELECT;

      return ret;
}


// Just for ease of displaying
const char *button[7] ={"Right ", "Up ", "Down ", "Left ", "Select ", " ", "??????"};

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

byte hours = 0;
byte minutes = 0;
byte secounds = 0; 
char line0[21]; 
char line1[21];

void setup() {
      lcd.begin(16, 2);      
}

void loop() {
      lcd.setCursor(0, 0);
      /*
      lcd.print("Button Pressed:");
      lcd.setCursor(0, 1);
      if (readkeypad()!=btnNONE) {
        lcd.print(button[readkeypad()]); 
      } else {
        lcd.print("                ");
      }

      if (readkeypad()==btnSELECT) {
        menu();
      }         
      */
      //lcd.printf("%03d:%03d:%03d", hours, minutes, secounds);
      //lcd.print(String(hours) + ":" + String(minutes) + ":" + String(secounds));
      delay(1000);
      
      updateClock();
      updateDisplay(); 
}

void menu() {
  const char *arrows[2] = {"<", ">"};
  const char *menuPosition[9] = {"SPEED",};
  delay(50);
  lcd.clear();
  do {
    lcd.setCursor(0, 0);
    lcd.print("POSITION 1");
    lcd.setCursor(0, 1);
    lcd.print("POSITION 2");
  } while(readkeypad()== btnSELECT);
}

void updateDisplay() {
   lcd.setCursor(0,0);
   lcd.print(line0);
   lcd.print(line1);
}

void updateClock() {
    secounds++;
    if (secounds==60) {
      secounds=00;
      minutes++;
    }
    if (minutes==60) {
      minutes=00;
      hours++;
    }
    if (hours==60) {
      hours=00;
    }
    sprintf(line0, "    %02d:%02d:%02d    ", hours, minutes, secounds);
}
