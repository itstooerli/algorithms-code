///////////////////////////////////////////////////////////////////////////////
// You need to
//    1. Read the programming assignment in homework #4.
//    2. Implement function GetStudentName.
//    3. Implement function MinCost.
//    4. Compile your code as explained in the PDF file.
//    5. Run the executable on small and large unit tests.
//    6. Test and debug your code. Make sure that your program does not have
//       any memory leaks.
//    7. Remove all commented out code. Double check that your program does not
//       print any debug information on the screen.
//    8. Submit your code ("student_code_4.h") via Canvas.
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

int MinCost(const std::vector<int>& prices, int fee)
{
	int numGames = prices.size();
	std::vector<int> tickets(numGames);

	for (int i = 0; i < numGames; i++) {
		if (i == 0) {
			tickets[i] = prices[i] - floor(prices[i] / 10) + fee;
		}
		else if (i == 1 || i == 2 || i == 3) {
			tickets[i] = tickets[i - 1] + prices[i] - floor(prices[i] / 10) + fee;	
		}
		else if (i == 4) {
			int oneGameTicket = tickets[i - 1] + prices[i] - floor(prices[i] / 10) + fee;
			int fiveGameTicket = prices[i - 4] + prices[i - 3] + prices[i - 2] + prices[i - 1] + prices[i] + fee;
			tickets[i] = std::min(oneGameTicket, fiveGameTicket);
		}
		else {
			int oneGameTicket = tickets[i - 1] + prices[i] - floor(prices[i] / 10) + fee;
			int fiveGameTicket = tickets[i - 5] + prices[i - 4] + prices[i - 3] + prices[i - 2] + prices[i - 1] + prices[i] + fee;
			tickets[i] = std::min(oneGameTicket, fiveGameTicket);
		}
	}
   /* implement your algorithm here */

	return tickets[numGames - 1]; /* your answer */;
}
