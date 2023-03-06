#include <catch.hpp>
#include <list_node.h>

#include <solution.hpp>

#include <vector>

void CheckSolution(std::vector<int> values, std::vector<int> expected) {
  auto head = VectorToList(values);
  auto odd_even_head = Solution::oddEvenList(head);

  REQUIRE(expected == ListToVector(odd_even_head));

  FreeList(odd_even_head);
}

TEST_CASE("Simple") {
  CheckSolution({1, 2, 3, 4, 5}, {1, 3, 5, 2, 4});
  CheckSolution({2, 1, 3, 5, 6, 4, 7}, {2, 3, 6, 7, 1, 5, 4});
}
