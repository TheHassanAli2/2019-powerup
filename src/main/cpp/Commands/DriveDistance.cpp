#include "Commands/DriveDistance.h"
#include "Robot.h"
const float kP = 0.025;

DriveDistance::DriveDistance(double distance)
{
	targetDistance = distance;
	if (distance < 0){
		speed = 0.65;
	}else{
		speed = -0.65;
	}
	Requires(Robot::drivetrain.get());
}

void DriveDistance::Initialize() {
	Robot::drivetrain->Reset();
}

void DriveDistance::Execute() {
	//frc::SmartDashboard::PutNumber("Left Distance travelled", Robot::drivetrain->GetLeftDistance());
	//frc::SmartDashboard::PutNumber("Right Distance travelled", Robot::drivetrain->GetRightDistance());
	//frc::SmartDashboard::PutNumber("target distance", targetDistance);
	Robot::drivetrain->ArcadeDrive(speed, 0.05);
}

bool DriveDistance::IsFinished() {
	return (abs(targetDistance) >= abs(Robot::drivetrain->GetLeftDistance()) || abs(targetDistance) >= abs(Robot::drivetrain->GetRightDistance()));
}

void DriveDistance::End() {
	Robot::drivetrain->Stop();
}

void DriveDistance::Interrupted() {
	End();
}
