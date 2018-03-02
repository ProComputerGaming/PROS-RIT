#ifndef LIFT_H_
#define LIFT_H_

#define HIGH_HEIGHT 930
#define MID_HEIGHT 650
#define DOWN_HEIGHT 15
#define SYNCHRONOUS_POWER_OFFSET 20
#define INTAKE_LIFT_POWER 127
#define LIFT_POWER 80
#define LIFT_DEADZONE 10

//LiftMonitorTask variables
bool runLift;
int liftTargetTicks;
int rightOffset;
int leftOffset;

void liftMonitorTask(void *parameter);
void liftPID(void *parameter);
void setSyncLift(int targetTicks);
void dLeftLiftUp();
void dLeftLiftDown();
void dRightLiftUp();
void dRightLiftDown();
void stopLeftLift();
void stopRightLift();
void stopLift();

#endif
