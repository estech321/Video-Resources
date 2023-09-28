//Copyright Attribution: Code from Cyragia's Instructables tutorial, Fading RGB LED (Arduino). 
//This version has not been modified from the original.
//This code is licenced under CC BY-NC-SA 4.0

//This program fades RGB LED lights different colors. 
//It is suitable for use with LED strips, SMDs or standard 5mms.
//This program is used in the following video: https://youtu.be/9YJtSkO6SYA
//Comments and code shared by esTech (youtube.com/@estech321)
//and on the website estech321.github.io

#define GREEN 3
#define BLUE 5
#define RED 6
#define delayTime 20

void setup() {

  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(RED, OUTPUT);
  digitalWrite(GREEN, HIGH);
  digitalWrite(BLUE, HIGH);
  digitalWrite(RED, HIGH);
}

int redVal;
int blueVal;
int greenVal;

void loop() {

  int redVal = 255;
  int blueVal = 0;
  int greenVal = 0;
  for( int i = 0 ; i < 255 ; i += 1 ){
	greenVal += 1;
	redVal -= 1;
	analogWrite( GREEN, 255 - greenVal );
	analogWrite( RED, 255 - redVal );

	delay( delayTime );
  }

  redVal = 0;
  blueVal = 0;
  greenVal = 255;
  for( int i = 0 ; i < 255 ; i += 1 ){
	blueVal += 1;
	greenVal -= 1;
	analogWrite( BLUE, 255 - blueVal );
	analogWrite( GREEN, 255 - greenVal );

	delay( delayTime );
  }

  redVal = 0;
  blueVal = 255;
  greenVal = 0;
  for( int i = 0 ; i < 255 ; i += 1 ){
	redVal += 1;
	blueVal -= 1;
	analogWrite( RED, 255 - redVal );
	analogWrite( BLUE, 255 - blueVal );

	delay( delayTime );
  }
}