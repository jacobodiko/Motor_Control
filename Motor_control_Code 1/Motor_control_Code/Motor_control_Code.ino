#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Change 0x27 to your I2C address

const byte enA = A0;               //Arduino Enable pin for motor A | connect to the A0 of the driver
const byte motorDriveCWA = 7;     //Arduino clockwise control for motor A |Connect to D7 of the Driver
const byte motorDriveCCWA = 8;    // Arduino Counterclockwise control for motor A| Connect to D8 of the driver
const byte motorDriverPWMA = 5;  // D5Arduino Speed Control for Motor A |Connect to D5 of the driver


const int clockwiseDuration = 70000;      // 70 seconds
const int anticlockwiseDuration = 65000;  // 65 seconds
const int restDuration = 60000;           // 60 seconds

void setup() {
  Serial.begin(9600);
  pinMode(enA, OUTPUT);
  pinMode(motorDriverPWMA, OUTPUT);
  pinMode(motorDriveCWA, OUTPUT);
  pinMode(motorDriveCCWA, OUTPUT);
  digitalWrite(enA, HIGH);
  lcd.begin(16, 2);
  delay(2000);
}

void loop() {
  // Rotate clockwise
  lcd.clear();
  lcd.print("CLOCKWISE");
  motorControl(255, HIGH, LOW);
  delay(clockwiseDuration);

  // Stop and rest
  lcd.clear();
  lcd.print("STOPPED");
  motorControl(0, LOW, LOW);
  delay(restDuration);

  // Rotate anticlockwise
  lcd.clear();
  lcd.print("ANTICLOCKWISE");
  motorControl(255, LOW, HIGH);
  delay(anticlockwiseDuration);

  // Stop and rest
  lcd.clear();
  lcd.print("STOPPED");
  motorControl(0, LOW, LOW);
  delay(restDuration);
}

void motorControl(int speed, int in1, int in2) {
  analogWrite(motorDriverPWMA, speed);
  digitalWrite(motorDriveCWA, in1);
  digitalWrite(motorDriveCCWA, in2);
}
