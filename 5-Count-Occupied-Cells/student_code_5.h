///////////////////////////////////////////////////////////////////////
// You need to
//    1. Read the programming assignment in homework #5.
//    2. Implement function GetStudentName.
//    3. Implement function CountOccupiedCells
//    4. Compile your code as explained in the PDF file.
//    5. Run the executable on small and large unit tests.
//    6. Test and debug your code. Make sure that your program does
//       not have any memory leaks.
//    7. Remove all commented out code. Double check that your program
//       does not print any debug information on the screen.
//    8. Submit your code ("student_code_5.h")
//       via Canvas.
///////////////////////////////////////////////////////////////////////

//required libraries
#include <string>
#include <vector>
#include <utility>

//you can include standard C++ libraries here

// This function should return your name.
// The name should match your name in Canvas

std::string GetStudentName()
{
   //replace the placeholders "Firstname" and "Lastname"
   //with you first name and last name
   return "Firstname Lastname";
}

std::string  DefaultProblemSet()
{
   return "small";
}

int CountOccupiedCells(const std::vector<double>& hLines, 
                       const std::vector<double>& vLines, 
                       const std::vector<std::pair<double,double>>& rabbits)
{

   return 0 /* your answer */;
}

