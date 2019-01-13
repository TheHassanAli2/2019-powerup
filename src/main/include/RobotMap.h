/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include <frc/WPILib.h>

class RobotMap {
public:
	// Arm subsystem
	static std::shared_ptr<frc::Encoder> armEncoder;
	static std::shared_ptr<frc::DigitalInput> bottomShoulderSwitch;

	static std::shared_ptr<frc::SpeedController> clawMotor;
	static std::shared_ptr<frc::SpeedController> spineMotor1;
	static std::shared_ptr<frc::SpeedController> spineMotor2;
	static std::shared_ptr<frc::SpeedController> armMotor1;
	static std::shared_ptr<frc::SpeedController> armMotor2;

	// Drivetrain subsystem
	static std::shared_ptr<frc::ADXRS450_Gyro> gyro;
	static std::shared_ptr<frc::Encoder> leftDriveEncoder;
	static std::shared_ptr<frc::Encoder> rightDriveEncoder;

	static std::shared_ptr<frc::SpeedController> frontLeftDrive;
	static std::shared_ptr<frc::SpeedController> backLeftDrive;
	static std::shared_ptr<frc::SpeedController> frontRightDrive;
	static std::shared_ptr<frc::SpeedController> backRightDrive;
	static std::shared_ptr<frc::DifferentialDrive> differentialDrive;
	static std::shared_ptr<frc::SpeedControllerGroup>leftDrive;
	static std::shared_ptr<frc::SpeedControllerGroup> rightDrive;

	// Vision
	static std::shared_ptr<frc::AnalogInput> leftLightReflector;
	static std::shared_ptr<frc::AnalogInput> rightLightReflector;

	static void init();
	static void reset();

	typedef enum robotType {
		PROTOCASE,
		STEAMWORKS,
		POWERUP_PROTO,
		POWERUP
	} RobotType_t;

	static RobotType_t m_robotType;

private:



	/**
	 * initialization common to all robots
	 */
	static void initCommon();

	/**
	 * initialization common to both 2018 Power Up prototype and competition robots
	 */
	static void initPowerUpCommon();

	/**
	 * initialization specific to 2018 Power Up prototype robot
	 */
	static void initPowerUpProto();

	/**
	 * initialization specific to 2018 Power Up competition robot
	 */
	static void initPowerUp();

	/**
	 * initialization specific to protocase robot
	 */
	static void initProtoCase();

	/**
	 * initialization specific to 2017 steamworks robot
	 */
	static void initSteamworks();
};

#endif
