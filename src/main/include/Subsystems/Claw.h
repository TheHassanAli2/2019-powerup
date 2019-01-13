/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/Commands/Subsystem.h>
#include <frc/WPILib.h>

class Claw : public frc::Subsystem {
private:
	std::shared_ptr<frc::SpeedController> clawMotor;

public:
	Claw();
	void InitDefaultCommand();
	void SetClawSpeed(float speed);
	void OpenClawMotor();
	void CloseClawMotor();
	void StopClaw();
	double CurrentDraw();
	// Claw Variables
	bool IsClawClosed;
};

