#include <catch.hpp>
#include <list_node.h>

#include <solution.hpp>

#include <vector>

void CheckSolution(const std::vector<int> &values,
                   const std::vector<int> &expected) {
  auto head = VectorToList(values);
  auto half = Solution::middleNode(head);

  REQUIRE(expected == ListToVector(half));

  FreeList(head);
}

TEST_CASE("Simple") {
  {
    std::vector<int> values{1, 2, 3, 4, 5};
    std::vector<int> expected{3, 4, 5};
    CheckSolution(values, expected);
  }
  {
    std::vector<int> values{1, 2, 3, 4, 5, 6};
    std::vector<int> expected{4, 5, 6};
    CheckSolution(values, expected);
  }
}
