#include <iostream>
#include <vector>
#include <mutex>
#include <thread>

#define LIMIT  1000000

std::mutex increment_mutex;

void increment(unsigned long & sum) {
   for(unsigned i = 0; i < LIMIT; ++i){
       std::lock_guard<std::mutex> guard(increment_mutex);
       sum += 1;
   }
}

void spawn_threads(size_t num_threads) {
    unsigned long sum = 0;
    std::vector<std::thread> threads(num_threads);
    for(int i = 0;i <= num_threads;++i){
        threads.emplace_back(std::thread(increment, std::ref(sum)));
        }
    for(auto & t: threads){
      if(t.joinable()){
        t.join();
      }
    }
    std::cout << "num_threads " << num_threads << " sum " << sum << "\n";
}

int main(){
    spawn_threads(1);
    spawn_threads(2);
    spawn_threads(4);
    spawn_threads(8);
    spawn_threads(16);
    spawn_threads(64);
    spawn_threads(512);
}
