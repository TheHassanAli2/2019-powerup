#include "Subsystems/Drivetrain.h"
#include "RobotMap.h"
#include "Robot.h"
#include "OI.h"
#include "Commands/DriveWithJoystick.h"

#include <ctre/phoenix/MotorControl/CAN/WPI_TalonSRX.h>
#include <ctre/phoenix/MotorControl/CAN/WPI_VictorSPX.h>
#include <ctre/phoenix/MotorControl/SensorCollection.h>


#define SPEED_MULTIPLIER 0.95

Drivetrain::Drivetrain() : Subsystem("DriveTrain") {
	    IsSpine = true;
		gyro = RobotMap::gyro;

	    leftDriveEncoder = RobotMap::leftDriveEncoder;
		rightDriveEncoder = RobotMap::rightDriveEncoder;

		differentialDrive = RobotMap::differentialDrive;

		leftDrive = RobotMap::leftDrive;
		rightDrive = RobotMap::rightDrive;

		backLeftDrive = RobotMap::backLeftDrive;
		frontLeftDrive = RobotMap::frontLeftDrive;
		backRightDrive = RobotMap::backRightDrive;
		frontRightDrive = RobotMap::frontRightDrive;
}

void Drivetrain::InitDefaultCommand() {
	SetDefaultCommand(new DriveWithJoystick());
}

void Drivetrain::Reset(){
	Stop();
	ResetEncoder();
}

void Drivetrain::ArcadeDrive(double speed, double turn){
	differentialDrive->ArcadeDrive(speed, turn);
	Debug();
}

void Drivetrain::Stop(){
	ArcadeDrive(0,0);
}

float Drivetrain::GetLeftDistance(){
	return leftDriveEncoder->GetDistance();
}

float Drivetrain::GetRightDistance(){
	return rightDriveEncoder->GetDistance();
}

float Drivetrain::GetLeftCount(){
	return leftDriveEncoder->Get();
}

float Drivetrain::GetRightCount(){
	return rightDriveEncoder->Get();
}
void Drivetrain::TankDrive(double leftSpeed, double rightSpeed){
	differentialDrive->TankDrive(leftSpeed, rightSpeed);
	Debug();
}

void Drivetrain::ResetEncoder(){
	rightDriveEncoder->Reset();
	leftDriveEncoder->Reset();
}

void Drivetrain::Debug() {
/*	frc::SmartDashboard::PutNumber("Encoder Right Distance", rightDriveEncoder->GetDistance());
	frc::SmartDashboard::PutNumber("Encoder Left Distance", leftDriveEncoder->GetDistance());

	frc::SmartDashboard::PutNumber("Left Current Count", leftDriveEncoder->Get());
	frc::SmartDashboard::PutNumber("Right Current Count", rightDriveEncoder->Get());

	frc::SmartDashboard::PutNumber("Left Period", leftDriveEncoder->GetPeriod());
	frc::SmartDashboard::PutNumber("Right Period", rightDriveEncoder->GetPeriod());

	frc::SmartDashboard::PutNumber("Left Rate", leftDriveEncoder->GetRate());
	frc::SmartDashboard::PutNumber("Right Rate", rightDriveEncoder->GetRate());

	frc::SmartDashboard::PutNumber("Left Raw", leftDriveEncoder->GetRaw());
	frc::SmartDashboard::PutNumber("Right Raw", rightDriveEncoder->GetRaw());


	//if (RobotMap::m_robotType == RobotMap::PROTOCASE) {

		int pos = std::dynamic_pointer_cast<ctre::phoenix::motorcontrol::can::WPI_TalonSRX>(backLeftDrive)->GetSelectedSensorPosition(0);
		frc::SmartDashboard::PutNumber("Talon SRX - encoder: ", pos);

		double volt = std::dynamic_pointer_cast<ctre::phoenix::motorcontrol::can::WPI_TalonSRX>(backLeftDrive)->GetMotorOutputVoltage();
		frc::SmartDashboard::PutNumber("Talon SRX - volt: ", volt);

		double current = std::dynamic_pointer_cast<ctre::phoenix::motorcontrol::can::WPI_TalonSRX>(backLeftDrive)->GetOutputCurrent();
		frc::SmartDashboard::PutNumber("Talon SRX - current: ", current);

		ctre::phoenix::motorcontrol::SensorCollection &sc = std::dynamic_pointer_cast<ctre::phoenix::motorcontrol::can::WPI_TalonSRX>(backLeftDrive)->GetSensorCollection();
		int fwdLs = sc.IsFwdLimitSwitchClosed();
		frc::SmartDashboard::PutNumber("Talon SRX - fwdLs: ", fwdLs);

		int revLs = sc.IsRevLimitSwitchClosed();
		frc::SmartDashboard::PutNumber("Talon SRX - revLs: ", revLs);
	}*/
}
