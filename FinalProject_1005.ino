/*
  NOTES TO FREQUENCIES BEING USED:
       NOTE_A =  971
       NOTE_A2 = 591
       NOTE_D =  642 (155 DELAY)
       NOTE_D2 = 642 (385 DELAY)
       NOTE_E =  690
       NOTE_G =  851

  THESE NOTES WILL PLAY A SEQUENCE OF THE SONG:
        THE HEALING SONG
  FROM THE VIDEO GAME: LEGEND OF ZELDA: MAJORA'S MASK

  THE KNOB IS BEING USEED TO TURN OFF THE SOUND AFTER THE LOOP IS COMPLETE
*/

const int analogInPin = A0;
int sensorValue = 0;

void setup() {//BEGIN SETUP
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
}//END SETUP

void loop() {//BEGIN LOOP
  sensorValue = analogRead(analogInPin);
  Serial.println(sensorValue);
  /*THIS STATEMENT WILL ALLOW THE USER TO EITHER LET THE TONES PLAY, OR COMPLETELY SHUT IT OFF 
  AFTER TURNING MORE THAN HALF WAY, AFTER THE LOOP IS COMPLETE*/
  
  if (sensorValue > 500) {
    playNotes();
  } else {
    digitalWrite(3, LOW); digitalWrite(4, LOW); digitalWrite(5, LOW); digitalWrite(6, LOW); digitalWrite(7, LOW);
    noTone(8);
  }
}//END LOOP
/*------------------------------NOTE FUNCTIONS----------------------------
  THESE ARE SEPARATE FUNCTIONS FOR PLAYING THE NOTE TONES*/
void playNotes() {//BEGIN PLAYNOTES
  NOTE_A();
  NOTE_G();
  NOTE_E();

  NOTE_A();
  NOTE_G();
  NOTE_E();

  NOTE_A();
  NOTE_G();

  NOTE_D();
  NOTE_A2();
  NOTE_D2();
}//END PLAYNOTES

/*EACH TONE/NOTE HAS A SPECIFIC FREQUENCY AND/OR DURATION*/
void NOTE_A() {//BEGIN NOTE A
  tone(8, 971, 3000);
  digitalWrite(3, HIGH); digitalWrite(4, LOW); digitalWrite(5, HIGH); digitalWrite(6, LOW); digitalWrite(7, HIGH);
  delay(500);  noTone(8); delay(120);
}//END NOTE A

void NOTE_G() {//BEGIN NOTE G
  tone(8, 851, 3000);
  digitalWrite(3, LOW); digitalWrite(4, HIGH); digitalWrite(5, LOW); digitalWrite(6, HIGH); digitalWrite(7, LOW);
  delay(500);  noTone(8); delay(120);
}//END NOTE G

void NOTE_E() {//BEGIN NOTE E
  tone(8, 690, 3000);
  digitalWrite(3, LOW); digitalWrite(4, LOW); digitalWrite(5, HIGH); digitalWrite(6, LOW); digitalWrite(7, LOW);
  delay(500);  noTone(8); delay(120);
}//END NOTE E

void NOTE_D() {//BEGIN NOTE D
  tone(8, 642, 4000);
  digitalWrite(3, HIGH); digitalWrite(4, LOW); digitalWrite(5, HIGH); digitalWrite(6, LOW); digitalWrite(7, LOW);
  delay(155);  noTone(8); delay(140);
}//END NOTE D

void NOTE_D2() {//BEGIN NOTE D2
  tone(8, 642, 4000);
  digitalWrite(3, HIGH); digitalWrite(4, HIGH); digitalWrite(5, HIGH); digitalWrite(6, HIGH); digitalWrite(7, HIGH);
  delay(385);  noTone(8); delay(140);
}//END NOTE D2

void NOTE_A2() {//BEGIN NOTE A2
  tone(8, 591, 4000);
  digitalWrite(3, LOW); digitalWrite(4, HIGH); digitalWrite(5, LOW); digitalWrite(6, HIGH); digitalWrite(7, LOW);
  delay(250);  noTone(8); delay(120);
}//END NOTE A2
