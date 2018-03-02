#ifndef INTAKE_H_
#define INTAKE_H_

#include <API.h>

#define stackPos 450
#define suckPos 3350

#define DELTA_TIME 50
#define DELTA_TIME_IN_SECONDS DELTA_TIME/1000

//ClawMonitorTask variables
bool runFinger;
int CLAW_POWER;

void intakePID(void *parameter);
void computeLeft();
void closeClaw(int millis);
void openClaw();
void suck();
void drop();

#endif
