## Problem Statement
A mobile communications company, Tech336 wants to upgrade their cellular network
along highway X to a new wireless standard 10G. To do so, it plans to install new wireless transmitters on some of their existing towers. A user can receive a signal from a tower if the distance from the user to the tower is at most `range`. To guarantee an uninterrupted service for all their customers, Tech336 wants to install new transmitters so that no matter where the customer is located on the highway, he or she is within the range of at least two transmitters. Your goal is to find the minimum number of transmitters required for the upgrade.

Design and implement a greedy algorithm for finding the minimum number of transmitters. Note
that Tech336 can install at most one transmitter on an existing a cell tower. Write the following
function

> `MinStations(int roadLength, int range, std::vector<int> towers)`

The parameters of this function are `roadLength` – the length of the highway; `range` – the transmission range of the new transmitters; `towers` – positions of the towers. Each position is the distance from the tower to the beginning of the highway. Function `MinStations` should return the minimum number of new transmitters. If the problem has no feasible solution, `MinStations` should return −1. In this problem, you can assume that the highway is a straight line.
