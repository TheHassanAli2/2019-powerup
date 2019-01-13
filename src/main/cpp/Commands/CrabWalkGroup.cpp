#include "Commands/CrabWalkGroup.h"
#include "Commands/CrabWalk.h"
#include "Commands/CrabWalk2.h"
#include "Commands/DriveDistance.h"
CrabWalkGroup::CrabWalkGroup(bool isLeft):
	isLeftWalk(isLeft)
{
	AddSequential(new CrabWalk(isLeftWalk));
	AddSequential(new CrabWalk2(isLeftWalk));
	AddSequential(new DriveDistance(2.45));
}
