// Signatures

class avoid : public ArAction // Class action inherits from ArAction
{
public:
	avoid(); // Constructor
	virtual ~avoid() {}  // Destructor
	ArActionDesired * avoid::fire(ArActionDesired d); // Body of the action
	ArActionDesired desiredState; // Holds state of the robot that we wish to action

	int speed; // Speed of the robot in mm/s
	// speeds
#define FULL_SPEED 500 // 0.5m/s
	//int maxSpeed;
	//bool accelration;
	double deltaHeading; // Change in heading


	// Starting WANDERING coordinates
	double startWanderingX, startWanderingY;
	double WANDERINGDistance;

	double leftSonar, rightSonar, frontSonar;


	// distance thresholds
#define OBSTACLE_DISTANCE 100 // will not come into 0.1m of obstacles



	

};
