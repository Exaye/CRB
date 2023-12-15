#include <Servo.h>                           // Include servo library

const int pingPin = 12;
Servo servoLeft;
Servo servoRight;

void setup() {
  Serial.begin(9600);

  /*On lie les servo :
  / Droite assigné à la pin 10
  / Gauche assigné à la pin 11
  */
  servoLeft.attach(11);
  servoRight.attach(10);

  //On imopse les vitesses initiales à l'arrêt
  servoLeft.writeMicroseconds(1475); 
}

void loop() {

  long duration, cm;

  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);

  cm = microsecondsToCentimeters(duration);

  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  if(cm<=10) Speed(servoLeft, -1, 3); Speed(servoRight, 1, 3);
  if(cm>10 && cm <=15) Speed(servoLeft, -1, 2); Speed(servoRight, 1, 2);
  if(cm>15 && cm <=20) Speed(servoLeft, -1, 1); Speed(servoRight, 1, 1);
  if(cm>20 && cm <=25) Speed(servoLeft, 0, 0); Speed(servoRight, 0, 0);
  if(cm>25 && cm <=30) Speed(servoLeft, 1, 1); Speed(servoRight, -1, 1);
  if(cm>30 && cm <=35) Speed(servoLeft, 1, 2); Speed(servoRight, -1, 2);
  if(cm>40) Speed(servoLeft, 1, 3); Speed(servoRight, -1, 3);

  delay(100);

}

long microsecondsToCentimeters(long microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the object we
  // take half of the distance travelled.
  return microseconds / 29 / 2;
}
