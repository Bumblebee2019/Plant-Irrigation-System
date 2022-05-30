/*
 * Output on LCD: "Moisture: <percent>%"
 */
//https://www.youtube.com/watch?v=AQIayZgeqq4
#include <LiquidCrystal.h>
#include <string.h>

LiquidCrystal lcd(1, 2, 4, 5, 6, 7);

//initializing connection between relay and Arduino
int IN1 = 13;
int IN2 = 12;

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
bool is_watered = false;
bool is_watered_2 = false;
bool is_first_tank_empty = false;
bool is_second_tank_empty = false;
int LED1 = 10;
int LED2 = 9;
int LED3 = 8;
int LED4 = 3;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  lcd.begin(16,2);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT); 
  pinMode(Pin1, INPUT);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
  delay(500);
} 
void last_time_watered() {
  display("Last watered ", 0, true);
  display(String((millis() - ms_since_pump_tunred_on - 3000)/1000) + " seconds ago", 1, false);
 
} 

void led_manager() {
  digitalWrite(LED1, HIGH);
  delay(100);
  digitalWrite(LED2, HIGH);
  delay(100);
  digitalWrite(LED3, HIGH);
  delay(100);
  digitalWrite(LED4, HIGH);
  delay(100);
  digitalWrite(LED1, LOW);
  delay(100);
  digitalWrite(LED2, LOW);
  delay(100);
  digitalWrite(LED3, LOW);
  delay(100);
  digitalWrite(LED4, LOW);
  delay(100);
}

void pump_manager() {
  display("                ", 1, true);
  sensor_1_val = analogRead(Pin1);
  if(sensor_1_val > 460) {  //if the soil is dry then we open the relay, if wet, close the relay
    if(is_first_tank_empty == true) { //if the tank is empty, there is no need to turn the pump on in vain
      digitalWrite(IN1, HIGH);
    }
    else {
       digitalWrite(IN1, LOW);
       is_watered = true;
       ms_since_pump_tunred_on = millis();
    }
    display("Test message", 0, true);
    delay(2000);
      //-----------check if water tank #1 is empty---------//
    if(is_watered && sensor_1_val > 460) {  //if the pump was working but the soil remained as dry as before
        if(is_second_tank_empty == true) {digitalWrite(IN2, HIGH);}
        else {
        digitalWrite(IN2, LOW);
        digitalWrite(IN1, HIGH);
        is_first_tank_empty = true;
        is_watered_2 = true;}
        display("  Moisture 2 ", 0, false);
        delay(2000);
        if (is_watered_2 && sensor_1_val > 460) { //if the second water tank is empty as well, we turn the water pump off
          digitalWrite(IN2, HIGH);
          is_second_tank_empty = true;
        }
    }
    else {
      digitalWrite(IN2, HIGH);
    }
  }
  else {
    digitalWrite(IN1, HIGH);
  }
  while (is_second_tank_empty && is_first_tank_empty) {
    tone(11, 1000, 500);
    led_manager();
    display("    WARNING", 0, true);
    led_manager();
    display("Both tanks empty", 1, false);
    led_manager();

    /*
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
   
    if(sensor_1_val < 460) {  //if water was added to the tank and soil was watered
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, HIGH);
      //break;
    }
    delay(3000);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, HIGH);*/
  }
}

void display(String message, int row, bool isClear){
   if(isClear){
    lcd.clear();   
   }
   lcd.setCursor(0,row);
   lcd.print(message);
}


void display_old() {
  /*
  //pump_manager();
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
  lcd.clear();*/
}
void loop() {
  pump_manager();
  delay(3000);
}
