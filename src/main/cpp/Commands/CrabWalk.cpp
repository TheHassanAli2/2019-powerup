#include "Commands/CrabWalk.h"

CrabWalk::CrabWalk(bool isLeft):
	isLeftWalk(isLeft)
{
	Requires(Robot::drivetrain.get());
}

void CrabWalk::Initialize() {
	Robot::drivetrain->ResetEncoder();
	if (isLeftWalk){
			Robot::drivetrain->TankDrive(0,0.5);
			} else {
			Robot::drivetrain->TankDrive(0.5,0);
	}
}

void CrabWalk::Execute() {
	Robot::drivetrain->Debug();

}

bool CrabWalk::IsFinished() {
	float target;
		if (isLeftWalk) {
			target = Robot::drivetrain->GetLeftCount();
		} else {
			target = Robot::drivetrain->GetRightCount();
		}
		float placeholder = 143;
		return (abs(target) >= abs(placeholder));
}

void CrabWalk::End() {
	SetTimeout(0.5);
	while(!IsTimedOut()) {
			if (isLeftWalk) {
				Robot::drivetrain->ArcadeDrive(0, -0.4);
			} else {
				Robot::drivetrain->ArcadeDrive(-0.4, 0);
			}
		}
	Robot::drivetrain->Stop();
	Robot::drivetrain->TankDrive(0,0);
	Robot::drivetrain->ResetEncoder();

}

void CrabWalk::Interrupted() {
	End();
}
