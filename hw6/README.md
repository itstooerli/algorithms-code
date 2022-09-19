## Problem Statement
You work for a startup that develops a new smartphone – Phone336. This phone
must be capable of working 336 hours (2 weeks) without charge. To make it happen, you need to
develop a new energy-aware job scheduling software. Your scheduler receives $n$ jobs that need to be executed on the phone one after another. The order of jobs is given to the scheduler in advance and cannot be changed. All jobs are “parallelizable”. That is, every job can run on several processor cores at the same time. The phone’s processor has 8 cores. Thus, your software should assign every job $j$ up to 8 cores. If job $j$ uses $k$ cores, then its processing time is $p_{jk}$, and it consumes $q_{jk}$ units of energy.

We ask you to design an algorithm that given $n$ jobs, numbers $p_{jk}$, $q_{jk}$, and an energy budget $Q$, finds the minimum time required to execute these jobs subject to the constraint that these jobs can consume at most $Q$ units of energy. Parameters $p_{jk}$, $q_{jk}$, and $Q$ are positive integers. The running time of your algorithm must be polynomial in $n$ and $Q$.

**Example**. Here is an example for 5 jobs and 3 cores.

Processing times $p_{jk}$

| | job 1 | job 2 | job 3 | job 4 | job 5 |
| - | - | - | - | - | - |
| 1 core | 12 | 10 | 15 | 12 | 10 |
| 2 cores | 6 | 5 | 10 | 6 | 10 |
| 3 cores | 4 | 5 | 8 | 4 | 10 |

Energy consumption $q_{jk}$

| | job 1 | job 2 | job 3 | job 4 | job 5 |
| - | - | - | - | - | - |
| 1 core | 1 | 1 | 3 | 1 | 2 |
| 2 cores | 1 | 4 | 9 | 2 | 4 |
| 3 cores | 1 | 9 | 16 | 5 | 6 |

If $Q = 8$, then you can assign 3 cores to the first job and 1 core to other jobs. In this case, the total energy consumption is

$q_{13} + q_{21} + q_{31} + q_{41} + q_{51} = 1 + 1 + 3 + 1 + 2 = 8$,

and the processing time is

$p_{13} + p_{21} + p_{31} + p_{41} + p_{51} = 4 + 10 + 15 + 12 + 10 = 51$.

If $Q = 10$, then you can assign 3 cores to job 1; 2 cores to job 4; and 1 core to jobs 2, 3, 5. In this case, the total energy consumption is

$q_{13} + q_{21} + q_{31} + q_{42} + q_{51} = 1 + 1 + 3 + 2 + 2 = 9$,

and the processing time is

$p_{13} + p_{21} + p_{31} + p_{42} + p_{51} = 4 + 10 + 15 + 6 + 10 = 45$.

Write the following function

> `MinProcessingTime(const std::vector<std::vector<Profile>>& profiles, int maxEnergy)`

The parameters of this function are job profiles (`profiles`) and energy budget (`maxEnergy`). The processing time of job $j$ on $k$ cores equals `profiles[j][k-1].time`. The energy consumption of job $j$ on $k$ cores equals `profiles[j][k-1].energy`. Your function should return the minimum running time. If there is no feasible solution to the problem, your function should return `-1`. The running time of your program should not exceed several seconds (please, compile your code with `-O2` or `-O3` optimization switch). You can assume that the maximum number of jobs in 150 and maxEnergy ≤ 10000.