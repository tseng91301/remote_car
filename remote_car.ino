#include "motors.h"
Car car(D1,D2,D3,D4);
void setup(){

}
void loop(){
    car.set_fb_speed(225);
    car.motor_turn();
    delay(1000);
    car.set_fb_speed(-225);
    car.motor_turn();
    delay(1000);
    car.set_lr_speed(150);
    car.motor_turn();
    delay(1000);
    car.set_lr_speed(-150);
    car.motor_turn();
    delay(1000);
}