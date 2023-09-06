#include <catch.hpp>

#include <solution.hpp>

#include <algorithm>
#include <vector>

template <class T>
void CheckSorted(std::vector<T> expected, std::vector<T> actual) {
  std::sort(expected.begin(), expected.end());
  std::sort(actual.begin(), actual.end());
  REQUIRE(expected == actual);
}

TEST_CASE("Simple") {
  {
    std::vector<int> test{1, 2, 1, 3, 2, 5};
    CheckSorted({3, 5}, Solution::singleNumber(test));
  }
  {
    std::vector<int> test{{-1, 0}};
    CheckSorted({-1, 0}, Solution::singleNumber(test));
  }
  {
    std::vector<int> test{{0, 1}};
    CheckSorted({0, 1}, Solution::singleNumber(test));
  }
}
