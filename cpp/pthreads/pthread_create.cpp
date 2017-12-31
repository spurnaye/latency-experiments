#include <pthread.h>
#include "benchmark/benchmark.h"

void *do_nothing(void *null) {
  int i;
  i=0;
  pthread_exit(NULL);
}  

#define ARGS(N) \
  ->Arg(N) \
  ->UseRealTime()

void BM_thread(benchmark::State& state) {
  size_t num_threads = state.range_x();
  int rc, i, j, detachstate;
  pthread_t tid;
  pthread_attr_t attr;

  pthread_attr_init(&attr);
  pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

  while (state.KeepRunning()) {
    for (j=0; j<num_threads; j++) {
      rc = pthread_create(&tid, &attr, do_nothing, NULL);
      if (rc) {              
       printf("ERROR; return code from pthread_create() is %d\n", rc);
       exit(-1);
      }

      /* Wait for the thread */
      rc = pthread_join(tid, NULL);
      if (rc) {
       printf("ERROR; return code from pthread_join() is %d\n", rc);
       exit(-1);
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

