///////////////////////////////////////////////////////////////////////
// You need to
//    1. Read the programming assignment in homework #7.
//    2. Implement function GetStudentName.
//    3. Implement function MaxCommonSubtrees
//    4. Compile your code as explained in the instructions.
//    5. Run the executable on small and large unit tests.
//    6. Test and debug your code. Make sure that your program does
//       not have any memory leaks.
//    7. Remove all commented out code. Double check that your program
//       does not print any debug information on the screen.
//    8. Submit your code ("student_code_7.h")
//       via Canvas.
///////////////////////////////////////////////////////////////////////

//required libraries
#include <string>
#include <vector>

#include <unordered_map>
#include <iostream>

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

enum class Code: int
{
   unary_op = 0,
   binary_op = 1,
   commut_binary_op = 2, 
   variable = 3,
   number = 4
};

struct Node
{
   Code code;
   int id;
};

int LeftChild(int i)
{
   return 2 * i + 1;
}

int RightChild(int i)
{
   return 2 * i + 2;
}

// Cantor Pairing takes two positive integers and returns a unique positive integer
// The order these integers are provided does matter (note, + y in expression below)
// CantorHash supplies a hash for a Node, CantorInt supplies a hash for ints
struct CantorHash{
  int operator() (Node const& node){
    int x = int(node.code);
    int y = int(node.id);
    return ((x + y) * (x + y + 1)/2 + y);
  }
};

int CantorInt(int x, int y){
  return ((x + y) * (x + y + 1)/2 + y);
}

// Traverse Tree - Hash node, explore tree, calculate total size and full hash of subtree
std::pair<int,int> TraverseTree(const std::vector<Node>& tree,
                                std::unordered_map<int,int>& nodeMap,
                                const int& index,
                                int& maxSubtreeSize){

  Node node = tree[index];
  int nodeHash = CantorHash{}(node);
  int size = 0;
  
  switch(node.code){
    case Code::unary_op:{
      // unary_op: Traverse only left child,
      //           CantorInt distinguishes child has second int;
      int childHash, childSize;
      std::tie(childHash, childSize) = TraverseTree(tree, nodeMap, LeftChild(index), maxSubtreeSize);
      nodeHash = CantorInt(nodeHash, childHash);
      size = 1 + childSize;
      break;
    }
    case Code::binary_op: {
      // binary_op: Traverse both left and right children,
      //            Cantor Int distinguishes left and right children;
      int childHashL, childHashR, childSizeL, childSizeR;
      std::tie(childHashL, childSizeL) = TraverseTree(tree, nodeMap, LeftChild(index), maxSubtreeSize);
      std::tie(childHashR, childSizeR) = TraverseTree(tree, nodeMap, RightChild(index), maxSubtreeSize);
      nodeHash = CantorInt(nodeHash, CantorInt(childHashL, childHashR));
      size = 1 + childSizeL + childSizeR;
      break;
    }
    case Code::commut_binary_op:{
      // commut_binary_op: Traverse both left and right children, 
      //                   modified cantor hashing leveraging constant
      //                   prime number used to ignore ordering of left 
      //                   and right children, Cantor Int distinguishes child
      int childHashL, childHashR, childSizeL, childSizeR;
      std::tie(childHashL, childSizeL) = TraverseTree(tree, nodeMap, LeftChild(index), maxSubtreeSize);
      std::tie(childHashR, childSizeR) = TraverseTree(tree, nodeMap, RightChild(index), maxSubtreeSize);
      nodeHash = CantorInt(nodeHash, ((childHashL + childHashR) * (childHashL + childHashR + 1) / 2 + 2741));
      size = 1 + childSizeL + childSizeR;
      break;
    }
    case Code::variable:
    case Code::number: {
      // variable/number: End tree search, leaf size = 1
      size = 1;
      break;
    }
    default: {
      std::cout << "Code " << int(node.code) << " not identified in TraverseTree.\n";
    }
  }

  // After total hash is calculated, check if total hash had already been computed
  // If the size stored for this total hash is greater than the current subtree size,
  // set current maxSubtreeSize to the stored size, else store new entry in hash table
  if (nodeMap.count(nodeHash)){
    if (nodeMap[nodeHash] > maxSubtreeSize){
        maxSubtreeSize = nodeMap[nodeHash];
    }
  }
  else{
    nodeMap[nodeHash] = size;
  }
  
  return std::make_pair(nodeHash, size);
}

int MaxCommonSubtrees(const std::vector<Node>& tree)
{

  // Initialize Variables and Traverse Tree
  // nodeMap - Stores totalhash of node and the size of the node;
  // startingNode - Assume root = 0;
  // maxSubtreeSize - Stores size of largest matching subtree;

  std::unordered_map<int, int> nodeMap;
  int startingNode = 0;
  int maxSubtreeSize = 0;
  TraverseTree(tree, nodeMap, startingNode, maxSubtreeSize);

  // Determine whether a singular variable/number match is a subtree
  /*
  if (maxSubtreeSize == 1){
    maxSubtreeSize = 0;
  }
  */

  // FOR DEBUG PURPOSES - [TODO: Explore Cantor Inversion]
  // Cantor Inversion:
  // C = Cantor Hash
  // n = FLOOR((-1 + sqrt(8*C + 1)) / 2);
  // a = C - 1/2 * (n + 1)(n);
  // b = n - a;
  
  /* 
  for (auto& node : nodeMap){
    std::cout << "Hash: " << node.first << " : " << node.second << "\n";
  }
  std::cout << "\n";
  */
  
  return maxSubtreeSize /* your answer */;
}
