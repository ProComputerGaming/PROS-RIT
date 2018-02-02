#include "main.h"

void liftMonitorTask(void *parameter){
  while(true){
    bool leftLiftDone = false;
    bool rightLiftDone = false;

    bool run = runLift;

    int target = liftTargetTicks;

    while(run){

      if(encoderGet(leftLiftQuad) < target){
        dLeftLiftUp();
      }else if(encoderGet(leftLiftQuad) > target){
        dLeftLiftDown();
      }else{
        stopLeftLift();
        leftLiftDone = true;
      }

      if(encoderGet(rightLiftQuad) < target){
        dRightLiftUp();
      }else if(encoderGet(rightLiftQuad) > target){
        dRightLiftDown();
      }else{
        stopRightLift();
        rightLiftDone = true;
      }

      if(leftLiftDone && rightLiftDone){
        run = false;

        runLift = false;

        stopLift();
      }

      delay(1);
    }
    delay(1);
  }
}

void liftPID(void *parameter){

}

void setSyncLift(int targetTicks){
  liftTargetTicks = targetTicks;

  runLift = true;
}

void dLeftLiftUp(){
  setMotor(&leftLiftY, 127);
}

void dLeftLiftDown(){
  setMotor(&leftLiftY, -127);
}

void dRightLiftUp(){
  setMotor(&rightLiftY, 127);
}

void dRightLiftDown(){
  setMotor(&rightLiftY, -127);
}

void stopLeftLift(){
  setMotor(&leftLiftY, 0);
}

void stopRightLift(){
  setMotor(&rightLiftY, 0);
}

void stopLift(){
  stopLeftLift();
  stopRightLift();
}
