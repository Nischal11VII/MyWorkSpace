#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>

std::queue<int> q;
std::mutex mux;
std::condition_variable cv; // simply a communication channel, threads will use
                            // this object to communicate to each other.

void threadpush() {
  for (int i = 1; i < 1000; ++i) {
    std::lock_guard<std::mutex> lock(mux); // this is a safe practice instead of
                                           // just using mux lock and mux unlock
    q.push(i);
    cv.notify_one(); // notify only one thread among multiple threads,
                     // notify_all() -> notifies all threads.
  }
}
void threadpop() {
  while (q.empty() == false) {
    // constantly checks if the condition is met or not, we want a event driven
    // solution so that it only works when a event is triggered, solution is
    // condition_variable;
    std::lock_guard<std::mutex> lock(mux); // lock_guard -> locks on construction and unlocks on
              // destructions. can't manually unlock in the middle of the scope

    int t = q.front();
    q.pop();
    std::cout << t << std::endl;
  }
}

int main() {

  std::thread t1(threadpush);
  std::thread t2(threadpop);

  t1.join();
  t2.join();
}
