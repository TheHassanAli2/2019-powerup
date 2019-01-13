#ifndef Turn90Degrees_H
#define Turn90Degrees_H


#include "RobotMap.h"
#include "Robot.h"
#include <frc/WPILib.h>

class Turn90Degrees : public frc::Command {
private:
	bool isLeftTurn;
public:
	Turn90Degrees(bool isLeft);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // Turn90Degrees_H
