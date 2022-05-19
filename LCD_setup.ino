/*
 * Output on LCD: "Moisture: <percent>%"
 */

#include <LiquidCrystal.h>
LiquidCrystal lcd(1, 2, 4, 5, 6, 7);

//initializing connection between relay and Arduino
//int IN1 = 5;

//initiliazing connection between the moisture sensor and Arduino
int Pin1 = A0;
float sensor_1_val = 0;
int low_moisture = 488;
int high_moisture = 183;
int percent = 0;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  //pinMode(IN1, OUTPUT);
  pinMode(Pin1, INPUT);
  //digitalWrite(IN1, HIGH);
  delay(500);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensor_1_val = analogRead(Pin1);
  lcd.setCursor(0,0);
  //lcd.print(sensor_1_val);
  //we want to map the current moisture somewhere between the low_moisture and the high_moisture, them being 0% and 100%, respectively.
  percent = map(sensor_1_val, low_moisture, high_moisture, 0, 100);
  //it's important to call lcd.clear() before writing anything onto the screen
  lcd.clear();
  lcd.print("Moisture: ");
  lcd.print(percent);
  lcd.print("%");
  delay(500);
}
