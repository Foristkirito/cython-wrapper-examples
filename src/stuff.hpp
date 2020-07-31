
#include <vector>
#include <complex>
#include <set>
#include <iostream>

namespace my {

  namespace other {

    template <class T>
    bool templated_function(bool toBe, T myThing) {
      std::cout << "My thing is: " << myThing << std::endl;
      return toBe || !toBe;
    }

  }

  namespace cool {
    namespace Namespace {

      int function(double var1, std::vector<std::complex<float> > ofThis, int* uce, std::size_t len_uce);

      int function(std::set<int> overLoadSet);

    }
  }
}

class MyCoolClass {
public:

  float publicProp;

  MyCoolClass(bool notNullary)
    : publicProp(3.1415)
    , notNullary_(notNullary)
    , counter_(0)
    { }

  void loremIpsum() {
    std::cout << "Lorem ipsum dolor sit amet, consectetur "
              << "adipiscing elit, sed do eiusmod tempor "
              << "incididunt ut labore et dolore magna aliqua. "
              << "Ut enim ad minim veniam, quis nostrud "
              << "exercitation ullamco laboris nisi ut aliquip "
              << "ex ea commodo consequat. Duis aute irure dolor "
              << "in reprehenderit in voluptate velit esse cillum "
              << "dolore eu fugiat nulla pariatur. Excepteur sint "
              << "occaecat cupidatat non proident, sunt in culpa "
              << "qui officia deserunt mollit anim id est laborum."
              << std::endl;
  }

  int step() {
    return ++(this->counter_);
  }

private:
  bool notNullary_;
  int counter_;
};
