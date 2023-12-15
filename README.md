# Conception Robot Mobiles

## Objectifs de la repo
<div style="text-align: right">L'objectif de cette repo est de regrouper le code source de l'Arduino ainsi que les fichiers utiles à l'informatique.

L'avantage de GitHub est qu'il facilite le travail de groupe/collaboratif, à l'aide d'un répertoire partagé et d'un maintien à jour constant de la repo ainsi que la possibilité de versionner le travail et donc d'accéder aux anciennes versions rapidement.</div>

_Lien vers la  repo :_ https://github.com/Exaye/CRB

## Info utiles

### Salle
  1. Longueur de la porte : 90cm
  2. Angle optimal : 8°
  3. Longueur de la salle : 6.3m approximativement

### Librairie Servo
On utilise la librairie servo, native à Arduino. Cette dernière nous permet d'utiliser plus simplement les servo-moteurs du robot.

|      Plage      |      Write      |      Write(ms)     |
| --------------- | --------------- | -----------------  |
| Max Horaire     | 0               | 1575               |
| Arrêt           | 90              | 1475               |
| Max Anti-Horaire| 180             | 1375               |

## Objectifs
- [x] Avoir un programme de test pour chaque élément du robot
- [x] Prendre en main les librairies utilisées
- [ ] Créer une librairie pour faciliter le développement du programme (En cours...)
  - [ ] Pour  contrôler les déplacements du robot (En cours...)
  - [ ] Faciliter l'utilisation du capteur à ultrasons (En cours...)
- [x] Mettre en place un algorithme naïf pour que le robot sorte de la pièce
- [ ] Développer un programme suivant cet algorithme (En cours...)
- [ ] Mettre en place un algorithme plus avancé afin d'optimiser la vitesse de sortie
- [ ] Développer le programme suivant cet algorithme
