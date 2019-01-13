#include "Commands/CrabWalk2.h"

CrabWalk2::CrabWalk2(bool isLeft):
	isLeftWalk(isLeft)
{
	Requires(Robot::drivetrain.get());
}

void CrabWalk2::Initialize() {

	if (isLeftWalk){
		Robot::drivetrain->TankDrive(0.5,0);
		} else {
		Robot::drivetrain->TankDrive(0,0.5);
	}
}

void CrabWalk2::Execute() {
	Robot::drivetrain->Debug();
}

bool CrabWalk2::IsFinished() {
	float target;
	if (isLeftWalk) {
		target = Robot::drivetrain->GetRightCount();
	} else {
		target = Robot::drivetrain->GetLeftCount();
	}
	float placeholder = 143;
	return (abs(target) <= abs(placeholder));
}

void CrabWalk2::End() {
	SetTimeout(0.5);
	while(!IsTimedOut()) {
			if (isLeftWalk) {
				Robot::drivetrain->ArcadeDrive(-0.4, 0);
			} else {
				Robot::drivetrain->ArcadeDrive(0, -0.4);
			}
		}
	Robot::drivetrain->Stop();
	Robot::drivetrain->ResetEncoder();
}

void CrabWalk2::Interrupted() {
	End();
}
