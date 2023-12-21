#include <Servo.h>

//Pin du Sensor
const int pingPin = 12;

//Déclaration des variables globales
int dist;

//Déclaration des deux Servo
Servo servoLeft;
Servo servoRight;

void setup(){
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

void loop(){
  Scan();
  while(PusleDistance() > 100){
    Move(servoLeft, servoRight, 1, 1);

    //latence entre chaque execution de la loop
    delay(100);
  }
}


// Fonctions de repérage
void Scan(){
  int Dist[8];
  for(short i=0;i<=8;i++){
    Rotate(servoLeft, servoRight, 1, 100);
    Dist[i] = PusleDistance();
    delay(100);
  }
  Rotate(servoLeft, servoRight, -1, 8-MaxDistID(Dist));
  short Rslt = MaxDistID(Dist);
  //Serial.print("La distance la plus eloigne est ");
  Serial.println(Rslt);
}
int MaxDistID(int arr[8]) {
  int max = arr[0];
  short ind = 0;
  for (short i=0;i<=8;++i) {
    if (arr[i] > max) {
      max = arr[i];
      ind = i;
    }
  }
  return ind;
}

// Fonctions utiles pour les déplacements
void Speed(Servo servo, int Direction, int SpeedLevel){

  // Direction = 1 --> Horaire || Direction = -1 --> Anti-Horaire
  // SpeedLevel range from 0 to 4
  servo.writeMicroseconds(1475 + Direction*25*SpeedLevel);
}
void Move(Servo ServoLeft, Servo ServoRight, int Direction, int SpeedLevel){
  // Direction = 1 --> Avant || Direction = -1 --> Arrière
  Speed(ServoLeft, Direction*(-1), SpeedLevel);
  Speed(ServoRight, Direction*1, SpeedLevel);
}
void Rotate(Servo ServoLeft, Servo ServoRight, int Direction, int Time){

  Speed(ServoLeft, -1, 0);
  Speed(ServoRight, 1, 0);

  // Direction = 1 --> Sens Horaire || Direction = -1 --> Sens Anti-Horaire
  if(Direction == 1){
    Speed(ServoLeft, 1, 4);
    Speed(ServoRight, 1, 4);
    delay(Time);
  }
  if(Direction == -1){
    Speed(ServoLeft, -1, 4);
    Speed(ServoRight, -1, 4);
    delay(Time);
  }

  Speed(ServoLeft, -1, 0);
  Speed(ServoRight, 1, 0);

}

// Fonctions utiles pour le capteur
int PusleDistance(){
  //On définit les variable pour calculer la distance
  int duration, cm;

  //On pulse une onde et calcule la distance avant de l'afficher
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);

  cm = microsecondsToCentimeters(duration);

  /*Serial.print(cm);
  Serial.print("cm");
  Serial.println();*/
  return(cm);
}
int microsecondsToCentimeters(long microseconds) {
  // La vitesse du son est de 340 m/s ou 29 microseconds par centimètres.
  // Le ping effectuant un aller-retour,on prend la moitié de la disance.
  return microseconds / 29 / 2;
}