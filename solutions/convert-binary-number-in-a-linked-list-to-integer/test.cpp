#include <catch.hpp>
#include <list_node.h>

#include <solution.hpp>

#include <vector>

void CheckSolution(std::vector<int> values, int expected) {
  auto head = VectorToList(values);
  auto actual = Solution::getDecimalValue(head);
  REQUIRE(expected == actual);
}

TEST_CASE("Simple") {
  {
    std::vector<int> values{1, 0, 1};
    CheckSolution(values, 5);
  }
  {
    std::vector<int> values{0};
    CheckSolution(values, 0);
  }
}
