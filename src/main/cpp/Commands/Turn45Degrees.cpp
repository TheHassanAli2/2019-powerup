#include "Commands/Turn45Degrees.h"

Turn45Degrees::Turn45Degrees(bool isLeft):
    isLeftTurn(isLeft)
{
    Requires(Robot::drivetrain.get());
}

void Turn45Degrees::Initialize() {
    Robot::drivetrain->ResetEncoder();
    if(isLeftTurn) {
    Robot::drivetrain->TankDrive(-1,1);
    } else {
    Robot::drivetrain->TankDrive(1,-1);
    }
}

void Turn45Degrees::Execute() {
    Robot::drivetrain->Debug();
}

bool Turn45Degrees::IsFinished() {
    float target;
    if (isLeftTurn) {
        target = Robot::drivetrain->GetLeftCount();
    } else {
        target = Robot::drivetrain->GetRightCount();
    }
    float placeholder = 152.5;//Half of a 90 Degree turn
    return (abs(target) >= abs(placeholder));
}

void Turn45Degrees::End() {
    Robot::drivetrain->Stop();
    Robot::drivetrain->ResetEncoder();
}

void Turn45Degrees::Interrupted() {
    End();
}


