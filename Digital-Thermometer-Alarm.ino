// Digital Thermometer with an Alarm

// Pin assignments
const int tempSensorPin = A0; // Analog pin where we check the temp
const int buzzerPin = 9;      // Digital pin for the buzzer

// Temperature limit
const int tempLimit = 25; // If it's hotter than this, the buzzer goes off you can edit it as much as you want

void setup() {
  Serial.begin(9600); // Start talking to the computer
  pinMode(buzzerPin, OUTPUT); //turn on the buzzer 
}

void loop() {
  // Grab the temperature from the LM35 sensor
  int rawTemp = analogRead(tempSensorPin);
  float tempCelsius = (rawTemp * 5.0) / 1024.0 * 100.0;

  // Shows  the temperature
  Serial.print("Current Temp: ");
  Serial.print(tempCelsius);
  Serial.println(" degrees Celsius");

  // Check if it's too hot 
  if (tempCelsius > tempLimit) {
    // Activate the buzzer for  1 second
    digitalWrite(buzzerPin, HIGH);
    delay(1000);
    digitalWrite(buzzerPin, LOW);
  }

  delay(5000); // it wairs for 5 seconds before the next reading
}
