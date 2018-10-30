
// pins for the LEDs:
const int pinCounter1 = 3;
const int pinD1 = 2;
const int pinD2 = 4;
const int pinCounter2 = 5;

void setup() {
  // initialize serial:
  Serial.begin(9600);
  // make the pins outputs:
  pinMode(pinCounter1, OUTPUT);
  pinMode(pinCounter2, OUTPUT);
  pinMode(pinD1, OUTPUT);
  pinMode(pinD2, OUTPUT);
}

void loop() {
  // if there's any serial available, read it:
  while (Serial.available() > 0) {

    int d1  = Serial.parseInt();
    int d2  = Serial.parseInt();
    int counter1  = Serial.parseInt();
    int counter2  = Serial.parseInt();
    if (d1 == 1)
      digitalWrite(pinD1,HIGH);
    else
      digitalWrite(pinD1,LOW);
    if (d2 == 1)
      digitalWrite(pinD2,HIGH);
    else
      digitalWrite(pinD2,LOW);

    analogWrite(pinCounter1,counter1);
    analogWrite(pinCounter2,counter2);
      
      
      // print thed three numbers in one string as hexadecimal:
      //Serial.print(red, HEX);
      //Serial.print(green, HEX);
      //Serial.println(blue, HEX);
   }
 }








