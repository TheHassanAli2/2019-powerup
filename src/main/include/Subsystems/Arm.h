#ifndef Arm_H
#define Arm_H

#include <frc/Commands/Subsystem.h>
#include <frc/WPILib.h>

class Arm : public frc::Subsystem {
private:
	std::shared_ptr<frc::Encoder> armEncoder;
	std::shared_ptr<frc::Encoder> spineEncoder1;
	std::shared_ptr<frc::Encoder> spineEncoder2;
	std::shared_ptr<frc::DigitalInput> bottomShoulderSwitch;

	std::shared_ptr<frc::SpeedController> armMotor1;
	std::shared_ptr<frc::SpeedController> armMotor2;

public:
	Arm();
	void InitDefaultCommand();
	void SetArmSpeed(float speed);
	float GetArmPosition();
	void Reset();
	void ResetArm();
	void ResetArmEncoder();
	void Log();

};

#endif  // Arm_H
