#ifndef CLAW_H_
#define CLAW_H_

#include <API.h>
#include "Motor.h"

//Claw Motors
#define CLAW_PORT 1

Motor intake;

//ClawMonitorTask variables
bool runFinger;
int CLAW_POWER;

TaskHandle clawMonitorHandle;

void clawMonitorTask(void *parameter);
void closeClaw(int millis);
void openClaw();

#endif
