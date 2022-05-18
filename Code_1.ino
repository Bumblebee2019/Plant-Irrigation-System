//initializing connection between relay and Arduino
int IN1 = 5;

//initiliazing connection between the moisture sensor and Arduino
int Pin1 = A0;
float sensor_1_val = 0;

void setup() {
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(Pin1, INPUT);
  digitalWrite(IN1, HIGH);
  delay(500);
}

void loop() {
  //More water in soil -> better conductivity -> lower resistance
  //Less water in soil -> worse conductivity -> higher resistance
  //---------------------Display--------------------------
  Serial.print("Moisture level of plant 1: ");
  sensor_1_val = analogRead(Pin1);
  Serial.print(sensor_1_val);
  Serial.print("\n");
  if (sensor_1_val > 460) {
    Serial.print("Soil is too dry; needs to be watered");
  }
  else {
    Serial.print("Soil is wet; does not to be watered");
  }
  Serial.print("\n");
  //---------------------Logic--------------------------
  if(sensor_1_val > 460) {  //if the soil is dry then we open the relay, if wet, close the relay
    digitalWrite(IN1, LOW);
  }
  else {
    digitalWrite(IN1, HIGH);
  }
  delay(5000);

}
