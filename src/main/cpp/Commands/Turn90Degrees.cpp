#include "Commands/Turn90Degrees.h"

Turn90Degrees::Turn90Degrees(bool isLeft):
	isLeftTurn(isLeft)

{
	Requires(Robot::drivetrain.get());
}

void Turn90Degrees::Initialize() {
	Robot::drivetrain->ResetEncoder();
	if(isLeftTurn) {
	Robot::drivetrain->TankDrive(-1,1);
	} else {
	Robot::drivetrain->TankDrive(1,-1);
	}
}

void Turn90Degrees::Execute() {
	if(Robot::oi->driveStick->GetRawButton(11)){
		Robot::drivetrain->TankDrive(-1,1);
	}else if(Robot::oi->driveStick->GetRawButton(12)){
		Robot::drivetrain->TankDrive(1,-1);
	}
	Robot::drivetrain->Debug();
}

bool Turn90Degrees::IsFinished() {
	float target;
	if (isLeftTurn) {
		target = Robot::drivetrain->GetLeftCount();
	} else {
		target = Robot::drivetrain->GetRightCount();
	}
	float placeholder = 305;
	return (abs(target) >= abs(placeholder));
}

void Turn90Degrees::End() {
	Robot::drivetrain->Stop();
	Robot::drivetrain->ResetEncoder();
}

void Turn90Degrees::Interrupted() {
}
