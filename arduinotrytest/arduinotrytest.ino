void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0)
  {
    char a =Serial.read();
     switch(a)
     {
      case '1':
        sql();
        break;
      case '2':
        rfid();
        break;
      case '3':
        tch();
        break;
      default:
        Serial.println("noononono");
        
     }  
  }
}

void sql()
{
  Serial.println("1sql");
}
void rfid()
{
  Serial.println("rfid");  
}
void tch()
{
  Serial.println("tch");  
}
