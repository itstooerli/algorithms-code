## Problem Statement
Alice has chosen `n` holiday gifts for her friends. Alice knows that each gift will be on
sale during Black Friday. The Black Friday sale price of gift `i` will be `giftPrices[i].sale`. The price of item `i` before Black Friday will be `giftPrices[i].before`; and the price of gift `i` after Black Friday is going to be `giftPrices[i].after`. Alice wants to plan when to buy each gift to minimize the total cost of all gifts. The challenge is that Alice can buy at most `k` gifts on Black Friday. She, however, can buy any number of gifts before and after Black Friday.

Design and implement an algorithm for finding the minimum total cost of all n gifts. Write the
following function

> `MinCost(const std::vector<Price>& giftPrices, int k)`

The parameters of this function are `const std::vector<Price>& giftPrices` – the list of prices
and `k` – the maximum number of items Alice can buy on the Black Friday sale. Each element of
the array/vector `giftPrices` contains three fields: sale, before, and after, as described above.
Function `MinCost` should return the minimum possible total cost of all gifts. All numbers are
integers.