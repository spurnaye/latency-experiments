#include <thread>
#include <iostream>
#include "benchmark/benchmark.h"

void *do_nothing(void *null) {
  int i;
  i=0;
}

#define ARGS(N) \
  ->Arg(N) \
  ->UseRealTime()

void BM_thread(benchmark::State& state) {
  size_t num_threads = state.range_x();
  while (state.KeepRunning()) {
    for (int j=0; j<num_threads; j++) {
      std::thread t1([]{do_nothing(nullptr);});
      t1.join();
    }
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
