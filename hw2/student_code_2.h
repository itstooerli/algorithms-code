///////////////////////////////////////////////////////////////////////////////
// You need to
//    1. Read the programming assignment in homework #2.
//    2. Implement function GetStudentName.
//    3. Implement function MinCost
//    4. Compile your code as explained in the PDF file.
//    5. Run the executable on small and large unit tests.
//    6. Test and debug your code. Make sure that your program does not have
//       any memory leaks.
//    7. Remove all commented out code. Double check that your program does not
//       print any debug information on the screen.
//    8. Submit your code ("student_code_2.h") via Canvas.
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

struct Price
{
   int sale {0};
   int after {0};
   int before {0};
};

int MinCost(const std::vector<Price>& giftPrices, int k)
{
   // Please, keep in mind that the sale price is not always 
   // less than the after and before Black Friday prices.

	int blackFridayCounter = 0;
	int priceAcc = 0;
	int numGifts = giftPrices.size();
	
	std::vector<Price> sortedPrices = giftPrices;		
	std::sort(sortedPrices.begin(), sortedPrices.end(), 
		[](Price i, Price j) {
			return (abs(i.sale - i.before - i.after + std::max({ i.sale, i.before, i.after })) > abs(j.sale - j.before - j.after + std::max({ j.sale, j.before, j.after }))); });
	
	for (int i = 0; i < numGifts; i++)
	{
		if (blackFridayCounter < k) {
			if ((sortedPrices[i].before <= sortedPrices[i].sale) || (sortedPrices[i].after <= sortedPrices[i].sale)) {
				priceAcc += std::min(sortedPrices[i].before, sortedPrices[i].after);
			}
			else {
				priceAcc += sortedPrices[i].sale;
				blackFridayCounter++;
			}
		}
		else {
			priceAcc += std::min(sortedPrices[i].before, sortedPrices[i].after);
		}
	}

   return priceAcc /* your answer */;
}