/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#ifndef Turn45Degrees_H
#define Turn45Degrees_H

#include "RobotMap.h"
#include "Robot.h"
#include <frc/WPILib.h>

class Turn45Degrees : public frc::Command {
private:
    bool isLeftTurn;
public:
    Turn45Degrees(bool isLeft);
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};

#endif  // Turn45Degrees_H


