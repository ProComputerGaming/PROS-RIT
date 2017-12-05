

typedef struct {
  int portNum;
  int speed;
  int requestedSpeed;
  bool reversed;
  bool slewOn;
  int slewRate;
} Motor;

Motor* motors[10];

void initMotor(Motor* motor, int port, bool reversed, bool slewOn);

Motor* getMotor(int portNum);

void setMotor(Motor* motor, int speed);

void changeMotor(Motor* motor);

void motorSlewTask(void *parameter);
