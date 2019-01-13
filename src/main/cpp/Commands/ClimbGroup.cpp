/*
 * ClimbGroup.cpp
 *
 *  Created on: Feb 20, 2018
 *      Author: Sayfullah
 */

#include "Commands/ClimbGroup.h"
#include "Commands/Spine.h"
#include "Commands/ArmSwing.h"
#include "Commands/Spine.h"


ClimbGroup::ClimbGroup() {
	AddSequential(new ArmSwing(0, false));
	AddSequential(new Spine(737280, false));
	AddSequential(new ArmSwing(180, true));
	AddSequential(new Spine(6826, false));
}


