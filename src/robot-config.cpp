#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen.
brain  Brain;

//The motor constructor takes motors as (port, ratio, reversed), so for example
//motor LeftFront = motor(PORT1, ratio6_1, false);

//Add your devices below, and don't forget to do the same in robot-config.h:

motor testMotor = motor(PORT1, ratio6_1, true); 

motor frontLeft = motor(PORT1, ratio6_1, true); 
motor MiddleLeft = motor(PORT1, ratio6_1, true);
motor UpsidedownLeft = motor(PORT1, ratio6_1, false);

motor_group chassisLeft = motor_group(frontLeft, MiddleLeft, UpsidedownLeft); 

motor frontRight = motor(PORT1, ratio6_1, true); 
motor MiddleRight = motor(PORT1, ratio6_1, true);
motor UpsidedownRight = motor(PORT1, ratio6_1, false);

motor_group chassisRight = motor_group(frontRight, MiddleRight, UpsidedownRight);

motor Arm1 = motor(PORT1, ratio6_1, true);
motor Arm2 = motor(PORT1, ratio6_1, false);

motor_group Arms = motor_group(Arm1, Arm2);

motor Intake = motor(PORT1, ratio6_1, true);

digital_out clampA = digital_out(Brain.ThreeWirePort.A); 
digital_out clampB = digital_out(Brain.ThreeWirePort.B); 

digital_out sweeperC = digital_out(Brain.ThreeWirePort.C); 
digital_out sweeperD = digital_out(Brain.ThreeWirePort.D); 


controller Controller; 
void vexcodeInit( void ) {
  // nothing to initialize
}