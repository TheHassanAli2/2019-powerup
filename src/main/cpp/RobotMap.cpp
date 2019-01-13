/*
 * RobotMap.cpp
 *
 *  Created on: Jan 13, 2018
 *      Author: Madeline
 */

#ifndef SRC_ROBOTMAP_CPP_
#define SRC_ROBOTMAP_CPP_

//For Pi Const
#include <math.h>

#include "RobotMap.h"
#include "Robot.h"
#include "SmartDashboard/Sendable.h"
#include "Encoder.h"

//#include <ctre/phoenix/motorcontrol/can/WPI_TalonSRX.h>
//#include <ctre/phoenix/motorcontrol/can/WPI_VictorSPX.h>
#include "ctre/Phoenix.h"

// PORT MAPPINGS
	// PWM Ports
		// Arm subsystem
#define CLAW_MOTOR_PORT 8
#define ARM_MOTOR_1_PORT 6 // in wiring, 1 = left; 2 = right
#define ARM_MOTOR_2_PORT 7
#define SPINE_MOTOR_1_PORT 5
#define SPINE_MOTOR_2_PORT 4

		// Drivetrain subsystem
#define FRONT_LEFT_DRIVE_PORT 2
#define BACK_LEFT_DRIVE_PORT 3
#define FRONT_RIGHT_DRIVE_PORT 0
#define BACK_RIGHT_DRIVE_PORT 1

	// Digital Ports
		// Arm subsystem
#define BOTTOM_SHOULDER_SWITCH_PORT 17
#define ARM_ENCODER_A_PORT 18
#define ARM_ENCODER_B_PORT 19

		// Drivetrain subsystem
#define LEFT_DRIVE_ENCODER_A_PORT 10
#define LEFT_DRIVE_ENCODER_B_PORT 11
#define RIGHT_DRIVE_ENCODER_A_PORT 12
#define RIGHT_DRIVE_ENCODER_B_PORT 13

	//Analog Ports
#define GYRO_PORT 0
#define LEFT_LIGHT_REFLECTOR_PORT 1
#define RIGHT_LIGHT_REFLECTOR_PORT 2

// POINTERS
	// Arm subsystem
std::shared_ptr<frc::Encoder> RobotMap::armEncoder;
std::shared_ptr<frc::DigitalInput> RobotMap::bottomShoulderSwitch;

std::shared_ptr<frc::SpeedController> RobotMap::armMotor1;
std::shared_ptr<frc::SpeedController> RobotMap::armMotor2;
std::shared_ptr<frc::SpeedController> RobotMap::clawMotor;
std::shared_ptr<frc::SpeedController> RobotMap::spineMotor1;
std::shared_ptr<frc::SpeedController> RobotMap::spineMotor2;

	// Drivetrain subsystem
std::shared_ptr<frc::ADXRS450_Gyro> RobotMap::gyro;
std::shared_ptr<frc::Encoder> RobotMap::leftDriveEncoder;
std::shared_ptr<frc::Encoder> RobotMap::rightDriveEncoder;

std::shared_ptr<frc::SpeedController> RobotMap::backLeftDrive;
std::shared_ptr<frc::SpeedController> RobotMap::backRightDrive;
std::shared_ptr<frc::SpeedController> RobotMap::frontLeftDrive;
std::shared_ptr<frc::SpeedController> RobotMap::frontRightDrive;
std::shared_ptr<frc::SpeedControllerGroup> RobotMap::leftDrive;
std::shared_ptr<frc::SpeedControllerGroup> RobotMap::rightDrive;

std::shared_ptr<frc::DifferentialDrive> RobotMap::differentialDrive;

RobotMap::RobotType_t RobotMap::m_robotType;

void RobotMap::init() {

	/**
	 * set m_robotType to PROTOCASE | STEAMWORKS | POWERUP | POWERUP_PROTO
	 * depending on target robot
	 *
	 * default to POWERUP_PROTO
	 */
	m_robotType = POWERUP;

	switch (m_robotType) {
	case PROTOCASE:
		initCommon();
		initProtoCase();
		break;
	case STEAMWORKS:
		initCommon();
		initSteamworks();
		break;
	case POWERUP:
		initCommon();
		initPowerUpCommon();
		initPowerUp();
		break;
	case POWERUP_PROTO:
		initCommon();
		initPowerUpCommon();
		initPowerUpProto();
	}
}

