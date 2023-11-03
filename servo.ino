#include <Servo.h>

Servo myservo;
int pos = 90; // Initialize the servo at the center position

void setup() {
    myservo.attach(9); // Attach the servo to pin D9
    Serial.begin(9600); // Initialize serial communication
}

void loop() {
    if (Serial.available() > 0) {
        char command = Serial.read();
        if (command == 'L') {
            // Move servo to the left
            pos = max(0, pos - 100);
        } else if (command == 'R') {
            // Move servo to the right
            pos = min(180, pos + 100);
        } else if (command == 'C') {
            // Center the servo
            pos = 90;
        }
        myservo.write(pos);
        delay(15); // Allow the servo to reach the desired position
    }
}