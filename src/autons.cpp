#include "vex.h"

/**
 * Resets the constants for auton movement.
 * Modify these to change the default behavior of functions like
 * drive_distance(). For explanations of the difference between
 * drive, heading, turning, and swinging, as well as the PID and
 * exit conditions, check the docs. ROSHIE TIME PLS WORK come on TateTime
 */

void default_constants()
{
  // Each constant set is in the form of (maxVoltage, kP, kI, kD, startI).
  chassis.set_drive_constants(10, 1.5, 0, 10, 0);
  chassis.set_heading_constants(6, .4, 0, 1, 0);
  chassis.set_turn_constants(8, .07, 0, 0, 0);
  chassis.set_swing_constants(8, .3, .001, 2, 15);

  // Each exit condition set is in the form of (settle_error, settle_time, timeout).
  // chassis.set_drive_exit_conditions(1.5, 300, 5000);
  // chassis.set_drive_exit_conditions(1, 0, 0);
  // chassis.set_turn_exit_conditions(1, 300,3000); //-------------------------
  // // chassis.set_swing_exit_conditions(1, 300, 3000);
  // chassis.set_swing_exit_conditions(1, 0, 0);

  // chassis.set_drive_constants(10, 1.5, 0, 10, 0);
  // chassis.set_heading_constants(6, .4, 0, 1, 0);
  // chassis.set_turn_constants(12, .1, .03, 1, 15);
  // chassis.set_swing_constants(12, .3, .001, 2, 15);

  // Each exit condition set is in the form of (settle_error, settle_time, timeout).
  // chassis.set_drive_exit_conditions(1.5, 300, 5000);
  // chassis.set_turn_exit_conditions(1, 300, 3000);
  // chassis.set_swing_exit_conditions(1, 300, 3000);
  chassis.set_drive_exit_conditions(1.5, 300, 5000);
  chassis.set_turn_exit_conditions(1, 300, 1000);
  chassis.set_swing_exit_conditions(1, 300, 3000);
}
/**
 * Sets constants to be more effective for odom movements.
 * For functions like drive_to_point(), it's often better to have
 * a slower max_voltage and greater settle_error than you would otherwise.
 */

void odom_constants()
{
  default_constants();
  chassis.heading_max_voltage = 10;
  chassis.drive_max_voltage = 8;
  chassis.drive_settle_error = 3;
  chassis.boomerang_lead = .5;
  chassis.drive_min_voltage = 0;
}

void skillsAuton()
{
  firstQuarter();
  firstCrossover();
  secondQuarter();
  Brain.Screen.print(round(vex::timer::system() / 1000));
}

// ██████████████████████████████████████████████████████████████████████████████████████████████████ █
// ██████████████████████████████████████████████████████████████████████████████████████████████████ █
// Skills Auton

int antiJamIntake()
{
  while (true)
  {
    if (Intake2.current() > 0 && Intake2.efficiency() == 0)
    {
      Intake2.spin(reverse, 100, pct);
    }
    else
    {
      Intake2.spin(fwd, 100, pct);
    }
  }

  return 0;
}

void firstQuarter()
{
  float error = 0;
  sweeperA = false;
  sweeperB = true;
  clampA = false;
  clampB = true;

  goalStakeMacro();
  vex::task::sleep(500);
  Intake1.spin(directionType::fwd, 200, vex::velocityUnits::pct);
  Intake2.spin(directionType::fwd, 200, vex::velocityUnits::pct);
  // Intake2.spin(directionType::fwd, 200, vex::velocityUnits::pct);
  // task intakeTask = task(antiJamIntake);

  vex::task::sleep(500);

  // chassis.drive_distance(7);
  // intakeTask.stop();//
  task intakeTask = task(antiJamIntake);
  vex::task::sleep(500);

  chassis.turn_to_angle(115 + error);
  chassis.drive_distance(-20, 4);
  //
  clampA = true;
  clampB = false; // clamap first gool
  // fun
  vex::task::sleep(1000);
  // Intake2.spin(directionType::fwd, 200, vex::velocityUnits::pct);
  // intakeTask = task(antiJamIntake);

  error = error - 15;
  chassis.turn_to_angle(0 + error);
  chassis.drive_distance(25); // rizz up a ring
  //
  error = error - 12;
  chassis.turn_to_angle(317 + error); // ring on the line
  // Intake1.spin(directionType::fwd, -200, vex::velocityUnits::pct);
  // Intake2.spin(directionType::fwd, -200, vex::velocityUnits::pct);
  chassis.drive_distance(34); // go there
  // Intake1.spin(directionType::fwd, 200, vex::velocityUnits::pct);
  // Intake2.spin(directionType::fwd, 200, vex::velocityUnits::pct);
  // I love Mason <3

  error = error + 17.5;
  chassis.turn_to_angle(150 + error);
  chassis.drive_distance(13); // go bacc

  // chassis.turn_to_angle(180+error);
  error = error + 10;
  chassis.drive_distance(45, 180 + error, 4, 4); // go there

  chassis.turn_to_angle(340 + error); // ring on the line
  chassis.drive_distance(13);         // go there

  chassis.turn_to_angle(45 + error); // ring on the line
  chassis.drive_distance(-15);
  clampA = false;
  clampB = true;
  vex::task::sleep(500);
  intakeTask.stop(); 
  Intake1.spin(directionType::fwd, -200, vex::velocityUnits::pct);
  Intake2.spin(directionType::fwd, -200, vex::velocityUnits::pct);
  chassis.drive_distance(23);
  chassis.turn_to_angle(-90 + error); // ring on the line
}
// ██████████████████████████████████████████████████████████████████████████████████████████████████ █

