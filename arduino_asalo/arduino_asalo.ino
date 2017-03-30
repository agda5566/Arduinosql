#include <Stepper.h> 
int Pin1 = 8; 
int Pin2 = 9; 
int Pin3 = 10; 
int Pin4 = 11; 
int StepsPerRound = 2048; 
// 28BYJ-48 5V DC 繞一圈的步數 

int _delay = 1000; 
int State = 0; 

Stepper stepper(StepsPerRound, Pin1, Pin3, Pin2, Pin4); 
//馬達轉一圈為2048步 (360/7.5 deg)，定義11, 10, 9, 8為輸出腳位 

void setup() { 
  Serial.begin(9600);
  stepper.setSpeed(16); //將馬達的速度設定成5RPM (設錯會歸零，見上方解釋) 
} 

void loop() {
    if(Serial.available()>0){
      char a= Serial.read();
      switch(a)
      {
        case '1':
        ha();
        break;
        case '2':
        haa();
        break;
        
       
        default:
          Serial.println("nononono");
      }
      
      }
}
void ha(){
  stepper.step(512);
  
  }
  void haa(){
    stepper.step(-512);
    
    }
    /*if(State == 1){ 
  // turn on: 
    stepper.step(512);//正半圈 
    delay(_delay); 
    stepper.step(-512);//反半圈 
  }
    else{ 
    delay(_delay); 
    } 
  State++; 
  if(State>10){ 
  State =0;
  }*/

