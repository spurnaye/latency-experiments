#include <iostream>
#include <vector>
#include <thread>
#include <algorithm>
#include <functional>
#include "benchmark/benchmark.h" 

#define ARGS(N) \
  ->Arg(N) \
  ->UseRealTime()

void *do_nothing(unsigned i) {
  //std::cout << "within the thread " << i << std::endl;
}

void BM_thread(benchmark::State& state) {
  size_t num_threads = state.range_x();
  std::vector<std::thread> threads(num_threads);

	while (state.KeepRunning()) {
		for(unsigned i = 0;i <= num_threads;++i){
			threads.emplace_back(std::thread(do_nothing, i));
		}

		for(auto& thread : threads)
		{
			if(thread.joinable())
			{
				thread.join();
			}
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









