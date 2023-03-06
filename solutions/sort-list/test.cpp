#include <catch.hpp>
#include <list_node.h>

#include <solution.hpp>

#include <vector>

void CheckSolution(std::vector<int> values, std::vector<int> expected) {
  auto head = VectorToList(values);
  auto sorted = Solution::sortList(head);

  REQUIRE(expected == ListToVector(sorted));

  FreeList(sorted);
}

TEST_CASE("Simple") {
  CheckSolution({4, 2, 1, 3}, {1, 2, 3, 4});
  CheckSolution({-1, 5, 3, 4, 0}, {-1, 0, 3, 4, 5});
  CheckSolution({}, {});
}
