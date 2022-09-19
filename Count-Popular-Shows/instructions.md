Homework Assignment #2
========================

You work for a TV channel, "Modern Algorithms". You want to find out what shows are popular on your channel. A show is called popular if more than ``threshold`` number of *distinct* users watch it simulateously at some point of time. You are given a collection of ``intervals``. Each interval tells you when a user with id ``interval.userID`` started and finished watching your channel. The start and finish time is given to you in ``interval.start`` and ``interval.finish``. 

Note that the same user can watch your show on several devices at the same time, in which case, the user should be counted only once.

#### Please, open file "student_code_2.h" and implement function 

```c++
int CountMostPopularShows(const std::vector<Interval>& intervals, 
                          const std::vector<int>& showStartTimes, 
                          int threshold)
```

This function should find the number of popular shows. The parameters of the function are the set of ``intervals``, an array of show start times ``showStartTimes``, and  the ``threshold``. Please, keep in mind that one show ends when the next show starts.

To run your code, press the green "Run" button in Replit. Also, compile your code using the *make* command. Then, test your program with *small* and *large* problem sets. Type:
```shell
make clean
make
./main small
./main large
```

#### Submit your code (student_code_2.h) on Canvas. Do not submit it on Replit.