///////////////////////////////////////////////////////////////////////////////
// You need to
//    1. Read the programming assignment in homework #5.
//    2. Implement function GetStudentName.
//    3. Implement function MaxTour
//    4. Compile your code as explained in the PDF file.
//    5. Run the executable on small and large unit tests.
//    6. Test and debug your code. Make sure that your program does not have
//       any memory leaks.
//    7. Remove all commented out code. Double check that your program does not
//       print any debug information on the screen.
//    8. Submit your code ("student_code_5.h") via Canvas.
///////////////////////////////////////////////////////////////////////////////

//required libraries
#include <string>
#include <vector>

//you can include standard C++ libraries here

// This function should return your name.
// The name should match your name in Canvas

void GetStudentName(std::string& your_name)
{
   //replace the placeholders "Firstname" and "Lastname"
   //with you first name and last name
   your_name.assign("Eric Li");
}

struct Point
{
   double x{0.0};
   double y{0.0};
};

int MaxTour(const std::vector<Point>& points, double maxDistance)
{
	// Variables
	int numSites = points.size() + 1;
	double minDistance;
	double tempDistance;

	// Preprocessing
	std::vector<std::vector<double>> routes;
	routes.resize(numSites, std::vector<double>(numSites));
	
	// Base Cases
	routes[0][0] = 0;
	for (int startingSites = 1; startingSites < numSites; startingSites++) {
		routes[startingSites][0] = sqrt(pow(points[startingSites - 1].x, 2) + pow(points[startingSites - 1].y, 2));
	}
	
	// Recurrence Relations
	for (int travelSpace = 1; travelSpace < numSites; travelSpace++) {
		for (int startingSite = 0; startingSite < numSites - travelSpace; startingSite++) {

			if (startingSite == 0) {
				minDistance = sqrt(pow(points[startingSite].x, 2) + pow(points[startingSite].y, 2)) + routes[startingSite + 1][travelSpace - 1];
			}
			else {
				minDistance = sqrt(pow((points[startingSite - 1].x - points[startingSite].x), 2) + pow((points[startingSite - 1].y - points[startingSite].y), 2)) + routes[startingSite + 1][travelSpace - 1];
			}

			for (int exploreZone = startingSite + 1; exploreZone < numSites - travelSpace; exploreZone++) {
				if (startingSite == 0) {
					tempDistance = sqrt(pow(points[exploreZone].x, 2) + pow(points[exploreZone].y, 2)) + routes[exploreZone + 1][travelSpace - 1];
				}
				else {
					tempDistance = sqrt(pow((points[startingSite - 1].x - points[exploreZone].x), 2) + pow((points[startingSite - 1].y - points[exploreZone].y), 2)) + routes[exploreZone + 1][travelSpace - 1];
				}

				if (tempDistance < minDistance) {
					minDistance = tempDistance;
				}

			}

			routes[startingSite][travelSpace] = minDistance;

			// Return early if mininum path given travel space already exceeds maxDistance
			if (startingSite == 0 && routes[startingSite][travelSpace] >= maxDistance) {
				return travelSpace - 1;
			}
		}
	}

	return numSites - 1;
}
