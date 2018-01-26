#include "main.h"

void wheelMonitorTask(void *parameter){
  while(true){
          bool dLeftDirection = false;
          bool dRightDirection = false;
          bool leftDone = false;
          bool rightDone = false;
          bool gyroStepOne = false;
          bool gyroStepTwo = false;
          int targetOffset = 0;

          bool run = runWheels;

          int target = wheelTargetTicks;

          enum WheelDirection d = wheelDir;

          while(run){
              run = runWheels;

              int gyroAverage = (gyroGet(gyroOne) + gyroGet(gyroTwo)) / 2;
              if(gyro){
                  if((!leftDone || !rightDone) && !gyroStepOne){
                      targetOffset =  abs(target) < 45 ? 30 : abs(target * .6);
                      if(gyroAverage < target - targetOffset){
                          dLeft(true);
                          dRight(false);
                      }else if(gyroAverage > target + targetOffset){
                          dLeft(false);
                          dRight(true);
                      }else{
                          gyroStepOne = true;
                          stopDrive();
                          delay(400);
                      }
                  }else if((!leftDone || !rightDone) && !gyroStepTwo){
                      DRIVEBASE_POWER = (int)((double)DRIVEBASE_POWER * .55);
                      if(gyroAverage < target){
                          dLeft(true);
                          dRight(false);
                      }else if(gyroAverage > target){
                          dLeft(false);
                          dRight(true);
                      }else{
                          gyroStepTwo = true;
                      }
                      DRIVEBASE_POWER /= .55;
                  }else{

                      leftDone = true;
                      rightDone = true;
                      stopDrive();
                  }

                  if(leftDone && rightDone){
                      run = false;

                      runWheels = false;
                      stopDrive();
                  }
              }else{
                  if(abs(encoderGet(leftQuad)) < target){
                      switch(d){
                          case FORWARD: dLeftDirection = false; break;
                          case BACKWARD: dLeftDirection = true; break;
                          case LEFT: dLeftDirection = true; break;
                          case RIGHT: dLeftDirection = false; break;
                      }
                      dLeft(dLeftDirection);
                  }else{
                      leftDone = true;
                      stopLeft();
                  }

                  if(abs(encoderGet(rightQuad)) < target){
                      switch(d){
                          case FORWARD: dRightDirection = false; break;
                          case BACKWARD: dRightDirection = true; break;
                          case LEFT: dRightDirection = false; break;
                          case RIGHT: dRightDirection = true; break;
                      }
                      dRight(dRightDirection);
                  }else{
                      rightDone = true;
                      stopRight();
                  }

                  if(leftDone && rightDone){
                      run = false;

                      runWheels = false;
                      stopDrive();
                  }
              }
              if(leftDone && rightDone){
                  run = false;

                  runWheels = false;

                  stopDrive();
              }

              delay(1);
          }
          delay(1);
  }
}

void setSyncMove(enum WheelDirection d,int targetTicks, bool enableGyro){
  wheelTargetTicks = targetTicks;
  wheelDir = d;

  runWheels = true;
}

void dLeftBackward(){
  setMotor(&backLeft, -DRIVEBASE_POWER);
  setMotor(&frontLeft, -DRIVEBASE_POWER);
}

void dLeftForward(){
  setMotor(&backLeft, DRIVEBASE_POWER);
  setMotor(&frontLeft, DRIVEBASE_POWER);
}

void dRightBackward(){
  setMotor(&backRight, -DRIVEBASE_POWER);
  setMotor(&frontRight, -DRIVEBASE_POWER);
}

void dRightForward(){
  setMotor(&backRight, DRIVEBASE_POWER);
  setMotor(&frontRight, DRIVEBASE_POWER);
}

void analogDrive(){
  int leftPower = joystickGetAnalog(1, 3);
  int rightPower = joystickGetAnalog(1, 2);
  if(abs(leftPower) < JOYSTICK_DEADZONE)
    leftPower = 0;
  if(abs(rightPower) < JOYSTICK_DEADZONE)
    rightPower = 0;
  setMotor(&backLeft, leftPower);
  setMotor(&frontLeft, -leftPower);
  setMotor(&backRight, -rightPower);
  setMotor(&frontRight, rightPower);
}

void stopLeft(){
  setMotor(&backLeft, 0);
  setMotor(&frontLeft, 0);
}

void stopRight(){
  setMotor(&backLeft, 0);
  setMotor(&frontLeft, 0);
}

void stopDrive(){
  stopLeft();
  stopRight();
}
