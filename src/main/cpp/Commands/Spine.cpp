/*
 * Spine.cpp
 *
 *  Created on: Feb 20, 2018
 *      Author: incognito
 */

#include "Commands/Spine.h"

Spine::Spine(float P, bool isGoingDown){
	Requires(Robot::spine.get());
	Position = P;
	GoingDown = isGoingDown;
	finished = false;
}

void Spine::Initialize(){
	Robot::spine->SetMotor(0,0);
}

void Spine::Execute(){
	int limitFlag = Robot::spine->CheckReset();
	finished = false;
	if((Robot::spine->GetSpinePos1() < Position) and !GoingDown){
		Robot::spine->AdjustSimple(GoingDown, limitFlag);
	}else if ((Robot::spine->GetSpinePos1() > Position) and GoingDown){
		Robot::spine->AdjustSimple(GoingDown, limitFlag);
	}else{
		finished = true;
	}
	frc::SmartDashboard::PutNumber("Spine Encoder 1", Robot::spine->GetSpinePos1());
	frc::SmartDashboard::PutNumber("Spine Encoder 2", Robot::spine->GetSpinePos2());

}

void Spine::End(){
	Robot::spine->SetMotor(0,0);
}

bool Spine::IsFinished(){
	return finished;
}

void Spine::Interrupted(){
	End();
}
