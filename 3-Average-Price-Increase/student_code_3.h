/////////////////////////////////////////////////////////////
// You need to
//    1. Read the programming assignment in homework #3.
//    2. Implement function GetStudentName.
//    3. Implement function AvgPriceIncrease
//    4. Run the executable on small and large unit tests.
//    5. Test and debug your code. Make sure that your 
//       program does not have any memory leaks.
//    6. Remove all commented out code. Double check that your
//       program does not print any debug information on the 
//       screen.
//    7. Submit your code ("student_code_3.h")
//       via Canvas.
/////////////////////////////////////////////////////////////

//required libraries
#include <string>
#include <vector>
#include <cmath>

//you can include standard C++ libraries here


/////////////////////////////////////////////////////////////
// In this problem, you can use a Fenwick Tree.
// Here is a slightly modified Fenwick Tree implementation 
// from Wikipedia:
//  * https://en.wikipedia.org/wiki/Fenwick_tree
//

class FenwickTree 
{
private:
   std::vector<int> data;

   int GetParent(int i) const 
   {
      return i - (i & (-i));
   }

   int GetNext(int i) const 
   {
      return i + (i & (-i));
   }

public:
   // Create a Fenwick Tree for n variables.
   // Initially, all values are set to 0.

   FenwickTree(int n) : data(n+1, 0) {}

   // Get the sum of the first k variables. If
   // variables are x[0],...,x[n-1], then the 
   // function returns:
   //   x[0] + x[1] ... + x[k-1] for k > 0; and
   //   0 for k == 0

   int GetPartialSum(int k) const 
   {
      int sum = 0;
      while (k > 0) 
      {
         sum += data[k];
         k = GetParent(k);
      }
      return sum;
   }

   //Increase variable i by delta.
   void Update(int i, int delta) 
   {
      ++i;
      while (i < data.size()) 
      {
         data[i] += delta;
         i = GetNext(i);
      }
   }
};

/////////////////////////////////////////////////////////////
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

struct PriceUpdate
{
   int restaurantID;
   int premium;
};

int AvgPriceIncrease(const std::vector<int>& prices,
                     const std::vector<PriceUpdate>& updates,
                     int radius)
{
  // Preprocessing
  int numRestaurants = prices.size();
  FenwickTree ftree(numRestaurants);
  for (int i = 0; i < numRestaurants; i++){
    ftree.Update(i, prices[i]);
  }
  int initTotal = ftree.GetPartialSum(numRestaurants);

  // Price Updates
  int numUpdates = updates.size();
  int neighborhoodRange = 2 * radius + 1;

  for (int i = 0; i < numUpdates; i++){
    // Initialize variables for current restaurant
    int rID = updates[i].restaurantID;
    int premium = updates[i].premium;
    int downstream = rID - radius;
    int upstream = rID + radius + 1;
    bool isCornerRestaurant = false;

    // Check Corner Cases
    if (downstream < 0){
      downstream = numRestaurants + downstream;
      isCornerRestaurant = true;
    }
    
    if (upstream > numRestaurants){
      upstream = upstream - numRestaurants;
      isCornerRestaurant = true;
    }
    
    // Find New Price and Update Fenwick Tree
    int newPrice;
    int down = ftree.GetPartialSum(downstream);
    int up = ftree.GetPartialSum(upstream);

    if (isCornerRestaurant){
      int total = ftree.GetPartialSum(numRestaurants);
      newPrice = std::floor((total - down + up) / neighborhoodRange) + premium;
    }
    else{
      newPrice = std::floor((up - down) / neighborhoodRange) + premium;
    }

    int oldVal = ftree.GetPartialSum(rID + 1) - ftree.GetPartialSum(rID);
    int delta = newPrice - oldVal;
    ftree.Update(rID, delta);
  }

  // Return the average price increase
  return std::floor((ftree.GetPartialSum(numRestaurants) - initTotal) / numRestaurants);
}