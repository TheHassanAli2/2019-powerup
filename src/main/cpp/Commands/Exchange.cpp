/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/Exchange.h"
#include "Commands/ArmSwing.h"
#include "Commands/Spine.h"

Exchange::Exchange() {
	frc::SmartDashboard::PutString("Command", "Exchange");
	AddSequential(new ArmSwing(0, false));
	AddSequential(new Spine(0, false));
}
