#include "main.h"

void stopAll(){
  setMotor(&backLeft, 0);
  setMotor(&frontLeft, 0);
  setMotor(&backRight, 0);
  setMotor(&frontRight, 0);
  setMotor(&leftInLift, 0);
  setMotor(&rightInLift, 0);
  setMotor(&leftFour, 0);
  setMotor(&rightFour, 0);
  setMotor(&intake, 0);
}

void turnLeft(int degrees, int speed){
  int numOfTicks = (degrees / 360.0) * fullTurnTicks;
  encoderReset(leftQuad);
  encoderReset(rightQuad);

  int encoderAverage = (abs(encoderGet(leftQuad)) + abs(encoderGet(rightQuad))) / 2;
  while(encoderAverage < numOfTicks){
    setMotor(&backLeft, -speed);
    setMotor(&frontLeft, -speed);
    setMotor(&backRight, speed);
    setMotor(&frontRight, speed);
    encoderAverage = (abs(encoderGet(leftQuad)) + abs(encoderGet(rightQuad))) / 2;
  }
  stopDrive();
}

void turnRight(int degrees, int speed){
  int numOfTicks = (degrees / 360.0) * fullTurnTicks;
  encoderReset(leftQuad);
  encoderReset(rightQuad);

  int encoderAverage = (abs(encoderGet(leftQuad)) + abs(encoderGet(rightQuad))) / 2;
  while(encoderAverage < numOfTicks){
    setMotor(&backLeft, speed);
    setMotor(&frontLeft, speed);
    setMotor(&backRight, -speed);
    setMotor(&frontRight, -speed);
    encoderAverage = (abs(encoderGet(leftQuad)) + abs(encoderGet(rightQuad))) / 2;
  }
  stopDrive();
}

void forwardInches(int inches, int speed){
  int numOfTicks = (inches/(PI * WHEEL_DIAM_INCHES)) * 360;
  encoderReset(leftQuad);
  encoderReset(rightQuad);

  int encoderAverage = (abs(encoderGet(leftQuad)) + abs(encoderGet(rightQuad))) / 2;
  while(encoderAverage < numOfTicks){
    setMotor(&backLeft, speed);
    setMotor(&frontLeft, speed);
    setMotor(&backRight, speed);
    setMotor(&frontRight, speed);
    encoderAverage = (abs(encoderGet(leftQuad)) + abs(encoderGet(rightQuad))) / 2;
  }
  stopDrive();
}

void backwardInches(int inches, int speed){
  int numOfTicks = (inches/(PI * WHEEL_DIAM_INCHES)) * 360;
  encoderReset(leftQuad);
  encoderReset(rightQuad);

  int encoderAverage = (abs(encoderGet(leftQuad)) + abs(encoderGet(rightQuad))) / 2;
  while(encoderAverage < numOfTicks){
    setMotor(&backLeft, -speed);
    setMotor(&frontLeft, -speed);
    setMotor(&backRight, -speed);
    setMotor(&frontRight, -speed);
    encoderAverage = (abs(encoderGet(leftQuad)) + abs(encoderGet(rightQuad))) / 2;
  }
  stopDrive();
}

void forwardTicks(int ticks, int speed){
  encoderReset(leftQuad);
  encoderReset(rightQuad);

  int encoderAverage = (abs(encoderGet(leftQuad)) + abs(encoderGet(rightQuad))) / 2;
  while(encoderAverage < ticks){
    setMotor(&backLeft, speed);
    setMotor(&frontLeft, -speed);
    setMotor(&backRight, -speed);
    setMotor(&frontRight, speed);
    encoderAverage = (abs(encoderGet(leftQuad)) + abs(encoderGet(rightQuad))) / 2;
  }

  setMotor(&backLeft, -speed);
  setMotor(&frontLeft, speed);
  setMotor(&backRight, speed);
  setMotor(&frontRight, -speed);
  delay(500);
  stopDrive();
}

