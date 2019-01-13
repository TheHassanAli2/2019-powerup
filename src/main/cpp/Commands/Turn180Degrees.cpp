#include "Commands/Turn180Degrees.h"

Turn180Degrees::Turn180Degrees(bool isLeft):
	isLeftTurn(isLeft)
{
	Requires(Robot::drivetrain.get());
}

void Turn180Degrees::Initialize() {
	Robot::drivetrain->ResetEncoder();
	if (isLeftTurn){
		Robot::drivetrain->TankDrive(0,1);
	}
	else{
		Robot::drivetrain->TankDrive(1,0);
	}
}

void Turn180Degrees::Execute() {
	Robot::drivetrain->Debug();
}

bool Turn180Degrees::IsFinished() {
	float target;
	if (isLeftTurn) {
		target = Robot::drivetrain->GetLeftCount();
	} else {
		target = Robot::drivetrain->GetRightCount();
	}
	float placeholder = 1400;
	return (abs(target) >= abs(placeholder));
}

void Turn180Degrees::End() {
	SetTimeout(0.5);
	while(!IsTimedOut()) {
		if (isLeftTurn) {
			Robot::drivetrain->ArcadeDrive(0, -0.4);
		} else {
			Robot::drivetrain->ArcadeDrive(-0.4, 0);
		}
	}
	Robot::drivetrain->Stop();
	Robot::drivetrain->ResetEncoder();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Turn180Degrees::Interrupted() {
	End();
}
