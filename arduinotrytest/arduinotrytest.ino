#include <dht.h> //DHT函式庫
#define dht_dpin 2 //溫度資訊從pin2進來
#include <HX711.h>

HX711 hx(9, 10,128,0.00127551);//秤重
dht DHT;//溫度

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  hx.set_offset(41562);
}

void loop() {
  DHT.read11(dht_dpin);
  // put your main code here, to run repeatedly:
  if(Serial.available()>0)
  {
    char a =Serial.read();
     switch(a)
     {
      case '1':
        kg();
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
void rfid()
{
  Serial.println("rfid");  
}
void tch()
{
  
  //Serial.println("tch");
  //double humidity=DHT.humidity;
  //Serial.print(humidity);
  //Serial.print("% ");
  //Serial.print("temperature = ");
  double temperature=DHT.temperature;
  Serial.println(temperature);
  //Serial.print(DHT.temperature);
  //Serial.println("C ");  
}
