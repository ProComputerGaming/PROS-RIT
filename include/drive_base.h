#ifndef DRIVE_BASE_H_
#define DRIVE_BASE_H_

//Drive Motors
#define BACK_RIGHT_PORT 3
#define FRONT_LEFT_PORT 4
#define BACK_LEFT_PORT 5
#define FRONT_RIGHT_PORT 2

//Quad Encoders (Digital)
#define leftQuadBottom 3
#define leftQuadTop 4
#define rightQuadBottom 1
#define rightQuadTop 2

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
void setSyncMove(enum WheelDirection d,int targetTicks, bool enableGyro);
void dLeftBackward();
void dLeftForward();
void dRightBackward();
void dRightForward();
void analogDrive();
void stopLeft();
void stopRight();
void stopDrive();

#endif
