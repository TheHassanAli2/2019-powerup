/*
 * ArmSwing.cpp
 *
 *  Created on: Feb 10, 2018
 *      Author: Sayfullah
 */

#include "Commands/ArmSwingDPAD.h"


ArmSwingDPAD::ArmSwingDPAD() {
	Requires(Robot::arm.get());
	// TODO; change armTargetPOS value to the encoder value at start of match
	armTargetPOS = 0;
}

void ArmSwingDPAD::Initialize(){
	frc::SmartDashboard::PutString("Arm", "Start");


	Robot::arm->SetArmSpeed(0);
	armTargetPOS = 0.0;
}

void ArmSwingDPAD::Execute(){
	frc::SmartDashboard::PutNumber("Arm Encoder", Robot::arm->GetArmPosition());

	if (Robot::oi->driveStick->GetPOV(0) == 90){//ArmSwing up
		Robot::arm->SetArmSpeed(0.58);
		armTargetPOS = Robot::arm->GetArmPosition();
		if (armTargetPOS < 0){
			armTargetPOS = 0;
		}
		frc::SmartDashboard::PutString("Arm", "Moving");
	}
	else if(Robot::oi->driveStick->GetPOV(0) == -1){

		float speed = 0.0;
		Robot::arm->SetArmSpeed(speed);
		if (Robot::arm->GetArmPosition() > 30){ //30 is an estimated value and needs to be changed
			if (armTargetPOS > (1.01 * Robot::arm->GetArmPosition())){
				Robot::arm->SetArmSpeed(0.34);
			}
			else {
				Robot::arm->SetArmSpeed(0);
			}
		} else {
			Robot::arm->SetArmSpeed(-0.1);
		}
		frc::SmartDashboard::PutString("Arm", "Stopped");
	}
	else if(Robot::oi->driveStick->GetPOV(0) == 270){//ArmSwing Down
		Robot::arm->SetArmSpeed(-0.25);
		armTargetPOS = Robot::arm->GetArmPosition();
		if (armTargetPOS < 0){
			armTargetPOS = 0;
		}
		frc::SmartDashboard::PutString("Arm", "Moving");
		Robot::arm->ResetArm();
	}
}

bool ArmSwingDPAD::IsFinished(){
	return false;
}

void ArmSwingDPAD::End(){
	Robot::arm->SetArmSpeed(0);
	frc::SmartDashboard::PutString("Arm","Finished");
}

void ArmSwingDPAD::Interrupted(){
	End();
}