void RobotMap::reset() {
	Robot::arm->Reset();
	Robot::drivetrain->Reset();
	}

void RobotMap::initCommon() {

	// Arm subsystem
	armEncoder.reset(new frc::Encoder(ARM_ENCODER_A_PORT, ARM_ENCODER_B_PORT, false, frc::Encoder::EncodingType::k4X));
		armEncoder->Sendable::SetName("Arm", "encoder");
		armEncoder->SetMaxPeriod(0.1);
		armEncoder->SetMinRate(1);
		armEncoder->SetSamplesToAverage(15);
		armEncoder->SetReverseDirection(false);
		armEncoder->SetDistancePerPulse(1); //PLACEHOLDER

	bottomShoulderSwitch.reset(new frc::DigitalInput(BOTTOM_SHOULDER_SWITCH_PORT));
		bottomShoulderSwitch->Sendable::SetName("Shoulder", "bottom switch");

	armMotor1.reset(new frc::VictorSP(ARM_MOTOR_1_PORT));
	std::static_pointer_cast<frc::VictorSP>(armMotor1)->SetName("Arm", "motor 1");
	armMotor1->SetInverted(false);

	armMotor2.reset(new frc::VictorSP(ARM_MOTOR_2_PORT));
	std::static_pointer_cast<frc::VictorSP>(armMotor2)->SetName("Arm", "motor 2");
	armMotor2->SetInverted(true);
}

void RobotMap::initProtoCase() {

	// Drivetrain subsystem
	leftDriveEncoder.reset(new frc::Encoder(LEFT_DRIVE_ENCODER_A_PORT, LEFT_DRIVE_ENCODER_B_PORT, false, frc::Encoder::EncodingType::k4X));
		leftDriveEncoder->Sendable::SetName("Drivetrain", "left encoder");
		leftDriveEncoder->SetMaxPeriod(0.1);
		leftDriveEncoder->SetMinRate(1);
		leftDriveEncoder->SetSamplesToAverage(5);
		leftDriveEncoder->SetReverseDirection(true);
		leftDriveEncoder->SetDistancePerPulse((M_PI*6.0)/360.0); //PLACEHOLDER

	rightDriveEncoder.reset(new frc::Encoder(RIGHT_DRIVE_ENCODER_A_PORT, RIGHT_DRIVE_ENCODER_B_PORT, false, frc::Encoder::EncodingType::k4X));
		rightDriveEncoder->Sendable::SetName("Drivetrain", "right encoder");
		rightDriveEncoder->SetMaxPeriod(0.1);
		rightDriveEncoder->SetMinRate(1);
		rightDriveEncoder->SetSamplesToAverage(5);
		rightDriveEncoder->SetReverseDirection(true);
		rightDriveEncoder->SetDistancePerPulse((M_PI*6.0)/360.0); //PLACEHOLDER


	backLeftDrive.reset(new ctre::phoenix::motorcontrol::can::WPI_TalonSRX(0));

	backLeftDrive.reset(new ctre::phoenix::motorcontrol::can::WPI_TalonSRX(6));

	std::dynamic_pointer_cast<ctre::phoenix::motorcontrol::can::WPI_TalonSRX>(backLeftDrive)->SetName("Drivetrain", "back left drive");

	frontLeftDrive.reset(new ctre::phoenix::motorcontrol::can::WPI_VictorSPX(5));
	std::dynamic_pointer_cast<ctre::phoenix::motorcontrol::can::WPI_VictorSPX>(frontLeftDrive)->SetName("Drivetrain", "front left drive");

	std::dynamic_pointer_cast<ctre::phoenix::motorcontrol::can::WPI_VictorSPX>(frontLeftDrive)->Follow(*(std::dynamic_pointer_cast<ctre::phoenix::motorcontrol::can::WPI_TalonSRX>(backLeftDrive)));

	backRightDrive.reset(new frc::VictorSP(BACK_RIGHT_DRIVE_PORT));
	std::static_pointer_cast<frc::VictorSP>(backRightDrive)->SetName("Drivetrain", "back right drive");

	frontRightDrive.reset(new frc::VictorSP(FRONT_RIGHT_DRIVE_PORT));
	std::static_pointer_cast<frc::VictorSP>(frontRightDrive)->SetName("Drivetrain", "front right drive");

	backLeftDrive->SetInverted(true);
	backRightDrive->SetInverted(true);
	frontLeftDrive->SetInverted(true);
	frontRightDrive->SetInverted(true);

	leftDrive = std::make_shared <frc::SpeedControllerGroup>(*backLeftDrive, *frontLeftDrive);
	rightDrive = std::make_shared <frc::SpeedControllerGroup>(*backRightDrive, *frontRightDrive);

	differentialDrive.reset(new frc::DifferentialDrive(*leftDrive, *rightDrive));
		differentialDrive->SetSafetyEnabled(false);
		differentialDrive->SetExpiration(0.1);
		differentialDrive->SetMaxOutput(1.0);

	spineMotor1.reset(new ctre::phoenix::motorcontrol::can::WPI_TalonSRX(5));
	std::dynamic_pointer_cast<ctre::phoenix::motorcontrol::can::WPI_TalonSRX>(spineMotor1)->SetName("Spine", "motor 1");

	spineMotor2.reset(new ctre::phoenix::motorcontrol::can::WPI_TalonSRX(0));
	std::dynamic_pointer_cast<ctre::phoenix::motorcontrol::can::WPI_TalonSRX>(spineMotor2)->SetName("Spine", "motor 2");

	clawMotor.reset(new frc::PWMTalonSRX(CLAW_MOTOR_PORT));
	std::static_pointer_cast<frc::PWMTalonSRX>(clawMotor)->SetName("Claw", "motor");

	gyro.reset(new frc::ADXRS450_Gyro(frc::SPI::Port(GYRO_PORT)));
		gyro->Sendable::SetName("Drivetrain", "gyro");
		gyro->Calibrate();
}

