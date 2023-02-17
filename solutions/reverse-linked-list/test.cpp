#include <catch.hpp>
#include <list_node.h>

#include <solution.hpp>

#include <vector>

void CheckSolution(std::vector<int> values, std::vector<int> expected) {
  auto head = VectorToList(values);
  auto reversed_list_head = Solution::reverseList(head);

  REQUIRE(expected == ListToVector(reversed_list_head));

  FreeList(reversed_list_head);
}

TEST_CASE("Simple") {
  {
    CheckSolution({1, 2, 3, 4, 5}, {5, 4, 3, 2, 1});
    CheckSolution({1, 2}, {2, 1});
    CheckSolution({}, {});
  }
}
