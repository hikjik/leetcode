#include <catch.hpp>
#include <list_node.h>

#include <solution.hpp>

#include <vector>

void CheckSolution(const std::vector<int> &values,
                   const std::vector<int> &expected) {
  auto head = VectorToList(values);
  auto deduplicated = Solution::deleteDuplicates(head);

  REQUIRE(expected == ListToVector(deduplicated));

  FreeList(deduplicated);
}

TEST_CASE("Simple") {
  {
    std::vector<int> values{1, 2, 3, 3, 4, 4, 5};
    std::vector<int> expected{1, 2, 5};
    CheckSolution(values, expected);
  }
  {
    std::vector<int> values{1, 1, 1, 2, 3};
    std::vector<int> expected{2, 3};
    CheckSolution(values, expected);
  }
}
