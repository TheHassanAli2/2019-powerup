/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/LoosenClaw.h"
#include "Robot.h"
#include "RobotMap.h"
#include "Subsystems/Arm.h"

LoosenClaw::LoosenClaw() {
	Requires(Robot::claw.get());

}

void LoosenClaw::Initialize() {
	frc::SmartDashboard::PutString("Claw: ", "Loosening");
	SetTimeout(0.1);
	Robot::claw->SetClawSpeed(0.8);
}

void LoosenClaw::Execute() {

}

bool LoosenClaw::IsFinished() {
	return IsTimedOut();
}

void LoosenClaw::End() {
	Robot::claw->SetClawSpeed(0);
}

void LoosenClaw::Interrupted() {

}
