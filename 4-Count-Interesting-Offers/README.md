## Homework Assignment #4, First Problem

You would like to buy many cupcakes for a party. To do so, you obtained price quotes from many bakeries. For each bakery you know the price of  cupcakes they offer and their quality. You stored this information in the array of `offers` as follows: `offers[i].first` is the price of cupcakes in bakery `i`; `offers[i].second` is the quality score for cupcakes in bakery `i`. Prices and quality scores are real numbers. An offer `i` is not interesting to you if both the price and quality score of that offer is less than or equal to the price and quality score of another offer (respectively). Your goal is to develop an algorithm that counts the number of interesting offers.

Remark: You can assume that there are no two offers with exactly the same price and quality score.

#### Please, open file "student_code_4.h" and implement function 

```c++
int CountInterestingOffers(std::vector<std::pair<double, double>> offers)
```

The running time of your program should be less than 0.5 second.

To run your code, press the green "Run" button in Replit. Also, compile your code using the *make* command. Then, test your program with *small* and *large* problem sets. Type:
```shell
make clean
make
./main small
./main large
```

#### Submit your code (student_code_4.h) on Canvas. Do not submit it on Replit.