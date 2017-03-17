void setup() {
  // put your setup code here, to run once:
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
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
        d();
        break;
      case '2':
       b();
        break;
      case '3':
        c();
        break;
      default:
        Serial.println("noononono");
        
     }  
  }
}
void d(){
  int i=0;
  while(i<128){
        digitalWrite( 4 , HIGH );
        digitalWrite( 5 , LOW );
        digitalWrite( 6 , LOW );
        digitalWrite( 7 , LOW );
        delay( 20 );
        digitalWrite( 4 , LOW );
        digitalWrite( 5 , HIGH );
        digitalWrite( 6 , LOW );
        digitalWrite( 7 , LOW );
        delay( 20 );
        digitalWrite( 4 , LOW );
        digitalWrite( 5 , LOW );
        digitalWrite( 6 , HIGH );
        digitalWrite( 7 , LOW );
        delay( 20 );
        digitalWrite( 4 , LOW );
        digitalWrite( 5 , LOW );
        digitalWrite( 6 , LOW );
        digitalWrite( 7 , HIGH );
        delay( 20 );
        i++;
  }
  }
  void b(){
    int k=0;
  while(k<128){
        digitalWrite( 4 , LOW );
        digitalWrite( 5 , LOW );
        digitalWrite( 6 , LOW );
        digitalWrite( 7 , HIGH );
        delay( 20 );
        digitalWrite( 4 , LOW );
        digitalWrite( 5 , LOW);
        digitalWrite( 6 , HIGH );
        digitalWrite( 7 , LOW );
        delay( 20 );
        digitalWrite( 4 , LOW );
        digitalWrite( 5 , HIGH );
        digitalWrite( 6 , LOW );
        digitalWrite( 7 , LOW );
        delay( 20 );
        digitalWrite( 4 , HIGH );
        digitalWrite( 5 , LOW );
        digitalWrite( 6 , LOW );
        digitalWrite( 7 , LOW );
        delay( 20 );
        k++;
        }
    }
    void c(){
      Serial.println("3");
      }
