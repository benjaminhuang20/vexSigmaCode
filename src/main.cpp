#include "vex.h"

using namespace vex;
competition Competition;

/*---------------------------------------------------------------------------*/
/*                             VEXcode Config                                */
/*                                                                           */
/*  Before you do anything else, start by configuring your motors and        */
/*  sensors. In VEXcode Pro V5, you can do this using the graphical          */
/*  configurer port icon at the top right. In the VSCode extension, you'll   */
/*  need to go to robot-config.cpp and robot-config.h and create the         */
/*  motors yourself by following the style shown. All motors must be         */
/*  properly reversed, meaning the drive should drive forward when all       */
/*  motors spin forward.                                                     */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*                             JAR-Template Config                           */
/*                                                                           */
/*  Where all the magic happens. Follow the instructions below to input      */
/*  all the physical constants and values for your robot. You should         */
/*  already have configured your motors.                                     */
/*---------------------------------------------------------------------------*/

Drive chassis(

//Pick your drive setup from the list below:
//ZERO_TRACKER_NO_ODOM
//ZERO_TRACKER_ODOM
//TANK_ONE_FORWARD_ENCODER
//TANK_ONE_FORWARD_ROTATION
//TANK_ONE_SIDEWAYS_ENCODER
//TANK_ONE_SIDEWAYS_ROTATION
//TANK_TWO_ENCODER
//TANK_TWO_ROTATION
//HOLONOMIC_TWO_ENCODER
//HOLONOMIC_TWO_ROTATION
//
//Write it here:
ZERO_TRACKER_NO_ODOM,

//Add the names of your Drive motors into the motor groups below, separated by commas, i.e. motor_group(Motor1,Motor2,Motor3).
//You will input whatever motor names you chose when you configured your robot using the sidebar configurer, they don't have to be "Motor1" and "Motor2".

//Left Motors:
// motor_group(),
// chassisLeft,
motor_group(frontLeft, MiddleLeft, UpsidedownLeft),

//Right Motors:
// motor_group(),

motor_group(frontRight, MiddleRight, UpsidedownRight),

//Specify the PORT NUMBER of your inertial sensor, in PORT format (i.e. "PORT1", not simply "1"):
PORT1,

//Input your wheel diameter. (4" omnis are actually closer to 4.125"):
3.25,

//External ratio, must be in decimal, in the format of input teeth/output teeth.
//If your motor has an 84-tooth gear and your wheel has a 60-tooth gear, this value will be 1.4.
//If the motor drives the wheel directly, this value is 1:
0.6,

//Gyro scale, this is what your gyro reads when you spin the robot 360 degrees.
//For most cases 360 will do fine here, but this scale factor can be very helpful when precision is necessary.
360,

/*---------------------------------------------------------------------------*/
/*                                  PAUSE!                                   */
/*                                                                           */
/*  The rest of the drive constructor is for robots using POSITION TRACKING. */
/*  If you are not using position tracking, leave the rest of the values as  */
/*  they are.                                                                */
/*---------------------------------------------------------------------------*/

//If you are using ZERO_TRACKER_ODOM, you ONLY need to adjust the FORWARD TRACKER CENTER DISTANCE.

//FOR HOLONOMIC DRIVES ONLY: Input your drive motors by position. This is only necessary for holonomic drives, otherwise this section can be left alone.
//LF:      //RF:    
PORT1,     -PORT2,

//LB:      //RB: 
PORT3,     -PORT4,

//If you are using position tracking, this is the Forward Tracker port (the tracker which runs parallel to the direction of the chassis).
//If this is a rotation sensor, enter it in "PORT1" format, inputting the port below.
//If this is an encoder, enter the port as an integer. Triport A will be a "1", Triport B will be a "2", etc.
3,

//Input the Forward Tracker diameter (reverse it to make the direction switch):
2.75,

//Input Forward Tracker center distance (a positive distance corresponds to a tracker on the right side of the robot, negative is left.)
//For a zero tracker tank drive with odom, put the positive distance from the center of the robot to the right side of the drive.
//This distance is in inches:
-2,

//Input the Sideways Tracker Port, following the same steps as the Forward Tracker Port:
1,

//Sideways tracker diameter (reverse to make the direction switch):
-2.75,

//Sideways tracker center distance (positive distance is behind the center of the robot, negative is in front):
5.5

);

