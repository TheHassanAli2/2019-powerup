/*
 * Spine.h
 *
 *  Created on: Feb 20, 2018
 *      Author: raven8
 */

#ifndef SRC_COMMANDS_SPINE_H_
#define SRC_COMMANDS_SPINE_H_

#include <frc/WPILib.h>
#include "Robot.h"
#include "RobotMap.h"

class Spine : public frc::Command {
private:
	float Position;
	bool GoingDown;
	bool finished;
public:
	Spine(float P, bool isGoingUp);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif /* SRC_COMMANDS_SPINE_H_ */
