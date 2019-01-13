/*
 * SpineSubSystem.h
 *
 *  Created on: Feb 15, 2018
 *      Author: Sayfullah
 */

#ifndef SRC_SUBSYSTEMS_SPINESUBSYSTEM_H_
#define SRC_SUBSYSTEMS_SPINESUBSYSTEM_H_

#include <frc/Commands/Subsystem.h>
#include <frc/WPILib.h>

class SpineSubSystem : public frc::Subsystem  {
private:
	//Spine Encoders
	std::shared_ptr<frc::Encoder> spineEncoder1;
	std::shared_ptr<frc::Encoder> spineEncoder2;

	//Spine Switches
	std::shared_ptr<frc::DigitalInput> bottomShoulderSwitch;
	std::shared_ptr<frc::DigitalInput> topShoulderSwitch;

	//Spine Motors
	std::shared_ptr<frc::SpeedController> spineMotor1;
	std::shared_ptr<frc::SpeedController> spineMotor2;

public:
	SpineSubSystem();
	void InitDefaultCommand();
	double Converter(bool toInch, double value); //true = convert from pulse to inch, false = convert inches to pulses
	double AdjustSpine(bool isGoingUp);
	void AdjustSimple(bool down, int limitFlag);
	void SetMotor(double spine1, double spine2);
	int GetSpinePos1();
	int GetSpinePos2();
	void ResetSpineEncoder1();
	void ResetSpineEncoder2();
	bool CanMoveSpine();
	bool CheckMove1();
	bool CheckMove2();
	void Reset();
	int CheckReset();
	void DisplaySpineCurrents();
};

#endif /* SRC_SUBSYSTEMS_SPINESUBSYSTEM_H_ */
