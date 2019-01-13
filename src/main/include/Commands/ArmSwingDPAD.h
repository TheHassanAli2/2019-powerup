/*
 * ArmSwing.h
 *
 *  Created on: Feb 10, 2018
 *      Author: Sayfullah
 */

#ifndef SRC_COMMANDS_ARMSWINGDPAD_H_
#define SRC_COMMANDS_ARMSWINGDPAD_H_

#include <frc/WPILib.h>
#include "Robot.h"
#include "RobotMap.h"

class ArmSwingDPAD : public frc::Command {
private:
	float armTargetPOS;
public:
	ArmSwingDPAD();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif /* SRC_COMMANDS_ARMSWINGDPAD_H_ */
