#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// Servo parameters
#define SERVO_MIN_PULSE_WIDTH 150
#define SERVO_MAX_PULSE_WIDTH 600
#define SERVO_MIN_ANGLE 0
#define SERVO_MAX_ANGLE 180

// Define relay control pins
const int relay1_forward = 2;
const int relay1_reverse = 3;
const int relay2_forward = 4;
const int relay2_reverse = 5;

void setup() {
  Serial.begin(9600);

  // Initialize relay control pins as outputs
  pinMode(relay1_forward, OUTPUT);
  pinMode(relay1_reverse, OUTPUT);
  pinMode(relay2_forward, OUTPUT);
  pinMode(relay2_reverse, OUTPUT);

  pwm.begin();
  pwm.setPWMFreq(50);  // Set PWM frequency to 50 Hz (adjust as needed)
  delay(10);
}

void setServoAngle(int num, int angle) {
  // Map angle to PWM pulse width
  uint16_t pulse_width = map(angle, SERVO_MIN_ANGLE, SERVO_MAX_ANGLE, SERVO_MIN_PULSE_WIDTH, SERVO_MAX_PULSE_WIDTH);
  pwm.setPWM(num, 0, pulse_width);  // Set PWM pulse width for channel 0
}

//Forward
void front() {
  digitalWrite(relay1_forward, LOW);
  digitalWrite(relay1_reverse, HIGH);
  digitalWrite(relay2_forward, LOW);
  digitalWrite(relay2_reverse, HIGH);
}

//Backward
void back() {
  digitalWrite(relay1_forward, HIGH);
  digitalWrite(relay1_reverse, LOW);
  digitalWrite(relay2_forward, HIGH);
  digitalWrite(relay2_reverse, LOW);
}

//Left
void left() {
  digitalWrite(relay1_forward, LOW);
  digitalWrite(relay1_reverse, HIGH);
  digitalWrite(relay2_forward, HIGH);
  digitalWrite(relay2_reverse, LOW);
}

//Right
void right() {
  digitalWrite(relay1_forward, HIGH);
  digitalWrite(relay1_reverse, LOW);
  digitalWrite(relay2_forward, LOW);
  digitalWrite(relay2_reverse, HIGH);
}

//Stop
void stopMotors() {
  digitalWrite(relay1_forward, LOW);
  digitalWrite(relay1_reverse, LOW);
  digitalWrite(relay2_forward, LOW);
  digitalWrite(relay2_reverse, LOW);
}

void loop() {
  if (Serial.available() > 0) {
    // Check if input is a character (for DC motors) or an integer (for servos)
    if (isDigit(Serial.peek())) {
      // Input is an integer (for servos)
      int num = Serial.parseInt();
      Serial.println("Enter servo number, Enter servo angle ");
      int angle = Serial.parseInt();

      if (angle >= 0 && angle <= 180) {
        setServoAngle(num, angle);
      } else {
        Serial.println("Invalid angle. Please enter a value between 0 and 180.");
      }
    } else {
      // Input is a character (for DC motors)
      char command = Serial.read();

      switch (command) {
        case 'b':
          back();
          break;

        case 'f':
          front();
          break;

        case 'r':
          right();
          break;

        case 'l':
          left();
          break;

        case 's':
          stopMotors();
          break;
          
        default:
          break;
      }
    }
  }
}