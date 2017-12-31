# Environment:
*   RHEL 7.3
*   RAM 48GB
*   CPUs 16 (2X4 core X5570  @ 2.93GHz)
```
g++ std_threds.cpp -lbenchmark -lpthread -std=c++1y -o std_threads && ./std_threads
Benchmark                        Time           CPU Iterations
--------------------------------------------------------------
BM_thread/1/real_time        18095 ns      19631 ns      39143
BM_thread/2/real_time        35642 ns      38619 ns      19334
BM_thread/4/real_time        71708 ns      77528 ns       9790
BM_thread/8/real_time       146099 ns     157805 ns       4771
BM_thread/16/real_time      296069 ns     320531 ns       2412
BM_thread/64/real_time     1140797 ns    1242152 ns        597
BM_thread/512/real_time    9186566 ns    9964105 ns         76
```
