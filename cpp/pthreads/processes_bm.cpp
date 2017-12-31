#include "benchmark/benchmark.h"
#include<sys/types.h>
#include<unistd.h>
#include <sys/wait.h>
void * do_nothing() {
  int i;
  i=0;
}  

#define ARGS(N) \
  ->Arg(N) \
  ->UseRealTime()

void BM_thread(benchmark::State& state) {
	int pid, j, status;
	size_t num_processes = state.range_x();
	while (state.KeepRunning()) {
		for (j=0; j<num_processes; j++) {

			/*** error handling ***/
			if ((pid = fork()) < 0 ) {
				printf ("fork failed with error code= %d\n", pid);
				exit(0);
			}

			/*** this is the child of the fork ***/
			else if (pid ==0) {
				do_nothing();
				exit(0);
			 }

			/*** this is the parent of the fork ***/
			else {
             //do nothing
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

