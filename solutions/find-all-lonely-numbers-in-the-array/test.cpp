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
    std::vector<int> numbers{10, 6, 5, 8};
    std::vector<int> expected{8, 10};
    CheckSorted(expected, Solution::findLonely(numbers));
  }
  {
    std::vector<int> numbers{1, 3, 5, 3};
    std::vector<int> expected{1, 5};
    CheckSorted(expected, Solution::findLonely(numbers));
  }
}
