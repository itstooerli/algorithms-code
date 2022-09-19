///////////////////////////////////////////////////////////////////////////////
// You need to
//    1. Read the programming assignment in homework #6.
//    2. Implement function GetStudentName.
//    3. Implement function MinProcessingTime
//    4. Compile your code as explained in the PDF file.
//    5. Run the executable on small and large unit tests.
//    6. Test and debug your code. Make sure that your program does not have
//       any memory leaks.
//    7. Remove all commented out code. Double check that your program does not
//       print any debug information on the screen.
//    8. Submit your code ("student_code_6.h") via Canvas.
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

struct Profile
{
   int time {0};
   int energy {0};
};

int MinProcessingTime(const std::vector<std::vector<Profile>>& profiles,
                      int maxEnergy)
{
   // The number of cores is fixed. You can assume that it is always equal to 8.   
   const int nCores = 8;

   // Preprocessing
   int numJobs = profiles.size();
   int minTime;
   int optimalRemainingEnergyTime;
   int coreTime;
   std::vector<std::vector<int>> processingTimes;
   processingTimes.resize(numJobs, std::vector<int>(maxEnergy));

   // Base Cases (j = jobs, q = charges, k = cores)
   if (maxEnergy == 0) {
       return -1;
   }
   
   for (int q = 1; q <= maxEnergy; q++) {
       
       minTime = -1;
              
       for (int k = 0; k < nCores; k++) {

           if (profiles[0][k].energy <= q) {
               
               coreTime = profiles[0][k].time;

               if (minTime == -1 || coreTime < minTime) {
                   
                   minTime = coreTime;

               }

           }
       }

       processingTimes[0][q - 1] = minTime;
   }

   if (processingTimes[0][maxEnergy - 1] == -1) {
       return -1;
   }

   // Dynamic Programming (j = jobs, q = charges, k = cores)

   for (int j = 1; j < numJobs; j++) {
       
       for (int q = 1; q <= maxEnergy; q++) {
           
           minTime = -1;

           for (int k = 0; k < nCores; k++) {

               if (q - profiles[j][k].energy > 0) {

                   optimalRemainingEnergyTime = processingTimes[j - 1][q - 1 - profiles[j][k].energy];

                   if (optimalRemainingEnergyTime != -1) {

                       coreTime = profiles[j][k].time + optimalRemainingEnergyTime;

                       if (minTime == -1 || coreTime < minTime) {

                           minTime = coreTime;

                       }
                   }

               }

           }

           processingTimes[j][q - 1] = minTime;

       }
   }

   return processingTimes[numJobs - 1][maxEnergy - 1];
}
