#include <iostream>
#include <stdlib.h>
#include <Aria.h>
#include <math.h>

#include "wander.h"


// Calculates a random number between min and max inclusive
int randomNoBetween(int min, int max) {
	return rand() % (max - min + 1) + min;
}

// Pythagoras theorem for calcuation distance to use in random turning
double distBetween(double x1, double y1, double x2, double y2) {
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}



//Constructor
wander::wander() : ArAction("Go forward")
{
	speed = FULL_SPEED; // 0.5m/s
	deltaHeading = 0; // 0 degrees
	
	// Random distance betwen 0.5m and 1.5m
	//WANDERINGDistance = rand() % (1500 - 500 + 1) + 500;
	
	startWanderingX = 0;
	startWanderingY = 0;

	
	//To find random angel between 0 and 140
	randomHeading = rand() % (140 - 0 + 1) + 0;
	
	

}



// Body of action
ArActionDesired * wander::fire(ArActionDesired d)
{
	frontSonar = myRobot->getClosestSonarRange(-20, 20);
	speed = FULL_SPEED;

	currentDistance = distBetween(startWanderingX, startWanderingY,
		myRobot->getX(), myRobot->getY());

	if ((frontSonar > 1500) && (currentDistance > WANDERINGDistance)) {
			printf("\nTurning RANDOMLY \n");

			//Decreasing speed before making the turn
			speed = 0;
			deltaHeading = randomHeading;

			if (randomNoBetween(0, 1) == 0) {
				deltaHeading = -deltaHeading;	
			}

			if (startedRandom.mSecSince() > 2000) {
				startWanderingX = myRobot->getX();
				startWanderingY = myRobot->getY();
				WANDERINGDistance = rand() % (1500 - 500 + 1) + 500;
			}
		}

	desiredState.reset(); // reset the desired state (must be done)
	desiredState.setVel(speed); // set the speed of the robot in the desired state
	desiredState.setDeltaHeading(deltaHeading); // set the new angle

	//printf("\n DeltaHeading ===== %d \n", deltaHeading);

	//printf("%f %f %f\n", myRobot->getX(), myRobot->getY(), myRobot->getTh());
	//printf("\n my speed = %i", speed);

	//printf("\n current Distance %d \n wandering Distance %d", currentDistance, WANDERINGDistance);
	return &desiredState; // give the desired state to the robot for actionin

}
