const int PWM_pin = 9; // PWM pin
const int Range = 255; // Number of steps for the triangular wave
const int Time = 4; // Delay between steps (controls frequency)
const int Analog_pin = A0; // Analog input pin

void setup() {
  // Initialize pin 9 as an OUTPUT
  pinMode(PWM_pin, OUTPUT);
  // Start the serial communication for monitoring
  Serial.begin(9600);
}

void loop() {
  // Generate triangular wave (ramp up)
  for (int i = 0; i <= Range; i++) {
    analogWrite(PWM_pin, i); // Set PWM value
    
    // Read the value from A0
    int Sensor_value = analogRead(Analog_pin);

    // Print both the PWM value and A0 reading to Serial Plotter
    Serial.print("Ramp_Signal:");
    Serial.print(i); // PWM value
    Serial.print(",PWM_Output:"); 
    Serial.println(Sensor_value); // Analog value from A0
    
    delay(Time); // Delay to control the frequency
  }

  // Generate triangular wave (ramp down)
  for (int i = Range; i >= 0; i--) {
    analogWrite(PWM_pin, i); // Set PWM value
    
    // Read the value from A0
    int Sensor_value = analogRead(Analog_pin);

    // Print both the PWM value and A0 reading to Serial Plotter
    Serial.print("Ramp_Signal:");
    Serial.print(i); // PWM value
    Serial.print(",PWM_Output:"); 
    Serial.println(Sensor_value); // Analog value from A0
    
    delay(Time); // Delay to control the frequency
  }
}
