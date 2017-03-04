#include<dht.h>
#define dht_dpin2
#include<HX711.h>
HX711 hx(9, 10,128,0.00127551);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  hx.set_offset(41562);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0)
  {
    char a=Serial.read();
    double i=122;
    switch(a)
    {
      case '1':
        
        Serial.println(i);
        break;
      case '2':
        kg();      
        break;
      case 'h':
        hing();
        break;
      case 'l':
        low();
        break;
      default:
        Serial.println("xd");  
    }  
  }
}
void kg()
{
  double sum0=0;
  double sum1=0;
  double a=0;
  for(int i=0;i<10;i++){
    sum0+=hx.read();
    sum1+=hx.bias_read();
  }
  a=(sum1/10)-51;
  //Serial.println("ks:"); 
  if(a<1){
    Serial.println("0");
  }
  else{
    Serial.println(a);
  }
  //delay(500);
}
void hing()
{
  digitalWrite(LED_BUILTIN,HIGH);
  Serial.println("ledopen!");
  
  }
  void low()
  {
    digitalWrite(LED_BUILTIN, LOW);
    Serial.println("ledclose"); 
    }
