#include <iostream>
#include <stdlib.h>
#include <Aria.h>
#include <math.h>

#include "follow.h"

// Calculates a random number between min and max inclusive
int ranNoBetween(int min, int max) {
	return rand() % (max - min + 1) + min;
}

// PID variables
double dState; // Last position input
double integratorState; // Integrator state
double iMax, iMin;

// Maximum and minimum allowable integrator state integral gain, proportional gain and derivative gain
double integralGain;
double proportionalGain;
double derivativeGain;

//Constructor
follow::follow() : ArAction("Go forward")
{
	speed = FULL_SPEED; // 0.5m/s
	deltaHeading = 0; // 0 degrees

	//Update PID values
	integralGain = 0;
	proportionalGain = 0.02;
	derivativeGain = 2;

	// Random distance betwen 0.5m and 1.5m
	WANDERINGDistance = ranNoBetween(500, 1500);
	error;

}

// Updates the PID values 
double updatePID(double error, double position)
{
	double proportionalTerm, derivativeTerm, integralTerm;

	// calculate the proportional term
	proportionalTerm = proportionalGain * error;

	// calculate the integral state with appropriate limiting
	integratorState += error;
	if (integratorState > iMax) {
		integratorState = iMax;
	} else if (integratorState < iMin) {
		integratorState = iMin;
	}

	// calculate the integral term
	integralTerm = integralGain * integratorState;
	derivativeTerm = derivativeGain * (position - dState);
	dState = position;

	return proportionalTerm + integralTerm - derivativeTerm;
}



// Body of action
ArActionDesired * follow::fire(ArActionDesired d)
{
	// Read sonar readings
	leftSonar = myRobot->getClosestSonarRange(-20, 100);
	rightSonar = myRobot->getClosestSonarRange(-100, 20);
	
	// Looking for error
	if (leftSonar < (2 * FOLLOW_WALL_DISTANCE)) { // Left < 1m
		printf(" Following wall LEFT \n");
		speed = FULL_SPEED;
		error = (FOLLOW_WALL_DISTANCE - leftSonar);
		deltaHeading = -updatePID(error, leftSonar);
		desiredState.setDeltaHeading(deltaHeading);
		
	}
	
	
	// Looking for error
	if (rightSonar < (2 * FOLLOW_WALL_DISTANCE)) { // Right < 1m
		printf(" Following wall RIGHT \n");
		speed = FULL_SPEED;
		error = -(rightSonar - FOLLOW_WALL_DISTANCE);
		deltaHeading = updatePID(error, rightSonar);
		desiredState.setDeltaHeading(deltaHeading);
		
	}
	
	

	desiredState.reset(); // reset the desired state (must be done)
	desiredState.setVel(speed); // set the speed of the robot in the desired state
	desiredState.setDeltaHeading(deltaHeading); // set the new angle

	//printf("%f %f %f\n", myRobot->getX(), myRobot->getY(), myRobot->getTh());
	//printf("\n my speed = %i", speed);


	
	return &desiredState; // give the desired state to the robot for actionin

}