void firstCrossover()
{
  task intakeTask = task(antiJamIntake);
  float error = 0;
  chassis.drive_distance(-54);
  chassis.turn_to_angle(-33 + error);
  chassis.drive_distance(-14, 4);
  clampA = true;
  clampB = false;
  vex::task::sleep(500);
  intakeTask.stop(); 
}

// ██████████████████████████████████████████████████████████████████████████████████████████████████ █

void secondQuarter()
{
  task intakeTask = task(antiJamIntake);
  float error = 0;
  Intake1.spin(directionType::fwd, 200, vex::velocityUnits::pct);
  Intake2.spin(directionType::fwd, 200, vex::velocityUnits::pct);
  error = 15;
  chassis.turn_to_angle(0 + error);
  chassis.drive_distance(25); // rizz up a ring
  //
  error = error + 12;
  chassis.turn_to_angle(-310 + error); // ring on the line
  // RING FIX

  chassis.drive_distance(34);

  error = error - 17.5;
  chassis.turn_to_angle(-150 + error);
  chassis.drive_distance(9); // go bacc

  // chassis.turn_to_angle(180+error);
  error = error - 10;
  chassis.drive_distance(42, -180 + error, 4, 4); // go there

  chassis.turn_to_angle(-335 + error); // last ring
  chassis.drive_distance(13);          //

  chassis.turn_to_angle(-50 + error); // place mog
  chassis.drive_distance(10);
  chassis.drive_distance(-30);
  intakeTask.stop(); 
  Intake1.spin(directionType::fwd, -200, vex::velocityUnits::pct);
  Intake2.spin(directionType::fwd, -200, vex::velocityUnits::pct);
  clampA = false;
  clampB = true;
  vex::task::sleep(1000);
  chassis.drive_distance(23);
  chassis.turn_to_angle(0 + error); // ring on the line
  chassis.drive_distance(20);
}

// ██████████████████████████████████████████████████████████████████████████████████████████████████ █
// ██████████████████████████████████████████████████████████████████████████████████████████████████ █

/**
 * The expected behavior is to return to the start position.
 */

void goalRushBlue()
{

  sweeperA = false;
  sweeperB = true;
  clampA = true;
  clampB = false;
  chassis.drive_distance(-32);
  chassis.turn_to_angle(40);
  chassis.drive_distance(-12);
  clampA = false;
  clampB = true;
  vex::task::sleep(200);
  // Intake.spin(directionType::fwd, 100, vex::velocityUnits::pct);
  chassis.drive_distance(5);
  chassis.turn_to_angle(-45); // 0--------------------
  chassis.drive_distance(12);
  // Intake.spin(directionType::fwd, 0, vex::velocityUnits::pct);
  chassis.turn_to_angle(160);
  chassis.drive_distance(-25);
  clampA = true;
  clampB = false;
  chassis.drive_distance(24);
  chassis.turn_to_angle(90);
  chassis.drive_distance(-23);
  clampA = false;
  clampB = true;
  vex::task::sleep(100);
  // Intake.spin(directionType::fwd, 100, vex::velocityUnits::pct);
  vex::task::sleep(1300);
  // Intake.spin(directionType::fwd, 100, vex::velocityUnits::pct);
  chassis.turn_to_angle(270);
  chassis.drive_distance(20);
}
void TresRedRing()
{
  sweeperA = false;
  sweeperB = true;
  clampA = false;
  clampB = true;
  chassis.drive_distance(-22);
  clampA = true;
  clampB = false;
  vex::task::sleep(100);
  task intakeTask = task(antiJamIntake);
  Intake1.spin(directionType::fwd, 200, vex::velocityUnits::pct);
  vex::task::sleep(400);
  chassis.turn_to_angle(120);
  chassis.drive_distance(25);
  chassis.turn_to_angle(190);
  chassis.drive_distance(13);
  chassis.drive_distance(-13);
  chassis.turn_to_angle(220);
  chassis.drive_distance(13);
  chassis.turn_to_angle(320);
  chassis.drive_distance(45);
  intakeTask.stop();
}
void TresBlueRing(){
  sweeperA = false;
  sweeperB = true;
  clampA = false;
  clampB = true;
  chassis.drive_distance(-20);
  clampA = true;
  clampB = false;
  Intake2.spin(directionType::fwd, 200, vex::velocityUnits::pct);
  Intake1.spin(directionType::fwd, 200, vex::velocityUnits::pct);
  vex::task::sleep(400);
  chassis.turn_to_angle(240);
  chassis.drive_distance(25);
  chassis.turn_to_angle(190);
  chassis.drive_distance(13);
  chassis.drive_distance(-13);
  chassis.turn_to_angle(160);
  chassis.drive_distance(13);
  chassis.turn_to_angle(270);
  chassis.drive_distance(20);
}
void TresRedGoal(){
  sweeperA = false;
  sweeperB = true;
  clampA = false;
  clampB = true;
}
void TresBlueGoal(){
  sweeperA = false;
  sweeperB = true;
  clampA = false;
  clampB = true;
}

