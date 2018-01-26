#ifndef LIFT_H_
#define LIFT_H_

#include <API.h>
#include "Motor.h"

//Lift Motors
#define LEFT_LIFT_PORT 6
#define RIGHT_LIFT_PORT 7
#define LEFT_FOUR_PORT 9
#define RIGHT_FOUR_PORT 8

//Digital Sensors
#define LIFT_QUAD_PORT 1

#define HIGH_HEIGHT 930
#define MID_HEIGHT 650
#define DOWN_HEIGHT 15

Motor liftOne;
Motor liftTwo;
Motor liftThree;

//Quadrature Encoders
Encoder liftQuad;

//LiftMonitorTask variables
bool runLift;
int liftTargetTicks;
int LIFT_POWER;

TaskHandle liftMonitorHandle;

void liftMonitorTask(void *parameter);
void liftPID(void *parameter);
void setSyncLift(int targetTicks);
void dLift(bool down);
void stopLift();

#endif
