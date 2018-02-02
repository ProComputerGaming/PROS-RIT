#ifndef LIFT_H_
#define LIFT_H_

#define HIGH_HEIGHT 930
#define MID_HEIGHT 650
#define DOWN_HEIGHT 15

//LiftMonitorTask variables
bool runLift;
int liftTargetTicks;
int LIFT_POWER;

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