void backwardTicks(int ticks, int speed){
  encoderReset(leftQuad);
  encoderReset(rightQuad);

  int encoderAverage = (abs(encoderGet(leftQuad)) + abs(encoderGet(rightQuad))) / 2;
  while(encoderAverage < ticks){
    setMotor(&backLeft, -speed);
    setMotor(&frontLeft, speed);
    setMotor(&backRight, speed);
    setMotor(&frontRight, -speed);
    encoderAverage = (abs(encoderGet(leftQuad)) + abs(encoderGet(rightQuad))) / 2;
  }
  stopDrive();
}

void liftToTicks(int targetTick);

void liftToInches(int targetInches);

void liftScissorTime(int milliseconds, int speed, bool down){
  if(down){
    setMotor(&leftInLift, -speed);
    setMotor(&rightInLift, -speed);
    delay(milliseconds);
    setMotor(&leftInLift, 0);
    setMotor(&rightInLift, 0);
  }else{
    setMotor(&leftInLift, speed);
    setMotor(&rightInLift, speed);
    delay(milliseconds);
    setMotor(&leftInLift, 50);
    setMotor(&rightInLift, 50);

  }
}

void liftFourTime(int milliseconds, int speed, bool down){
  if(down){
    setMotor(&leftFour, -speed);
    setMotor(&rightFour, -speed);
    delay(milliseconds);
    setMotor(&leftFour, 0);
    setMotor(&rightFour, 0);
  }else{
    setMotor(&leftFour, speed);
    setMotor(&rightFour, speed);
    delay(milliseconds);
    setMotor(&leftFour, 20);
    setMotor(&rightFour, 20);

  }
}

void dropCone(int milliseconds, int speed){
  setMotor(&intake, speed);
  delay(milliseconds);
  setMotor(&intake, 0);
}

void pickupCone(int milliseconds, int speed){
  setMotor(&intake, -speed);
  delay(milliseconds);
  setMotor(&intake, 0);
}

void inLiftDropPos(){
  while(analogRead(rightIntakeLiftPot) > stackPos){
    setMotor(&leftInLift, INTAKE_LIFT_POWER);
    setMotor(&rightInLift, INTAKE_LIFT_POWER);
  }

  while(analogRead(rightIntakeLiftPot) < stackPos){
    setMotor(&leftInLift, -INTAKE_LIFT_POWER);
    setMotor(&rightInLift, -INTAKE_LIFT_POWER);
  }
  setMotor(&leftInLift, 0);
  setMotor(&rightInLift, 0);
}

void inLiftSuckPos(){
  while(analogRead(rightIntakeLiftPot) > suckPos){
    setMotor(&leftInLift, INTAKE_LIFT_POWER);
    setMotor(&rightInLift, INTAKE_LIFT_POWER);
  }

  while(analogRead(rightIntakeLiftPot) < suckPos){
    setMotor(&leftInLift, -INTAKE_LIFT_POWER);
    setMotor(&rightInLift, -INTAKE_LIFT_POWER);
  }
  setMotor(&leftInLift, 0);
  setMotor(&rightInLift, 0);
}

void lowerMG(){
  int mgTime = millis();
  while(millis() - mgTime < 900){
    setMotor(&goalLift, 127);
  }
  setMotor(&goalLift, 0);
}

void raiseMG(){
  int mgTime = millis();
  while(millis() - mgTime < 1100){
    setMotor(&goalLift, -127);
  }
  setMotor(&goalLift, 0);
}

void waitForTasks(){
    bool lift = true;
    bool wheels = true;

    while(wheels == true || lift == true){
        lift = runLift;
        wheels = runWheels;

        delay(20);
    }
}

void autoOne(){
  //setSyncMoveTicks(FORWARD, 1000);
  lowerMG();
  setSyncMoveTicks(FORWARD, 1250);
  waitForTasks();
  raiseMG();
  inLiftDropPos();
  delay(1000);
  drop();

}


void autonomous() {
  autoOne();
}
