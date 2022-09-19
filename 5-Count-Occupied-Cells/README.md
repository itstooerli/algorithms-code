## Homework Assignment #4, Second Problem


A 1-by-1 field is partitioned into cells by horizontal and vertical lines. There are `n` rabbits on the field. The coordinates of the `i`-th rabbit is `(rabbits[i].first, rabbits[i].second)`. Your goal is to design an algorithm that counts the number of occupied cells. A cell is occupied if there is at least one rabbit sitting in that cell. The `y`-coordinates of horizontal lines are given in the vector `hLines`. The `x`-coordinates of vertical lines are given in the vector `vLines`. You can assume that no rabbit seats on the boundary of two cells.

#### Please, open file "student_code_5.h" and implement function 

```c++
int CountOccupiedCells(const std::vector<double>& hLines, 
                       const std::vector<double>& vLines, 
                       const std::vector<std::pair<double,double>>& rabbits)
```

The running time of your program should be less than 0.5 second.

To run your code, press the green "Run" button in Replit. Also, compile your code using the *make* command. Then, test your program with *small* and *large* problem sets. Type:
```shell
make clean
make
./main small
./main large
```

#### Submit your code (student_code_5.h) on Canvas. Do not submit it on Replit.