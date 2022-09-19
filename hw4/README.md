## Problem Statement
John wants to attend n football games this season. In order to so, he needs to get
tickets for each game. He can buy two types of tickets: single game tickets and tickets for five
consecutive games.
* A single game ticket is valid for one game. The ticket for game i costs pi coins. John can use
the discount code “CS 336” to get a 10% discount for every single game ticket (if *p<sub>i</sub>*
is not divisible by 10, the discount is rounded down to the closest integer). So, John’s price for a single day ticket for day *i* is *p<sub>i</sub> − ⌊p<sub>i</sub>/10⌋*.
* A five game ticket is valid for five consecutive days. There are no discounts for these tickets. So, the price of the ticket for games *i*, *i*+1, *i*+2, *i*+3, and *i*+4 is *p<sub>i</sub>*+*p<sub>i+1</sub>*+*p<sub>i+2</sub>*+*p<sub>i+3</sub>*+*p<sub>i+4</sub>*
coins.
Additionally, the ticket office charges John a fee of *f* coins for every ticket he buys (the fee is the same for single game and five game tickets).

Design an algorithm that finds the minimum cost of tickets for games 1 through n. The cost
should include all fees and discounts. Note that John must buy exactly one ticket for each game.

Write the following function
> `MinCost(const std::vector<int>& prices, int fee)`

The parameters of this function are `prices` – the prices of the tickets (`prices[i]` is the price for day `i`); `fee` –the ticket office fee charged for every ticket.