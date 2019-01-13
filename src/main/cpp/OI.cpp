/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"
#include <WPILib.h>

#include "Commands/Switch.h"
#include "Commands/Exchange.h"
#include "Commands/Inboard.h"
#include "Commands/Scale.h"

#include "Commands/ClimbGroup.h"

#include "Commands/OpenClawGroup.h"
#include "Commands/CloseClawGroup.h"
#include "Commands/LoosenClaw.h"
#include "Commands/Turn90Degrees.h"

#include "Commands/SwitchCamera.h"


//OI::ControllerType_t OI::m_controllerType;

OI::OI() {



	driveStick.reset(new frc::Joystick(0));
	driveStick2.reset(new frc::Joystick(1));

	// Drive Stick Buttons
	aButtonE = new frc::JoystickButton(driveStick.get(), 1);
	bButtonE = new frc::JoystickButton(driveStick.get(), 2);
	xButtonE = new frc::JoystickButton(driveStick.get(), 3);
	yButtonE = new frc::JoystickButton(driveStick.get(), 4);
	leftBumperButtonE = new frc::JoystickButton(driveStick.get(), 5);
	rightBumperButtonE = new frc::JoystickButton(driveStick.get(), 6);
	selectButtonE = new frc::JoystickButton(driveStick.get(), 7);
	startButtonE = new frc::JoystickButton(driveStick.get(), 8);
	leftStickButtonE = new frc::JoystickButton(driveStick.get(), 9);
	rightStickButtonE = new frc::JoystickButton(driveStick.get(), 10);


	// Drive Stick Buttons
	aButtonD = new frc::JoystickButton(driveStick.get(), 2); //'X' on PS
	bButtonD = new frc::JoystickButton(driveStick.get(), 3); //'O' on PS
	xButtonD = new frc::JoystickButton(driveStick.get(), 1); //'[]' on PS
	yButtonD = new frc::JoystickButton(driveStick.get(), 4); //'/\' on PS
	leftBumperButtonD = new frc::JoystickButton(driveStick.get(), 5); //'L1' on PS
	rightBumperButtonD = new frc::JoystickButton(driveStick.get(), 6); //'R1' on PS
	leftTriggerButtonD = new frc::JoystickButton(driveStick.get(), 7); //'L2' on PS
	rightTriggerButtonD = new frc::JoystickButton(driveStick.get(), 8); //'R2' on PS
	selectButtonD = new frc::JoystickButton(driveStick.get(), 9); //'Share/Back' on PS
	startButtonD = new frc::JoystickButton(driveStick.get(), 10); //'Start' on PS
	leftStickButtonD = new frc::JoystickButton(driveStick.get(), 11); //'L3' on PS
	rightStickButtonD = new frc::JoystickButton(driveStick.get(), 12); //'R3' on PS
	homeButtonD = new frc::JoystickButton(driveStick.get(), 13); //'PS' on PS
	touchpadButtonD = new frc::JoystickButton(driveStick.get(), 14); //'Touchpad' on PS


	// Assigning Commands to Buttons

	//Drive Stick Controls
	//bButtonD->ToggleWhenPressed(new Inboard());
	//xButtonD->ToggleWhenPressed(new Switch());
	//aButtonD->ToggleWhenPressed(new Exchange());
	//yButtonD->ToggleWhenPressed(new Scale());

	//Camera Switch Controls
	selectButtonD->ToggleWhenPressed(new SwitchCamera());

	//Climb Controls
	//ASA	touchpadButtonD->ToggleWhenPressed(new ClimbGroup()); //Switch to startButtonD if using XBOX

	//Claw Controls
	aButtonD->ToggleWhenPressed(new LoosenClaw());
	rightBumperButtonD->WhileHeld(new OpenClawGroup());
	rightBumperButtonD->WhenReleased(new CloseClawGroup());

	//90 Degree Turn Control



}

std::shared_ptr<frc::Joystick> OI::getDriveStick() {
	return driveStick;
}

std::shared_ptr<frc::Joystick> OI::getDriveStick2() {
	return driveStick2;
}
