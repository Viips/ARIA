#include <iostream>
#include <stdlib.h>
#include <Aria.h>
#include <math.h>

#include "avoid.h"


//Constructor
avoid::avoid() : ArAction("Go forward")
{
	speed = FULL_SPEED; // 0.5m/s
	deltaHeading = 0; // 0 degrees

}



// Body of action
ArActionDesired * avoid::fire(ArActionDesired d)
{
	leftSonar = myRobot->getClosestSonarRange(0, 30);
	rightSonar = myRobot->getClosestSonarRange(-30, 0);

	if (leftSonar < (OBSTACLE_DISTANCE + 1100)) {
		printf(" OBSTACLE <--left \n");
		speed = 0;
		deltaHeading = -30;
		desiredState.setDeltaHeading(deltaHeading); // set the new angle
	} else if (rightSonar < (OBSTACLE_DISTANCE + 1100)) {
		printf(" OBSTACLE right--> \n");
		speed = 0;
		deltaHeading = 30;
		desiredState.setDeltaHeading(deltaHeading); // set the new angle
	} else {
		speed = FULL_SPEED;
		deltaHeading = 0;
		desiredState.setDeltaHeading(deltaHeading); // set the new angle
	}

	desiredState.reset(); // reset the desired state (must be done)
	desiredState.setVel(speed); // set the speed of the robot in the desired state
	desiredState.setDeltaHeading(deltaHeading); // set the new angle

	//printf("%f %f %f\n", myRobot->getX(), myRobot->getY(), myRobot->getTh());
	//printf("\n my speed = %i", speed);

	return &desiredState; // give the desired state to the robot for actionin

}