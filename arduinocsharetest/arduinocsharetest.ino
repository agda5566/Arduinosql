char str_in;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0)
  {
  //str_in = Serial.read();
  //Serial.print("key in chart is : ");
  Serial.println(str_in);
  delay(1000);
//  Serial.println ('1'); delay(1000);
//  Serial.println ('2'); delay(1000);
//  Serial.println ('3'); delay(1000);
//  Serial.println ('4'); delay(1000);
//  Serial.println ('5'); delay(1000); 
  }
}