/**
 *  Power UP
 *
 *  Drivetrain               | PWM | CAN | DIO | Description |
 * ===========================================================
 *  Left Front Controller    |  2  |  2  |     | Victor SPX  |
 *  Left Back Controller     |  3  |  3  |     | Victor SPX  |
 *                           |     |     |     |             |
 *  Right Front Controller   |  0  |  0  |     | Victor SPX  |
 *  Right Back Controller    |  1  |  1  |     | Victor SPX  |
 *                           |     |     |     |             |
 *  Left Encoder Y           |     |     |  10 | E4T         |
 *  Left Encoder B           |     |     |  11 | E4T         |
 *  Right Encoder Y          |     |     |  12 | E4T         |
 *  Right Encoder B          |     |     |  13 | E4T         |
 *
 *  Spine                    | PWM | CAN | DIO |             |
 * ==========================================================|
 *  Left Spine Controller    |  5  |  ?  |     | Talon SRX   |
 *  Right Spine Controller   |  4  |  ?  |     | Talon SRX   |
 *                                                           |
 *  Left Encoder Y           |     |     |  14 |             |
 *  Left Encoder B           |     |     |  15 |             |
 *  Right Encoder Y          |     |     |  16 |             |
 *  Right Encoder B          |     |     |  17 |             |
 *
 *  Arm                      | PWM | CAN | DIO |             |
 * ==========================================================|
 *  Left Controller          |  6  |     |     | Victor SP   |
 *  Right Controller         |  7  |     |     | Victor SP   |
 *
 *  Encoder Y                |     |     |  18 |             |
 *  Encoder B                |     |     |  19 |             |
 *
 */

