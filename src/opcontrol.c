#include "main.h"

void operatorControl() {
	int clawPower = 127;
	int liftPower = 127;
	int fourPower = 127;
	while (1) {

		if(joystickGetDigital(1, 6, JOY_UP)){
			if(digitalRead(leftScissorSwitch) == 1)
				setMotor(&leftLiftY, liftPower);
			else
				setMotor(&leftLiftY, 0);

			if(digitalRead(rightScissorSwitch) == 1)
				setMotor(&rightLiftY, (liftPower - 25));
			else
				setMotor(&rightLiftY, 0);
		}else if(joystickGetDigital(1, 6, JOY_DOWN)){
			setMotor(&leftLiftY, -liftPower);
			setMotor(&rightLiftY, -(liftPower - 25));
		}else{
			setMotor(&leftLiftY, 0);
			setMotor(&rightLiftY, 0);
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

		// if(joystickGetDigital(1, 8, JOY_UP)){
		// 	digitalWrite(leftSolenoid, 1);
		// 	digitalWrite(rightSolenoid, 1);
		// }else if(joystickGetDigital(1, 8, JOY_DOWN)){
		// 	digitalWrite(leftSolenoid, 0);
		// 	digitalWrite(rightSolenoid, 0);
		// }

		if(joystickGetDigital(1, 8, JOY_RIGHT))
			autoOne();


		delay(20);
	}
}