void backUpAuton()
{
  clampA = false;
  clampB = true;
  chassis.drive_distance(-24);
  clampA = true;
  clampB = false;
  wait(1, seconds);
  Intake1.spin(directionType::fwd, 200, vex::velocityUnits::pct);
  Intake2.spin(directionType::fwd, 200, vex::velocityUnits::pct);
  wait(1, seconds);
  // chassis.drive_distance(12);
  // Intake1.spin(directionType::fwd, 0, vex::velocityUnits::pct);
  // Intake2.spin(directionType::fwd, 200, vex::velocityUnits::pct);
  chassis.turn_to_angle(180);
  chassis.drive_distance(20);
}
void startMacro()
{
  sweeperA = false;
  sweeperB = true;
  clampA = false;
  clampB = true;

  goalStakeMacro();

  Intake1.spin(directionType::fwd, 200, vex::velocityUnits::pct);
  Intake2.spin(directionType::fwd, 200, vex::velocityUnits::pct);

  vex::task::sleep(500);

  chassis.drive_distance(20);
  chassis.turn_to_angle(77);
  chassis.drive_distance(-24);
  //
  clampA = true;
  clampB = false;
  // fun
  vex::task::sleep(500);
  chassis.turn_to_angle(341);
}

void goalRushRed()
{
  sweeperA = false;
  sweeperB = true;
  clampA = true;
  clampB = false;
  chassis.drive_distance(-32);
  chassis.turn_to_angle(0);
  // vex::task::sleep(100);
  chassis.turn_to_angle(-45);
  // vex::task::sleep(100);
  chassis.drive_distance(-11.5);
  clampA = false;
  clampB = true;
  vex::task::sleep(100);
  // Intake.spin(directionType::fwd, 100, vex::velocityUnits::pct);
  chassis.drive_distance(5);
  chassis.turn_to_angle(45);
  vex::task::sleep(100);

  chassis.drive_distance(13);
  // Intake.spin(directionType::fwd, 0, vex::velocityUnits::pct);
  vex::task::sleep(100);
  chassis.turn_to_angle(160);
  chassis.drive_distance(-25);
  clampA = true;
  clampB = false;
  chassis.drive_distance(24);
  chassis.turn_to_angle(-90);
  chassis.drive_distance(-22);
  clampA = false;
  clampB = true;
  vex::task::sleep(100);
  // Intake.spin(directionType::fwd, 100, vex::velocityUnits::pct);
  vex::task::sleep(1300);
  // Intake.spin(directionType::fwd, 100, vex::velocityUnits::pct);
  chassis.turn_to_angle(170);
  // chassis.turn_to_angle(135);
  chassis.drive_distance(18);
}

void ringSideBlue()
{
  clampA = true;
  clampB = false;

  chassis.drive_distance(-24);
  clampA = false;
  clampB = true;
  chassis.drive_distance(-6);
  chassis.turn_to_angle(-90);

  // Intake.spin(directionType::fwd, 100, vex::velocityUnits::pct);
  vex::task::sleep(100);
  chassis.drive_distance(24);
  vex::task::sleep(400);

  chassis.turn_to_angle(180);
  chassis.drive_distance(17);
  vex::task::sleep(400);
  chassis.drive_distance(-7);

  chassis.turn_to_angle(130);
  chassis.drive_distance(8);
  vex::task::sleep(200);
  chassis.drive_distance(-13);

  chassis.turn_to_angle(90);
  chassis.drive_distance(27);

  // rwar

  // chassis.turn_to_angle(160);
  // Intake.spin(directionType::fwd, 100, vex::velocityUnits::pct);
  // chassis.drive_distance(20);
  // chassis.drive_distance(-10);

  // chassis.turn_to_angle(200);
  // Intake.spin(directionType::fwd, 100, vex::velocityUnits::pct);
  // chassis.drive_distance(10);
}

