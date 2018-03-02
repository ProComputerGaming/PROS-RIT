#include "main.h"

void operatorControl() {

	int lastTime = millis();
	while (1) {
		if(millis() - lastTime > 1000){
			printf("Intake Quad: %d\n", encoderGet(intakeQuad));
			printf("Left Drive Quad: %d\n", encoderGet(leftQuad));
			printf("Right Drive Quad: %d\n", encoderGet(rightQuad));
			printf("Left Lift Quad: %d\n", encoderGet(leftLiftQuad));
			printf("Right Lift Quad: %d\n", encoderGet(rightLiftQuad));
			printf("Right Intake Pot: %d\n", analogRead(rightIntakeLiftPot));
			lastTime = millis();
		}
		if(joystickGetDigital(1, 6, JOY_UP)){

				setMotor(&leftInLift, INTAKE_LIFT_POWER);
				setMotor(&rightInLift, INTAKE_LIFT_POWER);
		}else if(joystickGetDigital(1, 6, JOY_DOWN)){

			setMotor(&leftInLift, -INTAKE_LIFT_POWER);
			setMotor(&rightInLift, -INTAKE_LIFT_POWER);
		}else{
				setMotor(&leftInLift, 0);
				setMotor(&rightInLift, 0);

		}

		if(joystickGetDigital(1, 7, JOY_UP)){
			suck();
		}else if(joystickGetDigital(1, 7, JOY_DOWN)){
			drop();
		}

		if(encoderGet(leftLiftQuad) < encoderGet(rightLiftQuad)){
			leftOffset = SYNCHRONOUS_POWER_OFFSET;
			rightOffset = 0;
		}else if(encoderGet(rightLiftQuad) < encoderGet(leftLiftQuad)){
			rightOffset = SYNCHRONOUS_POWER_OFFSET;
			leftOffset = 0;
		}else{
			rightOffset = 0;
			leftOffset = 0;
		}

		if(joystickGetDigital(1, 5, JOY_UP)){
			dLeftLiftUp();
			dRightLiftUp();
		}else if(joystickGetDigital(1, 5, JOY_DOWN)){
			dLeftLiftDown();
			dRightLiftDown();
		}else{
			stopLift();
		}

		analogDrive();

		if(joystickGetDigital(1, 8, JOY_RIGHT)){
			autoOne();
		}

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
