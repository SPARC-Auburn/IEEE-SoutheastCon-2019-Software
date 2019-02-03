const int pinLeft1 = 6;
const int pinLeft2 = 5;
const int pinRight2 = 10;
const int pinRight1 = 11;

void setup() {
  // initialize serial:
  Serial.begin(9600);
  // make the pins outputs:
  pinMode(pinLeft1, OUTPUT);
  pinMode(pinRight1, OUTPUT);
  pinMode(pinLeft2, OUTPUT);
  pinMode(pinRight2, OUTPUT);
}

void loop() {
  // if there's any serial available, read it:
  while (Serial.available() > 0) {
    int dir1  = Serial.parseInt();
    int speed1  =  Serial.parseInt();
    int dir2  =  Serial.parseInt();
    int speed2  =  Serial.parseInt();
    if (dir1 == 1){
      analogWrite(pinLeft2,speed1);
      digitalWrite(pinLeft1,LOW);
    }
    else {
      analogWrite(pinLeft1,speed1);
      digitalWrite(pinLeft2,LOW);
    }
    if (dir2 == 1){
      analogWrite(pinRight2,speed2);
      digitalWrite(pinRight1,LOW);
    }
    else {
      analogWrite(pinRight1,speed2);
      digitalWrite(pinRight2,LOW);
    }      
  }
 }








