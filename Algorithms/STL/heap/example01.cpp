#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

template <typename T>
void printArr(const std::vector<T> &arr) {
  for (const T &t : arr) std::cout << t << " ";
  std::cout << std::endl;
}

std::random_device rd;
std::mt19937_64 urng(rd());

int main(int argc, char const *argv[]) {
  std::cout << "original array" << std::endl;
  std::vector<int> heap(7);
  std::iota(heap.begin(), heap.end(), 1);
  printArr(heap);

  std::cout << "shuffle" << std::endl;
  // std::shuffle(heap.begin(), heap.end(), urng);
  printArr(heap);

  // auto cmp = std::greater<int>();
  auto cmp = std::less<int>();

  std::cout << "make heap" << std::endl;
  std::make_heap(heap.begin(), heap.end(), cmp);
  printArr(heap);

  std::cout << "push back 8" << std::endl;
  heap.push_back(8);
  printArr(heap);

  std::cout << "push heap" << std::endl;
  std::push_heap(heap.begin(), heap.end(), cmp);
  printArr(heap);

  std::cout << "pop heap" << std::endl;
  std::pop_heap(heap.begin(), heap.end(), cmp);
  printArr(heap);

  std::cout << "is heap" << std::endl;
  std::cout << std::is_heap(heap.begin(), heap.end()) << std::endl;

  std::cout << "is heap until" << std::endl;
  auto it = std::is_heap_until(heap.begin(), heap.end());
  std::cout << *it << std::endl;

  std::cout << "sort heap (begin, end-1)" << std::endl;
  std::sort_heap(heap.begin(), heap.end() - 1, cmp);
  printArr(heap);
  return 0;
}
