/* Test Platform test program
 *  Motors are 12V, 19:1 gear ratio and are similar to this one: https://www.pololu.com/product/3239
 *  Motor controllers are similar to this one: https://content.solarbotics.com/products/datasheets/solarbotics_l298_compact_motor_driver_kit.pdf
*/

#define LEFTMOTOR1 2 // I1
#define LEFTMOTOR2 3 // I2
#define RIGHTMOTOR1 4 // I3
#define RIGHTMOTOR2 5 // I4

void setup() {
  pinMode(LEFTMOTOR1, OUTPUT);
  pinMode(LEFTMOTOR2, OUTPUT);
  pinMode(RIGHTMOTOR1, OUTPUT);
  pinMode(RIGHTMOTOR2, OUTPUT);
  delay(5000);
}

void loop() {
  goBackward();
  delay(500);
  stopMotion();
  delay(1000);
  goLeft();
  delay(250);
  stopMotion();
  delay(1000);
}


void goForward(){
  digitalWrite(LEFTMOTOR1, LOW);
  digitalWrite(LEFTMOTOR2, HIGH);
  digitalWrite(RIGHTMOTOR1, LOW);
  digitalWrite(RIGHTMOTOR2, HIGH);

}

void goBackward(){
  digitalWrite(LEFTMOTOR1, HIGH);
  digitalWrite(LEFTMOTOR2, LOW);
  digitalWrite(RIGHTMOTOR1, HIGH);
  digitalWrite(RIGHTMOTOR2, LOW);
}

void goLeft(){
  digitalWrite(LEFTMOTOR1, LOW);
  digitalWrite(LEFTMOTOR2, HIGH);
  digitalWrite(RIGHTMOTOR1, HIGH);
  digitalWrite(RIGHTMOTOR2, LOW);
}

void goRight(){
  digitalWrite(LEFTMOTOR1, HIGH);
  digitalWrite(LEFTMOTOR2, LOW);
  digitalWrite(RIGHTMOTOR1, LOW);
  digitalWrite(RIGHTMOTOR2, HIGH);
}

void stopMotion(){
  digitalWrite(LEFTMOTOR1, LOW);
  digitalWrite(LEFTMOTOR2, LOW);
  digitalWrite(RIGHTMOTOR1, LOW);
  digitalWrite(RIGHTMOTOR2, LOW);
}

