Homework Assignment #6
========================

Your team is working on a compiler for a new programming language for competitive programmers. You need to implement an algorithm for common subexpression elimination. In your compiler, expressions are represented by binary trees. Each tree is stored in an array. Similarly to a binary heap, the left and right children of node `i` have indices `2i+1` and `2i+2`, respectively. Each internal node of the tree is an unary (`Code::unary_op`), binary (`Code::binary_op`), or commutative binary (`Code::commut_binary_op`) operation; and each leaf is a variable (`Code::variable`) or constant (`Code::number`). The type of the operation is stored in the field `code`. That is, the code of node `i` is `tree[i].code`. Additionally, each node has an `id`. For operations, variables, and numbers, these ids specify the operation id, variable id, and number. 

Every node in the tree returns a number based on the values assigned to variables and constants. Variable and constant nodes return the value of the corresponding variables and constants, respectively. Operation nodes apply the prescribed operation to its children and return the obtained result. 

#### Please, open file "student_code_7.h" and implement function 

```c++
int MaxCommonSubtrees(const std::vector<Node>& tree)
```

This function should return the size of the maximum proper subtree of `tree` that has two equivalent copies. Do not make any assumptions about the operations except:

 * The result of an unary operation depends only on the left child.

 * The result of a commutative binary operation does not depend on the ordering of its children. That is, `L x R = R x L`, where `x` is the **commutative** binary operation

To run your code, press the green "Run" button in Replit. Also, compile your code using the *make* command. Then, test your program with *small* and *large* problem sets. Type:
```shell
make clean
make
./main small
./main large
```

The expected running time for the large problem set is in the range 0.1-1 seconds or less. 

#### Submit your code (student_code_7.h) on Canvas. Do not submit it on Replit.