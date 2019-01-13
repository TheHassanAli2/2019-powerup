#include "Commands/CloseClaw.h"
#include "Robot.h"
#include "RobotMap.h"
#include "Subsystems/Arm.h"

CloseClaw::CloseClaw() {
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::claw.get());
	maxcurrent = 20.0;
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void CloseClaw::Initialize() {
	Robot::claw->CloseClawMotor();
	SetTimeout(3);
}

// Called repeatedly when this Command is scheduled to run
void CloseClaw::Execute() {
	frc::SmartDashboard::PutString("Claw: ", "Closing");
	frc::SmartDashboard::PutBoolean("Is Claw Closed", Robot::claw->IsClawClosed);
	//frc::SmartDashboard::PutNumber("CloseClaw-current", Robot::claw->CurrentDraw());
	//frc::SmartDashboard::PutNumber("CloseClaw-maxcurrent", maxcurrent);
}

// Make this return true when this Command no longer needs to run execute()
bool CloseClaw::IsFinished() {
	return  (abs(Robot::claw->CurrentDraw()) > abs(maxcurrent)) or IsTimedOut();
}

// Called once after isFinished returns true
void CloseClaw::End() {
	Robot::claw->IsClawClosed = true;
	Robot::claw->StopClaw();
	frc::SmartDashboard::PutBoolean("Is Claw Closed", Robot::claw->IsClawClosed);
	//frc::SmartDashboard::PutNumber("CloseClaw-current", Robot::claw->CurrentDraw());
	//frc::SmartDashboard::PutNumber("CloseClaw-maxcurrent", maxcurrent);

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CloseClaw::Interrupted() {
End();
}
