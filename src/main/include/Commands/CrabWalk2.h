#ifndef CrabWalk2_H
#define CrabWalk2_H

#include "RobotMap.h"
#include "Robot.h"
#include <frc/WPILib.h>

class CrabWalk2 : public frc::Command {
private:
	bool isLeftWalk;
public:
	CrabWalk2(bool isLeft);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // CrabWalk2_H