void RobotMap::initPowerUpCommon() {

	// Drivetrain subsystem
	leftDriveEncoder.reset(new frc::Encoder(LEFT_DRIVE_ENCODER_A_PORT, LEFT_DRIVE_ENCODER_B_PORT, false, frc::Encoder::EncodingType::k4X));
		leftDriveEncoder->Sendable::SetName("Drivetrain", "left encoder");
		leftDriveEncoder->SetMaxPeriod(0.1);
		leftDriveEncoder->SetMinRate(1);
		leftDriveEncoder->SetSamplesToAverage(5);
		leftDriveEncoder->SetReverseDirection(true);
		leftDriveEncoder->SetDistancePerPulse((M_PI*6.0)/360.0); //PLACEHOLDER

	rightDriveEncoder.reset(new frc::Encoder(RIGHT_DRIVE_ENCODER_A_PORT, RIGHT_DRIVE_ENCODER_B_PORT, false, frc::Encoder::EncodingType::k4X));
		rightDriveEncoder->Sendable::SetName("Drivetrain", "right encoder");
		rightDriveEncoder->SetMaxPeriod(0.1);
		rightDriveEncoder->SetMinRate(1);
		rightDriveEncoder->SetSamplesToAverage(5);
		rightDriveEncoder->SetReverseDirection(true);
		rightDriveEncoder->SetDistancePerPulse((M_PI*6.0)/360.0); //PLACEHOLDER

	backLeftDrive.reset(new ctre::phoenix::motorcontrol::can::WPI_VictorSPX(3));
	std::dynamic_pointer_cast<ctre::phoenix::motorcontrol::can::WPI_VictorSPX>(backLeftDrive)->SetName("Drivetrain", "back left drive");

	backRightDrive.reset(new ctre::phoenix::motorcontrol::can::WPI_VictorSPX(1));
	std::dynamic_pointer_cast<ctre::phoenix::motorcontrol::can::WPI_VictorSPX>(backRightDrive)->SetName("Drivetrain", "back right drive");

	frontLeftDrive.reset(new ctre::phoenix::motorcontrol::can::WPI_VictorSPX(2));
	std::dynamic_pointer_cast<ctre::phoenix::motorcontrol::can::WPI_VictorSPX>(frontLeftDrive)->SetName("Drivetrain", "front left drive");

	frontRightDrive.reset(new ctre::phoenix::motorcontrol::can::WPI_VictorSPX(0));
	std::dynamic_pointer_cast<ctre::phoenix::motorcontrol::can::WPI_VictorSPX>(frontRightDrive)->SetName("Drivetrain", "front right drive");

	backLeftDrive->SetInverted(true);
	backRightDrive->SetInverted(true);
	frontLeftDrive->SetInverted(true);
	frontRightDrive->SetInverted(true);

	leftDrive = std::make_shared <frc::SpeedControllerGroup>(*backLeftDrive, *frontLeftDrive);
	rightDrive = std::make_shared <frc::SpeedControllerGroup>(*backRightDrive, *frontRightDrive);

	differentialDrive.reset(new frc::DifferentialDrive(*leftDrive, *rightDrive));
		differentialDrive->SetSafetyEnabled(false);
		differentialDrive->SetExpiration(0.1);
		differentialDrive->SetMaxOutput(1.0);

	spineMotor1.reset(new ctre::phoenix::motorcontrol::can::WPI_TalonSRX(SPINE_MOTOR_1_PORT));
	std::dynamic_pointer_cast<ctre::phoenix::motorcontrol::can::WPI_TalonSRX>(spineMotor1)->SetName("Spine", "motor 1");

	spineMotor2.reset(new ctre::phoenix::motorcontrol::can::WPI_TalonSRX(SPINE_MOTOR_2_PORT));
	std::dynamic_pointer_cast<ctre::phoenix::motorcontrol::can::WPI_TalonSRX>(spineMotor2)->SetName("Spine", "motor 2");

	clawMotor.reset(new ctre::phoenix::motorcontrol::can::WPI_TalonSRX(CLAW_MOTOR_PORT));
	std::dynamic_pointer_cast<ctre::phoenix::motorcontrol::can::WPI_TalonSRX>(clawMotor)->SetName("Claw", "motor");

	gyro.reset(new frc::ADXRS450_Gyro(frc::SPI::Port(GYRO_PORT)));
		gyro->Sendable::SetName("Drivetrain", "gyro");
		gyro->Calibrate();

}

void RobotMap::initPowerUp() {

}

