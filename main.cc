#include <iostream>
#include <vector>
#include "permandcomb.h"

int main(int argc, char const *argv[])
 {
  std::vector<int> l{1, 2, 3, 4};
  std::cout << permutations(l, 3);
  std::cout<<std::endl;
  std::cout << combinations(l, 3);
  return 0;
 }

