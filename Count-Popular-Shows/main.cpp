/////////////////////////////////////////////////////////////////////////
// DO NOT EDIT THIS FILE
//
// Compile this file using clang++, g++, or 
// Microsoft Visual Studio C++ compiler.
//
// To compile using Clang type:
//    clang++ main.cpp -O3 -std=c++17 -o main

#include <string>
#include <vector>
#include "test_framework.h"
#include "student_code_2.h"

const char* smallDataset = "small_problem_set_2.in";
const char* largeDataset = "large_problem_set_2.in";

const char*  helpMsg = "Please, indicate which problem set to use.\n\n"
                       "For small problem set, type: ./problem_solver_2 small\n"
                       "For large problem set, type: ./problem_solver_2 large\n";

const char* strNotice = "##################################\n"
                        "# Do not edit this file!\n"
                        "##################################\n";

constexpr int problem_set_id = 2;

struct ProblemN2: public TestFramework::BasicProblem
{
   std::vector<int> start_times;
   std::vector<int> finish_times;
   std::vector<int> user_ids;
   std::vector<int> show_start_times;
   int threshold;
};

int CountMostPopularShows(const std::vector<int>& start_times, 
                          const std::vector<int>& finish_times, 
                          const std::vector<int>& user_ids, 
                          const std::vector<int>& show_start_times, 
                          int threshold)
{
   int nIntervalCount = start_times.size();
   assert(finish_times.size() == nIntervalCount);
   assert(user_ids.size() == nIntervalCount);

   std::vector<Interval> intervals(nIntervalCount);

   for (int i = 0; i < nIntervalCount; ++i)
   {
       intervals[i].start = start_times[i];
       intervals[i].finish = finish_times[i];
       intervals[i].userID = user_ids[i];
   }
     

   return CountMostPopularShows(intervals, show_start_times, threshold);
}

int main(int argc, char *argv[])
{
   using namespace TestFramework;

   static_assert (GetTestFrameworkVersion () == 7,
      "TestFramework version 7 is required. Please, update test_framework.h.");

   if ((argc != 2) && (argc != 3))
   {
      std::cout << helpMsg;
   }

   std::string firstArg(DefaultProblemSet());

   if (argc >= 2)
   {
      firstArg = argv[1];
   }
   else
   {
      std::cout << "\nUsing the default problem set: " << firstArg;
   }

   ExitIfConditionFails((firstArg == "small") || (firstArg == "large"), "Unknown problem set.");
   bool bSmallDataset = (firstArg == "small");

   std::cout << std::endl << "Problem set #" << problem_set_id << ". ";

   ProblemSetHeader header;
   RecordAdapter<ProblemSetHeader> psAdapter(header);
   AddDefaultProblemSetColumns(psAdapter);

   std::vector<ProblemN2> problems;
   TableAdapter<ProblemN2> prAdapter(problems);
   AddDefaultProblemColumns(prAdapter);

   AddColumn<ProblemN2>(prAdapter, "start_times", &ProblemN2::start_times);
   AddColumn<ProblemN2>(prAdapter, "finish_times", &ProblemN2::finish_times);
   AddColumn<ProblemN2>(prAdapter, "user_ids", &ProblemN2::user_ids);
   AddColumn<ProblemN2>(prAdapter, "show_start_times", &ProblemN2::show_start_times);
   AddColumn<ProblemN2>(prAdapter, "threshold", &ProblemN2::threshold);

   BasicYamlParser parser(dynamic_cast<ITable*>(&psAdapter),
                          dynamic_cast<ITable*>(&prAdapter));

   const char* inputFilename = bSmallDataset ? smallDataset : largeDataset;
   std::cout << "File: " << inputFilename << ".\n";

   parser.ParseFile(inputFilename, true);
   header.student_name = GetStudentName();
   PreprocessProblemSet(problem_set_id, problems, header);

   for (int i = 0; i < problems.size(); ++i)
   {
      auto& theProblem = problems[i];
      theProblem.student_answer = CountMostPopularShows(theProblem.start_times, theProblem.finish_times, theProblem.user_ids, theProblem.show_start_times, theProblem.threshold);
   }

   ProcessResults(problems, header);

   std::cout << "Don't forget to submit your source code on Canvas.";
   std::cout << "\nRunning time: " << header.time << "ms";
   std::cout << std::endl << std::endl;
   std::cout << std::endl << std::endl;

   if (argc == 3)
   {
      const char * outputFilename = argv[2];
      std::cout << "Generating a report. ";
      std::cout << "The report is saved in file '" << outputFilename << "'.\n";
      TableAdapter<ProblemN2> prOutAdapter(problems);
      AddDefaultProblemColumnsForOutput(prOutAdapter);

      WriteTableToFile(outputFilename, &prOutAdapter, &psAdapter, true, strNotice);
   }

   return 0;
}
