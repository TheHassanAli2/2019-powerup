#ifndef Turn180Degrees_H
#define Turn180Degrees_H

#include "RobotMap.h"
#include "Robot.h"
#include <frc/WPILib.h>

class Turn180Degrees : public frc::Command {
private:
	bool isLeftTurn;
public:
	Turn180Degrees(bool isLeft);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // Turn180Degrees_H
