
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0)
  {
    char a=Serial.read();
    switch(a)
    {
      case '1':
        digitalWrite(7, HIGH);
        digitalWrite(6, LOW);
        break;
      case '2':
        digitalWrite(7, LOW);
        digitalWrite(6, HIGH);
        break;
      default:
        Serial.println("Error");
        
    }
  }
}
