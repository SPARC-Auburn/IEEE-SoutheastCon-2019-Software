const int pinLeft = 5;
const int pinRight = 6;

void setup() {
  // initialize serial:
  Serial.begin(9600);
  // make the pins outputs:
  pinMode(pinLeft, OUTPUT);
  pinMode(pinRight, OUTPUT);
}

void loop() {
  // if there's any serial available, read it:
  analogWrite(pinLeft,127);
  analogWrite(pinRight,127);  
  while (Serial.available() > 0) {
    int dir1  = Serial.parseInt();
    int speed1  =  Serial.parseInt();
    int dir2  =  Serial.parseInt();
    int speed2  =  Serial.parseInt();
    if (dir1 == 0)
      dir1 = -1;
    if (dir2 == 0)
      dir2 = -1;
    analogWrite(pinLeft,speed1*dir1+127);
    analogWrite(pinRight,speed1*dir1+127);    
    Serial.flush();
  }
 }








