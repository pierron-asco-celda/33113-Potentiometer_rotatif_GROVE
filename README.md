# 33113-Potentiomètre rotatif GROVE

Potentiometer rotatif GROVE [33113](https://www.pierron.fr/interface-arduino-uno-5950.html)

<div style="text-align: justify">Module potentiomètre compatible Grove délivrant un signal analogique et équipé d'une résistance de 10 kΩ. Ce module se raccorde sur une entrée analogique du Base Shield via un câble 4 conducteurs.
Il est similaire au capteur d'angle Grove à l'exception du connecteur qui se trouve du côté opposé au potentiomètre.</div>

Caractéristiques techniques :
- Alimentation : 5 V
- Potentiomètre : 10 kΩ
- Rotation : 300°

![L-33113](/img/L-33113.jpg)

# Usage :
Pour l’utilisation de ce module référez-vous aux indications présentes sur le circuit imprimé GROVE.

# Schémas :

![SCH-33113](/img/SCH-33113.jpg)
![BRD-33113](/img/BRD-33113.jpg)

# Exemple :
### Arduino / C++
```cpp
/*
    ** Mesure Angle (0° à 300°) Potemtiometre module Grove **
       PIN A0 Module shield GROVE
       Baud rate 9600 -> Moniteur série*
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
  voltage = (float)sensor_value * ADC_REF / 1023; // cf. datasheet src
  float degrees = (voltage * FULL_ANGLE) / GROVE_VCC;
  return degrees;
}
```
## À propos :
<div style="text-align: justify">*Le débit en bauds est un taux de transfert de données en unités de bits par seconde (bps). Si le débit en bauds est de 9600, cela signifie que la possibilité d’envoyer des données est de 9600 bits en une seconde. 1 caractère est identique à 1 octet.</div>
<br>
PIERRON ASCO-CELDA (https://www.pierron.fr).
