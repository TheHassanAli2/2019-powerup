#include "Commands/SwitchCamera.h"

SwitchCamera::SwitchCamera() {
}

void SwitchCamera::Initialize(){
	Robot::drivetrain->IsSpine = false;
	frc::SmartDashboard::PutString("Front of robot: ", "Ramp");
}
bool SwitchCamera::IsFinished(){
	return false;
}

void SwitchCamera::End(){
	Robot::drivetrain->IsSpine = true;
	frc::SmartDashboard::PutString("Front of the Robot: ", "Cube");
}

void SwitchCamera::Interrupted(){
	End();
}
