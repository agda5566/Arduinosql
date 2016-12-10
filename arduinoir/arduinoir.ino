int Led=13;
#define FALSE 0
#define TRUE 1
int buttonpin=3;
int val;
int i=0,j=0;
static int g_counter = 0;
//http://www.yd-tech.com.tw/product_info.php/products_id/70965
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  pinMode(Led,OUTPUT);
  pinMode(buttonpin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  val=digitalRead(buttonpin);
  if(val==HIGH){
    digitalWrite(Led,HIGH);
   
    }else{
      digitalWrite(Led,LOW);
      i=1;
      delay(1000);
      if(i){
        j++;
        Serial.print(j);
        }
      }
}
