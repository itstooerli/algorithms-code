///////////////////////////////////////////////////////////////////////
// DO NOT EDIT THIS FILE
//
// Compile this file using clang++, g++, or Microsoft Visual Studio 
// C++ compiler.
//
// To compile using Clang type:
//    clang++ main.cpp -O3 -o main


#include <algorithm>
#include <string>
#include <vector>
#include <utility>
#include "test_framework.h"
#include "student_code_5.h"

const char* smallDataset = "small_problem_set_5.in";
const char* largeDataset = "large_problem_set_5.in";

const char*  helpMsg = "Please, indicate which problem set to use.\n\n"
                       "For small problem set, type: ./main small\n"
                       "For large problem set, type: ./main large\n";

const char* strNotice = "##################################\n"
                        "# Do not edit this file!\n"
                        "##################################\n";

constexpr int problem_set_id = 5;

struct ProblemN5: public TestFramework::BasicProblem
{
   std::vector<int> horizontal_lines;
   std::vector<int> vertical_lines;
   std::vector<int> rabbits_x;
   std::vector<int> rabbits_y;
};

double ToReal(int a)
{
   const double norm = 1.0 / 8388608.0;
   return a * norm;
}

int CountOccupiedCells(const std::vector<int>& int_horizontal_lines, 
                       const std::vector<int>& int_vertical_lines, 
                       const std::vector<int>& int_rabbits_x, 
                       const std::vector<int>& int_rabbits_y)
{
   const char* errorMsg = "The problem set file is corrupted.";

   TestFramework::ExitIfConditionFails(int_rabbits_x.size() == int_rabbits_y.size(), errorMsg);
   
   int nHLines = int_horizontal_lines.size();
   int nVLines = int_vertical_lines.size();
   int nRabbits = int_rabbits_x.size();

   std::vector<double> hLines(nHLines);
   std::vector<double> vLines(nVLines);
   std::vector<std::pair<double, double>> rabbits;

   std::transform(int_horizontal_lines.begin(), int_horizontal_lines.end(), 
                  hLines.begin(), ToReal);

   std::transform(int_vertical_lines.begin(), int_vertical_lines.end(), 
                  vLines.begin(), ToReal);


   rabbits.reserve(nRabbits);
   for (int i = 0; i < nRabbits; ++i)
   {
      rabbits.emplace_back(ToReal(int_rabbits_x[i]), ToReal(int_rabbits_y[i]));
   }

   return CountOccupiedCells(hLines, vLines, rabbits);
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

   std::vector<ProblemN5> problems;
   TableAdapter<ProblemN5> prAdapter(problems);
   AddDefaultProblemColumns(prAdapter);

   AddColumn<ProblemN5>(prAdapter, "horizontal_lines", &ProblemN5::horizontal_lines);
   AddColumn<ProblemN5>(prAdapter, "vertical_lines", &ProblemN5::vertical_lines);
   AddColumn<ProblemN5>(prAdapter, "rabbits_x", &ProblemN5::rabbits_x);
   AddColumn<ProblemN5>(prAdapter, "rabbits_y", &ProblemN5::rabbits_y);

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
      theProblem.student_answer = CountOccupiedCells(theProblem.horizontal_lines, theProblem.vertical_lines, theProblem.rabbits_x, theProblem.rabbits_y);
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
      TableAdapter<ProblemN5> prOutAdapter(problems);
      AddDefaultProblemColumnsForOutput(prOutAdapter);

      WriteTableToFile(outputFilename, &prOutAdapter, &psAdapter, true, strNotice);
   }

   return 0;
}