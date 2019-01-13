#ifndef DriveDistance_H
#define DriveDistance_H

#include <frc/WPILib.h>
#include "Robot.h"
#include "RobotMap.h"

class DriveDistance : public frc::Command {
private:
	float targetDistance;
	float speed;
public:
	DriveDistance(double time);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DriveDistance_H
