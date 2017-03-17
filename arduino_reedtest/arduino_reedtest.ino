#define DPin 12
void setup() {
  // put your setup code here, to run once:
  pinMode(DPin,INPUT);//定義digital為輸入介面
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val ;
  val=digitalRead(DPin);//讀取Light感測器的模擬值

  Serial.println(val);//輸出模擬值，並將其列印出來
}
