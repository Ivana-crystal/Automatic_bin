#include <Servo.h> // Include Servo library

Servo s1; // Create servo object

const int trigPin = 9;     // Ultrasonic sensor Trig pin
const int echoPin = 10;    // Ultrasonic sensor Echo pin

long duration;
int distanceCm;

void setup() {
  Serial.begin(9600); 
  s1.attach(3);            // Attach servo to pin 3
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Trigger the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Read the echo time
  duration = pulseIn(echoPin, HIGH);
  distanceCm = duration * 0.034 / 2; // Convert to cm

  Serial.print("Distance: ");
  Serial.print(distanceCm);
  Serial.println(" cm");

  // If the object is closer than 50 cm, move the servo
  if (distanceCm < 50) {
    s1.write(180); // Rotate servo to 90 degrees
    delay(2000);  // Wait for 2 seconds
  } else {
    s1.write(0);  // Rotate servo back to 0 degrees
    delay(500);   // Wait for 5 seconds
  }
}
