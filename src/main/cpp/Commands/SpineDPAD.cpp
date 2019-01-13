#include "Commands/SpineDPAD.h"

SpineDPAD::SpineDPAD() {
	Requires(Robot::spine.get());
}

void SpineDPAD::Initialize() {
	frc::SmartDashboard::PutString("Spine", "Start");
	frc::SmartDashboard::PutNumber("DPAD", Robot::oi->driveStick->GetPOV(0));
	frc::SmartDashboard::PutNumber("Spine Encoder 1", Robot::spine->GetSpinePos1());
	frc::SmartDashboard::PutNumber("Spine Encoder 2", Robot::spine->GetSpinePos2());
}

// Called repeatedly when this Command is scheduled to run
void SpineDPAD::Execute() {
	frc::SmartDashboard::PutNumber("DPAD", Robot::oi->driveStick->GetPOV(0));
	frc::SmartDashboard::PutNumber("Spine Encoder 1", Robot::spine->GetSpinePos1());
	frc::SmartDashboard::PutNumber("Spine Encoder 2", Robot::spine->GetSpinePos2());
	Robot::spine->DisplaySpineCurrents();

	int limitFlag = Robot::spine->CheckReset();

	bool isManual;

	float manualLeft = Robot::oi->getDriveStick2()->GetRawAxis(Robot::oi->LEFT_Y_AXIS_E);
	float manualRight = Robot::oi->getDriveStick2()->GetRawAxis(Robot::oi->RIGHT_Y_AXIS_E);

	float leftVal = 0.0;
	float rightVal = 0.0;

	if (abs(manualLeft) > 0.1 || abs(manualRight) > 0.1){
		isManual = true;
	} else {
		isManual = false;
	}

	if (manualLeft > 0.1){
		//If left axis down, Set spine left down
		leftVal = -0.4;
	} else if (manualLeft < -0.1){
		//If left axes up, Set spine left up
		leftVal = 0.4;
	}

	if (manualRight > 0.05){
		//If right axes down, Set spine right down
		rightVal = -0.4;
	} else if (manualRight < -0.1){
		//If right axes up, Set spine right up
		rightVal = 0.4;
	}

	if (isManual) {
		Robot::spine->SetMotor(leftVal, rightVal);
	} else if (Robot::oi->driveStick->GetPOV(0) == 0){
		//Move Spine upwards when DPAD up is pressed
		Robot::spine->AdjustSimple(false, limitFlag);
	} else if(Robot::oi->driveStick->GetPOV(0) == -1){
		//Stops spine when no DPAD button is pressed
		frc::SmartDashboard::PutString("Spine", "Stopped");
		Robot::spine->SetMotor(0,0);
	} else if(Robot::oi->driveStick->GetPOV(0) == 180){
		//Move Spine downwards when DPAD down is pressed
		Robot::spine->AdjustSimple(true, limitFlag);
	}
}

bool SpineDPAD::IsFinished() {
	return false;

}

void SpineDPAD::End() {
	Robot::spine->SetMotor(0,0);
	frc::SmartDashboard::PutString("Spine", "Finished");
}

void SpineDPAD::Interrupted() {
	End();

}
