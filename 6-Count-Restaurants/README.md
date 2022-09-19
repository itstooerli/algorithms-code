Homework Assignment #6
========================

Alice and Bob are foodies. Each of them keeps track of the restaurants they attended in the past 20 years. On day `i`, Alice went to restaurant `alice[i]`, and Bob went to restaurant `bob[i]`. Your goal is to write an algorithm that finds the number of restaurants that were visited by both Alice and Bob in a given time range.

Your algorithm should receive two arrays `alice` and `bob` as well as a list of queries (`queries`). Each query consists of two numbers `queries[i].first` and `queries[i].second`. For each query, your algorithm should return the number of restaurants that were visited by both Alice and Bob in the time interval `[queries[i].first, queries[i].second]`. You should save the answer in the entry `answer[i]` and then return array `answer[i]`.

#### Please, open file "student_code_6.h" and implement function 

```c++
std::vector<int> 
CountABRestaurant(const std::vector<int>& alice, 
                  const std::vector<int>& bob, 
                  const std::vector<std::pair<int, int>>& queries)

{   
   int nQueries = queries.size();
   std::vector<int> answers(nQueries, -1);

   // answer[i] should contain the answer to the i-th query
   // i.e., the number of restaurants visited at least once 
   // by both Alice and Bob in the time interval 
   // [queries[i].first, queries[i].second]

   return answers;
}                  
```

To run your code, press the green "Run" button in Replit. Also, compile your code using the *make* command. Then, test your program with *small* and *large* problem sets. Type:
```shell
make clean
make
./main small
./main large
```

The running time for the large problem set can be in the range 5-10 seconds. The unit tests included with this assignment will compare the sum of all answers in the array `answers` with the correct result.

#### Submit your code (student_code_6.h) on Canvas. Do not submit it on Replit.