#include "main.h"

void wheelMonitorTask(void *parameter){

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
