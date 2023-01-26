#include <Arduino.h>

const int speakerPin = 5;

void setup() {
  Serial.begin(9600);
  pinMode(speakerPin, OUTPUT);
}

void loop() {
  int reading  = analogRead(A0);

  // the map() function takes 5 arguments: the number we want to scale,
  // the minimum and maximum values that we are getting,
  // and the minimum and maximum values of the range we'd like
  // Kitchen light
  int frequency = map(reading, 0, 200, 500, 1000);

  // Makes tone on speaker
  tone(speakerPin, frequency);

  Serial.print(reading);
  Serial.print(" -> ");
  Serial.println(frequency);
}