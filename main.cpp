#include <iostream>
#include <vector>
#include "sorts.h"

template <typename T>
void print(std::vector<T> v) {
  std::cout << "[";
  bool first = true;
  for (auto x : v) {
    if (!first) {
      std::cout << ", ";
    }
    std::cout << x;
    first = false;
  }
  std::cout << "]";
  std::cout << std::endl;
}

int main() {
  std::vector<std::string> v;
  v = {"Lithium", "Hydrogen", "Carbon", "Oxygen", "Mercury"};
  std::cout << "\nBubble Sort:\n";
  print(v);
  BubbleSort(v);
  print(v);

  std::vector<std::string> u;
  u = {"cat","dog","cow","pig","bat"};
  std::cout << "\nMerge Sort:\n";
  print(u);
  MergeSort(u);
  print(u);

  std::vector<int> t;
  t = {6, 11, 2, 4, 1, 6, -8, 13, 9};
  std::cout << "\nInsertion Sort:\n";
  print(t);
  InsertionSort(t);
  print(t);
  
  return 0;
}