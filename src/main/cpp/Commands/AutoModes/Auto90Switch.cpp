/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/AutoModes/Auto90Switch.h"
#include "Commands/DriveDistance.h"
#include "Commands/Switch.h"
#include "Commands/Turn90Degrees.h"
#include "Commands/CloseClaw.h"
#include "Commands/OpenClaw.h"
#include "Commands/Exchange.h"


Auto90Switch::Auto90Switch(bool isLeft) {
    AddSequential(new DriveDistance(150));//Cross auto line a bit to turn in place for switch
    AddSequential(new Turn90Degrees(isLeft));
    AddSequential(new DriveDistance(25));//Move towards switch(85"-30"-30")
 //ASA   AddSequential(new Switch());
    AddSequential(new OpenClaw());
    // @todo: replace Wait with ... ?
    //Wait(4);
    AddSequential(new CloseClaw());
 //ASA   AddSequential(new Exchange());
}
    // Add Commands here:
    // e.g. AddSequential(new Command1());
    //      AddSequential(new Command2());
    // these will run in order.




