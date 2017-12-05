#include "main.h"

void stopDrive(){
  setMotor(&backLeft, 0);
  setMotor(&frontLeft, 0);
  setMotor(&backRight, 0);
  setMotor(&frontRight, 0);
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
    setMotor(&frontLeft, speed);
    setMotor(&backRight, speed);
    setMotor(&frontRight, speed);
    encoderAverage = (abs(encoderGet(leftQuad)) + abs(encoderGet(rightQuad))) / 2;
  }
  stopDrive();
}

void backwardTicks(int ticks, int speed){
  encoderReset(leftQuad);
  encoderReset(rightQuad);

  int encoderAverage = (abs(encoderGet(leftQuad)) + abs(encoderGet(rightQuad))) / 2;
  while(encoderAverage < ticks){
    setMotor(&backLeft, -speed);
    setMotor(&frontLeft, -speed);
    setMotor(&backRight, -speed);
    setMotor(&frontRight, -speed);
    encoderAverage = (abs(encoderGet(leftQuad)) + abs(encoderGet(rightQuad))) / 2;
  }
  stopDrive();
}

 void liftToTicks(int targetTick);

 void liftToInches(int targetInches);

 void openClaw(int speed){
   while(digitalRead(clawLimitSwitch) != 0){
     setMotor(&claw, speed);
   }
   setMotor(&claw, 0);
 }

 void closeClaw(int milliseconds, int speed){
   int now = millis();
   while( millis() - now < milliseconds){
     setMotor(&claw, -speed);
   }
   setMotor(&claw, 0);
 }

void autonomous() {

}