void ringSideRed()
{
  clampA = true;
  clampB = false;

  chassis.drive_distance(-24);
  clampA = false;
  clampB = true;
  chassis.drive_distance(-6);
  chassis.turn_to_angle(90);

  // Intake.spin(directionType::fwd, 100, vex::velocityUnits::pct);
  vex::task::sleep(400);
  chassis.drive_distance(24);
  vex::task::sleep(400);

  chassis.turn_to_angle(165);
  chassis.drive_distance(17);
  vex::task::sleep(400);
  chassis.drive_distance(-7);

  chassis.turn_to_angle(-130);
  chassis.drive_distance(8);
  vex::task::sleep(200);
  chassis.drive_distance(-13);

  chassis.turn_to_angle(-90);
  chassis.drive_distance(27);

  // rwar

  // chassis.turn_to_angle(160);
  // Intake.spin(directionType::fwd, 100, vex::velocityUnits::pct);
  // chassis.drive_distance(20);
  // chassis.drive_distance(-10);

  // chassis.turn_to_angle(200);
  // Intake.spin(directionType::fwd, 100, vex::velocityUnits::pct);
  // chassis.drive_distance(10);
}

void goalStakeMacro()
{
  sweeperA = false;
  sweeperB = true;
  clampA = false;
  clampB = true;
  chassis.drive_distance(1.5);
}

/**
 * The expected behavior is to return to the start angle, after making a complete turn.
 */

void turn_test()
{
  chassis.turn_to_angle(90);
  chassis.turn_to_angle(180);
  chassis.turn_to_angle(270);
  chassis.turn_to_angle(360);
  chassis.turn_to_angle(0);
  chassis.turn_to_angle(90);
  chassis.turn_to_angle(180);
  chassis.turn_to_angle(270);
  chassis.turn_to_angle(360);
  chassis.turn_to_angle(0);
  chassis.turn_to_angle(90);
  chassis.turn_to_angle(180);
  chassis.turn_to_angle(270);
  chassis.turn_to_angle(360);
  chassis.turn_to_angle(0);
  Controller.Screen.clearScreen();
  Controller.Screen.print("finished turn test");
}

/**
 * Should swing in a fun S shape.
 */

void swing_test()
{
  chassis.left_swing_to_angle(90);
  chassis.right_swing_to_angle(0);
}

/**
 * A little of this, a little of that; it should end roughly where it started.
 */

void full_test()
{
  chassis.drive_distance(24);
  chassis.turn_to_angle(-45);
  chassis.drive_distance(-36);
  chassis.right_swing_to_angle(-90);
  chassis.drive_distance(24);
  chassis.turn_to_angle(0);
}

/**
 * Doesn't drive the robot, but just prints coordinates to the Brain screen
 * so you can check if they are accurate to life. Push the robot around and
 * see if the coordinates increase like you'd expect.
 */

void odom_test()
{
  chassis.set_coordinates(0, 0, 0);
  while (1)
  {
    Brain.Screen.clearScreen();
    Brain.Screen.printAt(5, 20, "X: %f", chassis.get_X_position());
    Brain.Screen.printAt(5, 40, "Y: %f", chassis.get_Y_position());
    Brain.Screen.printAt(5, 60, "Heading: %f", chassis.get_absolute_heading());
    Brain.Screen.printAt(5, 80, "ForwardTracker: %f", chassis.get_ForwardTracker_position());
    Brain.Screen.printAt(5, 100, "SidewaysTracker: %f", chassis.get_SidewaysTracker_position());
    task::sleep(20);
  }
}

/**
 * Should end in the same place it began, but the second movement
 * will be curved while the first is straight.
 */

void tank_odom_test()
{
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.turn_to_point(24, 24);
  chassis.drive_to_point(24, 24);
  chassis.drive_to_point(0, 0);
  chassis.turn_to_angle(0);
}

/**
 * Drives in a square while making a full turn in the process. Should
 * end where it started.
 */

void holonomic_odom_test()
{
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.holonomic_drive_to_pose(0, 18, 90);
  chassis.holonomic_drive_to_pose(18, 0, 180);
  chassis.holonomic_drive_to_pose(0, 18, 270);
  chassis.holonomic_drive_to_pose(0, 0, 0);
}