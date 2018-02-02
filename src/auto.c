#include "main.h"

void stopDrive(){
  setMotor(&backLeft, 0);
  setMotor(&frontLeft, 0);
  setMotor(&backRight, 0);
  setMotor(&frontRight, 0);
}

void stopAll(){
  setMotor(&backLeft, 0);
  setMotor(&frontLeft, 0);
  setMotor(&backRight, 0);
  setMotor(&frontRight, 0);
  setMotor(&leftLiftY, 0);
  setMotor(&rightLiftY, 0);
  setMotor(&leftFour, 0);
  setMotor(&rightFour, 0);
  setMotor(&claw, 0);
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
     setMotor(&leftLiftY, -speed);
     setMotor(&rightLiftY, -speed);
     delay(milliseconds);
     setMotor(&leftLiftY, 0);
     setMotor(&rightLiftY, 0);
   }else{
     setMotor(&leftLiftY, speed);
     setMotor(&rightLiftY, speed);
     delay(milliseconds);
     setMotor(&leftLiftY, 50);
     setMotor(&rightLiftY, 50);

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
  setMotor(&claw, speed);
  delay(milliseconds);
  setMotor(&claw, 0);
 }

 void pickupCone(int milliseconds, int speed){
   setMotor(&claw, -speed);
   delay(milliseconds);
   setMotor(&claw, 0);
 }

void autoOne(){

/*
Plan
  forwardTicks(250, 127);
//Forward until Red/Blue && Lower MG
//Load PL

for(int i = 3; i <= 1; i++){

//Forward
forwardTicks(250, 127);
//Pickup/Place
}
//Repeat steps 3 & 4 three times
//Backward until white
backwardTicks(250, 127);
//Backward until white
backwardTicks(250, 127);
//CCW Rotate 180
turnLeft(180, 127);
//Forward
forwardTicks(250, 127);
//CCW Rotate 45
turnLeft(45, 127);
//Lower MG
//Backwards until white
//CW Rotate
turnRight(90, 127);
//Forward
forwardTicks(250, 127);
//CW Rotate 90
turnRight(90, 127);
//Forward
forwardTicks(250, 127);
//Pick up cone
//Forward
forwardTicks(250, 127);
//Raise MG
//Place cone
//Rotate CW 180
turnRight(90, 127);
*/

  /*
  Mike's code
  liftFourTime(2500, 127, false);
  delay(500);
  liftScissorTime(750, 127, false);
  forwardTicks(250, 127);
  delay(500);
  liftFourTime(500, 127, true);
  dropCone(750, 127);
  delay(500);
  liftFourTime(1000, 127, false);
  delay(500);
  backwardTicks(250, 127);
  */
  stopAll();
}

void autonomous() {
  autoOne();
}
