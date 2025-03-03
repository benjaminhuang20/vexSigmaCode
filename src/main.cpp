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

    // Pick your drive setup from the list below:
    // ZERO_TRACKER_NO_ODOM
    // ZERO_TRACKER_ODOM
    // TANK_ONE_FORWARD_ENCODER
    // TANK_ONE_FORWARD_ROTATION
    // TANK_ONE_SIDEWAYS_ENCODER
    // TANK_ONE_SIDEWAYS_ROTATION
    // TANK_TWO_ENCODER
    // TANK_TWO_ROTATION
    // HOLONOMIC_TWO_ENCODER
    // HOLONOMIC_TWO_ROTATION
    //
    // Write it here:
    ZERO_TRACKER_NO_ODOM,

    // Add the names of your Drive motors into the motor groups below, separated by commas, i.e. motor_group(Motor1,Motor2,Motor3).
    // You will input whatever motor names you chose when you configured your robot using the sidebar configurer, they don't have to be "Motor1" and "Motor2".

    // Left Motors:
    //  motor_group(),
    //  chassisLeft,
    motor_group(frontLeft, MiddleLeft, UpsidedownLeft),

    // Right Motors:
    //  motor_group(),

    motor_group(frontRight, MiddleRight, UpsidedownRight),

    // Specify the PORT NUMBER of your inertial sensor, in PORT format (i.e. "PORT1", not simply "1"):
    PORT18,

    // Input your wheel diameter. (4" omnis are actually closer to 4.125"):
    3.25,

    // External ratio, must be in decimal, in the format of input teeth/output teeth.
    // If your motor has an 84-tooth gear and your wheel has a 60-tooth gear, this value will be 1.4.
    // If the motor drives the wheel directly, this value is 1:
    0.6,

    // Gyro scale, this is what your gyro reads when you spin the robot 360 degrees.
    // For most cases 360 will do fine here, but this scale factor can be very helpful when precision is necessary.
    360,

    /*---------------------------------------------------------------------------*/
    /*                                  PAUSE!                                   */
    /*                                                                           */
    /*  The rest of the drive constructor is for robots using POSITION TRACKING. */
    /*  If you are not using position tracking, leave the rest of the values as  */
    /*  they are.                                                                */
    /*---------------------------------------------------------------------------*/

    // If you are using ZERO_TRACKER_ODOM, you ONLY need to adjust the FORWARD TRACKER CENTER DISTANCE.

    // FOR HOLONOMIC DRIVES ONLY: Input your drive motors by position. This is only necessary for holonomic drives, otherwise this section can be left alone.
    // LF:      //RF:
    PORT1, -PORT2,

    // LB:      //RB:
    PORT3, -PORT4,

    // If you are using position tracking, this is the Forward Tracker port (the tracker which runs parallel to the direction of the chassis).
    // If this is a rotation sensor, enter it in "PORT1" format, inputting the port below.
    // If this is an encoder, enter the port as an integer. Triport A will be a "1", Triport B will be a "2", etc.
    3,

    // Input the Forward Tracker diameter (reverse it to make the direction switch):
    2.75,

    // Input Forward Tracker center distance (a positive distance corresponds to a tracker on the right side of the robot, negative is left.)
    // For a zero tracker tank drive with odom, put the positive distance from the center of the robot to the right side of the drive.
    // This distance is in inches:
    -2,

    // Input the Sideways Tracker Port, following the same steps as the Forward Tracker Port:
    1,

    // Sideways tracker diameter (reverse to make the direction switch):
    -2.75,

    // Sideways tracker center distance (positive distance is behind the center of the robot, negative is in front):
    5.5

);

int current_auton_selection = 5;
bool auto_started = false;

/**
 * Function before autonomous. It prints the current auton number on the screen
 * and tapping the screen cycles the selected auton by 1. Add anything else you
 * may need, like resetting pneumatic components. You can rename these autons to
 * be more descriptive, if you like.
 */

