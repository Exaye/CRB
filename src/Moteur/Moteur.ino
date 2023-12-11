/*
 Robotics with the BOE Shield – LeftServoClockwise
 Generate a servo full speed clockwise signal on digital pin 13.
 */

#include <Servo.h>                           // Include servo library

Servo servoLeft;

void setup()                                 // Built in initialization block
{
  servoLeft.attach(11);                      // Attach left signal to pin 13
  servoLeft.writeMicroseconds(1475); 
}  
 
void loop()                                  
{       
}