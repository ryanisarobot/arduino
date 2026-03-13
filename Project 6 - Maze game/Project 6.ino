#include <Servo.h>

Servo servo1;
Servo servo2;

int joyXPin = A5; // Analog pin for X-axis
int joyYPin = A4; // Analog pin for Y-axis

const int servo1Min = 70;
const int servo1Max = 90;
const int servo2Min = 105;
const int servo2Max = 115;

unsigned long previousMillis = 0; // Timer variable for Serial output
const long interval = 500;        // Interval for Serial output in milliseconds

void setup() 
{
  Serial.begin(9600); // Initialize serial communication at 9600 bps
  servo1.attach(6);    // Connect servo1 to digital pin 3
  servo2.attach(7);    // Connect servo2 to digital pin 5
}

void loop()
{
  int joyValX = analogRead(joyXPin);  // Read and map X-axis joystick value for servo1
  int joyValY = analogRead(joyYPin);  // Read and map Y-axis joystick value for servo2
  
  int servo1Pos = map(joyValX, 0, 1023, servo1Min, servo1Max);
  int servo2Pos = map(joyValY, 0, 1023, servo2Min, servo2Max);
  
  servo1.write(servo1Pos);
  servo2.write(servo2Pos);
  
  // Check if the interval has elapsed for Serial output
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) 
  {
    previousMillis = currentMillis; // Update the timer

    // Print joystick and servo positions to Serial Monitor
    Serial.print("Joystick X: ");
    Serial.print(joyValX);
    Serial.print(" -> Servo1 Position: ");
    Serial.println(servo1Pos);

    Serial.print("Joystick Y: ");
    Serial.print(joyValY);
    Serial.print(" -> Servo2 Position: ");
    Serial.println(servo2Pos);
  }

  delay(65); // Small delay for stable servo movement
}
