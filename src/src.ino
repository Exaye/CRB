#include <Servo.h>                           // Include servo library

const int pingPin = 12;
Servo servoLeft;

void setup() {
  Serial.begin(9600);
  servoLeft.attach(11);                      // Attach left signal to pin 8
  servoLeft.writeMicroseconds(1475); 
}

void loop() {

  long duration, inches, cm;

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

  if(cm>50){
    servoLeft.writeMicroseconds(1800); 
  }
  if(cm<50){
    servoLeft.writeMicroseconds(1475); 
  }

  delay(100);

}

long microsecondsToCentimeters(long microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the object we
  // take half of the distance travelled.
  return microseconds / 29 / 2;
}
