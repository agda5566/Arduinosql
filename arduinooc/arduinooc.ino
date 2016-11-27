#include <dht.h>

#define dht_dpin 2 //定義訊號要從Pin A0 進來

dht DHT;

void setup(){
Serial.begin(9600);
delay(300);             //Let system settle
Serial.println("Humidity and temperature\n\n");
delay(700);             //Wait rest of 1000ms recommended delay before
                        //accessing sensor
}

void loop(){
DHT.read11(dht_dpin);   //去library裡面找DHT.read11
Serial.print("Humidity = ");
double humidity=DHT.humidity;
Serial.print(humidity);
Serial.print("% ");
Serial.print("temperature = ");
double temperature=DHT.temperature;
Serial.print(temperature);
Serial.print(DHT.temperature);
Serial.println("C ");
delay(5000);            //每1000ms更新一次
}
