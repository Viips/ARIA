// Signatures

class follow : public ArAction // Class action inherits from ArAction
{
public:
	follow(); // Constructor
	virtual ~follow() {}  // Destructor
	ArActionDesired * follow::fire(ArActionDesired d); // Body of the action
	ArActionDesired desiredState; // Holds state of the robot that we wish to action

	int speed; // Speed of the robot in mm/s
#define FULL_SPEED 500 // 0.5m/s
	
	double deltaHeading; // Change in heading

	// Reading from the Sonar
	double leftSonar, rightSonar;

	// Starting WANDERING coordinates
	double startWanderingX, startWanderingY;
	double WANDERINGDistance;

	// Control variables
	double error; // Current error
	double output; // Final output signal

	ArTime startedRandom;

	// distance thresholds
#define OBSTACLE_DISTANCE 100 // will not come into 0.1m of obstacles
#define FIND_WALL_DISTANCE 1000 // follow any wall edges detected within 1.0m
#define FOLLOW_WALL_DISTANCE 700 // at a constant distance of 0.7m

};
