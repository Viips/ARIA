#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <Aria.h>
#include <math.h>

#include "mapping.h"


//Constructor
mapping::mapping() : ArAction("Go forward")
{
	//speed = FULL_SPEED; // 0.5m/s
	PI = 3.1415926535;
	update = true;

}

// Body of action
ArActionDesired * mapping::fire(ArActionDesired d)
{
	/*
	double leftRange = mySonar->currentReadingPolar(0, 100) - myRobot->getRobotRadius();
	double rightRange = mySonar->currentReadingPolar(-100, 0) - myRobot->getRobotRadius();
	double frontRange = mySonar->currentReadingPolar(50, -50) - myRobot->getRobotRadius();
	*/

	double range = 0;

	double mySonar = myRobot->checkRangeDevicesCurrentPolar(100, -100, &range);
	mySonar += myRobot->getRobotRadius();

	std::ofstream datafile;

	if (update) {
		datafile.open("coordinates.csv");

		update = false;
	} else {
		datafile.open("coordinates.csv", std::ofstream::app);
	}

	if (mySonar <= 5500) {
		

		double robotXaxis = myRobot->getX();
		double robotYaxis = myRobot->getY();

		//TH in degress
		double robotTh = myRobot->getTh() * (PI / 180);


		double xObj = cos(range * PI / 180) * mySonar;
		double yObj = sin(range * PI / 180) * mySonar;

		double xRotate = (xObj * cos(robotTh)) + (yObj * -sin(robotTh));
		double yRotate = (xObj * sin(robotTh)) + (yObj * cos(robotTh));

		xObj = xRotate + robotXaxis;
		yObj = yRotate + robotYaxis;


		datafile << xObj << "," << yObj << "," << "\n";
		
	}

	


	desiredState.reset(); // reset the desired state (must be done)
	//desiredState.setVel(speed); // set the speed of the robot in the desired state


	//printf("%f %f %f\n", myRobot->getX(), myRobot->getY(), myRobot->getTh());
	//printf("\n my speed = %i", speed);

	return &desiredState; // give the desired state to the robot for actionin

}