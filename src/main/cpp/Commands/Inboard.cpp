/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/Inboard.h"
#include "Commands/ArmSwing.h"
#include "Commands/Spine.h"

Inboard::Inboard() {
	AddSequential(new Spine(Robot::spine->Converter(false, 10), false));
	AddSequential(new ArmSwing(367.5, true));
}
