/*
 * OpenClawGroup.cpp
 *
 *  Created on: Mar 3, 2018
 *      Author: Owen
 */

#include "Commands/OpenClawGroup.h"
#include "Commands/StartClaw.h"
#include "Commands/OpenClaw.h"

OpenClawGroup::OpenClawGroup() {
	AddSequential(new StartClaw(true));
	AddSequential(new OpenClaw());

}

