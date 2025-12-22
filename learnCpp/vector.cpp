#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

void funct(const std::vector<int> temp) {
  for (auto i : temp) {
    std::cout << i << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
}

int main() {
  std::vector<int> table;
  int user;
  std::cin >> user;
  for (int i = 0; i < user; i++) {

    table.push_back(i + 1);
  }

  std::thread t1(funct, table);
  t1.join();
}
