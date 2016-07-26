#include <iostream>
#include <stdlib.h>
#include <Aria.h>
#include <math.h>

#include "turning.h"

/*
// Calculates a random number between min and max inclusive
int randomNoBetween(int min, int max) {
	return rand() % (max - min + 1) + min;
}

// Pythagoras theorem for calcuation distance to use in random turning
double distBetween(double x1, double y1, double x2, double y2) {
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}



//Constructor
turning::turning() : ArAction("Go forward")
{
	speed = FULL_SPEED; // 0.5m/s
	deltaHeading = 0; // 0 degrees

	// Random distance betwen 0.5m and 1.5m
	WANDERINGDistance = randomNoBetween(500, 1500);

	startWanderingX = 0;
	startWanderingY = 0;
	
	//To find random angel between 0 and 140
	randomHeading = rand() % (140 - 0 + 1) + 0;

}


// Body of action
ArActionDesired * turning::fire(ArActionDesired d)
{
	double currentDistance = distBetween(startWanderingX, startWanderingY,
		myRobot->getX(), myRobot->getY());

	if (currentDistance > WANDERINGDistance) {
		printf("\nTurning RANDOMLY \n");
		
		//Decreasing speed before making the turn
		speed = 0;

		// Making a random turn between angle of 0 and 140
		deltaHeading = randomNoBetween(0, 140);
		
		
		
		if (randomNoBetween(0, 1) == 0) {
			deltaHeading = -deltaHeading;
		}
		
		
		if (startedRandom.mSecSince() > 2000) {
			
			startWanderingX = myRobot->getX();
			startWanderingY = myRobot->getY();
			WANDERINGDistance = randomNoBetween(500, 1500);
		}
		
		
		
	}


	desiredState.reset(); // reset the desired state (must be done)
	desiredState.setVel(speed); // set the speed of the robot in the desired state
	desiredState.setDeltaHeading(deltaHeading); // set the new angle

	//printf("%f %f %f\n", myRobot->getX(), myRobot->getY(), myRobot->getTh());
	//printf("\n my speed = %i \n", speed);

	//printf("\n DeltaHeading ===== %d \n", deltaHeading);

	return &desiredState; // give the desired state to the robot for actionin


}
*/