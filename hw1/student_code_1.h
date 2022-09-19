///////////////////////////////////////////////////////////////////////////////
// You need to
//    1. Read the programming assignment in homework #1.
//    2. Implement function GetStudentName.
//    3. Implement function FindKey.
//    4. Compile your code as explained in the PDF file.
//    5. Run the executable on small and large unit tests.
//    6. Test and debug your code. Make sure that your program does not have
//       any memory leaks.
//    7. Remove all commented out code. Double check that your program does not
//       print any debug information on the screen.
//    8. Submit your source code ("student_code_1.h") on Canvas.
///////////////////////////////////////////////////////////////////////////////

//required libraries
#include <string>
#include <vector>

//you can include standard C++ libraries here
#include "test_framework.h"
#include <set>

// This function should return your name.
// The name should match your name in Canvas

void GetStudentName(std::string& your_name)
{
   //replace the placeholders "Firstname" and "Lastname"
   //with you first name and last name
   
   your_name.assign("Eric Li");
}

// You can use the following function to decrypt a message encryptedName
// using key.
// Note: This is a toy cipher. It is not secure! Do not use it in practice!
std::string decrypt(const std::vector<int>& encryptedName, int key)
{
   constexpr int arrayLength = 26;   
   constexpr int alphabetSize = 26;
   constexpr int nCharacters = alphabetSize + 2;
   constexpr int64_t prime = 2147483647;
   constexpr int64_t a = 514229;
   constexpr int64_t b = 347;

   std::string result;
   result.reserve(arrayLength - 1);

   if (encryptedName.size() != arrayLength) return result;

   int64_t longKey = abs(key) % prime;
   int64_t salt = abs(encryptedName[0]) % prime;
   int64_t x = (longKey + salt + prime) % prime;
   int delay = (salt % arrayLength);

   while (delay-- > 0)
   {
      x = (a + b * x) % prime;
   }

   int i = 1;
   int code = 0;   
   while ((i < arrayLength) && (code < nCharacters - 1))
   {
      x = (a + b * x) % prime;
      assert(x >= 0);
      code = (encryptedName[i] + x) % nCharacters;
      if (code < alphabetSize) result += ('a' + code);
      if (code == alphabetSize) result += ' ';
      i++;
   }

   return result;
}

int FindKey(const std::vector<int>& encryptedName, 
            int n, 
            const std::string& restaurantList)
{
    std::set<std::string> restaurantSet;
    std::string delimiter = ";";
    size_t last = 0;
    size_t next = 0;
    std::string decryptedRestaurant;

    while ((next = restaurantList.find(delimiter, last)) != std::string::npos) {
        restaurantSet.insert(restaurantList.substr(last, next - last));
        last = next + 1;
    }

    for (size_t i = 0; i < n; i++) {
        
        decryptedRestaurant = decrypt(encryptedName, i);
        
        if (decryptedRestaurant.length() > 0) {

            if (restaurantSet.find(decryptedRestaurant) != restaurantSet.end()) return i;
        }
    }

   return -1; /* your answer */
}