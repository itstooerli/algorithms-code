## Average Price Increase

#### Please, work on this homework on your own and do collaborate with other students. Also, do not search for solutions online. When you are done, please, submit your code (student_code_3.h) on Canvas.

There are `n` restaurants along a circular road around Delicious Lake. All restaurants are numbered from `0` to `n-1`. Each restaurant offers a prix fixe menu for lunch. In the beginning of 2021, the price for lunch at restaurant `i` was `prices[i]`. However, during the year, restaurants adjusted their prices multiple times. Your goal is to find the average price increase in 2021 (rounded down to the closest integer).

You are given a list of original lunch prices and a list of price updates. You know that every day exactly one restaurant changed its prix fixe price. To be more competitive, the owners of that restaurant
calculated the average lunch price in their neighborhood and changed the lunch price at their restaurant to that average price plus a small premium. All restaurants within a distance of `radius` from `i` are in the neighborhood of restaurant `i`. There are no other restaurants in that neighborhood. (Specifically, a restaurant `j` is in the neighborhood of `i` if the number of restaurants between `i` and `j` is less than `radius`.) Thus, the total number of restaurants in the neighborhood of restaurant `i` is `2r + 1`. You may assume that `2r + 1 < n`.

Please, implement function 

```cpp
int AvgPriceIncrease(const std::vector<int>& prices, const std::vector<PriceUpdate>& updates, int radius)
```

Vector ``prices`` contains prices in the beginning of the year. Vector ``updates`` contains information about price updates: on day `t`, the prices are changed in restaurant ``updates[t].restaurantID``, and the additional premium equals ``updates[t].premium``. The radius of each neighborhood equals ``radius``. All prices are rounded down to the closest integer.

**Remark 1:** The running time of your algorithm should not exceed several seconds, when you run it on Replit (assuming that your compile your code with ``-O3`` switch.) 

**Remark 2:** You can use the implementation of the Fenwick Tree data structure provided to you in ``student_code_3.h``. Also, feel free to modify the source code of the FenwickTree class.

### Example.

Suppose, the original prices were ``[10, 15, 11, 7, 9]``, ``radius = 1``, and there was only one update ``{.restaurantID = 0, .premium = 5}``. It means that restaurant `0` changed the prix fixe menu price to `(9 + 10 + 15) / 3 + 5` (rounded down). Thus, the new price in that restaurant is `16`. The average price increase across all restaurants is `(16 - 10)/5 (rounded down) = 1`.