void RobotMap::initPowerUpProto() {

}

/**
 *  Steamworks
 *
 *  Drivetrain               | PWM | CAN | DIO | Description |
 * ===========================================================
 *  Left Front Controller    |  2  |  2  |     | Victor SP   |
 *  Left Back Controller     |  3  |  3  |     | Victor SP   |
 *                           |     |     |     |             |
 *  Right Front Controller   |  0  |  0  |     | Victor SP   |
 *  Right Back Controller    |  1  |  1  |     | Victor SP   |
 *                           |     |     |     |             |
 *  Left Encoder Y           |     |     |  10 | E4T         |
 *  Left Encoder B           |     |     |  11 | E4T         |
 *  Right Encoder Y          |     |     |  12 | E4T         |
 *  Right Encoder B          |     |     |  13 | E4T         |
 */

void RobotMap::initSteamworks() {

	// Drivetrain subsystem
	leftDriveEncoder.reset(new frc::Encoder(LEFT_DRIVE_ENCODER_A_PORT, LEFT_DRIVE_ENCODER_B_PORT, false, frc::Encoder::EncodingType::k4X));
		leftDriveEncoder->Sendable::SetName("Drivetrain", "left encoder");
		leftDriveEncoder->SetMaxPeriod(0.1);
		leftDriveEncoder->SetMinRate(1);
		leftDriveEncoder->SetSamplesToAverage(5);
		leftDriveEncoder->SetReverseDirection(true);
		leftDriveEncoder->SetDistancePerPulse((M_PI*6.0)/360.0); //PLACEHOLDER

	rightDriveEncoder.reset(new frc::Encoder(RIGHT_DRIVE_ENCODER_A_PORT, RIGHT_DRIVE_ENCODER_B_PORT, false, frc::Encoder::EncodingType::k4X));
		rightDriveEncoder->Sendable::SetName("Drivetrain", "right encoder");
		rightDriveEncoder->SetMaxPeriod(0.1);
		rightDriveEncoder->SetMinRate(1);
		rightDriveEncoder->SetSamplesToAverage(5);
		rightDriveEncoder->SetReverseDirection(true);
		rightDriveEncoder->SetDistancePerPulse((M_PI*6.0)/360.0); //PLACEHOLDER

	backLeftDrive.reset(new frc::VictorSP(BACK_LEFT_DRIVE_PORT));
	std::static_pointer_cast<frc::VictorSP>(backLeftDrive)->SetName("Drivetrain", "back left drive");

	backRightDrive.reset(new frc::VictorSP(BACK_RIGHT_DRIVE_PORT));
	std::static_pointer_cast<frc::VictorSP>(backRightDrive)->SetName("Drivetrain", "back right drive");

	frontLeftDrive.reset(new frc::VictorSP(FRONT_LEFT_DRIVE_PORT));
	std::static_pointer_cast<frc::VictorSP>(frontLeftDrive)->SetName("Drivetrain", "front left drive");

	frontRightDrive.reset(new frc::VictorSP(FRONT_RIGHT_DRIVE_PORT));
	std::static_pointer_cast<frc::VictorSP>(frontRightDrive)->SetName("Drivetrain", "front right drive");

	backLeftDrive->SetInverted(true);
	backRightDrive->SetInverted(true);
	frontLeftDrive->SetInverted(true);
	frontRightDrive->SetInverted(true);

	leftDrive = std::make_shared <frc::SpeedControllerGroup>(*backLeftDrive, *frontLeftDrive);
	rightDrive = std::make_shared <frc::SpeedControllerGroup>(*backRightDrive, *frontRightDrive);

	differentialDrive.reset(new frc::DifferentialDrive(*leftDrive, *rightDrive));
		differentialDrive->SetSafetyEnabled(false);
		differentialDrive->SetExpiration(0.1);
		differentialDrive->SetMaxOutput(1.0);

	gyro.reset(new frc::ADXRS450_Gyro(frc::SPI::Port(GYRO_PORT)));
		gyro->Sendable::SetName("Drivetrain", "gyro");
		gyro->Calibrate();
}

#endif /* SRC_ROBOTMAP_CPP_ */
