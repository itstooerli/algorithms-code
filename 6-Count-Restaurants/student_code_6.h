///////////////////////////////////////////////////////////////////////
// You need to
//    1. Read the programming assignment in homework #6.
//    2. Implement function GetStudentName.
//    3. Implement function ABRestaurantCount
//    4. Compile your code as explained in the PDF file.
//    5. Run the executable on small and large unit tests.
//    6. Test and debug your code. Make sure that your program does
//       not have any memory leaks.
//    7. Remove all commented out code. Double check that your program
//       does not print any debug information on the screen.
//    8. Submit your code ("student_code_6.h")
//       via Canvas.
///////////////////////////////////////////////////////////////////////

//required libraries
#include <string>
#include <vector>
#include <utility>

#include <math.h>
#include <algorithm>
//you can include standard C++ libraries here

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
   return "small";
}

int block;
typedef std::pair<std::pair<int,int>, int> queryWithIndex;

// moCompare sorts by block, then by finish time within the block
bool moCompare(queryWithIndex a, queryWithIndex b){
  
  int aStartTime = a.first.first;
  int aFinishTime = a.first.second;
  int bStartTime = b.first.first;
  int bFinishTime = b.first.second;

  if (aStartTime/block != bStartTime/block){
    return aStartTime/block < bStartTime/block;
  }

  return aFinishTime < bFinishTime;
}

std::vector<int> CountABRestaurants(const std::vector<int>& alice, 
                                    const std::vector<int>& bob, 
                                    const std::vector<std::pair<int, int>>& queries)
{   
  // Preprocessing
  int nQueries = queries.size();
  std::vector<int> answers(nQueries, -1);
  
  int nVisits = alice.size(); // Assumed that alice.size() == bob.size()
  block = sqrt(nVisits); // Integer Rounding
  std::vector<queryWithIndex> processedQueries;
  
  for (int i = 0; i < nQueries; i++){
    processedQueries.push_back(std::make_pair(queries[i], i));
  }
  
  sort(processedQueries.begin(), processedQueries.end(), moCompare);

  // Initializing for Mo's Algorithm
  int prevStartTime = 0;
  int prevFinishTime = 0;
  int currTotal = 0;

  // restaurantCount is used to track how many times Alice and Bob have visited restaurantID; 
  // Alice's count is pair.first;
  // Bob's count is pair.second;
  int maxRestaurantID = std::max(*std::max_element(alice.begin(), alice.end()), *std::max_element(bob.begin(), bob.end()));
  
  std::vector<std::pair<int,int>> restaurantCount(maxRestaurantID + 1, std::make_pair(0,0));

  // Mo's Algorithm
  for (int i = 0; i < nQueries; i++){
    int currStartTime = processedQueries[i].first.first;
    int currFinishTime = processedQueries[i].first.second;
    int queryNo = processedQueries[i].second;

    // Add new elements at end of range - necessary first to populate upon initialization
    while (prevFinishTime <= currFinishTime){
      int aliceVisit = alice[prevFinishTime];
      int bobVisit = bob[prevFinishTime];

      restaurantCount[aliceVisit].first++;
      if (restaurantCount[aliceVisit].first == 1 && restaurantCount[aliceVisit].second > 0){
        currTotal++;
      }
      
      restaurantCount[bobVisit].second++;
      if (restaurantCount[bobVisit].first > 0 && restaurantCount[bobVisit].second == 1){
        currTotal++;
      }
      
      prevFinishTime++;
    }

    // Remove old elements at end of range
    while (prevFinishTime > currFinishTime + 1){
      prevFinishTime--;
      int aliceVisit = alice[prevFinishTime];
      int bobVisit = bob[prevFinishTime];
      
      restaurantCount[aliceVisit].first--;
      if (restaurantCount[aliceVisit].first == 0 && restaurantCount[aliceVisit].second > 0){
        currTotal--;
      }
      
      restaurantCount[bobVisit].second--;
      if (restaurantCount[bobVisit].first > 0 && restaurantCount[bobVisit].second == 0){
        currTotal--;
      }
    }

    // Remove old elements at beginning of range
    while (prevStartTime < currStartTime){
      int aliceVisit = alice[prevStartTime];
      int bobVisit = bob[prevStartTime];

      restaurantCount[aliceVisit].first--;
      if (restaurantCount[aliceVisit].first == 0 && restaurantCount[aliceVisit].second > 0){
        currTotal--;
      }
      
      restaurantCount[bobVisit].second--;
      if (restaurantCount[bobVisit].first > 0 && restaurantCount[bobVisit].second == 0){
        currTotal--;
      }
      
      prevStartTime++;
    }

    // Add new elements at beginning of range
    while (prevStartTime > currStartTime){
      prevStartTime--;
      int aliceVisit = alice[prevStartTime];
      int bobVisit = bob[prevStartTime];
      
      restaurantCount[aliceVisit].first++;
      if (restaurantCount[aliceVisit].first == 1 && restaurantCount[aliceVisit].second > 0){
        currTotal++;
      }
      
      restaurantCount[bobVisit].second++;
      if (restaurantCount[bobVisit].first > 0 && restaurantCount[bobVisit].second == 1){
        currTotal++;
      }
    }

    answers[queryNo] = currTotal;
  }

  //answer[i] must contain the answer to the i-th query
  return answers;
}