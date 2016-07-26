// Signatures

class forward : public ArAction // Class action inherits from ArAction
{
public:
	forward(); // Constructor
	virtual ~forward() {}  // Destructor
	ArActionDesired * forward::fire(ArActionDesired d); // Body of the action
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



};