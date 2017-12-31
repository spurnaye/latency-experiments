#include <iostream>
#include <vector>
#include <thread>
#include <atomic>
#include "benchmark/benchmark.h" 

#define ARGS(N) \
      ->Threads(N) \
  ->UseRealTime()

volatile std::atomic<long long> x;

void BM_thread(benchmark::State& state) {
    while (state.KeepRunning()) {
        benchmark::DoNotOptimize(x.fetch_add(1, std::memory_order_relaxed));
    }
}

BENCHMARK(BM_thread) ARGS(1);
BENCHMARK(BM_thread) ARGS(2);
BENCHMARK(BM_thread) ARGS(4);
BENCHMARK(BM_thread) ARGS(8);
BENCHMARK(BM_thread) ARGS(16);
BENCHMARK(BM_thread) ARGS(64);
BENCHMARK(BM_thread) ARGS(512);

BENCHMARK_MAIN()

