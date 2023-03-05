#include <catch.hpp>
#include <list_node.h>

#include <solution.hpp>

#include <vector>

void CheckSolution(std::vector<int> values, bool expected) {
  auto head = VectorToList(values);
  REQUIRE(expected == Solution::isPalindrome(head));
  FreeList(head);
}

TEST_CASE("Simple") {
  CheckSolution({1, 2, 2, 1}, true);
  CheckSolution({1, 2, 1}, true);
  CheckSolution({1, 2, 1, 1}, false);
  CheckSolution({1, 2, 2}, false);
  CheckSolution({1}, true);
}
