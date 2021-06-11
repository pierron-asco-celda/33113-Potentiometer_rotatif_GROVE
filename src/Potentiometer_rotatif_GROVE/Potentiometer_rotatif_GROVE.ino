/*
    ** Mesure Angle (0° à 300°) Potemtiometre module Grove **
       PIN A0 Module shield GROVE
       Baud rate 9600 -> Moniteur série
*/

#define ROTARY_ANGLE_SENSOR A0
#define ADC_REF 5
#define GROVE_VCC 5
#define FULL_ANGLE 300

void setup() {
  Serial.begin(9600);
  pinMode(ROTARY_ANGLE_SENSOR, INPUT);
}

void loop() {
  int degrees;
  degrees = getDegree();
  Serial.print("Angle Potentiometer(0° à 300°) : ");
  Serial.print(degrees);
  Serial.print("°");
  Serial.println();
  delay(500);
}

int getDegree() {
  int sensor_value = analogRead(ROTARY_ANGLE_SENSOR);
  float voltage;
  voltage = (float)sensor_value * ADC_REF / 1023;
  float degrees = (voltage * FULL_ANGLE) / GROVE_VCC;
  return degrees;
}
