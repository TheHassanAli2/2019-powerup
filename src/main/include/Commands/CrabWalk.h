#ifndef CrabWalk_H
#define CrabWalk_H

#include "RobotMap.h"
#include "Robot.h"
#include <frc/WPILib.h>

class CrabWalk : public frc::Command {
private:
	bool isLeftWalk;
public:
	CrabWalk(bool isLeft);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // CrabWalk_H
