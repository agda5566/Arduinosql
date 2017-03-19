
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0)
  {
    char a=Serial.read();
    switch(a)
    {
      case '1':
        digitalWrite(8, HIGH);
        digitalWrite(7, LOW);
        break;
      case '2':
        digitalWrite(8, LOW);
        digitalWrite(7, HIGH);
        break;
      default:
        Serial.println("Error");
        
    }
  }
}
