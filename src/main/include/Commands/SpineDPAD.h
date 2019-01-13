#ifndef SpineUp_H
#define SpineUp_H

#include <frc/WPILib.h>
#include "Robot.h"
#include "RobotMap.h"

class SpineDPAD : public frc::Command {
public:
	SpineDPAD();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // SpineUp_H
