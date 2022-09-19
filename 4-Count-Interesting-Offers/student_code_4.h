///////////////////////////////////////////////////////////////////////
// You need to
//    1. Read the programming assignment in homework #4.
//    2. Implement function GetStudentName.
//    3. Implement function CountInterestingOffers
//    4. Compile your code as explained in the PDF file.
//    5. Run the executable on small and large unit tests.
//    6. Test and debug your code. Make sure that your program does
//       not have any memory leaks.
//    7. Remove all commented out code. Double check that your program
//       does not print any debug information on the screen.
//    8. Submit your code ("student_code_4.h")
//       via Canvas.
///////////////////////////////////////////////////////////////////////

//required libraries
#include <string>
#include <vector>
#include <utility>

//you can include standard C++ libraries here
#include <algorithm>
#include <set>

// This function should return your name.
// The name should match your name in Canvas

std::string GetStudentName()
{
   //replace the placeholders "Firstname" and "Lastname"
   //with you first name and last name
   return "Eric Li";
}

std::string  DefaultProblemSet()
{
   return "large";
}

int CountInterestingOffers(std::vector<std::pair<double, double>> offers)
{
  // Sort by x in descending order and compare y values
  // Set new larger y values as new lower y bound
  
  sort(offers.rbegin(), offers.rend());

  int count = 0;
  double minY = offers[0].second;
  count++;

  for (int i = 1; i < offers.size(); i++){
    if (offers[i].second > minY){
      minY = offers[i].second;
      count++;
    }
  }

  return count;
}