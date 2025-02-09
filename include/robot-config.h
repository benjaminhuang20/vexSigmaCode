using namespace vex;

extern brain Brain;

//To set up a motor called LeftFront here, you'd use
//extern motor LeftFront;

//Add your devices below, and don't forget to do the same in robot-config.cpp:

extern motor testMotor;

extern motor frontLeft; 
extern motor MiddleLeft;
extern motor UpsidedownLeft;

extern motor_group chassisLeft; 

extern motor frontRight; 
extern motor MiddleRight;
extern motor UpsidedownRight;

extern motor_group chassisRight;

extern motor Arm1;
extern motor Arm2;

extern motor_group Arms;

extern motor Intake1;
extern motor Intake2;

extern digital_out clampA; 
extern digital_out clampB; 

extern digital_out sweeperA; 
extern digital_out sweeperB;

extern controller Controller; 

void  vexcodeInit( void );