int current_auton_selection = 0;
bool auto_started = false;

/**
 * Function before autonomous. It prints the current auton number on the screen
 * and tapping the screen cycles the selected auton by 1. Add anything else you
 * may need, like resetting pneumatic components. You can rename these autons to
 * be more descriptive, if you like.
 */


void pre_auton() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  default_constants();
  Arm1.resetPosition();

  while(!auto_started){
    // Brain.Screen.clearScreen();
    // Brain.Screen.printAt(5, 20, "JAR Template v1.2.0");
    // Brain.Screen.printAt(5, 40, "Battery Percentage:");
    // Brain.Screen.printAt(5, 60, "%d", Brain.Battery.capacity());
    // Brain.Screen.printAt(5, 80, "Chassis Heading Reading:");
    // Brain.Screen.printAt(5, 100, "%f", chassis.get_absolute_heading());
    // Brain.Screen.printAt(5, 120, "Selected Auton:");
    switch(current_auton_selection){
      // case 0:
      //   Brain.Screen.printAt(5, 140, "Auton 1");
      //   break;
      // case 1:
      //   Brain.Screen.printAt(5, 140, "Auton 2");
      //   break;
      // case 2:
      //   Brain.Screen.printAt(5, 140, "Auton 3");
      //   break;
      // case 3:
      //   Brain.Screen.printAt(5, 140, "Auton 4");
      //   break;
      // case 4:
      //   Brain.Screen.printAt(5, 140, "Auton 5");
      //   break;
      // case 5:
      //   Brain.Screen.printAt(5, 140, "Auton 6");
      //   break;
      // case 6:
      //   Brain.Screen.printAt(5, 140, "Auton 7");
      //   break;
      // case 7:
      //   Brain.Screen.printAt(5, 140, "Auton 8");
      //   break;
    }
    if(Brain.Screen.pressing()){
      while(Brain.Screen.pressing()) {}
      current_auton_selection ++;
    } else if (current_auton_selection == 8){
      current_auton_selection = 0;
    }
    task::sleep(10);
  }

//yay
}

/**
 * Auton function, which runs the selected auton. Case 0 is the default,
 * and will run in the brain screen goes untouched during preauton. Replace
 * drive_test(), for example, with your own auton function you created in
 * autons.cpp and declared in autons.h.
 */

