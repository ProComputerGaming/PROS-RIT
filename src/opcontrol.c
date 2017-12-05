#include "main.h"

void operatorControl() {
	int clawPower = 127;
	int liftPower = 80;
	while (1) {

		if(joystickGetDigital(1, 6, JOY_UP)){
			setMotor(&leftLiftY, liftPower);
			setMotor(&rightLiftY, liftPower);
		}else if(joystickGetDigital(1, 6, JOY_DOWN)){
			setMotor(&leftLiftY, -liftPower);
			setMotor(&rightLiftY, -liftPower);
		}else{
			setMotor(&leftLiftY, 0);
			setMotor(&rightLiftY, 0);
		}

		if(joystickGetDigital(1, 5, JOY_UP)){
			setMotor(&claw, clawPower);
		}else if(joystickGetDigital(1, 5, JOY_DOWN)){
			setMotor(&claw, -clawPower);
		}else{
			setMotor(&claw, 0);
		}

		if(joystickGetDigital(1, 7, JOY_UP)){
			digitalWrite(leftSolenoid, 1);
			digitalWrite(rightSolenoid, 1);
		}else if(joystickGetDigital(1, 7, JOY_DOWN)){
			digitalWrite(leftSolenoid, 0);
			digitalWrite(rightSolenoid, 0);
		}

		int leftPower = joystickGetAnalog(1, 3);
		int rightPower = joystickGetAnalog(1, 2);
		if(abs(leftPower) < JOYSTICK_DEADZONE)
			leftPower = 0;
		if(abs(rightPower) < JOYSTICK_DEADZONE)
			rightPower = 0;
		setMotor(&backLeft, leftPower);
		setMotor(&frontLeft, leftPower);
		setMotor(&backRight, -rightPower);
		setMotor(&frontRight, -rightPower);
		delay(20);
		printf("Lift Potentiometer Left: %d", analogRead(leftLiftPot));
		printf("Lift Potentiometer Right: %d", analogRead(rightLiftPot));
	}
}
