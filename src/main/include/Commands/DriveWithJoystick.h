#ifndef DriveWithJoystick_H
#define DriveWithJoystick_H

#include "RobotMap.h"
#include "Robot.h"
#include <frc/WPILib.h>

class DriveWithJoystick : public frc::Command {
public:
	DriveWithJoystick();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DriveWithJoystick_H
