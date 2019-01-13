/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/AutoModes/AutoStraightSwitch.h"
#include "Commands/DriveDistance.h"
#include "Commands/Switch.h"
#include "Commands/OpenClaw.h"
#include "Commands/CloseClaw.h"
#include "Commands/Exchange.h"


AutoStraightSwitch::AutoStraightSwitch() {
    AddSequential(new DriveDistance(110));//From the starting point to the switch; straight (140 inches - bot)
 //ASA   AddSequential(new Switch());
    AddSequential(new OpenClaw());
    // @todo: replace Wait with ... ?
    //Wait(4);
    AddSequential(new CloseClaw());
 //ASA   AddSequential(new Exchange());
    // Add Commands here:
    // e.g. AddSequential(new Command1());
    //      AddSequential(new Command2());
    // these will run in order.

    // To run multiple commands at the same time,
    // use AddParallel()
    // e.g. AddParallel(new Command1());
    //      AddSequential(new Command2());
    // Command1 and Command2 will run in parallel.

}


