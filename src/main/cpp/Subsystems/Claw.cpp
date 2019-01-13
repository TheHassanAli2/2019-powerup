/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Subsystems/Claw.h"
#include "RobotMap.h"
#include "Robot.h"
#include <frc/WPILib.h>
#include <frc/SmartDashboard/Sendable.h>
#include <ctre/phoenix/MotorControl/CAN/WPI_TalonSRX.h>

Claw::Claw() : Subsystem("Claw"){
	clawMotor = RobotMap::clawMotor;

	IsClawClosed = false;
}

void Claw::InitDefaultCommand(){
}

void Claw::SetClawSpeed(float speed){
	/* Function sets the speed of the motor.
	 * speed - any value between '-1' and '1', positive opens the claw.
	 */
	clawMotor->Set(speed);
}

void Claw::OpenClawMotor(){
	// Sets the claw motor at '0.8' speed to open the claw.
	clawMotor->Set(0.8);
}

void Claw::CloseClawMotor(){
	// Sets the claw motor at '-0.8' speed to close the claw.
	clawMotor->Set(-0.8);
}

double Claw::CurrentDraw(){
	/* Function reads and returns the output current from the claw motor.
	 * It also displays this current on the SmartDashboard.
	 */
	double current = std::dynamic_pointer_cast<ctre::phoenix::motorcontrol::can::WPI_TalonSRX>(clawMotor)->GetOutputCurrent();
	//SmartDashboard::PutNumber("Talon SRX - current: ", current);
	return (current);
}

void Claw::StopClaw(){
	// Sets the claw motor speed to '0' to stop movement.
	clawMotor->Set(0);
}
