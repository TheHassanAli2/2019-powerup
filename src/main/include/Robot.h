/*
 * Robot.h
 *
 *  Created on: Jan 13, 2018
 *      Author: Sayf
 */

#ifndef _ROBOT_H_
#define _ROBOT_H_

#include <frc/WPILib.h>
#include <frc/Commands/Command.h>
#include "RobotMap.h"
// Vision includes
#include <thread>
#include <cameraserver/CameraServer.h>

// Autonomous mode includes
#include "Commands/AutoModes/Auto90Switch.h"
#include "Commands/AutoModes/AutoScale.h"
#include "Commands/AutoModes/AutoStraight.h"
#include "Commands/AutoModes/AutoStraightSwitch.h"
#include "Commands/AutoModes/LeftAutoMode.h"

// Subsystem includes
#include "Subsystems/Arm.h"
#include "Subsystems/Drivetrain.h"
#include "OI.h"
#include "Subsystems/SpineSubSystem.h"
#include "Subsystems/Claw.h"

class Robot : public frc::TimedRobot {
    public:
    std::string gameData;
    std::string matchData;//Not sure about this one, determines match type
    bool isLeft;
    frc::Command* autonomousCommand;
    int autonomousPos;
    static std::unique_ptr<OI> oi;
    frc::SendableChooser<int> chooser;
    static std::shared_ptr<Arm> arm;
    static std::shared_ptr<Drivetrain> drivetrain;
    static std::shared_ptr<SpineSubSystem> spine;
    static std::shared_ptr<Claw> claw;

    enum GameElements {
        GE_SWITCH_1 = 0,
        GE_SCALE = 1,
        GE_SWITCH_2 = 2
    };

    enum RobotPositon {
        DEFAULT = 0, // drive straight
        LEFT,
        CENTRE,
        RIGHT
    };

    enum FieldPosition {
        NONE = 0,
        SWITCH,
        SCALE,
        BOTH
    };

    static void VisionThread();
    void RobotInit() override;
    void DisabledInit() override;
    void DisabledPeriodic() override;
    void AutonomousInit() override;
    void AutonomousPeriodic() override;
    void TeleopInit() override;
    void TeleopPeriodic() override;

protected:
    void handleLeft(void);
    void handleRight(void);

    enum FieldPosition fieldPosition;
};
#endif


