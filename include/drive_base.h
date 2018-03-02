#ifndef DRIVE_BASE_H_
#define DRIVE_BASE_H_

#define ANALOG_DEADZONE 10

//Enumeration defining autonomous movement direction
enum WheelDirection{
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT,
};

enum WheelDirection wheelDir;

//WheelMonitorTask variables
int wheelTargetTicks;
bool runWheels;
int DRIVEBASE_POWER;


void wheelMonitorTask(void *parameter);
void setSyncMoveTicks(enum WheelDirection d, int targetTicks);
void dLeftBackward();
void dLeftForward();
void dRightBackward();
void dRightForward();
void analogDrive();
void stopLeft();
void stopRight();
void stopDrive();

#endif
