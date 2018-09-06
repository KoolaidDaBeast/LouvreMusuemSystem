const int SENSOR_1 = 6;
const int SENSOR_2 = 7;
const int SENSOR_3 = 8;
const int BUZZER = 2;

void triggerAlarm() {
  digitalWrite(BUZZER, HIGH);
}

void setup() {
  Serial.begin(9600);

  //Setting digital pins to input pins for the sensors
  pinMode(SENSOR_1, INPUT);
  pinMode(SENSOR_2, INPUT);
  pinMode(SENSOR_3, INPUT);
  pinMode(BUZZER, OUTPUT);

  //Set pin 5 as power source for the 3rd sensor
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  
  if(digitalRead(SENSOR_1) == HIGH)
  {
    //Set alaram
    triggerAlarm();
    Serial.println("RIGHT ACTIVE");
  }
  else if(digitalRead(SENSOR_2) == HIGH)
  {
    //Set alaram
    triggerAlarm(); 
     Serial.println("MIDDLE ACTIVE"); 
  }
  else if(digitalRead(SENSOR_3) == HIGH)
  {
    //Set alaram 
    triggerAlarm(); 
     Serial.println("LEFT ACTIVE");
  }
  else 
  {
    Serial.println("No Motion Detected");
    digitalWrite(BUZZER, LOW);
  }
}
