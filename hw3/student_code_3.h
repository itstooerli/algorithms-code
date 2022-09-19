///////////////////////////////////////////////////////////////////////////////
// You need to
//    1. Read the programming assignment in homework #3.
//    2. Implement function GetStudentName.
//    3. Implement function MinStations
//    4. Compile your code as explained in the PDF file.
//    5. Run the executable on small and large unit tests.
//    6. Test and debug your code. Make sure that your program does not have
//       any memory leaks.
//    7. Remove all commented out code. Double check that your program does not
//       print any debug information on the screen.
//    8. Submit your code ("student_code_3.h") via Canvas.
///////////////////////////////////////////////////////////////////////////////

//required libraries
#include <string>
#include <vector>

//you can include standard C++ libraries here
#include <algorithm>

// This function should return your name.
// The name should match your name in Canvas

void GetStudentName(std::string& your_name)
{
   //replace the placeholders "Firstname" and "Lastname"
   //with you first name and last name
   your_name.assign("Eric Li");
}

int MinStations(int roadLength, int range, std::vector<int> towers)
{

   /* implement your algorithm here */
   /* you can modify or sort vector **towers** if you want */

	std::sort(towers.begin(), towers.end());
	int numTowers = towers.size();
	std::vector<int> validStack;
	int min = 0;
	int count = 0;
	int nextMin = 0;

	for (int i = 0; i < numTowers; i++) {

		if (towers[i] - range <= min) {
			validStack.push_back(towers[i]);
		}
		else {

			if (validStack.empty()) { return -1; }

			min = nextMin;
			nextMin = validStack.back() + range;
			validStack.pop_back();
			count++;

			if (towers[i] - range <= min) {
				validStack.push_back(towers[i]);
			}
			else {

				if (validStack.empty()) { return -1; }

				min = validStack.back() + range;
				validStack.pop_back();
				count++;


				if (towers[i] - range <= min) {
					validStack.push_back(towers[i]);
				}
				else {
					return -1;
				}
			}
		}

		if (min >= roadLength) return count;
	}

	if (count == 0) {
		if (validStack.back() + range >= roadLength) {
			validStack.pop_back();
			count++;
		}
		else {
			return -1;
		}
		
		if (validStack.empty()) { return -1; }

		if (validStack.back() + range >= roadLength) {
			validStack.pop_back();
			count++;
		}
		else {
			return -1;
		}
	}
	else if (!validStack.empty() && nextMin < roadLength) {
		if (validStack.back() + range >= roadLength) {
			validStack.pop_back();
			count++;
		}
		else {
			return -1;
		}

		if (validStack.empty()) { return -1; }
		
		if (validStack.back() + range >= roadLength) {
			validStack.pop_back();
			count++;
		}
		else {
			return -1;
		}
	}
	else if (!validStack.empty() && min < roadLength && nextMin >= roadLength) {
		validStack.pop_back();
		count++;
	}

   return count /* your answer */;
}
