int photocellPin = 2;
int photocellVal = 0;
int minLight = 200;
int ledPin = 9;
int ledState = 0;
///光敏電阻
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  photocellVal = analogRead(photocellPin);
  Serial.println(photocellVal);
  if (photocellVal < minLight && ledState == 0) {
digitalWrite(ledPin, HIGH); // turn on LED
ledState = 1;
  }
if (photocellVal > minLight && ledState == 1) {
digitalWrite(ledPin, LOW); // turn off LED
ledState = 0;
}
  delay(100);
}
