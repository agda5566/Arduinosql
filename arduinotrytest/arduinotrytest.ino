#include <dht.h> //DHT函式庫
#include <HX711.h> //秤重函式庫
#include <Servo.h> //伺服馬達函式庫

#define dht_dpin 2 //溫度資訊從pin2進來
HX711 hx(9, 10,128,0.00127551);//秤重精度調整
dht DHT;//溫度宣告
Servo myservo; // 建立Servo物件宣告，控制伺服馬達

int val; //存放磁簧感應變數
  
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);//初始化通訊孢率
  hx.set_offset(41562); //重量設定
  pinMode (5, INPUT) ;// 5pin 設定為輸入
  myservo.attach(3); //馬達pin 宣告
  pinMode(8,OUTPUT); //燈號輸出
  pinMode(7,OUTPUT); //燈號輸出
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
        GetWeigh(); //抓重量
        break;
      case '2':
        BuleLed(); //藍色燈光，表示裡面沒有東西
        break;
      case '3':
        RedLed(); //紅色燈光，表示裡面有東西
        break;
      case '4':
        CloseDoor();//關門
        break;
      case '5':
        OpenDoor(); //開門
        break;
      case '6':
        Reduction(); //重置燈光和門，回到開啟狀態和關閉燈光
        break;
      case '7':
        DoorCheck(); //檢查門有無上鎖
        break;
      default:
        Serial.println("Not effective num");
        
     }  
  }
}

void GetWeigh()
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
    //重量小於1直接回傳0
  }
  else{
    Serial.println(a);
  }
 
}
void rfid()
{
  //紅外線Deprecated
  Serial.println("rfid");  
}
void tch()
{
  //溫度Deprecated
  //Serial.println("tch");
  //double humidity=DHT.humidity;
  //Serial.print(humidity);
  //Serial.print("% ");
  //Serial.print("temperature = ");
  double temperature=0;
  temperature=DHT.temperature;
  Serial.println(temperature);
  //Serial.print(DHT.temperature);
  //Serial.println("C ");  
}
void CloseDoor(){
  //關門
  myservo.write(25);
  Serial.println("1");
        
}
void OpenDoor(){
  //開門
  myservo.write(85);
  Serial.println("0");
}
void Reduction(){
  
  myservo.write(85);
  digitalWrite(8, LOW);
  digitalWrite(7, LOW);
  Serial.println("0");
  
}
void BuleLed(){
  digitalWrite(8, LOW);
  digitalWrite(7, HIGH);
  Serial.println("0");
}
void RedLed(){
  digitalWrite(8, HIGH);
  digitalWrite(7, LOW);
  Serial.println("1");
}
void DoorCheck(){
  //檢查門是否關上
  val =digitalRead(5);
  if(val==HIGH)
  {
    Serial.println(val);
  }
  else
  {
    Serial.println(val);  
  }
  
}
