#include <iostream>
#include <vector>
#include <set>
#include <complex>
#include <numeric>
#include <functional>

#include "stuff.hpp"

static const int answer = 42;

int my::cool::Namespace::function(double var1, std::vector<std::complex<float> > ofThis, int* uce, std::size_t len_uce) {
  std::cout << "var1: " << var1 << std::endl;
  std::cout << "sum(ofThis): " << std::accumulate(ofThis.begin(), ofThis.end(), std::complex<float>(0.0)) << std::endl;
  std::cout << "prod(uce): " << std::accumulate(uce, uce + len_uce, 1, std::multiplies<int>()) << std::endl;
  return answer;
}

int my::cool::Namespace::function(std::set<int> overLoadSet) {
  std::cout << "I looked up this function from the overload set!" << std::endl;
  return std::accumulate(overLoadSet.begin(), overLoadSet.end(), 1);
}
