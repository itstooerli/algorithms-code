## Problem Statement
You are going for a vacation to France. Before your trip, you chose *n* attractions
you want to visit and picked a specific order in which you want to visit them. In your list, the
coordinates of attraction `i` are stored in variable `point[i]`. The starting and ending points of your journey are the same. When you arrived to Paris, you realize that you cannot visit all attractions, because the maximum distance you can travel is maxDistance. So you would like to remove some of the attractions from your list so that the total length of the tour is at most maxDistance. Design and implement an algorithm that finds the maximum number of attractions you can visit. Note that
* The algorithm cannot change the order in which you visit attractions.
* Your trip must start and finish at location (0, 0).
* The length of the entire trip must be at most `maxDistance`.
* The distance between two points p and q equals $\sqrt{(p.x − q.x)^2 + (p.y − q.y)^2}$.

Write the following function
> `MaxTour(const std::vector<Point>& points, double maxDistance)`

The parameters of this function are `points` – attractions you plan to visit (each point has two
coordinates x and y); `maxDistance` – the maximum distance you can travel. The function should
return the maximum number of attractions you can visit. The running time of your program should
not exceed several seconds.