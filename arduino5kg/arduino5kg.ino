#include <HX711.h>

HX711 hx(9, 10,128,0.00127551);

void setup() {
  Serial.begin(9600);
  hx.set_offset(41562);
}

void loop()
{
 // double sum = 0;
//  for (int i = 0; i < 10; i++)
//    sum += hx.read();
//  Serial.println(sum/10);
  //Serial.println(cell.read());
  
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
  delay(500);
}
