// Signatures

class turning : public ArAction // Class action inherits from ArAction
{
public:
	turning(); // Constructor
	virtual ~turning() {}  // Destructor
	virtual ArActionDesired * fire(ArActionDesired d); // Body of the action
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

	//To find random angel between 0 and 140
	int randomHeading;

	ArTime startedRandom;
};
