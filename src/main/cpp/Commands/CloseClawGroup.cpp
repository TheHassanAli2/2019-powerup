/*
 * CloseClawGroup.cpp
 *
 *  Created on: Mar 3, 2018
 *      Author: Nader
 */

#include "Commands/CloseClawGroup.h"
#include "Commands/StartClaw.h"
#include "Commands/CloseClaw.h"

CloseClawGroup::CloseClawGroup() {
	AddSequential(new StartClaw(false));
	AddSequential(new CloseClaw());
}

