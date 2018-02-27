#include "main.h"

void liftMonitorTask(void *parameter){
  while(true){
    bool leftLiftDone = false;
    bool rightLiftDone = false;

    bool run = runLift;

    int target = liftTargetTicks;

    while(run){
      if(abs(encoderGet(leftLiftQuad)) < abs(encoderGet(rightLiftQuad))){
        leftOffset = SYNCHRONOUS_POWER_OFFSET;
        rightOffset = 0;
      }else if(abs(encoderGet(rightLiftQuad)) < abs(encoderGet(leftLiftQuad))){
        rightOffset = SYNCHRONOUS_POWER_OFFSET;
        leftOffset = 0;
      }

      if(abs(encoderGet(leftLiftQuad)) < target){
        dLeftLiftUp();
      }else if(abs(encoderGet(leftLiftQuad)) > target){
        dLeftLiftDown();
      }else{
        stopLeftLift();
        leftLiftDone = true;
      }

      if(abs(encoderGet(rightLiftQuad)) < target){
        dRightLiftUp();
      }else if(abs(encoderGet(rightLiftQuad)) > target){
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
  setMotor(&leftFour, LIFT_POWER + leftOffset);
}

void dLeftLiftDown(){
  setMotor(&leftFour, -LIFT_POWER - leftOffset);
}

void dRightLiftUp(){
  setMotor(&rightFour, LIFT_POWER + rightOffset);
}

void dRightLiftDown(){
  setMotor(&rightFour, -LIFT_POWER - rightOffset);
}

void stopLeftLift(){
  setMotor(&leftFour, 0);
}

void stopRightLift(){
  setMotor(&rightFour, 0);
}

void stopLift(){
  stopLeftLift();
  stopRightLift();
}
