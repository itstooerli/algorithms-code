/////////////////////////////////////////////////////////////////////////
// DO NOT EDIT THIS FILE
//
// To compile type:
//    clang++ main.cpp -O3 -Wall -o main
//

#include <numeric>
#include <string>
#include <vector>

#include "student_code_6.h"
#include "test_framework.h"


const char* smallDataset = "small_problem_set_6.in";
const char* largeDataset = "large_problem_set_6.in";

const char*  helpMsg = 
"Please, indicate which problem set to use.\n\n"
"For small problem set, type: ./main small\n"
"For large problem set, type: ./main large\n";

const char* strNotice =
"##################################\n"
"# Do not edit this file!\n"                        "##################################\n";

constexpr int problem_set_id = 6;

struct ProblemN6: public TestFramework::BasicProblem
{
   std::vector<int> alice;
   std::vector<int> bob;
   std::vector<int> start_times;
   std::vector<int> finish_times;
};


int CountABRestaurants(const std::vector<int>& alice, 
                       const std::vector<int>& bob, 
                       const std::vector<int>& start_times, 
                       const std::vector<int>& finish_times)
{
   const char* errorMsg = "Problem set file is corrupted.";
   TestFramework::ExitIfConditionFails(alice.size() == bob.size(), errorMsg);
   TestFramework::ExitIfConditionFails(start_times.size() == finish_times.size(), errorMsg);

   int nQueries = start_times.size();
   std::vector<std::pair<int, int>> queries;
   queries.reserve(nQueries);

   for (int i = 0; i < nQueries; ++i)
   {
      queries.emplace_back(start_times[i], finish_times[i]);
   }

   auto answers = CountABRestaurants(alice, bob, queries);
   int sum = std::accumulate(answers.begin(), answers.end(), 0);

   return sum;
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

   std::vector<ProblemN6> problems;
   TableAdapter<ProblemN6> prAdapter(problems);
   AddDefaultProblemColumns(prAdapter);

   AddColumn<ProblemN6>(prAdapter, "alice", &ProblemN6::alice);
   AddColumn<ProblemN6>(prAdapter, "bob", &ProblemN6::bob);
   AddColumn<ProblemN6>(prAdapter, "start_times", &ProblemN6::start_times);
   AddColumn<ProblemN6>(prAdapter, "finish_times", &ProblemN6::finish_times);

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
      theProblem.student_answer = CountABRestaurants(theProblem.alice, theProblem.bob, theProblem.start_times, theProblem.finish_times);
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
      TableAdapter<ProblemN6> prOutAdapter(problems);
      AddDefaultProblemColumnsForOutput(prOutAdapter);

      WriteTableToFile(outputFilename, &prOutAdapter, &psAdapter, true, strNotice);
   }

   return 0;
}