///////////////////////////////////////////////////////////////////////
// You need to
//    1. Read the programming assignment in homework #2.
//    2. Implement function CountMostPopularShows
//    3. Run the executable on small and large unit tests.
//    4. Test and debug your code. Make sure that your program does
//       not have any memory leaks.
//    5. Remove all commented out code. Double check that your program
//       does not print any debug information on the screen.
//    6. Submit your code ("student_code_2.h")
//       via Canvas.
///////////////////////////////////////////////////////////////////////

//required libraries
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

// You can include standard C++ libraries here

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

struct Interval
{
   int start = -1;
   int finish = -1;
   int userID = -1;
};

/// Definition of an event tuple
// 1) Time of the event as an integer
// 2) Integer in the set {0,1,2} where
// ----- 0 indicates the start of a new show
// ----- 1 indicates the start of a user watching a show on a new medium
// ----- 2 indicates the end of a user watching a show on a medium
// 3) The UserID of the user, where a show start time is arbitrarily given -1
typedef std::tuple<int, int, int> event;

int CountMostPopularShows(const std::vector<Interval>& intervals, 
                          const std::vector<int>& showStartTimes, 
                          int threshold)
{
  // Preprocessing
  std::priority_queue<event, std::vector<event>, std::greater<event>> eventQueue;
  
  for (int time : showStartTimes){
    eventQueue.push(std::make_tuple(time, 0, -1));
  }
  
  for (Interval i : intervals){
    eventQueue.push(std::make_tuple(i.start, 1, i.userID));
    eventQueue.push(std::make_tuple(i.finish, 2, i.userID));
  }

  bool isNewShow = false;
  std::unordered_map<int, int> userBase;
  int concurrentUsers = 0;
  int popularShowCount = 0;

  // Review all events
  while (!eventQueue.empty()){
    event currentEvent = eventQueue.top();
    int eventType = std::get<1>(currentEvent);

    if (eventType == 0){
      isNewShow = true;
    }
    else if (eventType == 1){
      // User started watching on a new medium:
      // If not in map, add to map with count 1 and increment concurrent users count 
      // If in map and 0 user count, increment user's count in map and increment concurrent users count
      // If in map and at least 1 user count, only increment user's count in map 
      int currentUser = std::get<2>(currentEvent);
      if (userBase.find(currentUser) == userBase.end() || userBase[currentUser] == 0){
        userBase[currentUser] = 1;
        concurrentUsers++;
      }
      else{
        userBase[currentUser]++;
      }
    }
    else{
      // User ended watching on a medium:
      // If user count in map 1, decrement in map and decrememnt concurrent users count
      // If user count in map greater than 1, decrement only in map 
      int currentUser = std::get<2>(currentEvent);
      if (userBase[currentUser] == 1){
        concurrentUsers--;
      }
      userBase[currentUser]--;
    }

    // If show is not already popular and concurrent user count greater than or equal to threshold, increment popular show count and reset new show to false)
    // Note: If keeping track of shows, then add to Set here.
    if (isNewShow && concurrentUsers >= threshold){
      popularShowCount++;
      isNewShow = false;
    }

    eventQueue.pop();
  }

  return popularShowCount;
}