#include <iostream>
#include <stdlib.h>
#include <Aria.h>
#include <math.h>

#include "forward.h"
// Implementation

// Constructor
forward::forward() : ArAction("Go forward")
{

	speed = FULL_SPEED; // 0.5m/s
	deltaHeading; // 0 degrees

}

/*
void forward::setRobot(ArRobot *robot)
{

ArAction::setRobot(robot);


mySonar = robot->findRangeDevice("sonar");
if (robot == NULL)
{
ArLog::log(ArLog::Terse, "actionExample: ActionGo: Warning: I found no sonar, deactivating.");
deactivate();
}

}
*/


// Body of action
ArActionDesired * forward::fire(ArActionDesired d)
{
	
	speed = FULL_SPEED;
	
	deltaHeading = 0;
	printf(" Forward \n");

	desiredState.reset(); // reset the desired state (must be done)
	desiredState.setVel(speed); // set the speed of the robot in the desired state
	desiredState.setDeltaHeading(deltaHeading); // set the new angle
	
	//printf("%f %f %f\n", myRobot->getX(), myRobot->getY(), myRobot->getTh());
	//printf("\n sonar range = %i\n", range); //prints range reader of sonar 
	printf("\n my speed = %i", speed);
	
	return &desiredState; // give the desired state to the robot for actioning
}


