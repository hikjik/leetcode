#include <catch.hpp>

#include <solution.hpp>

#include <vector>

void CheckSolution(const std::vector<int> &values, int expected) {
  auto head = VectorToList(values);
  REQUIRE(expected == Solution::pairSum(head));
  REQUIRE(values == ListToVector(head));
  FreeList(head);
}

TEST_CASE("Simple") {
  {
    const int expected = 6;
    std::vector<int> values{5, 4, 2, 1};
    CheckSolution(values, expected);
  }
  {
    const int expected = 7;
    std::vector<int> values{4, 2, 2, 3};
    CheckSolution(values, expected);
  }
  {
    const int expected = 100001;
    std::vector<int> values{1, 100000};
    CheckSolution(values, expected);
  }
}
