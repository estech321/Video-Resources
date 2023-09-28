//Copyright Notice: Code from Anonymous User's comment from Krepak's tutorial Ultrasonic Security System on the Arduino Project Hub. 
//The comment begins by saying, "Code needs some slight amendments as below." 
//I have modified this code by changing the values of the variables to match the pinout diagram used in Krepak's tutorial. 
//This code is licensed under CC BY-SA 3.0.

//This program detects when an object is close to an ultrasonic sensor. 
//It buzzes when an object is very close, and lights the LEDs in different ways depending on the distance.
//This program is used in the following video: https://youtu.be/9YJtSkO6SYA
//Comments and code shared by esTech (https://youtube.com/@estech321)
//and on the website https://estech321.github.io 

#define trigPin 7
#define echoPin 6
#define LEDlampRed 9
#define LEDlampYellow 10
#define LEDlampGreen 11
#define soundbuzzer 3
int sound = 500;
void setup() {
Serial.begin (9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(LEDlampRed, OUTPUT);
pinMode(LEDlampYellow, OUTPUT);
pinMode(LEDlampGreen, OUTPUT);
pinMode(soundbuzzer, OUTPUT);
}

void loop() {
long durationindigit, distanceincm;
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
durationindigit = pulseIn(echoPin, HIGH);
distanceincm = (durationindigit/5) / 29.1;

if (distanceincm < 50) {
digitalWrite(LEDlampGreen, HIGH);
}

else {
digitalWrite(LEDlampGreen, LOW);
}

if (distanceincm < 20) {
digitalWrite(LEDlampYellow, HIGH);
}

else {

digitalWrite(LEDlampYellow,LOW);

}
if (distanceincm < 5) {
digitalWrite(LEDlampRed, HIGH);
sound = 1000;
}
else {
digitalWrite(LEDlampRed,LOW);
}

if (distanceincm > 5 || distanceincm <= 0){
Serial.println("Outside the permissible range of distances");
noTone(soundbuzzer);
}

else {
Serial.print(distanceincm);
Serial.println(" cm");
tone(soundbuzzer, sound);
}

delay(300);
}

