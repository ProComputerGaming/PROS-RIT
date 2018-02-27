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
			setSyncLift(abs(encoderGet(leftLiftQuad)) + 5);
			// setMotor(&leftFour, fourPower);
			// setMotor(&rightFour, fourPower);
		}else if(joystickGetDigital(1, 5, JOY_DOWN)){
			setSyncLift(abs(encoderGet(leftLiftQuad)) - 5);
			// setMotor(&leftFour, -fourPower);
			// setMotor(&rightFour, -fourPower);
		}else{
			//runLift = false;
			setMotor(&leftFour, 0);
			setMotor(&rightFour, 0);
		}

		analogDrive();

		if(joystickGetDigital(1, 8, JOY_UP))
			setMotor(&goalLift, 127);
		else if(joystickGetDigital(1, 8, JOY_DOWN)){
			setMotor(&goalLift, -127);
		}else{
			setMotor(&goalLift, 0);
		}


		delay(20);
	}
}
