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

}

void dLeftLiftUp(){

}

void dLeftLiftDown(){

}

void dRightLiftUp(){

}

void dRightLiftDown(){

}

void stopLeftLift(){

}

void stopRightLift(){

}

void stopLift(){

}
