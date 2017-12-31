# Environment:
*   RHEL 7.3
*   RAM 48GB
*   CPUs 16 (2X4 core X5570  @ 2.93GHz)
```
g++ pthread_create.cpp -lbenchmark -pthread  -std=c++1y -o pthread_create && ./pthread_create
Benchmark                        Time           CPU Iterations
--------------------------------------------------------------
BM_thread/1/real_time        19288 ns      20899 ns      36156
BM_thread/2/real_time        38391 ns      41704 ns      18197
BM_thread/4/real_time        76970 ns      83501 ns       8852
BM_thread/8/real_time       153848 ns     166907 ns       4544
BM_thread/16/real_time      308452 ns     333224 ns       2272
BM_thread/64/real_time     1226508 ns    1333651 ns        573
BM_thread/512/real_time    9845959 ns   10667324 ns         71
```
