#ifndef SRC_SUBSYSTEMS_DRIVETRAIN_H_
#define SRC_SUBSYSTEMS_DRIVETRAIN_H_



#include <frc/Commands/Subsystem.h>
#include <frc/WPILib.h>

class Drivetrain : public frc::Subsystem {
private:
	std::shared_ptr<frc::ADXRS450_Gyro> gyro;
	std::shared_ptr<frc::Encoder> leftDriveEncoder;
	std::shared_ptr<frc::Encoder> rightDriveEncoder;
	std::shared_ptr<frc::DifferentialDrive> differentialDrive;

public:

	bool IsSpine;

	std::shared_ptr<frc::SpeedControllerGroup> leftDrive;
	std::shared_ptr<frc::SpeedControllerGroup> rightDrive;
	std::shared_ptr<frc::SpeedController> frontLeftDrive;
	std::shared_ptr<frc::SpeedController> backLeftDrive;
	std::shared_ptr<frc::SpeedController> frontRightDrive;
	std::shared_ptr<frc::SpeedController> backRightDrive;

	Drivetrain();
	void InitDefaultCommand();
	void ArcadeDrive(double, double);
	float GetLeftDistance();
	float GetRightDistance();
	float GetLeftCount();
	float GetRightCount();
	void Debug();
	void TankDrive(double leftSpeed, double rightSpeed);
	void Reset();
	void ResetEncoder();
	void Stop();
};

#endif // Drivetrain_H
