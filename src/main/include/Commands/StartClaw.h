/*
 * StartClaw.h
 *
 *  Created on: Mar 3, 2018
 *      Author: Owen
 */

#ifndef SRC_COMMANDS_STARTCLAW_H_
#define SRC_COMMANDS_STARTCLAW_H_

#include <frc/WPILib.h>
#include "Robot.h"
#include "RobotMap.h"

class StartClaw : public frc::Command {
private:
	bool direct;
public:
	StartClaw(bool direction); //true = open, false = close
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interupted();
};

#endif /* SRC_COMMANDS_STARTCLAW_H_ */
