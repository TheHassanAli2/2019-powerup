/*
 * DriveTime.h
 *
 *  Created on: Mar 25, 2018
 *      Author: Noodles
 */

#ifndef SRC_COMMANDS_DRIVETIME_H_
#define SRC_COMMANDS_DRIVETIME_H_

#include <frc/WPILib.h>
#include "Robot.h"
#include "RobotMap.h"


class DriveTime : public frc::Command {

private:
	float targetDistance;
	double timeDistance;

public:

	DriveTime(double time);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};





#endif /* SRC_COMMANDS_DRIVETIME_H_ */
