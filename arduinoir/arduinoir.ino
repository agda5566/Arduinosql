int Led=13;
int buttonpin=3;
int val;
static int g_counter = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); 
  pinMode(Led,OUTPUT);
  pinMode(buttonpin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  val=digitalRead(buttonpin);
  if(val==HIGH){
    digitalWrite(Led,HIGH);
    //Serial.println(g_counter);
    //g_counter++;
    Serial.print("ok");
    }else{
      digitalWrite(Led,LOW);
      //Serial.print("no");
      }
}
