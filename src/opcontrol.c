#include "main.h"

void operatorControl() {
	int clawPower = 127;
	int liftPower = 127;
	int fourPower = 127;
	while (1) {

		if(joystickGetDigital(1, 6, JOY_UP)){
				setMotor(&leftInLift, liftPower);
				setMotor(&rightInLift, liftPower);
		}else if(joystickGetDigital(1, 6, JOY_DOWN)){
			setMotor(&leftInLift, -liftPower);
			setMotor(&rightInLift, -liftPower);
		}else{
			setMotor(&leftInLift, 0);
			setMotor(&rightInLift, 0);
		}

		if(joystickGetDigital(1, 7, JOY_UP)){
			setMotor(&claw, -clawPower);
		}else if(joystickGetDigital(1, 7, JOY_DOWN)){
			setMotor(&claw, clawPower);
		}else{
			setMotor(&claw, 0);
		}

		if(joystickGetDigital(1, 5, JOY_UP)){
			setMotor(&leftFour, fourPower);
			setMotor(&rightFour, fourPower);
		}else if(joystickGetDigital(1, 5, JOY_DOWN)){
			setMotor(&leftFour, -fourPower);
			setMotor(&rightFour, -fourPower);
		}else{
			setMotor(&leftFour, 0);
			setMotor(&rightFour, 0);
		}

		analogDrive();

		if(joystickGetDigital(1, 8, JOY_RIGHT))
			autoOne();


		delay(20);
	}
}
