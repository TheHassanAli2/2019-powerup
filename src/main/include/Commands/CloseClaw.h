#ifndef CloseClaw_H
#define CloseClaw_H

#include <frc/WPILib.h>
#include "Robot.h"
#include "RobotMap.h"

class CloseClaw : public frc::Command {
private:
	double maxcurrent;
public:
	CloseClaw();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // CloseClaw_H
