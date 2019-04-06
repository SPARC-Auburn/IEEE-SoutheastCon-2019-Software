/*
  Analog input, analog output, serial output

 Reads an analog input pin, maps the result to a range from 0 to 255
 and uses the result to set the pulsewidth modulation (PWM) of an output pin.
 Also prints the results to the serial monitor.

 The circuit:
 * potentiometer connected to analog pin 0.
   Center pin of the potentiometer goes to the analog pin.
   side pins of the potentiometer go to +5V and ground
 * LED connected from digital pin 9 to ground

 created 29 Dec. 2008
 modified 9 Apr 2012
 by Tom Igoe

 This example code is in the public domain.

 */

// These constants won't change.  They're used to give names
// to the pins used:
const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
const int analogOutPin = 3; // Analog output pin that the LED is attached to
const int buttonPin = 4;

int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  
  int readyState = 0;
  int mode = -1;
  int buttonState = 0;  
  
  while (readyState == 0){
    sensorValue = analogRead(analogInPin);
    buttonState = digitalRead(buttonPin);
    if (sensorValue < 255){
      Serial.print("Mode: 0 (Red)\n");
      mode = 0;
    }
    else if (sensorValue < 510){
      Serial.print("Mode: 1 (Green)\n");
      mode = 1;
    }
    else if (sensorValue < 765){
      Serial.print("Mode: 2 (Blue)\n");
      mode = 2;
    }
    else if (sensorValue < 1024){
      Serial.print("Mode: 3 (Yellow)\n");
      mode = 3;
    }
    else {
      Serial.print("Mode: Error\n");
      mode = -1;
    }
    if (buttonState){
      readyState = 1;
    }
  }
  Serial.print("Ready, Mode:");
  Serial.print(mode);
  Serial.print("\nPlease press go\n");
  buttonState = 0;
  delay(2000);
  while (buttonState == 0){
    buttonState = digitalRead(buttonPin);
  }
  Serial.print("Running...");
}

void loop() {
  // read the analog in value:
  
  delay(2);
}
