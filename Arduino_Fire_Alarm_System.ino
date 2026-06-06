float temp;
int gasSensor;

int LED = 13;
int buzzer = 7;

void setup()
{
  pinMode(A0, INPUT);   // MQ Gas Sensor
  pinMode(A1, INPUT);   // LM35 Temperature Sensor

  pinMode(LED, OUTPUT);
  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  // Temperature Reading (LM35)
  int sensorValue = analogRead(A1);
  temp = (sensorValue * 5.0 * 100.0) / 1024.0;

  // Gas Sensor Reading
  gasSensor = analogRead(A0);

  // Temperature Alert
  if(temp >= 30)   // Testing kosam 30°C pettanu
  {
    digitalWrite(LED, HIGH);
  }
  else
  {
    digitalWrite(LED, LOW);
  }

  // Gas Alert
  if(gasSensor >= 100)
  {
    digitalWrite(buzzer, HIGH);
  }
  else
  {
    digitalWrite(buzzer, LOW);
  }

  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print(" C\t");

  Serial.print("Gas Value: ");
  Serial.println(gasSensor);

  delay(1000);
}
