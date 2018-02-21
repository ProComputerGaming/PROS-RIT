/** @file main.h
 * @brief Header file for global functions
 *
 * Any experienced C or C++ programmer knows the importance of header files. For those who
 * do not, a header file allows multiple files to reference functions in other files without
 * necessarily having to see the code (and therefore causing a multiple definition). To make
 * a function in "opcontrol.c", "auto.c", "main.c", or any other C file visible to the core
 * implementation files, prototype it here.
 *
 * This file is included by default in the predefined stubs in each VEX Cortex PROS Project.
 *
 * Copyright (c) 2011-2016, Purdue University ACM SIGBots.
 * All rights reserved.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#ifndef MAIN_H_

// This prevents multiple inclusion, which isn't bad for this file but is good practice
#define MAIN_H_

#include <API.h>
#include "Motor.h"
#include "lift.h"
#include "intake.h"
#include "drive_base.h"
#include "auto.h"

// Allow usage of this file in C++ programs
#ifdef __cplusplus
extern "C" {
#endif

#define JOYSTICK_DEADZONE 10

//Quadrature math constants
#define WHEEL_DIAM_INCHES 4.25
#define BOT_DIAM_INCHES 15
#define PI 3.141592
#define QUAD_TICKS_PER_REV 360

//Quad Encoders (Digital)
#define leftQuadBottom 7
#define leftQuadTop 8
#define rightQuadBottom 1
#define rightQuadTop 2
#define leftLiftQuadTop 5
#define leftLiftQuadBottom 6
#define rightLiftQuadBottom 3
#define rightLiftQuadTop 4


#define leftScissorSwitch 7
#define rightScissorSwitch 8


#define leftLiftPot 1
#define rightLiftPot 2

#define leftSolenoid 5
#define rightSolenoid 6

#define REVERSED true
#define NOT_REVERSED false
#define SLEW_ON true
#define SLEW_OFF false
#define DEFAULT_SLEW_RATE 15
#define SLEW_DELAY 25

#define CLAW_POWER 127

Motor backLeft;
Motor frontLeft;
Motor backRight;
Motor frontRight;
Motor leftInLift;
Motor rightInLift;
Motor leftFour;
Motor rightFour;
Motor claw;

Encoder leftQuad;
Encoder rightQuad;

Encoder leftLiftQuad;
Encoder rightLiftQuad;

int fullTurnTicks;

TaskHandle motorSlewHandle;
TaskHandle wheelMonitorHandle;
TaskHandle liftMonitorHandle;

void autonomous();

void initializeIO();

void initialize();

void operatorControl();

// End C++ export structure
#ifdef __cplusplus
}
#endif

#endif
