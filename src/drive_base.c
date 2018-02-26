#include "main.h"

void wheelMonitorTask(void *parameter){
  while(true){
    bool leftDone = false;
    bool rightDone = false;

    bool run = runWheels;

    int target = wheelTargetTicks;

    enum WheelDirection d = wheelDir;

    while(run){

      if(abs(encoderGet(leftQuad)) < target){
        switch(d){
          case FORWARD:
          dLeftForward();
          break;
          case BACKWARD:
          dLeftBackward();
          break;
          case LEFT:
          dLeftBackward();
          break;
          case RIGHT:
          dLeftForward();
          break;
          default:
          stopDrive();
          break;

        }
      }
      else{
        stopLeft();
        leftDone = true;
      }

      if(abs(encoderGet(rightQuad)) < target){
        switch(d){
          case FORWARD:
          dRightForward();
          break;
          case BACKWARD:
          dRightBackward();
          break;
          case LEFT:
          dRightForward();
          break;
          case RIGHT:
          dRightBackward();
          break;
          default:
          stopDrive();
          break;
        }
      }else{
        stopRight();
        rightDone = true;
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

void setSyncMoveTicks(enum WheelDirection d,int targetTicks){
  wheelTargetTicks = targetTicks;
  wheelDir = d;

  encoderReset(leftQuad);
  encoderReset(rightQuad);

  runWheels = true;
}

//TODO ADD INCHES TO TICK CONVERSION
void setSyncMoveInches(enum WheelDirection d, float targetInches){
  wheelTargetTicks = targetInches;
  wheelDir = d;

  encoderReset(leftQuad);
  encoderReset(rightQuad);

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
  setMotor(&backRight, rightPower);
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
  setMotor(&backLeft, 0);
  setMotor(&frontLeft, 0);
  setMotor(&backRight, 0);
  setMotor(&frontRight, 0);
}
