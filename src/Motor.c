#include "main.h"

void initMotor(Motor* motor, int port, bool reversed, bool slewOn){
  motor->portNum = port;
  motor->reversed = reversed;
  motor->slewRate = DEFAULT_SLEW_RATE;
  motor->speed = 0;
  motor->requestedSpeed = 0;
  motor->slewOn = slewOn;
  changeMotor(motor);
}

void setMotor(Motor* motor, int speed){
  if(motor->reversed == REVERSED){
    motor->requestedSpeed = -speed;
  }
  else{
    motor->requestedSpeed = speed;
  }
}

Motor* getMotor(int portNum){
  return motors[portNum - 1];
}

void changeMotor(Motor* motor){
  motors[motor->portNum - 1] = motor;
}

void motorSlewTask(void *parameter){
  while(true){
    int i;
    for(i = 0; i < 10; i++){
      if(motors[i] == NULL || motors[i]->slewOn == false)
        continue;
      int requested = motors[i]->requestedSpeed;
      int speed = motors[i]->speed;
      int slew = motors[i]->slewRate;
      if(requested == 0){
        speed = 0;
      }else{
        if(requested > speed){
          speed += slew;
          if(speed > requested)
            speed = requested;
        }
        if(requested < speed){
          speed -= slew;
          if(speed < requested)
            speed = requested;
        }
      }

      motors[i]->speed = speed;
      motorSet(motors[i]->portNum, speed);
    }
    delay(SLEW_DELAY);
  }
}
