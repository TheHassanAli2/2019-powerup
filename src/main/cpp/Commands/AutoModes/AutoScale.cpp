/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/AutoModes/AutoScale.h"
#include "Commands/DriveDistance.h"
#include "Commands/Switch.h"
#include "Commands/Turn45Degrees.h"
#include "Commands/CloseClaw.h"
#include "Commands/OpenClaw.h"
#include "Commands/Exchange.h"
#include "Commands/Scale.h"

/*Auto: drive forward and while doing that start the scale motion
 * turn 45 degrees, drive forward and drop box in scale,
 * back up and put arm and spine in original position
 */
AutoScale::AutoScale(bool isLeft) {

    AddSequential(new DriveDistance(262.5));//Cross auto line, move towards scale, to turn in place for scale
//    AddParallel(new Scale()); Command for scale position for arm and spine
    AddSequential(new Turn45Degrees(isLeft));
    AddSequential(new DriveDistance(10));//calculated estimation on a 45 degree angle
    AddSequential(new OpenClaw());
    // @todo: replace Wait with ... ?
    //Wait(4);
    AddSequential(new CloseClaw());
    AddSequential(new DriveDistance(-20));//calculated estimation to back away from scale
 //ASA   AddSequential(new Exchange());

}


