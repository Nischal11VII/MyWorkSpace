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

bool exitProgram = false;

void threadpush() {
  for (int i = 1; i < 10000; ++i) {
    std::lock_guard<std::mutex> lock(mux); // this is a safe practice instead of
                                           // just using mutex lock and mutex unlock
    q.push(i);
    cv.notify_one(); // notify only one thread among multiple threads,
                     // notify_all() -> notifies all threads.
  }
    
  std::lock_guard<std::mutex> lock(mux);
  exitProgram = true;
  cv.notify_one();


}
void threadpop() {
  while (true) {
  

      if(!q.empty()) {
      // constantly checks if the condition is met or not, we want a event driven solution so that it only works when a event is triggered, solution is condition_variable;
    

   // std::lock_guard<std::mutex> lock(mux); 
 //  lock_guard -> locks on construction and unlocks on destructions. can't manually unlock in the middle of the scope
    // solution for lock_guard -> unique_lock;
   
      //provides ability to temporarily unlock the unlock the mutex and lock it later;
      std::unique_lock<std::mutex> lock(mux);
      
    //unlocks the mutex -> push threads takes the priority -> this thread however enters the blocked or waiting state which tells the operating system schedular(OSS) to not give current threads any CPU time. -> wait for the push thread to call and OSS notifies this thread to wake up   
      cv.wait(lock , [] {return !q.empty();}); 



    int t = q.front();
    q.pop();
    std::cout << t << std::endl;
    }
      if(q.empty() && exitProgram)
      {
        break;
      }


  }
}

int main() {

  std::thread t1(threadpush);
  std::thread t2(threadpop);

  t1.join();
  t2.join();
    


  return 0;
}