void autonomous(void) {
  auto_started = true;
  switch(current_auton_selection){ 
    case 0:
      drive_test();
      break;
    case 1:         
      drive_test();
      break;
    case 2:
      turn_test();
      break;
    case 3:
      swing_test();
      break;
    case 4:
      full_test();
      break;
    case 5:
      odom_test();
      break;
    case 6:
      tank_odom_test();
      break;
    case 7:
      holonomic_odom_test();
      break;
 }
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
  
int ControllerUpdate;
int OrderedUpdate;

void controllerPrint(int screenLine, std::string controllerText) {
  OrderedUpdate = OrderedUpdate + 2;
  if (ControllerUpdate == OrderedUpdate) {
  Controller.Screen.setCursor(screenLine, 1);
  Controller.Screen.print(controllerText.c_str());
  }
}







void usercontrol(void) {
  // User control code here, inside the loop
  
  // very useful variables, luckily cole can't delete them (he doesn't have edit access LLLLLLLLLLLL)
  bool ifTheButtonWithTheNameAIsPressedThisVariableActsAsAToggleSoItDoesntFireMultipleTimesThisTechniqueIsSeenInVERYSQUISHYSEALSScratchGamesGoToHisProfileIfThisVariableDoesntExplainWellEnoughAlthoughVERYSQUISHYSEALsProfileDoesNotActuallyExplainItAndYouNeedToGoIntoHisScratchGameWhichHasNoCommentsAndShortVariableNamesAndFindItBecauseYay;
  bool ifTheButtonWithTheNameXIsPressedThisVariableActsAsAToggleSoItDoesntFireMultipleTimesThisTechniqueIsSeenInVERYSQUISHYSEALSScratchGamesGoToHisProfileIfThisVariableDoesntExplainWellEnoughAlthoughVERYSQUISHYSEALsProfileDoesNotActuallyExplainItAndYouNeedToGoIntoHisScratchGameWhichHasNoCommentsAndShortVariableNamesAndFindItBecauseYay;
  bool ifTheButtonWithTheNameR2IsPressedThisVariableActsAsAToggleSoItDoesntFireMultipleTimesThisTechniqueIsSeenInVERYSQUISHYSEALSScratchGamesGoToHisProfileIfThisVariableDoesntExplainWellEnoughAlthoughVERYSQUISHYSEALsProfileDoesNotActuallyExplainItAndYouNeedToGoIntoHisScratchGameWhichHasNoCommentsAndShortVariableNamesAndFindItBecauseYay;
  bool ifTheButtonWithTheNameL2IsPressedThisVariableActsAsAToggleSoItDoesntFireMultipleTimesThisTechniqueIsSeenInVERYSQUISHYSEALSScratchGamesGoToHisProfileIfThisVariableDoesntExplainWellEnoughAlthoughVERYSQUISHYSEALsProfileDoesNotActuallyExplainItAndYouNeedToGoIntoHisScratchGameWhichHasNoCommentsAndShortVariableNamesAndFindItBecauseYay;
  bool ifTheButtonWithTheNameYAndBAreBothPressedThisVariableActsAsAToggleSoItDoesntFireMultipleTimesThisTechniqueIsSeenInVERYSQUISHYSEALSScratchGamesGoToHisProfileIfThisVariableDoesntExplainWellEnoughAlthoughVERYSQUISHYSEALsProfileDoesNotActuallyExplainItAndYouNeedToGoIntoHisScratchGameWhichHasNoCommentsAndShortVariableNamesAndFindItBecauseYay;


  bool SlowMode = false;
  // bool DoinkerOn;
  bool ToggleA = false, ToggleX = false, ToggleR2 = false, ToggleL2 = false;
  int ArmAngle = 0;
  int ArmAngleFinal = 0;
  // int arm1Start = Arm1.
  // , arm2Start; 

  
  // clampUpdate;
  Brain.Screen.setCursor(3,1);
  Brain.Screen.print("Normal Mode yay fun time");
  Brain.Screen.setCursor(4,1);
  Brain.Screen.print("Clamp Retracted");
  bool ClampOn = true;
  sweeperA = true;
  sweeperB = false;
  clampA = true;
  clampB = false;


  while (1) {
    // MAIN LOOOOOOOOP (SWEAL THE SEAL IS THE BESTEST SEAL COLE DID YOU SEE THIS)
    // ControllerUpdate++;
    // if(ControllerUpdate == 20){
    //   ControllerUpdate = 0;
    // OrderedUpdate = 0;
    // }
    if(SlowMode){

      // Brain.Screen.print("Slow Mode");
      // controllerPrint(2,"Slow Mode");
      chassis.control_arcade(.2);
      
    }else{

      // Brain.Screen.print("Normal Mode");
      // controllerPrint(2,"Normal Mode");
      chassis.control_arcade(1);
    }
   


    // chassis.control_arcade(1);
    // // chassisLeft.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct); 

    // // frontRight.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct); 
    // // pls work

    
    
    Brain.Screen.setCursor(1,1);
    Brain.Screen.clearLine(1); 
    Brain.Screen.print("Battery: "), Brain.Screen.print(Brain.Battery.capacity());
    // Brain.Screen.setCursor(2,1);
    // Brain.Screen.print("- Functions -");
    // Brain.Screen.setCursor(3,1);



  
  




    if(Controller.ButtonR2.pressing()){ //If you are confused by this pls visit https://scratch.mit.edu/projects/1122100301/ for demo
      if(ToggleR2 == true){
        clampA = !clampA;
        clampB = !clampB;
        ClampOn =!ClampOn;
        Brain.Screen.setCursor(4,1);
        Controller.Screen.setCursor(2,1);
        if (ClampOn == true){
          Brain.Screen.print("Clamp Retracted");
          Controller.Screen.print("Clamp Retracted");
          
        }else{
          Brain.Screen.clearLine(4,1);
          Controller.Screen.clearLine(2);
          Brain.Screen.print("Clamp Extended");
          Controller.Screen.print("Clamp Extended");
        }
        // clampUpdate;
        ToggleR2 = false;
      }
    }else{
      ToggleR2 = true;
    }

   
    //set clamp here

    if(Controller.ButtonX.pressing()){ //If you are confused by this pls visit https://scratch.mit.edu/projects/1122100301/ for demo
      if(ToggleX){
        sweeperA = !sweeperA;
        sweeperB = !sweeperB;
        Brain.Screen.print("Doinker Toggled");
        ToggleX = false;
      }
    }else{
      ToggleX = true;
    }

    if(Controller.ButtonL2.pressing()){ //If you are confused by this pls visit https://scratch.mit.edu/projects/1122100301/ for demo
    if(ToggleL2){
      ArmAngle++;
      if(ArmAngle % 3 == 0){
        // Arm1.spinToPosition(0, rotationUnits::deg, 50, vex::velocityUnits::pct);
        Arm2.spinToPosition(0, rotationUnits::deg, 50, vex::velocityUnits::pct);
        // Arm2.spinToPosition(0, rotationUnits::deg, 50, vex::velocityUnits::pct);
        
 
       
      }else if(ArmAngle % 3 == 1){
        // Arm1.spinToPosition(105, rotationUnits::deg, 50, vex::velocityUnits::pct);
        Arm2.spinToPosition(100.5, rotationUnits::deg, 50, vex::velocityUnits::pct);
        // Arm2.spinToPosition(110, rotationUnits::deg, 50, vex::velocityUnits::pct);
      }else{
        // Arm1.spinToPosition(750, rotationUnits::deg, 50, vex::velocityUnits::pct);
        Arm2.spinToPosition(750, rotationUnits::deg, 50, vex::velocityUnits::pct);
        // Arm2.spinToPosition(750, rotationUnits::deg, 50, vex::velocityUnits::pct);
      }
      Brain.Screen.print("Arm Toggled");
      ToggleL2 = false;
      
    }
    }else{
      ToggleL2 = true;
    }

    if(Controller.ButtonA.pressing()){ //If you are confused by this pls visit https://scratch.mit.edu/projects/1122100301/ for demo
    if(ToggleA){
      SlowMode = !SlowMode;
      ToggleA = false;
      Brain.Screen.setCursor(3,1); 
      Brain.Screen.clearLine(3);  
      Controller.Screen.clearLine(1);
      Controller.Screen.setCursor(1,1); 
      if(SlowMode){
        Brain.Screen.print("Slow Mode");
        Controller.Screen.print("Slow Mode");
      } else{
        Brain.Screen.print("Normal Mode");
        Controller.Screen.print("Normal Mode");
      }
      
      
    }

    }else{
      ToggleA = true;
    }
    
    Brain.Screen.setCursor(5,1);
    

    int IntakeSpeed = (Controller.ButtonR1.pressing() + Controller.ButtonL1.pressing()* (-1)) * 1000;
    // int ArmSpeed = (Controller.ButtonY.pressing() + Controller.ButtonB.pressing()* (-1)) * 30;
    // ArmAngleFinal = ArmAngleFinal + ArmSpeed;
    Intake.spin(directionType::fwd, IntakeSpeed, vex::velocityUnits::pct);
    // Arm1.spinToPosition(ArmAngleFinal, rotationUnits::deg, 50, vex::velocityUnits::pct);

    

    // testMotor.spin(vex::directionType::fwd, Controller.Axis1.position(percent), vex::velocityUnits::pct);; 

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }

}
//big men are better
//why won't it work
//big man work pls