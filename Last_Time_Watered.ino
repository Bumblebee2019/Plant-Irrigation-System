#include <LiquidCrystal.h>
LiquidCrystal lcd(1, 2, 4, 5, 6, 7);

unsigned long seconds;
unsigned long minutes;
int hours;
int days;

int Pin1 = A0;
float sensor_1_val = 0;
int low_moisture = 488;
int high_moisture = 183;
int percent = 0;

void setup(){
  lcd.begin(16,2);
  pinMode(Pin1, INPUT);
  delay(500);
}
void loop (){
  if (millis() % 1000 == 0) {
     seconds = seconds + 1;
     if (seconds == 60){
        seconds = 0;
        minutes = minutes + 1;
     }
     if (minutes == 60){
        minutes = 0;
        hours = hours + 1;
     }
     if (hours == 24){
        days = 1;
        seconds = 0;
        //hours = 0;
        minutes = 0;
     }
     else if (hours == 48){
        days = 2;
        seconds = 0;
        hours = 0;
        minutes = 0;
     }
     else if (hours == 72){
        days = 3;
        seconds = 0;
        hours = 0;
        minutes = 0;
     }
     else if (hours == 96){
        days = 4;
        seconds = 0;
        hours = 0;
        minutes = 0;
     }
     else if (hours == 120){
        days = 5;
        seconds = 0;
        hours = 0;
        minutes = 0;
     }
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("Last watered ");
  lcd.setCursor(2,1);
  lcd.print(days);
  lcd.print(" days ago");
  }
} 