void pre_auton()
{
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  default_constants();
  Arm.resetPosition();

  while (!auto_started)
  {
    // Brain.Screen.clearScreen();
    // Brain.Screen.printAt(5, 20, "JAR Template v1.2.0");
    // Brain.Screen.printAt(5, 40, "Battery Percentage:");
    // Brain.Screen.printAt(5, 60, "%d", Brain.Battery.capacity());
    // Brain.Screen.printAt(5, 80, "Chassis Heading Reading:");
    // Brain.Screen.printAt(5, 100, "%f", chassis.get_absolute_heading());
    // Brain.Screen.printAt(5, 120, "Selected Auton:");
    switch (current_auton_selection)
    {
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
    if (Brain.Screen.pressing())
    {
      while (Brain.Screen.pressing())
      {
      }
      current_auton_selection++;
    }
    else if (current_auton_selection == 8)
    {
      current_auton_selection = 0;
    }
    task::sleep(10);
  }

  // yay
}

/**
 * Auton function, which runs the selected auton. Case 0 is the default,
 * and will run in the brain screen goes untouched during preauton. Replace
 * drive_test(), for example, with your own auton function you created in
 * autons.cpp and declared in autons.h.
 */

void autonomous(void)
{
  auto_started = true;

  // ringSideBlue();
  //  ringSideRed();
  // backUpAuton();
  TresRedRing();
  //skillsAuton();
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

void controllerPrint(int screenLine, std::string controllerText)
{
  OrderedUpdate = OrderedUpdate + 2;
  if (ControllerUpdate == OrderedUpdate)
  {
    Controller.Screen.clearLine(screenLine);
    Controller.Screen.setCursor(screenLine, 1);
    Controller.Screen.print(controllerText.c_str());
  }
}

void controllerPrint2(int screenLine, float controllerText)
{
  OrderedUpdate = OrderedUpdate + 2;
  if (ControllerUpdate == 0)
  {
    Controller.Screen.clearLine(screenLine);
    Controller.Screen.setCursor(screenLine, 1);
    Controller.Screen.print(controllerText);
  }
}

bool warnBattery = false;
bool warnTemp = false;
bool warnTemp2 = false;
bool warnTemp3 = false;
float averageDriveTemp;

vex::rotation RotationSensor = vex::rotation(PORT15); // Replace PORT15 with actual sensor port

void moveToAngle(double targetAngle) {
    while (fabs(RotationSensor.position(degrees) - targetAngle) > 10) {  
        double currentAngle = RotationSensor.position(degrees);
        double error = targetAngle - currentAngle;
        Controller.Screen.clearScreen();
        Controller.Screen.setCursor(1, 1);
        Controller.Screen.print(error);
        Controller.Screen.setCursor(2, 1);
        Controller.Screen.print(currentAngle);

        // if(RotationSensor.angle(degrees) > 0 && RotationSensor.angle(degrees) < 10) {
        //   error = targetAngle - 360;
        // }

        // Determine shortest direction (Clockwise vs Counterclockwise)
        while (true){
          if (error > 180) {
            error -= 360; // Move counterclockwise
          } 
          else if (error < -180) {
              error += 360; // Move clockwise
          } else{
            break; //once it is within the confines it will leave the while loop 
          }
        }
        

        double speed = error * 0.5; // Adjust control factor
        speed = clamp(speed, -50.0, 50.0); // Use custom clamp function

        // Spin in correct direction based on error
            Arm.spin(directionType::rev, speed, velocityUnits::pct); // Counterclockwise

        vex::task::sleep(10); // Small delay to prevent CPU overload
    }
    Arm.stop(hold);
}

int ArmCode() {  
    bool ToggleL2 = false;
    int state = 0; // Keeps track of arm position state

    while (true) {
        if (Controller.ButtonL2.pressing()) { 
            if (ToggleL2) {
                if (state == 0) {
                    moveToAngle(333);  // Move to first position
                    state = 1;
                } 
                else if (state == 1) {
                    moveToAngle(220); // Move to second position
                    state = 2;
                } 
                else {
                    Controller.Screen.clearScreen();
                    Controller.Screen.print("moving back");
                    moveToAngle(0); // Move back to 0° (now counterclockwise)
                    state = 0;
                }
                
                ToggleL2 = false;
            }
        } else {
            ToggleL2 = true;
        }

        vex::task::sleep(10);  // Prevent CPU overload
    }

    return 0;  // Required return statement for a task function
}







void usercontrol(void)
{
  // User control code here, inside the loop

  // very useful variables, luckily cole can't delete them (he doesn't have edit access LLLLLLLLLLLL)
  // bool ifTheButtonWithTheNameAIsPressedThisVariableActsAsAToggleSoItDoesntFireMultipleTimesThisTechniqueIsSeenInVERYSQUISHYSEALSScratchGamesGoToHisProfileIfThisVariableDoesntExplainWellEnoughAlthoughVERYSQUISHYSEALsProfileDoesNotActuallyExplainItAndYouNeedToGoIntoHisScratchGameWhichHasNoCommentsAndShortVariableNamesAndFindItBecauseYay;
  // bool ifTheButtonWithTheNameXIsPressedThisVariableActsAsAToggleSoItDoesntFireMultipleTimesThisTechniqueIsSeenInVERYSQUISHYSEALSScratchGamesGoToHisProfileIfThisVariableDoesntExplainWellEnoughAlthoughVERYSQUISHYSEALsProfileDoesNotActuallyExplainItAndYouNeedToGoIntoHisScratchGameWhichHasNoCommentsAndShortVariableNamesAndFindItBecauseYay;
  // bool ifTheButtonWithTheNameR2IsPressedThisVariableActsAsAToggleSoItDoesntFireMultipleTimesThisTechniqueIsSeenInVERYSQUISHYSEALSScratchGamesGoToHisProfileIfThisVariableDoesntExplainWellEnoughAlthoughVERYSQUISHYSEALsProfileDoesNotActuallyExplainItAndYouNeedToGoIntoHisScratchGameWhichHasNoCommentsAndShortVariableNamesAndFindItBecauseYay;
  // bool ifTheButtonWithTheNameL2IsPressedThisVariableActsAsAToggleSoItDoesntFireMultipleTimesThisTechniqueIsSeenInVERYSQUISHYSEALSScratchGamesGoToHisProfileIfThisVariableDoesntExplainWellEnoughAlthoughVERYSQUISHYSEALsProfileDoesNotActuallyExplainItAndYouNeedToGoIntoHisScratchGameWhichHasNoCommentsAndShortVariableNamesAndFindItBecauseYay;
  // bool ifTheButtonWithTheNameYAndBAreBothPressedThisVariableActsAsAToggleSoItDoesntFireMultipleTimesThisTechniqueIsSeenInVERYSQUISHYSEALSScratchGamesGoToHisProfileIfThisVariableDoesntExplainWellEnoughAlthoughVERYSQUISHYSEALsProfileDoesNotActuallyExplainItAndYouNeedToGoIntoHisScratchGameWhichHasNoCommentsAndShortVariableNamesAndFindItBecauseYay;

  int driveMode = 0;
  // bool DoinkerOn;
  bool ToggleA = false, ToggleX = false, ToggleR2 = false, ToggleL2 = false, ToggleBY = false, ToggleUp = false, ToggleDown = false;
  int ArmAngle = 0;

  

  task ArmTask = task(ArmCode);
  // int ArmAngleFinal = 0;
  // int arm1Start = Arm1.

  // clampUpdate;
  Brain.Screen.setCursor(3, 1);
  Brain.Screen.print("Normal Mode");
  Controller.Screen.setCursor(1, 1), Controller.Screen.print("Normal Mode");
  Brain.Screen.setCursor(4, 1);
  Brain.Screen.print("Clamp Off");
  Controller.Screen.setCursor(2, 1), Controller.Screen.print("Clamp Off");
  bool ClampOn = true;
  bool ArmOn = true;
  bool allowWarnings = false;
  int timeElapsed = 0;
  int oldTime = 0;
  sweeperA = 0;
  sweeperB = 1;
  // clampA = 0;
  // clampB = 1; // yay yay
  clampA = false;
  clampB = true; // clamap first gool

  while (1)
  {
    // MAIN LOOOOOOOOP (SWEAL THE SEAL IS THE BESTEST SEAL COLE DID YOU SEE THIS)
    ControllerUpdate++;
    // Brain.Screen.setCursor(2,1);
    // Brain.Screen.clearLine(2);
    // Brain.Screen.print(ControllerUpdate);
    if (ControllerUpdate == 30)
    {
      timeElapsed = round(vex::timer::system() / 1000);
      OrderedUpdate = 0;
      ControllerUpdate = 0;
      averageDriveTemp =
          frontRight.temperature(temperatureUnits::fahrenheit) +
          MiddleRight.temperature(temperatureUnits::fahrenheit) +
          UpsidedownRight.temperature(temperatureUnits::fahrenheit) +
          frontLeft.temperature(temperatureUnits::fahrenheit) +
          MiddleLeft.temperature(temperatureUnits::fahrenheit) +
          UpsidedownLeft.temperature(temperatureUnits::fahrenheit);
      averageDriveTemp = averageDriveTemp / 6;
      Brain.Screen.clearLine(9), Brain.Screen.setCursor(9, 1), Brain.Screen.print("Drive Temp: "), Brain.Screen.print(averageDriveTemp), Brain.Screen.print(" F");
      // Brain.Screen.clearLine(10),Brain.Screen.setCursor(10,1),Brain.Screen.print("Intake Temp: "),Brain.Screen.print(Intake.temperature(temperatureUnits::fahrenheit)), Brain.Screen.print(" F");
      if (allowWarnings)
      {
        Controller.Screen.clearLine(3), Controller.Screen.setCursor(3, 1), Controller.Screen.print(averageDriveTemp), Controller.Screen.print(" F");
        if (Brain.Battery.capacity() < 20)
        {
          if (warnBattery == false)
          {
            Controller.rumble(". . .");
            Controller.Screen.clearLine(3), Controller.Screen.setCursor(3, 1), Controller.Screen.print("BATTERY WARNING 20");
            ControllerUpdate = -100;
            warnBattery = true;
          }
        }
        else
        {
          warnBattery = false;
        }
        if (averageDriveTemp > 110)
        {
          if (warnTemp == false)
          {
            Controller.rumble("- - -");
            Controller.Screen.clearLine(3), Controller.Screen.setCursor(3, 1), Controller.Screen.print("TEMP 110F");
            ControllerUpdate = -100;
            warnTemp = true;
          }
        }
        else
        {
          warnTemp = false;
        }
        if (averageDriveTemp > 120)
        {
          if (warnTemp2 == false)
          {
            Controller.rumble("-.-.-");
            Controller.Screen.clearLine(3), Controller.Screen.setCursor(3, 1), Controller.Screen.print("HIGH TEMP 120F");
            ControllerUpdate = -100;
            warnTemp2 = true;
          }
        }
        else
        {
          warnTemp2 = false;
        }
        if (averageDriveTemp > 130)
        {
          if (warnTemp3 == false)
          {
            Controller.rumble(".....");
            Controller.Screen.clearLine(3), Controller.Screen.setCursor(3, 1), Controller.Screen.print("VERY HIGH TEMP 130F");
            ControllerUpdate = -100;
            warnTemp3 = true;
          }
        }
        else
        {
          warnTemp3 = false;
        }
      }
      else
      {
        if (timeElapsed == oldTime)
        {
        }
        else
        {
          Controller.Screen.clearLine(3), Controller.Screen.setCursor(3, 1), Controller.Screen.print(timeElapsed);
          oldTime = timeElapsed;
          // if(timeElapsed%5==0){
          //   Controller.rumble("-");
          // }
          if (timeElapsed == 70)
          {
            Controller.rumble(".................");
          }
        }
      }
    }
    if (driveMode == 1)
    {

      // Brain.Screen.print("Slow Mode");
      // controllerPrint(2,"Slow Mode");
      chassis.control_arcade(0.2);
    }
    else if (driveMode == 0)
    {

      // Brain.Screen.print("Normal Mode");
      // controllerPrint(2,"Normal Mode");
      chassis.control_arcade(1);
    }
    else
    {
      chassis.control_arcade(0);
    }

    // chassis.control_arcade(1);
    // // chassisLeft.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);

    // // frontRight.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
    // // pls work

    Brain.Screen.setCursor(1, 1);
    Brain.Screen.clearLine(1);
    Brain.Screen.print("Battery: "), Brain.Screen.print(Brain.Battery.capacity());

    // Brain.Screen.setCursor(2,1);
    // Brain.Screen.print("- Functions -");
    // Brain.Screen.setCursor(3,1);

    if (Controller.ButtonR2.pressing())
    { // If you are confused by this pls visit https://scratch.mit.edu/projects/1122100301/ for demo
      if (ToggleR2 == true)
      {
        clampA = !clampA;
        clampB = !clampB;
        ClampOn = clampB;
        Brain.Screen.setCursor(4, 1);
        Controller.Screen.setCursor(2, 1);
        Brain.Screen.clearLine(4, 1);
        Controller.Screen.clearLine(2);
        if (ClampOn == 0)
        {
          Brain.Screen.print("Clamp Off");
          Controller.Screen.print("Clamp Off");
        }
        else
        {
          Brain.Screen.print("Clamp On");
          Controller.Screen.print("Clamp On");
        }
        // clampUpdate;
        ToggleR2 = false;
      }
    }
    else
    {
      ToggleR2 = true;
    }


  

   
    
    if (Controller.ButtonUp.pressing())
    { // If you are confused by this pls visit https://scratch.mit.edu/projects/1122100301/ for demo
      if (ToggleUp == true)
      {

        goalStakeMacro(); 
        ToggleUp = false;
      }
    }
    else
    {
      ToggleUp = true;
    }


    // set clamp here

    if (Controller.ButtonX.pressing())
    { // If you are confused by this pls visit https://scratch.mit.edu/projects/1122100301/ for demo
      if (ToggleX)
      {
        sweeperA = !sweeperA;
        sweeperB = !sweeperB;
        Brain.Screen.print("Doinker Toggled");
        ToggleX = false;
      }
    }
    else
    {
      ToggleX = true;
    }


    if (Controller.ButtonA.pressing())
    { // If you are confused by this pls visit https://scratch.mit.edu/projects/1122100301/ for demo
      if (ToggleA)
      {
        ToggleA = false;
        Brain.Screen.setCursor(3, 1);
        Brain.Screen.clearLine(3);
        Controller.Screen.clearLine(1);
        Controller.Screen.setCursor(1, 1);
        if (driveMode == 1)
        {
          driveMode = 0;
        }
        else
        {
          driveMode = 1;
        }

        if (driveMode == 0)
        {
          Brain.Screen.print("Normal Mode");
          Controller.Screen.print("Normal Mode");
        }
        else
        {
          Brain.Screen.print("Slow Mode");
          Controller.Screen.print("Slow Mode");
        }
      }
    }
    else
    {
      ToggleA = true;
    }

    if (Controller.ButtonB.pressing() && Controller.ButtonY.pressing())
    {
      if (ToggleBY)
      {
        Brain.Screen.setCursor(3, 1);
        Brain.Screen.clearLine(3);
        Controller.Screen.clearLine(1);
        Controller.Screen.setCursor(1, 1);
        ToggleBY = false;
        if (driveMode == 2)
        {
          Brain.Screen.print("Normal (Sigma) Mode");
          Controller.Screen.print("Normal (Sigma) Mode");
          driveMode = 0;
        }
        else
        {
          Brain.Screen.print("CONTROL LOCK");
          Controller.Screen.print("CONTROL LOCK");
          driveMode = 2;
        }
      }
    }
    else
    {
      ToggleBY = true;
    }

    Brain.Screen.setCursor(5, 1);

    int IntakeSpeed = (Controller.ButtonR1.pressing() + Controller.ButtonL1.pressing() * (-1)) * 100 * 2;
    // int ArmSpeed = (Controller.ButtonY.pressing() + Controller.ButtonB.pressing()* (-1)) * 30;
    // ArmAngleFinal = ArmAngleFinal + ArmSpeed;
    Intake1.spin(directionType::fwd, IntakeSpeed, vex::velocityUnits::pct);
    Intake2.spin(directionType::fwd, IntakeSpeed, vex::velocityUnits::pct);
    // Arm1.spinToPosition(ArmAngleFinal, rotationUnits::deg, 50, vex::velocityUnits::pct);

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main()
{
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true)
  {
    wait(100, msec);
  }
}
// big men are better
// why won't it work
// big man work pls

