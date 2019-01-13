/*
 * ArmClimb.cpp
 *
 *  Created on: Feb 20, 2018
 *      Author: raven8
 */

#include "Commands/ArmSwing.h"


ArmSwing::ArmSwing(float position, bool isGoingUp)
{
	Position = position;
	GoingUp = isGoingUp;
	Requires(Robot::arm.get());
}

void ArmSwing::Initialize(){
	Robot::arm->SetArmSpeed(0);
}

void ArmSwing::Execute(){
	if (Robot::arm->GetArmPosition() <= Position * 1.01 && GoingUp) {
		Robot::arm->SetArmSpeed(0.6);
	}else if (Robot::arm->GetArmPosition() >= Position * 0.99 && !GoingUp){
		Robot::arm->SetArmSpeed(-0.3);
	}else {
		End();
	}
	frc::SmartDashboard::PutNumber("Arm Encoder", Robot::arm->GetArmPosition());
}

void ArmSwing::End(){
	Robot::arm->SetArmSpeed(0);
}

bool ArmSwing::IsFinished(){
	return false;
}

void ArmSwing::Interrupted(){
	End();
}
