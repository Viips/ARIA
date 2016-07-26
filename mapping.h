class mapping : public ArAction // Class action inherits from ArAction
{
public:
	mapping(); // Constructor
	virtual ~mapping() {}  // Destructor
	ArActionDesired * mapping::fire(ArActionDesired d); // Body of the action
	ArActionDesired desiredState; // Holds state of the robot that we wish to action
	//virtual void mapping::setRobot(ArRobot *myRobot);

	int speed; // Speed of the robot in mm/s
	// speeds
#define FULL_SPEED 500 // 0.5m/s
	//int maxSpeed;
	//bool accelration;


	//Sonar 
	ArRangeDevice *mySonar;


	boolean update;

	double PI;

	/*
	double rightRange, leftRange, frontRange;

	double robotX, robotY, robotTh, robotHeading;

	double cCosD, cSinD;


	double findcosTh, findsinTh, findMsinTh;


	double newX, newY;


	double globalX, globalY;
	*/
};