/*
 * Output on LCD: "Moisture: <percent>%"
 */

#include <LiquidCrystal.h>
LiquidCrystal lcd(1, 2, 4, 5, 6, 7);

//initializing connection between relay and Arduino
int IN1 = 13;

//initiliazing connection between the moisture sensor and Arduino
unsigned long ms_since_pump_tunred_on = 0;
int Pin1 = A0;
float sensor_1_val = 0;
int low_moisture = 488;
int high_moisture = 183;
int percent = 0;
unsigned long seconds = 0;
unsigned long minutes = 0;
int hours = 0;
int days = 0;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  pinMode(IN1, OUTPUT);
  pinMode(Pin1, INPUT);
  digitalWrite(IN1, HIGH);
  delay(500);
} 
void last_time_watered() {
  //lcd.setCursor(1,0);
  //lcd.print("Seconds: ");
  //lcd.print(seconds);
  //if(millis() % 1000 == 0) {
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("Last watered ");
  lcd.setCursor(2,1);
  lcd.print((millis() - ms_since_pump_tunred_on - 3000)/1000);
  lcd.print(" seconds ago");
  //}
} 
void loop() {
  lcd.clear();
  //we will alternate between 2 LCD displays every 3 seconds
  // put your main code here, to run repeatedly:
  sensor_1_val = analogRead(Pin1);
  if(sensor_1_val > 460) {  //if the soil is dry then we open the relay, if wet, close the relay
    digitalWrite(IN1, LOW);
    ms_since_pump_tunred_on = millis();
  }
  else {
    digitalWrite(IN1, HIGH);
  }
  lcd.setCursor(0,0);
  //lcd.print(sensor_1_val);
  //we want to map the current moisture somewhere between the low_moisture and the high_moisture, them being 0% and 100%, respectively.
  percent = map(sensor_1_val, low_moisture, high_moisture, 0, 100);
  //it's important to call lcd.clear() before writing anything onto the screen
  lcd.clear();
  lcd.print("  Moisture: ");
  lcd.print(percent);
  lcd.print("%");
  delay(3000);
  lcd.clear();
  //===================Below put info from the Last_Time_Watered file========================//
  last_time_watered();
  delay(3000);
}
