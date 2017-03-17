#include <Stepper.h>
Stepper stepper(48, 7, 6, 5, 4);
//我手上的馬達轉一圈為48步 (360/7.5 deg)，定義11, 10, 9, 8為輸出腳位 
void setup()
{
stepper.setSpeed(20); // 將馬達的速度設定成20RPM (太大趕不上)
}
void loop()
{
stepper.step(24);//正半圈
delay(1000);
stepper.step(-24);//反半圈
delay(1000);
stepper.step(48);//正1圈
delay(1000);
stepper.step(-48);//反1圈
delay(1000);
}
