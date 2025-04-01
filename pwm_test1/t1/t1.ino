const int pwmPin = 5;   // PWM-capable pin 
const int pwmValue = 53; // Duty cycle value 

void setup() {
  pinMode(pwmPin, OUTPUT);  // Set the PWM pin as an output
}

void loop() {
  for (int i = 0; i < pwmValue; i++) {
    analogWrite(pwmPin, i);
    delay(30);
  }
  for (int i = pwmValue; i >= 0; i--) {
    analogWrite(pwmPin, i);
    delay(30);
  }
}