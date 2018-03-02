#include "main.h"



void suck(){
	int intakeTime = millis();
  encoderReset(intakeQuad);
  while(abs(encoderGet(intakeQuad)) < 180){
		if(millis() - intakeTime > 1000)
			break;
    setMotor(&intake, 127);
  }
  setMotor(&intake, 0);
}

void drop(){
	int intakeTime = millis();
  encoderReset(intakeQuad);
  while(abs(encoderGet(intakeQuad)) < 180){
		if(millis() - intakeTime > 1000)
			break;
    setMotor(&intake, -127);
  }
  setMotor(&intake, 0);
}
