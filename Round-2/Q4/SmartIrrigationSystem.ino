#include <Servo.h>

const int soilMoisturePin = A0;
const int potentiometerPin = A1;
const int pumpPin = 9;
const int buzzerPin = 7;
const int ledPin = 8;
const int buttonPin = 2;

Servo servoMotor;
int threshold = 300;  // Default threshold

void setup() {
  pinMode(soilMoisturePin, INPUT);
  pinMode(potentiometerPin, INPUT);
  pinMode(pumpPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);  // Internal pull-up resistor for button
  servoMotor.attach(10);
}

void loop() {
  // Read soil moisture and potentiometer values
  int soilMoisture = analogRead(soilMoisturePin);
  int potValue = analogRead(potentiometerPin);
  
  // Adjust threshold based on potentiometer value
  threshold = map(potValue, 0, 1023, 200, 800);  // Map potentiometer range to threshold range
  
  // Check soil moisture against adjusted threshold
  if (soilMoisture < threshold) {
    digitalWrite(pumpPin, HIGH);
    servoMotor.write(90);
    feedback(true);  // Start watering feedback
    delay(5000);     // Watering duration
    digitalWrite(pumpPin, LOW);
    servoMotor.write(0);
    feedback(false);  // Stop watering feedback
  }
  
  // Enter sleep mode when button is pressed
  if (digitalRead(buttonPin) == LOW) {
    sleepMode();
  }
  
  delay(1000); // Check soil moisture periodically
}

// Function to provide feedback with buzzer and LED
void feedback(bool isWatering) {
  if (isWatering) {
    digitalWrite(ledPin, HIGH);    // LED ON
    tone(buzzerPin, 1000);         // Short beep
    delay(100);
    digitalWrite(ledPin, LOW);     // LED OFF
    noTone(buzzerPin);
  } else {
    digitalWrite(ledPin, HIGH);    // LED ON
    tone(buzzerPin, 1500);         // Short beep
    delay(100);
    digitalWrite(ledPin, LOW);     // LED OFF
    noTone(buzzerPin);
  }
}

// Function to enter sleep mode
void sleepMode() {
  digitalWrite(pumpPin, LOW);   // Turn off pump
  servoMotor.detach();           // Release servo
  digitalWrite(ledPin, LOW);    // Turn off LED
  noTone(buzzerPin);            // Turn off buzzer
  
  // Enter sleep mode (low power state)
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  sleep_enable();
  attachInterrupt(digitalPinToInterrupt(buttonPin), wakeUp, LOW);
  sleep_mode();
  
  // Waking up
  sleep_disable();
  servoMotor.attach(10);        // Reattach servo
  delay(50);                    // Allow time for servo to initialize
}

// Interrupt service routine to wake up from sleep
void wakeUp() {
  detachInterrupt(digitalPinToInterrupt(buttonPin));
}
