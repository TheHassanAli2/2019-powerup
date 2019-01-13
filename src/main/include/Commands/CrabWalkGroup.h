#ifndef CrabWalkGroup_H
#define CrabWalkGroup_H

#include <frc/Commands/CommandGroup.h>
#include <frc/WPILib.h>

class CrabWalkGroup : public frc::CommandGroup {
private:
	bool isLeftWalk;
public:
	CrabWalkGroup(bool isLeft);
};

#endif  // CrabWalkGroup_H
