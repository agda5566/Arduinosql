//#include <Stepper.h>
//#define STEPS 200  //定義步進馬達每圈的步數
//Stepper stepper(STEPS, 11, 10, 9, 8);

void setup() {
  // put your setup code here, to run once:
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  
 

}

void loop() {
  

   //put your main code here, to run repeatedly:
        digitalWrite( 4 , HIGH );
        digitalWrite( 5 , LOW );
        digitalWrite( 6 , LOW );
        digitalWrite( 7 , LOW );
        delay( 10 );
        digitalWrite( 4 , LOW );
        digitalWrite( 5 , HIGH );
        digitalWrite( 6 , LOW );
        digitalWrite( 7 , LOW );
        delay( 10 );
        digitalWrite( 4 , LOW );
        digitalWrite( 5 , LOW );
        digitalWrite( 6 , HIGH );
        digitalWrite( 7 , LOW );
        delay( 10 );
        digitalWrite( 4 , LOW );
        digitalWrite( 5 , LOW );
        digitalWrite( 6 , LOW );
        digitalWrite( 7 , HIGH );
        delay( 10 );
}
